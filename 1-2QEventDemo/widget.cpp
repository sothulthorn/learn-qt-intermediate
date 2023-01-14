#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Pressed at " << event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Moved at " << event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << "Mouse Released at " << event->pos();
}

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug() << "Widget about to close";
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug() << "ContextMenu Event";
    QMenu *mMenu = new QMenu(this);
    mMenu->addAction(tr("Action1"));
    mMenu->addAction(tr("Action2"));

    mMenu->popup(mapToGlobal(event->pos()));

    qDebug() << "Event x : " << event->x() << " event y : " << event->y();

    qDebug() << "Envent reason : " << event->reason();
}

void Widget::wheelEvent(QWheelEvent *event)
{

}



