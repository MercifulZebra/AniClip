#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString config_filename = "aniclip_config.txt";

    if (argc > 1) {
        config_filename = QString::fromLatin1(argv[1]);
    }

    if (w.init(config_filename)) {
        w.show();
        return a.exec();
    }
    else {
        printf("ERROR - Unable to initialize.\n");
        return 0;
    }

}
