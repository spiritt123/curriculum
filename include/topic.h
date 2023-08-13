#pragma once

#include "icontext.h"

#include <QWidget>
#include <QLabel>
#include <QLineEdit>


class Topic : public IContex
{
	Q_OBJECT
public:
	explicit Topic(QWidget *parent, quint32 number);
	~Topic();

	quint32 getNumber() { return _number; }
	QString getTopicName() { return _edit->text(); }

	void updateNumber(quint32 number);

private:
	QLabel    *_label_string;
	QLabel    *_enumerate;
	QLineEdit *_edit;

	quint32   _number;
};

