// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 16/16)
// pure3d::CompositeDrawable::vfunc_9 @ 0x00298e60
// pure3d::CompositeDrawable::vfunc_9: run the update hook of every child (in order), then of the two extra drawables
#include "gen/pure3d.h"

struct Node_298e60 {
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
    virtual void v23();
};

struct Group_298e60 {
    char pad00[0x20];
    unsigned char count;
    char pad21[0xf];
    unsigned char *order;
    char pad34[8];
    struct Slot_298e60 *slots;
    void FUN_00298870();
};

struct Slot_298e60 {
    char pad00[8];
    Node_298e60 *node;
};

struct Alt {
    char pad00[8];
    unsigned char count;
    char pad09[0xf];
    unsigned char *order;
    char pad1c[8];
    Node_298e60 **nodes;
};

void pure3d::CompositeDrawable::vfunc_9() {
    if ((*(Alt * *)&this->f_48) == 0) {
        if ((*(Group_298e60 * *)&this->f_44) != 0) {
            (*(Group_298e60 * *)&this->f_44)->FUN_00298870();
            unsigned char n = (*(Group_298e60 * *)&this->f_44)->count;
            for (unsigned int i = 0; i < n; i++)
                (*(Group_298e60 * *)&this->f_44)->slots[(*(Group_298e60 * *)&this->f_44)->order[i]].node->v9();
        }
        if ((*(Node_298e60 * *)&this->f_4c) != 0)
            (*(Node_298e60 * *)&this->f_4c)->v23();
        if ((*(Node_298e60 * *)&this->f_50) != 0)
            (*(Node_298e60 * *)&this->f_50)->v23();
    } else {
        unsigned char n = (*(Alt * *)&this->f_48)->count;
        for (unsigned int i = 0; i < n; i++)
            (*(Alt * *)&this->f_48)->nodes[(*(Alt * *)&this->f_48)->order[i]]->v23();
    }
}
