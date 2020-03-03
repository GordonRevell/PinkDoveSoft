#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "optionsdialog.h"

#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusbar->addPermanentWidget(_timeLabel);

    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::update);

    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::update()
{
    QDateTime time = QDateTime::currentDateTime();

    _timeLabel->setText(time.toString("hh:mm:ss dd-MMM-yyyy"));
}

void MainWindow::on_actionOptions_triggered()
{
    OptionsDialog* d = new OptionsDialog(this);

    d->exec();
}
