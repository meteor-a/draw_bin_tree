#include "dialogsetrange.h"
#include "ui_dialogsetrange.h"

DialogSetRange::DialogSetRange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSetRange)
{
    ui->setupUi(this);
    ui->label->setWordWrap(true);
    ui->label_2->setWordWrap(true);
    ui->label->setText(u8"”кажите минимальное значение элементов:");
    ui->label_2->setText(u8"”кажите максимальное значение элементов: ");
}

DialogSetRange::~DialogSetRange()
{
    delete ui;
}

QString DialogSetRange::getMinNumber() {
    return ui->lineEdit->text();
}

QString DialogSetRange::getMaxNumber() {
    return ui->lineEdit_2->text();
}
