#include "stackedwidget.h"

StackedWidget::StackedWidget(QWidget *parent) : QWidget(parent),
    minSize(500,500),
    maxSize(500,500)
{

}

QSize StackedWidget::getMinSize() {
    return minSize;
}

QSize StackedWidget::getMaxSize() {
    return maxSize;
}
