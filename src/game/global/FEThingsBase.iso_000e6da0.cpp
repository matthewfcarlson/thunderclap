// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000e6da0 FEThingsBase::vfunc_21 (231 B): matches/0x000e6da0.cpp [isolated: conflict: World; on include/gen/ and not mergeable]
// sym: ?vfunc_21@FEThingsBase@@UAEXXZ
#include "gen/global.h"

#include "decls/data/game/global.h"
#include "decls/address.h"

struct ResetObject {
    void FUN_000363d0();
};
struct ContextChild {
    char pad[0x124];
    ResetObject* reset;
};
struct World {
    char pad[0x20];
    ContextChild* child;
};
struct Panel_e6da0 {
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
    char pad[0xbbc];
    unsigned char enabled;
    void FUN_000e5440(int);
};

void FEThingsBase::vfunc_21() {
    if (this->f_17b0 < 0 || (!(*(unsigned char *)&this->f_2104) && this->f_17b0 == 0) || ((*(Panel_e6da0 * *)&this->f_175c) && !(*(Panel_e6da0 * *)&this->f_175c)->enabled)) {
        vfunc_48(7);
        return;
    }
    vfunc_48(1);
    --this->f_17b0;
    (*(unsigned int *)&this->f_1768) = this->f_17b0 >= 0 ? (*(unsigned int (*)[16])&this->f_1770)[this->f_17b0] : 0;
    this->f_17f8 = 1;
    this->f_176c = 2;
    if ((*(Panel_e6da0 * *)&this->f_175c)) {
        (*(Panel_e6da0 * *)&this->f_175c)->v15();
        (*(Panel_e6da0 * *)&this->f_175c)->FUN_000e5440(this->f_176c);
    }
    World* context = DAT_004dd700;
    (*(unsigned char*)&DAT_004e222c) = 1;
    if (context->child && context->child->reset && (*(unsigned char*)&DAT_004e2518)) {
        (*(unsigned char*)&DAT_004e2518) = 0;
        context->child->reset->FUN_000363d0();
    }
}

