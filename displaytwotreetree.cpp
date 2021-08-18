#include "displaytwotreetree.h"

displaytwotreetree::displaytwotreetree() {
    scene_tree23_ = new QGraphicsScene();
}

void displaytwotreetree::inizialize_twotree() {
    int min_in_tree = *tree23_tree.getMinNode(tree23_tree.getFirst())->getBigKey();
    int max_long_in_tree = *tree23_tree.getMaxNode(tree23_tree.getFirst())->getBigKey();
    QString tt;
    if (QString::number(max_long_in_tree).length() > QString::number(min_in_tree).length()) {
        tt = QString::number(max_long_in_tree);
    }
    else {
        tt = QString::number(min_in_tree);
    }
    width_of_ellips = (tt.length() + 1) * 50 * 2 + 40;
    SCENE_RECT_HEIGHT = (tree23_tree.HeightOfTree()) * height_of_ellips + tree23_tree.HeightOfTree() * interval_beetween_ellips_height;
    SCENE_RECT_WIDTH = std::pow(3, tree23_tree.HeightOfTree()) * width_of_ellips + (std::pow(3, tree23_tree.HeightOfTree() - 1)) * interval_beetween_ellips_width;
    scene_tree23_->setSceneRect(SCENE_RECT_X, SCENE_RECT_Y, SCENE_RECT_WIDTH, SCENE_RECT_HEIGHT);
}

void displaytwotreetree::update_scene_twotreetree(CNode<int>* root, qreal x_draw_left, qreal x_draw_right, qreal y_draw, short last_left_mid_right) {

    if (root != NULL) {
        if (root == tree23_tree.getFirst()) {
            qreal x_dd = SCENE_RECT_WIDTH / 2.0;
            QColor color_of_ellips = QColor(0, 0, 0);
            QColor text_color = QColor(255, 255, 255);
            QString text_ellps = "";
            int num__;
            if (root->isSmallKeySet()) {
                num__ = *root->getSmallKey();
                text_ellps += QString::number(num__);
                if (root->isBigKeySet()) {
                    num__ = *root->getBigKey();
                    text_ellps += " ; " + QString::number(num__);
                }
            }
            else {
                if (root->isBigKeySet()) {
                    num__ = *root->getBigKey();
                    text_ellps += QString::number(num__);
                }
            }
            
            GraphicEllipseCustom* tee2_ = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, color_of_ellips, text_ellps, text_color);
            connect(tee2_, SIGNAL(signal1(QString)), this, SLOT(slotFromPointTwoTree(QString)));
            scene_tree23_->addItem(tee2_);

            update_scene_twotreetree(root->getChild(leftChild), 0, SCENE_RECT_WIDTH / 3.0, y_draw + interval_beetween_ellips_height, 0);
            update_scene_twotreetree(root->getChild(middleChild), SCENE_RECT_WIDTH / 3.0, SCENE_RECT_WIDTH / 3.0 * 2, y_draw + interval_beetween_ellips_height, 1);
            update_scene_twotreetree(root->getChild(rightChild), SCENE_RECT_WIDTH / 3.0 * 2, SCENE_RECT_WIDTH, y_draw + interval_beetween_ellips_height, 2);
        }
       else {
            qreal x_dd = x_draw_left + (x_draw_right - x_draw_left) / 2.0;
            QColor color_of_ellips = QColor(0, 0, 0);
            QColor text_color = QColor(255, 255, 255);

            QString text_ellps = "";
            int num__;
            if (root->isSmallKeySet()) {
                num__ = *root->getSmallKey();
                text_ellps += QString::number(num__);
                if (root->isBigKeySet()) {
                    num__ = *root->getBigKey();
                    text_ellps += " ; " + QString::number(num__);
                }
            }
            else {
                if (root->isBigKeySet()) {
                    num__ = *root->getBigKey();
                    text_ellps += QString::number(num__);
                }
            }

            GraphicEllipseCustom* tee2_ = new GraphicEllipseCustom(x_dd - width_of_ellips / 2.0, y_draw, width_of_ellips, height_of_ellips, color_of_ellips, text_ellps, text_color);
            connect(tee2_, SIGNAL(signal1(QString)), this, SLOT(slotFromPointTwoTree(QString)));
            scene_tree23_->addItem(tee2_);

            
            qreal ostr = 0.25;
            if (last_left_mid_right == 1) {
                scene_tree23_->addLine(x_dd, y_draw - interval_beetween_ellips_height + height_of_ellips, x_dd, y_draw); // главная диния стрелки
                qreal x_ = x_dd;
                qreal y_ = y_draw - (y_draw - interval_beetween_ellips_height + height_of_ellips);

                ostr = 0.8;
                qreal lons = 20;
                qreal ugol = atan2(y_, x_);

                qreal f1x2_ = x_dd - lons * cos(ugol + ostr);
                qreal f1y2_ = y_draw - lons * sin(ugol + ostr);
                scene_tree23_->addLine(x_dd, y_draw, f1x2_, f1y2_);
                scene_tree23_->addLine(x_dd, y_draw, x_dd + (x_dd - f1x2_), f1y2_);
            }
            else if (last_left_mid_right == 0) {
                scene_tree23_->addLine(x_draw_right + (x_draw_right - x_draw_left) / 2.0, y_draw - interval_beetween_ellips_height + height_of_ellips, x_dd, y_draw); // главная диния стрелки

                qreal x_ = x_dd - x_draw_right;
                qreal y_ = y_draw - (y_draw - interval_beetween_ellips_height + height_of_ellips);

                qreal lons = 20;
                qreal ugol = atan2(y_, x_);

                qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
                qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
                scene_tree23_->addLine(x_dd, y_draw, f1x2_, f1y2_);

                f1x2_ = x_dd - lons * cos(ugol + ostr);
                f1y2_ = y_draw - lons * sin(ugol + ostr);
                scene_tree23_->addLine(x_dd, y_draw, f1x2_, f1y2_);
            }
            else if (last_left_mid_right == 2) {
                scene_tree23_->addLine(x_draw_left - (x_draw_right - x_draw_left) / 2.0, y_draw - interval_beetween_ellips_height + height_of_ellips, x_dd, y_draw);

                qreal x_ = x_dd - x_draw_left;
                qreal y_ = y_draw - (y_draw - interval_beetween_ellips_height + height_of_ellips);

                qreal lons = 20;
                qreal ugol = atan2(y_, x_);

                qreal f1x2_ = x_dd - lons * cos(ugol - ostr);
                qreal f1y2_ = y_draw - lons * sin(ugol - ostr);
                scene_tree23_->addLine(x_dd, y_draw, f1x2_, f1y2_);

                f1x2_ = x_dd - lons * cos(ugol + ostr);
                f1y2_ = y_draw - lons * sin(ugol + ostr);
                scene_tree23_->addLine(x_dd, y_draw, f1x2_, f1y2_);
            }
            

            update_scene_twotreetree(root->getChild(leftChild), x_draw_left, (x_draw_right - x_draw_left) / 3.0 + x_draw_left, y_draw + interval_beetween_ellips_height, 0);
            update_scene_twotreetree(root->getChild(middleChild), (x_draw_right - x_draw_left) / 3.0 + x_draw_left, ((x_draw_right - x_draw_left) / 3.0) * 2 + x_draw_left, y_draw + interval_beetween_ellips_height, 1);
            update_scene_twotreetree(root->getChild(rightChild), ((x_draw_right - x_draw_left) / 3.0) * 2 + x_draw_left, x_draw_right, y_draw + interval_beetween_ellips_height, 2);
        }
    }
}

void displaytwotreetree::slotFromPointTwoTree(QString text) {
    emit signal2(text);
}
