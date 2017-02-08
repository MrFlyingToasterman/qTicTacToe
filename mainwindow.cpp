#include "mainwindow.h"
#include "ui_mainwindow.h"

//GlobVarz
QString player = "X";
QString playground[3][3];

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

bool check_used(int x, int y) {

    if(playground[x][y] == "") {
        return true;
    }else {
        return false;
    }

}

void MainWindow::btn_rename(int x, int y) {

    //Check if this field is unused
    if(check_used(x, y)) {

        //Switch Player
        change_player();

        //Create unique string
        std::string checkme = std::to_string(x) + std::to_string(y);

        //Set Playername as btntext
        if(checkme == "00") {
            ui->pushButton->setText(player);
        }
        if(checkme == "01") {
            ui->pushButton_2->setText(player);
        }
        if(checkme == "02") {
            ui->pushButton_3->setText(player);
        }
        if(checkme == "10") {
            ui->pushButton_4->setText(player);
        }
        if(checkme == "11") {
            ui->pushButton_5->setText(player);
        }
        if(checkme == "12") {
            ui->pushButton_6->setText(player);
        }
        if(checkme == "20") {
            ui->pushButton_7->setText(player);
        }
        if(checkme == "21") {
            ui->pushButton_8->setText(player);
        }
        if(checkme == "22") {
            ui->pushButton_9->setText(player);
        }

        //Save position to array
        playground[x][y] = player;
    }

}

void MainWindow::on_pushButton_clicked() {
    btn_rename(0, 0);
}

void MainWindow::on_pushButton_2_clicked() {
    btn_rename(0, 1);
}

void MainWindow::on_pushButton_3_clicked() {
    btn_rename(0, 2);
}

void MainWindow::on_pushButton_4_clicked() {
    btn_rename(1, 0);
}

void MainWindow::on_pushButton_5_clicked() {
    btn_rename(1, 1);
}

void MainWindow::on_pushButton_6_clicked() {
    btn_rename(1, 2);
}

void MainWindow::on_pushButton_7_clicked() {
    btn_rename(2, 0);
}

void MainWindow::on_pushButton_8_clicked() {
    btn_rename(2, 1);
}

void MainWindow::on_pushButton_9_clicked() {
    btn_rename(2, 2);
}
