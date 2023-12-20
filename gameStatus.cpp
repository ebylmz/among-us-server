#include "gameStatus.h"
#include "ui_gameStatus.h"

GameStatus::GameStatus(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameStatus)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(new QGraphicsScene());
    //ui->graphicsView->setFixedSize(1280, 720);

    // requires a server object

    //connect(server, &Server::newPlayer, this, &GameStatus::registerPlayer);
    //connect(server, &Server::updatePlayer, this, &GameStatus::updatePlayer);

    GameStatus::updatePlayer(nullptr);
}

GameStatus::~GameStatus()
{
    delete ui;
}

void GameStatus::registerPlayer(PlayerInfo *player) {

}

void GameStatus::updatePlayer(PlayerTransform *ptransform) {

    int playerX = 300, playerY = 300;

    // Access QGraphicsView from the UI
    QGraphicsView *view = ui->graphicsView;

    if (view) {
        // Retrieve the QGraphicsScene from the QGraphicsView
        QGraphicsScene *scene = view->scene();

        if (scene) {
            // Load the game map image
            QPixmap mapImage(":/assets/images/game-map-small.png");

            // Clear the scene before adding the map image
            scene->clear();

            // Add the game map image to the scene
            QGraphicsPixmapItem *mapPixmapItem = scene->addPixmap(mapImage);
            //view->fitInView(mapPixmapItem, Qt::KeepAspectRatio);

            // Create and position the player icon
            QGraphicsPixmapItem *playerIcon = new QGraphicsPixmapItem(QPixmap(":assets/images/red-among-us.png"));
            playerIcon->setPos(playerX, playerY);
            scene->addItem(playerIcon);
        }
    }
}

void GameStatus::on_disconnectButton_clicked()
{
    emit disconnectRequested();
}

