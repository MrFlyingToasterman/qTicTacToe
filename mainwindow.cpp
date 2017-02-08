#include "mainwindow.h"
#include "ui_mainwindow.h"

//GlobVarz
QString player = "X";

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),ui(new Ui::MainWindow) {

    ui->setupUi(this);

}

MainWindow::~MainWindow() {

    delete ui;

}

void change_player() {

    if(player == "X") {
        player = "O";
    }else{
        player = "X";
    }

}

void MainWindow::btn_rename(int btn) {

    //Switch Player
    change_player();

    //Set Playername as btntext
    switch(btn) {
    case 1:
    ui->pushButton->setText(player);
        break;
    case 2:
    ui->pushButton_2->setText(player);
        break;
    case 3:
    ui->pushButton_3->setText(player);
        break;
    case 4:
    ui->pushButton_4->setText(player);
        break;
    case 5:
    ui->pushButton_5->setText(player);
        break;
    case 6:
    ui->pushButton_6->setText(player);
        break;
    case 7:
    ui->pushButton_7->setText(player);
        break;
    case 8:
    ui->pushButton_8->setText(player);
        break;
    case 9:
    ui->pushButton_9->setText(player);
        break;
    default:
        break;
    }

}

void MainWindow::on_pushButton_clicked() {

    btn_rename(1);

}

void MainWindow::on_pushButton_2_clicked() {

    btn_rename(2);

}

void MainWindow::on_pushButton_3_clicked() {

    btn_rename(3);

}

void MainWindow::on_pushButton_4_clicked() {

    btn_rename(4);

}

void MainWindow::on_pushButton_5_clicked() {
    btn_rename(5);
}

void MainWindow::on_pushButton_6_clicked() {
    btn_rename(6);
}

void MainWindow::on_pushButton_7_clicked() {
    btn_rename(7);
}

void MainWindow::on_pushButton_8_clicked() {
    btn_rename(8);
}

void MainWindow::on_pushButton_9_clicked() {
    btn_rename(9);
}
