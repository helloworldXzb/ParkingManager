#include "parkingwindow.h"
#include "ui_parkingwindow.h"




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
void parkingwindow::print(QString *parkingstr, int *parkingnum, QDateTime (*parkingtim)[2], QString *recordSource, int len) {
    // 清空布局
    QLayoutItem *child;
    while ((child = pLayout->takeAt(0)) != nullptr) {
        if (child->widget()) {
            child->widget()->setParent(nullptr);
        }
        delete child;
    }

    for (int i = 0; i < len; ++i) {
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
        lineEdit_2->setText(parkingstr[i]);               // 用户名或车牌号
        QString statim = parkingtim[i][0].toString("yyyy-MM-dd hh:mm:ss"); // 开始时间
        QString endtim = parkingtim[i][1].isNull() ? "无" : parkingtim[i][1].toString("yyyy-MM-dd hh:mm:ss"); // 结束时间，空值显示为 "无"
        lineEdit_3->setText(statim);
        lineEdit_4->setText(endtim);

        // 将每个 QLineEdit 添加到网格布局的指定位置
        pLayout->addWidget(lineEdit, i, 0, 1, 1);
        pLayout->addWidget(lineEdit_2, i, 1, 1, 1);
        pLayout->addWidget(lineEdit_3, i, 2, 1, 1);
        pLayout->addWidget(lineEdit_4, i, 3, 1, 1);

        // 动态创建“完结订单”按钮并添加到布局中
        QPushButton *finishButton = new QPushButton("完结订单");
        pLayout->addWidget(finishButton, i, 4, 1, 1);  // 将按钮添加在停车信息右侧

        // 点击按钮时读取起始和结束时间并发出 finishOrder 信号
        connect(finishButton, &QPushButton::clicked, this, [=]() {
            emit finishOrder(parkingstr[i], recordSource[i]);   // 发送信号传递用户/车牌ID和记录来源（book nuserbook）
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
{
    //parkingsettings *settings = new parkingsettings(this);
    emit showParkSettings(); // 发出信号
    this->hide(); // 隐藏当前窗口
}



//此处向下是图片识别功能
// Base64 编码函数
QString parkingwindow::encodeToBase64(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", "无法打开图片文件：" + filePath);
        return QString();
    }

    QByteArray fileData = file.readAll();
    file.close();

    QString base64 = fileData.toBase64();
    qDebug() << "图片 Base64 编码：" << base64.left(100) << "..."; // 打印前100个字符调试
    return base64;
}


// 获取 Access Token
void parkingwindow::getAccessToken(std::function<void(const QString &)> callback) {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QUrl tokenUrl("https://aip.baidubce.com/oauth/2.0/token");
    QUrlQuery query;
    query.addQueryItem("grant_type", "client_credentials");
    query.addQueryItem("client_id", CLIENT_ID);
    query.addQueryItem("client_secret", CLIENT_SECRET);
    tokenUrl.setQuery(query);

    QNetworkRequest request(tokenUrl);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply *reply = manager->post(request, QByteArray());
    connect(reply, &QNetworkReply::finished, this, [this, reply, callback]() { // 显式捕获 this
        if (reply->error() != QNetworkReply::NoError) {
            QMessageBox::critical(nullptr, "错误", "获取Access Token失败：" + reply->errorString());
            reply->deleteLater();
            return;
        }

        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QString accessToken = jsonDoc.object().value("access_token").toString();
        qDebug() << "获取的 Access Token：" << accessToken;

        reply->deleteLater();
        if (accessToken.isEmpty()) {
            QMessageBox::critical(nullptr, "错误", "Access Token解析失败！");
            return;
        }

        callback(accessToken); // 调用回调函数，传递 Access Token
    });
}




// 调用车牌识别接口
void parkingwindow::recognizeLicensePlate(const QString &imageBase64, const QString &accessToken) {
    QNetworkRequest request(QUrl("https://aip.baidubce.com/rest/2.0/ocr/v1/license_plate?access_token=" + accessToken));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray postData;
    postData.append("image=").append(QUrl::toPercentEncoding(imageBase64)); // 确保 URL 编码
    //qDebug() << "请求 POST 数据：" << postData;

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            //qDebug() << "响应数据：" << responseData; // 打印完整响应

            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObject = jsonResponse.object();

            if (jsonObject.contains("words_result")) {
                QString plateNumber = jsonObject["words_result"].toObject()["number"].toString();
                if (!plateNumber.isEmpty()) {
                     qDebug() << "识别到车牌号：" << plateNumber;
                    //QMessageBox::information(this, "车牌识别结果", "识别到的车牌号: " + plateNumber);
                     emit requestCheckCarId(plateNumber);
                } else {
                    QMessageBox::warning(this, "警告", "未识别到车牌，请检查图片！");
                }
            } else {
                QMessageBox::warning(this, "警告", "响应中未包含车牌信息！");
            }
        } else {
            QMessageBox::warning(this, "错误", "车牌识别失败：" + reply->errorString());
        }
        reply->deleteLater();
    });

    manager->post(request, postData); // 发送 POST 请求
}




// 按钮点击事件
void parkingwindow::on_scanButton_clicked() {
    // 打开文件对话框，选择车牌图片
    QString filePath = QFileDialog::getOpenFileName(this, "选择车牌图片", "", "Images (*.png *.jpg *.jpeg)");
    // 如果未选择文件，直接返回，避免重复弹窗
    if (filePath.isEmpty()) {
        QMessageBox::warning(this, "警告", "未选择图片！");
        return;
    }

    QString imageBase64 = encodeToBase64(filePath);
    if (imageBase64.isEmpty()) {
        QMessageBox::critical(this, "错误", "图片编码失败！");
        return;
    }
    // 获取 Access Token 并调用车牌识别
    getAccessToken([this, imageBase64](const QString &accessToken) {
        recognizeLicensePlate(imageBase64, accessToken);
    });

}
std::optional<std::pair<int, QString>> parkingwindow::getNonRegisteredCarInfo(const QString &carId) {
    // 创建对话框
    QDialog dialog(this);
    dialog.setWindowTitle(QString("车辆入库: %1").arg(carId));
    dialog.setModal(true);
    dialog.resize(300, 200);

    // 创建布局
    QVBoxLayout *layout = new QVBoxLayout(&dialog);

    // 提示标签
    QLabel *label = new QLabel(QString("车牌号: %1 正在入库").arg(carId), &dialog);
    layout->addWidget(label);

    // 车位号输入框
    QLabel *carPosLabel = new QLabel("车位号:", &dialog);
    QLineEdit *carPosInput = new QLineEdit(&dialog);
    carPosInput->setValidator(new QIntValidator(1, 999, &dialog)); // 限制为整数输入
    QHBoxLayout *carPosLayout = new QHBoxLayout();
    carPosLayout->addWidget(carPosLabel);
    carPosLayout->addWidget(carPosInput);
    layout->addLayout(carPosLayout);

    // 类型下拉框
    QLabel *carTypeLabel = new QLabel("车型:", &dialog);
    QComboBox *carTypeComboBox = new QComboBox(&dialog);
    carTypeComboBox->addItems({"小型车", "中型车", "大型车"});
    QHBoxLayout *carTypeLayout = new QHBoxLayout();
    carTypeLayout->addWidget(carTypeLabel);
    carTypeLayout->addWidget(carTypeComboBox);
    layout->addLayout(carTypeLayout);

    // 确定和取消按钮
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *confirmButton = new QPushButton("确定", &dialog);
    QPushButton *cancelButton = new QPushButton("取消", &dialog);
    buttonLayout->addWidget(confirmButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);

    // 连接按钮信号
    connect(confirmButton, &QPushButton::clicked, [&]() {
        if (carPosInput->text().isEmpty()) {
            QMessageBox::warning(&dialog, "警告", "请输入车位号！");
        } else {
            dialog.accept(); // 提交数据并关闭对话框
        }
    });

    connect(cancelButton, &QPushButton::clicked, [&]() {
        dialog.reject(); // 取消操作并关闭对话框
    });

    // 显示对话框并等待结果
    if (dialog.exec() == QDialog::Accepted) {
        int carPos = carPosInput->text().toInt();
        QString carType = carTypeComboBox->currentText();
        return std::make_optional(std::make_pair(carPos, carType)); // 返回填写的值
    }

    QMessageBox::information(this, "取消", "用户取消入库操作！");
    return std::nullopt; // 返回空值
}
// //它是一个辅助函数，用于弹出对话框，让用户填写非注册用户的车位信息。
// bool getNonRegisteredCarInfo(QString &carType, int &carPos) {
//     bool ok;

//     // 获取车辆类型
//     carType = QInputDialog::getText(nullptr, "输入车辆类型",
//                                     "请输入车辆类型（如小型车、中型车、大型车）：",
//                                     QLineEdit::Normal, QString(), &ok);
//     if (!ok || carType.isEmpty()) {
//         QMessageBox::warning(nullptr, "警告", "未填写车辆类型或取消操作！");
//         return false;
//     }

//     // 获取车位号
//     carPos = QInputDialog::getInt(nullptr, "输入车位号",
//                                   "请输入车位号：",
//                                   1, 1, 1000, 1, &ok);
//     if (!ok) {
//         QMessageBox::warning(nullptr, "警告", "未填写车位号或取消操作！");
//         return false;
//     }

//     return true;
// }

// //非注册用户操作函数
// void parkingwindow::processNonRegisteredCar(const QString &carId, const QString &parkingName) {
//     // 弹出对话框获取车辆类型和车位号
//     QString carType;
//     int carPos;

//     bool ok = getNonRegisteredCarInfo(carType, carPos);
//     if (!ok) {
//         QMessageBox::warning(this, "操作取消", "非注册用户停车流程已取消！");

//         return;
//     }

//     // 当前时间作为停车时间
//     QDateTime startTime = QDateTime::currentDateTime();

//     // 发送信号请求数据库操作
//     emit requestInsertNonRegisteredCar(carId, parkingName, carType, carPos, startTime);
// }


// void parkingwindow::on_pushButton_2_clicked() {
//     QDialog *userDialog = new QDialog(this);
//     userDialog->setWindowTitle("用户信息");
//     userDialog->resize(600, 400);

//     QTableWidget *userTable = new QTableWidget(userDialog);
//     userTable->setColumnCount(4); // 设置列数
//     userTable->setHorizontalHeaderLabels(QStringList() << "ID" << "姓名" << "电话" << "用户类型");
//     userTable->horizontalHeader()->setStretchLastSection(true); // 拉伸最后一列
//     userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 自适应列宽
//     userTable->verticalHeader()->setVisible(false); // 隐藏垂直表头
//     userTable->resize(userDialog->size());
//     userTable->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑

//     // 设置表头文字居中对齐
//     QHeaderView *header = userTable->horizontalHeader();
//     header->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

//     // 设置表头字体加粗
//     QFont headerFont = userTable->font();
//     headerFont.setBold(true); // 加粗
//     userTable->horizontalHeader()->setFont(headerFont);

//     // 查询数据库并填充表格
//     QSqlQuery query;
//     QString userQuery = "SELECT id, name, tel, type FROM userinfo";
//     if (!query.exec(userQuery)) {
//         QMessageBox::warning(this, "错误", "查询用户信息失败：" + query.lastError().text());
//         return;
//     }

//     int row = 0;
//     while (query.next()) {
//         userTable->insertRow(row); // 添加新行
//         for (int col = 0; col < 4; ++col) {
//             QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
//             item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); // 水平居中 + 垂直居中
//             userTable->setItem(row, col, item);
//         }
//         row++;
//     }

//     userDialog->exec(); // 显示弹出窗口
// }

void parkingwindow::on_pushButton_2_clicked() {
    QDialog *userDialog = new QDialog(this);
    userDialog->setWindowTitle("用户信息");
    userDialog->resize(600, 400);

    // 创建一个垂直布局管理器，用于管理控件
    QVBoxLayout *layout = new QVBoxLayout(userDialog);

    // 创建一个水平布局管理器，用于放置查询条件和按钮
    QHBoxLayout *hLayout = new QHBoxLayout();

    // 创建一个QLineEdit用于输入查询条件
    QLineEdit *searchEdit = new QLineEdit(userDialog);
    searchEdit->setPlaceholderText("请输入ID或姓名进行查询");
    hLayout->addWidget(searchEdit, 1); // 让searchEdit占用一半空间

    // 创建查询按钮
    QPushButton *searchButton = new QPushButton("查询", userDialog);
    hLayout->addWidget(searchButton, 1); // 让searchButton占用另一半空间

    // 创建显示全部按钮
    QPushButton *showAllButton = new QPushButton("显示全部", userDialog);
    hLayout->addWidget(showAllButton, 1); // 让showAllButton占用另一半空间

    // 将水平布局添加到主布局中
    layout->addLayout(hLayout);

    // 创建QTableWidget用于显示用户信息
    QTableWidget *userTable = new QTableWidget(userDialog);
    userTable->setColumnCount(4); // 设置列数
    userTable->setHorizontalHeaderLabels(QStringList() << "ID" << "姓名" << "电话" << "用户类型");
    userTable->horizontalHeader()->setStretchLastSection(true); // 拉伸最后一列
    userTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); // 自适应列宽
    userTable->verticalHeader()->setVisible(false); // 隐藏垂直表头
    userTable->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑

    // 设置表头文字居中对齐
    QHeaderView *header = userTable->horizontalHeader();
    header->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // 设置表头字体加粗
    QFont headerFont = userTable->font();
    headerFont.setBold(true); // 加粗
    userTable->horizontalHeader()->setFont(headerFont);

    // 将表格控件添加到布局中
    layout->addWidget(userTable);

    // 查询并更新表格内容的函数
    auto updateTable = [this, userTable, searchEdit](const QString &searchText = "") {
        QSqlQuery query;
        QString userQuery;

        // 如果有搜索条件，则进行模糊查询，否则显示全部
        if (searchText.isEmpty()) {
            userQuery = "SELECT id, name, tel, type FROM userinfo"; // 查询所有数据
        } else {
            userQuery = "SELECT id, name, tel, type FROM userinfo WHERE id LIKE '%" + searchText + "%' OR name LIKE '%" + searchText + "%'"; // 根据ID或姓名查询
        }

        if (!query.exec(userQuery)) { // 执行查询
            QMessageBox::warning(this, "错误", "查询用户信息失败：" + query.lastError().text());
            return;
        }

        // 清空之前的表格数据
        userTable->setRowCount(0);

        int row = 0;
        while (query.next()) { // 遍历查询结果并插入到表格中
            userTable->insertRow(row); // 添加新行
            for (int col = 0; col < 4; ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); // 水平居中 + 垂直居中
                userTable->setItem(row, col, item);
            }
            row++;
        }
    };

    // 点击查询按钮时根据输入内容更新表格
    connect(searchButton, &QPushButton::clicked, [this, searchEdit, updateTable]() {
        QString searchText = searchEdit->text(); // 获取输入框中的查询条件
        updateTable(searchText); // 更新表格数据
    });

    // 点击显示全部按钮时显示所有用户信息
    connect(showAllButton, &QPushButton::clicked, [this, updateTable]() {
        updateTable(); // 显示所有数据
    });

    // 默认显示所有数据
    updateTable();  // 调用此函数在窗口打开时加载所有用户数据

    userDialog->exec(); // 显示弹出窗口
}










