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
//#include <opencv2/opencv.hpp>
#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QByteArray>
#include <QUrlQuery>
#include <functional>// functional用于回调函数的标准库支持
//以下多为为扫描按钮使用
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QIntValidator>
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
    void print(QString parkingstr[], int parkingnum[], QDateTime parkingtim[][2],QString recordSource[],int len);
    QString encodeToBase64(const QString &filePath); // 将图片转换为 Base64

    void processNonRegisteredCar(const QString &carId, const QString &parkingName);
    std::optional<std::pair<int, QString>> getNonRegisteredCarInfo(const QString &carId);
 //在 parkingwindow.h 中声明 finishOrder 信号,通过发送参数完结订单
signals:
    void finishOrder(const QString &firstId,const QString &recordSource);
    void showParkSettings(); // 用于请求显示 parkset 界面
    void requestCheckCarId(const QString &carId);// 发送信号请求校验车牌号
    void requestInsertNonRegisteredCar(const QString &carId, const QString &parkingName, const QString &carType, int carPos, const QDateTime &startTime);
private slots:
    void on_pushButton_clicked();
    void on_scanButton_clicked();

private:
    Ui::parkingwindow *ui;
    QGridLayout *pLayout;
    // 功能函数
    void getAccessToken(std::function<void(const QString &)> callback); // 获取 Access Token
    void recognizeLicensePlate(const QString &imageBase64, const QString &accessToken); // 调用车牌识别接口

    // 替换为你的百度云 API Key 和 Secret Key
    const QString CLIENT_ID = "KiFHYP52lFCK34hGfFnqa84s";
    const QString CLIENT_SECRET = "NU8m5Wwpe5oxmaUir5GHrmbPBCUcChwA";



};

#endif // PARKINGWINDOW_H
