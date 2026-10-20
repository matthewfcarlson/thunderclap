#include "compat/ptr.h"
#include "gen/pure3d.h"

struct Child_2a4350 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void Fn23();
};
struct Group_2a4350 {
    int pad;
    Child_2a4350** begin;
    Child_2a4350** end;
    int pad2;
};

void pure3d::DrawableContainer::vfunc_9() {
    hulk_uintptr n = (*(Group_2a4350 * *)&this->f_4c) - (*(Group_2a4350 * *)&this->f_48);
    for (unsigned i = 0; i < n; i++) {
        Group_2a4350* g = &(*(Group_2a4350 * *)&this->f_48)[i];
        hulk_uintptr m = g->end - g->begin;
        for (unsigned j = 0; j < m; j++) {
            Child_2a4350* c = g->begin[j];
            if (c)
                c->Fn23();
        }
    }
}
