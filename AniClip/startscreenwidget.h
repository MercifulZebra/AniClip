#ifndef STARTSCREENWIDGET_H
#define STARTSCREENWIDGET_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>
#include <QPropertyAnimation>

#include "styletypes.h"

#include "stackedwidget.h"


class StartScreenWidget : public StackedWidget
{
    Q_OBJECT
public:
    explicit StartScreenWidget(QWidget *parent = 0);

    bool init(QString config_filename, logger::Logger *nLog);
    void readConfig(QString config_filename);
    void updateButtonImages();

    void animateClear();
    void animateOn();

    virtual void resizeEvent(QResizeEvent *);
    void setButtonPosition(QSize buttonBoxSize);

    QGridLayout *mainLayout;

    QFrame *infoBox;
    QFrame *buttonBox;

    int buttonHeight;
    int buttonWidth;
    int vButtonBorder;
    int hButtonBorder;
    double minButtonStretch;
    double buttonStretch;
    int infoWidth;

    int minButtonBoxWidth;
    int maxButtonBoxWidth;

    QPushButton *addScreenButton;
    QPushButton *editScreenButton;
    QPushButton *miniScreenButton;
    QPushButton *settingsScreenButton;
    QPushButton *otherButton;

    style::ButtonStyle defaultButton_style;
    style::ButtonStyle addButton_style;
    style::ButtonStyle editButton_style;
    style::ButtonStyle miniButton_style;
    style::ButtonStyle settingButton_style;
    style::ButtonStyle otherButton_style;

    QPropertyAnimation *clearButtonsAnimation;
    QPropertyAnimation *onButtonsAnimation;

signals:

public slots:
    void onFinishPropertyAnimation_clear();
    void onFinishPropertyAnimation_on();
};

#endif // STARTSCREENWIDGET_H
