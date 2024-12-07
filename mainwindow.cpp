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

     // 定时器，用于实时更新时间显示
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
    connect(&user, &userwindow::send_main_yearmember, this, &MainWindow::sqlyearmember);
    connect(&user, &userwindow::send_main_monthmember, this, &MainWindow::sqlmonthmember);
    connect(&user, &userwindow::send_main_reservation, this, &MainWindow::sqlreservation);
    connect(&user, &userwindow::send_main_payment, this, &MainWindow::sqlpayment);
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
}


//------在 MainWindow 中定义 processPaymentForUser 槽函数，临时更新 userid，调用 sqlpayment 完成支付，然后恢复 userid。
void MainWindow::processPaymentForUser(const QString &userId, int duration, int money) {
    //qInfo() << userId;
    QString originalUserId = userid;  // 备份当前用户 ID
    userid = userId;                  // 临时设置为指定用户 ID

    sqlpayment(duration, money);      // 调用支付函数
    userid = originalUserId;          // 恢复原来的用户 ID

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
// 更新余额
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

void MainWindow::sqlyearmember(){
    QSqlQuery query;
    // 查询用户余额
    QString inquire = QString("select balance from userinfo where id = '%1'").arg(userid);
    query.exec(inquire);
    int balance = 0;
    while(query.next()){
        balance = query.value(0).toInt();
    }
    // 判断余额是否充足
    if(balance < 2500){
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("余额不足，请充值"), QMessageBox::Yes);
    }
    else{
        balance -= 2500;
        // 更新余额
        QString str = QString("update userinfo set balance = '%1' where id = '%2'").arg(balance).arg(userid);
        // 将用户类型设为年费会员
        QString str_2 = QString("update userinfo set type = '年费会员' where id = '%1'").arg(userid);
        query.exec(str);
        query.exec(str_2);
        QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("会员办理成功"), QMessageBox::Yes);
        this->sqlinfo();
    }
}

void MainWindow::sqlmonthmember(){
    QSqlQuery query;
    // 查询用户余额
    QString inquire = QString("select balance from userinfo where id = '%1'").arg(userid);
    query.exec(inquire);
    int balance = 0;
    while(query.next()){
        balance = query.value(0).toInt();
    }
    // 查询用户类型
    QString inquire_2 = QString("select type from userinfo where id = '%1'").arg(userid);
    query.exec(inquire_2);
    QString type;
    while(query.next()){
        type = query.value(0).toString();
    }
    // 判断是否为年费会员
    if(type == "年费会员"){
        QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("您已是年费会员"), QMessageBox::Yes);
    }
    else{
        // 判断余额是否足够
        if(balance < 260){
            QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("余额不足，请充值"), QMessageBox::Yes);
        }
        else{
            balance -= 260;
            // 更新余额
            QString str = QString("update userinfo set balance = '%1' where id = '%2'").arg(balance).arg(userid);
            // 更新用户类型为月费会员
            QString str_2 = QString("update userinfo set type = '月费会员' where id = '%1'").arg(userid);
            query.exec(str);
            query.exec(str_2);
            QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("会员办理成功"), QMessageBox::Yes);
            this->sqlinfo();
        }
    }
}


void MainWindow::sqlreservation(QString parkingname, int carpos, QDateTime statime, QDateTime endtime){
    int flag = 0;
    QSqlQuery query;
    // 查询当前用户是否有进行中的订单
    QString inquire = QString("select finish from book where id = '%1'").arg(userid);
    query.exec(inquire);
    QString fin;
    while(query.next()){
        fin = query.value(0).toString();
        if(fin == "no"){
            flag = 1;
            QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("您有一个订单在进行中"), QMessageBox::Yes);
        }
    }
    if(!flag){
        // 查询车位是否空闲
        QString inquire_2 = QString("select situation from parkingspace where carpos = '%1' and parkingname = '%2'").arg(carpos).arg(parkingname);
        if(query.exec(inquire_2)){
            QString rec;
            while(query.next()){
                rec = query.value(0).toString();
            }
            if(rec == "空闲"){
                // 检查车位类型和用户车型是否匹配
                QString inquire_3 = QString("select carpostype from parkingspace where carpos = '%1' and parkingname = '%2'").arg(carpos).arg(parkingname);
                query.exec(inquire_3);
                QString rec_2;
                while(query.next()){
                    rec_2 = query.value(0).toString();
                }
                QString inquire_4 = QString("select cartype from carinfo where id = '%1'").arg(userid);
                query.exec(inquire_4);
                QString rec_3;
                while(query.next()){
                    rec_3 = query.value(0).toString();
                }
                if(rec_2 == rec_3){
                    // 更新车位状态为占用
                    QString str = QString("update parkingspace set situation = '占用' where carpos = '%1' and parkingname = '%2'").arg(carpos).arg(parkingname);
                    query.exec(str);
                    // 更新预约时间
                    QString statim = statime.toString("yyyy-MM-dd hh:mm:ss");
                    QString endtim = endtime.toString("yyyy-MM-dd hh:mm:ss");
                    QString str_2 = QString("update parkingspace set statime = '%1' where carpos = '%2' and parkingname = '%3'").arg(statim).arg(carpos).arg(parkingname);
                    query.exec(str_2);
                    QString str_5 = QString("update parkingspace set endtime = '%1' where carpos = '%2' and parkingname = '%3'").arg(endtim).arg(carpos).arg(parkingname);
                    query.exec(str_5);
                    // 获取最新订单号并插入新订单记录
                    int curorder = 0;
                    QString inquire_5 = QString("select max(ordernum) from book");
                    query.exec(inquire_5);
                    while(query.next()){
                        curorder = query.value(0).toInt();
                    }
                    curorder += 1;
                    QString str_3 = QString("insert into book(id,parkingname,carpos,statime,endtime,finish,ordernum) values('%1', '%2', '%3', '%4', '%5', 'no', '%6')").arg(userid).arg(parkingname).arg(carpos).arg(statim).arg(endtim).arg(curorder);
                    query.exec(str_3);
                    // 更新停车场空位数量
                    QString str_4 = QString("update parkinglot set emptynum = emptynum - 1 where parkingname = '%1'").arg(parkingname);
                    query.exec(str_4);
                    this->sqlinq();
                    QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("预约成功"), QMessageBox::Yes);
                }
                else{
                    QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("该车位的适停车型与您的车型不符合"), QMessageBox::Yes);
                }
            }
            else{
                QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("停车场的此车位已被占用"), QMessageBox::Yes);
            }
        }
        else{
            QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("输入的停车场或车位号不存在"), QMessageBox::Yes);
        }
    }
}

void MainWindow::updatetimeout() {
    // 获取当前时间
    QDateTime curtime = QDateTime::currentDateTime();
    QSqlQuery query;

    // 查询当前用户的完成状态
    QString inquire = QString("select finish from book where id = '%1'").arg(userid);
    query.exec(inquire);
    QString fin;

    // 遍历查询结果，获取完成状态
    while (query.next()) {
        fin = query.value(0).toString();
    }

    // 如果未完成，则进行时间计算
    if (fin == "no") {
        // 查询结束时间
        QString inquire_2 = QString("select endtime from book where id = '%1'").arg(userid);
        query.exec(inquire_2);
        QDateTime endtime;
        while (query.next()) {
            endtime = query.value(0).toDateTime();
        }

        // 计算结束时间与当前时间的差值
        int elapsed = endtime.msecsTo(curtime);

        // 查询开始时间
        QString inquire_4 = QString("select statime from book where id = '%1'").arg(userid);
        query.exec(inquire_4);
        QDateTime statime;
        while (query.next()) {
            statime = query.value(0).toDateTime();
        }

        // 计算开始时间与当前时间的差值
        int elapsed_2 = statime.msecsTo(curtime);

        // 将毫秒转换为小时
        double hours = elapsed * 1.0 / 1000 / 3600;
        double hours_2 = elapsed_2 * 1.0 / 1000 / 3600;

        // 向上取整
        int duration = ceil(hours);
        int duration_2 = ceil(hours_2);
        int money = 0;

        // 查询用户类型
        QString inquire_3 = QString("select type from userinfo where id = '%1'").arg(userid);
        query.exec(inquire_3);
        QString rec;
        while (query.next()) {
            rec = query.value(0).toString();
        }

        // 根据用户类型计算费用
        if (rec == "普通用户") {
            money = duration_2 * 3; // 普通用户按小时收费
        }

        // 更新用户支付信息
        if (elapsed > 0) {
            user.setpayment(duration, money);
        } else {
            user.setpayment(0, money);
        }
    }
}
//
void MainWindow::sqlpayment(int duration, int money) {
    QSqlQuery query;
    // 查询用户余额
    QString inquire = QString("select balance from userinfo where id = '%1'").arg(userid);
    query.exec(inquire);
    int balance = 0;
    while (query.next()) {
        balance = query.value(0).toInt();
    }

    // 检查余额是否足够
    if (balance < money) {
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("余额不足，请先充值"), QMessageBox::Yes);
    } else {
        // 更新订单状态为完成
        QString str = QString("update book set finish = 'yes' where id = '%1'").arg(userid);
        query.exec(str);

        // 查询停车场名称
        QString inquire_2 = QString("select parkingname from book where id = '%1'").arg(userid);
        query.exec(inquire_2);
        QString parkingname;
        while (query.next()) {
            parkingname = query.value(0).toString();
        }

        // 查询车位
        QString inquire_3 = QString("select carpos from book where id = '%1'").arg(userid);
        query.exec(inquire_3);
        int carpos = 0;
        while (query.next()) {
            carpos = query.value(0).toInt();
        }

        // 查询订单号
        QString inquire_4 = QString("select ordernum from book where id = '%1'").arg(userid);
        query.exec(inquire_4);
        int ordernum = 0;
        while (query.next()) {
            ordernum = query.value(0).toInt();
        }

        // 查询开始和结束时间
        QString inquire_5 = QString("select statime from book where id = '%1'").arg(userid);
        query.exec(inquire_5);
        QDateTime statime;
        while (query.next()) {
            statime = query.value(0).toDateTime();
        }

        QString inquire_6 = QString("select endtime from book where id = '%1'").arg(userid);
        query.exec(inquire_6);
        QDateTime endtime;
        while (query.next()) {
            endtime = query.value(0).toDateTime();
        }

        // 更新停车场信息
        //成功支付会令对应停车场的空闲位置+1
        QString str_2 = QString("update parkinglot set emptynum = emptynum + 1 where parkingname = '%1'").arg(parkingname);
        query.exec(str_2);
        QString str_3 = QString("update parkinglot set income = income + '%1' where parkingname = '%2'").arg(money).arg(parkingname);
        query.exec(str_3);
        QString str_4 = QString("update parkingspace set situation = '空闲' where carpos = '%1' and parkingname = '%2'").arg(carpos).arg(parkingname);
        query.exec(str_4);
        QString str_5 = QString("update userinfo set balance = balance - '%1' where id = '%2'").arg(money).arg(userid);
        query.exec(str_5);

        // 插入消费记录
        QString statim = statime.toString("yyyy-MM-dd hh:mm:ss");
        QString endtim = endtime.toString("yyyy-MM-dd hh:mm:ss");
        QString str_6 = QString("insert into consumption(id,ordernum,carpos,parkingname,statime,endtime,timeout,fare) values('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8')")
                            .arg(userid).arg(ordernum).arg(carpos).arg(parkingname).arg(statim).arg(endtim).arg(duration).arg(money);
        query.exec(str_6);

        // 更新界面信息
        this->sqlinq();
        this->sqlinfo();
        QMessageBox::information(nullptr, QStringLiteral("提示"), QStringLiteral("订单完成"), QMessageBox::Yes);
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

void MainWindow::sqlparkinglot() {
    QSqlQuery query;
    // // 查询停车场信息
    // QString inquire = QString("select * from parkinglot where parkingid = '%1'").arg(parkerid);
    // query.exec(inquire);
    // int posnum = 0, emptynum = 0, income = 0;
    // while (query.next()) {
    //     posnum = query.value(1).toInt();   // 总车位
    //     emptynum = query.value(2).toInt(); // 空车位
    //     income = query.value(3).toInt();   // 收入
    // }
    // parker.setline(posnum, emptynum, income); // 更新停车场信息
    // 查询 parkingname 对应的停车场统计信息
    // 查询 parkinglot 表，获取当前停车场信息
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

    qDebug() << "停车场原始信息:" << parkingname << "总车位:" << posnum << "空车位:" << emptynum << "收入:" << income;

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

    qDebug() << "核对后的数据: 实际总车位=" << actualTotal << ", 实际空车位=" << actualEmpty;

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
    //qDebug() << "After clear: " << parkingname;

    QSqlQuery query;
    QString inquire = QString("select parkingname from parkinglot where parkingid = '%1'").arg(parkerid);
    query.exec(inquire);
    while (query.next()) {
        parkingname = query.value(0).toString();
    }

    // 查询未完成的停车记录
    QString inquire_2 = QString("select * from book where parkingname = '%1' and finish = 'no'").arg(parkingname);
    query.exec(inquire_2);
    int i = 0;

    while (query.next()) {

        parkingstr[i] = query.value(0).toString(); // 用户名
        parkingnum[i] = query.value(2).toInt();    // 车位号
        parkingtim[i][0] = query.value(3).toDateTime(); // 开始时间
        parkingtim[i][1] = query.value(4).toDateTime(); // 结束时间
        i++;
    }
    len_3 = i;
    // 调用 print 函数，并传递停车记录、车位编号、用户ID、停车时间等信息
    parker.print(parkingstr, parkingnum,  parkingtim, len_3);
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
        qDebug() << "车位号:" << parkingnum[i];
        carpostype[i] = query.value(2).toString();// 车位类型
        qDebug() << "车位类型:" << carpostype[i];
        parkingfinish[i]=query.value(3).toString(); //车位空闲是否
        qDebug() << "车位空闲是否:" << parkingfinish[i];
        i++;
        qDebug() << "循环次:" << i;
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

//添加车位
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


void MainWindow::quit() {
    user.close(); // 关闭用户信息
    this->show(); // 显示主窗口
}

MainWindow::~MainWindow() {
    delete ui; // 删除UI对象
}
