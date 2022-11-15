//*********************************************************************************************
//* Programme : QtSerialPort.cpp date : 08/11/2022
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 09/11/2022
//*
//*Programmeurs : René-Michel Decuy classe : BTSSN2
//* 
//*--------------------------------------------------------------------------------------------------------
//* BUT : Étude sondeur Marin et communication par liaison RS232
//*Programmes associés : QtSerialPort.h
//*********************************************************************************************
#include "QtSerialPort.h"
#include <QSerialPortInfo>
#include <QObject>
#include <QVariant>




QtSerialPort::QtSerialPort(QWidget *parent)
	: QObject(parent)
{
	//ui.setupUI(this);

	QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

	for (int i = 0; i < availablePorts.size(); i++)
	{
		QSerialPortInfo info = availablePorts[i];
		//ui.portComboBox->addItem(info.portName(), QVariant(info.portName()));
	}
}

void QtSerialPort::onOpenPortButtonClicked()
{
	//if (ui.portComboBox->currentIndex() >= 0)
	{
		port = new QSerialPort("COM1");
		QObject::connect(port, SIGNAL(readyRead()), this, SLOT(onSerialReadyRead()));
		port->setBaudRate(9600);
		port->setDataBits(QSerialPort::DataBits::Data8);
		port->setParity(QSerialPort::Parity::NoParity);
		port->setStopBits(QSerialPort::StopBits::OneStop);
		if (port->open(QIODevice::OpenModeFlag::ExistingOnly | QIODevice::OpenModeFlag::ReadWrite));
		{
			//ui.portStatusLabel->setText("Status port : Ouvert");
		}
	}
}

void QtSerialPort::onSerialPortReadyRead()
{
	QByteArray data = port->read(port->bytesAvailable());
	QString str(data);
	//ui.receivedDataText->insertPlainText(str);
}

void QtSerialPort::onSendMessageButtonClicked()
{
	if (port->isOpen())
	{
		//port->write(ui.lineEdit->text().toStdDtring().c_str());
	}
}