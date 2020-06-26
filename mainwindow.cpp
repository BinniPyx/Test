#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMenu>
#include <QFileDialog>
#include <QFontDialog>
#include <QRadioButton>
#include <QTranslator>
#include <QApplication>
#include <QToolBar>
#include <QDockWidget>
#include <QMenuBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plainTextEdit= new QPlainTextEdit();
/////////////////////////////////////////////////////////////////Menu bar/Tool bar position//////////////////////////////////////////////


QIcon ic= QIcon(":/print.png");

QMenuBar* mb=new QMenuBar(this);
mb->addAction("sdssssssssssssssssssssssssssssssssssssssssssssssssssssssssssf");
ui->toolButton->setIcon(ic);
QToolBar* mbr=new QToolBar(this);
mbr->addWidget(ui->toolButton);


m_open=new QMenu(tr("Открыть"));
m_open->addAction(tr("Чтение и запись"),this,SLOT(openFileRO()));
m_open->addAction(tr("Только чтение"), this, SLOT(openFileRW()));
ui->menubar->addMenu(m_open);

ui->menubar->addAction("Сохранить",this, SLOT(saveFile()));

mProper=new QMenu(tr("Настройки"));

subMenu= new QMenu(tr("Тема"));
action= subMenu->addAction(tr("Темная"));
action->setCheckable(true);
action=mProper->addAction("Параметры");
//mProper->addSeparator();


mProper->addMenu(subMenu);
ui->menubar->addMenu(mProper);

ui->comboBox->setEditable(true);
ui->comboBox->addItem("Chilanka");
ui->comboBox->addItem("Ani");
ui->comboBox_2->setMaxCount(5);////////нужно учзнать как выводить сразу не все элменты в комбобокс чтоб не использовать эту строчку

int i=8;
while(i<96){
ui->comboBox_2->addItem(QString::number(i));
i=i+2;
}


////////////////////////////////////////////////////////Central position/////////////////////////////////////////////////////////////////
    mdiAre=new QMdiArea(this);

QGridLayout* gridLayout =new QGridLayout(this);
ui->centralwidget->setLayout(gridLayout);

gridLayout->addWidget(mdiAre,1,0,10,1);
QPlainTextEdit *op=new QPlainTextEdit();
mdiAre->addSubWindow(plainTextEdit);
mdiAre->setViewMode(QMdiArea::TabbedView);
connect(action,SIGNAL(changed()),SLOT(changeThem()));





}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{

}

void MainWindow::saveFile()
{
    QString filename= QFileDialog::getSaveFileName(this,"Заголовок окна",QDir::current().path());
    if(filename.length()>0){
        QString ext=QString(&(filename.data()[filename.length()-4]));
        if(ext==".txt")
        {
            QFile file(filename);
            if(file.open(QFile::WriteOnly|QFile::NewOnly))
            {
                QTextStream stream(&file);
                stream<<plainTextEdit->toPlainText();
                file.close();
            }
        }
    }
}

void MainWindow::openFileRW()
{
    QString filename= QFileDialog::getOpenFileName(this);
    QFile file(filename);

    if(file.open(QIODevice::ReadWrite))
    {
        QByteArray byteArray=file.readAll();

        QPlainTextEdit* plainTE=new QPlainTextEdit();
         plainTE->setPlainText(byteArray.data());
        mdiAre->addSubWindow(plainTE);


    }

}

void MainWindow::openFileRO()
{

    QString filename= QFileDialog::getOpenFileName(this);
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray byteArray=file.readAll();
        QPlainTextEdit* plainTT=new QPlainTextEdit();
        plainTT->setPlainText(tr(byteArray.data()));
        mdiAre->addSubWindow(plainTT);

    }

}


void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{

    plainTextEdit->setStyleSheet("font-size:"+arg1+"px;");

}

void MainWindow::on_pushButton_clicked()
{
   // translate.load(":/translation/QtLanguage.qm");
  //  qApp->installTranslator(&translate);
}

void MainWindow::on_comboBox_editTextChanged(const QString &arg1)
{
    QFont font=QFont(arg1);
    plainTextEdit->setFont(font);
}

void MainWindow::changeThem()
{
   if(action->isChecked()==true){
       this->setStyleSheet("background-image: url(:/45.png)");
       plainTextEdit->setStyleSheet("color: white");
   }
   if(action->isChecked()==false){
       this->setStyleSheet("");
       plainTextEdit->setStyleSheet("");
   }

}


void MainWindow::on_pushButton_2_clicked()
{
    QTranslator tr;
    tr.load(":/translation/QtLanguage1.qm");
    qApp->installTranslator(&tr);
}

void MainWindow::on_toolButton_clicked()
{
     QPrinter printer;
     QPrintDialog dlg(&printer,this);
     dlg.setWindowTitle("Print");
     if(dlg.exec()!=QDialog::Accepted){
         return;
     }
     QString str=plainTextEdit->toPlainText();
     QChar *list=str.data();
       QStringList strlst;
     int line=0, cursor=0;
     for(bool getst=true;getst;){
         int index=str.indexOf("/n",cursor);
         QString s="";
         if(index==-1){
             getst=false;
             s.append(&list[cursor],str.length()-cursor);
         }
         else{
              s.append(&list[cursor], index - cursor);
                     cursor = index + 1;
                     strlst << s;
         }
     }


     QPainter painter;
        painter.begin(&printer);
        int w = painter.window().width();
        int h = painter.window().height();
        int amount = strlst.count();
        QFont font = painter.font();
        QFontMetrics fmetrics(font);
        for (int i = 0; i < amount; i++)
        {
            QPointF pf;
            pf.setX(10);
            pf.setY(line);
            painter.drawText(pf, strlst.at(i));
            line += fmetrics.height();
            if (h - line <= fmetrics.height())
            {
                printer.newPage();
                line = 0;
            }

        }
        painter.end();




}

void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{


    if(arg1=="Eng"){

     m_open->setTitle("Open");
     subMenu->setTitle("Theme");
     mProper->setTitle("Settings");

    }
    else if(arg1=="Rus"){
     m_open->setTitle("Открыть");
     subMenu->setTitle("Тема");
     mProper->setTitle("Настройки");
    }
}
