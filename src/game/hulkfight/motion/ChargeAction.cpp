// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00171820..0x001719c0 (kind game, layer game, confidence high), dominant class hulkfight::motion::ChargeAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffe35821 {
#define TREE_TU_END }
namespace fn_ffe35821 {} using namespace fn_ffe35821;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_ffe35821 {
struct A_171820 {
};
struct B_171820 {
    void* g();
};
struct C_171820 {
    void h(int);
};
struct A_171840 {
    A_171840* f59a30();
    void f37120(int);
};
class ActionDef {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float GetLength();
    char pad4[0x14 - 4];
    int step;
    char restart;
    char pad19[3];
    float elapsed;
};
class Fighter_171860 {
public:
    char pad0[0x1e58];
    float baseline;
    int lastStep;
};
class FighterRef_171860 {
public:
    Fighter_171860* FUN_00059a30();
};
class Owner_171860 {
public:
};
struct MotionData {
    char pad[0x1e58];
    float value;
    unsigned int id;
};
struct Holder_1718f0 {
    char pad[0x14];
    unsigned int id;
};
struct Resolver_1718f0 {
    MotionData* get();
};
struct Caller_1718f0 {
    Resolver_1718f0* get();
};
struct ChargeAction {
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual bool vfunc_5(int p2, float p3);
    char pad0[0x18];
    Holder_1718f0* holder;
    Caller_1718f0* source;
    float scale;
};
struct Buf28 {
    char d[28];
    void FUN_001c9a60(int a, int b, int c);
};
struct Sink_171950 { void FUN_001cbc20(Buf28 *b); };
struct Probe_171950 { bool FUN_001ccff0(); };
} // namespace fn_ffe35821
struct World { char pad[0x2c]; Probe_171950 *probe; Sink_171950 *sink; };
namespace fn_ffe35821 {
struct Ctx2_171950 { char pad[0x10]; int *p10; char pad2[0x1e58 - 0x14]; int v1e58; };
struct Ctx1_171950 { Ctx2_171950 *FUN_00059a30(); };
struct Owner_171950 {  };
struct Inner_171950 { char pad[0x14]; int v14; };

} // namespace fn_ffe35821

// 0x00171820 hulkfight::motion::IntentionClearAction::vfunc_3 (29 B): matches/0x00171820.cpp
// sym: ?vfunc_3@IntentionClearAction@motion@hulkfight@@UAE_NHH@Z
bool hulkfight::motion::IntentionClearAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    void* p = ((void *)((owners::Object_592a0 *)((*(A_171820 * *)&this->f_20)))->FUN_000592a0());
    p = ((B_171820*)p)->g();
    ((C_171820*)p)->h(1);
    return true;
}


// 0x00171840 hulkfight::motion::IntentionClearAction::vfunc_4 (25 B): matches/0x00171840.cpp
// sym: ?vfunc_4@IntentionClearAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::IntentionClearAction::vfunc_4() {
    A_171840* x = ((A_171840 *)((owners::Object_592a0 *)((*(A_171840 * *)&this->f_20)))->FUN_000592a0());
    x = x->f59a30();
    x->f37120(0);
}


// 0x00171860 hulkfight::motion::ChargeAction::vfunc_3 (139 B): equivalent/0x00171860.cpp
// sym: ?vfunc_3@ChargeAction@motion@hulkfight@@UAE_NHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19924 inputs, branch coverage 8/8)
// hulkfight::motion::ChargeAction::vfunc_3 @ 0x00171860
// Charge action update: track which action step is running and publish its progress ratio.
bool hulkfight::motion::ChargeAction::vfunc_3(hulk_intptr a, hulk_intptr b) {
    Fighter_171860* fighter = ((FighterRef_171860 *)((owners::Object_592a0 *)((*(Owner_171860 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
    int step = (*(ActionDef * *)&this->f_1c)->step;
    if ((*(ActionDef * *)&this->f_1c)->restart != 0 || step != fighter->lastStep) {
        fighter->baseline = 0;
    }
    fighter->lastStep = step;

    hulk_freg length = (*(ActionDef * *)&this->f_1c)->GetLength();
    hulk_freg elapsed = (*(ActionDef * *)&this->f_1c)->elapsed;
    if (length > 0.0f) {
        if (elapsed < 1.0f) {
            elapsed -= fighter->baseline;
        }
        this->f_24 = elapsed / length;
    } else {
        this->f_24 = elapsed;
    }
    return true;
}

namespace fn_ffe35821 {

// 0x001718f0 hulkfight::motion::ChargeAction::vfunc_5 (81 B): matches/0x001718f0.cpp
// sym: ?vfunc_5@ChargeAction@fn_ffe35821@@UAE_NHM@Z
bool ChargeAction::vfunc_5(int p2, float p3) {
    if (p2 == 0) {
        Resolver_1718f0* r = source->get();
        MotionData* m = r->get();
        unsigned int id = holder->id;
        if (id != m->id)
            m->value = 0.0f;
        m->id = id;
        m->value = p3 * scale + m->value;
    }
    return true;
}

} // namespace fn_ffe35821

// 0x00171950 hulkfight::motion::ChargeAction::vfunc_4 (107 B): matches/0x00171950.cpp
// sym: ?vfunc_4@ChargeAction@motion@hulkfight@@UAEXXZ
// hulkfight::motion::ChargeAction::vfunc_4 @ 0x00171950
void hulkfight::motion::ChargeAction::vfunc_4() {
    Buf28 buf;
    if (DAT_004dd700->probe != 0 && DAT_004dd700->probe->FUN_001ccff0()) {
        Sink_171950 *sink = DAT_004dd700->sink;
        if (sink != 0) {
            Ctx2_171950 *c = ((Ctx1_171950 *)((owners::Object_592a0 *)((*(Owner_171950 * *)&this->f_20)))->FUN_000592a0())->FUN_00059a30();
            if (c != 0) {
                buf.FUN_001c9a60(*c->p10, (*(Inner_171950 * *)&this->f_1c)->v14, c->v1e58);
                sink->FUN_001cbc20(&buf);
            }
        }
    }
}

