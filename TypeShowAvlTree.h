#ifndef TYPESHOWAVLTREE_H
#define TYPESHOWAVLTREE_H

#endif // TYPESHOWAVLTREE_H

#include "avl_tree.h"

class typeshowavl {
public:
    typeshowavl() { 
        nod = nullptr;
        slide = 0;
    }

    typeshowavl(nodeptr nn, long long rr) { 
        nod = nn;
        slide = rr;
    }

    nodeptr getNode() { return nod; }

    long long getSlide() { return slide; }

    void setNode(nodeptr nn) { nod = nn;
    }

    void setSlide(long long rr) { slide = rr;
    }

 private:
    nodeptr nod;
 long long slide;
};
