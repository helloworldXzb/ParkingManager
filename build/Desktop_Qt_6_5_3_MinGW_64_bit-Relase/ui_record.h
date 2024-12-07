/********************************************************************************
** Form generated from reading UI file 'record.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_H
#define UI_RECORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_record
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QWidget *record)
    {
        if (record->objectName().isEmpty())
            record->setObjectName("record");
        record->resize(1200, 600);
        record->setMinimumSize(QSize(1200, 600));
        record->setMaximumSize(QSize(1200, 600));
        scrollArea = new QScrollArea(record);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(20, 70, 1151, 511));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1149, 509));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(record);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 72, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(record);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 40, 72, 21));
        label_2->setFont(font);
        label_3 = new QLabel(record);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(360, 40, 72, 21));
        label_3->setFont(font);
        label_4 = new QLabel(record);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 40, 101, 16));
        label_4->setFont(font);
        label_5 = new QLabel(record);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(620, 40, 111, 21));
        label_5->setFont(font);
        label_6 = new QLabel(record);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(760, 40, 111, 21));
        label_6->setFont(font);
        label_7 = new QLabel(record);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(920, 40, 81, 21));
        label_7->setFont(font);
        label_8 = new QLabel(record);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1070, 40, 41, 21));
        label_8->setFont(font);

        retranslateUi(record);

        QMetaObject::connectSlotsByName(record);
    } // setupUi

    void retranslateUi(QWidget *record)
    {
        record->setWindowTitle(QCoreApplication::translate("record", "\346\266\210\350\264\271\350\256\260\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("record", "<html><head/><body><p>\347\224\250\346\210\267\345\220\215</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("record", "<html><head/><body><p>\350\256\242\345\215\225\345\217\267</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("record", "<html><head/><body><p>\350\275\246\344\275\215\345\217\267</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("record", "<html><head/><body><p>\346\211\200\345\234\250\345\201\234\350\275\246\345\234\272</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("record", "<html><head/><body><p>\351\242\204\347\272\246\350\265\267\345\247\213\346\227\266\351\227\264</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("record", "<html><head/><body><p>\351\242\204\347\272\246\347\273\223\346\235\237\346\227\266\351\227\264</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("record", "<html><head/><body><p>\350\266\205\346\227\266\346\227\266\351\225\277</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("record", "<html><head/><body><p>\350\264\271\347\224\250</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class record: public Ui_record {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_H
