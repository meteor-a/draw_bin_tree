#ifndef DISPLAYTWOTREETREE_H
#define DISPLAYTWOTREETREE_H

#include <QObject>
#include <QGraphicsView>
#include <cmath>
#include <graphicellipsecustom.h>
#include <CTree.h>

class displaytwotreetree : public QObject
{
    Q_OBJECT
public:
    displaytwotreetree();

    void UpdateTwoTreeTree() {
        if (tree23_tree.getFirst() != NULL) {
            scene_tree23_->clear();
            inizialize_twotree();
            update_scene_twotreetree(tree23_tree.getFirst(), 0, SCENE_RECT_WIDTH, 0, 0);
        }
        else {
            scene_tree23_->clear();
        }
    }

    QGraphicsScene* GetSceneTwoTreeTree() { return scene_tree23_; }

    CTree<int>* getTwoTreeTree() { return &tree23_tree; }

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

    QGraphicsScene* scene_tree23_;
    CTree<int> tree23_tree;

    void update_scene_twotreetree(CNode<int>*, qreal, qreal, qreal, short);
    void inizialize_twotree();

private slots:
    /* Слот для обработки сигнала из точки */
    void slotFromPointTwoTree(QString);
};

#endif // DISPLAYTWOTREETREE_H
