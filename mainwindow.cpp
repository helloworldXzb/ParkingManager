#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 连接 MySQL 数据库
    connectmysql();

    // 定时器，用于实时更新时间显示，超时时间+缴纳费用
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatetimeout);
    timer->start(1000);

    // 设置界面字体颜色为白色
    QPalette pe;
    pe.setColor(QPalette::WindowText,Qt::white);

    ui->label->setPalette(pe);
    ui->label_3->setPalette(pe);
    ui->label_4->setPalette(pe);
    ui->label_5->setPalette(pe);


    ui->groupBox->setPalette(pe);
    ui->pushButton->setPalette(pe);
    ui->pushButton_2->setPalette(pe);

    // 设置密码输入模式为隐藏
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

     // 设置背景图片
    QPixmap pixmap = QPixmap(":/ground.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    // 信号与槽函数连接
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::regist);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::login);
    connect(&registwindow, &registered::sendregist, this, &MainWindow::sqlregist);
    connect(&user, &userwindow::sendquit, this, &MainWindow::quit);
    connect(&user, &userwindow::sendprint, this, &MainWindow::sqlinq);
    connect(&user, &userwindow::send_main_updateinfo, this, &MainWindow::sqlupdateinfo);
    connect(&user, &userwindow::send_main_updatepass, this, &MainWindow::sqlupdatepass);
    connect(&user, &userwindow::send_main_balance, this, &MainWindow::sqlupdatebalance);
    //会员办理
    connect(&user, &userwindow::send_main_yearmember, this, [this]() {
        sqlProcessMembership("年费会员");
    });
    connect(&user, &userwindow::send_main_monthmember, this, [this]() {
        sqlProcessMembership("月费会员");
    });
    connect(&user, &userwindow::send_main_reservation, this, &MainWindow::sqlreservation);
    connect(&user, &userwindow::send_main_payment, this, [this] {
        // 获取当前时间
        QDateTime currentTime = QDateTime::currentDateTime();
        // 用封装的费用计算函数，获取费用和时长
        auto [money, totalDuration, overTimeDuration, userType] = sqlCalculateParkingFee(currentTime, userid);
        // 调用支付处理函数
        qDebug() << "计费的时间:" << totalDuration;
        qDebug() << "实际收取费用:" << money;
        sqluserpayment(userid, money, totalDuration);
    });

    connect(&user, &userwindow::send_main_consumption, this, &MainWindow::sqlconsumption);

    connect(&parker, &parkingwindow::finishOrder, this, &MainWindow::processPaymentForUser);
    //管理员页面按钮跳转触发调整车位页面
    connect(&parker, &parkingwindow::showParkSettings, this, &MainWindow::sqlparkingsettings_load);
    //管理员删除车位
    connect(&parkset, &parkingsettings::delsignal, this, &MainWindow::sqldelparksetspace);
    connect(&parkset, &parkingsettings::addsignal, this, &MainWindow::sqladdparksetspace);
    // 连接 parkingsettings 的 returnparkingwindow 信号返回界面
    connect(&parkset, &parkingsettings::returnparkingwindow, this, [&]() {
        sqlparkingspace();
        sqlparkinglot();
        parker.show();
    });
    //校验扫描车牌的连接
    connect(&parker, &parkingwindow::requestCheckCarId, this, &MainWindow::sqlCheckCarId);


}


//processPaymentForUser 槽函数，传递id帮助结算完成
void MainWindow::processPaymentForUser(const QString &firstId,const QString &recordSource) {
    QDateTime currentTime = QDateTime::currentDateTime();

    //是用户则用户正常支付流程
    if (recordSource=="book"){
        // 用封装的费用计算函数，获取费用和时长
        auto [money, totalDuration, overTimeDuration, userType] = sqlCalculateParkingFee(currentTime, firstId);

        sqlProcessPayment("book", firstId, money, totalDuration);
    }
    else if(recordSource=="nuserbook"){
        // 查询 statime
        QSqlQuery query;
        QString statimeQuery = QString("SELECT statime FROM nuserbook WHERE nusercarid = '%1' AND finish = 'no'").arg(firstId);
        QDateTime statime;

        if (query.exec(statimeQuery) && query.next()) {
            statime = query.value(0).toDateTime();
        } else {
            QMessageBox::warning(nullptr, "错误", "未能查询到开始时间，无法计算费用。");
            return;
        }

        // duration 为实际停车时长（单位：秒）
        int totalSeconds = statime.secsTo(currentTime);

        // 停车时长（单位：小时，未满一小时按一小时算）
        int roundedHours = ceil(totalSeconds / 3600.0);

        // 费用按每小时 3 元计算
        int money = roundedHours * 3;

        // 调用支付处理函数
        sqlProcessPayment("nuserbook", firstId, money, roundedHours);

    }
    else{
        return;
    }
    // 刷新管理员界面的停车信息
    sqlparkingspace();
    sqlparkinglot();
}

// 连接 MySQL 数据库
void MainWindow::connectmysql() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    // 设置数据库连接参数
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("123456");
    db.setDatabaseName("parking");

    // 尝试打开数据库连接
    if (!db.open()) {
        // 如果连接失败，弹出错误信息
        QString errorMsg = QString("数据库连接失败：%1").arg(db.lastError().text());
        QMessageBox::warning(this, QStringLiteral("错误"), errorMsg, QMessageBox::Ok);
        return;
    }

    // 连接成功，提示用户
    QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("数据库成功连接！"), QMessageBox::Ok);

}


// 打开注册窗口
void MainWindow::regist(){
    registwindow.show();
}

// 登录功能实现
void MainWindow::login(){
    QString account = this->ui->lineEdit->text();
    QString password = this->ui->lineEdit_2->text();
    if(account.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("账号密码不能为空"), QMessageBox::Yes);
    }
    else{
        if(!ui->radioButton->isChecked() && !ui->radioButton_2->isChecked())
        {
            QMessageBox::warning(nullptr, QStringLiteral("警告"), QStringLiteral("请选择你的身份"), QMessageBox::Yes);
        }
        else if(ui->radioButton_2->isChecked())
        {
            QSqlQuery query;
            QString rightword;
            QString str = QString("select password from userinfo where id = '%1'").arg(account);
            query.exec(str);
            while(query.next())
            {
                rightword = query.value(0).toString();
            }
//            qDebug() << rightword << endl;
            if(password == rightword){
                userid = account;
                qDebug() << "成功登录，赋值userid" << userid;
                this->hide();
                this->sqlinq();
                this->sqlinfo();
                user.show();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
            else{
                QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("账号密码错误"), QMessageBox::Yes);
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
        }
        else {// 停车场管理员登录
            QSqlQuery query;
            QString rightword;
            QString str = QString("select parkingpassword from parkinglot where parkingid = '%1'").arg(account);
            query.exec(str);
            while(query.next())
            {
                rightword = query.value(0).toString();
            }
            if(password == rightword){
                parkerid = account;
                this->sqlparkingspace();
                this->sqlparkinglot();
                parker.show();
                this->hide();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
            else{
                QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("账号密码错误"), QMessageBox::Yes);
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
            }
        }
    }

}
// 注册信息保存到数据库
void MainWindow::sqlregist(QString id, QString password, QString name, QString carid, QString cartype, QString tel){
    QSqlQuery query;
    QString str = QString("insert into userinfo(id,name,tel,type,balance,password) values('%1', '%2', '%3', '普通用户', 0, '%4')").arg(id).arg(name).arg(tel).arg(password);
    QString str_2 = QString("insert into carinfo(id,carid,cartype) values('%1', '%2', '%3')").arg(id).arg(carid).arg(cartype);
    if(query.exec(str) && query.exec(str_2)){
        QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("注册成功！"), QMessageBox::Yes);
    }
    else{
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("该用户名已被注册"), QMessageBox::Yes);
    }
}
// 查询空闲停车位
void MainWindow::sqlinq(){

    QSqlQuery query;
    QString inquire = QString("select * from parkingspace where situation = '空闲'");
    query.exec(inquire);
    int i = 0;
    while(query.next()){
        data[i][0] = query.value(2).toString();
        data[i][1] = query.value(3).toString();
        data[i][2] = query.value(1).toString();
        arr[i] = query.value(0).toInt();
        i++;
    }
    len = i;

    user.print(data, arr, len);
}
// 获取并显示用户信息
void MainWindow::sqlinfo(){
    QString name, carid, tel, cartype, type;
    int balance = 0;
    QSqlQuery query;
    QString inquire = QString("select * from userinfo where id = '%1'").arg(userid);
    query.exec(inquire);
    while(query.next()){
        name = query.value(1).toString();
        tel = query.value(2).toString();
        type = query.value(3).toString();
        balance = query.value(4).toInt();
    }
    QString inquire_2 = QString("select * from carinfo where id = '%1'").arg(userid);
    query.exec(inquire_2);
    while(query.next()){
        carid = query.value(1).toString();
        cartype = query.value(2).toString();
    }
    user.printinfo(userid, name, carid, tel, cartype, type, balance);
}
// 更新用户信息
void MainWindow::sqlupdateinfo(QString name, QString tel, QString carid, QString cartype){
    QSqlQuery query;
    QString str = QString("update userinfo set name = '%1' where id = '%2'").arg(name).arg(userid);
    query.exec(str);
    QString str_2 = QString("update userinfo set tel = '%1' where id = '%2'").arg(tel).arg(userid);
    query.exec(str_2);
    QString str_3 = QString("update carinfo set carid = '%1' where id = '%2'").arg(carid).arg(userid);
    query.exec(str_3);
    QString str_4 = QString("update carinfo set cartype = '%1' where id = '%2'").arg(cartype).arg(userid);
    query.exec(str_4);
    QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("修改成功"), QMessageBox::Yes);
    this->sqlinfo();
}
// 更新用户密码
void MainWindow::sqlupdatepass(QString oldpass, QString newpass){
    QSqlQuery query;
    QString inquire = QString("select password from userinfo where id = '%1'").arg(userid);
    query.exec(inquire);
    QString nowpass;
    while(query.next()){
        nowpass = query.value(0).toString();
    }
    if(nowpass != oldpass){
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("输入的旧密码不正确"), QMessageBox::Yes);
    }
    else{
        QString str = QString("update userinfo set password = '%1' where id = '%2'").arg(newpass).arg(userid);
        query.exec(str);
        QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("修改成功"), QMessageBox::Yes);
    }
}
// 充值更新余额
void MainWindow::sqlupdatebalance(int balance){
    QSqlQuery query;
    QString inquire = QString("select balance from userinfo where id = '%1'").arg(userid);
    query.exec(inquire);
    while(query.next()){
        balance += query.value(0).toInt();
    }
    QString str = QString("update userinfo set balance = '%1' where id = '%2'").arg(balance).arg(userid);
    query.exec(str);
    QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("充值成功"), QMessageBox::Yes);
    this->sqlinfo();
}

void MainWindow::sqlProcessMembership(const QString &membershipType) {
    QSqlQuery query;

    // 定义收费金额
    int membershipFee = 0;
    if (membershipType == "月费会员") {
        membershipFee = 260;
    } else if (membershipType == "年费会员") {
        membershipFee = 2500;
    } else {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("无效的会员类型"), QMessageBox::Yes);
        return;
    }

    // 查询用户余额、当前会员类型和有效期
    QString inquire = QString("SELECT balance, type, valid_until FROM userinfo WHERE id = '%1'").arg(userid);
    query.exec(inquire);

    int balance = 0;
    QString currentType;
    QDateTime validUntil;

    while (query.next()) {
        balance = query.value(0).toInt();
        currentType = query.value(1).toString();
        validUntil = query.value(2).toDateTime();
    }

    // 检查用户是否已是年费会员
    if (membershipType == "年费会员" && currentType == "年费会员") {
        QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("您已是年费会员，有效期至：%1")
                                                                        .arg(validUntil.toString("yyyy-MM-dd hh:mm:ss")),
                                 QMessageBox::Yes);
        return;
    }

    // 检查余额是否足够
    if (balance < membershipFee) {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("余额不足，请充值"), QMessageBox::Yes);
        return;
    }

    // 扣除会员费用并更新余额
    balance -= membershipFee;
    QString updateBalanceQuery = QString("UPDATE userinfo SET balance = %1 WHERE id = '%2'").arg(balance).arg(userid);
    query.exec(updateBalanceQuery);

    // 更新用户会员类型
    QString updateTypeQuery = QString("UPDATE userinfo SET type = '%1' WHERE id = '%2'").arg(membershipType).arg(userid);
    query.exec(updateTypeQuery);

    // 更新会员有效期
    QDateTime newValidUntil = QDateTime::currentDateTime();
    if (validUntil.isValid() && validUntil > QDateTime::currentDateTime()) {
        newValidUntil = (membershipType == "月费会员") ? validUntil.addMonths(1) : validUntil.addYears(1); // 续费
    } else {
        newValidUntil = (membershipType == "月费会员") ? newValidUntil.addMonths(1) : newValidUntil.addYears(1); // 新会员
    }

    QString updateValidUntilQuery = QString("UPDATE userinfo SET valid_until = '%1' WHERE id = '%2'")
                                        .arg(newValidUntil.toString("yyyy-MM-dd hh:mm:ss"))
                                        .arg(userid);
    query.exec(updateValidUntilQuery);

    // 提示成功并显示截止时间
    QMessageBox::information(nullptr, QStringLiteral("提示"),
                             QStringLiteral("%1办理成功！会员有效期至：%2")
                                 .arg(membershipType)
                                 .arg(newValidUntil.toString("yyyy-MM-dd hh:mm:ss")),
                             QMessageBox::Yes);

    this->sqlinfo();
}


//预约按钮数据库层判定
void MainWindow::sqlreservation(QString parkingname, int carpos, QDateTime statime, QDateTime endtime){
    // 1. 检查用户是否有未完成订单
    if (sqlUserHasPendingOrder(userid,"book")){
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("您有一个订单在进行中"), QMessageBox::Yes);
        return;
    }

    // 2. 检查车位是否空闲
    QString carpostype;
    if (!sqlIsParkingSpaceAvailable(parkingname, carpos, carpostype)) return;

    // 3. 检查车位类型与用户车型是否匹配
    if (!sqlIsCarTypeCompatible(userid, carpostype)) return;

    // 4. 更新车位状态
    if (!sqlUpdateParkingSpace(parkingname, carpos, "占用", statime, endtime)) return;

    // 5. 插入新订单
    if (!sqlInsertNewOrder(userid, parkingname, carpos, statime, endtime, "no", "book" )) return;

    // 6. 更新停车场空位数量
    if (!sqlUpdateParkingLotSpaces(parkingname, -1)) return;

    // 7. 结束提示
    QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("预约成功"), QMessageBox::Yes);
}

//提供给注册用户用的计算再返回函数
std::tuple<int, int, int, QString> MainWindow::sqlCalculateParkingFee(const QDateTime &currentTime, const QString &userid) {
    QSqlQuery query;
    qDebug() << "准备查询开始时间和结束时间userid:" << userid;

    // 查询开始时间和结束时间（仅针对未完成的订单）
    QString timeQuery = QString("SELECT statime, endtime FROM book WHERE id = '%1' AND finish = 'no'")
                            .arg(userid);
    QDateTime startTime, endTime;

    if (query.exec(timeQuery) && query.next()) {
        startTime = query.value(0).toDateTime();
        endTime = query.value(1).toDateTime();
    } else {
        qDebug() << "查询开始时间和结束时间失败：" << query.lastError().text();
        return {0, 0, 0, ""}; // 返回默认值，避免程序崩溃
    }

    qDebug() << "表中显示开始时间：" << startTime;
    qDebug() << "当前时间：" << currentTime;
    qDebug() << "表中显示的结束时间：" << endTime;



    // 计算用于计费的停车时长（向上取整）
    int totalDuration = ceil(startTime.secsTo(currentTime) / 3600.0); // 总停车时长（向上取整小时）

    // 计算超时时长（向上取整小时）
    int overTimeDuration = (!endTime.isNull() && currentTime > endTime)
                               ? ceil(endTime.secsTo(currentTime) / 3600.0)
                               : 0;

    qDebug() << "计费停车时长（向上取整）：" << totalDuration;
    qDebug() << "算出的超预约时长：" << overTimeDuration;

    // 查询用户类型
    QString userTypeQuery = QString("SELECT type FROM userinfo WHERE id = '%1'").arg(userid);
    QString userType;

    if (query.exec(userTypeQuery) && query.next()) {
        userType = query.value(0).toString();
    } else {
        qDebug() << "查询用户类型失败：" << query.lastError().text();
        return {0, totalDuration, overTimeDuration, ""};
    }

    // 计算费用
    int money = (userType == "普通用户") ? totalDuration * 3 : 0;

    qDebug() << "实际收取费用：" << money;

    // 返回费用、计费总时长、超时时长、用户类型
    return {money, totalDuration, overTimeDuration, userType};
}





//登录用户可查看的超时和支付费用信息刷新函数
void MainWindow::updatetimeout() {
    // 获取当前时间
    QDateTime currentTime = QDateTime::currentDateTime();
    QSqlQuery query;

    // 查询 `ordernum` 最大值对应的 `finish` 状态
    QString finishQuery = QString("SELECT finish, ordernum FROM book WHERE id = '%1' ORDER BY ordernum DESC LIMIT 1").arg(userid);
    QString finishStatus;
    int latestOrderNum = -1;

    if (query.exec(finishQuery) && query.next()) {
        finishStatus = query.value(0).toString(); // 获取 finish 状态
        latestOrderNum = query.value(1).toInt();  // 获取最新的 ordernum
    } else {
        qDebug() << "查询用户完成状态失败：" << query.lastError().text();
        return;
    }

    // 如果订单已完成，直接更新用户界面并返回
    if (finishStatus == "yes") {
        qDebug() << "最新订单已完成";
        user.usersetpayment("未预约", 0, 0);
        return;
    }

    // 订单未完成，调用封装函数计算停车费用、时长等
    auto [money, totalDuration, overTimeDuration, userType] = sqlCalculateParkingFee(currentTime, userid);

    // 检查计算结果是否有效
    if (totalDuration <= 0) {
        qDebug() << "停车时长无效，可能是时间数据异常";
        user.usersetpayment("已预约", 0, 0);
        return;
    }

    // 更新用户支付信息
    user.usersetpayment("已预约", overTimeDuration, money);

    // 调试信息输出
    qDebug() << "用户类型：" << userType;
    qDebug() << "超时时长：" << overTimeDuration;
    qDebug() << "应付费用：" << money;
    qDebug() << "最新订单编号：" << latestOrderNum;
}





//此处封装的函数兼容了用户和非注册顾客通过判定进行正常支付的情况，如果是用户则传入userid即可使用，否则传入carid
void MainWindow::sqlProcessPayment(const QString &tableName, const QString &firstField, int money, int duration) {
    QSqlQuery query;
    QString parkingname;
    int carpos = 0;
    QDateTime statime, endtime, currentTime = QDateTime::currentDateTime();

    // 1. 查询停车场名称、车位号、订单号、开始时间
    QString selectQuery = QString("SELECT parkingname, carpos, ordernum, statime, endtime FROM %1 WHERE %2 = '%3' AND finish = 'no'")
                              .arg(tableName)
                              .arg((tableName == "book") ? "id" : "nusercarid")
                              .arg(firstField);

    if (query.exec(selectQuery) && query.next()) {
        parkingname = query.value(0).toString();
        carpos = query.value(1).toInt();

        statime = query.value(3).toDateTime();
        endtime = query.value(4).toDateTime(); // endtime 可能为 NULL
    } else {
        qDebug() << "查询订单详细信息失败或无未完成订单：" << query.lastError().text();
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("未找到未完成的订单，无法完成支付操作！"), QMessageBox::Yes);
        return;
    }

    // 2. 如果是非注册用户 (nuserbook)，将当前时间插入到 endtime 字段
    if (tableName != "book") {
        QString updateEndTimeQuery = QString("UPDATE nuserbook SET endtime = '%1' WHERE nusercarid = '%2' AND finish = 'no'")
        .arg(currentTime.toString("yyyy-MM-dd hh:mm:ss"))
            .arg(firstField);
        if (!query.exec(updateEndTimeQuery)) {
            qDebug() << "更新 nuserbook 表中的 endtime 失败：" << query.lastError().text();
            return;
        }
    }

    // 3. 判断结束时间
    QDateTime finalEndTime = currentTime; // 默认结束时间为当前时间
    QString reservationStatus = "";       // 提示是否在预约时间内
    QString overTimeInfo;                 // 用于提示超出预约时间的信息

    if (!endtime.isNull() && currentTime > endtime) {
        // 超过预约时间，取当前时间为结束时间
        finalEndTime = currentTime;

        // 计算超出预约时间的时长（以小时和分钟为单位）
        int overtimeSeconds = endtime.secsTo(currentTime);
        int overtimeHours = overtimeSeconds / 3600;
        int overtimeMinutes = (overtimeSeconds % 3600) / 60;

        if (overtimeHours > 0 || overtimeMinutes > 0) {
            overTimeInfo = QString("超出预约时间 %1 小时 %2 分钟。").arg(overtimeHours).arg(overtimeMinutes);
        }
    } else if (!endtime.isNull()) {
        // 未超过预约时间，取预约的 endtime
        finalEndTime = endtime;
        reservationStatus = "尚在预约时间内，已经完结订单。"; // 特殊提示
    }

    qDebug() << "最终视为结束的时间 finalEndTime：" << finalEndTime;

    // 计算实际停车时长（以小时和分钟为单位）
    int totalSeconds = statime.secsTo(finalEndTime);
    int actualHours = totalSeconds / 3600;
    int actualMinutes = (totalSeconds % 3600) / 60;

    qDebug() << "totalSeconds:" << totalSeconds;
    qDebug() << "actualHours:" << actualHours;
    qDebug() << "actualMinutes:" << actualMinutes;

    // 4. 更新停车场状态
    QString updateParkingSpace = QString("UPDATE parkingspace SET situation = '空闲' "
                                         "WHERE carpos = '%1' AND parkingname = '%2'")
                                     .arg(carpos)
                                     .arg(parkingname);
    if (!query.exec(updateParkingSpace)) {
        qDebug() << "更新停车位状态失败：" << query.lastError().text();
        return;
    }

    // 停车场金额增加
    QString updateParkingLot = QString("UPDATE parkinglot SET emptynum = emptynum + 1, income = income + '%1' WHERE parkingname = '%2'")
                                   .arg(money)
                                   .arg(parkingname);
    if (!query.exec(updateParkingLot)) {
        qDebug() << "更新停车场收入失败：" << query.lastError().text();
        return;
    }

    // 5. 插入消费记录
    int newOrderNum = 0;
    // 获取当前最大的 ordernum
    if (query.exec("SELECT MAX(ordernum) FROM consumption") && query.next()) {
        newOrderNum = query.value(0).toInt() + 1;
    }
    QString insertConsumption = QString(
                                    "INSERT INTO consumption (id, ordernum, carpos, parkingname, statime, endtime, timeout, fare) "
                                    "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8')")
                                    .arg((tableName == "book") ? firstField : QString("nuser:%1").arg(firstField)) // 非注册用户标记
                                    .arg(newOrderNum)
                                    .arg(carpos)
                                    .arg(parkingname)
                                    .arg(statime.toString("yyyy-MM-dd hh:mm:ss"))
                                    .arg(finalEndTime.toString("yyyy-MM-dd hh:mm:ss"))
                                    .arg(duration)
                                    .arg(money);
    if (!query.exec(insertConsumption)) {
        qDebug() << "插入消费记录失败：" << query.lastError().text();
        return;
    }

    // 6. 若为注册用户，更新余额
    if (tableName == "book") {
        QString updateBalance = QString("UPDATE userinfo SET balance = balance - '%1' WHERE id = '%2'")
        .arg(money)
            .arg(firstField);
        if (!query.exec(updateBalance)) {
            qDebug() << "更新用户余额失败：" << query.lastError().text();
            return;
        }
    }



    // 7. 最后更新订单状态为完成
    QString updateOrderQuery = QString("UPDATE %1 SET finish = 'yes' WHERE %2 = '%3' AND finish = 'no'")
                                   .arg(tableName)
                                   .arg((tableName == "book") ? "id" : "nusercarid")
                                   .arg(firstField);
    if (!query.exec(updateOrderQuery)) {
        qDebug() << "更新订单状态失败：" << query.lastError().text();
        return;
    }

    // 8. 显示提示信息：实际停车时长和是否预约内
    QString message = QString("订单完成，车位已释放！\n\n"
                              "实际停车时长：%1 小时 %2 分钟\n"
                              "支付金额：%3 元\n%4%5")
                          .arg(actualHours)
                          .arg(actualMinutes)
                          .arg(money)
                          .arg(reservationStatus.isEmpty() ? "" : reservationStatus + "\n")
                          .arg(overTimeInfo.isEmpty() ? "" : overTimeInfo);

    QMessageBox::information(nullptr, QStringLiteral("提示"), message, QMessageBox::Yes);
}





void MainWindow::sqluserpayment(QString userId,int duration, int money) {
    QSqlQuery query;
    // 查询用户余额
    QString inquire = QString("select balance from userinfo where id = '%1'").arg(userId);
    query.exec(inquire);
    int balance = 0;
    while (query.next()) {
        balance = query.value(0).toInt();
    }

    // 检查余额是否足够
    if (balance < money) {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("余额不足，请先充值"), QMessageBox::Yes);
    } else {
        sqlProcessPayment("book", userid, money,duration );
        //更新空闲车位信息+显示
        this->sqlinq();
        //更新用户余额信息+显示
        this->sqlinfo();
    }
}

void MainWindow::sqlconsumption() {
    QSqlQuery query;
    // 查询消费记录
    QString inquire = QString("select * from consumption where id = '%1'").arg(userid);
    query.exec(inquire);
    int i = 0;
    while (query.next()) {
        str[i][0] = query.value(0).toString();  // 用户ID
        str[i][1] = query.value(3).toString();  // 停车场名称
        num[i][0] = query.value(1).toInt();     // 订单号
        num[i][1] = query.value(2).toInt();     // 车位
        num[i][2] = query.value(6).toInt();     // 超时
        num[i][3] = query.value(7).toInt();     // 收费
        tim[i][0] = query.value(4).toDateTime(); // 开始时间
        tim[i][1] = query.value(5).toDateTime(); // 结束时间
        i++;
    }
    len_2 = i;
    user.recordprint(str, num, tim, len_2); // 打印消费记录
}
// 查询停车场总空车位和收入信息并打印
void MainWindow::sqlparkinglot() {
    QSqlQuery query;
    QString inquire = QString("SELECT * FROM parkinglot WHERE parkingname = '%1'").arg(parkingname);
    if (!query.exec(inquire)) {
        qDebug() << "SQL 查询失败:" << query.lastError().text();
        return;
    }

    int posnum = 0, emptynum = 0, income = 0;

    // 获取 parkinglot 表中的当前数据
    if (query.next()) {
        posnum = query.value(1).toInt();   // 总车位
        emptynum = query.value(2).toInt(); // 空车位
        income = query.value(3).toInt();   // 收入
    }

    //qDebug() << "停车场原始信息:" << parkingname << "总车位:" << posnum << "空车位:" << emptynum << "收入:" << income;

    // 查询 parkingspace 表，统计实际总车位和空车位
    QString spaceQuery = QString("SELECT situation FROM parkingspace WHERE parkingname = '%1'").arg(parkingname);
    if (!query.exec(spaceQuery)) {
        qDebug() << "SQL 查询失败:" << query.lastError().text();
        return;
    }

    int actualTotal = 0;
    int actualEmpty = 0;

    // 遍历 parkingspace 表，统计总车位数和空车位数
    while (query.next()) {
        actualTotal++;
        if (query.value(0).toString() == "空闲") {
            actualEmpty++;
        }
    }

    //qDebug() << "核对后的数据: 实际总车位=" << actualTotal << ", 实际空车位=" << actualEmpty;

    // 更新 parkinglot 表中的总车位和空车位信息
    QString updateQuery = QString("UPDATE parkinglot SET posnum = %1, emptynum = %2 WHERE parkingname = '%3'")
                              .arg(actualTotal)
                              .arg(actualEmpty)
                              .arg(parkingname);
    if (!query.exec(updateQuery)) {
        qDebug() << "更新 parkinglot 表失败:" << query.lastError().text();
        return;
    }

    qDebug() << "停车场数据更新成功:" << parkingname;

    // 重新赋值以确保显示最新数据
    posnum = actualTotal;
    emptynum = actualEmpty;

    // 更新界面显示
    parker.setline(posnum, emptynum, income);

}
//管理员初始界面数据加载
void MainWindow::sqlparkingspace() {
    // 清空 parkingname
    parkingname.clear();

    // 获取停车场名称
    QSqlQuery query;
    QString inquire = QString("SELECT parkingname FROM parkinglot WHERE parkingid = '%1'").arg(parkerid);
    if (!query.exec(inquire)) {
        qDebug() << "获取停车场名称失败：" << query.lastError().text();
        return;
    }
    if (query.next()) {
        parkingname = query.value(0).toString();
    }
    if (parkingname.isEmpty()) {
        qDebug() << "停车场名称为空，检查 parkerid 是否有效：" << parkerid;
        return;
    }
    qDebug() << "准备清空存储的停车信息";
    const int maxRecords = sizeof(parkingstr) / sizeof(parkingstr[0]); // 数组最大容量
    // 清空存储的停车信息
    //对 QString 或 QDateTime 使用 memset暴力都为0，会破坏对象状态，导致后续操作出错。改为逐元素清空：
    for (int j = 0; j < maxRecords; ++j) {
        parkingstr[j].clear();
        parkingtim[j][0] = QDateTime();
        parkingtim[j][1] = QDateTime();
        recordSource[j].clear();
    }
    len_3 = 0;

    // 查询注册用户记录
    QString inquire_book = QString("SELECT id, carpos, statime, endtime, 'book' AS source FROM book WHERE parkingname = '%1' AND finish = 'no'")
                               .arg(parkingname);

    // 查询非注册用户记录
    QString inquire_nuserbook = QString("SELECT nusercarid, carpos, statime, endtime, 'nuserbook' AS source FROM nuserbook WHERE parkingname = '%1' AND finish = 'no'")
                                    .arg(parkingname);

    // 统一查询两个表的数据
    QString combinedQuery = QString("SELECT * FROM (%1 UNION ALL %2) AS combined ORDER BY statime")
                                .arg(inquire_book)
                                .arg(inquire_nuserbook);

    if (!query.exec(combinedQuery)) {
        qDebug() << "联合查询失败：" << query.lastError().text();
        return;
    }


    int i = 0;
    while (query.next()) {
        if (i >= maxRecords) {
            qDebug() << "查询结果超出数组容量，忽略多余记录";
            break; // 避免越界写入
        }

        qDebug() << "次数：" << i;

        // 获取查询结果
        QString userOrCarId = query.value(0).toString();
        qDebug() << "查询1：" << userOrCarId;

        int carPos = query.value(1).toInt();
        qDebug() << "查询2：车位号：" << carPos;

        QDateTime startTime = query.value(2).toDateTime();
        qDebug() << "查询3：开始时间：" << startTime.toString("yyyy-MM-dd hh:mm:ss");

        QDateTime endTime = query.value(3).toDateTime(); // 可能为空
        qDebug() << "查询4：结束时间：" << (endTime.isNull() ? "NULL" : endTime.toString("yyyy-MM-dd hh:mm:ss"));

        QString source = query.value(4).toString();
        qDebug() << "查询5：来源：" << source;

        // 写入到数组（保持 QDateTime 类型）
        parkingstr[i] = userOrCarId;       // 用户名或车牌号
        parkingnum[i] = carPos;            // 车位号
        parkingtim[i][0] = startTime;      // 开始时间
        parkingtim[i][1] = endTime;        // 结束时间（可能为 QDateTime()，即空）
        recordSource[i] = source;          // 来源标记 ("book" 或 "nuserbook")

        qDebug() << "写入数组：用户名/车牌：" << parkingstr[i]
                 << ", 车位号：" << parkingnum[i]
                 << ", 开始时间：" << parkingtim[i][0]
                 << ", 结束时间：" << (parkingtim[i][1].isNull() ? "NULL" : parkingtim[i][1].toString("yyyy-MM-dd hh:mm:ss"))
                 << ", 来源：" << recordSource[i];

        i++;
        qDebug() << "i是：" << i;
    }

    len_3 = i;


    // 调试输出
    qDebug() << "停车记录加载成功，共记录：" << len_3;

    // 调用 print 函数，传递停车记录和数据来源
    parker.print(parkingstr, parkingnum, parkingtim, recordSource, len_3);
}

//管理员设置界面车位信息扫库加载
void MainWindow::sqlparkingsettings_load(){

    qDebug() << "停车场名称:" << parkingname;
    QSqlQuery query;
    QString inquire_2 = QString("select * from parkingspace where parkingname = '%1' ").arg(parkingname);
    query.exec(inquire_2);
    int i = 0;

    while (query.next()) {
        parkingnum[i] = query.value(0).toInt();  // 车位号
        //qDebug() << "车位号:" << parkingnum[i];
        carpostype[i] = query.value(2).toString();// 车位类型
        //qDebug() << "车位类型:" << carpostype[i];
        parkingfinish[i]=query.value(3).toString(); //车位空闲是否
        //qDebug() << "车位空闲是否:" << parkingfinish[i];
        i++;
        //qDebug() << "循环次:" << i;
    }
    len_4 = i;
    parkset.setprint(parkingname,parkingnum,carpostype,parkingfinish,len_4);
    parkset.show();
}
//删除车位
void MainWindow::sqldelparksetspace(int carpos){
    QSqlQuery query;

    // 检查是否满足删除条件
    QString checkQuery = QString("SELECT situation FROM parkingspace WHERE parkingname = '%1' AND carpos = %2")
                             .arg(parkingname)
                             .arg(carpos);

    if (query.exec(checkQuery)) {
        if (query.next()) {
            QString situation = query.value(0).toString(); // 获取 situation 列的值

            if (situation == "占用") {
                // 弹出窗口提示先解除占用
                QMessageBox::warning(this, "操作失败", "当前车位被占用，请先解除占用状态再删除！");
                return; // 直接返回，不继续删除操作
            }
        } else {
            // 如果没有查询到记录，提示错误
            QMessageBox::warning(this, "操作失败", "未找到对应的车位记录！");
            return;
        }
    } else {
        qDebug() << "查询车位信息失败：" << query.lastError().text();
        return;
    }

    // 构造删除 SQL 语句
    QString deleteQuery = QString("DELETE FROM parkingspace WHERE parkingname = '%1' AND carpos = %2")
                              .arg(parkingname)
                              .arg(carpos);

    // 执行 SQL 语句并检查结果
    if (query.exec(deleteQuery)) {
        QMessageBox::information(nullptr, "成功", "车位删除成功！", QMessageBox::Yes);
        qDebug() << "停车场" << parkingname << "中车位号为" << carpos << "的记录已成功删除。";
    } else {
        qDebug() << "删除停车场" << parkingname << "中车位号为" << carpos << "的记录失败：" << query.lastError().text();
    }

    qDebug() << "准备执行更新加载 parkset 的数据" ;
    sqlparkingsettings_load(); // 更新加载 parkset 的数据
}

//管理员添加车位
void MainWindow::sqladdparksetspace(int carpos,QString type){
    QSqlQuery query;

    // 1. 检查车位号是否已存在
    QString checkQuery = QString("SELECT COUNT(*) FROM parkingspace WHERE carpos = %1 AND parkingname = '%2'")
                             .arg(carpos)
                             .arg(parkingname);

    if (query.exec(checkQuery)) {
        query.next();
        int count = query.value(0).toInt();
        if (count > 0) {
            QMessageBox::warning(nullptr, "错误", "车位号已存在，无法重复添加！");
            return;  // 如果车位号已存在，退出函数
        }
    } else {
        QMessageBox::warning(nullptr, "错误", "查询失败：" + query.lastError().text());
        return;
    }

    // 2. 插入新记录
    QString insertQuery = QString(
                              "INSERT INTO parkingspace (carpos, parkingname, carpostype, situation, statime, endtime) "
                              "VALUES (%1, '%2','%3','空闲', NULL, NULL)")
                              .arg(carpos)
                              .arg(parkingname)
                              .arg(type);

    if (query.exec(insertQuery)) {
        QMessageBox::information(nullptr, "成功", "车位添加成功！", QMessageBox::Yes);
    } else {
        QMessageBox::warning(nullptr, "错误", "车位添加失败：" + query.lastError().text());
    }

    qDebug() << "准备执行更新加载 parkset 的数据" ;
    sqlparkingsettings_load(); // 更新加载 parkset 的数据
}

void MainWindow::sqlCheckCarId(const QString &carId) {
    QSqlQuery query;
    // 查询车牌号是否在 carinfo 表中
    QString queryStr = QString("SELECT id FROM carinfo WHERE carid = '%1'").arg(carId);
    query.exec(queryStr);

    if (query.next()) {
        //1. 注册用户
        QString userId = query.value(0).toString();
        QMessageBox::information(nullptr, "用户确认", QString("该车牌号: %1 已注册，用户 ID: %2").arg(carId).arg(userId));
        //1.1已注册且预约——出库
        if (sqlUserHasPendingOrder(userId,"book")){
            //根据接收到的userId,查表是否会员获取money和duraation,填入到支付函数中
            // 获取当前时间
            QDateTime currentTime = QDateTime::currentDateTime();
            // 用封装的费用计算函数，获取费用和时长
            auto [money, totalDuration, overTimeDuration, userType] = sqlCalculateParkingFee(currentTime, userId);
            QMessageBox::information(nullptr, "%1", QString("该车牌号: %2 有订单，准备驶出").arg(userType).arg(carId));

            // 调用支付处理函数
            qDebug() << "计费的时间:" << totalDuration;
            qDebug() << "实际收取费用:" << money;
            sqlProcessPayment("book", userId, money, totalDuration);
            return;
        //1.2已注册——未预约要入库
        }else {
            QMessageBox::information(nullptr, "用户确认", QString("该车牌号: %1 无预约，准备入库").arg(carId));
            auto carInfo = parker.getNonRegisteredCarInfo(carId);
            auto [carpos, cartype] = *carInfo; // 解包 optional 中的 pair
            //检查车辆和车型是否匹配
            if(!sqlIsParkingSpaceAvailableForNonRegistered(parkingname, carpos, cartype)) return;

            // 定义变量并赋值为当前时间
            QDateTime statime = QDateTime::currentDateTime();
            QDateTime endtime; // 默认构造，表示空时间
            //插入新订单
            if(!sqlInsertNewOrder(userId, parkingname, carpos, statime, endtime, "no", "book" )) return;
            //停车场空间插入信息占用
            if(!sqlUpdateParkingSpace(parkingname, carpos, "占用", statime, endtime)) return;

            //更新停车场空位数量
            if(!sqlUpdateParkingLotSpaces(parkingname, -1)) return;

            //结束提示
            QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("车辆成功入库"), QMessageBox::Yes);
        }
    } else {
        // 2.1未注册——出库
        if (sqlUserHasPendingOrder(carId,"nuserbook")){
            QMessageBox::information(nullptr, "未注册用户确认", QString("该车牌号: %1 有订单，准备驶出").arg(carId));      
            // 获取当前时间
            QDateTime currentTime = QDateTime::currentDateTime();

            // 查询 statime
            QString statimeQuery = QString("SELECT statime FROM nuserbook WHERE nusercarid = '%1' AND finish = 'no'").arg(carId);
            QDateTime statime;

            if (query.exec(statimeQuery) && query.next()) {
                statime = query.value(0).toDateTime();
            } else {
                QMessageBox::warning(nullptr, "错误", "未能查询到开始时间，无法计算费用。");
                return;
            }

            // duration 为实际停车时长（单位：秒）
            int totalSeconds = statime.secsTo(currentTime);

            // 停车时长（单位：小时，未满一小时按一小时算）
            int roundedHours = ceil(totalSeconds / 3600.0);

            // 费用按每小时 3 元计算
            int money = roundedHours * 3;

            // 调用支付处理函数
            sqlProcessPayment("nuserbook", carId, money, roundedHours);


        }
        // 2.2未注册——入库
        else{
            QMessageBox::information(nullptr, "用户未注册", QString("该车牌号: %1 无预约，准备入库").arg(carId));

            auto carInfo = parker.getNonRegisteredCarInfo(carId);
            auto [carpos, cartype] = *carInfo; // 解包 optional 中的 pair

            //检查车辆和车型是否匹配
            if(!sqlIsParkingSpaceAvailableForNonRegistered(parkingname, carpos, cartype)) return;

            // 定义变量并赋值为当前时间
            QDateTime statime = QDateTime::currentDateTime();
            QDateTime endtime; // 默认构造，表示空时间

            //插入新订单
            if(!sqlInsertNewOrder(carId, parkingname, carpos, statime, endtime, "no", "nuserbook" )) return;

            //停车场空间插入信息占用
            if(!sqlUpdateParkingSpace(parkingname, carpos, "占用", statime, endtime)) return;


            //更新停车场空位数量
            if(!sqlUpdateParkingLotSpaces(parkingname, -1)) return;

            //结束提示
            QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("车辆成功入库"), QMessageBox::Yes);
        }


    }
    //刷新管理员查看界面
    sqlparkingspace();
    sqlparkinglot();
    parker.show();
}



//下面是为了减少重复语句用SQL语句封装的表操作函数
//是否完成订单
bool MainWindow::sqlUserHasPendingOrder(const QString &firstField, const QString &tableName) {
    QSqlQuery query;
    QString inquire = QString("SELECT COUNT(*) FROM %1 WHERE %2 = '%3' AND finish = 'no'")
                          .arg(tableName)
                          .arg((tableName == "book") ? "id" : "nusercarid") // 动态设置字段名
                          .arg(firstField);

    if (query.exec(inquire)) {
        if (query.next()) {
            int count = query.value(0).toInt();
            return count > 0; // 如果查询结果大于 0，则存在未完成订单
        }
    } else {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("查询未完成订单失败"), QMessageBox::Yes);
    }

    return false; // 没有未完成订单
}


//检查车位是否空闲
bool MainWindow::sqlIsParkingSpaceAvailable(const QString &parkingname, int carpos, QString &carpostype) {
    QSqlQuery query;
    QString inquire = QString("SELECT situation, carpostype FROM parkingspace WHERE carpos = '%1' AND parkingname = '%2'")
                          .arg(carpos).arg(parkingname);

    if (query.exec(inquire) && query.next()) {
        QString situation = query.value(0).toString();
        carpostype = query.value(1).toString();
        if (situation == "空闲") {
            return true; // 车位空闲
        } else {
            QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("停车场的此车位已被占用"), QMessageBox::Yes);
        }
    } else {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("输入的停车场或车位号不存在"), QMessageBox::Yes);
    }
    return false; // 车位不可用或不存在
}
//给非注册检查车位是否空闲+车型匹配
bool MainWindow::sqlIsParkingSpaceAvailableForNonRegistered(const QString &parkingname, int carpos, const QString &userCartype) {
    QSqlQuery query;
    QString inquire = QString("SELECT situation, carpostype FROM parkingspace WHERE carpos = '%1' AND parkingname = '%2'")
                          .arg(carpos).arg(parkingname);

    if (query.exec(inquire)) {
        if (query.next()) {
            QString situation = query.value(0).toString(); // 获取车位状态
            QString carpostype = query.value(1).toString(); // 获取车位类型

            // 检查车位是否空闲
            if (situation != "空闲") {
                QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("停车场的此车位已被占用"), QMessageBox::Yes);
                return false; // 车位被占用
            }

            // 检查车位类型是否与用户输入的车型匹配
            if (carpostype != userCartype) {
                QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("车型不匹配"), QMessageBox::Yes);
                return false; // 车型不匹配
            }

            qDebug() << "车位可用且车型匹配：" << parkingname << ", 车位号：" << carpos;
            return true; // 车位空闲且车型匹配
        } else {
            QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("车位不存在"), QMessageBox::Yes);
            return false; // 车位不存在
        }
    } else {
        qDebug() << "数据库查询失败：" << query.lastError().text();
        return false; // 查询失败
    }
}


//检查车位类型与用户车型是否匹配
bool MainWindow::sqlIsCarTypeCompatible(const QString &userid, const QString &carpostype) {
    QSqlQuery query;
    QString inquire = QString("SELECT cartype FROM carinfo WHERE id = '%1'").arg(userid);
    query.exec(inquire);

    if (query.next()) {
        QString userCarType = query.value(0).toString();
        if (userCarType == carpostype) {
            return true; // 匹配
        } else {
            QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("该车位的适停车型与您的车型不符合"), QMessageBox::Yes);
        }
    } else {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("用户车型信息获取失败"), QMessageBox::Yes);
    }
    return false; // 不匹配或查询失败
}
//更新车位状态
bool MainWindow::sqlUpdateParkingSpace(const QString &parkingname, int carpos, const QString &situation, const QDateTime &statime, const QDateTime &endtime) {
    QSqlQuery query;
    QString updateQuery;

    // 根据 statime 和 endtime 是否为空动态生成 SQL 语句
    QString statimeStr = (statime.isNull() || !statime.isValid()) ? "NULL" : QString("'%1'").arg(statime.toString("yyyy-MM-dd hh:mm:ss"));
    QString endtimeStr = (endtime.isNull() || !endtime.isValid()) ? "NULL" : QString("'%1'").arg(endtime.toString("yyyy-MM-dd hh:mm:ss"));

    // 生成更新语句
    updateQuery = QString("UPDATE parkingspace SET situation = '%1', statime = %2, endtime = %3 WHERE carpos = '%4' AND parkingname = '%5'")
                      .arg(situation)
                      .arg(statimeStr)
                      .arg(endtimeStr)
                      .arg(carpos)
                      .arg(parkingname);

    // 执行更新操作
    if (!query.exec(updateQuery)) {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("更新车位状态失败：%1").arg(query.lastError().text()), QMessageBox::Yes);
        return false;
    }
    return true;
}

//获取当前最大订单号
int MainWindow::sqlGetMaxOrderNumber(const QString &tableName) {
    QSqlQuery query;
    int curOrder = 0;

    QString inquire = QString ("SELECT MAX(ordernum) FROM %1").arg(tableName);
    query.exec(inquire);

    if (query.next()) {
        curOrder = query.value(0).toInt();
    }
    return curOrder + 1; // 返回新的订单号
}
//插入新订单
bool MainWindow::sqlInsertNewOrder(const QString &firstField, const QString &parkingname, int carpos, const QDateTime &statime, const QDateTime &endtime, const QString &finish, const QString &tableName) {
    QSqlQuery query;
    int newOrderNum = sqlGetMaxOrderNumber(tableName);

    // 动态生成 endtime 的 SQL 语句
    QString endtimeStr = (endtime.isNull() || !endtime.isValid()) ? "NULL" : QString("'%1'").arg(endtime.toString("yyyy-MM-dd hh:mm:ss"));
    qDebug() << "车场表的结束时间" << endtimeStr;
    // 动态生成插入语句
    QString insertQuery = QString(
                              "INSERT INTO %1 (%2, parkingname, carpos, statime, endtime, finish, ordernum) "
                              "VALUES ('%3', '%4', '%5', '%6', %7, '%8', '%9')")
                              .arg(tableName)
                              .arg((tableName == "book") ? "id" : "nusercarid") // 根据表名动态设置字段名
                              .arg(firstField)
                              .arg(parkingname)
                              .arg(carpos)
                              .arg(statime.toString("yyyy-MM-dd hh:mm:ss"))
                              .arg(endtimeStr) // 动态生成的 endtime 部分
                              .arg(finish)
                              .arg(newOrderNum);

    // 执行插入操作
    if (!query.exec(insertQuery)) {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("插入新订单失败：%1").arg(query.lastError().text()), QMessageBox::Yes);
        return false;
    }
    return true;
}


//更新停车场空位数量
bool MainWindow::sqlUpdateParkingLotSpaces(const QString &parkingname, int spaceChange) {
    QSqlQuery query;

    // 更新空闲车位数量
    QString updateQuery = QString(
                              "UPDATE parkinglot SET emptynum = emptynum + %1 WHERE parkingname = '%2'")
                              .arg(spaceChange)
                              .arg(parkingname);

    if (query.exec(updateQuery)) {
        qDebug() << "停车场" << parkingname << "的空闲车位数量已成功更新，变化值:" << spaceChange;
        return true;
    } else {
        qDebug() << "更新停车场空闲车位数量失败:" << query.lastError().text();
        QMessageBox::warning(nullptr, "数据库错误", "更新停车场空闲车位数量失败，请检查数据库！");
        return false;
    }
}


void MainWindow::quit() {
    user.close(); // 关闭用户信息
    this->show(); // 显示主窗口
}

MainWindow::~MainWindow() {
    delete ui; // 删除UI对象
}
