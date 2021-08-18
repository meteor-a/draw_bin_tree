#include "dialogeditadd.h"
#include "ui_dialogeditadd.h"

DialogEditAdd::DialogEditAdd(QString hint, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditAdd)
{
    ui->setupUi(this);
    HINT_TEXT = hint;
    SetHintText();
}

DialogEditAdd::DialogEditAdd(QString hint, QString old_num, QWidget* parent) :
    QDialog(parent),
    ui(new Ui::DialogEditAdd)
{
    ui->setupUi(this);
    HINT_TEXT = hint;
    Edit_number = old_num;
    SetHintText();
    setOldNumber();
}

DialogEditAdd::~DialogEditAdd()
{
    delete ui;
}

void DialogEditAdd::SetHintText() {
    ui->label->setText(HINT_TEXT);
}

QString DialogEditAdd::getNumber() {
    return ui->lineEdit->text();
}

void DialogEditAdd::setOldNumber() {
    ui->lineEdit->setText(Edit_number);
}
