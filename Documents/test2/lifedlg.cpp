#include "lifedlg.h"
#include "ui_lifedlg.h"

lifedlg::lifedlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lifedlg)
{
    ui->setupUi(this);
}

lifedlg::~lifedlg()
{
    delete ui;
}
