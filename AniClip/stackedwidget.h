#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QWidget>
#include <QSize>

class StackedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StackedWidget(QWidget *parent = 0);

    QSize getMinSize();
    QSize getMaxSize();

    QSize minSize;
    QSize maxSize;

signals:

public slots:
};

#endif // STACKEDWIDGET_H
