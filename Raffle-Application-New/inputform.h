#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QDialog>
#include "outputpresentation.h"

namespace Ui {
class InputForm;
}

class InputForm : public QDialog
{
    Q_OBJECT

public:
    explicit InputForm(QWidget *parent = nullptr);
    ~InputForm();

public slots:


private slots:
    void on_btnStart_clicked();

    void on_btnQuit_clicked();

    void on_btnInfromation_clicked();

    void on_btnClear_clicked();

    void on_btnEditName_clicked();

    void on_btnAddName_clicked();

    void on_btnAddPrize_clicked();

    void on_btnEditPrize_clicked();

    void on_themeSelection_currentIndexChanged(int index);

    void on_btnSaveName_clicked();

    void on_btnOpenName_clicked();

    void on_btnSavePrize_clicked();

    void on_btnOpenPrize_clicked();

    void on_btnRoll_clicked();


private:
    Ui::InputForm *ui;

};

#endif // INPUTFORM_H
