#pragma once

#include "topic.h"

#include <QLayout>
//#include <QPushButton>

Topic::Topic(QWidget *parent, quint32 number)
	: IContex(parent)
	, _number(number)
{
    QLayout* layout = new QHBoxLayout();
	_label_string = new QLabel("Тема");
	_enumerate = new QLabel("№" + QString::number(_number) + ". ");
	_edit = new QLineEdit();

	layout->addWidget(_label_string);
	layout->addWidget(_enumerate);
	layout->addWidget(_edit);
    //QPushButton* button = new QPushButton( "Click me" );
    //connect( button, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
    //layout->addWidget( button );
    this->setLayout( layout );
}

Topic::~Topic()
{}

void Topic::updateNumber(quint32 number)
{
	_number = number;
	_enumerate->setText("№" + QString::number(_number) + ". ");
}
