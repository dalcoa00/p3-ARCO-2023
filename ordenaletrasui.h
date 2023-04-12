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
    bool static compareChars(char a, char b);
    bool static isUnwantedChar(char c);
    void execAlgorithm();

private slots:
    void on_execAlgoritmo_clicked();
    void on_reset_clicked();

private:
    Ui::ordenaletrasui *ui;
};

#endif // ORDENALETRASUI_H
