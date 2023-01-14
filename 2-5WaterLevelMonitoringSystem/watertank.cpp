#include "watertank.h"
#include <QPen>
#include <QPainter>
#include <QWheelEvent>

WaterTank::WaterTank(QWidget *parent)
    : QWidget{parent},
      waterHeight(50),
      timer(new QTimer(this))
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, [=](){
       waterHeight += 10;
       update();

       // Emit signals
       if (waterHeight <= 210) {
           emit normal();
       } else if ((waterHeight >= 211) && (waterHeight <= 239)) {
           emit warning();
       } else {
           emit danger();
       }
    });

    timer->start();
}

void WaterTank::paintEvent(QPaintEvent *event)
{
    // Setup painter
    QPen mPen;
    mPen.setWidth(3);
    mPen.setColor(Qt::black);

    // Draw the tank
    QPainter painter(this);
    painter.drawLine(10, 10, 10, 300);      // Left
    painter.drawLine(10, 300, 300, 300);    // Bottom
    painter.drawLine(300, 300, 300, 10);    // Right

    // Draw the water
    painter.setBrush(Qt::blue);
    painter.drawRect(10, 300 - waterHeight, 290, waterHeight);

}

QSize WaterTank::sizeHint() const
{
    return QSize(400, 400);
}

void WaterTank::wheelEvent(QWheelEvent *event)
{
    if (event->delta() < 0 && (waterHeight > 10)) {
        waterHeight -= 10;
        update();
    }
}
