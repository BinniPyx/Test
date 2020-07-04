#ifndef TEXTEDITCONTEXT_H
#define TEXTEDITCONTEXT_H

#include <QObject>
#include <QTextEdit>
#include <QMenu>
#include <QDebug>
#include <QContextMenuEvent>
class TextEditContext : public QTextEdit
{
    Q_OBJECT
public:
    TextEditContext();
private:
    QMenu* menu;
protected:
    void contextMenuEvent(QContextMenuEvent* event) override;
private slots:
    void slotCopyFont();
    void setFont(const QString& str);


};

#endif // TEXTEDITCONTEXT_H
