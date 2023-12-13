#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    stackedWidget = new QStackedWidget(this);
    serverConnection = new ServerConnection;
    gameStatusPage = new GameStatusPage;

    // Add pages to stacked widget
    stackedWidget->addWidget(serverConnection);
    stackedWidget->addWidget(gameStatusPage);

    setCentralWidget(stackedWidget);

    // Connect signals and slots
    connect(serverConnection, &ServerConnection::connectionEstablished, this, &MainWindow::switchToGamePage);
    connect(gameStatusPage, &GameStatusPage::disconnectRequested, this, &MainWindow::switchToConnectionPage);

    // Set the initial size of the MainWindow
    resize(1280, 720); // Set a size of 1280x720 pixels
}

void MainWindow::switchToGamePage() {
    stackedWidget->setCurrentWidget(gameStatusPage);
}

void MainWindow::switchToConnectionPage() {
    stackedWidget->setCurrentWidget(serverConnection);
    // Perform cleanup or reset server connection if needed
}
