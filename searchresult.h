#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QWidget>

namespace Ui {
class SearchResult;
}

class SearchResult : public QWidget
{
    Q_OBJECT

public:
    explicit SearchResult(QWidget *parent = nullptr);
    ~SearchResult();

private slots:
    void on_buttonBook_clicked();

    void on_buttonCancel_clicked();

    void on_buttonHome_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_buttonFilter_clicked();

    void on_buttonReset_clicked();

    void on_buttonDetail_clicked();

private:
    Ui::SearchResult *ui;
};

void refreshTable(Ui::SearchResult*);

QString getSearchActivatedID();
QString getSearchBID();

#endif // SEARCHRESULT_H
