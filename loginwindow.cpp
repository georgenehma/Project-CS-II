#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->labelError->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButtonLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    for (int i = 0; i < usersCount ; i++){
        if (usernames[i] == username){
            if (passwords[i]==password){
                hide();
                WelcomeWindow* welcome = new WelcomeWindow(this, ages[i], username);
                welcome->show();
                ui->labelError->setVisible(false);
                break;
            }
            else{
                ui->labelError->setVisible(true);
                break;
            }
        }
    }
    ui->labelError->setVisible(true);
}


void LoginWindow::on_pushButtonRegister_clicked()
{
    hide();
    RegisterWindow* reg = new RegisterWindow(this);
    reg->show();
}

