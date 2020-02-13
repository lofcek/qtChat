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
    explicit UserForm(const QString& name, QWidget *parent = nullptr);
    ~UserForm();

private:
    Ui::UserForm *ui;
    QString name;
};

#endif // USERFORM_H
