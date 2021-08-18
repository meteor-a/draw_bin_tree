#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    seed.seed(time(0));
    NUMBER_OF_ELEMS = NUMBER_OF_START_ELEM__;
    MIN_GEN = INT32_MIN;
    MAX_GEN = INT32_MAX;
    window = new QWidget();
    label = new QLabel(this);
    label_num_of_elems = new QLabel(this);
    graph_view = new GraphViewCustom(this);
    vertical_layout = new QVBoxLayout();
    horizont_layout = new QHBoxLayout();

    button_next_tree = new QPushButton(u8"Следующее");
    button_prev_tree = new QPushButton(u8"Предыдущее");
    const QSize btnSize = QSize(150, 30);
    button_regen_trees = new QPushButton(u8"Пересоздать деревья");
    button_regen_trees->setFixedSize(btnSize);

    label->setText(u8"AVL ДЕРЕВО");
    QFont font = label_num_of_elems->font();
    font.setPointSize(17);
    label_num_of_elems->setFont(font);
    label_num_of_elems->setText(u8"Дерево содержит: " + QString::number(NUMBER_OF_ELEMS) + u8" элементов" + u8" (от " + QString::number(MIN_GEN) + u8" до " + QString::number(MAX_GEN) + u8")");

    horizont_layout->setAlignment(Qt::AlignCenter);
    horizont_layout->addWidget(button_prev_tree);
    horizont_layout->addWidget(label);
    horizont_layout->addWidget(button_next_tree);
    vertical_layout->addLayout(horizont_layout);
    vertical_layout->addWidget(label_num_of_elems);
    vertical_layout->addWidget(button_regen_trees);
    vertical_layout->addWidget(graph_view);
    window->setLayout(vertical_layout);
    window->show();

    graph_view->setDragMode(QGraphicsView::ScrollHandDrag);
    graph_view->setCacheMode(QGraphicsView::CacheBackground);
    graph_view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graph_view->setRenderHint(QPainter::Antialiasing);
    
    graph_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graph_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    init_all_tree();

    Update_Showing_Tree();

    connect(button_next_tree, SIGNAL(clicked()), this, SLOT(slotNextTree()));
    connect(button_prev_tree, SIGNAL(clicked()), this, SLOT(slotPrevTree()));
    connect(button_regen_trees, SIGNAL(clicked()), this, SLOT(slotRegenTrees()));
    connect(graph_view, SIGNAL(signalDoubleClick()), this, SLOT(slotMouseDoubleClickCustom()));
    connect(&display_avl, SIGNAL(signal2(QString)), this, SLOT(slotFromPoint2_(QString)));
    connect(&display_redblack, SIGNAL(signal2(QString)), this, SLOT(slotFromPoint2_(QString)));
    connect(&display_find_tree, SIGNAL(signal2(QString)), this, SLOT(slotFromPoint2_(QString)));

    connect(&display_twotreetree, SIGNAL(signal2(QString)), this, SLOT(slotFromPoint2_(QString)));
}

MainWindow::~MainWindow() {

}

void MainWindow::init_all_tree() {
    int num_gen;
    std::uniform_int_distribution<int> genRand(MIN_GEN, MAX_GEN);
    for (int ii = 1; ii <= NUMBER_OF_ELEMS; ++ii) {
        num_gen = genRand(seed);
        while (display_find_tree.getFindTree()->is_InTree(num_gen)) {
            num_gen = genRand(seed);
        }
        display_avl.getAVLTree()->insert(num_gen);
        display_redblack.getRedBlackTree()->insert(num_gen);
        display_find_tree.getFindTree()->insert(num_gen);
        display_twotreetree.getTwoTreeTree()->insert(&num_gen);
    }
}

void MainWindow::show_context_menu_top() {
    QMenu* menu = new QMenu(this);
    QAction* editDevice;
    QAction* deleteDevice;
    if (TREE_SHOW_NOW == 4 && text_elem_action.contains(";")) {
        first_num_delete = getFirstNum();
        second_num_delete = getSecondNum();
        editDevice = new QAction(u8"Редактировать " + first_num_delete, this);
        QAction* editDevice_2 = new QAction(u8"Редактировать " + second_num_delete, this);
        deleteDevice = new QAction(u8"Удалить " + first_num_delete, this);
        QAction* deleteDevice_2 = new QAction(u8"Удалить " + second_num_delete, this);
        /* Подключаем СЛОТы обработчики для действий контекстного меню */
        connect(editDevice, SIGNAL(triggered()), this, SLOT(slotEditRecord_number_1()));     // Обработчик вызова диалога редактирования
        connect(editDevice_2, SIGNAL(triggered()), this, SLOT(slotEditRecord_number_2()));     // Обработчик вызова диалога редактирования
        connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotDelete_number_1())); // Обработчик удаления записи
        connect(deleteDevice_2, SIGNAL(triggered()), this, SLOT(slotDelete_number_2())); // Обработчик удаления записи
        /* Устанавливаем действия в меню */
        menu->addAction(editDevice);
        menu->addAction(editDevice_2);
        menu->addAction(deleteDevice_2);
        menu->addAction(deleteDevice);
    }
    else {
        editDevice = new QAction(u8"Редактировать", this);
        deleteDevice = new QAction(u8"Удалить", this);
        /* Подключаем СЛОТы обработчики для действий контекстного меню */
        connect(editDevice, SIGNAL(triggered()), this, SLOT(slotEditRecord()));     // Обработчик вызова диалога редактирования
        connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotDelete())); // Обработчик удаления записи
        /* Устанавливаем действия в меню */
        menu->addAction(editDevice);
        menu->addAction(deleteDevice);
    }

    menu->exec(QCursor::pos());
}

QString MainWindow::getFirstNum() {
    QString ans = "";
    for (int ii = 0; ii < text_elem_action.length(); ++ii) {
        if (text_elem_action[ii] != " ") {
            ans += text_elem_action[ii];
        }
        else {
            return ans;
        }
    }
    return ans;
}

QString MainWindow::getSecondNum() {
    QString ans = "";
    bool fl = false;
    for (int ii = 0; ii < text_elem_action.length(); ++ii) {
        if (text_elem_action[ii] != " " && fl && text_elem_action[ii] != ";") {
            ans += text_elem_action[ii];
        }
        else if (text_elem_action[ii] == ";") {
            fl = true;
        }
    }
    return ans;
}

void MainWindow::show_context_menu_widget() {
    QMenu* menu = new QMenu(this);

    QAction* addOneElem = new QAction(u8"Добавить элемент", this);
    QAction* addManyElems = new QAction(u8"Добавить рандомные элементы", this);
    /* Подключаем СЛОТы обработчики для действий контекстного меню */
    connect(addOneElem, SIGNAL(triggered()), this, SLOT(slotAddOneElem()));     // Обработчик вызова диалога редактирования
    connect(addManyElems, SIGNAL(triggered()), this, SLOT(slotAddManyElems())); // Обработчик удаления записи
    /* Устанавливаем действия в меню */
    menu->addAction(addOneElem);
    menu->addAction(addManyElems);

    menu->exec(QCursor::pos());
}

void MainWindow::Update_Showing_Tree() {
    switch (TREE_SHOW_NOW) {
    case 1: // AVL
        label->setText(u8"AVL дерево");
        display_avl.UpdateSceneAVL();
        scene = display_avl.GetSceneAVL();
        graph_view->setScene(scene);
        break;
    case 2: // RedBlack
        label->setText(u8"Красно-черное дерево");
        display_redblack.UpdateSceneRedBlack();
        scene = display_redblack.GetSceneRedBlackTree();
        graph_view->setScene(scene);
        break;
    case 3: // FindTree
        label->setText(u8"Дерево Поиска");
        display_find_tree.UpdateSceneFindTree();
        scene = display_find_tree.GetSceneFindTree();
        graph_view->setScene(scene);
        break;
    case 4: // 2-3 Tree
        label->setText(u8"2-3 Дерево");
        display_twotreetree.UpdateTwoTreeTree();
        scene = display_twotreetree.GetSceneTwoTreeTree();
        graph_view->setScene(scene);
    break;
    }
   // scene->setBackgroundBrush(QBrush(QColor(239, 227, 175)));
    scene->setBackgroundBrush(QBrush(QColor(203, 250, 197)));
    graph_view->scale(qreal(1), qreal(1));
}

void MainWindow::slotFromPoint2_(QString text__) {
    text_elem_action = text__;
    show_context_menu_top();
}

void MainWindow::slotDelete() {
    display_avl.getAVLTree()->del(text_elem_action.toInt());
    display_redblack.getRedBlackTree()->del(text_elem_action.toInt());
    display_find_tree.getFindTree()->del(text_elem_action.toInt());
    int tmp__ = text_elem_action.toInt();
    display_twotreetree.getTwoTreeTree()->del(&tmp__);
    Update_Showing_Tree();
    --NUMBER_OF_ELEMS;
    label_num_of_elems->setText(u8"Дерево содержит: " + QString::number(NUMBER_OF_ELEMS) + u8" элементов" + u8" (от " + QString::number(MIN_GEN) + u8" до " + QString::number(MAX_GEN) + u8")");
}

void MainWindow::slotDelete_number_1() {
    display_avl.getAVLTree()->del(first_num_delete.toInt());
    display_redblack.getRedBlackTree()->del(first_num_delete.toInt());
    display_find_tree.getFindTree()->del(first_num_delete.toInt());
    int tmp__ = first_num_delete.toInt();
    display_twotreetree.getTwoTreeTree()->del(&tmp__);
    Update_Showing_Tree();
    --NUMBER_OF_ELEMS;
    label_num_of_elems->setText(u8"Дерево содержит: " + QString::number(NUMBER_OF_ELEMS) + u8" элементов" + u8" (от " + QString::number(MIN_GEN) + u8" до " + QString::number(MAX_GEN) + u8")");
}

void MainWindow::slotDelete_number_2() {
    display_avl.getAVLTree()->del(second_num_delete.toInt());
    display_redblack.getRedBlackTree()->del(second_num_delete.toInt());
    display_find_tree.getFindTree()->del(second_num_delete.toInt());
    int tmp__ = second_num_delete.toInt();
    display_twotreetree.getTwoTreeTree()->del(&tmp__);
    Update_Showing_Tree();
    --NUMBER_OF_ELEMS;
    label_num_of_elems->setText(u8"Дерево содержит: " + QString::number(NUMBER_OF_ELEMS) + u8" элементов" + u8" (от " + QString::number(MIN_GEN) + u8" до " + QString::number(MAX_GEN) + u8")");

}

void MainWindow::slotEditRecord() {
    QString HINT_EDIT = u8"Укажите новое значение:";
    DialogEditAdd dialog(HINT_EDIT, text_elem_action, this);
    dialog.setModal(true);
    dialog.setFixedSize(dialog.size());
    if (dialog.exec() == QDialog::Accepted) {
        QString new_number = dialog.getNumber();
        if (Check_Correct_Digit(new_number)) {
            int tmp__ = text_elem_action.toInt();
            if (!display_find_tree.getFindTree()->is_InTree(new_number.toInt())) {
                display_avl.getAVLTree()->del(text_elem_action.toInt());
                display_redblack.getRedBlackTree()->del(text_elem_action.toInt());
                display_find_tree.getFindTree()->del(text_elem_action.toInt());
                display_twotreetree.getTwoTreeTree()->del(&tmp__);

                display_avl.getAVLTree()->insert(new_number.toInt());
                display_redblack.getRedBlackTree()->insert(new_number.toInt());
                display_find_tree.getFindTree()->insert(new_number.toInt());
                tmp__ = new_number.toInt();
                display_twotreetree.getTwoTreeTree()->insert(&tmp__);

                Update_Showing_Tree();
            }
            else {
                DialogError dialog_err(4, this);
                dialog_err.setModal(true);
                dialog_err.setFixedSize(dialog_err.size());
                dialog_err.exec();
            }
        }
        else {
            DialogError dialog_err(2, this);
            dialog_err.setModal(true);
            dialog_err.setFixedSize(dialog_err.size());
            dialog_err.exec();
        }
    }
}

void MainWindow::slotEditRecord_number_1() {
    QString HINT_EDIT = u8"Укажите новое значение:";
    DialogEditAdd dialog(HINT_EDIT, first_num_delete, this);
    dialog.setModal(true);
    dialog.setFixedSize(dialog.size());
    if (dialog.exec() == QDialog::Accepted) {
        QString new_number = dialog.getNumber();
        if (Check_Correct_Digit(new_number)) {
            int tmp__ = first_num_delete.toInt();
            if (!display_find_tree.getFindTree()->is_InTree(new_number.toInt())) {
                display_avl.getAVLTree()->del(first_num_delete.toInt());
                display_redblack.getRedBlackTree()->del(first_num_delete.toInt());
                display_find_tree.getFindTree()->del(first_num_delete.toInt());
                display_twotreetree.getTwoTreeTree()->del(&tmp__);

                display_avl.getAVLTree()->insert(new_number.toInt());
                display_redblack.getRedBlackTree()->insert(new_number.toInt());
                display_find_tree.getFindTree()->insert(new_number.toInt());
                tmp__ = new_number.toInt();
                display_twotreetree.getTwoTreeTree()->insert(&tmp__);

                Update_Showing_Tree();
            } else {
                DialogError dialog_err(4, this);
                dialog_err.setModal(true);
                dialog_err.setFixedSize(dialog_err.size());
                dialog_err.exec();
            }
        }
        else {
            DialogError dialog_err(2, this);
            dialog_err.setModal(true);
            dialog_err.setFixedSize(dialog_err.size());
            dialog_err.exec();
        }
    }
}

void MainWindow::slotEditRecord_number_2() {
    QString HINT_EDIT = u8"Укажите новое значение:";
    DialogEditAdd dialog(HINT_EDIT, second_num_delete, this);
    dialog.setModal(true);
    dialog.setFixedSize(dialog.size());
    if (dialog.exec() == QDialog::Accepted) {
        QString new_number = dialog.getNumber();
        if (Check_Correct_Digit(new_number)) {
            int tmp__ = second_num_delete.toInt();
            if (!display_find_tree.getFindTree()->is_InTree(new_number.toInt())) {
                display_avl.getAVLTree()->del(second_num_delete.toInt());
                display_redblack.getRedBlackTree()->del(second_num_delete.toInt());
                display_find_tree.getFindTree()->del(second_num_delete.toInt());
                display_twotreetree.getTwoTreeTree()->del(&tmp__);

                display_avl.getAVLTree()->insert(new_number.toInt());
                display_redblack.getRedBlackTree()->insert(new_number.toInt());
                display_find_tree.getFindTree()->insert(new_number.toInt());
                tmp__ = new_number.toInt();
                display_twotreetree.getTwoTreeTree()->insert(&tmp__);

                Update_Showing_Tree();
            }
            else {
                DialogError dialog_err(4, this);
                dialog_err.setModal(true);
                dialog_err.setFixedSize(dialog_err.size());
                dialog_err.exec();
            }
        }
        else {
            DialogError dialog_err(2, this);
            dialog_err.setModal(true);
            dialog_err.setFixedSize(dialog_err.size());
            dialog_err.exec();
        }
    }
}

void MainWindow::slotAddOneElem() {
    QString HINT_EDIT = u8"Укажите новый элемент:";
    DialogEditAdd dialog(HINT_EDIT, this);
    dialog.setModal(true);
    dialog.setFixedSize(dialog.size());
    if (dialog.exec() == QDialog::Accepted) {
        QString new_number = dialog.getNumber();
        if (Check_Correct_Digit(new_number)) {
            if (!display_find_tree.getFindTree()->is_InTree(new_number.toInt())) {
                display_avl.getAVLTree()->insert(new_number.toInt());
                display_redblack.getRedBlackTree()->insert(new_number.toInt());
                display_find_tree.getFindTree()->insert(new_number.toInt());
                int tmp__ = new_number.toInt();
                display_twotreetree.getTwoTreeTree()->insert(&tmp__);

                if (tmp__ < MIN_GEN) {
                    MIN_GEN = tmp__;
                }
                else if (tmp__ > MAX_GEN) {
                    MAX_GEN = tmp__;
                }

                Update_Showing_Tree();
                ++NUMBER_OF_ELEMS;
                label_num_of_elems->setText(u8"Дерево содержит: " + QString::number(NUMBER_OF_ELEMS) + u8" элементов" + u8" (от " + QString::number(MIN_GEN) + u8" до " + QString::number(MAX_GEN) + u8")");

            }
            else {
                DialogError dialog_err(4, this);
                dialog_err.setModal(true);
                dialog_err.setFixedSize(dialog_err.size());
                dialog_err.exec();
            }
        }
        else {
            DialogError dialog_err(2, this);
            dialog_err.setModal(true);
            dialog_err.setFixedSize(dialog_err.size());
            dialog_err.exec();
        }
        
    }
}

void MainWindow::slotAddManyElems() {
    QString HINT_EDIT = u8"Укажите кол-во новых элементов(от 1 до 1000):";
    DialogEditAdd dialog(HINT_EDIT, this);
    dialog.setModal(true);
    dialog.setFixedSize(dialog.size());
    if (dialog.exec() == QDialog::Accepted) {
        QString number_of_elems = dialog.getNumber();
        if (Check_Correct_Digit(number_of_elems)) {
            if (number_of_elems.toInt() <= 1000 && number_of_elems.toInt() >= 1) {
                int num_of = number_of_elems.toInt();
                int num_gen;
                std::uniform_int_distribution<int> genRand(MIN_GEN, MAX_GEN);
                for (int ii = 1; ii <= num_of; ++ii) {
                    num_gen = genRand(seed);
                    while (display_find_tree.getFindTree()->is_InTree(num_gen)) {
                        num_gen = genRand(seed);
                    }
                    display_avl.getAVLTree()->insert(num_gen);
                    display_redblack.getRedBlackTree()->insert(num_gen);
                    display_find_tree.getFindTree()->insert(num_gen);
                    display_twotreetree.getTwoTreeTree()->insert(&num_gen);
                    ++NUMBER_OF_ELEMS;

                    label_num_of_elems->setText(u8"Дерево содержит: " + QString::number(NUMBER_OF_ELEMS) + u8" элементов" + u8" (от " + QString::number(MIN_GEN) + u8" до " + QString::number(MAX_GEN) + u8")");

                    Update_Showing_Tree();
                }
            }
            else {
                DialogError dialog_err(3, this);
                dialog_err.setModal(true);
                dialog_err.setFixedSize(dialog_err.size());
                dialog_err.exec();
            }
        }
        else {
            DialogError dialog_err(2, this);
            dialog_err.setModal(true);
            dialog_err.setFixedSize(dialog_err.size());
            dialog_err.exec();
        }
    }
}

void MainWindow::slotNextTree() {
    ++TREE_SHOW_NOW;
    if (TREE_SHOW_NOW > NUM_OF_TREES) {
        TREE_SHOW_NOW = 1;
    }
    Update_Showing_Tree();
}

void MainWindow::slotPrevTree() {
    --TREE_SHOW_NOW;
    if (TREE_SHOW_NOW < 1) {
        TREE_SHOW_NOW = NUM_OF_TREES;
    }
    Update_Showing_Tree();
}

void MainWindow::slotRegenTrees() {
    QString HINT_EDIT = u8"Укажите кол-во элементов(от 1 до 1000):";
    DialogEditAdd dialog(HINT_EDIT, this);
    dialog.setModal(true);
    dialog.setFixedSize(dialog.size());
    if (dialog.exec() == QDialog::Accepted) {
        QString number_of_elems = dialog.getNumber();
        if (Check_Correct_Digit(number_of_elems)) {
            if (number_of_elems.toInt() <= 1000 && number_of_elems.toInt() >= 1) {
                DialogSetRange dialog_range(this);
                dialog_range.setModal(true);
          //      dialog_range.setFixedSize(dialog.size());
                if (dialog_range.exec() == QDialog::Accepted) {
                    QString new_min = dialog_range.getMinNumber();
                    QString new_max = dialog_range.getMaxNumber();
                    if (Check_Correct_Digit(new_min) && Check_Correct_Digit(new_max)) {
                        if (new_min.toInt() < new_max.toInt() && number_of_elems.toInt() < new_max.toInt() - new_min.toInt()) {
                            NUMBER_OF_ELEMS = number_of_elems.toInt();
                            MIN_GEN = new_min.toInt();
                            MAX_GEN = new_max.toInt();

                            display_twotreetree.getTwoTreeTree()->removeAll();
                            display_avl.getAVLTree()->removeAll();
                            display_redblack.getRedBlackTree()->removeAll();
                            display_find_tree.getFindTree()->removeAll();
                            
                            init_all_tree();
                            Update_Showing_Tree();
                            label_num_of_elems->setText(u8"Дерево содержит: " + QString::number(NUMBER_OF_ELEMS) + u8" элементов" + u8" (от " + QString::number(MIN_GEN) + u8" до " + QString::number(MAX_GEN) + u8")");

                        }
                        else {
                            DialogError dialog_err(1, this);
                            dialog_err.setModal(true);
                            dialog_err.setFixedSize(dialog_err.size());
                            dialog_err.exec();
                        }
                    }
                    else {
                        DialogError dialog_err(2, this);
                        dialog_err.setModal(true);
                        dialog_err.setFixedSize(dialog_err.size());
                        dialog_err.exec();
                    }
                }
            }
            else {
                DialogError dialog_err(3, this);
                dialog_err.setModal(true);
                dialog_err.setFixedSize(dialog_err.size());
                dialog_err.exec();
            }
        }
        else {
            DialogError dialog_err(2, this);
            dialog_err.setModal(true);
            dialog_err.setFixedSize(dialog_err.size());
            dialog_err.exec();
        }
    }
}

void MainWindow::slotMouseDoubleClickCustom() {
    show_context_menu_widget();
}

bool MainWindow::Check_Correct_Digit(QString number) {
    int MAX_IN_LONG_PLUS = 10;
    int MAX_IN_LONG_MINUS = 11;

    for (int ii = 0; ii < number.length(); ++ii) {
        if (!number[ii].isDigit() && ii != 0) {
            return false;
        }
        else if (!number[ii].isDigit() && ii == 0) {
            if (number[ii] != "-") {
                return false;
            }
        }
        if (ii > 12) {
            return false;
        }
    }

    if (number.length() == MAX_IN_LONG_PLUS && number[0] != "-") { // +
        if (QString(number[0]).toInt() <= 2) {
            if (QString(number[1]).toInt() <= 1) {
                if (QString(number[2]).toInt() <= 4) {
                    if (QString(number[3]).toInt() <= 7) {
                        if (QString(number[4]).toInt() <= 4) {
                            if (QString(number[5]).toInt() <= 8) {
                                if (QString(number[6]).toInt() <= 3) {
                                    if (QString(number[7]).toInt() <= 6) {
                                        if (QString(number[8]).toInt() <= 4) {
                                            if (QString(number[9]).toInt() <= 7) {
                                                return false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
    else if (number.length() == MAX_IN_LONG_MINUS && number[0] == "-") { // -
        if (QString(number[1]).toInt() <= 2) {
            if (QString(number[2]).toInt() <= 1) {
                if (QString(number[3]).toInt() <= 4) {
                    if (QString(number[4]).toInt() <= 7) {
                        if (QString(number[5]).toInt() <= 4) {
                            if (QString(number[6]).toInt() <= 8) {
                                if (QString(number[7]).toInt() <= 3) {
                                    if (QString(number[8]).toInt() <= 6) {
                                        if (QString(number[9]).toInt() <= 4) {
                                            if (QString(number[10]).toInt() <= 8) {
                                                return false;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
    else if (number.length() < 10) {
        return true;
    }
    else {
        return false;
    }

    return true;
}