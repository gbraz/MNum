#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_okButton_clicked()
{
    double pmulti = ui->multiplicidade->text().toDouble();
    int nrea = ui->nReacoes->text().toInt();

    if(nrea > 5){
        QMessageBox::critical(this,"Erro","Número máximo de reações é 5!\nRegule a entrada dos coeficientes!",
                                        QMessageBox::Cancel);
        return;
    }
    if(nrea == 0){
        QMessageBox::critical(this,"Erro","Número de reações inválido!", QMessageBox::Cancel);
        return;
    }
    if(pmulti <= 0){
        QMessageBox::critical(this,"Erro","Valor de multiplicidade inválido!", QMessageBox::Cancel);
        return;
    }
    //QVector<double> vet;
    //QVector<QVector<double>> coef;
    double coef[5][5];
    coef[0][0] = ui->a11->text().toDouble();
    coef[0][1] = ui->a12->text().toDouble();
    coef[0][2] = ui->a13->text().toDouble();
    coef[0][3] = ui->a14->text().toDouble();
    coef[0][4] = ui->a15->text().toDouble();
    coef[1][0] = ui->a21->text().toDouble();
    coef[1][1] = ui->a22->text().toDouble();
    coef[1][2] = ui->a23->text().toDouble();
    coef[1][3] = ui->a24->text().toDouble();
    coef[1][4] = ui->a25->text().toDouble();
    coef[2][0] = ui->a31->text().toDouble();
    coef[2][1] = ui->a32->text().toDouble();
    coef[2][2] = ui->a33->text().toDouble();
    coef[2][3] = ui->a34->text().toDouble();
    coef[2][4] = ui->a35->text().toDouble();
    coef[3][0] = ui->a41->text().toDouble();
    coef[3][1] = ui->a42->text().toDouble();
    coef[3][2] = ui->a43->text().toDouble();
    coef[3][3] = ui->a44->text().toDouble();
    coef[3][4] = ui->a45->text().toDouble();
    coef[4][0] = ui->a51->text().toDouble();
    coef[4][1] = ui->a52->text().toDouble();
    coef[4][2] = ui->a53->text().toDouble();
    coef[4][3] = ui->a54->text().toDouble();
    coef[4][4] = ui->a55->text().toDouble();

}
