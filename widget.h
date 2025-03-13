#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QSslSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // QTcpSocket socket_;
    QSslSocket socket_;
    int isHTTPS = 0;

public slots:
    void doConnected();
    void doDisConnected();
    void doReadyRead();

private slots:
    void on_pbDisConnect_clicked();

    void on_pbConnect_clicked();

    void on_pbClear_clicked();

    void on_pbSend_clicked();


    void on_cbHttps_toggled(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
