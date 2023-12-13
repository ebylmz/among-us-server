#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "serverConnection.h"
#include "gameStatusPage.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void switchToGamePage();
    void switchToConnectionPage();

private:
    QStackedWidget *stackedWidget;
    ServerConnection *serverConnection;
    GameStatusPage *gameStatusPage;
};

#endif // MAINWINDOW_H
