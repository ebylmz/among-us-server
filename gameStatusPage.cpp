#include "gameStatusPage.h"

GameStatusPage::GameStatusPage(QWidget *parent) : QWidget(parent) {

    // Create the QGraphicsScene and QGraphicsView
    QGraphicsScene *scene = new QGraphicsScene(this);
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(1280, 720); // Set the size of the QGraphicsView

    /*

    QPixmap mapImage(":/assets/images/game-map.png");
    mapLabel = new QLabel;
    mapLabel->setPixmap(mapImage.scaled(mapLabel->size() * 1.5, Qt::KeepAspectRatio));
    mapLabel->setAlignment(Qt::AlignCenter); // Align the pixmap to the center
    */
    healthLabel = new QLabel("Health: N/A");
    locationLabel = new QLabel("Location: N/A");

    disconnectButton = new QPushButton("Disconnect from server");

    layout = new QVBoxLayout(this);
    layout->addWidget(view);
    //layout->addWidget(mapLabel);
    layout->addWidget(healthLabel);
    layout->addWidget(locationLabel);
    layout->addWidget(disconnectButton);

    updateGameStatus(150, "playerLocation", 300, 300);

    connect(disconnectButton, &QPushButton::clicked, this, &GameStatusPage::disconnect);
}

void GameStatusPage::updateGameStatus(int playerHealth, QString playerLocation, int playerX, int playerY) {
    healthLabel->setText("Health: " + QString::number(playerHealth));
    locationLabel->setText("Location: " + playerLocation);

    // Retrieve the QGraphicsView from the layout
    QGraphicsView *view = qobject_cast<QGraphicsView*>(layout->itemAt(0)->widget());

    if (view) {
        // Retrieve the QGraphicsScene from the QGraphicsView
        QGraphicsScene *scene = view->scene();

        if (scene) {
            // Load the game map image
            QPixmap mapImage(":/assets/images/game-map.png");

            // Clear the scene before adding the map image
            scene->clear();

            // Add the game map image to the scene
            scene->addPixmap(mapImage);



            // Create and position the player icon
            QGraphicsPixmapItem *playerIcon = new QGraphicsPixmapItem(QPixmap(":assets/images/red-among-us.png"));



            playerIcon->setPos(playerX, playerY);
            scene->addItem(playerIcon);
        }
    }

}

void GameStatusPage::disconnect() {
    emit disconnectRequested(); // Signal to return to the server connection page
}
