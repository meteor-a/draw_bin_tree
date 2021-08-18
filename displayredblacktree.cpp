#include "displayredblacktree.h"

displayRedBlackTree::displayRedBlackTree() {
    scene_redblack = new QGraphicsScene();
    //UpdateSceneRedBlack();
}

void displayRedBlackTree::inizialize_redblack() {
    int min_in_redblack = redblack_tree.minimum(redblack_tree.getFirst())->key;
    int max_in_redblack = redblack_tree.maximum(redblack_tree.getFirst())->key;
    QString tt = "";
    if (QString::number(max_in_redblack).length() > QString::number(min_in_redblack).length()) {
        tt = QString::number(max_in_redblack);
    }
    else {
        tt = QString::number(min_in_redblack);
    }
    width_of_ellips = (tt.length() + 1) * 50;
   // SCENE_RECT_HEIGHT = (redblack_tree.getMaxHeight()) * height_of_ellips + redblack_tree.getMaxHeight() * interval_beetween_ellips_height;
    SCENE_RECT_WIDTH = std::pow(2, redblack_tree.getMaxHeight()) * width_of_ellips + (std::pow(2, redblack_tree.getMaxHeight()) - 1) * interval_beetween_ellips_width;
    SCENE_RECT_HEIGHT = SCENE_RECT_WIDTH;

    scene_redblack->setSceneRect(SCENE_RECT_X, SCENE_RECT_Y, SCENE_RECT_WIDTH, SCENE_RECT_HEIGHT);
}

void displayRedBlackTree::update_scene_redblack(NodePtrRB root, qreal x_draw_left, qreal x_draw_right, qreal y_draw, short last_left_or_right) {
    if (root != NULL) {
        if (!(root->key == 0 && root->left == NULL && root->right == NULL)) {
            if (root == redblack_tree.getFirst()) {
                qreal x_dd = SCENE_RECT_WIDTH / 2.0;
                QColor color_of_ellips;
                QColor text_color;
                if (root->color == 0) {
                    text_color = QColor(255, 255, 255);
                    color_of_ellips = QColor(0, 0, 0);
                }
                else if (root->color == 1) {
                    color_of_ellips = QColor(255, 0, 0);
                    text_color = QColor(0, 0, 0);
                }
                GraphicEllipseCustom* tee2_ = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, color_of_ellips, QString::number(root->key), text_color);
                connect(tee2_, SIGNAL(signal1(QString)), this, SLOT(slotFromPointRedBlack(QString)));
                scene_redblack->addItem(tee2_);

                update_scene_redblack(root->left, 0, x_dd, SCENE_RECT_WIDTH / 4.0, 1);
                update_scene_redblack(root->right, x_dd, SCENE_RECT_WIDTH, SCENE_RECT_WIDTH / 4.0, 2);
            }
            else if (root != NULL) {
                qreal x_dd = x_draw_left + (x_draw_right - x_draw_left) / 2.0;
                QColor color_of_ellips;
                QColor text_color;
                if (root->color == 0) {
                    text_color = QColor(255, 255, 255);
                    color_of_ellips = QColor(0, 0, 0);
                }
                else if (root->color == 1) {
                    color_of_ellips = QColor(255, 0, 0);
                    text_color = QColor(0, 0, 0);
                }
                GraphicEllipseCustom* tee2_ = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, color_of_ellips, QString::number(root->key), text_color);
                connect(tee2_, SIGNAL(signal1(QString)), this, SLOT(slotFromPointRedBlack(QString)));
                scene_redblack->addItem(tee2_);

                qreal ostr = 0.25;
                if (last_left_or_right == 1) {
                    scene_redblack->addLine(x_draw_right, y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips, x_dd, y_draw); // главная диния стрелки

                    qreal x_ = x_dd - x_draw_right;
                    qreal y_ = y_draw - (y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips);

                    qreal lons = 20;
                    qreal ugol = atan2(y_, x_);

                    qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
                    qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
                    scene_redblack->addLine(x_dd, y_draw, f1x2_, f1y2_);

                    f1x2_ = x_dd - lons * cos(ugol + ostr);
                    f1y2_ = y_draw - lons * sin(ugol + ostr);
                    scene_redblack->addLine(x_dd, y_draw, f1x2_, f1y2_);
                }
                else if (last_left_or_right == 2) {
                    scene_redblack->addLine(x_draw_left, y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips, x_dd, y_draw);

                    qreal x_ = x_dd - x_draw_left;
                    qreal y_ = y_draw - (y_draw - (x_draw_right - x_draw_left) / 2.0 + height_of_ellips);

                    qreal lons = 20;
                    qreal ugol = atan2(y_, x_);

                    qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
                    qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
                    scene_redblack->addLine(x_dd, y_draw, f1x2_, f1y2_);

                    f1x2_ = x_dd - lons * cos(ugol + ostr);
                    f1y2_ = y_draw - lons * sin(ugol + ostr);
                    scene_redblack->addLine(x_dd, y_draw, f1x2_, f1y2_);
                }

                update_scene_redblack(root->left, x_draw_left, x_dd, y_draw + (x_dd - x_draw_left) / 2.0, 1);
                update_scene_redblack(root->right, x_dd, x_draw_right, y_draw + (x_draw_right - x_dd) / 2.0, 2);
            }
        }
    }
}

void displayRedBlackTree::slotFromPointRedBlack(QString text) {
    emit signal2(text);
}