#include "parkingsettings.h"
#include "ui_parkingsettings.h"
#include  <iostream>

parkingsettings::parkingsettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parkingsettings)
{
    ui->setupUi(this);

     // 初始化网格布局，用于展示停车信息，令网格大小适中
    pLayout = new QGridLayout(); // 在构造函数中初始化 pLayout
    pLayout->setSpacing(20); // 设置控件间距
    pLayout->setAlignment(Qt::AlignTop);// 设置布局靠顶部对齐
    // 初始化车型下拉框数据
    // 设置背景图片，并调整为与窗口大小匹配
    QPixmap pixmap = QPixmap(":/ground_4.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
    ui->comboBox->addItems({"小型车", "中型车", "大型车"});
}

parkingsettings::~parkingsettings()
{
    delete ui;
}

// 打印函数：展示停车信息到界面的 scrollArea 中
void parkingsettings::setprint(QString parkingname,int *carpos, QString *carpostype, QString *situation, int len) {

    //清空布局：移除所有已有的控件
    QLayoutItem *child;
    while ((child = pLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            child->widget()->setParent(nullptr); // 将控件从布局中移除
        }
        delete child; // 删除布局项
    }

    ui->label->setText("停车场：" + parkingname);

    // 遍历每一行数据，动态生成控件并添加到布局中
    for (int i = 0; i < len; ++i) {
        QLineEdit *lineEdit = new QLineEdit(QString::number(carpos[i])); // 车位编号
        QLineEdit *lineEdit_2 = new QLineEdit(carpostype[i]);           // 车位类型
        QLineEdit *lineEdit_3 = new QLineEdit(situation[i]);            // 车位状态

        lineEdit->setReadOnly(true);
        lineEdit_2->setReadOnly(true);
        lineEdit_3->setReadOnly(true);

        lineEdit->setAlignment(Qt::AlignHCenter);
        lineEdit_2->setAlignment(Qt::AlignHCenter);
        lineEdit_3->setAlignment(Qt::AlignHCenter);

        // lineEdit->setFixedHeight(30);  // 设置控件固定高度
        // lineEdit_2->setFixedHeight(30);
        // lineEdit_3->setFixedHeight(30);

        // lineEdit->setContentsMargins(0, 0, 0, 0);  // 去掉控件外边距
        // lineEdit_2->setContentsMargins(0, 0, 0, 0);
        // lineEdit_3->setContentsMargins(0, 0, 0, 0);

        pLayout->addWidget(lineEdit, i, 0, 1, 1);   // 第一列：车位编号
        pLayout->addWidget(lineEdit_2, i, 1, 1, 1); // 第二列：车位类型
        pLayout->addWidget(lineEdit_3, i, 2, 1, 1); // 第三列：车位状态

        //以下新增--------------------------------------------------------------------------动态创建“删除车位”按钮并添加到布局中
        QPushButton *delButton = new QPushButton("删除车位");
        pLayout->addWidget(delButton, i, 4, 1, 1);  // 将按钮添加在停车信息右侧

        // 点击按钮时读取起始和结束时间并发出 finishOrder 信号
        connect(delButton, &QPushButton::clicked, this, [=]() {
            emit delsignal(carpos[i]);   // 发送信号联动删除车位
        });
    }

    //确保在清空布局和添加控件时正确地绑定到 scrollArea
    ui->scrollArea->widget()->setLayout(pLayout);
}

void parkingsettings::on_pushButton_clicked()
{
    // 获取用户输入
    QString carPosStr = ui->lineEdit->text();
    QString carType = ui->comboBox->currentText();

    // 验证用户输入是否合法
    if (carPosStr.isEmpty()) {
        QMessageBox::warning(this, "警告", "车位号不能为空！");
        return;
    }

    bool isNumber;
    int carPos = carPosStr.toInt(&isNumber);
    if (!isNumber || carPos <= 0) {
        QMessageBox::warning(this, "警告", "车位号必须是正整数！");
        return;
    }

    // 调用数据库添加方法
    emit addsignal(carPos, carType);
}

void parkingsettings::closeEvent(QCloseEvent *event)
{
    emit returnparkingwindow(); // 触发信号
    QWidget::closeEvent(event); // 确保父类逻辑正常执行
}

void parkingsettings::on_pushButton_2_clicked()
{
    this->close();
    // 显示 parkset 界面
    emit returnparkingwindow(); // 发出信号
}

