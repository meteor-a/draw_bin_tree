/********************************************************************************
** Form generated from reading UI file 'dialogdeletechoose.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGDELETECHOOSE_H
#define UI_DIALOGDELETECHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogDeleteChoose
{
public:
    QLabel *label;
    QPushButton *pushButton_number_1;
    QPushButton *pushButton_number_2;

    void setupUi(QDialog *DialogDeleteChoose)
    {
        if (DialogDeleteChoose->objectName().isEmpty())
            DialogDeleteChoose->setObjectName(QString::fromUtf8("DialogDeleteChoose"));
        DialogDeleteChoose->resize(529, 184);
        label = new QLabel(DialogDeleteChoose);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 491, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        label->setFont(font);
        pushButton_number_1 = new QPushButton(DialogDeleteChoose);
        pushButton_number_1->setObjectName(QString::fromUtf8("pushButton_number_1"));
        pushButton_number_1->setGeometry(QRect(30, 130, 211, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        pushButton_number_1->setFont(font1);
        pushButton_number_2 = new QPushButton(DialogDeleteChoose);
        pushButton_number_2->setObjectName(QString::fromUtf8("pushButton_number_2"));
        pushButton_number_2->setGeometry(QRect(280, 130, 211, 31));
        pushButton_number_2->setFont(font);

        retranslateUi(DialogDeleteChoose);

        QMetaObject::connectSlotsByName(DialogDeleteChoose);
    } // setupUi

    void retranslateUi(QDialog *DialogDeleteChoose)
    {
        DialogDeleteChoose->setWindowTitle(QCoreApplication::translate("DialogDeleteChoose", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogDeleteChoose", "TextLabel", nullptr));
        pushButton_number_1->setText(QCoreApplication::translate("DialogDeleteChoose", "PushButton", nullptr));
        pushButton_number_2->setText(QCoreApplication::translate("DialogDeleteChoose", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogDeleteChoose: public Ui_DialogDeleteChoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGDELETECHOOSE_H
