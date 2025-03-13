#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // socket_.connected(); // signal func
    // socket_.readyRead();
    QObject::connect(&socket_, &QAbstractSocket::connected, this, &Widget::doConnected);
    QObject::connect(&socket_, &QAbstractSocket::disconnected, this, &Widget::doDisConnected);
    QObject::connect(&socket_, &QIODevice::readyRead, this, &Widget::doReadyRead);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::doConnected(){
    ui->pteMessage->insertPlainText("Connected");
}

void Widget::doDisConnected(){
    ui->pteMessage->insertPlainText("DisConnected");
}

void Widget::doReadyRead(){
    ui->pteMessage->insertPlainText(socket_.readAll());
}

void Widget::on_pbConnect_clicked()
{
    if (isHTTPS){
        socket_.connectToHostEncrypted(ui->lePost->text(), ui->lePort->text().toUShort());
    }
    else {
        socket_.connectToHost(ui->lePost->text(), ui->lePort->text().toUShort());
    }


}


void Widget::on_pbDisConnect_clicked()
{
    socket_.disconnectFromHost();
}


void Widget::on_pbClear_clicked()
{
    ui->pteMessage->clear();
}


void Widget::on_pbSend_clicked()
{
    socket_.write(ui->pteSend->toPlainText().toUtf8());
}



void Widget::on_cbHttps_toggled(bool checked)
{
    if (checked){
        ui->lePort->setText("443");
        isHTTPS = 1;
    }
    else {
        ui->lePort->setText("80");
        isHTTPS = 0;
    }
}

