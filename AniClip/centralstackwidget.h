#ifndef CENTRALSTACKWIDGET_H
#define CENTRALSTACKWIDGET_H

#include <QWidget>
#include <QStackedWidget>

class StackedWidget;
class StartScreenWidget;
class AddScreenWidget;
class TransitionScreenWidget;

namespace logger {
    class Logger;
}

class CentralStackWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit CentralStackWidget(QWidget *parent = 0);
    bool init(QString config_filename, logger::Logger *nLog);
    void setInitialPage(int index);

    void changeCurrentPage(int index);
    void changeCurrentPage_helper(int index);
    void disableInput();
    void enableInput();

    logger::Logger *log;

    bool useAnimation_flag;
    int  queuedPage_index;
    bool disableInput_flag;

    StartScreenWidget *startScreen;
    int startScreen_index;

    AddScreenWidget *addScreen;
    int addScreen_index;

    TransitionScreenWidget *tranScreen;
    int tranScreen_index;
    bool finishedSizeAnimation_flag;
    bool finishedBackgroundAnimation_flag;

signals:
    void requestSizeBound(int minHeight, int minWidth, int maxHeight, int maxWidth, bool animate_flag);

public slots:
    void setStartScreen();
    void setAddScreen();

    void setTransitionScreen();
    void onSizeAnimationFinish();
    void onBackgroundAnimationFinish();
    void setQueuedScreen();

    void finishedTransition();
};

#endif // CENTRALSTACKWIDGET_H
