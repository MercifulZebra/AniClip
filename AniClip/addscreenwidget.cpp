#include "addscreenwidget.h"

AddScreenWidget::AddScreenWidget(QWidget *parent) : StackedWidget(parent),
    mainLayout(NULL),
    backButton(NULL)
{

}

bool AddScreenWidget::init(QString config_filename) {
    bool initSuccess_flag = true;

    mainLayout = new QGridLayout(this);

    backButton = new QPushButton(this);

    mainLayout->addWidget(backButton, 0, 0);

    minSize = QSize(300, 300);
    maxSize = QSize(300, 300);

    return initSuccess_flag;
}
