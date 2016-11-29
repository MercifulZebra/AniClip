#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "centralstackwidget.h"

#include <QDebug>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    centralStack(NULL),
    minSizeAnimation(NULL),
    maxSizeAnimation(NULL)
{
    ui->setupUi(this);
    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::init(QString config_filename) {
    bool initSuccess_flag = true;

    centralStack = new CentralStackWidget(this);

    minSizeAnimation = new QPropertyAnimation(this, "minimumSize", this);\
    maxSizeAnimation = new QPropertyAnimation(this, "maximumSize", this);

    minSizeAnimation->setEasingCurve(QEasingCurve::OutBack);
    maxSizeAnimation->setEasingCurve(QEasingCurve::OutBack);
    minSizeAnimation->setDuration(800);
    maxSizeAnimation->setDuration(800);

    connect(maxSizeAnimation, SIGNAL(finished()), this, SLOT(onSizeAnimationFinish()));

    initSuccess_flag = initSuccess_flag && centralStack->init(config_filename);

    if (initSuccess_flag) {
        setCentralWidget(centralStack);
        connect(centralStack, SIGNAL(requestSizeBound(int,int,int,int, bool)), this, SLOT(setSizeBound(int,int,int,int, bool)));
        centralStack->setInitialPage(centralStack->startScreen_index);
    }



    return initSuccess_flag;
}


void MainWindow::setSizeBound(int minHeight, int minWidth, int maxHeight, int maxWidth, bool animate_flag) {

    if (!animate_flag) {
        setMinimumHeight(minHeight + ui->statusBar->height() + 10);
        setMaximumHeight(maxHeight + ui->statusBar->height() + 10);
        setMinimumWidth(minWidth);
        setMaximumWidth(maxWidth);
    }
    else {

        minSizeAnimation->setStartValue(minimumSize());
        minSizeAnimation->setEndValue(QSize(minWidth, minHeight + ui->statusBar->height() + 10));

        maxSizeAnimation->setStartValue(maximumSize());
        maxSizeAnimation->setEndValue(QSize(maxWidth, maxHeight + ui->statusBar->height() + 10));

        minSizeAnimation->start();
        maxSizeAnimation->start();
//        setMinimumHeight(minHeight + ui->statusBar->height() + 10);
//        setMaximumHeight(maxHeight + ui->statusBar->height() + 10);
//        setMinimumWidth(minWidth);
//        setMaximumWidth(maxWidth);


    }

}

void MainWindow::onSizeAnimationFinish() {
    centralStack->onSizeAnimationFinish();
}
