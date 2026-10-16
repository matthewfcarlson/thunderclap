#include "gen/hulkfight.h"

struct Obj31 {
    char p[0x31];
    char f;
};
struct Mgr_1a8ee0 {
    Obj31* Get();
};
struct Hnd {
    void Rel();
};
struct Ent_1a8ee0 {
    char p[0xa8];
    char f;
};
struct Hulk {
    Ent_1a8ee0* Fn(int);
    void Fn2(int);
};
struct Sub_1a8ee0 {
    char p[0x124];
    Hulk* h;
};
struct Gl {
    char p[0x20];
    Sub_1a8ee0* s;
    char q[0x30];
    Mgr_1a8ee0* m;
};
extern Gl* g_1a8ee0;
struct NISAnimationAction_nv_1a8ee0 {
    void Inner();
};

void hulkfight::scenario::NISAnimationAction::vfunc_4() {
    g_1a8ee0->m->Get()->f = 1;
    ((NISAnimationAction_nv_1a8ee0*)this)->Inner();
    if (this->f_214) {
        (*(Hnd * *)&this->f_20c)->Rel();
        this->f_214 = 0;
    }
    Hulk* x = g_1a8ee0->s->h;
    if (x) {
        x->Fn(1)->f = 1;
        x->Fn2(0);
    }
}
