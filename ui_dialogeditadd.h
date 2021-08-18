/********************************************************************************
** Form generated from reading UI file 'dialogeditadd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGEDITADD_H
#define UI_DIALOGEDITADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogEditAdd
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DialogEditAdd)
    {
        if (DialogEditAdd->objectName().isEmpty())
            DialogEditAdd->setObjectName(QString::fromUtf8("DialogEditAdd"));
        DialogEditAdd->resize(480, 195);
        buttonBox = new QDialogButtonBox(DialogEditAdd);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogEditAdd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 431, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        label->setFont(font);
        lineEdit = new QLineEdit(DialogEditAdd);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 80, 421, 31));
        lineEdit->setFont(font);

        retranslateUi(DialogEditAdd);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogEditAdd, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogEditAdd, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogEditAdd);
    } // setupUi

    void retranslateUi(QDialog *DialogEditAdd)
    {
        DialogEditAdd->setWindowTitle(QCoreApplication::translate("DialogEditAdd", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogEditAdd", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogEditAdd: public Ui_DialogEditAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGEDITADD_H
