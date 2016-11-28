#ifndef CENTRALSTACKWIDGET_H
#define CENTRALSTACKWIDGET_H

#include <QWidget>
#include <QStackedWidget>

class StartScreenWidget;
class AddScreenWidget;

class CentralStackWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit CentralStackWidget(QWidget *parent = 0);
    bool init(QString config_filename);

    void changeCurrentPage(int index);

    StartScreenWidget *startScreen;
    int startScreen_index;

    AddScreenWidget *addScreen;
    int addScreen_index;

signals:
    void requestSizeBound(int minHeight, int minWidth, int maxHeight, int maxWidth);

public slots:
    void setStartScreen();
    void setAddScreen();
};

#endif // CENTRALSTACKWIDGET_H
