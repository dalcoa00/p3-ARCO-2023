#ifndef TRATAMIENTOIMAGENES_H
#define TRATAMIENTOIMAGENES_H

#include <QDialog>
#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QLabel>
#include <QInputDialog>
#include <QMessageBox>
#include <QTime>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class tratamientoImagenes;
}
QT_END_NAMESPACE

class tratamientoImagenes : public QDialog
{
    Q_OBJECT

public:
    explicit tratamientoImagenes(QWidget *parent = nullptr);
    ~tratamientoImagenes();
    QString directorioEntrada, directorioSalida;
    std::vector<float>executionTime;
    void seleccionarDirectorio();
    void ejecutarAlgoritmo(const QString &directorioEntrada, const QString &directorioSalida);
    void escribirTiempoEjecucion(long long tiempoEjecucion);
    QImage aplicarAlgoritmo(const QImage &imagen);

private:
    Ui::tratamientoImagenes *ui;
    QStringList imagenes;
    std::vector<QLabel*> labels;

private slots:
    void on_execImagenes_clicked();
    void on_resetImagenes_clicked();
};

#endif // TRATAMIENTOIMAGENES_H
