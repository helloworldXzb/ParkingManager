/********************************************************************************
** Form generated from reading UI file 'edit_info.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_INFO_H
#define UI_EDIT_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_info
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QComboBox *comboBox;

    void setupUi(QWidget *edit_info)
    {
        if (edit_info->objectName().isEmpty())
            edit_info->setObjectName("edit_info");
        edit_info->resize(489, 646);
        edit_info->setMinimumSize(QSize(489, 646));
        edit_info->setMaximumSize(QSize(489, 646));
        label = new QLabel(edit_info);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 70, 231, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(14);
        label->setFont(font);
        label_2 = new QLabel(edit_info);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 180, 41, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_3 = new QLabel(edit_info);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 280, 72, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(edit_info);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 380, 51, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(edit_info);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 480, 72, 21));
        label_5->setFont(font1);
        lineEdit = new QLineEdit(edit_info);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 180, 181, 21));
        lineEdit->setMaxLength(20);
        lineEdit_2 = new QLineEdit(edit_info);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(160, 280, 181, 21));
        lineEdit_2->setMaxLength(20);
        lineEdit_3 = new QLineEdit(edit_info);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(160, 380, 181, 21));
        lineEdit_3->setMaxLength(20);
        pushButton = new QPushButton(edit_info);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 550, 101, 41));
        pushButton->setFont(font1);
        comboBox = new QComboBox(edit_info);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(160, 480, 181, 22));

        retranslateUi(edit_info);

        QMetaObject::connectSlotsByName(edit_info);
    } // setupUi

    void retranslateUi(QWidget *edit_info)
    {
        edit_info->setWindowTitle(QCoreApplication::translate("edit_info", "\344\277\256\346\224\271\344\270\252\344\272\272\350\265\204\346\226\231", nullptr));
        label->setText(QCoreApplication::translate("edit_info", "\350\257\267\350\276\223\345\205\245\346\226\260\347\232\204\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("edit_info", "<html><head/><body><p>\345\247\223\345\220\215</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("edit_info", "<html><head/><body><p>\350\201\224\347\263\273\346\226\271\345\274\217</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("edit_info", "<html><head/><body><p>\350\275\246\347\211\214\345\217\267</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("edit_info", "<html><head/><body><p>\350\275\246\350\276\206\347\261\273\345\236\213</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("edit_info", "\347\241\256\350\256\244", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("edit_info", "\345\244\247\345\236\213\350\275\246", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("edit_info", "\344\270\255\345\236\213\350\275\246", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("edit_info", "\345\260\217\345\236\213\350\275\246", nullptr));

    } // retranslateUi

};

namespace Ui {
    class edit_info: public Ui_edit_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_INFO_H
