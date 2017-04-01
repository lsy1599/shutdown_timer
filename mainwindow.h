#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <QTimer>
#include <QMessageBox>
#include <QByteArray>
#include <QDebug>
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_shutdownPushButton_clicked();

    void on_cancelPushButton_clicked();

    void on_action_A_triggered();

private:
    bool shutdown;
    QString shutdownStr;
    QString cancelShutdownStr;


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
