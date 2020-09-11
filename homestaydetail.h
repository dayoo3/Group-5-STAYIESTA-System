#ifndef HOMESTAYDETAIL_H
#define HOMESTAYDETAIL_H

#include <QWidget>

namespace Ui {
class HomestayDetail;
}

class HomestayDetail : public QWidget
{
    Q_OBJECT

public:
    explicit HomestayDetail(QWidget *parent = nullptr);
    ~HomestayDetail();

private slots:
    void on_buttonBook_clicked();

    void on_buttonReturn_clicked();

    void on_buttonHome_clicked();

    void on_buttonNextRev_clicked();

    void on_buttonPrevRev_clicked();

private:
    Ui::HomestayDetail *ui;
};

void refreshTable(Ui::HomestayDetail*);
void getFormData();
void setFormData(Ui::HomestayDetail*);

static QVector<QString> reviewVect;
static int i;

#endif // HOMESTAYDETAIL_H
