#include "window.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QLabel>
#include <QToolBar>
#include <QHBoxLayout>
#include <QLineEdit>

#include <iostream>
#include "topic.h"
#include "lesson_context.h"

Window::Window(QMainWindow *parent, QString path) : 
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

	connect(ui->_button_topic_create, &QPushButton::clicked, this, &Window::MakeNewTopic);
	connect(ui->_button_lesson_create, &QPushButton::clicked, this, &Window::MakeNewLesson);

    this->resize(800, 600);

}

void Window::MakeNewTopic()
{
	Topic *widget = new Topic(this, 0);

	MakeItem(ui->_list, widget);
}

void Window::MakeNewLesson()
{
	LessonContext *widget = new LessonContext(this, 0);

	MakeItem(ui->_list, widget);
}

void Window::MakeItem( QListWidget* list_widget, IContext *context ) 
{
    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint( context->sizeHint() );

	int row = list_widget->row(list_widget->selectedItems().last());
	list_widget->insertItem(row + 1, item);

    list_widget->setItemWidget( item, context );
}

Window::~Window()
{
    delete ui;
}

void Window::onBtnClicked() {
    if( QPushButton* btn = qobject_cast< QPushButton* >( sender() ) ) {
        if( QLineEdit* e = btn->parent()->findChild< QLineEdit* >() ) {
            QMessageBox::information( this, "Button was clicked!", e->text() );
            return;
        }
    }
}


