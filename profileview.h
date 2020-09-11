#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <QWidget>

namespace Ui {
class ProfileView;
}

class ProfileView : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileView(QWidget *parent = nullptr);
    ~ProfileView();

private slots:

    void on_buttonHome_clicked();

    void on_buttonDelete_clicked();

    void on_buttonUpdate_clicked();

    void on_buttonReward_clicked();

private:
    Ui::ProfileView *ui;
};

void getFormData(Ui::ProfileView*);


#endif // PROFILEVIEW_H
