#include "window.h"
#include "ui_mainwindow.h"
#include <QDebug>


Window::Window(QMainWindow *parent, QString path) : 
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

//    setStyleSheet(loadStyle("css/style.css"));
//    setStyleSheet(loadStyle("css/background.css"));

    this->resize(800, 600);

}

Window::~Window()
{
    delete ui;
}


