#ifndef DISPLAYREDBLACKTREE_H
#define DISPLAYREDBLACKTREE_H

#include <QObject>
#include "RedBlackTree.h"
#include <QGraphicsView>
#include <cmath>
#include <graphicellipsecustom.h>

class displayRedBlackTree : public QObject
{
    Q_OBJECT
public:
    displayRedBlackTree();

    void UpdateSceneRedBlack() {
        if (redblack_tree.getFirst() != redblack_tree.getTNULL()) {
            scene_redblack->clear();
            inizialize_redblack();
            update_scene_redblack(redblack_tree.getFirst(), 0, SCENE_RECT_WIDTH, 0, 0);
        }
        else {
            scene_redblack->clear();
        }
    }

    RBTree*getRedBlackTree() { return &redblack_tree; }

    QGraphicsScene* GetSceneRedBlackTree() { return scene_redblack; }


signals:
    void signal2(QString);

private:
    long long SCENE_RECT_X = 0;
    long long SCENE_RECT_Y = 0;
    long long SCENE_RECT_HEIGHT = 0;
    long long SCENE_RECT_WIDTH = 0;
    int width_of_ellips;
    int height_of_ellips = 100;
    int interval_beetween_ellips_width = 5;
    int interval_beetween_ellips_height = 500;

    QGraphicsScene* scene_redblack;
    RBTree redblack_tree;

    void update_scene_redblack(NodePtrRB, qreal, qreal, qreal, short);
    void inizialize_redblack();

private slots:
    /* Слот для обработки сигнала из точки */
    void slotFromPointRedBlack(QString);
};

#endif // DISPLAYREDBLACKTREE_H
