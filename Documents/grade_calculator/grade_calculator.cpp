#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grade_calculator),
    scheme(),
    scores()
{
    ui->setupUi(this);

    //connect the sliders and spinners
    connect(ui->hw1Box, SIGNAL(valueChanged(double)), this, SLOT(hw1BoxChanged(double)));
    connect(ui->hw1Slider, SIGNAL(valueChanged(int)), this, SLOT(hw1SliderChanged(int)));
    connect(ui->hw2Box, SIGNAL(valueChanged(double)), this, SLOT(hw2BoxChanged(double)));
    connect(ui->hw2Slider, SIGNAL(valueChanged(int)), this, SLOT(hw2SliderChanged(int)));
    connect(ui->hw3Box, SIGNAL(valueChanged(double)), this, SLOT(hw3BoxChanged(double)));
    connect(ui->hw3Slider, SIGNAL(valueChanged(int)), this, SLOT(hw3SliderChanged(int)));
    connect(ui->hw4Box, SIGNAL(valueChanged(double)), this, SLOT(hw4BoxChanged(double)));
    connect(ui->hw4Slider, SIGNAL(valueChanged(int)), this, SLOT(hw4SliderChanged(int)));
    connect(ui->hw5Box, SIGNAL(valueChanged(double)), this, SLOT(hw5BoxChanged(double)));
    connect(ui->hw5Slider, SIGNAL(valueChanged(int)), this, SLOT(hw5SliderChanged(int)));
    connect(ui->hw6Box, SIGNAL(valueChanged(double)), this, SLOT(hw6BoxChanged(double)));
    connect(ui->hw6Slider, SIGNAL(valueChanged(int)), this, SLOT(hw6SliderChanged(int)));
    connect(ui->hw7Box, SIGNAL(valueChanged(double)), this, SLOT(hw7BoxChanged(double)));
    connect(ui->hw7Slider, SIGNAL(valueChanged(int)), this, SLOT(hw7SliderChanged(int)));
    connect(ui->hw8Box, SIGNAL(valueChanged(double)), this, SLOT(hw8BoxChanged(double)));
    connect(ui->hw8Slider, SIGNAL(valueChanged(int)), this, SLOT(hw8SliderChanged(int)));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::update_overall(int unused){
    double score = static_cast<double>(unused);

    ui->numberLabel->setText(QString::number(score));

    return;
}

void grade_calculator::hw1SliderChanged(int val){
    scores[0] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw1BoxChanged(double val){
    scores[0] = val;
    emit compute_overall();
}

void grade_calculator::hw2SliderChanged(int val){
    scores[1] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw2BoxChanged(double val){
    scores[1] = val;
    emit compute_overall();
}

void grade_calculator::hw3SliderChanged(int val){
    scores[2] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw3BoxChanged(double val){
    scores[2] = val;
    emit compute_overall();
}

void grade_calculator::hw4SliderChanged(int val){
    scores[3] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw4BoxChanged(double val){
    scores[3] = val;
    emit compute_overall();
}

void grade_calculator::hw5SliderChanged(int val){
    scores[4] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw5BoxChanged(double val){
    scores[4] = val;
    emit compute_overall();
}

void grade_calculator::hw6SliderChanged(int val){
    scores[5] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw6BoxChanged(double val){
    scores[5] = val;
    emit compute_overall();
}

void grade_calculator::hw7SliderChanged(int val){
    scores[6] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw7BoxChanged(double val){
    scores[6] = val;
    emit compute_overall();
}

void grade_calculator::hw8SliderChanged(int val){
    scores[7] = (double) val;
    emit compute_overall();
}

void grade_calculator::hw8BoxChanged(double val){
    scores[7] = val;
    emit compute_overall();
}
