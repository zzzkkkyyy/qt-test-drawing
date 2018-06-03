#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "paintarea.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PaintArea *pt_area = new PaintArea(0);
    pt_area->setSceneRect(QRectF(QPointF(0, 0), QSizeF(900, 750)));
    ui->paintarea->setScene(pt_area);
    ui->paintarea->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
