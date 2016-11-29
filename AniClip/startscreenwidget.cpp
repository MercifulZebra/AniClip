#include "startscreenwidget.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QPalette>

StartScreenWidget::StartScreenWidget(QWidget *parent) : StackedWidget(parent),
    mainLayout(NULL),
    infoBox(NULL),
    buttonBox(NULL),
    buttonHeight(40),
    buttonWidth(120),
    vButtonBorder(10),
    hButtonBorder(2),
    minButtonStretch(1),
    buttonStretch(1.7),
    infoWidth(500),
    minButtonBoxWidth(120),
    maxButtonBoxWidth(200),
    addScreenButton(NULL),
    editScreenButton(NULL),
    miniScreenButton(NULL),
    settingsScreenButton(NULL),
    otherButton(NULL),
    clearButtonsAnimation(NULL),
    onButtonsAnimation(NULL)
{

}

bool StartScreenWidget::init(QString config_filename) {
    bool initSuccess_flag = true;

    readConfig(config_filename);

    mainLayout  = new QGridLayout(this);
    infoBox     = new QFrame(this);
    buttonBox   = new QFrame(this);

    mainLayout->addWidget(infoBox, 0, 0, Qt::AlignTop);
    mainLayout->addWidget(buttonBox, 0, 1, Qt::AlignTop);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);

    int minHeight = vButtonBorder * 6 + buttonHeight * 6;

    minButtonBoxWidth = buttonWidth * minButtonStretch + 2 * hButtonBorder;
    maxButtonBoxWidth = buttonWidth * buttonStretch + 2 * hButtonBorder;
    minSize = QSize(infoWidth + minButtonBoxWidth, minHeight);
    maxSize = QSize(infoWidth + maxButtonBoxWidth, minHeight);

    //infoBox
    infoBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    infoBox->setMinimumHeight(minHeight);
    infoBox->setFixedWidth(500);
    //infoBox->setFrameStyle(QFrame::Box);

    //buttonBox
    buttonBox->setMinimumWidth(0);//buttonWidth + 2 * hButtonBorder);
    buttonBox->setMinimumHeight(minHeight);
    buttonBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    //buttonBox->setFrameStyle(QFrame::Box);

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
    updateButtonImages();

    clearButtonsAnimation = new QPropertyAnimation(buttonBox, "maximumWidth", this);
    clearButtonsAnimation->setDuration(300);
    clearButtonsAnimation->setStartValue(maxButtonBoxWidth);
    clearButtonsAnimation->setEndValue(0);

    onButtonsAnimation = new QPropertyAnimation(buttonBox, "maximumWidth", this);
    onButtonsAnimation->setDuration(300);
    onButtonsAnimation->setStartValue(0);
    onButtonsAnimation->setEndValue(maxButtonBoxWidth);

    connect(clearButtonsAnimation, SIGNAL(finished()), this, SLOT(onFinishPropertyAnimation_clear()));
    connect(onButtonsAnimation, SIGNAL(finished()), this, SLOT(onFinishPropertyAnimation_on()));

    return initSuccess_flag;
}

void StartScreenWidget::readConfig(QString config_filename) {
    QFile configFile(config_filename);

    if (configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream configStream(&configFile);

        while(!configStream.atEnd()) {
            QString line = configStream.readLine();

            if (!line.startsWith("#") && !line.isEmpty()) {
                QStringList split = line.split(QRegExp("\\s+"));

                if (split.count() > 1) {

                    if (split.at(0) == "buttonHeight_pix") {
                        buttonHeight = split.at(1).toInt();
                    }
                    else if (split.at(0) == "buttonWidth_pix") {
                        buttonWidth = split.at(1).toInt();
                    }
                    else if (split.at(0) == "verticalButtonBorder_pix") {
                        vButtonBorder = split.at(1).toInt();
                    }
                    else if (split.at(0) == "horizantalButtonBorder_pix") {
                        hButtonBorder = split.at(1).toInt();
                    }
                    else if (split.at(0) == "minButtonStretch_ratio") {
                        minButtonStretch = split.at(1).toDouble();
                    }
                    else if (split.at(0) == "maxButtonStretch_ratio") {
                        buttonStretch = split.at(1).toDouble();
                    }
                    else if (split.at(0) == "infoAreaWidth_pix") {
                        infoWidth = split.at(1).toDouble();
                    }

                }
            }
        }
    }
}

void StartScreenWidget::updateButtonImages() {

    buttonNormal_path = "testButton.png";
    buttonHovered_path = "testHover.png";
    buttonChecked_path = "testChecked.png";

    if (!buttonNormal_path.isEmpty() || !buttonHovered_path.isEmpty() || !buttonChecked_path.isEmpty()) {
        QString buttonNormalStyle = "";
        QString buttonHoverStyle = "";
        QString buttonCheckedStyle = "";
        QString buttonNormalImgStyle = QString("background-image: url(C:/Users/ZAC/Documents/Aniclip/trunk/AniClip/resources/%1);").arg(buttonNormal_path);
        QString buttonHoverImgStyle = QString("background-image: url(C:/Users/ZAC/Documents/Aniclip/trunk/AniClip/resources/%1);").arg(buttonHovered_path);
        QString buttonCheckedImgStyle = QString("background-image: url(C:/Users/ZAC/Documents/Aniclip/trunk/AniClip/resources/%1);").arg(buttonChecked_path);

        if (!buttonNormal_path.isEmpty()) {
            buttonNormalStyle = QString ("QPushButton {"
                                         "background-color: transparent;"
                                         "image-position: Center;"
                                         "background-repeat: none;" +
                                         buttonNormalImgStyle +
                                         "border: none;"
                                         "}");
        }

        if (!buttonHovered_path.isEmpty()) {
            buttonHoverStyle = QString ("QPushButton:hover {"
                                        "background-color: transparent;"
                                        "image-position: Center;"
                                        "background-repeat: none;" +
                                        buttonHoverImgStyle +
                                        "border: none;"
                                        "}");
        }

        if (!buttonChecked_path.isEmpty()) {
            buttonCheckedStyle = QString ("QPushButton:pressed {"
                                          "background-color: transparent;"
                                          "image-position: Center;"
                                          "background-repeat: none;" +
                                          buttonCheckedImgStyle +
                                          "border: none;"
                                          "}");
        }
        addScreenButton->setStyleSheet(buttonNormalStyle + buttonHoverStyle + buttonCheckedStyle);
    }



}

void StartScreenWidget::animateClear() {
    buttonBox->setMinimumWidth(0);
    clearButtonsAnimation->start();
}

void StartScreenWidget::animateOn() {

    setButtonPosition(QSize(minButtonBoxWidth, minSize.height()));
    onButtonsAnimation->start();
}

void StartScreenWidget::resizeEvent(QResizeEvent *e) {
    if (infoBox != NULL && buttonBox != NULL && !animationActive_flag) {
        setButtonPosition(buttonBox->size());
    }

    StackedWidget::resizeEvent(e);
}

void StartScreenWidget::setButtonPosition(QSize buttonBoxSize) {
    int border = hButtonBorder;
    int staggerMid = (buttonBoxSize.width() - buttonWidth - border * 2) / 2;
    int vBorder = (buttonBoxSize.height() - buttonHeight * 5) / 6;
    addScreenButton->setGeometry(border, vBorder, 120, 40);
    editScreenButton->setGeometry(border + staggerMid, (vBorder * 2+ buttonHeight), 120, 40);
    miniScreenButton->setGeometry(border + staggerMid * 2, (vBorder * 3+ buttonHeight * 2), 120, 40);
    settingsScreenButton->setGeometry(border + staggerMid, (vBorder * 4 + buttonHeight * 3), 120, 40);
    otherButton->setGeometry(border, (vBorder * 5 + buttonHeight * 4), 120, 40);
}

void StartScreenWidget::onFinishPropertyAnimation_clear() {
    emit finishAnimate_clear();
}

void StartScreenWidget::onFinishPropertyAnimation_on() {
    emit finishAnimate_on();
    buttonBox->setMinimumWidth(minButtonBoxWidth);
}
