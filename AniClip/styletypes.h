#ifndef STYLETYPES_H
#define STYLETYPES_H

#include <QString>


namespace logger {
    class Logger;
}

namespace style {

struct ButtonStyle {
    QString button_style;

    QString base_path;
};

QString generateButtonStyle(QString base_path, QString default_path, logger::Logger *log);

}

#endif // STYLETYPES_H
