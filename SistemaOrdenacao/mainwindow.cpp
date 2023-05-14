#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      objetoOrdenacao(0)
{
    ui->setupUi(this);
    ui->textEditVetorOrdenado->setEnabled(false);
    ui->textEditVetorOriginal->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->pushButtonExecutar->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(objetoOrdenacao) delete[] objetoOrdenacao;
}


void MainWindow::on_pushButtonCriar_clicked()
{
    try{
        if(ui->lineEditQuantidadeElementos->text().toInt()<=0) throw QString("Informe qunatidade de elementos maior que zero");
        ui->comboBox->setEnabled(true);
        ui->pushButtonExecutar->setEnabled(true);

        objetoOrdenacao = new ggs::ExecutarOrdenacao(ui->lineEditQuantidadeElementos->text().toInt());
        ui->textEditVetorOriginal->setText(objetoOrdenacao->imprimirVetor());

        ui->lineEditQuantidadeElementos->clear();
    } catch(QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}


void MainWindow::on_pushButtonExecutar_clicked()
{
    try{
        if(ui->comboBox->currentText() == "Crescente") objetoOrdenacao->ordenarCrescente();
        if(ui->comboBox->currentText() == "Decrescente") objetoOrdenacao->ordenarDecrescente();

        ui->textEditVetorOrdenado->setText(objetoOrdenacao->imprimirVetor());
    } catch(QString &erro){
        QMessageBox::information(this, "ERRO DO SISTEMA", erro);
    }
}
