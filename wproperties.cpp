#include "wproperties.h"
#include "ui_wproperties.h"

WProperties::WProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WProperties)
{
    ui->setupUi(this);
}

WProperties::~WProperties()
{
    delete ui;
}
