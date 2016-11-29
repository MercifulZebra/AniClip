#ifndef STACKEDWIDGET_H
#define STACKEDWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QSize>

class StackedWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit StackedWidget(QWidget *parent = 0);

    virtual void animateClear();
    virtual void animateOn();

    void setAnimating(bool flag);

    void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;

    QSize getMinSize();
    QSize getMaxSize();

    QSize minSize;
    QSize maxSize;

    QImage backgroundImg;
    bool animationActive_flag;


signals:
    void finishAnimate_clear();
    void finishAnimate_on();
public slots:
};

#endif // STACKEDWIDGET_H
