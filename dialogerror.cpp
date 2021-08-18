#include "dialogerror.h"
#include "ui_dialogerror.h"

DialogError::DialogError(int Num_err, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogError)
{
    ui->setupUi(this);
    ui->label->setWordWrap(true);
    inizialize_map();
    SetTextError(Num_err);
}

DialogError::~DialogError()
{
    delete ui;
    NUM_OF_ERR.clear();
    TEXT_ERROR.clear();
    ERROR_AND_NUMBER.clear();
}

void DialogError::inizialize_map() {
    for (int ii = 0; ii < NUM_OF_ERR.size(); ++ii) {
        ERROR_AND_NUMBER.insert(std::pair<int, QString>(NUM_OF_ERR[ii], TEXT_ERROR[ii]));
    }
}

void DialogError::SetTextError(int error) {
    ui->label->setText(ERROR_AND_NUMBER[error]);
}
