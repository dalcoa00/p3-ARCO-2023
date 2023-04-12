#include "ordenaletrasui.h"
#include "ui_ordenaletrasui.h"
//#include <iostream>
//#include <ostream>
//#include <fstream>
//#include <QFileDialog>

ordenaletrasui::ordenaletrasui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordenaletrasui)
{
    ui->setupUi(this);

    ui->tiempo1->setReadOnly(true);
    ui->tiempo2->setReadOnly(true);
    ui->tiempo3->setReadOnly(true);
    ui->tiempo4->setReadOnly(true);
    ui->tiempo5->setReadOnly(true);
    ui->tiempoMedio->setReadOnly(true);
}

ordenaletrasui::~ordenaletrasui()
{
    delete ui;
}

// Función para ordenar los caracteres en base a mayúsculas y minúsculas, y números al final
bool ordenaletrasui::compareChars(char a, char b) {
    if (std::tolower(a) == std::tolower(b)) {
        return a < b;
    }
    else if (std::isdigit(a) && std::isalpha(b)) {
        return false;
    }
    else if (std::isalpha(a) && std::isdigit(b)) {
        return true;
    }
    else {
        return std::tolower(a) < std::tolower(b);
    }
}

// Función para eliminar caracteres no deseados
bool ordenaletrasui::isUnwantedChar(char c) {
    return std::isspace(c) || std::ispunct(c);
}

void ordenaletrasui::execAlgorithm() {
//    std::ifstream inputFile;
//    std::ofstream outputFile;
    const int numExecutions = 5; // Número de ejecuciones
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Escoger archivo"), "", tr("Archivos de Texto (*.txt);;Todos los archivos (*.*)"));
//    std::string fileNameStr = fileName.toStdString();
//    inputFile.open(fileNameStr);
//    std::string outputFileNameStr = "output.txt"; // Nombre del archivo de salida
//    outputFile.open(outputFileNameStr);

//    if (!inputFile.is_open()) {
//        std::cerr << "Error: no se pudo abrir el archivo de entrada." << std::endl;
//        return;
//    }

//    if (!outputFile.is_open()) {
//        std::cerr << "Error: no se pudo abrir el archivo de salida." << std::endl;
//        return;
//    }

//    std::string inputText;
//    std::getline(inputFile, inputText);

    // Eliminar caracteres no deseados del texto de entrada
    inputText.erase(std::remove_if(inputText.begin(), inputText.end(), isUnwantedChar), inputText.end());

    // Medir el tiempo de ejecución
    auto startTime = std::chrono::steady_clock::now();

    // Realizar varias ejecuciones
    for (int i = 0; i < numExecutions; ++i) {
        auto startPartialTime = std::chrono::steady_clock::now();
        // Ordenar los caracteres en base a mayúsculas y minúsculas, y números al final
        std::sort(inputText.begin(), inputText.end(), compareChars);

        outputFile << "Intento numero: " << i + 1 << "\n";

        // Insertar un salto de línea entre caracteres nuevos
        std::string outputText;
        char prevChar = '\0';
        for (char c : inputText) {
            if (c != prevChar) {
                outputText += '\n';
            }
            outputText += c;
            prevChar = c;
        }

        // Escribir el resultado en el archivo de salida
        outputFile << outputText << std::endl;
        outputFile << "Fin del intento numero " << i + 1 << "\n\n\n\n\n\n";
        auto endPartialTime = std::chrono::steady_clock::now();
        auto elapsedPartialTime = std::chrono::duration_cast<std::chrono::milliseconds>(endPartialTime - startPartialTime).count();

        switch(i)
        {
            case 0:
                ui->tiempo1->setText(QString::number(elapsedPartialTime));
                outputFile.clear();
            break;
            case 1:
                ui->tiempo2->setText(QString::number(elapsedPartialTime));
                outputFile.clear();
            break;
            case 2:
                ui->tiempo3->setText(QString::number(elapsedPartialTime));
                outputFile.clear();
            break;
            case 3:
                ui->tiempo4->setText(QString::number(elapsedPartialTime));
                outputFile.clear();
            break;
            case 4:
                ui->tiempo5->setText(QString::number(elapsedPartialTime));
            break;
        }
    }

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    ui->tiempoMedio->setText(QString::number(elapsedTime / numExecutions));

    inputFile.close();
    outputFile.close();

    return;
}

void ordenaletrasui::on_execAlgoritmo_clicked()
{
        execAlgorithm();
}

void ordenaletrasui::on_reset_clicked()
{
    ui->tiempo1->clear();
    ui->tiempo2->clear();
    ui->tiempo3->clear();
    ui->tiempo4->clear();
    ui->tiempo5->clear();
    ui->tiempoMedio->clear();
}

void ordenaletrasui::on_selecArchivo_clicked()
{

    fileName = QFileDialog::getOpenFileName(this, tr("Escoger archivo"), "", tr("Archivos de Texto (*.txt);;Todos los archivos (*.*)"));
    fileNameStr = fileName.toStdString();
    inputFile.open(fileNameStr);
    outputFileNameStr = "output.txt"; // Nombre del archivo de salida
    outputFile.open(outputFileNameStr);

    if (!inputFile.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo de entrada." << std::endl;
        return;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo de salida." << std::endl;
        return;
    }

    std::getline(inputFile, inputText);
}

