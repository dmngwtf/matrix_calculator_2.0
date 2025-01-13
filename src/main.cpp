#include "mainwindow.h"
#include <QApplication>
#include <QCoreApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <QDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;      // creates a new window object

    w.showMaximized();
    w.setFixedSize(1200, 600);   // sets the window's size
    w.show();

    return a.exec();
}
