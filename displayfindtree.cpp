#include "displayfindtree.h"

displayfindtree::displayfindtree() {
    scene_find_tree = new QGraphicsScene();
}

void displayfindtree::inizialize() {

    QString tt = "";
    if (QString::number(find_tree.getMax()).length() > QString::number(find_tree.getMin()).length()) {
        tt = QString::number(find_tree.getMax());
    }
    else {
        tt = QString::number(find_tree.getMin());
    }
    width_of_ellips = (tt.length() + 1) * 50;
    //  SCENE_RECT_HEIGHT = find_tree.HeightOfTree(find_tree.getFirst()) * height_of_ellips + find_tree.HeightOfTree(find_tree.getFirst()) * interval_beetween_ellips_height;
    SCENE_RECT_WIDTH = std::pow(2, find_tree.HeightOfTree(find_tree.getFirst())) * width_of_ellips + (std::pow(2, find_tree.HeightOfTree(find_tree.getFirst())) - 1) * interval_beetween_ellips_width;
    SCENE_RECT_HEIGHT = SCENE_RECT_WIDTH;
    scene_find_tree->setSceneRect(SCENE_RECT_X, SCENE_RECT_Y, SCENE_RECT_WIDTH, SCENE_RECT_HEIGHT);
}

void displayfindtree::update_scene_treefind(TreeNode* root, qreal x_draw_left, qreal x_draw_right, qreal y_draw, short last_left_or_right) {
 
    if (root == find_tree.getFirst()) {
        qreal x_dd = SCENE_RECT_WIDTH / 2.0;
        GraphicEllipseCustom* tee = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, QColor(255, 255, 255), QString::number(root->data), QColor(0, 0, 0));
        connect(tee, SIGNAL(signal1(QString)), this, SLOT(slotFromPoint(QString)));
        scene_find_tree->addItem(tee);

        update_scene_treefind(root->left, 0, x_dd, SCENE_RECT_WIDTH / 4.0, 1);
        update_scene_treefind(root->right, x_dd, SCENE_RECT_WIDTH, SCENE_RECT_WIDTH / 4.0, 2);
    }
    else if (root != NULL) {
        qreal x_dd = x_draw_left + (x_draw_right - x_draw_left) / 2.0;
        GraphicEllipseCustom* tee = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, QColor(255, 255, 255), QString::number(root->data), QColor(0, 0, 0));
        connect(tee, SIGNAL(signal1(QString)), this, SLOT(slotFromPoint(QString)));
        scene_find_tree->addItem(tee);

        qreal ostr = 0.25;
        if (last_left_or_right == 1) {
            scene_find_tree->addLine(x_draw_right, y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips, x_dd, y_draw); // главная диния стрелки

            qreal x_ = x_dd - x_draw_right;
            qreal y_ = y_draw - (y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips);

            qreal lons = 20;
            qreal ugol = atan2(y_, x_);

            qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
            qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
            scene_find_tree->addLine(x_dd, y_draw, f1x2_, f1y2_);

            f1x2_ = x_dd - lons * cos(ugol + ostr);
            f1y2_ = y_draw - lons * sin(ugol + ostr);
            scene_find_tree->addLine(x_dd, y_draw, f1x2_, f1y2_);
        }
        else if (last_left_or_right == 2) {
            scene_find_tree->addLine(x_draw_left, y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips, x_dd, y_draw);

            qreal x_ = x_dd - x_draw_left;
            qreal y_ = y_draw - (y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips);

            qreal lons = 20;
            qreal ugol = atan2(y_, x_);

            qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
            qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
            scene_find_tree->addLine(x_dd, y_draw, f1x2_, f1y2_);

            f1x2_ = x_dd - lons * cos(ugol + ostr);
            f1y2_ = y_draw - lons * sin(ugol + ostr);
            scene_find_tree->addLine(x_dd, y_draw, f1x2_, f1y2_);
        }

        update_scene_treefind(root->left, x_draw_left, x_dd, y_draw + (x_dd - x_draw_left) / 2.0, 1);
        update_scene_treefind(root->right, x_dd, x_draw_right, y_draw + (x_draw_right - x_dd) / 2.0, 2);
    }
    
}

void displayfindtree::slotFromPoint(QString text) {
    emit signal2(text);
}
