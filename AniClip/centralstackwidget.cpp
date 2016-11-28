#include "centralstackwidget.h"

#include "startscreenwidget.h"
#include "addscreenwidget.h"

CentralStackWidget::CentralStackWidget(QWidget *parent) : QStackedWidget(parent),
    startScreen(NULL),
    startScreen_index(-1),
    addScreen(NULL),
    addScreen_index(-1)
{

}

bool CentralStackWidget::init(QString config_filename) {
    bool initSuccess_flag = true;

    startScreen = new StartScreenWidget(this);
    initSuccess_flag = initSuccess_flag && startScreen->init(config_filename);

    if (initSuccess_flag) {
        startScreen_index = addWidget(startScreen);
        changeCurrentPage(startScreen_index);

        connect(startScreen->addScreenButton, SIGNAL(clicked(bool)), this, SLOT(setAddScreen()));
    }

    addScreen = new AddScreenWidget(this);
    initSuccess_flag = initSuccess_flag && addScreen->init(config_filename);

    if (initSuccess_flag) {
        addScreen_index = addWidget(addScreen);
        connect(addScreen->backButton, SIGNAL(clicked(bool)), this, SLOT(setStartScreen()));
    }


    return initSuccess_flag;
}

void CentralStackWidget::changeCurrentPage(int index) {
    setCurrentIndex(index);

    StackedWidget *current = dynamic_cast<StackedWidget *>(currentWidget());

    if (current != NULL) {

        QSize nMin = current->getMinSize();
        QSize nMax = current->getMaxSize();

        requestSizeBound(nMin.height(), nMin.width(), nMax.height(), nMax.width());
    }
}

void CentralStackWidget::setStartScreen() {
    changeCurrentPage(startScreen_index);
}

void CentralStackWidget::setAddScreen() {
    changeCurrentPage(addScreen_index);
}

