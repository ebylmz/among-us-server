#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "server.h"
#include "player.h"

namespace Ui {
class GameStatus;
}

class GameStatus : public QWidget
{
    Q_OBJECT

public:
    explicit GameStatus(QWidget *parent = nullptr);
    ~GameStatus();

    void disconnect();

signals:
    void disconnectRequested();

private slots:
    void on_disconnectButton_clicked();
    void registerPlayer(PlayerInfo *player);
    void updatePlayer(PlayerTransform *ptransform);

private:
    Ui::GameStatus *ui;
};

#endif // GAMESTATUS_H
