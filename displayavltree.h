#ifndef DISPLAYAVLTREE_H
#define DISPLAYAVLTREE_H

#include <avl_tree.h>
#include <QGraphicsView>
#include <graphicellipsecustom.h>

class DisplayAVLTree : public QObject
{
    Q_OBJECT
public:
    DisplayAVLTree();

    void UpdateSceneAVL() {
        if (avl_tree.getFirst() != NULL) {
            scene_avl->clear();
            inizialize();
            update_scene_avl(avl_tree.getFirst(), 0, SCENE_RECT_WIDTH, 0, 0);
        }
        else {
            scene_avl->clear();
        }
    }

    avl_tree *getAVLTree() { return &avl_tree; }

    QGraphicsScene *GetSceneAVL() { return scene_avl; }

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

    QGraphicsScene *scene_avl;
    avl_tree avl_tree;

    void update_scene_avl(nodeptr, qreal, qreal, qreal, short);
    void inizialize();

private slots:
    /* Слот для обработки сигнала из точки */
    void slotFromPoint(QString);
};

#endif // DISPLAYAVLTREE_H
