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
    bool init(QString config_filename);

    QGridLayout *mainLayout;

    QWidget *topBar;
    QWidget *editWidget;
    QWidget *tagDispWidget;
    QWidget *clipDispWidget;


signals:

public slots:
};

#endif // ADDSCREENWIDGET_H
