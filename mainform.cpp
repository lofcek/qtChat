#include "ui_mainform.h"
#include "mainform.h"
#include "userform.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    auto user1 = new UserForm(GetCurrentUsername());
    ui->verticalLayout->addWidget(user1);

    auto user2 = new UserForm("Coding Challenge");
    ui->verticalLayout->addWidget(user2);
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
