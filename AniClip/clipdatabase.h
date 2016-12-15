#ifndef CLIPDATABASE_H
#define CLIPDATABASE_H

#include <QObject>
#include <QTime>
#include <QVector>


namespace logger {
    class Logger;
}

enum Season {
    SEASON_SPRING,
    SEASON_SUMMER,
    SEASON_FALL,
    SEASON_WINTER
};

struct AirSeason {
    AirSeason() : year(2000), season(Season::SEASON_SPRING) {}
    int year;
    Season season;
};

class Clip : public QObject
{
    Q_OBJECT
public:
    explicit Clip(QObject *parent = 0);

    static QString seasonToString(Season s);
    bool compareInfo(QString nName, int nNum, AirSeason nSeason, QTime nStart, QTime nEnd, QStringList nTags, QString nNote, QString nLink, QString nSource);

    QStringList clipFromString(QString clipString);

    QString     show_name;
    int         episode_num;
    AirSeason   air_season;

    QTime       start_time;
    QTime       end_time;

    QStringList tags;
    QString     notes;
    QString     link;
    QString     source;


signals:

public slots:
};

class ShowGroup : public QObject
{
    explicit ShowGroup(QObject *parent = 0);

    QVector<Clip*> clips;
    QString show_name;
};

class ClipList : public QObject
{
    Q_OBJECT
public:
    explicit ClipList(QObject *parent = 0);

    logger::Logger *log;

    QVector<ShowGroup*>  shows;
    QString         list_name;
signals:

public slots:
};

class ClipDatabase : public QObject
{
    Q_OBJECT
public:
    explicit ClipDatabase(QObject *parent = 0);

    void init(QString config_filename, logger::Logger *nLog);
    void loadDatabase(QString database_filename, ClipList* target_list);
    void saveDatabase();

    void importShows(QString filename);

    Clip* addNewClip();

    logger::Logger *log;

    //
    ClipList* main_list;
    QVector<ClipList*> lists;
    QString databaseFilename;
    QString backupFilename;
    QStringList showList;



signals:

public slots:
};

#endif // CLIPDATABASE_H
