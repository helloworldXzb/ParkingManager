/********************************************************************************
** Form generated from reading UI file 'parkingwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARKINGWINDOW_H
#define UI_PARKINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parkingwindow
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *parkingwindow)
    {
        if (parkingwindow->objectName().isEmpty())
            parkingwindow->setObjectName("parkingwindow");
        parkingwindow->resize(980, 600);
        parkingwindow->setMinimumSize(QSize(980, 600));
        parkingwindow->setMaximumSize(QSize(980, 600));
        scrollArea = new QScrollArea(parkingwindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 80, 961, 391));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 959, 389));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(parkingwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 510, 111, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(parkingwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 510, 111, 21));
        label_2->setFont(font);
        label_3 = new QLabel(parkingwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(670, 510, 91, 21));
        label_3->setFont(font);
        lineEdit = new QLineEdit(parkingwindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 510, 113, 21));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(parkingwindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(490, 510, 113, 21));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(parkingwindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(770, 510, 113, 21));
        lineEdit_3->setReadOnly(true);
        label_4 = new QLabel(parkingwindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 40, 72, 21));
        label_4->setFont(font);
        label_5 = new QLabel(parkingwindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(320, 40, 72, 21));
        label_5->setFont(font);
        label_6 = new QLabel(parkingwindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(520, 40, 72, 21));
        label_6->setFont(font);
        label_7 = new QLabel(parkingwindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(740, 40, 72, 21));
        label_7->setFont(font);
        pushButton = new QPushButton(parkingwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(770, 550, 111, 28));
        pushButton_2 = new QPushButton(parkingwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(50, 550, 111, 28));

        retranslateUi(parkingwindow);

        QMetaObject::connectSlotsByName(parkingwindow);
    } // setupUi

    void retranslateUi(QWidget *parkingwindow)
    {
        parkingwindow->setWindowTitle(QCoreApplication::translate("parkingwindow", "\345\201\234\350\275\246\345\234\272\347\256\241\347\220\206\344\272\272\345\221\230\347\263\273\347\273\237", nullptr));
        label->setText(QCoreApplication::translate("parkingwindow", "\345\201\234\350\275\246\345\234\272\346\200\273\350\275\246\344\275\215", nullptr));
        label_2->setText(QCoreApplication::translate("parkingwindow", "\345\201\234\350\275\246\345\234\272\347\251\272\350\275\246\344\275\215", nullptr));
        label_3->setText(QCoreApplication::translate("parkingwindow", "\345\201\234\350\275\246\345\234\272\346\224\266\345\205\245", nullptr));
        label_4->setText(QCoreApplication::translate("parkingwindow", "\350\275\246\344\275\215\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("parkingwindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_6->setText(QCoreApplication::translate("parkingwindow", "\350\265\267\345\247\213\346\227\266\351\227\264", nullptr));
        label_7->setText(QCoreApplication::translate("parkingwindow", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        pushButton->setText(QCoreApplication::translate("parkingwindow", "\350\260\203\346\225\264\350\275\246\344\275\215", nullptr));
        pushButton_2->setText(QCoreApplication::translate("parkingwindow", "\346\211\253\346\217\217\350\275\246\347\211\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parkingwindow: public Ui_parkingwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARKINGWINDOW_H
