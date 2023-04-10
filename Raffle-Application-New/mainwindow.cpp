#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QPainter>
#include "inputform.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/Ticket.png");
    ui->LabelTicket->setPixmap(pix);
    ui->LabelTicket->setPixmap(pix.scaled(50, 37,Qt::KeepAspectRatio));

    // Disable Resize
    this->setFixedSize(QSize(842, 449));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btCreate_clicked()
{
    close();
    InputForm inputForm;
    inputForm.setModal(true);
    inputForm.exec();
}

