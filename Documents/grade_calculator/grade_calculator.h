#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QWidget>

namespace Ui {
class grade_calculator;
}

class grade_calculator : public QWidget
{
    Q_OBJECT

public:
    explicit grade_calculator(QWidget *parent = nullptr);
    ~grade_calculator();

private:
    Ui::grade_calculator *ui;
};

#endif // GRADE_CALCULATOR_H
