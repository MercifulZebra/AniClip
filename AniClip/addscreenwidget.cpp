#include <QDebug>

#include "addscreenwidget.h"


AddScreenWidget::AddScreenWidget(QWidget *parent) : StackedWidget(parent),
    mainLayout(NULL),
    topBar(NULL),
    editWidget(NULL),
    tagDispWidget(NULL),
    clipDispWidget(NULL),
    returnButton(NULL)
{

}

bool AddScreenWidget::init(QString config_filename, logger::Logger *nLog) {
    bool initSuccess_flag = true;

    log = nLog;

    mainLayout = new QGridLayout(this);
    topBar = new QWidget(this);
    editWidget = new QWidget(this);
    tagDispWidget = new QWidget(this);
    clipDispWidget = new QWidget(this);

    mainLayout->addWidget(topBar, 0, 0, 1, 2);
    mainLayout->addWidget(editWidget, 1, 0, 1, 1);
    mainLayout->addWidget(tagDispWidget, 1, 2, 2, 1);
    mainLayout->addWidget(clipDispWidget, 2, 0, 1, 1);


    //Top Bar
    returnButton = new QPushButton(topBar);

    minSize = QSize(900, 500);
    maxSize = QSize(900, 500);

    return initSuccess_flag;
}
