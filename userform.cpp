#include <QTextCursor>
#include <QDebug>
#include "userform.h"
#include "ui_userform.h"


UserForm::UserForm(QColor color, QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserForm),
    name(name),
    color(color)
{
    ui->setupUi(this);
    ui->username->setText(name);
    connect(ui->sendButton, &QPushButton::clicked, [&]{
        emit send(this->color, this->name, ui->lineEdit->text());
        ui->lineEdit->clear();
        //qDebug() << "clicked!!!";
    });
    connect( ui->lineEdit, &QLineEdit::textChanged, [=](QString msg) {
        ui->sendButton->setDisabled(msg.isEmpty());
    });
    ui->sendButton->setDisabled(ui->lineEdit->text().isEmpty());
}

UserForm::~UserForm()
{
    delete ui;
}

void UserForm::addText(QColor color, QString author, QString msg)
{
    // what is not included is removing text at the end. That could cause a problem if thousands of the message will be inserted.
    auto appendText = QString(R"(<font color="%1"><b>%2</b>:</font> <font color="blue">%3</font><br>)")
            .arg(color.name())
            .arg(author.toHtmlEscaped())
            .arg(msg.toHtmlEscaped());
    // something that surprised me in the video is that chat does not insert new messages at the top. If you prefer such behaviour please uncomment following line.
    //ui->textEdit->moveCursor(QTextCursor::Start);
    ui->textEdit->insertHtml(appendText);
}
