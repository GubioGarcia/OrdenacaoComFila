#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <executarordenacao.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCriar_clicked();
    void on_pushButtonExecutar_clicked();

private:
    Ui::MainWindow *ui;
    ggs::ExecutarOrdenacao *objetoOrdenacao;
};
#endif // MAINWINDOW_H
