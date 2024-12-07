#ifndef PARKINGWINDOW_H
#define PARKINGWINDOW_H


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
#include <QTimer>
#include <qdatetime.h>
#include <QPushButton>
#include <parkingsettings.h>

namespace Ui {
class parkingwindow;
}

class parkingwindow : public QWidget
{
    Q_OBJECT

public:
    explicit parkingwindow(QWidget *parent = nullptr);
    ~parkingwindow();
    void setline(int, int, int);
    void print(QString parkingstr[], int parkingnum[], QDateTime parkingtim[][2], int len);


 //在 parkingwindow.h 中声明 finishOrder 信号,通过发送参数完结订单
signals:
    void finishOrder(const QString &userId, int duration, int money);
    void showParkSettings(); // 用于请求显示 parkset 界面
private slots:
    void on_pushButton_clicked();
private:
    Ui::parkingwindow *ui;
    QGridLayout *pLayout;

};

#endif // PARKINGWINDOW_H
