// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1ed0..0x001aace0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::EffectAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "gen/fight.h"
#define TREE_TU_BEGIN namespace fn_fabb071b {
#define TREE_TU_END }
namespace fn_fabb071b {} using namespace fn_fabb071b;
#include "game/hulkfight/scenario.h"

// ---- declarations shared by the functions below
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_fabb071b {
extern "C" void* FUN_0008d690(unsigned int size);
} // namespace fn_fabb071b
namespace hulkfight { namespace scenario {
class NodeIsNotRunningCondition_1a6f30 {
public:
    void FUN_001a1ed0();
};
} }
namespace fn_fabb071b {
class __declspec(novtable) ParamBoolBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamBoolBase(const char* name) { ((fight::ParamValueBool *)this)->FUN_00234860(name); }
};
} // namespace fn_fabb071b
namespace fight {
template <class T>
class ParamBool_1a6f30 : public ParamBoolBase {
public:
    ParamBool_1a6f30(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fabb071b {
extern "C" void FUN_002347b0(ParamRegistry* reg, void** params, int count);
} // namespace fn_fabb071b
namespace hulkfight { namespace scenario {
class NodeShouldRunImmediatelyCondition_1a6f90 {
public:
    void FUN_001a1ef0();
};
} }
namespace fight {
template <class T>
class ParamBool_1a6f90 : public ParamBoolBase {
public:
    ParamBool_1a6f90(const char* name, void (T::*s)()) : ParamBoolBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace scenario {
class Event_StringCondition_1a9500 {
public:
    void FUN_001a1ee0();
};
} }
namespace fn_fabb071b {
class __declspec(novtable) ParamNameBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameBase(const char* name) { ((fight::ParamValueName *)this)->FUN_00234a90(name); }
};
} // namespace fn_fabb071b
namespace fight {
template <class T>
class ParamName_1a9500 : public ParamNameBase {
public:
    ParamName_1a9500(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace scenario {
class Event_PropTypeCondition_1a9650 {
public:
    void FUN_001a1f50();
};
} }
namespace fight {
template <class T>
class ParamName_1a9650 : public ParamNameBase {
public:
    ParamName_1a9650(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace scenario {
class Event_PropStateNameCondition_1a96e0 {
public:
    void FUN_001a1f60();
};
} }
namespace fight {
template <class T>
class ParamName_1a96e0 : public ParamNameBase {
public:
    ParamName_1a96e0(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace hulkfight { namespace scenario {
class Event_PropNameCondition_1a9770 {
public:
    void FUN_001a1f70();
};
} }
namespace fight {
template <class T>
class ParamName_1a9770 : public ParamNameBase {
public:
    ParamName_1a9770(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fabb071b {
class EffectTrack {
public:
    void FUN_001a1f80();
    void FUN_001a1fa0();
    void FUN_001a1fb0();
    void FUN_001a1fc0();
    void FUN_001a1fe0();
    void FUN_001a1ff0();
    void FUN_001a2020();
    void FUN_001a2060();
    void FUN_001a20b0();
    void FUN_001a20c0();
    void FUN_001a20e0();
};
} // namespace fn_fabb071b
namespace fight {
template <class T>
class ParamEnumConstList_1a9800 : public ParamEnumConstListBase {
public:
    ParamEnumConstList_1a9800(const char* name, const char** n, int c, void (T::*s)())
        : ParamEnumConstListBase(name) { count = c; names = n; setter = s; }
    virtual void v0();
    const char** names;
    int count;
    void (T::*setter)();
    int unused1c;
};
}
namespace fn_fabb071b {
class __declspec(novtable) ParamFloatConstRangeBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamFloatConstRangeBase(const char* name) { ((fight::ParamValueFloat *)this)->FUN_00234960(name); }
};
} // namespace fn_fabb071b
namespace fight {
template <class T>
class ParamFloatConstRange_1a9800 : public ParamFloatConstRangeBase {
public:
    ParamFloatConstRange_1a9800(const char* name, void (T::*s)()) : ParamFloatConstRangeBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamName_1a9800 : public ParamNameBase {
public:
    ParamName_1a9800(const char* name, void (T::*s)()) : ParamNameBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fn_fabb071b {
class __declspec(novtable) ParamNameConstListBase {
public:
    virtual void v0();
    char pad04[0xc];
    ParamNameConstListBase(const char* name) { ((fight::ParamValueNameList *)this)->FUN_00234ba0(name); }
};
} // namespace fn_fabb071b
namespace fight {
template <class T>
class ParamNameConstList_1a9800 : public ParamNameConstListBase {
public:
    ParamNameConstList_1a9800(const char* name, void (T::*s)()) : ParamNameConstListBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}
namespace fight {
template <class T>
class ParamVector_1a9800 : public ParamVectorBase {
public:
    ParamVector_1a9800(const char* name, void (T::*s)()) : ParamVectorBase(name) { setter = s; }
    virtual void v0();
    void (T::*setter)();
    int unused14;
};
}

namespace fn_fabb071b {

// 0x001a6f30 FUN_001a6f30 (95 B): equivalent/0x001a6f30.cpp
// sym: ?FUN_001a6f30@fn_fabb071b@@YAXXZ @cb77700d4f91 @wb9188fa4a502
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001a6f30 @ 0x001a6f30
void FUN_001a6f30()
{
    if (DAT_004e170c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1a6f30<hulkfight::scenario::NodeIsNotRunningCondition_1a6f30>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1a6f30<hulkfight::scenario::NodeIsNotRunningCondition_1a6f30>("nodeIsNotRunning", &hulkfight::scenario::NodeIsNotRunningCondition_1a6f30::FUN_001a1ed0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1708), params, 1);
    }
    DAT_004e170c++;
}


// 0x001a6f90 FUN_001a6f90 (95 B): equivalent/0x001a6f90.cpp
// sym: ?FUN_001a6f90@fn_fabb071b@@YAXXZ @35bf17a07407 @we5a44410c0e3
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_001a6f90 @ 0x001a6f90
void FUN_001a6f90()
{
    if (DAT_004e171c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamBool_1a6f90<hulkfight::scenario::NodeShouldRunImmediatelyCondition_1a6f90>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamBool_1a6f90<hulkfight::scenario::NodeShouldRunImmediatelyCondition_1a6f90>("thisBooleanDoesNothing", &hulkfight::scenario::NodeShouldRunImmediatelyCondition_1a6f90::FUN_001a1ef0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1718), params, 1);
    }
    DAT_004e171c++;
}


// 0x001a9500 FUN_001a9500 (95 B): equivalent/0x001a9500.cpp
// sym: ?FUN_001a9500@fn_fabb071b@@YAXXZ @69b785f2d628 @wc837dd2ac75a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001a9500 @ 0x001a9500
void FUN_001a9500()
{
    if (DAT_004e1714 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a9500<hulkfight::scenario::Event_StringCondition_1a9500>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_1a9500<hulkfight::scenario::Event_StringCondition_1a9500>("string", &hulkfight::scenario::Event_StringCondition_1a9500::FUN_001a1ee0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1710), params, 1);
    }
    DAT_004e1714++;
}


// 0x001a9650 FUN_001a9650 (95 B): equivalent/0x001a9650.cpp
// sym: ?FUN_001a9650@fn_fabb071b@@YAXXZ @94fd076b770a @w978e35b919dc
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 4/4)
// FUN_001a9650 @ 0x001a9650
void FUN_001a9650()
{
    if (DAT_004e173c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a9650<hulkfight::scenario::Event_PropTypeCondition_1a9650>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_1a9650<hulkfight::scenario::Event_PropTypeCondition_1a9650>("propType", &hulkfight::scenario::Event_PropTypeCondition_1a9650::FUN_001a1f50);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1738), params, 1);
    }
    DAT_004e173c++;
}


// 0x001a96e0 FUN_001a96e0 (95 B): equivalent/0x001a96e0.cpp
// sym: ?FUN_001a96e0@fn_fabb071b@@YAXXZ @35e19015f912 @we243e457be4a
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_001a96e0 @ 0x001a96e0
void FUN_001a96e0()
{
    if (DAT_004e1744 == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a96e0<hulkfight::scenario::Event_PropStateNameCondition_1a96e0>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_1a96e0<hulkfight::scenario::Event_PropStateNameCondition_1a96e0>("stateName", &hulkfight::scenario::Event_PropStateNameCondition_1a96e0::FUN_001a1f60);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1740), params, 1);
    }
    DAT_004e1744++;
}


// 0x001a9770 FUN_001a9770 (95 B): equivalent/0x001a9770.cpp
// sym: ?FUN_001a9770@fn_fabb071b@@YAXXZ @7132b9f52571 @wcc0a476a0f78
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// FUN_001a9770 @ 0x001a9770
void FUN_001a9770()
{
    if (DAT_004e174c == 0) {
        void* params[1];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a9770<hulkfight::scenario::Event_PropNameCondition_1a9770>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamName_1a9770<hulkfight::scenario::Event_PropNameCondition_1a9770>("propName", &hulkfight::scenario::Event_PropNameCondition_1a9770::FUN_001a1f70);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1748), params, 1);
    }
    DAT_004e174c++;
}


// 0x001a9800 FUN_001a9800 (647 B): equivalent/0x001a9800.cpp
// sym: ?FUN_001a9800@fn_fabb071b@@YAXXZ @8f7042a57027 @w909108f129b9
// STATUS: equivalent (tools/equiv.py level 3: 66 inputs, branch coverage 24/24)
// FUN_001a9800 @ 0x001a9800
void FUN_001a9800()
{
    if (DAT_004e1754 == 0) {
        void* params[11];
        void* mem;
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1a9800<EffectTrack>));
        params[0] = 0;
        if (mem)
            params[0] = new (mem) fight::ParamFloatConstRange_1a9800<EffectTrack>("timeBegin", &EffectTrack::FUN_001a1f80);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1a9800<EffectTrack>));
        params[1] = 0;
        if (mem)
            params[1] = new (mem) fight::ParamFloatConstRange_1a9800<EffectTrack>("timeEnd", &EffectTrack::FUN_001a1fa0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a9800<EffectTrack>));
        params[2] = 0;
        if (mem)
            params[2] = new (mem) fight::ParamName_1a9800<EffectTrack>("characterName", &EffectTrack::FUN_001a1fb0);
        mem = FUN_0008d690((int)sizeof(fight::ParamName_1a9800<EffectTrack>));
        params[3] = 0;
        if (mem)
            params[3] = new (mem) fight::ParamName_1a9800<EffectTrack>("effectName", &EffectTrack::FUN_001a1fc0);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1a9800<EffectTrack>));
        params[4] = 0;
        if (mem)
            params[4] = new (mem) fight::ParamEnumConstList_1a9800<EffectTrack>("emitSpace", ((const char**)&DAT_00495d60), (*(int*)&DAT_003fa9e8), &EffectTrack::FUN_001a1fe0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_1a9800<EffectTrack>));
        params[5] = 0;
        if (mem)
            params[5] = new (mem) fight::ParamNameConstList_1a9800<EffectTrack>("emitJoint", &EffectTrack::FUN_001a1ff0);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1a9800<EffectTrack>));
        params[6] = 0;
        if (mem)
            params[6] = new (mem) fight::ParamVector_1a9800<EffectTrack>("offset", &EffectTrack::FUN_001a2020);
        mem = FUN_0008d690((int)sizeof(fight::ParamVector_1a9800<EffectTrack>));
        params[7] = 0;
        if (mem)
            params[7] = new (mem) fight::ParamVector_1a9800<EffectTrack>("orientation", &EffectTrack::FUN_001a2060);
        mem = FUN_0008d690((int)sizeof(fight::ParamEnumConstList_1a9800<EffectTrack>));
        params[8] = 0;
        if (mem)
            params[8] = new (mem) fight::ParamEnumConstList_1a9800<EffectTrack>("attachSpace", ((const char**)&DAT_00495d50), (*(int*)&DAT_003fa9e4), &EffectTrack::FUN_001a20b0);
        mem = FUN_0008d690((int)sizeof(fight::ParamNameConstList_1a9800<EffectTrack>));
        params[9] = 0;
        if (mem)
            params[9] = new (mem) fight::ParamNameConstList_1a9800<EffectTrack>("attachJoint", &EffectTrack::FUN_001a20c0);
        mem = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange_1a9800<EffectTrack>));
        params[10] = 0;
        if (mem)
            params[10] = new (mem) fight::ParamFloatConstRange_1a9800<EffectTrack>("scale", &EffectTrack::FUN_001a20e0);
        FUN_002347b0(((ParamRegistry*)&DAT_004e1750), params, 11);
    }
    DAT_004e1754++;
}

} // namespace fn_fabb071b

// 0x001a9b10 FUN_001a9b10 (1021 B): equivalent/0x001a9b10.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster; pure3d::CompositeDrawable; pure3d::DrawableHierarchy; pure3d::Entity (+2)]
// sym: ?FUN_001a9b10@AnimSetup@fn_001a9b10@@QAE_NPAUOut_1a9b10@2@PBD1_N2H2@Z @76aee2ab8faa @wa3202028c957
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001a9b10 {
// STATUS: equivalent (tools/equiv.py level 3: 19972 inputs, branch coverage 34/34)
// FUN_001a9b10 @ 0x001a9b10
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)


void *thunk_FUN_0008d690(unsigned int size);

namespace pure3d { class Animation; }

namespace content {
namespace LoadInventory {
template <class T>
class DynamicCaster {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d {
class Entity {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
};

class DrawableHierarchy {
public:
    virtual void h0();
    virtual void h1();
};

class CompositeDrawable : public Entity {
public:
    virtual Entity *vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void *vf11();
    char pad04[0x4c - 4];
    void *controller;
    void FUN_00298f90(void *ctrl);
};

namespace scenegraph {
class Node {
public:
    virtual void n0();
    virtual void n1();
};

class DrawableNode : public Node {
public:
    DrawableHierarchy *FUN_002960d0();
    void FUN_00296b80(CompositeDrawable *cd);
};
}
}

struct Vec3_1a9b10 {
    float x, y, z;
};

class Controller_1a9b10 {
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
    virtual void v24(pure3d::Animation *anim, unsigned int g, float t);
    char pad[0x150 - 4];
    Controller_1a9b10 *FUN_00287860();
    void FUN_000118c0(void *v);
    void FUN_00284ad0(int a);
};

struct Driver {
    char pad00[0x224];
    char b224;
    char pad225[7];
    float f22c;
    float f230;
    Driver *FUN_00225950(void *rig, pure3d::Animation *anim);
    void FUN_000118c0(void *v);
    void FUN_00225e00(float t, Vec3_1a9b10 v);
    float FUN_00225b30();
    void FUN_00225cf0(float v);
};

struct Context {
    char pad[4];
};

struct LayerSet_1a9b10 {
    char pad00[4];
    LayerSet_1a9b10 *FUN_00222620(void *tag);
    void FUN_000118c0(void *v);
    void *FUN_002226b0();
    void FUN_00222890(Driver *d, float t, int a, float b, float c, float e, float f);
};
LayerSet_1a9b10 *__fastcall FUN_00059a40(Context *ctx);

struct Item_1a9b10 {
    char pad00[0x10];
    Context *ctx;
    void FUN_0003dd00(int a);
    void FUN_00040170();
    void FUN_000354e0(float v);
    void FUN_00035250(Vec3_1a9b10 *v);
};

struct ModeB_1a9b10 {
    Item_1a9b10 *FUN_00024280(unsigned __int64 key);
};

struct World {
    char pad0[0x20];
    ModeB_1a9b10 *modeB;
};

class Inventory_1a9b10 {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual pure3d::Animation *Find(const content::LoadInventory::DynamicCaster<pure3d::Animation> &c, unsigned __int64 id);
    void *FUN_001a9420(const char *name);
};

struct Registry_1a9b10 {
    Inventory_1a9b10 *FUN_00203d60(int index);
};

struct SceneRoot_1a9b10 {
    pure3d::scenegraph::Node *FUN_002961e0(unsigned int lo, unsigned int hi, int a, int b);
};

class Owner_1a9b10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float vf7();
    char pad04[0x14 - 4];
    float f14;
    float f18;
    float f1c;
    float f20;
    char pad24[0x2c - 0x24];
    float f2c;
    char pad30[0x54 - 0x30];
    int f54;
};

struct Out_1a9b10 {
    char b0;
    char pad1[2];
    char b3;
    Driver *driver;
    LayerSet_1a9b10 *layers;
    Item_1a9b10 *item;
    pure3d::CompositeDrawable *drawable;
    pure3d::scenegraph::DrawableNode *node;
};

void FUN_0013a790(Driver **slot, Driver *v);
void FUN_00059c50(LayerSet_1a9b10 **slot, LayerSet_1a9b10 *v);
void FUN_00081070(pure3d::CompositeDrawable **slot, pure3d::CompositeDrawable *v);
void FUN_001a5a30(pure3d::scenegraph::DrawableNode **slot, pure3d::scenegraph::DrawableNode *v);
void FUN_00025960(Item_1a9b10 **slot, Item_1a9b10 *v);
float FUN_000964e0();
float __cdecl FUN_00225be0(float a, float b, float c, int d);

class AnimSetup {
public:
    char pad00[0x1c];
    Owner_1a9b10 *owner;
    char pad20[0x20c - 0x20];
    Registry_1a9b10 *registry;
    SceneRoot_1a9b10 *scene;
    unsigned char noOwner;

    void FUN_001a54a0(Vec3_1a9b10 *pos, float *angle);
    bool FUN_001a9b10(Out_1a9b10 *out, const char *animName, const char *name2, bool a, bool isCustom, int c, bool d);
};

bool AnimSetup::FUN_001a9b10(Out_1a9b10 *out, const char *animName, const char *name2, bool a, bool isCustom, int c, bool d)
{
    if (out == 0)
        return false;

    int idx;
    if (noOwner)
        idx = 0;
    else
        idx = owner->f54;
    Inventory_1a9b10 *inv = registry->FUN_00203d60(idx);

    content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
    pure3d::Animation *anim = inv->Find(caster, FUN_002672f0(animName, 0, 0));
    if (anim == 0)
        return false;

    void *rig;
    void *tag;
    LayerSet_1a9b10 *layers;
    Item_1a9b10 *item = 0;

    if (isCustom) {
        rig = inv->FUN_001a9420(name2);
        if (rig == 0)
            return false;

        unsigned __int64 h = FUN_002672f0(name2, 0, 0);
        pure3d::scenegraph::DrawableNode *dn = dynamic_cast<pure3d::scenegraph::DrawableNode *>(
            scene->FUN_002961e0((unsigned int)h, (unsigned int)(h >> 32), 0x10, c));
        if (dn == 0)
            return false;
        pure3d::CompositeDrawable *cd1 = dynamic_cast<pure3d::CompositeDrawable *>(dn->FUN_002960d0());
        if (cd1 == 0)
            return false;
        pure3d::CompositeDrawable *cd = dynamic_cast<pure3d::CompositeDrawable *>(cd1->vf4());
        dn->FUN_00296b80(cd);
        tag = cd->vf11();
        if (cd->controller == 0) {
            void *mem = thunk_FUN_0008d690(0x150);
            Controller_1a9b10 *ctrl = 0;
            if (mem != 0)
                ctrl = ((Controller_1a9b10 *)mem)->FUN_00287860();
            cd->FUN_00298f90(ctrl);
            ctrl->v24(anim, 0, 0.0f);
            ctrl->FUN_000118c0(cd);
            ctrl->v23();
            ctrl->FUN_00284ad0(1);
            out->b3 = 1;
        }
        FUN_00081070(&out->drawable, cd);
        FUN_001a5a30(&out->node, dn);
        void *mem2 = thunk_FUN_0008d690(0x2f0);
        layers = 0;
        if (mem2 != 0)
            layers = ((LayerSet_1a9b10 *)mem2)->FUN_00222620(tag);
        layers->FUN_000118c0(rig);
        FUN_00059c50(&out->layers, layers);
    } else {
        ModeB_1a9b10 *mb = DAT_004dd700->modeB;
        unsigned __int64 key = FUN_002672f0(name2, 0, 0);
        item = mb->FUN_00024280(key);
        if (item == 0)
            return false;
        item->FUN_0003dd00(1);
        if (a)
            item->FUN_00040170();
        FUN_00025960(&out->item, item);
        layers = FUN_00059a40(item->ctx);
        if (layers == 0)
            return false;
        FUN_00059c50(&out->layers, layers);
        rig = layers->FUN_002226b0();
    }

    void *mem3 = thunk_FUN_0008d690(0x240);
    Driver *nd = 0;
    if (mem3 != 0)
        nd = ((Driver *)mem3)->FUN_00225950(rig, anim);
    FUN_0013a790(&out->driver, nd);
    out->driver->FUN_000118c0(anim);
    Driver *drv = out->driver;
    drv->b224 = 0;

    Vec3_1a9b10 v;
    v.z = owner->f20;
    v.y = owner->f1c;
    v.x = owner->f14;
    drv->FUN_00225e00(owner->vf7(), v);
    layers->FUN_00222890(drv, drv->FUN_00225b30(), 1, 1.0f, 0.0f, 0.0f, -1.0f);

    hulk_freg f18 = owner->f18;
    hulk_freg val;
    if (f18 < 0.0f) {
        hulk_freg lo = drv->f22c;
        hulk_freg span = drv->f230 - lo;
        val = FUN_000964e0() * span + lo;
    } else {
        val = FUN_00225be0(f18, drv->f22c, drv->f230, 0);
    }
    drv->FUN_00225cf0(val);

    out->b0 = 1;
    if (!isCustom) {
        Vec3_1a9b10 pos;
        float angle;
        hulk_freg r = owner->f2c;
        FUN_001a54a0(&pos, &angle);
        if (d) {
            r += 3.55338573f;
            pos.x = pos.x + 0.01f;
        }
        item->FUN_000354e0(angle + r);
        item->FUN_00035250(&pos);
    }
    return true;
}
} // namespace fn_001a9b10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

