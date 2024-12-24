/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userwindow
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab_2;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QDateTimeEdit *dateTimeEdit;
    QDateTimeEdit *dateTimeEdit_2;
    QLabel *label_11;
    QComboBox *comboBox;
    QPushButton *pushButton_02;
    QWidget *tab_6;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_6;
    QLabel *label_28;
    QLineEdit *lineEdit_14;
    QLabel *label_29;
    QLabel *label_30;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_15;
    QLabel *label_31;
    QLabel *label_12;
    QWidget *tab_3;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_10;
    QWidget *tab_4;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QWidget *tab_5;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *userwindow)
    {
        if (userwindow->objectName().isEmpty())
            userwindow->setObjectName("userwindow");
        userwindow->resize(980, 600);
        userwindow->setMinimumSize(QSize(980, 600));
        userwindow->setMaximumSize(QSize(980, 600));
        tabWidget = new QTabWidget(userwindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(30, 30, 911, 561));
        tabWidget->setMaximumSize(QSize(911, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setTabsClosable(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        scrollArea = new QScrollArea(tab);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 50, 851, 471));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 849, 469));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 20, 72, 15));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(300, 20, 72, 15));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(520, 20, 72, 15));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(720, 20, 101, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        scrollArea_5 = new QScrollArea(tab_2);
        scrollArea_5->setObjectName("scrollArea_5");
        scrollArea_5->setGeometry(QRect(0, 0, 891, 561));
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName("scrollAreaWidgetContents_5");
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 889, 559));
        label_7 = new QLabel(scrollAreaWidgetContents_5);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(180, 90, 221, 21));
        label_8 = new QLabel(scrollAreaWidgetContents_5);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(180, 170, 241, 21));
        label_9 = new QLabel(scrollAreaWidgetContents_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(160, 250, 241, 21));
        label_10 = new QLabel(scrollAreaWidgetContents_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(160, 330, 231, 21));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents_5);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(400, 430, 101, 41));
        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents_5);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(440, 170, 191, 21));
        lineEdit_2->setMaxLength(20);
        dateTimeEdit = new QDateTimeEdit(scrollAreaWidgetContents_5);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(440, 250, 194, 22));
        dateTimeEdit_2 = new QDateTimeEdit(scrollAreaWidgetContents_5);
        dateTimeEdit_2->setObjectName("dateTimeEdit_2");
        dateTimeEdit_2->setGeometry(QRect(440, 330, 194, 22));
        label_11 = new QLabel(scrollAreaWidgetContents_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(290, 30, 311, 20));
        comboBox = new QComboBox(scrollAreaWidgetContents_5);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(440, 90, 191, 27));
        pushButton_02 = new QPushButton(scrollAreaWidgetContents_5);
        pushButton_02->setObjectName("pushButton_02");
        pushButton_02->setGeometry(QRect(640, 90, 101, 31));
        scrollArea_5->setWidget(scrollAreaWidgetContents_5);
        tabWidget->addTab(tab_2, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        scrollArea_6 = new QScrollArea(tab_6);
        scrollArea_6->setObjectName("scrollArea_6");
        scrollArea_6->setGeometry(QRect(0, 0, 891, 561));
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName("scrollAreaWidgetContents_6");
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 889, 559));
        label_28 = new QLabel(scrollAreaWidgetContents_6);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(230, 170, 131, 21));
        lineEdit_14 = new QLineEdit(scrollAreaWidgetContents_6);
        lineEdit_14->setObjectName("lineEdit_14");
        lineEdit_14->setGeometry(QRect(380, 170, 113, 21));
        lineEdit_14->setReadOnly(true);
        label_29 = new QLabel(scrollAreaWidgetContents_6);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(510, 170, 261, 21));
        label_30 = new QLabel(scrollAreaWidgetContents_6);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(300, 270, 72, 21));
        pushButton_8 = new QPushButton(scrollAreaWidgetContents_6);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(360, 370, 151, 61));
        lineEdit_15 = new QLineEdit(scrollAreaWidgetContents_6);
        lineEdit_15->setObjectName("lineEdit_15");
        lineEdit_15->setGeometry(QRect(380, 270, 113, 21));
        lineEdit_15->setReadOnly(true);
        label_31 = new QLabel(scrollAreaWidgetContents_6);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(520, 270, 72, 15));
        label_12 = new QLabel(scrollAreaWidgetContents_6);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(390, 10, 111, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(16);
        label_12->setFont(font1);
        scrollArea_6->setWidget(scrollAreaWidgetContents_6);
        tabWidget->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        scrollArea_4 = new QScrollArea(tab_3);
        scrollArea_4->setObjectName("scrollArea_4");
        scrollArea_4->setGeometry(QRect(0, 0, 891, 561));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 889, 559));
        label_13 = new QLabel(scrollAreaWidgetContents_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(170, 60, 51, 21));
        label_13->setLayoutDirection(Qt::LeftToRight);
        label_14 = new QLabel(scrollAreaWidgetContents_4);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(190, 130, 41, 21));
        label_15 = new QLabel(scrollAreaWidgetContents_4);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(170, 200, 51, 21));
        label_16 = new QLabel(scrollAreaWidgetContents_4);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(150, 270, 72, 21));
        label_17 = new QLabel(scrollAreaWidgetContents_4);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(150, 340, 72, 21));
        label_18 = new QLabel(scrollAreaWidgetContents_4);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(150, 410, 72, 21));
        label_19 = new QLabel(scrollAreaWidgetContents_4);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(180, 480, 41, 21));
        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(270, 60, 161, 21));
        lineEdit_7->setReadOnly(true);
        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(270, 130, 161, 21));
        lineEdit_8->setReadOnly(true);
        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(270, 200, 161, 21));
        lineEdit_9->setReadOnly(true);
        lineEdit_10 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(270, 270, 161, 21));
        lineEdit_10->setReadOnly(true);
        lineEdit_11 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(270, 340, 161, 21));
        lineEdit_11->setReadOnly(true);
        lineEdit_12 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(270, 410, 161, 21));
        lineEdit_12->setReadOnly(true);
        lineEdit_13 = new QLineEdit(scrollAreaWidgetContents_4);
        lineEdit_13->setObjectName("lineEdit_13");
        lineEdit_13->setGeometry(QRect(270, 480, 161, 21));
        lineEdit_13->setReadOnly(true);
        pushButton_3 = new QPushButton(scrollAreaWidgetContents_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(610, 110, 121, 61));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents_4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(610, 380, 121, 61));
        pushButton_10 = new QPushButton(scrollAreaWidgetContents_4);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(610, 240, 121, 61));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        scrollArea_3 = new QScrollArea(tab_4);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(0, 0, 891, 561));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 889, 559));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(180, 400, 131, 51));
        pushButton_6 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(380, 400, 131, 51));
        pushButton_7 = new QPushButton(scrollAreaWidgetContents_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(570, 400, 131, 51));
        label_20 = new QLabel(scrollAreaWidgetContents_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(260, 100, 111, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font2.setPointSize(14);
        label_20->setFont(font2);
        label_21 = new QLabel(scrollAreaWidgetContents_3);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(500, 100, 101, 31));
        label_21->setFont(font2);
        label_22 = new QLabel(scrollAreaWidgetContents_3);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(270, 170, 72, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font3.setPointSize(11);
        label_22->setFont(font3);
        label_23 = new QLabel(scrollAreaWidgetContents_3);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(270, 240, 72, 21));
        label_23->setFont(font3);
        label_24 = new QLabel(scrollAreaWidgetContents_3);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(270, 310, 72, 21));
        label_24->setFont(font3);
        label_25 = new QLabel(scrollAreaWidgetContents_3);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(500, 170, 91, 16));
        label_25->setFont(font3);
        label_26 = new QLabel(scrollAreaWidgetContents_3);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(510, 240, 81, 16));
        label_26->setFont(font3);
        label_27 = new QLabel(scrollAreaWidgetContents_3);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(510, 310, 81, 16));
        label_27->setFont(font3);
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        scrollArea_2 = new QScrollArea(tab_5);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(0, 0, 891, 561));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 889, 559));
        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 80, 141, 111));
        label->setPixmap(QPixmap(QString::fromUtf8(":/question.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 240, 361, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\346\245\267\344\275\223")});
        font4.setPointSize(22);
        label_2->setFont(font4);
        pushButton = new QPushButton(scrollAreaWidgetContents_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(390, 330, 101, 41));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        tabWidget->addTab(tab_5, QString());

        retranslateUi(userwindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(userwindow);
    } // setupUi

    void retranslateUi(QWidget *userwindow)
    {
        userwindow->setWindowTitle(QCoreApplication::translate("userwindow", "\347\224\250\346\210\267", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("userwindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_3->setText(QCoreApplication::translate("userwindow", "\350\275\246\344\275\215\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("userwindow", "\351\200\202\345\201\234\350\275\246\345\236\213", nullptr));
        label_5->setText(QCoreApplication::translate("userwindow", "\350\275\246\344\275\215\347\212\266\346\200\201", nullptr));
        label_6->setText(QCoreApplication::translate("userwindow", "\346\211\200\345\234\250\345\201\234\350\275\246\345\234\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("userwindow", "\345\201\234\350\275\246\346\237\245\350\257\242", nullptr));
        label_7->setText(QCoreApplication::translate("userwindow", "\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\350\246\201\351\242\204\347\272\246\347\232\204\345\201\234\350\275\246\345\234\272", nullptr));
        label_8->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\350\246\201\351\242\204\347\272\246\347\232\204\350\275\246\344\275\215\345\217\267</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\350\246\201\351\242\204\347\272\246\347\232\204\345\274\200\345\247\213\346\227\266\351\227\264</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\350\257\267\350\276\223\345\205\245\346\202\250\346\203\263\350\246\201\351\242\204\347\272\246\347\232\204\347\273\223\346\235\237\346\227\266\351\227\264</p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("userwindow", "\347\241\256\350\256\244", nullptr));
        label_11->setText(QCoreApplication::translate("userwindow", "\357\274\210\346\227\266\351\227\264\346\230\276\347\244\272\346\241\206\357\274\211", nullptr));
        pushButton_02->setText(QCoreApplication::translate("userwindow", "\346\237\245\350\257\242\345\201\234\350\275\246\345\234\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("userwindow", "\351\242\204\347\272\246", nullptr));
        label_28->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\346\202\250\345\267\262\350\266\205\350\277\207\351\242\204\347\272\246\346\227\266</p></body></html>", nullptr));
        label_29->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\345\260\217\346\227\266\357\274\210\346\234\252\346\273\2411\345\260\217\346\227\266\346\214\211\344\270\200\345\260\217\346\227\266\350\256\241\347\256\227\357\274\211</p></body></html>", nullptr));
        label_30->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\351\234\200\347\274\264\347\272\263</p></body></html>", nullptr));
        pushButton_8->setText(QCoreApplication::translate("userwindow", "\345\256\232\344\275\215\345\217\226\350\275\246\345\271\266\347\274\264\350\264\271", nullptr));
        label_31->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>CNY</p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("userwindow", "\351\242\204\347\272\246\346\203\205\345\206\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("userwindow", "\345\217\226\350\275\246\344\270\216\347\274\264\350\264\271", nullptr));
        label_13->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\347\224\250\346\210\267\345\220\215</p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\345\247\223\345\220\215</p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\350\275\246\347\211\214\345\217\267</p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\350\201\224\347\263\273\346\226\271\345\274\217</p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\350\275\246\350\276\206\347\261\273\345\236\213</p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\345\256\242\346\210\267\347\261\273\345\236\213</p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\344\275\231\351\242\235</p></body></html>", nullptr));
        pushButton_3->setText(QCoreApplication::translate("userwindow", "\347\274\226\350\276\221\344\277\241\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("userwindow", "\346\266\210\350\264\271\350\256\260\345\275\225\346\237\245\350\257\242", nullptr));
        pushButton_10->setText(QCoreApplication::translate("userwindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("userwindow", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        pushButton_5->setText(QCoreApplication::translate("userwindow", "\345\271\264\350\264\271\344\274\232\345\221\230\345\212\236\347\220\206", nullptr));
        pushButton_6->setText(QCoreApplication::translate("userwindow", "\346\234\210\350\264\271\344\274\232\345\221\230\345\212\236\347\220\206", nullptr));
        pushButton_7->setText(QCoreApplication::translate("userwindow", "\344\275\231\351\242\235\345\205\205\345\200\274", nullptr));
        label_20->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\347\224\250\346\210\267\347\261\273\345\236\213</p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\350\265\204\350\264\271\346\240\207\345\207\206</p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\345\271\264\350\264\271\347\224\250\346\210\267</p><p><br/></p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\346\234\210\350\264\271\347\224\250\346\210\267</p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>\346\231\256\351\200\232\347\224\250\346\210\267</p></body></html>", nullptr));
        label_25->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>2500CNY/\345\271\264</p></body></html>", nullptr));
        label_26->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>260CNY/\346\234\210</p></body></html>", nullptr));
        label_27->setText(QCoreApplication::translate("userwindow", "<html><head/><body><p>3CNY/\345\260\217\346\227\266</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("userwindow", "\345\205\205\345\200\274", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("userwindow", "\346\230\257\345\220\246\347\241\256\345\256\232\351\200\200\345\207\272\347\231\273\345\275\225\357\274\237", nullptr));
        pushButton->setText(QCoreApplication::translate("userwindow", "\347\241\256\345\256\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("userwindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userwindow: public Ui_userwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
