#include "startscreenwidget.h"

#include <QDebug>
StartScreenWidget::StartScreenWidget(QWidget *parent) : StackedWidget(parent),
    mainLayout(NULL),
    infoBox(NULL),
    buttonBox(NULL),
    addScreenButton(NULL),
    editScreenButton(NULL),
    miniScreenButton(NULL),
    settingsScreenButton(NULL),
    otherButton(NULL)
{

}

bool StartScreenWidget::init(QString config_filename) {
    bool initSuccess_flag = true;

    mainLayout  = new QGridLayout(this);
    infoBox     = new QFrame(this);
    buttonBox   = new QFrame(this);

    mainLayout->addWidget(infoBox, 0, 0, Qt::AlignTop);
    mainLayout->addWidget(buttonBox, 0, 1, Qt::AlignTop);

    minSize = QSize(660, 300);
    maxSize = QSize(800, 400);

    //infoBox
    infoBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    infoBox->setFixedHeight(300);
    infoBox->setFixedWidth(500);
    infoBox->setFrameStyle(QFrame::Box);

    //buttonBox
    buttonBox->setMinimumWidth(140);
    buttonBox->setMinimumHeight(300);
    buttonBox->setFrameStyle(QFrame::Box);

    buttonHeight = 40;
    buttonWidth = 120;

    addScreenButton = new QPushButton(buttonBox);
    editScreenButton = new QPushButton(buttonBox);
    miniScreenButton = new QPushButton(buttonBox);
    settingsScreenButton = new QPushButton(buttonBox);
    otherButton = new QPushButton(buttonBox);

    addScreenButton->setText("add");
    editScreenButton->setText("edit");
    miniScreenButton->setText("mini");
    settingsScreenButton->setText("settings");
    otherButton->setText("other");

    addScreenButton->setFixedSize(buttonWidth, buttonHeight);
    editScreenButton->setFixedSize(buttonWidth, buttonHeight);
    miniScreenButton->setFixedSize(buttonWidth, buttonHeight);
    settingsScreenButton->setFixedSize(buttonWidth, buttonHeight);
    otherButton->setFixedSize(buttonWidth, buttonHeight);

    setButtonPosition(buttonBox->size());
    return initSuccess_flag;
}

void StartScreenWidget::resizeEvent(QResizeEvent *event) {
    if (infoBox != NULL && buttonBox != NULL) {
        setButtonPosition(buttonBox->size());
    }
}

void StartScreenWidget::setButtonPosition(QSize buttonBoxSize) {
    if (buttonBoxSize.width() > 140) {
        int border = (buttonBoxSize.width() - buttonWidth) / 2;
        int vBorder = (buttonBoxSize.height() - buttonHeight * 5) / 6;
        addScreenButton->setGeometry(border, vBorder, 120, 40);
        editScreenButton->setGeometry(border, (vBorder * 2+ buttonHeight), 120, 40);
        miniScreenButton->setGeometry(border, (vBorder * 3+ buttonHeight * 2), 120, 40);
        settingsScreenButton->setGeometry(border, (vBorder * 4 + buttonHeight * 3), 120, 40);
        otherButton->setGeometry(border, (vBorder * 5 + buttonHeight * 4), 120, 40);
    }
    else {
        int border = (buttonBoxSize.width() - buttonWidth) / 2;
        int vBorder = (buttonBoxSize.height() - buttonHeight * 5) / 6;
        addScreenButton->setGeometry(border, vBorder, 120, 40);
        editScreenButton->setGeometry(border, (vBorder * 2+ buttonHeight), 120, 40);
        miniScreenButton->setGeometry(border, (vBorder * 3+ buttonHeight * 2), 120, 40);
        settingsScreenButton->setGeometry(border, (vBorder * 4 + buttonHeight * 3), 120, 40);
        otherButton->setGeometry(border, (vBorder * 5 + buttonHeight * 4), 120, 40);
    }
}
