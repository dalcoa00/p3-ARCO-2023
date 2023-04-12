#include "tratamientoimagenes.h"
#include "ui_tratamientoimagenes.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <chrono>

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


