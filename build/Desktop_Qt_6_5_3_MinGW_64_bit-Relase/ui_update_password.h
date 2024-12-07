/********************************************************************************
** Form generated from reading UI file 'update_password.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_PASSWORD_H
#define UI_UPDATE_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_update_password
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;

    void setupUi(QWidget *update_password)
    {
        if (update_password->objectName().isEmpty())
            update_password->setObjectName("update_password");
        update_password->resize(489, 348);
        label = new QLabel(update_password);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 70, 121, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(10);
        label->setFont(font);
        label_2 = new QLabel(update_password);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 140, 121, 21));
        label_2->setFont(font);
        label_3 = new QLabel(update_password);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 210, 161, 21));
        label_3->setFont(font);
        lineEdit = new QLineEdit(update_password);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(190, 70, 191, 21));
        lineEdit->setEchoMode(QLineEdit::Password);
        lineEdit_2 = new QLineEdit(update_password);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(190, 140, 191, 21));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        lineEdit_3 = new QLineEdit(update_password);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(190, 210, 191, 21));
        lineEdit_3->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(update_password);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 280, 121, 41));
        pushButton->setFont(font);

        retranslateUi(update_password);

        QMetaObject::connectSlotsByName(update_password);
    } // setupUi

    void retranslateUi(QWidget *update_password)
    {
        update_password->setWindowTitle(QCoreApplication::translate("update_password", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("update_password", "\350\257\267\350\276\223\345\205\245\346\227\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("update_password", "\350\257\267\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("update_password", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("update_password", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class update_password: public Ui_update_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_PASSWORD_H
