#ifndef DIALOGERROR_H
#define DIALOGERROR_H

#include <QDialog>
#include <map>

namespace Ui {
class DialogError;
}

class DialogError : public QDialog
{
    Q_OBJECT

public:
    explicit DialogError(int Num_err, QWidget *parent = nullptr);
    ~DialogError();

private:
    Ui::DialogError *ui;
    QString ERROR_RANGE_AND_NUM_OF_ELEMS = u8"���������� ��������� ������ ���� ������, ��� ���������� ����� ����� � ��������� ���������.";
    QString ERROR_INCORRECT_NUMBER = u8"��������� ������������ ����� ������ �����.";
    QString ERROR_NUMBER_OUT_OF_RANGE = u8"��������� ����� ������ ���������.";
    QString ERROR_DUBLICATE_NUMBER = u8"� �������� ��� ���������� ������� � ����� ���������.";
    std::vector<QString> TEXT_ERROR{ ERROR_RANGE_AND_NUM_OF_ELEMS , ERROR_INCORRECT_NUMBER, ERROR_NUMBER_OUT_OF_RANGE, 
        ERROR_DUBLICATE_NUMBER };
    std::vector<int> NUM_OF_ERR{ 1, 2, 3, 4 };
    std::map<int, QString> ERROR_AND_NUMBER;

    void inizialize_map();
    void SetTextError(int);
};

#endif // DIALOGERROR_H
