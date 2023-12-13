// ServerConnection.h
#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QMessageBox>

class ServerConnection : public QWidget {
    Q_OBJECT

public:
    explicit ServerConnection(QWidget *parent = nullptr);

private slots:
    void connectToServer();

signals:
    void connectionEstablished();

private:
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
    QPushButton *connectButton;
    QTcpSocket *socket;
};

#endif // SERVERCONNECTION_H
