/********************************************************************************
** Form generated from reading UI file 'registered.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERED_H
#define UI_REGISTERED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registered
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;

    void setupUi(QWidget *registered)
    {
        if (registered->objectName().isEmpty())
            registered->setObjectName("registered");
        registered->resize(489, 646);
        registered->setMinimumSize(QSize(489, 646));
        registered->setMaximumSize(QSize(489, 646));
        label = new QLabel(registered);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 50, 291, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(24);
        label->setFont(font);
        label_3 = new QLabel(registered);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 150, 51, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(10);
        label_3->setFont(font1);
        label_4 = new QLabel(registered);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 210, 41, 16));
        label_4->setFont(font1);
        label_5 = new QLabel(registered);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 270, 111, 16));
        label_5->setFont(font1);
        label_6 = new QLabel(registered);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 330, 41, 16));
        label_6->setFont(font1);
        label_7 = new QLabel(registered);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(90, 390, 61, 16));
        label_7->setFont(font1);
        label_8 = new QLabel(registered);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(100, 450, 41, 16));
        label_8->setFont(font1);
        label_9 = new QLabel(registered);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(90, 510, 61, 16));
        label_9->setFont(font1);
        pushButton = new QPushButton(registered);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 570, 111, 41));
        pushButton->setFont(font1);
        comboBox = new QComboBox(registered);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(160, 450, 201, 22));
        lineEdit = new QLineEdit(registered);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 150, 201, 21));
        lineEdit->setMaxLength(20);
        lineEdit_2 = new QLineEdit(registered);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(160, 210, 201, 21));
        lineEdit_2->setMaxLength(20);
        lineEdit_3 = new QLineEdit(registered);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(160, 270, 201, 21));
        lineEdit_3->setMaxLength(20);
        lineEdit_4 = new QLineEdit(registered);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(160, 330, 201, 21));
        lineEdit_4->setMaxLength(20);
        lineEdit_5 = new QLineEdit(registered);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(160, 390, 201, 21));
        lineEdit_5->setMaxLength(20);
        lineEdit_6 = new QLineEdit(registered);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(160, 510, 201, 21));
        lineEdit_6->setMaxLength(11);

        retranslateUi(registered);

        QMetaObject::connectSlotsByName(registered);
    } // setupUi

    void retranslateUi(QWidget *registered)
    {
        registered->setWindowTitle(QCoreApplication::translate("registered", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("registered", "\345\201\234\350\275\246\345\234\272\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        label_3->setText(QCoreApplication::translate("registered", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("registered", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("registered", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_6->setText(QCoreApplication::translate("registered", "\345\247\223\345\220\215", nullptr));
        label_7->setText(QCoreApplication::translate("registered", "\350\275\246\347\211\214\345\217\267", nullptr));
        label_8->setText(QCoreApplication::translate("registered", "\350\275\246\345\236\213", nullptr));
        label_9->setText(QCoreApplication::translate("registered", "\346\211\213\346\234\272\345\217\267", nullptr));
        pushButton->setText(QCoreApplication::translate("registered", "\346\263\250\345\206\214", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("registered", "\345\244\247\345\236\213\350\275\246", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("registered", "\344\270\255\345\236\213\350\275\246", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("registered", "\345\260\217\345\236\213\350\275\246", nullptr));

    } // retranslateUi

};

namespace Ui {
    class registered: public Ui_registered {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERED_H
