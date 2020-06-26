#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QTranslator>
#include <QEvent>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QMdiArea>
#include <QPlainTextEdit>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QAction* action;
    QAction* property;
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QMenu* m_open=nullptr;
    QMenu* mProper=nullptr;
    QMenu* subMenu=nullptr;
    QMdiArea* mdiAre= nullptr;
    QPlainTextEdit* plainTextEdit=nullptr;

protected:
     void changeEvent(QEvent* event) override;

private slots:

    void saveFile();
    void openFileRO();
    void openFileRW();
    void on_comboBox_2_currentTextChanged(const QString &arg1);
    void on_pushButton_clicked();
    void on_comboBox_editTextChanged(const QString &arg1);
    void changeThem();
    void on_pushButton_2_clicked();
    void on_toolButton_clicked();
    void on_comboBox_3_currentTextChanged(const QString &arg1);
};
#endif // MAINWINDOW_H
