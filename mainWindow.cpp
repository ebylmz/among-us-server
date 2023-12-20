#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    server = new Server;
    gameStatus = new GameStatus(server);

    // Add pages to stacked widget
    stackedWidget->addWidget(server);
    stackedWidget->addWidget(gameStatus);

    setCentralWidget(stackedWidget);

    // Connect signals and slots
    connect(server, &Server::serverStarted, this, &MainWindow::switchToGamePage);
    connect(gameStatus, &GameStatus::disconnectRequested, this, &MainWindow::switchToConfigurationPage);

    // Set the initial size of the MainWindow
    resize(1280, 720); // Set a size of 1280x720 pixels
}

void MainWindow::switchToGamePage() {
    stackedWidget->setCurrentWidget(gameStatus);
}

void MainWindow::switchToConfigurationPage() {
    stackedWidget->setCurrentWidget(server);
    // Perform cleanup or reset server connection if needed
}
