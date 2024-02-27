#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"
WelcomeWindow::WelcomeWindow(QWidget *parent, int age, QString username)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QPixmap pix ("/Users/georgekarim/Desktop/image.jpeg");
    int w = ui->labelImage->width();
    int h = ui->labelImage->height();
    ui->labelImage->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->labelWelcomeUser->setText("Welcome "+username+" "+QString::number(age));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButtonLogout_clicked()
{
    hide();
    LoginWindow* log = new LoginWindow(this);
    log->show();

}

