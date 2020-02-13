#include "userform.h"
#include "ui_userform.h"

UserForm::UserForm(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm),
    name(name)
{
    ui->setupUi(this);
    ui->username->setText(name);
}

UserForm::~UserForm()
{
    delete ui;
}
