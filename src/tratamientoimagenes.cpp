#include "tratamientoimagenes.h"
#include "ui_tratamientoimagenes.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <string>

using namespace std;

tratamientoImagenes::tratamientoImagenes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tratamientoImagenes)
{
    ui->setupUi(this);

//    QMenu* menuAbrir = ui->menubar->addMenu("Archivo(s)");

//    menuAbrir->addAction("Abrir...", this , SLOT(abrir_imagen()));
//    menuAbrir->addAction("Imagenes Demo", this , SLOT(abrirDemo()));
//    menuAbrir->addAction("Guardar...", this , SLOT(guardar_imagen()));
//    menuAbrir->addAction("Guardar como...", this , SLOT(guardarComo_imagen()));

//    QMenu* menuEditar = ui->menubar->addMenu("Editar");

//    QMenu* menuFiltros = menuEditar->addMenu("Filtros...");

//    menuFiltros->addAction("Algoritmo", this , SLOT(algoritmo()));

}

tratamientoImagenes::~tratamientoImagenes()
{
    delete ui;
}

//void tratamientoImagenes::abrir_imagen(){

//    imagenes = QFileDialog::getOpenFileNames(this, "Escoge una o varias imagenes", "/home", "Images (*.jpg *.xpm *.png *.jpeg)");

//    mostrarImagenes();

//}

//void tratamientoImagenes::guardar_imagen(){
//    QMessageBox::information(this,"Guardar","Tus imagenes seran guaradas");
//    for (int i=0; i< imagenes.length(); i++){
//        QImage image=labels[i]->pixmap().toImage();
//        image.save(imagenes[i]);
//    }


//}

//void tratamientoImagenes::guardarComo_imagen(){



//    for(int i =0;i<imagenes.length();i++){
//        QString imagePath = QFileDialog::getSaveFileName(this, tr("Guardar archivo"), "", tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
//        QImage image=labels[i]->pixmap().toImage();

//        image.save(imagePath);
//    }

//}

//void tratamientoImagenes::mostrarImagenes(){

//    for(int i = 0; i < imagenes.length(); i++){

//        QLabel* label = new QLabel;

//        label->setPixmap(QPixmap::fromImage(QImage(imagenes.at(i))));

//        labels.push_back(label);

//        ui->gridLayout->addWidget(label);

//    }

//}

//void tratamientoImagenes::abrirDemo(){

//    imagenes = QStringList();

//    imagenes.push_back(":/demo/imagenes/bicicleta.png");
//    imagenes.push_back(":/demo/imagenes/avion.png");
//    imagenes.push_back(":/demo/imagenes/triciclo.png");
//    imagenes.push_back(":/demo/imagenes/tren.png");
//    imagenes.push_back(":/demo/imagenes/coche.png");
//    imagenes.push_back(":/demo/imagenes/cochedeportivo.png");
//    imagenes.push_back(":/demo/imagenes/motocicleta.png");

//    mostrarImagenes();

//}


//void tratamientoImagenes::algoritmo(){
//    // Abre la imagen original
//    ifstream imagenes("imagen.bmp", ios::binary);

//    // Lee la cabecera de la imagen
//    char cabecera[54];
//    imagenes.read(cabecera, 54);

//    // Lee los datos de la imagen
//    int ancho = *(int*)&cabecera[18];
//    int alto = *(int*)&cabecera[22];
//    int tamano_datos = ancho * alto * 3;
//    char* datos = new char[tamano_datos];
//    imagenes.read(datos, tamano_datos);

//    // Invierte la imagen
//    auto start = chrono::high_resolution_clock::now();
//    for (int i = 0; i < tamano_datos; i += 3) {
//        datos[i] = 255 - datos[i]; // Canal Rojo
//        datos[i+1] = 255 - datos[i+1]; // Canal Verde
//        datos[i+2] = 255 - datos[i+2]; // Canal Azul
//    }

//    // Convierte la imagen invertida a blanco y negro
//    for (int i = 0; i < tamano_datos; i += 3) {
//        // Calcula la luminosidad del píxel
//        float r = datos[i];
//        float g = datos[i+1];
//        float b = datos[i+2];
//        float luminosidad = 0.21*r + 0.72*g + 0.07*b;

//        // Asigna la misma luminosidad a los tres canales de color
//        datos[i] = datos[i+1] = datos[i+2] = (char)luminosidad;
//    }
//    auto stop = chrono::high_resolution_clock::now();

//    // Calcula el tiempo de ejecución total
//    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//    cout << "Tiempo de ejecución total: " << duration.count() << " microsegundos" << endl;

//    // Guarda la imagen invertida
//    ofstream imagen_invertida("imagen_invertida.bmp", ios::binary);
//    imagen_invertida.write(cabecera, 54);
//    imagen_invertida.write(datos, tamano_datos);

//    // Guarda la imagen en blanco y negro
//    ofstream imagen_bn("imagen_bn.bmp", ios::binary);
//    imagen_bn.write(cabecera, 54);
//    imagen_bn.write(datos, tamano_datos);

//    // Cierra los archivos
//    imagenes.close();
//    imagen_invertida.close();
//    imagen_bn.close();

//}




