/********************************************************************************
** Form generated from reading UI file 'parkingsettings.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARKINGSETTINGS_H
#define UI_PARKINGSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parkingsettings
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QPushButton *pushButton_2;

    void setupUi(QWidget *parkingsettings)
    {
        if (parkingsettings->objectName().isEmpty())
            parkingsettings->setObjectName("parkingsettings");
        parkingsettings->resize(980, 600);
        parkingsettings->setMaximumSize(QSize(980, 600));
        QFont font;
        font.setBold(false);
        parkingsettings->setFont(font);
        label = new QLabel(parkingsettings);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 510, 191, 31));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        label->setFont(font1);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        scrollArea = new QScrollArea(parkingsettings);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 80, 961, 431));
        scrollArea->setFont(font);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 959, 429));
        scrollArea->setWidget(scrollAreaWidgetContents);
        label_2 = new QLabel(parkingsettings);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(120, 50, 69, 19));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        label_2->setFont(font2);
        label_3 = new QLabel(parkingsettings);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(420, 50, 69, 19));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font3.setPointSize(10);
        font3.setBold(false);
        label_3->setFont(font3);
        label_4 = new QLabel(parkingsettings);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(700, 50, 69, 19));
        label_4->setFont(font3);
        pushButton = new QPushButton(parkingsettings);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(880, 510, 92, 28));
        lineEdit = new QLineEdit(parkingsettings);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(670, 510, 113, 27));
        comboBox = new QComboBox(parkingsettings);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(780, 510, 101, 27));
        pushButton_2 = new QPushButton(parkingsettings);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 510, 92, 28));

        retranslateUi(parkingsettings);

        QMetaObject::connectSlotsByName(parkingsettings);
    } // setupUi

    void retranslateUi(QWidget *parkingsettings)
    {
        parkingsettings->setWindowTitle(QCoreApplication::translate("parkingsettings", "\350\260\203\346\225\264\350\275\246\344\275\215", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("parkingsettings", "\350\275\246\344\275\215\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("parkingsettings", "\350\275\246\344\275\215\347\261\273\345\236\213", nullptr));
        label_4->setText(QCoreApplication::translate("parkingsettings", "\350\275\246\344\275\215\347\212\266\346\200\201", nullptr));
        pushButton->setText(QCoreApplication::translate("parkingsettings", "\346\267\273\345\212\240\350\275\246\344\275\215", nullptr));
        pushButton_2->setText(QCoreApplication::translate("parkingsettings", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parkingsettings: public Ui_parkingsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARKINGSETTINGS_H
