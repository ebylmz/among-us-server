#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    serverConfiguration = new ServerConfiguration;
    gameStatus = new GameStatus;

    // Add pages to stacked widget
    stackedWidget->addWidget(serverConfiguration);
    stackedWidget->addWidget(gameStatus);

    setCentralWidget(stackedWidget);

    // Connect signals and slots
    connect(serverConfiguration, &ServerConfiguration::connectionEstablished, this, &MainWindow::switchToGamePage);
    connect(gameStatus, &GameStatus::disconnectRequested, this, &MainWindow::switchToConfigurationPage);

    // Set the initial size of the MainWindow
    resize(1280, 720); // Set a size of 1280x720 pixels
}

void MainWindow::switchToGamePage() {
    stackedWidget->setCurrentWidget(gameStatus);
}

void MainWindow::switchToConfigurationPage() {
    stackedWidget->setCurrentWidget(serverConfiguration);
    // Perform cleanup or reset server connection if needed
}
