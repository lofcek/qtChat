#include <QTextCursor>
#include "userform.h"
#include "ui_userform.h"


UserForm::UserForm(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm),
    name(name)
{
    ui->setupUi(this);
    ui->username->setText(name);
    addText(Qt::red, "user1<br>",  "hello world!<br>");
    addText(Qt::blue, "user2", "hello world!");
    addText(Qt::green, "user3", "hello world!");
}

UserForm::~UserForm()
{
    delete ui;
}

void UserForm::addText(QColor color, const QString& user, const QString& text)
{
    // what is not included is removing text at the end. That could cause a problem if thousands of the message will be inserted.
    auto appendText = QString(R"(<font color="%1">%2:</font> <font color="blue">%3</font><br>)")
            .arg(color.name())
            .arg(user.toHtmlEscaped())
            .arg(text.toHtmlEscaped());
    ui->textEdit->moveCursor(QTextCursor::Start);
    ui->textEdit->insertHtml(appendText);
}
