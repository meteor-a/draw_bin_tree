#ifndef DISPLAYFINDTREE_H
#define DISPLAYFINDTREE_H

#include <QObject>
#include <QGraphicsView>
#include <graphicellipsecustom.h>
#include "FindTree.h"
#include <cmath>

class displayfindtree : public QObject
{
    Q_OBJECT
public:
    
    displayfindtree();
    
    void UpdateSceneFindTree() {
        if (find_tree.getFirst() != NULL) {
            scene_find_tree->clear();
            inizialize();
            update_scene_treefind(find_tree.getFirst(), 0, SCENE_RECT_WIDTH, 0, 0);
        }
        else {
            scene_find_tree->clear();
        }
    }

    FindTree* getFindTree() { return &find_tree; }

    QGraphicsScene* GetSceneFindTree() { return scene_find_tree; }

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

    QGraphicsScene* scene_find_tree;
    FindTree find_tree;

    void update_scene_treefind(TreeNode*, qreal, qreal, qreal, short);
    void inizialize();

private slots:
     //Слот для обработки сигнала из точки */
    void slotFromPoint(QString);
    
};

#endif // DISPLAYFINDTREE_H
