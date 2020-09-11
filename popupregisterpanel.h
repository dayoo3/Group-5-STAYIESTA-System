#ifndef POPUPREGISTERPANEL_H
#define POPUPREGISTERPANEL_H

#include <QDialog>

namespace Ui {
class PopupRegisterPanel;
}

class PopupRegisterPanel : public QDialog
{
    Q_OBJECT

public:
    explicit PopupRegisterPanel(QWidget *parent = nullptr);
    ~PopupRegisterPanel();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupRegisterPanel *ui;
};

#endif // POPUPREGISTERPANEL_H
