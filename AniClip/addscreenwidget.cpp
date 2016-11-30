#include <QDebug>

#include "addscreenwidget.h"


AddScreenWidget::AddScreenWidget(QWidget *parent) : StackedWidget(parent),
    mainLayout(NULL),
    topBar(NULL),
    editWidget(NULL),
    tagDispWidget(NULL),
    clipDispWidget(NULL)
{

}

bool AddScreenWidget::init(QString config_filename) {
    bool initSuccess_flag = true;

    mainLayout = new QGridLayout(this);
    topBar = new QWidget(this);
    editWidget = new QWidget(this);
    tagDispWidget = new QWidget(this);
    clipDispWidget = new QWidget(this);

    mainLayout->addWidget(topBar, 0, 0, 1, 2);
    mainLayout->addWidget(editWidget, 1, 0, 1, 1);
    mainLayout->addWidget(tagDispWidget, 1, 2, 2, 1);
    mainLayout->addWidget(clipDispWidget, 2, 0, 1, 1);


    minSize = QSize(900, 500);
    maxSize = QSize(900, 500);

    return initSuccess_flag;
}
