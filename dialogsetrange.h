#ifndef DIALOGSETRANGE_H
#define DIALOGSETRANGE_H

#include <QDialog>

namespace Ui {
class DialogSetRange;
}

class DialogSetRange : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetRange( QWidget *parent = nullptr);
    ~DialogSetRange();
    QString getMinNumber();
    QString getMaxNumber();

private:
    Ui::DialogSetRange *ui;
};

#endif // DIALOGSETRANGE_H
