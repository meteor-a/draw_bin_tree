#include "graphviewcustom.h"


void GraphViewCustom::wheelEvent(QWheelEvent *event) {
    scaleView(pow(2.0, -event->angleDelta().y() / 240.0));
}

void GraphViewCustom::mouseDoubleClickEvent(QMouseEvent* event) {
    emit signalDoubleClick();
}

void GraphViewCustom::scaleView(qreal scaleFactor) {
    qreal factor = transform()
        .scale(scaleFactor, scaleFactor)
        .mapRect(QRectF(0, 0, 1, 1))
        .width();
    scale(scaleFactor, scaleFactor);
}
