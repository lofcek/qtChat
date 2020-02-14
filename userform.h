#ifndef USERFORM_H
#define USERFORM_H

#include <QWidget>

namespace Ui {
class UserForm;
}

class UserForm : public QWidget
{
    Q_OBJECT

public:
    UserForm(QColor color, QString name, QWidget *parent = nullptr);
    ~UserForm();

signals:
    void send(QColor color, QString author, QString msg);

public slots:
    void addText(QColor color, QString author, QString msg);

private:
    Ui::UserForm *ui;
    QString name;
    QColor color;
};

#endif // USERFORM_H
