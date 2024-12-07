#ifndef PARKINGSETTINGS_H
#define PARKINGSETTINGS_H

#include <QWidget>
#include <QMessageBox>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariantList>
#include <QDebug>
#include <QLayout>
#include <QLayoutItem>
#include <QPushButton>
#include <QCloseEvent>

namespace Ui {
class parkingsettings;
}

class parkingsettings : public QWidget
{
    Q_OBJECT

public:
    explicit parkingsettings(QWidget *parent = nullptr);
    ~parkingsettings();
    //管理员设置页面打印
    void setprint(QString parkingname,int carpos[],QString carpostype[], QString situation[],int len);
protected:
    void closeEvent(QCloseEvent *event) override;
signals:
    void delsignal(int);
    void addsignal(int,QString);
    void returnparkingwindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::parkingsettings *ui;
    QGridLayout *pLayout;

};

#endif // parkingsettings_H
