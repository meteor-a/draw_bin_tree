#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QGraphicsView>
#include <QMessageBox>
#include <QWheelEvent>
#include <ctime>
#include <random>
#include "displayavltree.h"
#include <qmenu.h>
#include <qcolor.h>
#include "displayredblacktree.h"
#include "dialogeditadd.h"
#include "graphviewcustom.h"
#include <qpushbutton.h>
#include <QHBoxLayout>
#include "displayfindtree.h"
#include "displayfindtree.h"
#include "displaytwotreetree.h"
#include "dialogsetrange.h"
#include "dialogerror.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QVBoxLayout  *vertical_layout;
    QHBoxLayout* horizont_layout;
    GraphViewCustom *graph_view;
    QWidget *window;
    QLabel *label;
    QLabel* label_num_of_elems;
    QPushButton* button_next_tree;
    QPushButton* button_prev_tree;
    QPushButton* button_regen_trees;
    QMetaObject::Connection myConnectAVL;

    const int NUMBER_OF_START_ELEM__ = 4;
    QGraphicsScene* scene = new QGraphicsScene;

    short TREE_SHOW_NOW = 1; //1 - AVL // 2 - RedBlackTree ; 3 - FindTree // 4 - 2-3 Tree

    short NUM_OF_TREES = 4;

    DisplayAVLTree display_avl;
    displayRedBlackTree display_redblack;
    displayfindtree display_find_tree;
    displaytwotreetree display_twotreetree;

    void init_all_tree();
    std::mt19937 seed;

    void show_context_menu_top();

    QString getFirstNum();

    QString getSecondNum();

    void show_context_menu_widget();

    void Update_Showing_Tree();

    QString text_elem_action;
    QString first_num_delete;
    QString second_num_delete;

    long long NUMBER_OF_ELEMS;
    int MIN_GEN;
    int MAX_GEN;
    //void keyPressEvent(QKeyEvent* e);

private slots:
    // Слот для обработки сигнала нажатия  по вершине
    void slotFromPoint2_(QString);

    // слот обработки удаления вершины
    void slotDelete();
    void slotDelete_number_1();
    void slotDelete_number_2();

    void slotEditRecord();
    void slotEditRecord_number_1();
    void slotEditRecord_number_2();

    void slotAddOneElem();

    void slotAddManyElems();

    void slotNextTree();

    void slotPrevTree();
    void slotRegenTrees();

    void slotMouseDoubleClickCustom();

    bool Check_Correct_Digit(QString text);

};

#endif // MAINWINDOW_H
