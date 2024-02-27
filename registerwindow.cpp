#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"
RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->labelErrorPassword->setVisible(false);
    ui->labelErrorUsername->setVisible(false);
    ui->labelErrorRegister->setVisible(false);
    ui->labelErrorAge->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButtonRegister_clicked()
{
    bool error_check[4]={true, true, true, true};
    ui->labelErrorPassword->setVisible(false);
    ui->labelErrorUsername->setVisible(false);
    ui->labelErrorRegister->setVisible(false);
    ui->labelErrorAge->setVisible(false);
    QString username = ui->lineEditUsername->text();
    QString password1 = ui->lineEditPassword->text();
    QString password2 = ui->lineEditPasswordRetry->text();
    QString str = ui->lineEditYear->text();
    QString month = ui->comboBoxMonth->currentText();
    QString day = ui->lineEditDay->text();
    int year = str.toInt();
    //Check 1
    for (int i = 0 ; i<usersCount ; i++){
        if (usernames[i]==username){
            error_check[0]=false;
            ui->labelErrorUsername->setVisible(true);
            break;
        }
    }
    //Check 2
    if (password1!=password2){
        error_check[1]=false;
        ui->labelErrorPassword->setVisible(true);
    }
    //Check 3
    if ((2024-year)<12){
        error_check[2]=false;
        ui->labelErrorAge->setVisible(true);
    }
    //Check 4
    if (month==""||day==""||str==""||username==""||password2==""||password1=="" ||!(ui->radioButtonFemale->isChecked()||ui->radioButtonMale->isChecked())|| !(ui->radioButtonUser->isChecked()||ui->radioButtonAdmin->isChecked())||!(ui->checkBoxAction->isChecked()||ui->checkBoxComedy->isChecked()||ui->checkBoxRomance->isChecked()||ui->checkBoxDrama->isChecked()||ui->checkBoxHorror->isChecked()||ui->checkBoxOther->isChecked())){
        error_check[3]=false;
        ui->labelErrorRegister->setVisible(true);
    }
    //Going to login
    if (error_check[0]&&error_check[1]&&error_check[2]&&error_check[3]){
        usernames[usersCount]=username;
        passwords[usersCount]=password1;
        ages[usersCount]=2024-year;
        usersCount++;
        hide();
        WelcomeWindow* welcome = new WelcomeWindow(this, 2024-year, username);
        welcome->show();
    }


}

