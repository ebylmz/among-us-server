#ifndef GAMESTATUS_H
#define GAMESTATUS_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

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
    void updateGameStatus();

signals:
    void disconnectRequested();

private slots:
    void on_disconnectButton_clicked();

private:
    Ui::GameStatus *ui;
};

#endif // GAMESTATUS_H
