#ifndef STARTSCREENWIDGET_H
#define STARTSCREENWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>

#include "stackedwidget.h"

class StartScreenWidget : public StackedWidget
{
    Q_OBJECT
public:
    explicit StartScreenWidget(QWidget *parent = 0);

    bool init(QString config_filename);

    virtual void resizeEvent(QResizeEvent *);
    void setButtonPosition(QSize buttonBoxSize);

    QGridLayout *mainLayout;

    QFrame *infoBox;
    QFrame *buttonBox;

    int buttonHeight;
    int buttonWidth;

    QPushButton *addScreenButton;
    QPushButton *editScreenButton;
    QPushButton *miniScreenButton;
    QPushButton *settingsScreenButton;
    QPushButton *otherButton;

signals:

public slots:
};

#endif // STARTSCREENWIDGET_H
