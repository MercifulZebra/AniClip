#include "transitionscreenwidget.h"

#include <QDebug>

TransitionScreenWidget::TransitionScreenWidget(QWidget *parent) : StackedWidget(parent)
{

}

bool TransitionScreenWidget::init(QString config_filename, logger::Logger *nLog) {
    bool initSucces_flag = true;

    log = nLog;

    return initSucces_flag;
}

void TransitionScreenWidget::animateBackground() {
    emit finishAnimate_background();
}
