#include <QDebug>
#include "ui_mainform.h"
#include "mainform.h"
#include "userform.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    auto user1 = new UserForm(Qt::red, GetCurrentUsername());
    ui->verticalLayout->addWidget(user1);

    auto user2 = new UserForm(Qt::blue, "Coding Challenge");
    ui->verticalLayout->addWidget(user2);


    connect(user1, &UserForm::send, user2, &UserForm::addText);
    connect(user2, &UserForm::send, user1, &UserForm::addText);
    // connect send and addText of the same UserForm is done in ui
}

MainForm::~MainForm()
{
    delete ui;
}

QString MainForm::GetCurrentUsername()
{
    QString name = qgetenv("USER");
    if (!name.isEmpty())
        return name;
    name = qgetenv("USERNAME");
    if (!name.isEmpty())
        return name;
    return "Unknown";
}
