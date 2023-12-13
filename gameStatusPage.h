#ifndef GAMESTATUSPAGE_H
#define GAMESTATUSPAGE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

class GameStatusPage : public QWidget {
    Q_OBJECT

public:
    explicit GameStatusPage(QWidget *parent = nullptr);
    void updateGameStatus(int playerHealth, QString playerLocation);
    void disconnect();

signals:
    void disconnectRequested(); // Signal to return to the server connection page

private:
    QLabel *mapLabel;
    QLabel *healthLabel;
    QLabel *locationLabel;
    QVBoxLayout *layout;
    QPushButton *disconnectButton;
};

#endif // GAMESTATUSPAGE_H
