#include "ordenaletrasui.h"
#include "ui_ordenaletrasui.h"

ordenaletrasui::ordenaletrasui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordenaletrasui)
{
    ui->setupUi(this);
}

ordenaletrasui::~ordenaletrasui()
{
    delete ui;
}
