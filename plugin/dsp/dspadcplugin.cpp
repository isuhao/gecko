/*
Copyright 2011 Bastian Loeher, Roland Wirth

This file is part of GECKO.

GECKO is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GECKO is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "dspadcplugin.h"
#include "pluginmanager.h"
#include "pluginconnectorqueued.h"
#include "samqvector.h"

#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>

static PluginRegistrar registrar ("dspadc", DspAdcPlugin::create, AbstractPlugin::GroupDSP);

DspAdcPlugin::DspAdcPlugin(int _id, QString _name)
    : BasePlugin(_id, _name)
{
    createSettings(settingsLayout);

    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::in,"trigger"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::in,"calorimetry"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::in,"baseline"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::out,"amplitudes"));

    std::cout << "Instantiated DspAdcPlugin" << std::endl;
}

void DspAdcPlugin::createSettings(QGridLayout * l)
{
    // Plugin specific code here

    QWidget* container = new QWidget();
    {
        QGridLayout* cl = new QGridLayout;

        QLabel* label = new QLabel(tr("This plugin reads amplitudes at the timestamped positions."));

        cl->addWidget(label,0,0,1,2);

        container->setLayout(cl);
    }

    // End

    l->addWidget(container,0,0,1,1);
}

void DspAdcPlugin::applySettings(QSettings* settings)
{
    QString set;
    settings->beginGroup(getName());
    settings->endGroup();

    // UI update

}

void DspAdcPlugin::saveSettings(QSettings* settings)
{
    if(settings == NULL)
    {
        std::cout << getName().toStdString() << ": no settings file" << std::endl;
        return;
    }
    else
    {
        std::cout << getName().toStdString() << " saving settings...";
        settings->beginGroup(getName());
        settings->endGroup();
        std::cout << " done" << std::endl;
    }
}

void DspAdcPlugin::userProcess()
{
    //std::cout << "DspPileUpCorrectionPlugin Processing" << std::endl;
    QVector<double> itrigger = inputs->at(0)->getData().value< QVector<double> > ();
    QVector<double> icalorimetry = inputs->at(1)->getData().value< QVector<double> > ();
    QVector<double> ibase = inputs->at(2)->getData().value< QVector<double> > ();
	
    double baseline = 0;
    double pointsForBaseline = 0;

    SamDSP dsp;

    if(!ibase.empty())
    {
        baseline = ibase.at(0);
        pointsForBaseline = ibase.at(1);
//      std::cout << "Using baseline value: " << baseline << " from " << pointsForBaseline << " points" << std::endl;
    }
    else
    {
//      std::cout << "Using standard baseline value: " << baseline << std::endl;
    }


    // Compact input data
    dsp.fast_addC(icalorimetry,-baseline);
    QVector< QVector<double> > amplitudes = dsp.select(icalorimetry, itrigger);
    outputs->first()->setData(QVariant::fromValue (amplitudes [AMP]));
}

/*!
\page dspadcplg ADC Plugin
\li <b>Plugin names:</b> \c dspadcplugin
\li <b>Group:</b> DSP

\section pdesc Plugin Description
The ADC plugin mimics the behaviour of an ADC.
It takes a trigger, a baseline and the calorimetry signal to be converted as inputs and outputs the baseline-corrected values of the signal at each trigger.

The baseline input is optional. If unconnected, the baseline value is assumed to be zero.

\section attrs Attributes
None

\section conf Configuration
None

\section inputs Input Connectors
\li \c trigger \c &lt;double>: Trigger signal
\li \c calorimetry \c &lt;double>: Signal to be sampled
\li \c baseline \c &lt;double>: Baseline value

\section outputs Output Connectors
\li \c amplitudes \c &lt;double>: The baseline-corrected sample values at points where trigger is nonzero
*/
