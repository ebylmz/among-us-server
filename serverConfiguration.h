#ifndef SERVERCONFIGURATION_H
#define SERVERCONFIGURATION_H

#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>

namespace Ui {
class ServerConfiguration;
}

class ServerConfiguration : public QWidget
{
    Q_OBJECT

public:
    explicit ServerConfiguration(QWidget *parent = nullptr);
    ~ServerConfiguration();

private slots:
    void on_createButton_clicked();

signals:
    void connectionEstablished();

private:
    Ui::ServerConfiguration *ui;
    QTcpSocket *socket;
};


#endif // SERVERCONFIGURATION_H
