#include "window.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QLabel>
#include <QToolBar>
#include <QHBoxLayout>
#include <QLineEdit>

#include <iostream>
#include "topic.h"

Window::Window(QMainWindow *parent, QString path) : 
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

	connect(ui->_button, &QPushButton::clicked, this, &Window::MakeItemSlot);

    this->resize(800, 600);

}

void Window::MakeItemSlot()
{
	MakeItem(ui->_list);
}

void Window::MakeItem( QListWidget* list_widget ) 
{
	Topic *widget = new Topic(this, 0);

    QListWidgetItem* item = new QListWidgetItem();
    item->setSizeHint( widget->sizeHint() );

	int row = list_widget->row(list_widget->selectedItems().last());
	list_widget->insertItem(row + 1, item);

    list_widget->setItemWidget( item, widget );
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


