#include "graphicellipsecustom.h"

GraphicEllipseCustom::GraphicEllipseCustom(QObject *parent) : QObject(parent), QGraphicsItem()
{
}

GraphicEllipseCustom::GraphicEllipseCustom(qreal x, qreal y, qreal width, qreal height, QColor col_ell, QString tt, QColor tt_col) {
    x__ = x;
    y__ = y;
    width__ = width;
    height__ = height;
    color_ellipse__ = col_ell;
    text__ = tt;
    text_color__ = tt_col;
}

GraphicEllipseCustom::GraphicEllipseCustom(qreal x, qreal y, qreal width, qreal height, QColor col_ell, QString tt) {
    x__ = x;
    y__ = y;
    width__ = width;
    height__ = height;
    color_ellipse__ = col_ell;
    text__ = tt;
    text_color__ = QColor(0, 0, 0);
}

GraphicEllipseCustom::~GraphicEllipseCustom() {
}

QRectF GraphicEllipseCustom::boundingRect() const
{
    return QRectF(x__, y__, width__, height__);
}

void GraphicEllipseCustom::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setBrush(color_ellipse__);
    painter->drawEllipse(QRectF(x__, y__, width__, height__));
    int count_symb_in_text = text__.length();
    painter->setPen(text_color__);
    QFont font = painter->font();
    font.setPointSize(60);
    painter->setFont(font);
   // painter->drawText(QRectF(x__ + 20, y__, width__, height__), text__, Qt::AlignCenter);
    painter->drawText(x__, y__, width__, height__, Qt::AlignCenter, text__);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


/* Переопределив метод перехвата события нажатия кнопки мыши,
 * добавляем посылку СИГНАЛА от объекта
 * */
void GraphicEllipseCustom::mousePressEvent(QGraphicsSceneMouseEvent* event) {
   QGraphicsItem::mousePressEvent(event);
   if (event->buttons() & Qt::RightButton) {
       emit signal1(text__);
   }
}

