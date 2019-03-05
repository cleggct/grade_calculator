#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grade_calculator),
    scheme(true),
    scores()
{
    ui->setupUi(this);

    //set up the combo box
    ui->courseBox->addItem("Pic 10B. Intermediate Programming.");
    ui->courseBox->addItem("Pic 10C. Advanced Programming.");

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
    connect(ui->midterm1Box, SIGNAL(valueChanged(double)), this, SLOT(midterm1BoxChanged(double)));
    connect(ui->midterm1Slider, SIGNAL(valueChanged(int)), this, SLOT(midterm1SliderChanged(int)));
    connect(ui->midterm2Box, SIGNAL(valueChanged(double)), this, SLOT(midterm2BoxChanged(double)));
    connect(ui->midterm2Slider, SIGNAL(valueChanged(int)), this, SLOT(midterm2SliderChanged(int)));
    connect(ui->finalBox, SIGNAL(valueChanged(double)), this, SLOT(finalBoxChanged(double)));
    connect(ui->finalSlider, SIGNAL(valueChanged(int)), this, SLOT(finalSliderChanged(int)));

    //connect radio buttons
    connect(ui->schemaButtonA, SIGNAL(toggled(bool)), this, SLOT(schemaChanged(bool)));

    //connect compute_overall() signal to update_overall
    connect(this, SIGNAL(compute_overall()), this, SLOT(update_overall()));

    //connect combobox to the combobox slot
    connect(ui->courseBox, SIGNAL(activated(int)), this, SLOT(courseChanged(int)));
}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::update_overall(){

    //make sliders and boxes change according to score value
    ui->hw1Box->setValue(scores[0]);
    ui->hw1Slider->setValue((int)scores[0]);
    ui->hw2Box->setValue(scores[1]);
    ui->hw2Slider->setValue((int)scores[1]);
    ui->hw3Box->setValue(scores[2]);
    ui->hw3Slider->setValue((int)scores[2]);
    ui->hw4Box->setValue(scores[3]);
    ui->hw4Slider->setValue((int)scores[3]);
    ui->hw5Box->setValue(scores[4]);
    ui->hw5Slider->setValue((int)scores[4]);
    ui->hw6Box->setValue(scores[5]);
    ui->hw6Slider->setValue((int)scores[5]);
    ui->hw7Box->setValue(scores[6]);
    ui->hw7Slider->setValue((int)scores[6]);
    ui->hw8Box->setValue(scores[7]);
    ui->hw8Slider->setValue((int)scores[7]);
    ui->midterm1Box->setValue(scores[8]);
    ui->midterm1Slider->setValue((int)scores[8]);
    ui->midterm2Box->setValue(scores[9]);
    ui->midterm2Slider->setValue((int)scores[9]);
    ui->finalBox->setValue(scores[10]);
    ui->finalSlider->setValue((int)scores[10]);

    double score = 0;
    double hwavg = 0; //homework average
    for(size_t i = 0; i < 8; ++i){ //average the homework scores
        hwavg += scores[i];
    }
    hwavg /= 8;

    if(scheme){ //compute final score
        score = (0.25 * hwavg) + (0.2 * scores[8]) + (0.2 * scores[9]) + (0.35 * scores[10]);
    }
    else {
        double max = scores[8] > scores[9] ? scores[8] : scores[9]; //get highest midterm score
        score = (0.25 * hwavg) + (0.3 * max) + (0.44 * scores[10]);
    }

    ui->numberLabel->setText(QString::number(score)); //set score label to the computed score

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

void grade_calculator::midterm1SliderChanged(int val){
    scores[8] = (double) val;
    emit compute_overall();
}

void grade_calculator::midterm1BoxChanged(double val){
    scores[8] = val;
    emit compute_overall();
}

void grade_calculator::midterm2SliderChanged(int val){
    scores[9] = (double) val;
    emit compute_overall();
}

void grade_calculator::midterm2BoxChanged(double val){
    scores[9] = val;
    emit compute_overall();
}

void grade_calculator::finalSliderChanged(int val){
    scores[10] = (double) val;
    emit compute_overall();
}

void grade_calculator::finalBoxChanged(double val){
    scores[10] = val;
    emit compute_overall();
}

void grade_calculator::schemaChanged(bool val){
    scheme = val;
    emit compute_overall();
}

void grade_calculator::courseChanged(int index){
    for(size_t i = 0; i < 11; ++i){
        scores[i] = 0;
    }
    if(index == 0){
        ui->midterm1Label->setText("Midterm 1");
        ui->midterm2Label->setText("Midterm 2");
    }
    else if(index == 1){
        ui->midterm1Label->setText("Midterm");
        ui->midterm2Label->setText("Project");
    }
    emit compute_overall();
}
