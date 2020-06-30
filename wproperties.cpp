#include "wproperties.h"
#include "ui_wproperties.h"
#include <QGridLayout>
#include <QMdiArea>
#include <QPlainTextEdit>
#include <QDebug>
#include <QPushButton>
#include <QToolButton>
#include <QIcon>
#include "mainwindow.h"
#include "main.cpp"
WProperties::WProperties(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WProperties)
{
    ui->setupUi(this);
ui->listWidget->addItem("Sreda");
ui->listWidget->addItem("Top");
ui->listWidget->currentItem();

connect(this,&WProperties::signalSetPage1, &WProperties::slotSetPage1);
connect(this,&WProperties::signalSetPage2, &WProperties::slotSetPage2);



}

WProperties::~WProperties()
{
    delete ui;
}

void WProperties::mousePressEvent(QMouseEvent *event)
{
    QListWidgetItem* item=ui->listWidget->currentItem();
    QString a=item->text();
if(event->button()==Qt::MouseButton::LeftButton && a=="Sreda") {
    emit signalSetPage1();
}
else if(event->button()==Qt::MouseButton::LeftButton && a=="Top"){
    emit signalSetPage2();
}

}

void WProperties::slotSetPage1(){
    qDebug()<<"1";
    ui->stackedWidget_2->setCurrentIndex(0);
}

void WProperties::slotSetPage2(){
    qDebug()<<"2";
    ui->stackedWidget_2->setCurrentIndex(1);

}

void WProperties::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    MainWindow* mw=new MainWindow;

    if(arg1=="Eng"){

     mw->m_open->setTitle("Open");
     mw->subMenu->setTitle("Theme");
     mw->mProper->setTitle("Settings");

    }
    else if(arg1=="Rus"){
     mw->m_open->setTitle("Открыть");
     mw->subMenu->setTitle("Тема");
     mw->mProper->setTitle("Настройки");
    }
    mw->update();
}
