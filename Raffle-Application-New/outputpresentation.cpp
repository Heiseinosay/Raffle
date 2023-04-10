#include "outputpresentation.h"
#include "ui_outputpresentation.h"

#include "inputform.h"
#include <QPixmap>

OutputPresentation::OutputPresentation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutputPresentation)
{
    ui->setupUi(this);
    //Z-order
    ui->btnEdit->raise();

    //Icons
    ui->btnDeleteName->setIcon(QIcon(":/img/img/trash.png"));
    ui->btnEdit->setIcon(QIcon(":/img/img/edit.png"));

    ui->themeSelection->addItem(QIcon(":/img/img/gold.png"), "Gold");
    ui->themeSelection->addItem(QIcon(":/img/img/red.png"), "Red");
    ui->themeSelection->addItem(QIcon(":/img/img/pink.png"), "Pink");
    ui->themeSelection->addItem(QIcon(":/img/img/green.png"), "Green");
}

OutputPresentation::~OutputPresentation()
{
    delete ui;
}

void OutputPresentation::on_btnEdit_clicked()
{
    hide();
    InputForm inputForm;
    inputForm.setModal(true);
    inputForm.exec();
}


void OutputPresentation::on_themeSelection_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
        {
            QPixmap background1(":/img/img/GoldBg.jpg");
            ui->BackgroundTheme->setPixmap(background1);
            ui->BackgroundTheme->setPixmap(background1.scaled(1450, 920,Qt::KeepAspectRatio));
            ui->CelebrationTitle->setStyleSheet("color: #C49503");
            ui->WinnerName->setStyleSheet("color: #C49503");
            ui->PrizeName->setStyleSheet("color: #C49503");
            break;
        }
        case 1:
        {
            QPixmap background2(":/img/img/RedBg.jpg");
            ui->BackgroundTheme->setPixmap(background2);
            ui->BackgroundTheme->setPixmap(background2.scaled(1450, 920,Qt::KeepAspectRatio));
            ui->CelebrationTitle->setStyleSheet("color: #C41703");
            ui->WinnerName->setStyleSheet("color: #C41703");
            ui->PrizeName->setStyleSheet("color: #C41703");
            break;
        }
        case 2:
        {
            QPixmap background3(":/img/img/PinkBg.jpg");
            ui->BackgroundTheme->setPixmap(background3);
            ui->BackgroundTheme->setPixmap(background3.scaled(1450, 920,Qt::KeepAspectRatio));
            ui->CelebrationTitle->setStyleSheet("color: #C800D6");
            ui->WinnerName->setStyleSheet("color: #C800D6");
            ui->PrizeName->setStyleSheet("color: #C800D6");
            break;
        }
        case 3:
        {
            QPixmap background4(":/img/img/GreenBg.jpg");
            ui->BackgroundTheme->setPixmap(background4);
            ui->BackgroundTheme->setPixmap(background4.scaled(1450, 920,Qt::KeepAspectRatio));
            ui->CelebrationTitle->setStyleSheet("color: #317E34");
            ui->WinnerName->setStyleSheet("color: #317E34");
            ui->PrizeName->setStyleSheet("color: #317E34");
            break;
        }
        default:
            QPixmap background5(":/img/img/GoldBg.jpg");
            ui->BackgroundTheme->setPixmap(background5);
            ui->BackgroundTheme->setPixmap(background5.scaled(1450, 920,Qt::KeepAspectRatio));
            ui->CelebrationTitle->setStyleSheet("color: #C49503}");
            ui->WinnerName->setStyleSheet("color: #C49503");
            ui->PrizeName->setStyleSheet("color: #C49503");
    }

}

