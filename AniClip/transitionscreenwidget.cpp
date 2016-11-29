#include "transitionscreenwidget.h"

#include <QDebug>

TransitionScreenWidget::TransitionScreenWidget(QWidget *parent) : StackedWidget(parent)
{

}

bool TransitionScreenWidget::init(QString config_filename) {
    bool initSucces_flag = true;


    return initSucces_flag;
}

void TransitionScreenWidget::animateBackground() {
    qDebug () << "animateBackground";
    emit finishAnimate_background();
}
