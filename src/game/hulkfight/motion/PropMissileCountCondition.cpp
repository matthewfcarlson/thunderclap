// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001819f0..0x00181cc0 (kind game, layer game, confidence medium), dominant class hulkfight::motion::PropMissileCountCondition
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc979cf7 {
#define TREE_TU_END }
namespace fn_fc979cf7 {} using namespace fn_fc979cf7;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fight {
class Params_1819f0 {
public:
    virtual void v0();
};
}
namespace fn_fc979cf7 {
class CFightParams_1819f0 : public fight::Params_1819f0 {
public:
    virtual void v1();
};
struct Fighter_1819f0 {
    char pad0[0x128];
    void *f128;
};
struct Anchor_1819f0 {
    Fighter_1819f0 *FUN_00059a30();
};
struct FightHandle {
};
extern char DAT_00494b44[];
extern char DAT_00494b60[];
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
struct Stats_181a70;
struct Ctx_181a70 {
    Stats_181a70 *FUN_00059a30();
};
class Owner_181a70 {
public:
};
struct Target_181a70 {
    char pad0[0x148];
    int f148;
};
struct Stats_181a70 {
    char pad0[0x3a4];
    struct Slot {
        char pad0[8];
        Target_181a70 *f8;
        int fc;
    } *f3a4;
};
struct Sink_181ae0 {
    bool FUN_001d4e20();
};
struct Part_181ae0 {
    char pad[0xec];
    Sink_181ae0 *sink;
};
struct Fighter_181ae0 {
    char pad[0x128];
    Part_181ae0 *part;
};
struct Owner_181ae0 {
    char pad[1];
};
Owner_181ae0 *__fastcall FUN_000592a0(void *obj);
Fighter_181ae0 *__fastcall FUN_00059a30(Owner_181ae0 *o);

} // namespace fn_fc979cf7

// 0x001819f0 hulkfight::motion::PropIsAttachedCondition::vfunc_6 (117 B): equivalent/0x001819f0.cpp
// sym: ?vfunc_6@PropIsAttachedCondition@motion@hulkfight@@UAE_NPAX00@Z @3ce56562e49d @w70a594a5fc82
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::PropIsAttachedCondition::vfunc_6 @ 0x001819f0
bool hulkfight::motion::PropIsAttachedCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; fight::Params_1819f0 * params = (fight::Params_1819f0 *)__p1; int c = (int)__p2;

    CFightParams_1819f0 *fp = dynamic_cast<CFightParams_1819f0 *>(params);
    if (fp == 0)
        return false;
    Fighter_1819f0 *f = ((Anchor_1819f0 *)((owners::Object_592a0 *)(((FightHandle *)params)))->FUN_000592a0())->FUN_00059a30();
    void *prop = 0;
    if (f != 0) {
        if (this->f_0c < 0)
            prop = f->f128;
        else if (this->f_0c < 8)
            prop = ((void *)((owners::C_35ef0 *)f)->FUN_00035ef0((hulk_intptr)(this->f_0c)));
    }
    return (prop != 0) == (*(unsigned char *)&this->f_10);
}


// 0x00181a70 hulkfight::motion::CSMPropIsCharacterCondition::vfunc_6 (101 B): equivalent/0x00181a70.cpp
// sym: ?vfunc_6@CSMPropIsCharacterCondition@motion@hulkfight@@UAE_NPAX00@Z @2ab66077f4bf @w3e4fce3bc8e0
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 8/8)
// hulkfight::motion::CSMPropIsCharacterCondition::vfunc_6 @ 0x00181a70
bool hulkfight::motion::CSMPropIsCharacterCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; Owner_181a70 * owner = (Owner_181a70 *)__p1; int a3 = (int)__p2;

    if (FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    Stats_181a70::Slot *slot = ((Ctx_181a70 *)((owners::Object_592a0 *)owner)->FUN_000592a0())->FUN_00059a30()->f3a4;
    if (slot == 0 || slot->fc != 5)
        return false;
    return (slot->f8->f148 != 0) == (int)(*(unsigned char *)&this->f_0c);
}


// 0x00181ae0 hulkfight::motion::SmartPropIsCargoCondition::vfunc_6 (116 B): equivalent/0x00181ae0.cpp
// sym: ?vfunc_6@SmartPropIsCargoCondition@motion@hulkfight@@UAE_NPAX00@Z @972f1dca4704 @w8c9588dfccc4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::SmartPropIsCargoCondition::vfunc_6 @ 0x00181ae0
bool hulkfight::motion::SmartPropIsCargoCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a1 = (int)__p0; void * subject = (void *)__p1; int a3 = (int)__p2;

    if (FUN_00344e74(subject, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    bool result = false;
    Fighter_181ae0 *f = FUN_00059a30(FUN_000592a0(subject));
    if (f != 0) {
        Part_181ae0 *part;
        if (this->f_0c < 0) {
            part = f->part;
        } else if (this->f_0c < 8) {
            part = (Part_181ae0 *)((Part_181ae0 *)((owners::C_35ef0 *)f)->FUN_00035ef0((hulk_intptr)(this->f_0c)));
        } else {
            return result;
        }
        if (part != 0)
            result = part->sink->FUN_001d4e20();
    }
    return result;
}


// 0x00181b60 hulkfight::motion::PropCollidedWithWorldCondition::vfunc_6 (112 B): equivalent/0x00181b60.cpp [wrapped: conflict: FUN_000592a0; hulkfight::motion::PropCollidedWithWorldCondition]
// sym: ?vfunc_6@PropCollidedWithWorldCondition@motion@hulkfight@fn_00181b60@@UAE_NHPAXH@Z @1943b4d6d597 @wb69aa0146438
namespace fn_00181b60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// hulkfight::motion::PropCollidedWithWorldCondition::vfunc_6 @ 0x00181b60
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);
extern char DAT_00494b44[];
extern char DAT_00494b60[];

struct Part_181b60 {
    bool FUN_001d6ab0();
};

struct Fighter_181b60 {
    char pad[0x128];
    Part_181b60* part;     // 0x128
    Part_181b60* FUN_00035ef0(int index);
};

struct Owner_181b60 {
    char pad[1];
};
Owner_181b60* __fastcall FUN_000592a0(void* obj);
Fighter_181b60* __fastcall FUN_00059a30(Owner_181b60* o);

namespace hulkfight { namespace motion { class PropCollidedWithWorldCondition {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual bool vfunc_6(int a1, void* subject, int a3);
    char pad04[8];
    int index;      // 0xc
}; }}

bool hulkfight::motion::PropCollidedWithWorldCondition::vfunc_6(int a1, void* subject, int a3)
{
    if (FUN_00344e74(subject, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return false;
    bool result = false;
    Fighter_181b60* f = FUN_00059a30(FUN_000592a0(subject));
    if (f != 0) {
        Part_181b60* part;
        if (index < 0) {
            part = f->part;
        } else if (index < 8) {
            part = f->FUN_00035ef0(index);
        } else {
            return result;
        }
        if (part != 0)
            result = part->FUN_001d6ab0();
    }
    return result;
}
} // namespace fn_00181b60


// 0x00181bd0 hulkfight::motion::PropMissileCountCondition::vfunc_6 (209 B): equivalent/0x00181bd0.cpp [wrapped: conflict: DAT_00494b44; hulkfight::motion::PropMissileCountCondition]
// sym: ?vfunc_6@PropMissileCountCondition@motion@hulkfight@fn_00181bd0@@UAE_NPAXPAUContext@4@0@Z @a2b1dc74eb65 @w0b49bc751ec9
namespace fn_00181bd0 {
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 30/30)
// hulkfight::motion::PropMissileCountCondition::vfunc_6 @ 0x00181bd0
struct TypeDescriptor_181bd0 { unsigned int data; }; extern TypeDescriptor_181bd0 DAT_00494b44, DAT_00494b60;
extern "C++" __declspec(nothrow) void* __cdecl FUN_00344e74(void*, int, TypeDescriptor_181bd0*, TypeDescriptor_181bd0*, int);
struct MissileSource { int FUN_001d6c50(); };
struct Actor_181bd0 { char pad[0x128]; MissileSource* active; MissileSource* FUN_00035ef0(int); };
struct ActorHandle { Actor_181bd0* FUN_00059a30(); };
struct Context { ActorHandle* FUN_000592a0(); };
namespace hulkfight { namespace motion {
struct PropMissileCountCondition {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(void*, Context*, void*);
 char pad[8]; int slot; unsigned int comparison; int threshold;
};
bool PropMissileCountCondition::vfunc_6(void*, Context* context, void*) {
 if (!FUN_00344e74(context,0,&DAT_00494b44,&DAT_00494b60,0)) return false;
 Actor_181bd0* actor = context->FUN_000592a0()->FUN_00059a30();
 int index = slot;
 if (!actor) return false;
 MissileSource* source;
 if (index < 0) source = actor->active;
 else { if (index >= 8) return false; source = actor->FUN_00035ef0(index); }
 if (!source) return false;
 int count = source->FUN_001d6c50();
 switch (comparison) {
 case 0: return count < threshold;
 case 1: return count <= threshold;
 case 2: return count == threshold;
 case 3: return count != threshold;
 case 4: return count >= threshold;
 case 5: return count > threshold;
 default: return false;
 }
}
}}
} // namespace fn_00181bd0

