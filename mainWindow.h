#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "oldserverConfiguration.h"
#include "gameStatus.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void switchToGamePage();
    void switchToConfigurationPage();

private:
    QStackedWidget *stackedWidget;
    ServerConfiguration *serverConfiguration;
    GameStatus *gameStatus;
};

#endif // MAINWINDOW_H
