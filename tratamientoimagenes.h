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
//    std::vector<float>executionTime;

private:
    Ui::tratamientoImagenes *ui;
//    QStringList imagenes;
//    void mostrarImagenes();
//    std::vector<QLabel*> labels;

private slots:
//    void abrir_imagen();
//    void guardar_imagen();
//    void guardarComo_imagen();
//    void abrirDemo();
//    void algoritmo();
};

#endif // TRATAMIENTOIMAGENES_H
