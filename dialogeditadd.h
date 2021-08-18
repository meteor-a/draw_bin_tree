#ifndef DIALOGEDITADD_H
#define DIALOGEDITADD_H

#include <QDialog>

namespace Ui {
class DialogEditAdd;
}

class DialogEditAdd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditAdd(QString hint, QWidget *parent = nullptr);
    explicit DialogEditAdd(QString hint, QString old_num, QWidget* parent = nullptr);
    ~DialogEditAdd();
    QString getNumber();
    

private:
    Ui::DialogEditAdd *ui;

    QString HINT_TEXT;
    QString Edit_number;

    void SetHintText();
    void setOldNumber();
};

#endif // DIALOGEDITADD_H
