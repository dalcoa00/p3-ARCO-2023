#ifndef TRATAMIENTOIMAGENES_H
#define TRATAMIENTOIMAGENES_H

#include <QDialog>

namespace Ui {
class tratamientoImagenes;
}

class tratamientoImagenes : public QDialog
{
    Q_OBJECT

public:
    explicit tratamientoImagenes(QWidget *parent = nullptr);
    ~tratamientoImagenes();

private:
    Ui::tratamientoImagenes *ui;
};

#endif // TRATAMIENTOIMAGENES_H
