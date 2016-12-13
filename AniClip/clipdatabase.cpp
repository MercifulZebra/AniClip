#include "clipdatabase.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

#include "logger.h"

Clip::Clip(QObject *parent) : QObject(parent),
    show_name(),
    episode_num(),
    air_season(),
    start_time(),
    end_time(),
    tags(),
    notes(),
    link(),
    source()
{

}

QString Clip::seasonToString(Season s)
{
    QString textString = "";

    if(s == SEASON_FALL) {
        textString = "Fall";
    }
    else if (s == SEASON_WINTER) {
        textString = "Winter";
    }
    else if (s == SEASON_SPRING) {
        textString = "Spring";
    }
    else if (s == SEASON_SUMMER) {
        textString = "Summer";
    }
    else {
        textString = "Unknown";
    }

    return textString;
}

bool Clip::compareInfo(QString nName, int nNum, AirSeason nSeason, QTime nStart, QTime nEnd, QStringList nTags, QString nNote, QString nLink, QString nSource)
{
    bool infoChanged_flag = false;

    if (nName != show_name) {
        infoChanged_flag = true;
    }

    if (nNum != episode_num) {
        infoChanged_flag = true;
    }

    if (nSeason.year != air_season.year) {
        infoChanged_flag = true;
    }

    if (nSeason.season != air_season.season) {
        infoChanged_flag = true;
    }

    if (nStart != start_time) {
        infoChanged_flag = true;
    }

    if (nEnd != end_time) {
        infoChanged_flag = true;
    }

    if (nTags != tags) {
        infoChanged_flag = true;
    }

    if (nNote != notes) {
        infoChanged_flag = true;
    }

    if (nLink != link) {
        infoChanged_flag = true;
    }

    if (nSource != source) {
        infoChanged_flag = true;
    }

    return infoChanged_flag;
}

ShowGroup::ShowGroup(QObject *parent) : QObject(parent) ,
    clips(),
    show_name()
{

}

ClipList::ClipList(QObject *parent) : QObject(parent)
{

}

ClipDatabase::ClipDatabase(QObject *parent) : QObject(parent)
{

}

void ClipDatabase::init(QString config_filename, logger::Logger *nLog) {

    log = nLog;

    QFile nFile(config_filename);
    if (nFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream nStream(&nFile);

        while (!nStream.atEnd()) {

            QString line = nStream.readLine();
            if (!line.startsWith("#") && !line.isEmpty()) {
                QStringList split = line.split(QRegExp("\\s+"));

                if (split.count() > 1) {
                    if (split.at(0) == "database_filename") {
                        databaseFilename = split.at(1);
                    }
                }

            }
        }
    }

    if (!databaseFilename.isEmpty()) {
        loadDatabase(databaseFilename, main_list);
    }
    else {
        log->warn("No initial database found");
    }
}

void ClipDatabase::loadDatabase(QString database_filename, ClipList* target_list) {
    bool rButton = true;

    if (target_list != main_list) {

        QMessageBox sBox(QMessageBox::Question, "Load Database?", "Merge Files to Database?", QMessageBox::Ok | QMessageBox::Cancel, this);
        rButton = sBox.exec();
    }

    if (rButton) {
        if (target_list != NULL) {
            QFile nFile(database_filename);
            if (nFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream nStream(&nFile);

                while (!nStream.atEnd()) {

                }
            }
        }
        else {
            log->warn("loadDatabase: Target List is NULL");
        }
    }

}

void ClipDatabase::saveDatabase() {
    //Write to file

    //copy to backup file
}

void ClipDatabase::importShows(QString filename) {
    QFile nFile(filename);
    int count = 0;
    if (nFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream nStream(&nFile);

        while (!nStream.atEnd()) {

            QString line = nStream.readLine();
            if (!line.isEmpty() && line.contains(QString("<series_title>"))) {
                int startBound = line.indexOf("<![CDATA[");
                int boundLength = 9;
                int endBound = line.indexOf("]]></series_title");

                QString title = line.mid(startBound + boundLength, endBound - (startBound + boundLength));
                showList.append(title);
            }
        }
    }
}

Clip* ClipDatabase::addNewClip() {

}

