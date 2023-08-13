#pragma once

#include "icontext.h"

#include <QWidget>
#include <QLabel>
#include <QTextEdit>


class LessonContext : public IContext
{
	Q_OBJECT
public:
	explicit LessonContext(QWidget *parent, quint32 number);
	~LessonContext();

	quint32 getNumber() { return _number; }
	QString getLessonContextName() { return _edit->toPlainText(); }

	void updateNumber(quint32 number);

private:
	QLabel    *_label_string;
	QLabel    *_enumerate;
	QTextEdit *_edit;

	quint32   _number;
};

