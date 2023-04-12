#include "tratamientoimagenes.h"
#include "ui_tratamientoimagenes.h"

using namespace std;

int contador = 1;

QString directorioEntrada;
QString directorioSalida;

tratamientoImagenes::tratamientoImagenes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tratamientoImagenes)
{
    ui->setupUi(this);

    ui->time1->setReadOnly(true);
    ui->time2->setReadOnly(true);
    ui->time3->setReadOnly(true);
    ui->time4->setReadOnly(true);
    ui->time5->setReadOnly(true);
    ui->timeMedio->setReadOnly(true);

    // Conectar el botón selecDirectorio con la función correspondiente
    connect(ui->selecDirectorio, &QPushButton::clicked, this, &tratamientoImagenes::seleccionarDirectorio);
}

tratamientoImagenes::~tratamientoImagenes()
{
    delete ui;
}

void tratamientoImagenes::seleccionarDirectorio()
{
    // Abrir un cuadro de diálogo para seleccionar el directorio de entrada
    directorioEntrada = QFileDialog::getExistingDirectory(this, "Seleccionar directorio de entrada");

    // Abrir un cuadro de diálogo para seleccionar el directorio de salida
    directorioSalida = QFileDialog::getExistingDirectory(this, "Seleccionar directorio de salida");
}

void tratamientoImagenes::ejecutarAlgoritmo(const QString &directorioEntrada, const QString &directorioSalida)
{
    QDir dirEntrada(directorioEntrada); // Directorio de entrada
    QDir dirSalida(directorioSalida);   // Directorio de salida

    QStringList listaArchivos = dirEntrada.entryList(QDir::Files); // Lista de archivos en el directorio de entrada

    // Calcular tiempo de ejecución
    QTime tiempoInicio = QTime::currentTime(); // Tiempo de inicio
    for (int i = 0; i < listaArchivos.size(); ++i) {
        QString archivoEntrada = listaArchivos.at(i);
        QString rutaAbsolutaEntrada = dirEntrada.absoluteFilePath(archivoEntrada); // Obtener la ruta absoluta del archivo de entrada
        QImage imagenEntrada(rutaAbsolutaEntrada);
        if (!imagenEntrada.isNull()) {
            QImage imagenModificada = aplicarAlgoritmo(imagenEntrada); // Aplicar el algoritmo a la imagen
            QString archivoSalida = dirSalida.absoluteFilePath(archivoEntrada);
            if (imagenModificada.save(archivoSalida)) {
                qDebug() << "Imagen modificada guardada en:" << archivoSalida;
            } else {
                qDebug() << "Error al guardar la imagen modificada en:" << archivoSalida;
            }
        } else {
            qDebug() << "Error al cargar la imagen de entrada:" << archivoEntrada;
        }
    }
    QTime tiempoFin = QTime::currentTime(); // Tiempo de fin

    long long tiempoEjecucion = tiempoInicio.msecsTo(tiempoFin); // Tiempo de ejecución en milisegundos

    escribirTiempoEjecucion(tiempoEjecucion); // Escribir tiempo de ejecución en los cuadros de texto
}

void tratamientoImagenes::escribirTiempoEjecucion(long long tiempoEjecucion)
{
    // Escribir el tiempo de ejecución en el cuadro de texto correspondiente
    switch (contador) {
    case 1:
        ui->time1->setText(QString::number(tiempoEjecucion));
        break;
    case 2:
        ui->time2->setText(QString::number(tiempoEjecucion));
        break;
    case 3:
        ui->time3->setText(QString::number(tiempoEjecucion));
        break;
    case 4:
        ui->time4->setText(QString::number(tiempoEjecucion));
        break;
    case 5:
        ui->time5->setText(QString::number(tiempoEjecucion));
        break;
    }

    // Calcular el tiempo medio de ejecución
    if (contador == 5) {
        long long tiempoMedio = (ui->time1->text().toLongLong() +
                                 ui->time2->text().toLongLong() +
                                 ui->time3->text().toLongLong() +
                                 ui->time4->text().toLongLong() +
                                 ui->time5->text().toLongLong()) / 5;
        ui->timeMedio->setText(QString::number(tiempoMedio));
        contador = 1; // Reiniciar el contador
    } else {
        contador++; // Incrementar el contador
    }
}

QImage tratamientoImagenes::aplicarAlgoritmo(const QImage &imagen)
{
    // Invertir la imagen
    QImage imagenInvertida = imagen.mirrored(true, false);

    // Convertir la imagen a blanco y negro
    QImage imagenBlancoNegro = imagenInvertida.convertToFormat(QImage::Format_Grayscale8);

    return imagenBlancoNegro;
}

void tratamientoImagenes::on_execImagenes_clicked()
{
    QMessageBox message;

    if(directorioEntrada.isNull() || directorioSalida.isNull()){
        message.setText("Tienes que seleccionar directorios. En caso de haber clickado RESET, vuelva a seleccionar.");
        message.exec();
        return;
    }

    // Verificar que ambos directorios han sido seleccionados
    if (!directorioEntrada.isEmpty() && !directorioSalida.isEmpty()) {
        // Ejecutar el algoritmo en las imágenes del directorio de entrada
        ejecutarAlgoritmo(directorioEntrada, directorioSalida);
    }
}

void tratamientoImagenes::on_resetImagenes_clicked()
{
    ui->time1->clear();
    ui->time2->clear();
    ui->time3->clear();
    ui->time4->clear();
    ui->time5->clear();
    ui->timeMedio->clear();

    contador = 1;

    directorioEntrada = NULL;
    directorioSalida = NULL;
}
