/********************************************************************************
** Form generated from reading UI file 'topup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPUP_H
#define UI_TOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_topup
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QWidget *topup)
    {
        if (topup->objectName().isEmpty())
            topup->setObjectName("topup");
        topup->resize(433, 149);
        topup->setMinimumSize(QSize(433, 149));
        topup->setMaximumSize(QSize(433, 149));
        label = new QLabel(topup);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 40, 211, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(10);
        label->setFont(font);
        lineEdit = new QLineEdit(topup);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(260, 40, 113, 21));
        lineEdit->setMaxLength(8);
        pushButton = new QPushButton(topup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 90, 93, 41));
        pushButton->setFont(font);

        retranslateUi(topup);

        QMetaObject::connectSlotsByName(topup);
    } // setupUi

    void retranslateUi(QWidget *topup)
    {
        topup->setWindowTitle(QCoreApplication::translate("topup", "\345\205\205\345\200\274\347\225\214\351\235\242", nullptr));
        label->setText(QCoreApplication::translate("topup", "<html><head/><body><p>\350\257\267\350\276\223\345\205\245\346\202\250\351\234\200\350\246\201\345\205\205\345\200\274\347\232\204\351\207\221\351\242\235</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("topup", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class topup: public Ui_topup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPUP_H
