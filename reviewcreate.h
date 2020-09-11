#ifndef REVIEWCREATE_H
#define REVIEWCREATE_H

#include <QWidget>

namespace Ui {
class ReviewCreate;
}

class ReviewCreate : public QWidget
{
    Q_OBJECT

public:
    explicit ReviewCreate(QWidget *parent = nullptr);
    ~ReviewCreate();

private slots:
    void on_buttonHome_clicked();

    void on_buttonReset_clicked();

    void on_buttonSubmit_clicked();

private:
    Ui::ReviewCreate *ui;
};


QString IDCheck() ;

#endif // REVIEWPANEL_H
