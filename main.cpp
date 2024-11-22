#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QUuid>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // // Open the events.csv file and prepend a QUuid to each line
    // QFile file("D:/AUC/Semester Two/CSCE2 Lab/Final Project/AUC-UCMS/events.csv");
    // if (!file.open(QIODevice::ReadWrite))
    //     throw std::runtime_error("Could not open file");
    // QTextStream in(&file);
    // in.readLine();
    // QString line;
    // while (!in.atEnd()) {
    //     line = in.readLine();
    //     QUuid id = QUuid::createUuid();
    //     line.append(id.toString());
    //     // Add new line to file
    //     in << line << '\n';
    //     // qDebug() << line;
    // }

    return a.exec();

}
