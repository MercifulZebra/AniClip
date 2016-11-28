#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class CentralStackWidget;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool init(QString config_filename);

private:
    Ui::MainWindow *ui;

    CentralStackWidget *centralStack;

public slots:
    void setSizeBound(int minHeight, int minWidth, int maxHeight, int maxWidth);
};

#endif // MAINWINDOW_H
