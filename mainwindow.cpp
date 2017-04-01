#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("关机小助手");
    this->shutdownStr = "shutdown -s -t ";
    this->cancelShutdownStr = "shutdown -a ";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_shutdownPushButton_clicked()
{
    this->shutdown = true;
    int time = ui->timeSpinBox->value();
    this->shutdownStr = this->shutdownStr+QString::number(time);
    system(this->shutdownStr.toLocal8Bit().data());
    qDebug() << this->shutdownStr.toLocal8Bit().data() ;
    QMessageBox::information(this,"关机","OK,已经准备好了亲");
}

void MainWindow::on_cancelPushButton_clicked()
{
    if(false == this->shutdown)
    {
        QMessageBox::information(this,"关机","取消成功");
        return ;
    }
    //QString to char*
    system(this->cancelShutdownStr.toLocal8Bit().data());
    QMessageBox::information(this,"关机","取消成功");
}

void MainWindow::on_action_A_triggered()
{
    Dialog *dialog = new Dialog;
    dialog->exec();
}
