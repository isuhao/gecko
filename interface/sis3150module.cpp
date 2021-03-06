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

#include <iostream>
#include "sis3150module.h"
#include "interfacemanager.h"

static InterfaceRegistrar registrar ("sis3150", Sis3150Module::create);

Sis3150Module::Sis3150Module(int _id, QString _name)
    : BaseInterface(_id, _name)
    , id (getId ())
    , name (getName ())
{
    m_device = 0;
    deviceOpen = false;

    // Setup
    conf.base_addr = 0x20000000;

    // Create user interface
    setUI (new Sis3150UI(this));

    std::cout << "Instantiated Sis3150 Module" << std::endl;
}

Sis3150Module::~Sis3150Module()
{
    if(isOpen()) this->close();
}

int Sis3150Module::open()
{
    int status;
    unsigned int found;

    Sis3150UI* ui = dynamic_cast<Sis3150UI*>(getUI());

    //! Find connected devices
    status = FindAll_SIS3150USB_Devices(info, &found, 1);
    ui->outputText("Found "
                   + QString("%1").arg(found,2)
                   + " devices with status "
                   + QString("%1").arg(status,2,16) + "\n");
    if(status != 0)
    {
        ui->outputText("No device found!\n");
        return 1;
    }

    //! Open the device
    if(found >= 1)
    {
        //status = Sis3150usb_OpenDriver((PCHAR)info[0].cDName, &m_device);
        status = Sis3150usb_OpenDriver_And_Download_FX2_Setup((PCHAR)info[0].cDName, &m_device);
        if(status != 0)
        {
            ui->outputText("ERROR: "
                   + QString("%1").arg(status,2,16)
                   + " \n");
            return status;
        }
    }
    else
    {
        ui->outputText("No device found!\n");
        return 1;
    }
    deviceOpen = true;
    ui->outputText("Device opened.\n");
    ui->moduleOpened ();

    return 0;
}

bool Sis3150Module::isOpen() const
{
    return deviceOpen;
}

int Sis3150Module::close()
{
    int status;

    Sis3150UI* ui = dynamic_cast<Sis3150UI*>(getUI());

    //! Close the device
    if(m_device != 0) {
        status = Sis3150usb_CloseDriver(m_device);
        deviceOpen = false;
        ui->outputText("Device closed\n");
    } else {
        ui->outputText("Device already closed.\n");
    }
    ui->moduleClosed ();

    return 0;
}

int Sis3150Module::readA32D32(const uint32_t addr, uint32_t* data)
{
    //return vme_A32D32_read(m_device,addr,data);
    return sis3150_vme_A32D32_read(m_device,addr,data);
}

int Sis3150Module::writeA32D32(const uint32_t addr, const uint32_t data)
{
    //return vme_A32D32_write(m_device,addr,data);
    return sis3150_vme_A32D32_write(m_device,addr,data);
}

int Sis3150Module::readA32D16(const uint32_t addr, uint16_t* data)
{
    //return vme_A32D16_read(m_device,addr,data);
    return sis3150_vme_A32D16_read(m_device,addr,data);
}

int Sis3150Module::writeA32D16(const uint32_t addr, const uint16_t data)
{
    //return vme_A32D16_write(m_device,addr,data);
    return sis3150_vme_A32D16_write(m_device,addr,data);
}

int Sis3150Module::readA32DMA32(const uint32_t addr, uint32_t* dma_buffer,
                                uint32_t request_nof_words, uint32_t* got_nof_words)
{
    return sis3150Usb_Vme_Dma_Read(m_device, addr, 0x9, 4, 0, dma_buffer, request_nof_words, got_nof_words);
}

int Sis3150Module::readA32FIFO(const uint32_t addr, uint32_t* dma_buffer,
                                uint32_t request_nof_words, uint32_t* got_nof_words)
{
    return sis3150Usb_Vme_Dma_Read(m_device, addr, 0x9, 4, 1, dma_buffer, request_nof_words, got_nof_words);
}

int Sis3150Module::readA32BLT32(const uint32_t addr, uint32_t* dma_buffer,
                                uint32_t request_nof_words, uint32_t* got_nof_words)
{
    return sis3150Usb_Vme_Dma_Read(m_device, addr, 0xf, 4, 0, dma_buffer, request_nof_words, got_nof_words);
}

int Sis3150Module::readA32MBLT64(const uint32_t addr, uint32_t* dma_buffer,
                                uint32_t request_nof_words, uint32_t* got_nof_words)
{
    return sis3150Usb_Vme_Dma_Read(m_device, addr, 0x8, 8, 0, dma_buffer, request_nof_words & 0xfffffffe, got_nof_words);
}

int Sis3150Module::readA322E(const uint32_t addr, uint32_t* dma_buffer,
                             uint32_t request_nof_words, uint32_t* got_nof_words)
{
    //return sis3150Usb_Vme_Dma_Read(m_device, addr, 0x20, 4, 0, dma_buffer, request_nof_words, got_nof_words);
    return sis3150Usb_Vme_Dma_Read(m_device, addr, 0x8, 8, 0, dma_buffer, request_nof_words & 0xfffffffe, got_nof_words);
}

/*!
\page sis3150if SIS 3150 USB-to-VME Interface
<b>Module name:</b> \c sis3150

\section desc Module Description
Provides access to a VME crate via a USB interface.

\section Configuration Panel
The configuration panel provides basic test functionality and the means for sending arbitrary commands over the VME bus.
*/

