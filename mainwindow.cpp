#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSerialPort"

QSerialPort port("COM2");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(pressed()),  this, SLOT(pressed()));
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(released()));

    if (!port.open(QIODevice::ReadWrite))
    {
        return;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pressed()
{
    port.setRequestToSend(true);
}

void MainWindow::released()
{
    port.setRequestToSend(false);
}
