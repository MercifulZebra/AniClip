#ifndef CLIPDATABASE_H
#define CLIPDATABASE_H

#include <QObject>
#include <QTime>

enum Season {
    SPRING,
    SUMMER,
    FALL,
    WINTER
};

struct AirSeason {
    AirSeason() : year(2000), season(Season::SPRING) {}
    int year;
    Season season;
};

class Clip : public QObject
{
    Q_OBJECT
public:
    explicit Clip(QObject *parent = 0);

    static QString seasonToString(Season s);

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

class ClipList : public QObject
{
    Q_OBJECT
public:
    explicit ClipList(QObject *parent = 0);

signals:

public slots:
};

class ClipDatabase : public QObject
{
    Q_OBJECT
public:
    explicit ClipDatabase(QObject *parent = 0);

signals:

public slots:
};

#endif // CLIPDATABASE_H
