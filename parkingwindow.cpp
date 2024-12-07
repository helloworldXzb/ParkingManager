#include "parkingwindow.h"
#include "ui_parkingwindow.h"
#include  <iostream>
// 构造函数：初始化管理员界面
parkingwindow::parkingwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::parkingwindow)
{
    ui->setupUi(this);

    // 设置背景图片，并调整为与窗口大小匹配
    QPixmap pixmap = QPixmap(":/ground_4.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    // 初始化网格布局，用于展示停车信息
    pLayout = new QGridLayout();
    pLayout->setSpacing(20);          // 设置控件间距
    pLayout->setAlignment(Qt::AlignTop); // 设置布局靠顶部对齐
}

// 打印函数：展示停车信息到界面的 scrollArea 中
void parkingwindow::print(QString *parkingstr, int *parkingnum, QDateTime (*parkingtim)[2], int len){
    //清空布局
    QLayoutItem *child;
    while ((child = pLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            child->widget()->setParent(nullptr);
        }
        delete child;
    }

    for(int i = 0; i < len; ++i)
    {


        // 创建 QLineEdit 控件用于显示停车信息（如停车编号、停车场、开始时间和结束时间）
        QLineEdit *lineEdit = new QLineEdit();      // 显示停车编号
        QLineEdit *lineEdit_2 = new QLineEdit();    // 显示停车场名称
        QLineEdit *lineEdit_3 = new QLineEdit();    // 显示停车开始时间
        QLineEdit *lineEdit_4 = new QLineEdit();    // 显示停车结束时间

        // 设置这些控件为只读，并将文字居中对齐
        lineEdit->setReadOnly(true);
        lineEdit_2->setReadOnly(true);
        lineEdit_3->setReadOnly(true);
        lineEdit_4->setReadOnly(true);

        lineEdit->setAlignment(Qt::AlignHCenter);
        lineEdit_2->setAlignment(Qt::AlignHCenter);
        lineEdit_3->setAlignment(Qt::AlignHCenter);
        lineEdit_4->setAlignment(Qt::AlignHCenter);

        // 填充每个 QLineEdit 的文本内容
        lineEdit->setText(QString::number(parkingnum[i])); // 停车位编号
        lineEdit_2->setText(parkingstr[i]);               //用户名
        QString statim = parkingtim[i][0].toString("yyyy-MM-dd hh:mm:ss"); // 开始时间
        QString endtim = parkingtim[i][1].toString("yyyy-MM-dd hh:mm:ss"); // 结束时间
        lineEdit_3->setText(statim);
        lineEdit_4->setText(endtim);

        // 将每个 QLineEdit 添加到网格布局的指定位置
        pLayout->addWidget(lineEdit, i, 0, 1, 1);
        pLayout->addWidget(lineEdit_2, i, 1, 1, 1);
        pLayout->addWidget(lineEdit_3, i, 2, 1, 1);
        pLayout->addWidget(lineEdit_4, i, 3, 1, 1);

        //以下新增--------------------------------------------------------------------------动态创建“完结订单”按钮并添加到布局中
        QPushButton *finishButton = new QPushButton("完结订单");
        pLayout->addWidget(finishButton, i, 4, 1, 1);  // 将按钮添加在停车信息右侧

        // 点击按钮时读取起始和结束时间并发出 finishOrder 信号
        connect(finishButton, &QPushButton::clicked, this, [=]() {
            // 从 lineEdit_3 和 lineEdit_4 中读取起始和结束时间
            QDateTime startTime = QDateTime::fromString(lineEdit_3->text(), "yyyy-MM-dd hh:mm:ss");
            QDateTime endTime = QDateTime::fromString(lineEdit_4->text(), "yyyy-MM-dd hh:mm:ss");

            int duration = startTime.secsTo(endTime) / 3600; // 假设时长按小时计算
            int money = duration * 10;                       // 假设每小时费用为 10
            emit finishOrder(parkingstr[i], duration, money);   // 发送信号传递用户ID、时长和费用
        });

    }
    ui->scrollArea->widget()->setLayout(pLayout); // 再次将布局应用到 scrollArea 中
}

// 设置停车场信息（车位总数、空闲数和收入），并显示在界面的指定位置
void parkingwindow::setline(int posnum, int emptynum, int income){
    ui->lineEdit->setText(QString::number(posnum));   // 显示车位总数
    ui->lineEdit_2->setText(QString::number(emptynum)); // 显示空闲车位数
    ui->lineEdit_3->setText(QString::number(income));   // 显示收入
}




// 析构函数：释放 UI 资源
parkingwindow::~parkingwindow()
{
    delete ui;
}

//编辑停车位按钮,该函数会默认绑定按钮，不用手动绑定
void parkingwindow::on_pushButton_clicked()
{    // 假设 ParkingWindow 实例为 this
    parkingsettings *settings = new parkingsettings(this);
    emit showParkSettings(); // 发出信号
    this->hide(); // 隐藏当前窗口
}

