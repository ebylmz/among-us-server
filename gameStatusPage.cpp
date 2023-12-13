#include "gameStatusPage.h"

GameStatusPage::GameStatusPage(QWidget *parent) : QWidget(parent) {

    QPixmap mapImage(":/images/game-map.png");
    mapLabel = new QLabel;
    mapLabel->setPixmap(mapImage.scaled(mapLabel->size() * 1.5, Qt::KeepAspectRatio));
    mapLabel->setAlignment(Qt::AlignCenter); // Align the pixmap to the center
    healthLabel = new QLabel("Health: N/A");
    locationLabel = new QLabel("Location: N/A");

    disconnectButton = new QPushButton("Disconnect from server");

    layout = new QVBoxLayout(this);
    layout->addWidget(mapLabel);
    layout->addWidget(healthLabel);
    layout->addWidget(locationLabel);
    layout->addWidget(disconnectButton);

    connect(disconnectButton, &QPushButton::clicked, this, &GameStatusPage::disconnect);
}

void GameStatusPage::updateGameStatus(int playerHealth, QString playerLocation) {
    healthLabel->setText("Health: " + QString::number(playerHealth));
    locationLabel->setText("Location: " + playerLocation);
    // Load and display the game map image
    // mapLabel->setPixmap(mapImage.scaled(mapLabel->size(), Qt::KeepAspectRatio));
}

void GameStatusPage::disconnect() {
    emit disconnectRequested(); // Signal to return to the server connection page
}
