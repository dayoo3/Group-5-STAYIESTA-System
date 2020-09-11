#ifndef PROFILEDELETE_H
#define PROFILEDELETE_H

#include <QWidget>

namespace Ui {
class ProfileDelete;
}

class ProfileDelete : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileDelete(QWidget *parent = nullptr);
    ~ProfileDelete();

private slots:
    void on_lineEditPass_returnPressed();

    void on_buttonCancel_clicked();

    void on_buttonConfirm_clicked();

private:
    Ui::ProfileDelete *ui;
};

#endif // PROFILEDELETE_H
