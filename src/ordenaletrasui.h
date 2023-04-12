#ifndef ORDENALETRASUI_H
#define ORDENALETRASUI_H

#include <QDialog>

#include <iostream>
#include <ostream>
#include <fstream>
#include <QFileDialog>

namespace Ui {
class ordenaletrasui;
}

class ordenaletrasui : public QDialog
{
    Q_OBJECT

public:
    int contador = 1;
    explicit ordenaletrasui(QWidget *parent = nullptr);
    ~ordenaletrasui();
    bool static compareChars(char a, char b);
    bool static isUnwantedChar(char c);
    void execAlgorithm();

private slots:
    void on_execAlgoritmo_clicked();
    void on_reset_clicked();
    void on_selecArchivo_clicked();

private:
    Ui::ordenaletrasui *ui;
    std::ifstream inputFile;
    std::ofstream outputFile;
    QString fileName = NULL;
    std::string fileNameStr;
    std::string outputFileNameStr;
    std::string inputText;


};

#endif // ORDENALETRASUI_H
