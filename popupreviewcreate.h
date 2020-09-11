#ifndef POPUPREVIEWCREATE_H
#define POPUPREVIEWCREATE_H

#include <QWidget>

namespace Ui {
class PopupReviewCreate;
}

class PopupReviewCreate : public QWidget
{
    Q_OBJECT

public:
    explicit PopupReviewCreate(QWidget *parent = nullptr);
    ~PopupReviewCreate();

private slots:
    void on_buttonOK_clicked();

private:
    Ui::PopupReviewCreate *ui;
};

#endif // POPUPREVIEWCREATE_H
