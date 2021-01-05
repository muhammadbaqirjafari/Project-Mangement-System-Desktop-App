#ifndef SIGNIN_H
#define SIGNIN_H

#include <QMainWindow>
#include "signup.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SignIn; }
QT_END_NAMESPACE

class SignIn : public QMainWindow
{
    Q_OBJECT

public:
    SignIn(QWidget *parent = nullptr);
    ~SignIn();

private slots:


    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);
    void on_lineEdit_2_editingFinished();

    void on_label_2_linkActivated(const QString &link);

private:
    Ui::SignIn *ui;
    Signup * signup;
};
#endif // SIGNIN_H
