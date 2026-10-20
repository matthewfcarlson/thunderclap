#include "compat/ptr.h"
struct Node {
    int a;
    int b;
};
hulk_intptr __cdecl FUN_002430d0(Node* p) {
    hulk_intptr r = p->b;
    if (r) {
        p->b = *(int*)r;
    } else {
        r = 0;
    }
    return r;
}
