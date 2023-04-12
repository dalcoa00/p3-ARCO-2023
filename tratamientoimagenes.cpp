#include "tratamientoimagenes.h"
#include "ui_tratamientoimagenes.h"

tratamientoImagenes::tratamientoImagenes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tratamientoImagenes)
{
    ui->setupUi(this);
}

tratamientoImagenes::~tratamientoImagenes()
{
    delete ui;
}
