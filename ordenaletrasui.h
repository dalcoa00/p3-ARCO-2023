#ifndef ORDENALETRASUI_H
#define ORDENALETRASUI_H

#include <QDialog>

namespace Ui {
class ordenaletrasui;
}

class ordenaletrasui : public QDialog
{
    Q_OBJECT

public:
    explicit ordenaletrasui(QWidget *parent = nullptr);
    ~ordenaletrasui();

private:
    Ui::ordenaletrasui *ui;
};

#endif // ORDENALETRASUI_H
