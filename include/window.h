#pragma once

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>

#include <vector>


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

public slots:

private:

    Ui::Window *ui;
};

