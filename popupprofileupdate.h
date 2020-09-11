#ifndef POPUPPROFILEUPDATE_H
#define POPUPPROFILEUPDATE_H

#include <QWidget>

namespace Ui {
class PopupProfileUpdate;
}

class PopupProfileUpdate : public QWidget
{
    Q_OBJECT

public:
    explicit PopupProfileUpdate(QWidget *parent = nullptr);
    ~PopupProfileUpdate();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupProfileUpdate *ui;
};

#endif // POPUPPROFILEUPDATE_H
