//*********************************************************************************************
//* Programme : QtSerialPort.h date : 08/11/2022
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 09/11/2022
//*
//*Programmeurs : René-Michel Decuy classe : BTSSN2
//* 
//*--------------------------------------------------------------------------------------------------------
//* BUT : Étude sondeur Marin et communication par liaison RS232
//*Programmes associés : Aucun
//*********************************************************************************************
#pragma once

#include <QtWidgets/QMainWindow>
#include <QSerialPort>
#include <QObject>

class QtSerialPort : public QObject
{
	Q_OBJECT

public:
	QtSerialPort(QWidget *parent = Q_NULLPTR);

private:
	QSerialPort* port;

public slots:
	void onOpenPortButtonClicked();
	void onSerialPortReadyRead();
	void onSendMessageButtonClicked();


};

