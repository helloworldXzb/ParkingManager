#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <registered.h>
#include <userwindow.h>
#include <parkingwindow.h>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QDebug>
#include <QSqlRecord>
#include <QTimer>
#include <qdatetime.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool sqlUserHasPendingOrder(const QString &firstField, const QString &tableName);
    bool sqlIsParkingSpaceAvailable(const QString &parkingname, int carpos, QString &carpostype);
    bool sqlIsParkingSpaceAvailableForNonRegistered(const QString &parkingname, int carpos, const QString &userCartype);
    bool sqlIsCarTypeCompatible(const QString &userid, const QString &carpostype);
    bool sqlUpdateParkingSpace(const QString &parkingname, int carpos, const QString &situation, const QDateTime &statime, const QDateTime &endtime);
    int  sqlGetMaxOrderNumber(const QString &tableName);
    bool sqlInsertNewOrder(const QString &userid, const QString &parkingname, int carpos, const QDateTime &statime, const QDateTime &endtime, const QString &finish,const QString &tableName);
    bool sqlUpdateParkingLotSpaces(const QString &parkingname, int spaceChange);
    //----
    void regist();
    void login();
    void connectmysql();
    void sqlregist(QString, QString, QString, QString, QString, QString);
    void quit();
    void sqlinq();
    void sqlinfo();
    void sqlupdateinfo(QString, QString, QString, QString);
    void sqlupdatepass(QString, QString);
    void sqlupdatebalance(int);
    //会员办理函数
    void sqlProcessMembership(const QString &membershipType);
    void sqlreservation(QString, int, QDateTime, QDateTime);
    //传入当前时间和userid,即可返回支付费用,时间差,用户类型
    std::tuple<int, int, int, QString> sqlCalculateParkingFee(const QDateTime &currentTime, const QString &userid);
    void updatetimeout();
    void sqluserpayment(QString userId,int duration, int money);
    void sqlProcessPayment(const QString &tableName, const QString &firstField, int money, int duration);
    void sqlconsumption();
    void sqlparkinglot();
    void sqlparkingspace();
    //新增车位设置页面情况展示函数
    void sqlparkingsettings_load();
    void sqldelparksetspace(int);
    void sqladdparksetspace(int , QString);
    //----新增临时更改函数,用于管理员确认用户id
    void processPaymentForUser(const QString &firstId,const QString &recordSource);
    //------------------------------------------------------------------以下是扫描模块功能主体函数
    //对扫描到的车牌进行分析
    void sqlCheckCarId(const QString &carId);
    void requestProcessNonRegisteredCar(const QString &carId, const QString &parkingName);
    //------------------------------------------------------------------以上是扫描模块功能主体函数
    //新增了carpostype[100],parkingfinish[10],parkingname,recordSource[100]为区分是否注册用户触发完结订单使用
    QString data[100][3], str[100][2], userIds[100],parkingstr[100],carpostype[100],parkingfinish[10],parkingname,recordSource[100];
    int arr[100], num[100][4], parkingnum[100];
    QDateTime tim[100][2], parkingtim[100][2];
    //len4记录管理员设置表长度，其他类推
    int len, len_2, len_3,len_4;

private:
    Ui::MainWindow *ui;
    registered registwindow;
    userwindow user;
    parkingwindow parker;
    QString userid, parkerid;
    parkingsettings parkset;

};

#endif // MAINWINDOW_H
