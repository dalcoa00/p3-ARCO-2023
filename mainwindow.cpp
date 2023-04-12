#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ordenaletrasui.h"
#include "tratamientoimagenes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Cuando se pulsa el botón en la ventana principal se abre la ventana para el algoritmo de ordenación de letras*/
void MainWindow::on_inicioTexto_clicked()
{
    ordenaletrasui ordenaLetras;

    ordenaLetras.setModal(true);
    ordenaLetras.exec();
}

/*Cuando se pulsa el botón en la ventana principal se abre la ventana para el algoritmo de tratamiento de imágenes*/
void MainWindow::on_inicioImagen_clicked()
{
    tratamientoImagenes imagenesUI;

    imagenesUI.setModal(true);
    imagenesUI.exec();
}

