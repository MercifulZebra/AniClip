#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "centralstackwidget.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::init(QString config_filename) {
    bool initSuccess_flag = true;

    centralStack = new CentralStackWidget(this);

    initSuccess_flag = initSuccess_flag && centralStack->init(config_filename);

    if (initSuccess_flag) {
        setCentralWidget(centralStack);
        connect(centralStack, SIGNAL(requestSizeBound(int,int,int,int)), this, SLOT(setSizeBound(int,int,int,int)));
    }


    return initSuccess_flag;
}


void MainWindow::setSizeBound(int minHeight, int minWidth, int maxHeight, int maxWidth) {
    setMinimumHeight(minHeight + ui->statusBar->height());
    setMaximumHeight(maxHeight + ui->statusBar->height());
    setMinimumWidth(minWidth);
    setMaximumWidth(maxWidth);

    setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);

    qDebug() << minimumHeight() << minimumWidth() << maximumHeight() << maximumWidth();
}
