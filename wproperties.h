#ifndef WPROPERTIES_H
#define WPROPERTIES_H

#include <QWidget>

namespace Ui {
class WProperties;
}

class WProperties : public QWidget
{
    Q_OBJECT

public:
    explicit WProperties(QWidget *parent = nullptr);
    ~WProperties();

private:
    Ui::WProperties *ui;
};

#endif // WPROPERTIES_H
