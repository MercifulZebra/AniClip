#include "styletypes.h"

#include "logger.h"

#include <QFile>

using namespace style;

QString style::generateButtonStyle(QString base_path, QString default_path, logger::Logger *log) {
    QString rStyle = "";

    QString defaultNormal_path = default_path;
    QString defaultHovered_path = default_path;
    defaultHovered_path.insert(base_path.length() - 4, "_hover");
    QString defaultClicked_path = default_path;
    defaultClicked_path.insert(base_path.length() - 4, "_click");

    QString buttonNormal_path = base_path;
    QString buttonHovered_path = base_path;
    buttonHovered_path.insert(base_path.length() - 4, "_hover");
    QString buttonClicked_path = base_path;
    buttonClicked_path.insert(base_path.length() - 4, "_click");

    QFile tempFile;

    tempFile.setFileName(buttonNormal_path);
    if (!tempFile.exists()) {
        log->warn(QString("Button Image %1 does not exist. Using default.").arg(tempFile.fileName()));
        buttonNormal_path = defaultNormal_path;
    }
    tempFile.setFileName(buttonHovered_path);
    if (!tempFile.exists()) {
        log->warn(QString("Button Image %1 does not exist. Using default.").arg(tempFile.fileName()));
        buttonNormal_path = defaultHovered_path;
    }

    tempFile.setFileName(buttonClicked_path);
    if (!tempFile.exists()) {
        log->warn(QString("Button Image %1 does not exist. Using default.").arg(tempFile.fileName()));
        buttonClicked_path = defaultClicked_path;
    }

    QString buttonNormalStyle = "";
    QString buttonNormalImgStyle = QString("background-image: url(%1);").arg(buttonNormal_path);

    buttonNormalStyle = QString ("QPushButton {"
                                 "background-color: transparent;"
                                 "image-position: Center;"
                                 "background-repeat: none;" +
                                 buttonNormalImgStyle +
                                 "border: none;"
                                 "}");

    rStyle += buttonNormalStyle;


    QString buttonHoverStyle = "";
    QString buttonHoverImgStyle = QString("background-image: url(%1);").arg(buttonHovered_path);

    buttonHoverStyle = QString ("QPushButton:hover {"
                                "background-color: transparent;"
                                "image-position: Center;"
                                "background-repeat: none;" +
                                buttonHoverImgStyle +
                                "border: none;"
                                "}");

    rStyle += buttonHoverStyle;


    QString buttonCheckedStyle = "";
    QString buttonCheckedImgStyle = QString("background-image: url(%1);").arg(buttonClicked_path);

    buttonCheckedStyle = QString ("QPushButton:pressed {"
                                  "background-color: transparent;"
                                  "image-position: Center;"
                                  "background-repeat: none;" +
                                  buttonCheckedImgStyle +
                                  "border: none;"
                                  "}");

    rStyle += buttonCheckedStyle;

    log->trace(rStyle);
    return rStyle;
}
