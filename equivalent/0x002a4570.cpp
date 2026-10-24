// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 6/6)
// pure3d::DrawableContainer::vfunc_12 @ 0x002a4570
#include "gen/pure3d.h"

struct V3_2a4570 { float x, y, z; };

struct Sphere_2a4570 { float x, y, z, r; };

struct Box_2a4570 {
    V3_2a4570 min;
    V3_2a4570 max;
    void FUN_000a87f0(V3_2a4570* p);
    Sphere_2a4570* FUN_000a8890(Sphere_2a4570* out);
};

union Temp_2a4570 {
    Box_2a4570 box;
    Sphere_2a4570 sphere;
};

class Child_2a4570 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x14 - 4];
    Box_2a4570 box;
};

struct Slot_2a4570 {
    Child_2a4570* child;
    char pad[12];
};

void pure3d::DrawableContainer::vfunc_12() {
    unsigned int count = (unsigned int)((*(Slot_2a4570 * *)&this->f_4c) - (*(Slot_2a4570 * *)&this->f_48));
    Temp_2a4570 t;
    if (count == 0) {
        (*(Box_2a4570 *)&this->f_14).min.x = 0;
        (*(Box_2a4570 *)&this->f_14).min.y = 0;
        (*(Box_2a4570 *)&this->f_14).min.z = 0;
        (*(Box_2a4570 *)&this->f_14).max.x = 1.0f;
        (*(Box_2a4570 *)&this->f_14).max.y = 1.0f;
        (*(Box_2a4570 *)&this->f_14).max.z = 1.0f;
    } else {
        Child_2a4570* first = (*(Slot_2a4570 * *)&this->f_48)[0].child;
        first->v10();
        t.box = first->box;
        (*(Box_2a4570 *)&this->f_14) = t.box;
        for (unsigned int i = 1; i < count; i++) {
            Child_2a4570* c = (*(Slot_2a4570 * *)&this->f_48)[i].child;
            c->v10();
            t.box = c->box;
            (*(Box_2a4570 *)&this->f_14).FUN_000a87f0(&t.box.min);
            (*(Box_2a4570 *)&this->f_14).FUN_000a87f0(&t.box.max);
        }
    }
    Sphere_2a4570* s = (*(Box_2a4570 *)&this->f_14).FUN_000a8890(&t.sphere);
    (*(Sphere_2a4570 *)&this->f_2c) = *s;
}
