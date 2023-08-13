#pragma once

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QMessageBox>

#include <vector>

#include "icontext.h"

namespace Ui
{
    class Window;
} // namespace

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QMainWindow *parent = 0, QString path = "./settings.txt");
    virtual ~Window();

signals:

public slots:
	void MakeItem(QListWidget* list_widget, IContext *context);
	void MakeNewTopic();
	void MakeNewLesson();
	void onBtnClicked();
private:

    Ui::Window *ui;
};

