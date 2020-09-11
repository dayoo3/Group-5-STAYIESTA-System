#ifndef POPUPHOMESTAYUNAVAILABLE_H
#define POPUPHOMESTAYUNAVAILABLE_H

#include <QWidget>

namespace Ui {
class PopupHomestayUnavailable;
}

class PopupHomestayUnavailable : public QWidget
{
    Q_OBJECT

public:
    explicit PopupHomestayUnavailable(QWidget *parent = nullptr);
    ~PopupHomestayUnavailable();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupHomestayUnavailable *ui;
};

#endif // POPUPHOMESTAYUNAVAILABLE_H
