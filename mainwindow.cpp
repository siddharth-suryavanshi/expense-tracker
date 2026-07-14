#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabel->setColumnCount(4);

    QStringList headers;
    headers << "Date"
            << "Category"
            << "Description"
            << "Amount";

    ui->tabel->setHorizontalHeaderLabels(headers);
    ui->tabel->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addbtn_clicked()
{
    QString category = ui->dropdown->currentText();
    QString description = ui->desctiontext->text();
    QString amount = ui->amounttext->text();
    QString date = ui->dateEdit->date().toString("dd/MM/yyyy");

    int row = ui->tabel->rowCount();

    ui->tabel->insertRow(row);
    ui->tabel->setItem(row, 0, new QTableWidgetItem(date));
    ui->tabel->setItem(row, 1, new QTableWidgetItem(category));
    ui->tabel->setItem(row, 2, new QTableWidgetItem(description));
    ui->tabel->setItem(row, 3, new QTableWidgetItem(amount));
    ui->desctiontext->clear();
    ui->amounttext->clear();
    ui->dropdown->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
}

void MainWindow::on_deletbtn_clicked()
{

}

void MainWindow::on_editbtn_clicked()
{

}

void MainWindow::on_clearbtn_clicked()
{
    ui->desctiontext->clear();
    ui->amounttext->clear();
    ui->dropdown->setCurrentIndex(0);
    ui->dateEdit->setDate(QDate::currentDate());
}
