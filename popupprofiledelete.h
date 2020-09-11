#ifndef POPUPPROFILEDELETE_H
#define POPUPPROFILEDELETE_H

#include <QWidget>

namespace Ui {
class PopupProfileDelete;
}

class PopupProfileDelete : public QWidget
{
    Q_OBJECT

public:
    explicit PopupProfileDelete(QWidget *parent = nullptr);
    ~PopupProfileDelete();

  private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupProfileDelete *ui;
};

#endif // POPUPPROFILEDELETE_H
