#ifndef GRAPHICELLIPSECUSTOM_H
#define GRAPHICELLIPSECUSTOM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class GraphicEllipseCustom : public QObject, public QGraphicsItem {
    Q_OBJECT
public:
    explicit GraphicEllipseCustom(QObject *parent = 0);
    explicit GraphicEllipseCustom(qreal x, qreal y, qreal width, qreal height, QColor col_ell, QString tt, QColor tt_col);
    explicit GraphicEllipseCustom(qreal x, qreal y, qreal width, qreal height, QColor col_ell, QString tt);
    ~GraphicEllipseCustom();

signals:
    void signal1(QString);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int x__;
    int y__;
    int width__;
    int height__;
    QColor color_ellipse__;
    QColor text_color__;
    QString text__;

};

#endif // GRAPHICELLIPSECUSTOM_H
