#ifndef HOMESTAYVIEW_H
#define HOMESTAYVIEW_H

#include <QWidget>

namespace Ui {
class HomestayView;
}

class HomestayView : public QWidget
{
    Q_OBJECT

public:
    explicit HomestayView(QWidget *parent = nullptr);
    ~HomestayView();

private slots:

    void on_buttonAdd_clicked();

    void on_buttonUpdate_clicked();

    void on_buttonDelete_clicked();

    void on_buttonHome_clicked();

    void on_tableView_activated(const QModelIndex &index);


private:
    Ui::HomestayView *ui;
};

void refreshTable(Ui::HomestayView*);

QString getHomestayActivatedID();

static QString templateID = "";

#endif // HOMESTAYVIEW_H
