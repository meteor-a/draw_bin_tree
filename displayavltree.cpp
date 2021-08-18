#include "displayavltree.h"

DisplayAVLTree::DisplayAVLTree() {
    scene_avl = new QGraphicsScene();
    UpdateSceneAVL();
}

void DisplayAVLTree::inizialize() {
    int max_in_avl = avl_tree.findmax_in_tree()->element;
    int min_in_avl = avl_tree.findmin_in_tree()->element;
    QString tt = "";
    if (QString::number(max_in_avl).length() > QString::number(min_in_avl).length()) {
        tt = QString::number(max_in_avl);
    }
    else {
        tt = QString::number(min_in_avl);
    }
    width_of_ellips = (tt.length() + 1) * 50;
    //SCENE_RECT_HEIGHT = (avl_tree.getFirst()->height) * height_of_ellips + avl_tree.getFirst()->height * interval_beetween_ellips_height;
    SCENE_RECT_WIDTH = std::pow(2, avl_tree.getFirst()->height) * width_of_ellips + (std::pow(2, avl_tree.getFirst()->height) - 1) * interval_beetween_ellips_width;
    SCENE_RECT_HEIGHT = SCENE_RECT_WIDTH;
    scene_avl->setSceneRect(SCENE_RECT_X, SCENE_RECT_Y, SCENE_RECT_WIDTH, SCENE_RECT_HEIGHT);
}

void DisplayAVLTree::update_scene_avl(nodeptr root, qreal x_draw_left, qreal x_draw_right, qreal y_draw, short last_left_or_right) {
    if (root == avl_tree.getFirst()) {
        qreal x_dd = SCENE_RECT_WIDTH / 2.0;
        GraphicEllipseCustom* tee = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, QColor(255, 255, 255), QString::number(root->element), QColor(0, 0, 0));
        connect(tee, SIGNAL(signal1(QString)), this, SLOT(slotFromPoint(QString)));
        scene_avl->addItem(tee);

        update_scene_avl(root->left, 0, x_dd, SCENE_RECT_WIDTH / 4.0, 1);
        update_scene_avl(root->right, x_dd, SCENE_RECT_WIDTH, SCENE_RECT_WIDTH / 4.0, 2);
    }
    else if (root != NULL) {
        qreal x_dd = x_draw_left + (x_draw_right - x_draw_left) / 2.0;
        GraphicEllipseCustom* tee = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, QColor(255, 255, 255), QString::number(root->element), QColor(0, 0, 0));
        connect(tee, SIGNAL(signal1(QString)), this, SLOT(slotFromPoint(QString)));
        scene_avl->addItem(tee);

        qreal ostr = 0.25;
        if (last_left_or_right == 1) {
            scene_avl->addLine(x_draw_right, y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips, x_dd, y_draw); // главная диния стрелки

            qreal x_ = x_dd - x_draw_right;
            qreal y_ = y_draw - (y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips);

            qreal lons = 20;
            qreal ugol = atan2(y_, x_);

            qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
            qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
            scene_avl->addLine(x_dd, y_draw, f1x2_, f1y2_);

            f1x2_ = x_dd - lons * cos(ugol + ostr);
            f1y2_ = y_draw - lons * sin(ugol + ostr);
            scene_avl->addLine(x_dd, y_draw, f1x2_, f1y2_);
        }
        else if (last_left_or_right == 2) {
            scene_avl->addLine(x_draw_left, y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips, x_dd, y_draw);

            qreal x_ = x_dd - x_draw_left;
            qreal y_ = y_draw - (y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips);

            qreal lons = 20;
            qreal ugol = atan2(y_, x_);

            qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
            qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
            scene_avl->addLine(x_dd, y_draw, f1x2_, f1y2_);

            f1x2_ = x_dd - lons * cos(ugol + ostr);
            f1y2_ = y_draw - lons * sin(ugol + ostr);
            scene_avl->addLine(x_dd, y_draw, f1x2_, f1y2_);
        }

        update_scene_avl(root->left, x_draw_left, x_dd, y_draw + (x_dd - x_draw_left) / 2.0, 1);
        update_scene_avl(root->right, x_dd, x_draw_right, y_draw + (x_draw_right - x_dd) / 2.0, 2);
    }
}

void DisplayAVLTree::slotFromPoint(QString text) {
    emit signal2(text);
}