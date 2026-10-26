#include "decls/data/game/global.h"
// data: gZero_fc550 = DAT_003f32e0

#include "compat/ptr.h"
extern "C" char DAT_004a19e0[];
extern "C" char DAT_004a19f8[];
class Target_fc550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

class Elem_fc550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Act(int a, int b, int c);
    virtual void v5();
    virtual void v6();
    virtual void Fin(int x);
    char pad[4];
    float f;
};

class Other_fc550 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Notify();
    char pad[0x54];
    Target_fc550* t;
};

extern "C" void* FUN_00344e74(void*, int, void*, void*, int);

class Owner_fc550 {
  public:
    char pad[0x14];
    Elem_fc550* items[1];
    char pad2[0x3c];
    int cur;
    void Fn(int a, int b, char c);
};

void Owner_fc550::Fn(int a, int b, char c) {
    if (cur == -1)
        return;
    if (c) {
        Elem_fc550* e = items[cur];
        if (e->f <= DAT_003f32e0) {
            Other_fc550* o = (Other_fc550*)FUN_00344e74(e, 0, (void*)((hulk_intptr)DAT_004a19e0), (void*)((hulk_intptr)DAT_004a19f8), 0);
            if (o) {
                Target_fc550* t = o->t;
                if (t)
                    t->v6();
            }
        }
    }
    items[cur]->Act(a, b, *(int*)&c);  // the original forwards the whole stack word of the char argument
    items[cur]->Fin(1);
}
