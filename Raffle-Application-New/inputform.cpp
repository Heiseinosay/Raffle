#include "inputform.h"
#include "ui_inputform.h"
#include <QMessageBox>
#include <QTextStream>
#include <QTextBlock>
#include <stdio.h>
#include <string.h>
#include <QPixmap>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <chrono>
#include <thread>
#include <ctime>
#include <cstdlib>

using namespace std;

InputForm::InputForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputForm)
{
    ui->setupUi(this);
    //DropDown
    ui->PrizeSelectionMode->addItem("Random");
    ui->PrizeSelectionMode->addItem("Descending");
    ui->PrizeSelectionMode->addItem("Ascending");

    //Icon
    ui->btnInfromation->setIcon(QIcon(":/img/img/about.png"));
    //ui->btnSave->setIcon(QIcon(":/img/img/diskette.png"));
    //ui->btnOpen->setIcon(QIcon(":/img/img/folder.png"));

    //Logo
    QPixmap pix(":/img/img/Ticket.png");
    ui->logo->setPixmap(pix);
    ui->logo->setPixmap(pix.scaled(50, 50,Qt::KeepAspectRatio));

    //TextEdit
    ui->textEditName->setDisabled(true);
    ui->textEditPrize->setDisabled(true);

    // ThemeSelection Drop down
    ui->themeSelection->addItem(QIcon(":/img/img/gold.png"), "Gold");
    ui->themeSelection->addItem(QIcon(":/img/img/red.png"), "Red");
    ui->themeSelection->addItem(QIcon(":/img/img/pink.png"), "Pink");
    ui->themeSelection->addItem(QIcon(":/img/img/green.png"), "Green");

    //Celebration title Sample Text
    ui->lineEditTitle->setText("Sample Text");

    // Disable Resize
    this->setFixedSize(QSize(1280, 812));

}

InputForm::~InputForm()
{
    delete ui;
}

void InputForm::on_themeSelection_currentIndexChanged(int index)
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


void InputForm::on_btnQuit_clicked()
{
    QMessageBox::StandardButton answerQuit = QMessageBox::question(
                this, "Quit", "Recent changes may not have been saved. Are you sure you want to quit?",
                QMessageBox::Yes | QMessageBox::No);

    if (answerQuit == QMessageBox::Yes) {
        QApplication::quit();
    }

}

// Instructions Message Box
void InputForm::on_btnInfromation_clicked()
{
    QMessageBox::information(this, "Instructions",
                             "Input form\n\t1. Click the text field button to add names and prizes. \n\t2. Click the \"+\" button to add more participants and prizes.\n\t3. Click the pencil button to edit, and the trash button to delete.\n\t4. Click the next button below when you are done, clear button\n\tto empty all fields and the quit button if you want to exit.\n\nRaffle Window\n\t1. Press the start button to begin the hunt. \n\t2. Click the pencil button to return to the input form and edit details.\n\t3. Click the trash button to exit.");

}

//Reboot to clear
void InputForm::on_btnClear_clicked()
{
    QMessageBox::StandardButton answerQuit = QMessageBox::question(
                this, "Clear", "Recent changes may not have been saved. Are you sure you want to clear all fields?",
                QMessageBox::Yes | QMessageBox::No);

    if (answerQuit == QMessageBox::Yes) {
        close();

        InputForm inputForm;
        inputForm.setModal(true);
        inputForm.exec();
    }

}

//TextEdit Buttons
//Edit button Names
void InputForm::on_btnEditName_clicked()
{
    ui->textEditName->setDisabled(false);
}

//Add button Names
void InputForm::on_btnAddName_clicked()
{
    ui->textEditName->setDisabled(true);
    int textEditNameLength = ui->textEditName->document()->blockCount();
    ui->NameCount->setText(QString::number(textEditNameLength));
}

//Edit button Prizes
void InputForm::on_btnEditPrize_clicked()
{
    ui->textEditPrize->setDisabled(false);
}

//Add button Prizes
void InputForm::on_btnAddPrize_clicked()
{
    ui->textEditPrize->setDisabled(true);
    int textEditPrizeLength = ui->textEditPrize->document()->blockCount();
    ui->PrizeCount->setText(QString::number(textEditPrizeLength));
}

// global variables
QString names[100];
QString prizes[100];

int counterNames = 0;
int counterPrize = 0;

//Btn Go
void InputForm::on_btnStart_clicked()
{
    //NAME
    //Reset Array Size
    memset( names, 0, sizeof( names ) );
    //qDebug() << names->length() << "line 190";
    int textEditLength = ui->textEditName->document()->blockCount();
    //qDebug() << "textEdit length:" << textEditLength;

    //Array Names append
    for (int i = 0; i < textEditLength; i++) {
        QTextDocument *doc = ui->textEditName->document();
        QTextBlock tb = doc->findBlockByLineNumber(i); // The second line.
        QString s = tb.text();

        if(s.isEmpty()) {
            //qDebug() << "Hey Empty here Line: 126";
        } else if(!s.isEmpty()) {
            //qDebug() << i + 1;
            names[i] = s;
        }
    }

    // Print Name Array
    for (int j = 0; j < names->length(); j++) {
        if (names[j] == "") {
            break;
        } else {
            qDebug() << names[j];
        }

    }

    //Prize
    //Reset Array Size
    memset( prizes, 0, sizeof( prizes ) );
    int textEditPrizeLength = ui->textEditPrize->document()->blockCount();
    //qDebug() << textEditPrizeLength;

    //Array Prize append
    for (int i = 0; i < textEditPrizeLength; i++) {
        QTextDocument *doc = ui->textEditPrize->document();
        QTextBlock tb = doc->findBlockByLineNumber(i); // The second line.
        QString s = tb.text();

        if(s.isEmpty()) {
            //qDebug() << "Hey Empty here Line: 126";
        } else if(!s.isEmpty()) {
            //qDebug() << i + 1;
            prizes[i] = s;
        }
    }

    //Display Celebration title
    QString Title = ui->lineEditTitle->text();
    ui->CelebrationTitle->setText(Title);

    // Back to Zero;
    counterNames = 0;
    counterPrize = 0;
}


// File Save and Open
void InputForm::on_btnSaveName_clicked()
{
    //qDebug() << "Im here Line: 217";
    QString file_name = QFileDialog::getSaveFileName(this, "Save names", "C://.txt");
    QFile file(file_name);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "title", "file not save");
    }

    QTextStream out(&file);
    QString text = ui->textEditName->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void InputForm::on_btnOpenName_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "C://");
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEditName->setPlainText(text);

    file.close();
}

void InputForm::on_btnSavePrize_clicked()
{
    qDebug() << "Im here Line: 236";
    QString file_name = QFileDialog::getSaveFileName(this, "Save prizes", "C://.txt");
    QFile file(file_name);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "title", "file not save");
    }

    QTextStream out(&file);
    QString text = ui->textEditPrize->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void InputForm::on_btnOpenPrize_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "C://");
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "title", "file not open");
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEditPrize->setPlainText(text);

    file.close();
}


// Raffle Button Hunt-----------------------------------------------------------------------------------------------------------------
void InputForm::on_btnRoll_clicked()
{
    int textEditNameLength = ui->textEditName->document()->blockCount();
    int textEditPrizeLength = ui->textEditPrize->document()->blockCount();
    int descPrize = textEditPrizeLength - 1;
    int ascPrize = 0;
    if (counterNames == textEditNameLength || counterPrize == textEditPrizeLength) {
        QMessageBox::warning(this, "Notice!", "No more Entries");
    } else {
        //Flash the random letters
        QString randomNamesFlash[25] = {"dfgrgs sadw dsaf", "aFwwerdsg dsfyvny", "ioierimib ifwiemnsd",
                                        "pewprfj woeromneq", "sdbnlopry xcriopw", "mpyatcdvf aitpmzdtc",
                                        "dfgrgs sadw dsaf", "aFwwerdsg dsfyvny", "ioierimib ifwiemnsd",
                                        "dfgrgs sadw dsaf", "aFwwerdsg dsfyvny", "ioierimib ifwiemnsd",
                                        "pewprfj woeromneq", "sdbnlopry xcriopw", "mpyatcdvf aitpmzdtc",
                                        "dfgrgs sadw dsaf", "aFwwerdsg dsfyvny", "ioierimib ifwiemnsd",
                                        "pewprfj woeromneq", "sdbnlopry xcriopw", "mpyatcdvf aitpmzdtc",
                                        "dfgrgs sadw dsaf"};

        QString randomPrizeFlash[25] = {"ktmnmyuiy sdagarhwqebv", "ahsioudsg sdaghhrpert", "pokfdnbeu asdfioeruntre",
                                        "iouerngfgf sdagiweahut", "fsfefhewry ewgsdgdsfh", "mkbeoopiuosa isdhfgidsg",
                                        "ktmnmyuiy sdagarhwqebv", "ahsioudsg sdaghhrpert", "pokfdnbeu asdfioeruntre",
                                        "iouerngfgf sdagiweahut", "fsfefhewry ewgsdgdsfh", "mkbeoopiuosa isdhfgidsg",
                                        "ktmnmyuiy sdagarhwqebv", "ahsioudsg sdaghhrpert", "pokfdnbeu asdfioeruntre",
                                        "iouerngfgf sdagiweahut", "fsfefhewry ewgsdgdsfh", "mkbeoopiuosa isdhfgidsg",
                                        "ktmnmyuiy sdagarhwqebv", "ahsioudsg sdaghhrpert", "pokfdnbeu asdfioeruntre",
                                        "iouerngfgf sdagiweahut", "fsfefhewry ewgsdgdsfh", "mkbeoopiuosa isdhfgidsg",
                                         "ktmnmyuiy sdagarhwqebv"};

        for (int i = 0; i < 24; i++) {
                this_thread::sleep_for(chrono::milliseconds(0200));
                ui->WinnerName->setText(randomNamesFlash[i]);
                ui->PrizeName->setText(randomPrizeFlash[i]);
                qApp->processEvents();
        }

        // Choose Random Name
        srand(time(0));
        int randNumName = 0 + (rand() % (textEditNameLength - counterNames));
        qDebug() << randNumName;
        ui->WinnerName->setText(names[randNumName]);

        // Names
        int n = sizeof(names)/sizeof(names[0]);
        QString xName = names[randNumName];

        // Delete x from names[]
        int i;
        for (i = 0; i < n; i++)
            if (names[i] == xName)
                break;

        if (i < n)
        {
            n = n - 1;
            for (int j= i; j < n; j++)
                names[j] = names[j+1];
        }

        for (int k = 0; k < textEditNameLength; k++) {
            qDebug() << names[k];
        }
        counterNames++;
        //qDebug() << "length" << counterNames;

        // Prize
        int prizeSelectionIndex = ui->PrizeSelectionMode->currentIndex();

        switch (prizeSelectionIndex) {
            case 0:
            {
                // Choose Random Prize
                qDebug() << "random";
                srand(time(0));
                int randNumPrize = 0 + (rand() % (textEditPrizeLength - counterPrize));
                qDebug() << randNumPrize;
                ui->PrizeName->setText(prizes[randNumPrize]);

                // Names
                int n = sizeof(prizes)/sizeof(prizes[0]);
                QString xPrize = prizes[randNumPrize];

                // Delete x from names[]
                int i;
                for (i = 0; i < n; i++)
                    if (prizes[i] == xPrize)
                        break;

                if (i < n)
                {
                    n = n - 1;
                    for (int j= i; j < n; j++)
                        prizes[j] = prizes[j+1];
                }
                break;
            }
        case 1:
            {
                descPrize -= counterPrize;
                ui->PrizeName->setText(prizes[descPrize]);

                break;
            }
         case 2:
            {
                qDebug() << "ascending";
                ascPrize += counterPrize;
                ui->PrizeName->setText(prizes[ascPrize]);
                break;
            }
        }

        counterPrize++;

    }

}






