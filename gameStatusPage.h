#ifndef GAMESTATUSPAGE_H
#define GAMESTATUSPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QIcon>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>

class GameStatusPage : public QWidget {
    Q_OBJECT

public:
    explicit GameStatusPage(QWidget *parent = nullptr);
    void updateGameStatus(int playerHealth, QString playerLocation, int playerX, int playerY);

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
