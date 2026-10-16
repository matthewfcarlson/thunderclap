#include "gen/hulkfight.h"

struct X_14f630 {
    void* a();
    void* b();
    void c(int);
};

bool hulkfight::motion::NoHitPushbackAction::vfunc_3(int __p0, int __p1) {
    X_14f630* p = (*(X_14f630 * *)&this->f_20);
    if (p) {
        X_14f630* a = (X_14f630*)p->a();
        X_14f630* b = (X_14f630*)a->b();
        b->c(1);
    }
    return true;
}
