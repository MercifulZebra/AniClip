#ifndef ADDSCREENWIDGET_H
#define ADDSCREENWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDateTimeEdit>

#include "stackedwidget.h"

class AddScreenWidget : public StackedWidget
{
    Q_OBJECT
public:
    explicit AddScreenWidget(QWidget *parent = 0);
    bool init(QString config_filename, logger::Logger *nLog);

    void updateImages();

    QGridLayout *mainLayout;

    QWidget *topBar;
    QWidget *editWidget;
    QWidget *tagDispWidget;
    QWidget *clipDispWidget;

    //Top Bar
    QPushButton* returnButton;



signals:

public slots:
};

#endif // ADDSCREENWIDGET_H
