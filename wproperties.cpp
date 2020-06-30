#include "wproperties.h"
#include "ui_wproperties.h"
#include <QGridLayout>
#include <QMdiArea>
#include <QPlainTextEdit>
#include <QDebug>
#include <QPushButton>
#include <QToolButton>
#include <QIcon>
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
