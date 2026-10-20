#include "compat/ptr.h"
struct Node {
    int a;
    int b;
    int state;
};
struct Obj_fb150 {
    char pad0[8];
    Node* root;
    Node* cur;
    char pad10[4];
    char done;
    hulk_intptr next();
};
hulk_intptr Obj_fb150::next() {
    Node* n = root;
    if (!n)
        return 0;
    hulk_intptr r;
    if (done != 1) {
        Node* c = cur;
        if (!c) {
            c = *(Node**)((char*)n + 4);
        } else {
            c = *(Node**)((char*)c + 4);
        }
        r = (hulk_intptr)c;
        if (c && c->state < 2)
            r = 0;
    } else
        r = 0;
    cur = (Node*)r;
    if (!r)
        done = 1;
    return r;
}
