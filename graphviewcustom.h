#ifndef GRAPHVIEWCUSTOM_H
#define GRAPHVIEWCUSTOM_H

#include <QGraphicsView>
#include <QWheelEvent>

class GraphViewCustom : public QGraphicsView
{
    Q_OBJECT
public:
    GraphViewCustom(QWidget *pwgt=0): QGraphicsView (pwgt) {
    }


protected:
    virtual void wheelEvent(QWheelEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

private:
    void scaleView(qreal scaleFactor);

signals:
    void signalDoubleClick();
};

#endif // GRAPHVIEWCUSTOM_H
