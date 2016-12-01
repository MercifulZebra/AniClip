#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPropertyAnimation>

class CentralStackWidget;

namespace logger {
    class Logger;
}

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

    logger::Logger *log;

    CentralStackWidget *centralStack;
    QPropertyAnimation *minSizeAnimation;
    QPropertyAnimation *maxSizeAnimation;

public slots:
    void setSizeBound(int minHeight, int minWidth, int maxHeight, int maxWidth, bool animate_flag);
    void onSizeAnimationFinish();
};

#endif // MAINWINDOW_H
