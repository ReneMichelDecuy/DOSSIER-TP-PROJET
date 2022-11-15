//*********************************************************************************************
//* Programme : QtSerialPort.h date : 08/11/2022
//*---------------------------------------------------------------------------------------------------------
//* derni�re mise a jour : 09/11/2022
//*
//*Programmeurs : Ren�-Michel Decuy classe : BTSSN2
//* 
//*--------------------------------------------------------------------------------------------------------
//* BUT : �tude sondeur Marin et communication par liaison RS232
//*Programmes associ�s : Aucun
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

