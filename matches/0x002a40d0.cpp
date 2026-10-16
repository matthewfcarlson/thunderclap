#include "gen/pure3d.h"

struct Obj_2a40d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};
struct Grp {
    int m0;
    Obj_2a40d0** b;
    Obj_2a40d0** e;
    int mc;
};

void pure3d::DrawableContainer::vfunc_6(int a, int b) {
    unsigned n = (*(Grp * *)&this->f_4c) - (*(Grp * *)&this->f_48);
    for (unsigned i = 0; i < n; i++) {
        Grp* g = &(*(Grp * *)&this->f_48)[i];
        unsigned m = g->e - g->b;
        for (unsigned j = 0; j < m; j++) {
            Obj_2a40d0* o = g->b[j];
            if (o)
                o->v6(a, b);
        }
    }
}
