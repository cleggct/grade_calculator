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

signals:
    void compute_overall(); //tells us when to compute the score

public slots:
    void update_overall(); //update the score
    void hw1SliderChanged(int); //if the slider moves, change the number in the corresponding box
    void hw1BoxChanged(double); //if the number in the box changes, move the slider
    void hw2SliderChanged(int);
    void hw2BoxChanged(double);
    void hw3SliderChanged(int);
    void hw3BoxChanged(double);
    void hw4SliderChanged(int);
    void hw4BoxChanged(double);
    void hw5SliderChanged(int);
    void hw5BoxChanged(double);
    void hw6SliderChanged(int);
    void hw6BoxChanged(double);
    void hw7SliderChanged(int);
    void hw7BoxChanged(double);
    void hw8SliderChanged(int);
    void hw8BoxChanged(double);
    void midterm1SliderChanged(int);
    void midterm1BoxChanged(double);
    void midterm2SliderChanged(int);
    void midterm2BoxChanged(double);
    void finalSliderChanged(int);
    void finalBoxChanged(double);
    //slot for the radio buttons
    void schemaChanged(bool);
    //slot for changing class
    void courseChanged(int);


private:
    Ui::grade_calculator *ui;
    bool scheme; //T for A, F for B
    double scores [11]; //homework and test scores
};

#endif // GRADE_CALCULATOR_H
