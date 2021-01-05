#include "signin.h"
#include "ui_signin.h"

SignIn::SignIn(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
//    ui->label_2->setText("<a href=\"http://example.com/\">Click Here!</a>");
//    ui->label_2->setTextFormat(Qt::RichText);
//    ui->label_2->setTextInteractionFlags(Qt::TextBrowserInteraction);
//    ui->label_2->setOpenExternalLinks(true);

    ui->label_email->hide();
    ui->label_password->hide();
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    // Hiding label
    ui->label_email->hide();

    QString styleSheet = ui->lineEdit->styleSheet();
    styleSheet += "border: 3px solid #3f00b5;";
    ui->lineEdit->setStyleSheet(styleSheet);
}

void SignIn::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text() == "") {
        QString styleSheet = ui->lineEdit->styleSheet();
        styleSheet += "border: 3px solid red;";
        ui->lineEdit->setStyleSheet(styleSheet);

        // label show
        ui->label_email->show();
        ui->label_email->setText("Enter an email");
        ui->label_email->setStyleSheet("color: red;");
    } else {
        ui->label_email->hide(); // hiding label

        QString styleSheet = ui->lineEdit->styleSheet();
        styleSheet += "border: 3px solid green;";
        ui->lineEdit->setStyleSheet(styleSheet);
    }
}

void SignIn::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{
    ui->label_password->hide(); // Hiding label

    QString styleSheet = ui->lineEdit_2->styleSheet();
    styleSheet += "border: 3px solid #3f00b5;";
    ui->lineEdit_2->setStyleSheet(styleSheet);
}

void SignIn::on_lineEdit_2_editingFinished()
{
    QString pass = ui->lineEdit_2->text();

    if(pass == "") {
        // Border Color Red
        QString styleSheet = ui->lineEdit_2->styleSheet();
        styleSheet += "border: 3px solid red;";
        ui->lineEdit_2->setStyleSheet(styleSheet);

        // Displayig Label
        ui->label_password->show();
        ui->label_password->setText("Enter a password");
        ui->label_password->setStyleSheet("color: red;");
    } else if (pass.length() < 8) {
        // Border Color Red
        QString styleSheet = ui->lineEdit_2->styleSheet();
        styleSheet += "border: 3px solid red;";
        ui->lineEdit_2->setStyleSheet(styleSheet);

        // Displayig Label
        ui->label_password->show();
        ui->label_password->setText("Password is too short (minimum is 8 characters)");
        ui->label_password->setStyleSheet("color: red;");
    } else {
        // hiding label
        ui->label_password->hide();

        // Border COlor green
        QString styleSheet = ui->lineEdit_2->styleSheet();
        styleSheet += "border: 3px solid green;";
        ui->lineEdit_2->setStyleSheet(styleSheet);
    }

}

void SignIn::on_label_2_linkActivated(const QString &link)
{
    signup = new Signup(this);
    hide();
    signup->show();
}
