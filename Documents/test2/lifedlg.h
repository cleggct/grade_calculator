#ifndef LIFEDLG_H
#define LIFEDLG_H

#include <QMainWindow>

namespace Ui {
class lifedlg;
}

class lifedlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit lifedlg(QWidget *parent = nullptr);
    ~lifedlg();

private:
    Ui::lifedlg *ui;
};

#endif // LIFEDLG_H
