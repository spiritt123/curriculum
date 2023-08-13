#include "lesson_context.h"
#include "icontext.h"

#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

//#include <QPushButton>

LessonContext::LessonContext(QWidget *parent, quint32 number)
	: IContext(parent)
	, _number(number)
{
    QVBoxLayout* layout = new QVBoxLayout();
    QHBoxLayout* line   = new QHBoxLayout();
	_label_string = new QLabel("Занятие");
	_enumerate = new QLabel("№" + QString::number(_number));
	_edit = new QTextEdit();

	line->addWidget(_label_string);
	line->addWidget(_enumerate);
	line->setAlignment(Qt::AlignLeft);
	layout->addLayout(line);
	layout->addWidget(_edit);
    //QPushButton* button = new QPushButton( "Click me" );
    //connect( button, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
    //layout->addWidget( button );
    this->setLayout( layout );
}

LessonContext::~LessonContext()
{}

void LessonContext::updateNumber(quint32 number)
{
	_number = number;
	_enumerate->setText("№" + QString::number(_number) + ". ");
}
