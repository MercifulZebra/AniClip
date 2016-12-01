#ifndef TRANSITIONSCREENWIDGET_H
#define TRANSITIONSCREENWIDGET_H

#include <QWidget>

#include "stackedwidget.h"


class TransitionScreenWidget : public StackedWidget
{
    Q_OBJECT
public:
    explicit TransitionScreenWidget(QWidget *parent = 0);

    bool init(QString config_filename, logger::Logger *nLog);

    void animateBackground();

signals:
    void finishAnimate_background();
public slots:
};

#endif // TRANSITIONSCREENWIDGET_H
