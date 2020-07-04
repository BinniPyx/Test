#include "texteditcontext.h"
#include <QTextBlock>
TextEditContext::TextEditContext()
{
    menu=createStandardContextMenu();
    QAction *copyFont=menu->addAction("CopyFont");
    connect(copyFont,SIGNAL(triggered()),this,SLOT(slotCopyFont()));
}

void TextEditContext::contextMenuEvent(QContextMenuEvent *event)
{


    menu->exec(event->globalPos());

}

void TextEditContext::slotCopyFont()
{

 QString str=this->textCursor().selectedText();
 //QFont font=str.font();
}

void TextEditContext::setFont(const QString& str)
{
      qDebug()<<str;
   // QFont font=QFont();
    this->setStyleSheet("font:"+str+";");;
}
