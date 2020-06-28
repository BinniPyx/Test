#include "wproperties.h"
#include "ui_wproperties.h"
#include <QGridLayout>
#include <QMdiArea>
#include <QPlainTextEdit>
#include <QDebug>
WProperties::WProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WProperties)
{
    ui->setupUi(this);

    QGridLayout* gridLayout=new QGridLayout;
         this->setLayout(gridLayout);
    QMdiArea* mdiAreaLeft=new QMdiArea;
    QMdiArea* mdiAreaCentral=new QMdiArea;
    gridLayout->setRowMinimumHeight(1,1);
    gridLayout->setColumnMinimumWidth(10,10);
    gridLayout->addWidget(mdiAreaLeft,0,0,1,1);
    int width=mdiAreaLeft->width();
    mdiAreaCentral->setMinimumWidth(width*1.3);
    gridLayout->addWidget(mdiAreaCentral);
    QPlainTextEdit* pl=new QPlainTextEdit;
    mdiAreaCentral->addSubWindow(pl);



}

WProperties::~WProperties()
{
    delete ui;
}
