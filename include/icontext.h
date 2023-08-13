#pragma once

#include <QWidget>


class IContext : public QWidget
{
	Q_OBJECT
public:
	explicit IContext(QWidget *parent) : QWidget(parent) {}
	virtual ~IContext() {}
	
private:

};

