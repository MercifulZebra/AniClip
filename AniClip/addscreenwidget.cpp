#include <QDebug>

#include "addscreenwidget.h"


AddScreenWidget::AddScreenWidget(QWidget *parent) : StackedWidget(parent),
    mainLayout(NULL),
    backButton(NULL),
    startTime_edit(NULL)
{

}

bool AddScreenWidget::init(QString config_filename) {
    bool initSuccess_flag = true;

    mainLayout = new QGridLayout(this);

    backButton = new QPushButton(this);

    startTime_edit = new QTimeEdit(this);
    qDebug() << startTime_edit->displayFormat();
    startTime_edit->setDisplayFormat("mm:ss");
    mainLayout->addWidget(backButton, 0, 0);
    mainLayout->addWidget(startTime_edit);

    minSize = QSize(300, 500);
    maxSize = QSize(300, 500);

    return initSuccess_flag;
}
