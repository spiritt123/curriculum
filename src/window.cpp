#include "window.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QLabel>
#include <QToolBar>
#include <QHBoxLayout>
#include <QLineEdit>


Window::Window(QMainWindow *parent, QString path) : 
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

//    setStyleSheet(loadStyle("css/style.css"));
//    setStyleSheet(loadStyle("css/background.css"));

	
	connect(ui->_button, &QPushButton::clicked, this, &Window::MakeItemSlot);

    this->resize(800, 600);

}

void Window::MakeItemSlot()
{
	qDebug() << "sfd";
	MakeItem(ui->_list);
}

void Window::MakeItem( QListWidget* lstWgt ) {
    QWidget* wgt = new QWidget((QWidget*)lstWgt->parent());
    QLayout* l = new QHBoxLayout();
    l->addWidget( new QLineEdit(QString::number(qrand() % 1000) ));
    QPushButton* btn = new QPushButton( "Click me" );
    connect( btn, SIGNAL( clicked() ), SLOT( onBtnClicked() ) );
    l->addWidget( btn );
    wgt->setLayout( l );

    QListWidgetItem* item = new QListWidgetItem( lstWgt );
    item->setSizeHint( wgt->sizeHint() );
    lstWgt->setItemWidget( item, wgt );
}

Window::~Window()
{
    delete ui;
}


