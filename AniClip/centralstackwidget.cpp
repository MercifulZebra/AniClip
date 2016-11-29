#include "centralstackwidget.h"

#include "startscreenwidget.h"
#include "addscreenwidget.h"
#include "transitionscreenwidget.h"

#include <QDebug>

CentralStackWidget::CentralStackWidget(QWidget *parent) : QStackedWidget(parent),
    useAnimation_flag(true),
    queuedPage_index(-1),
    disableInput_flag(false),
    startScreen(NULL),
    startScreen_index(-1),
    addScreen(NULL),
    addScreen_index(-1),
    tranScreen(NULL),
    tranScreen_index(-1),
    finishedSizeAnimation_flag(false),
    finishedBackgroundAnimation_flag(false)
{

}

bool CentralStackWidget::init(QString config_filename) {
    bool initSuccess_flag = true;

    startScreen = new StartScreenWidget(this);
    initSuccess_flag = initSuccess_flag && startScreen->init(config_filename);

    if (initSuccess_flag) {
        startScreen_index = addWidget(startScreen);

        connect(startScreen->addScreenButton, SIGNAL(clicked(bool)), this, SLOT(setAddScreen()));
        connect(startScreen, SIGNAL(finishAnimate_clear()), this, SLOT(setTransitionScreen()));
        connect(startScreen, SIGNAL(finishAnimate_on()), this, SLOT(finishedTransition()));

    }

    addScreen = new AddScreenWidget(this);
    initSuccess_flag = initSuccess_flag && addScreen->init(config_filename);

    if (initSuccess_flag) {
        addScreen_index = addWidget(addScreen);
        connect(addScreen->backButton, SIGNAL(clicked(bool)), this, SLOT(setStartScreen()));
        connect(addScreen, SIGNAL(finishAnimate_clear()), this, SLOT(setTransitionScreen()));
        connect(addScreen, SIGNAL(finishAnimate_on()), this, SLOT(finishedTransition()));
    }

    tranScreen = new TransitionScreenWidget(this);
    initSuccess_flag = initSuccess_flag && tranScreen->init(config_filename);

    if (initSuccess_flag) {
        tranScreen_index = addWidget(tranScreen);

        connect(tranScreen, SIGNAL(finishAnimate_background()), this, SLOT(onBackgroundAnimationFinish()));
    }



    return initSuccess_flag;
}

void CentralStackWidget::setInitialPage(int index) {
    setCurrentIndex(index);

    StackedWidget *current = dynamic_cast<StackedWidget *>(currentWidget());

    if (current != NULL) {

        QSize nMin = current->getMinSize();
        QSize nMax = current->getMaxSize();

        emit requestSizeBound(nMin.height(), nMin.width(), nMax.height(), nMax.width(), false);
    }
}

void CentralStackWidget::changeCurrentPage(int index) {

    if (!useAnimation_flag) {

        changeCurrentPage_helper(index);

    }
    else {
        //Disable clicks
        StackedWidget *current = dynamic_cast<StackedWidget *>(currentWidget());

        if (current != NULL) {
            disableInput();
            finishedBackgroundAnimation_flag = false;
            finishedSizeAnimation_flag = false;
            current->animateClear();
        }
    }

}

void CentralStackWidget::changeCurrentPage_helper(int index) {
    setCurrentIndex(index);

    StackedWidget *current = dynamic_cast<StackedWidget *>(currentWidget());

    if (current != NULL) {
        QSize nMin = current->getMinSize();
        QSize nMax = current->getMaxSize();

        emit requestSizeBound(nMin.height(), nMin.width(), nMax.height(), nMax.width(), useAnimation_flag);
    }
}

void CentralStackWidget::disableInput() {
    disableInput_flag = true;
}

void CentralStackWidget::enableInput() {
    disableInput_flag = false;
}

void CentralStackWidget::setStartScreen() {
    if (!disableInput_flag) {
        queuedPage_index = startScreen_index;
        changeCurrentPage(startScreen_index);
    }
}

void CentralStackWidget::setAddScreen() {
    if (!disableInput_flag) {
        queuedPage_index = addScreen_index;
        changeCurrentPage(addScreen_index);
    }
}

void CentralStackWidget::setTransitionScreen() {
    // Load both backgrounds
    setCurrentIndex(tranScreen_index);
    tranScreen->animateBackground();
    StackedWidget *next = dynamic_cast<StackedWidget *>(widget(queuedPage_index));

    if (next != NULL) {
        QSize nMin = next->getMinSize();
        QSize nMax = next->getMaxSize();

        emit requestSizeBound(nMin.height(), nMin.width(), nMax.height(), nMax.width(), useAnimation_flag);
    }

}

void CentralStackWidget::onSizeAnimationFinish() {
    finishedSizeAnimation_flag = true;
    setQueuedScreen();
}

void CentralStackWidget::onBackgroundAnimationFinish() {
    finishedBackgroundAnimation_flag = true;
    setQueuedScreen();
}

void CentralStackWidget::setQueuedScreen() {

    if (finishedSizeAnimation_flag && finishedBackgroundAnimation_flag) {
        setCurrentIndex(queuedPage_index);
        StackedWidget *current = dynamic_cast<StackedWidget *>(currentWidget());

        if (current != NULL) {
            current->animateOn();
        }
    }
}

void CentralStackWidget::finishedTransition() {
    enableInput();
}
