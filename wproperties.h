#ifndef WPROPERTIES_H
#define WPROPERTIES_H
#include <QListWidget>
#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class WProperties;
}

class WProperties : public QWidget
{
    Q_OBJECT

public:
    explicit WProperties(QWidget *parent = nullptr);
    QListWidgetItem currentItem(QListWidgetItem *parent=nullptr);
    ~WProperties();
signals:
    void signalSetPage1();
    void signalSetPage2();
private:
    Ui::WProperties *ui;

protected:

    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void slotSetPage1();
    void slotSetPage2();
    void on_comboBox_3_currentTextChanged(const QString &arg1);
};

#endif // WPROPERTIES_H
