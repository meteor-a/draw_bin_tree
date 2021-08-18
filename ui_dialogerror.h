/********************************************************************************
** Form generated from reading UI file 'dialogerror.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGERROR_H
#define UI_DIALOGERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DialogError
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *DialogError)
    {
        if (DialogError->objectName().isEmpty())
            DialogError->setObjectName(QString::fromUtf8("DialogError"));
        DialogError->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogError);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogError);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 351, 201));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        label->setFont(font);

        retranslateUi(DialogError);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogError, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogError, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogError);
    } // setupUi

    void retranslateUi(QDialog *DialogError)
    {
        DialogError->setWindowTitle(QCoreApplication::translate("DialogError", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogError", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogError: public Ui_DialogError {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGERROR_H
