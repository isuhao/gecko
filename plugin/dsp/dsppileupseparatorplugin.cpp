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

#include "dsppileupseparatorplugin.h"
#include "pluginmanager.h"
#include "pluginconnectorqueued.h"

#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>

static PluginRegistrar registrar ("dsppileupseparator", DspPileupSeparatorPlugin::create, AbstractPlugin::GroupDSP);

DspPileupSeparatorPlugin::DspPileupSeparatorPlugin(int _id, QString _name)
    : BasePlugin(_id, _name)
{
    createSettings(settingsLayout);

    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::in,"signal"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::in,"trigger"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::out,"signalWithPileup"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::out,"triggerWithPileup"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::out,"signalWithoutPileup"));
    addConnector(new PluginConnectorQVDouble(this,ScopeCommon::out,"triggerWithoutPileup"));

    std::cout << "Instantiated DspPileupSeparatorPlugin" << std::endl;
}

void DspPileupSeparatorPlugin::createSettings(QGridLayout * l)
{
    // Plugin specific code here

    QWidget* container = new QWidget();
    {
        QGridLayout* cl = new QGridLayout;

        QLabel* label = new QLabel(tr("This plugin separates signals with and without pileup from a long trace."));
        QLabel* llabel = new QLabel(tr("Left"));
        QLabel* rlabel = new QLabel(tr("Right"));

        leftSpinner = new QSpinBox();
        rightSpinner = new QSpinBox();
        invertBox = new QCheckBox(tr("Invert"));

        leftSpinner->setValue(30);
        rightSpinner->setValue(100);

        leftSpinner->setMaximum(1000000);
        rightSpinner->setMaximum(1000000);

        invertBox->setChecked(true);

        connect(leftSpinner,SIGNAL(valueChanged(int)),this,SLOT(leftChanged()));
        connect(rightSpinner,SIGNAL(valueChanged(int)),this,SLOT(rightChanged()));
        connect(invertBox,SIGNAL(toggled(bool)),this,SLOT(invertChanged(bool)));

        cl->addWidget(label,0,0,1,2);
        cl->addWidget(llabel,1,0,1,1);
        cl->addWidget(rlabel,2,0,1,1);
        cl->addWidget(leftSpinner,1,1,1,1);
        cl->addWidget(rightSpinner,2,1,1,1);
        cl->addWidget(invertBox,3,0,1,1);

        container->setLayout(cl);
    }

    // End

    l->addWidget(container,0,0,1,1);
}

void DspPileupSeparatorPlugin::leftChanged()
{
    int newValue = leftSpinner->value();
    this->conf.left = newValue;
}

void DspPileupSeparatorPlugin::rightChanged()
{
    int newValue = rightSpinner->value();
    this->conf.right = newValue;
}

void DspPileupSeparatorPlugin::invertChanged(bool newValue)
{
    this->conf.invert = newValue;
}

void DspPileupSeparatorPlugin::applySettings(QSettings* settings)
{
    QString set;
    settings->beginGroup(getName());
        set = "left";   if(settings->contains(set)) conf.left = settings->value(set).toInt();
        set = "right";   if(settings->contains(set)) conf.right = settings->value(set).toInt();
        set = "invert";   if(settings->contains(set)) conf.invert = settings->value(set).toBool();
    settings->endGroup();

    // UI update
    leftSpinner->setValue(conf.left);
    rightSpinner->setValue(conf.right);
    invertBox->setChecked(conf.invert);
}

void DspPileupSeparatorPlugin::saveSettings(QSettings* settings)
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
            settings->setValue("left",conf.left);
            settings->setValue("right",conf.right);
            settings->setValue("invert",conf.invert);
        settings->endGroup();
        std::cout << " done" << std::endl;
    }
}

void DspPileupSeparatorPlugin::userProcess()
{
    //std::cout << "DspExtractSignalPlugin Processing" << std::endl;
    QVector<double> idata = inputs->at(0)->getData().value< QVector<double> > ();
    QVector<double> itrigger = inputs->at(1)->getData().value< QVector<double> > ();


    QVector<double> signalWithPileup;
    QVector<double> signalWithoutPileup;
    QVector<double> triggerWithPileup;
    QVector<double> triggerWithoutPileup;
    std::vector<double> pileup_mask(itrigger.size(),0);


    int t0 = -1;
    int t1 = -1;
    int dist = conf.left + conf.right;
    for(int i = 0; i < itrigger.size()-1; i++)
    {
        if(itrigger.at(i) == 1)
        {
            // Find first trigger timestamp
            if(t1 == -1)
            {
                t1 = i;
                continue;
            }

            // Determine distances
            t0 = t1;
            t1 = i;

            // Check for pileup
            if(t1 - t0 < dist)
            {
                // pileup
                for(int j = t0-conf.left; j < t1+conf.right; j++)
                {
                    if(j > 0 && j < (int)pileup_mask.size())
                    {
                        pileup_mask.at(j) = 1;
                    }
                }
            }
        }
    }

    // Extract signal
    for(int i = 0; i < (int)pileup_mask.size(); i++)
    {
        if(pileup_mask.at(i) == 1)
        {
            signalWithPileup.push_back(idata.at(i));
            triggerWithPileup.push_back(itrigger.at(i));
        }
        else
        {
            signalWithoutPileup.push_back(idata.at(i));
            triggerWithoutPileup.push_back(itrigger.at(i));
        }
    }

    outputs->at(0)->setData(QVariant::fromValue (signalWithPileup));
    outputs->at(1)->setData(QVariant::fromValue (triggerWithPileup));
    outputs->at(2)->setData(QVariant::fromValue (signalWithoutPileup));
    outputs->at(3)->setData(QVariant::fromValue (triggerWithoutPileup));
}
