/********************************************************************************
** Form generated from reading UI file 'dialogsetrange.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETRANGE_H
#define UI_DIALOGSETRANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogSetRange
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *DialogSetRange)
    {
        if (DialogSetRange->objectName().isEmpty())
            DialogSetRange->setObjectName(QString::fromUtf8("DialogSetRange"));
        DialogSetRange->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogSetRange);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogSetRange);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 321, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        label->setFont(font);
        lineEdit = new QLineEdit(DialogSetRange);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 70, 341, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(12);
        lineEdit->setFont(font1);
        label_2 = new QLabel(DialogSetRange);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 331, 41));
        label_2->setFont(font);
        lineEdit_2 = new QLineEdit(DialogSetRange);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 180, 341, 31));
        lineEdit_2->setFont(font1);

        retranslateUi(DialogSetRange);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSetRange, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSetRange, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSetRange);
    } // setupUi

    void retranslateUi(QDialog *DialogSetRange)
    {
        DialogSetRange->setWindowTitle(QCoreApplication::translate("DialogSetRange", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogSetRange", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSetRange", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetRange: public Ui_DialogSetRange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETRANGE_H
