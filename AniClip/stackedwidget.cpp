#include "stackedwidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QDebug>

StackedWidget::StackedWidget(QWidget *parent) : QOpenGLWidget(parent),
    minSize(500,500),
    maxSize(500,500),
    backgroundImg(),
    animationActive_flag(false)
{


}

void StackedWidget::animateClear() {
    emit finishAnimate_clear();
}

void StackedWidget::animateOn() {
    emit finishAnimate_on();
}

void StackedWidget::setAnimating(bool flag) {
    animationActive_flag = flag;
}

void StackedWidget::paintEvent(QPaintEvent *e) {
    static int count = 0;
    count++;
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect target(0,0,100,100);
    target.setWidth(backgroundImg.width());
    target.setHeight(backgroundImg.height());
    painter.fillRect(e->rect(), Qt::white);
    painter.drawImage(target, backgroundImg);
    painter.end();

}

void StackedWidget::resizeGL(int width, int height) {
    glViewport(0,0,width,height);
}

QSize StackedWidget::getMinSize() {
    return minSize;
}

QSize StackedWidget::getMaxSize() {
    return maxSize;
}
