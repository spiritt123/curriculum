#pragma once

#include <QMainWindow>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QListWidget>
#include <QMessageBox>

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

signals:
	void MakeItemSignal();

public slots:
	void MakeItem(QListWidget* list_widget);
	void MakeItemSlot();
	void onBtnClicked();
private:

    Ui::Window *ui;
};

