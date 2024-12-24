#include "userwindow.h"
#include "ui_userwindow.h"

userwindow::userwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userwindow)
{
    ui->setupUi(this);



    // 初始化布局
    pLayout = new QGridLayout();
    pLayout->setSpacing(20);
    pLayout->setAlignment(Qt::AlignTop);


    // 定时器，用于更新界面时间显示
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &userwindow::timerUpdate);
    timer->start(1000);

    // 按钮点击信号与槽函数连接
    connect(ui->pushButton, &QPushButton::clicked, this, &userwindow::emitquit);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &userwindow::emit_main_payment);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &userwindow::editinfo);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &userwindow::inqrec);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &userwindow::top_up);
    connect(ui->pushButton_10, &QPushButton::clicked, this, &userwindow::updatepassword);

    connect(ui->pushButton_5, &QPushButton::clicked, this, &userwindow::emit_main_yearmember);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &userwindow::emit_main_monthmember);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &userwindow::reservation);
    connect(ui->pushButton_02, &QPushButton::clicked, this, &userwindow::loadParkingLotNames);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &userwindow::emit_main_consumption);

    connect(&personalinfo, &edit_info::send_user_updateinfo, this, &userwindow::emit_main_updateinfo);
    connect(&updatepass, &update_password::sendpassword, this, &userwindow::emit_main_updatepass);
    connect(&topupinfo, &topup::send_user_balance, this, &userwindow::emit_main_balance);

     // 背景设置
    QPixmap pixmap = QPixmap(":/timg.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

}




userwindow::~userwindow()
{
    delete ui;
}

// 定时更新时间显示
void userwindow::timerUpdate(){
    QDateTime time = QDateTime::currentDateTime();
    ui->dateTimeEdit->setMinimumDateTime(time);
    ui->dateTimeEdit_2->setMinimumDateTime(time);

    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label_11->setText(str);
}

// 停车查询界面-循环查表打印
void userwindow::print(QString data[][3], int arr[], int len)
{
    // 清空现有布局内容
    QLayoutItem *child;
    while ((child = pLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            child->widget()->setParent(nullptr);
        }
        delete child;
    }
    ui->scrollArea->widget()->setLayout(pLayout); // 将布局设置到 scrollArea 中
    for(int i = 0; i < len; ++i) {
        QLineEdit *lineEdit = new QLineEdit();
        QLineEdit *lineEdit_2 = new QLineEdit();
        QLineEdit *lineEdit_3 = new QLineEdit();
        QLineEdit *lineEdit_4 = new QLineEdit();
        lineEdit->setReadOnly(true);
        lineEdit_2->setReadOnly(true);
        lineEdit_3->setReadOnly(true);
        lineEdit_4->setReadOnly(true);

        lineEdit->setAlignment(Qt::AlignHCenter);
        lineEdit_2->setAlignment(Qt::AlignHCenter);
        lineEdit_3->setAlignment(Qt::AlignHCenter);
        lineEdit_4->setAlignment(Qt::AlignHCenter);

        lineEdit->setText(QString::number(arr[i]));
        lineEdit_2->setText(data[i][0]);
        lineEdit_3->setText(data[i][1]);
        lineEdit_4->setText(data[i][2]);

        pLayout->addWidget(lineEdit, i, 0, 1, 1);
        pLayout->addWidget(lineEdit_2, i, 1, 1, 1);
        pLayout->addWidget(lineEdit_3, i, 2, 1, 1);
        pLayout->addWidget(lineEdit_4, i, 3, 1, 1);
    }
    ui->scrollArea->widget()->setLayout(pLayout);
}

// 打印信息到界面
void userwindow::printinfo(QString id, QString name, QString carid, QString tel, QString cartype, QString type, int balance){
    ui->lineEdit_7->setText(id);
    ui->lineEdit_8->setText(name);
    ui->lineEdit_9->setText(carid);
    ui->lineEdit_10->setText(tel);
    ui->lineEdit_11->setText(cartype);
    ui->lineEdit_12->setText(type);
    ui->lineEdit_13->setText(QString::number(balance));
}

// 查询按钮触发函数：从数据库中加载停车场名称
void userwindow::loadParkingLotNames() {
    ui->comboBox->clear();  // 清空现有选项

    // 查询数据库
    QSqlQuery query("SELECT parkingname FROM parkinglot");
    if (query.exec()) {
        while (query.next()) {
            QString parkingName = query.value(0).toString();
            ui->comboBox->addItem(parkingName);  // 将停车场名称添加到下拉框
        }
    } else {
        QMessageBox::warning(this, "Database Error", "无法加载停车场名称: " + query.lastError().text());
    }
}


// 预订停车位
void userwindow::reservation(){

    //QString parkingname = ui->lineEdit->text();
    QString parkingname = ui->comboBox->currentText();
    QString tmp = ui->lineEdit_2->text();
    if(parkingname.isEmpty() || tmp.isEmpty()){
        QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("请输入停车场及车位号"), QMessageBox::Yes);
    }
    else{
        bool ok;
        int carpos = tmp.toInt(&ok, 10);
        QDateTime statime = ui->dateTimeEdit->dateTime();
        QDateTime endtime = ui->dateTimeEdit_2->dateTime();
        if(statime == endtime){
            QMessageBox::warning(nullptr, QStringLiteral("错误"), QStringLiteral("请输入预约的结束时间"), QMessageBox::Yes);
        }
        else{
            //ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            timerUpdate();
            emit(send_main_reservation(parkingname, carpos, statime, endtime));
        }
    }
}



// 打印记录信息
void userwindow::recordprint(QString str[][2], int num[][4], QDateTime time[][2], int len){
    expenses.print(str, num, time, len);
}

void userwindow::emit_main_updateinfo(QString name, QString tel, QString carid, QString cartype){
    emit(send_main_updateinfo(name, tel, carid, cartype));
}

void userwindow::emit_main_updatepass(QString oldpass, QString newpass){
    emit(send_main_updatepass(oldpass, newpass));
}

void userwindow::emit_main_balance(int balance){
    emit(send_main_balance(balance));
}

void userwindow::emit_main_yearmember(){
    emit(send_main_yearmember());
}

void userwindow::emit_main_monthmember(){
    emit(send_main_monthmember());
}

// 设置缴费信息（封装成函数，是为了方便各端修改超时缴费这种关键的信息）
void userwindow::usersetpayment(QString reservationStatus,int duration, int money){
    ui->label_12->setText(reservationStatus);
    ui->lineEdit_14->setText(QString::number(duration));
    ui->lineEdit_15->setText(QString::number(money));
}
//定位取车并缴费功能按钮函数
void userwindow::emit_main_payment() {
    // 触发信号 send_main_payment，发送 duration 和 money 参数
    emit(send_main_payment());
}


void userwindow::emit_main_consumption(){
    emit(send_main_consumption());
}

void userwindow::emitquit(){
    emit(sendquit());
}

void userwindow::emitprint(){
    emit(sendprint());
}

void userwindow::editinfo(){
    personalinfo.show();
}

void userwindow::inqrec(){
    expenses.show();
}

void userwindow::top_up(){
    topupinfo.show();
}

void userwindow::updatepassword(){
    updatepass.show();
}
