#pragma once

#include <QWidget>


class IContex : public QWidget
{
	Q_OBJECT
public:
	explicit IContex(QWidget *parent) : QWidget(parent) {}
	~IContex() {}
	
private:

};

