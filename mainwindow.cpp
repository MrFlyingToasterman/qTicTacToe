#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

bool check_posswin() {

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (playground[y][x] == "") {
                return true;
            }
        }
    }

    return false;
}

bool check_win() {

    if(playground[0][0] == player && playground[0][1] == player && playground[0][2] == player) {
        return true;
    }
    if(playground[1][0] == player && playground[1][1] == player && playground[1][2] == player) {
        return true;
    }
    if(playground[2][0] == player && playground[2][1] == player && playground[2][2] == player) {
        return true;
    }

    if(playground[0][0] == player && playground[1][0] == player && playground[2][0] == player) {
        return true;
    }
    if(playground[0][1] == player && playground[1][1] == player && playground[2][1] == player) {
        return true;
    }
    if(playground[0][2] == player && playground[1][2] == player && playground[2][2] == player) {
        return true;
    }

    if(playground[0][0] == player && playground[1][1] == player && playground[2][2] == player) {
        return true;
    }
    if(playground[0][2] == player && playground[1][1] == player && playground[2][0] == player) {
        return true;
    }

    return false;
}

void MainWindow::cleanup() {

    ui->pushButton->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            playground[y][x] = "";
        }
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

        //Check if anyone has won yet
        if (check_win()) {
            QMessageBox mbox;
            mbox.setText("Player " + player + " has won!");
            mbox.exec();

            //cleanup -> set all btns to ""
            cleanup();
        }

        //Check if its possible to win
        if (!check_posswin()) {
            QMessageBox mbox;
            mbox.setText("Nobody wins!");
            mbox.exec();

            //cleanup -> set all btns to ""
            cleanup();
        }
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
