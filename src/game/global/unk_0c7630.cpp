// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c7630..0x000c8200 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9a0caab {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9a0caab {} using namespace fn_f9a0caab;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9a0caab {
namespace pure3d {
class DrawableHierarchy {
public:
    virtual void AddRef();
    virtual void Release();
};
}
namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};
} }
namespace content { namespace LoadInventory {
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
struct Key_c7630 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
};
struct NameHolder_c7630 {
    char pad[8];
};
namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0_00038290();
    char pad04[4];
    NameHolder_c7630 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}
struct IconSlot {
    int id;
    int f4;
    int f8;
    int fc;
    Key_c7630 key;
    int f18;
    int pad1c;
};
class Factory_c7630 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual pure3d::DrawableHierarchy *f3(content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *caster,
                                          unsigned int lo, unsigned int hi);
};
struct Holder44_c7630 { Factory_c7630 *FUN_00203d70(); };
struct Holder28_c7630 { Holder44_c7630 *FUN_000862a0(); };
} // namespace fn_f9a0caab
struct World { char pad0[0x54]; Holder28_c7630 *holder; };
namespace fn_f9a0caab {
class CHudIcons : public pure3d::Entity {
public:
    virtual void v1_000382a0();
    virtual void v2();
    virtual void v3_0027afe0();
    virtual void v4_0027aff0();
    char enabled;
    char pad11[3];
    int f14;
    int f18;
    pure3d::DrawableHierarchy* enemyShape;
    pure3d::DrawableHierarchy* arrowRed;
    pure3d::DrawableHierarchy* smashShape;
    pure3d::DrawableHierarchy* arrowRed2;
    pure3d::DrawableHierarchy* grabShape;
    pure3d::DrawableHierarchy* arrowYellow;
    pure3d::DrawableHierarchy* defendShape;
    pure3d::DrawableHierarchy* arrowBlue;
    pure3d::DrawableHierarchy* gotoShape;
    pure3d::DrawableHierarchy* arrowGreen;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    char pad5c[4];
    IconSlot slots[16];
    CHudIcons();
};
class Obj_c7920 {
  public:
    Obj_c7920* Get();
};
struct V3 {
    int x, y, z;
};
struct V2 {
    int x, y;
};
class Obj_c79a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
class Container_c79a0 {
  public:
    char pad[0x10];
    Obj_c79a0* member;

    void Fn();
};
class Target_c7ac0 {
    char pad[0x20];

  public:
    unsigned char value;
    void __fastcall set() { value = 1; }
};
class Provider {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Count();
};
struct Holder {
    char pad[16];
    Provider* provider;
    int GetCount() { return provider->Count(); }
};
class Obj {
  public:
    char _m_pad_0[0x8];
    V3* a;
    char _m_pad_c[0x4];
    union { int* b; Holder* holder; };
    V2* c;
    char _m_pad_18[0x28];
    float factor;
    char _m_pad_44[0x1cc];
    float second;
    char _m_pad_214[0x4];
    float first;
    char _m_pad_21c[0x273c];
    char enabled;
    char _m_pad_2959[0x3];
    void Set(const V3* p, int n, const V2* q);
    void Update_0008ef00();
    void Update(float x);
};
struct X_c7b60 {
    char pad[0x14];
    unsigned value;
};
struct Timer {
 unsigned int a,b;
 Timer* FUN_0027af00();
 void FUN_0027af70(Timer* source);
 void FUN_0027af50();
};
struct Entry_c7b70 {
 int id;
 unsigned int x,y,z;
 unsigned int zero0,zero1,zero2,zero3,zero4;
 char pad[4];
 Timer timer;
 int state;
 unsigned int zero5,zero6;
 unsigned char flag0,flag1;
 char tail[2];
};
struct Manager_c7b70 {
 char pad[0x258];
 Entry_c7b70 entries[128];
 int FUN_000c7b70(int id,unsigned int x,unsigned int y,unsigned int z);
};
struct Resource_c7e80 { unsigned char bytes[8]; Resource_c7e80* FUN_0027af00(); void FUN_0027af70(Resource_c7e80*); void FUN_0027af50(); };
struct Entry_c7e80 { int type; unsigned int a,b,c,d,e,f,g,h; char pad[4]; Resource_c7e80 resource; char reserved[8]; unsigned int value; unsigned char flag; char end[3]; };
struct Object { char pad[0x258]; Entry_c7e80 entries[128]; int target(unsigned int arg1, unsigned int arg2); };
struct Name_c8010 {
    int lo, hi;
    Name_c8010* FUN_0027af00();
    void FUN_0027af70(Name_c8010* src);
    void FUN_0027af50();
};
struct Slot_c8010 {
    int tag;            // -1 when free
    int a, b, c;
    unsigned __int64 id;
    int d, e, f;
    char pad[4];
    Name_c8010 name;
    int g;
    char pad2[4];
    int h;
    char used;
    char pad3[3];
};
struct SlotTable_c8010 {
    char pad[0x258];
    Slot_c8010 slot[0x80];
    void Reset();
};
struct Name_c80a0 {
    int lo, hi;
    Name_c80a0* FUN_0027af00();
    void FUN_0027af70(Name_c80a0* src);
    void FUN_0027af50();
};
struct Slot_c80a0 {
    int tag;            // -1 when free
    int a, b, c;
    unsigned __int64 id;
    int d, e, f;
    char pad[4];
    Name_c80a0 name;
    int g;
    char pad2[4];
    int h;
    char used;
    char pad3[3];
};
struct SlotTable_c80a0 {
    char pad[0x258];
    Slot_c80a0 slot[0x80];
    void Release(int tag);
};


// 0x000c7630 FUN_000c7630 (751 B): equivalent/0x000c7630.cpp
// sym: ??0CHudIcons@fn_f9a0caab@@QAE@XZ @92ef8dc17464 @wc34e481f9e92
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 42/42)
// FUN_000c7630 @ 0x000c7630
// equiv-map: ?FUN_0008d690@@YAPAXI@Z = 0x00263ea0
CHudIcons::CHudIcons()
{
    enabled = 1;
    for (int i = 0; i < 16; i++) {
        slots[i].id = -1;
        slots[i].f4 = 0;
        slots[i].f8 = 0;
        slots[i].fc = 0;
        slots[i].key.FUN_0027af00();
        slots[i].f18 = 0;
    }
    Factory_c7630 *factory = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70();
    f14 = 0;
    f18 = 0;
    enemyShape = 0;
    arrowRed = 0;
    smashShape = 0;
    arrowRed2 = 0;
    grabShape = 0;
    arrowYellow = 0;
    defendShape = 0;
    arrowBlue = 0;
    gotoShape = 0;
    arrowGreen = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f50 = 0;
    f54 = 0;
    f58 = 0;
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_enemyShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (enemyShape)
            enemyShape->Release();
        enemyShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_smashShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (smashShape)
            smashShape->Release();
        smashShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_grabShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (grabShape)
            grabShape->Release();
        grabShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_defendShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (defendShape)
            defendShape->Release();
        defendShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_indicator_gotoShape");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (gotoShape)
            gotoShape->Release();
        gotoShape = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_red");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowRed)
            arrowRed->Release();
        arrowRed = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_red");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowRed2)
            arrowRed2->Release();
        arrowRed2 = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_yellow");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowYellow)
            arrowYellow->Release();
        arrowYellow = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_blue");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowBlue)
            arrowBlue->Release();
        arrowBlue = obj;
    }
    {
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> caster;
        unsigned __int64 key = FUN_0027b020("target_arrow_green");
        pure3d::DrawableHierarchy *obj = factory->f3(&caster, (unsigned int)key, (unsigned int)(key >> 32));
        if (obj)
            obj->AddRef();
        if (arrowGreen)
            arrowGreen->Release();
        arrowGreen = obj;
    }
}


// 0x000c7920 FUN_000c7920 (3 B): matches/0x000c7920.cpp
// sym: ?Get@Obj_c7920@fn_f9a0caab@@QAEPAV12@XZ
Obj_c7920* Obj_c7920::Get() {
    return this;
}


// 0x000c7940 FUN_000c7940 (59 B): matches/0x000c7940.cpp
// sym: ?Set@Obj@fn_f9a0caab@@QAEXPBUV3@2@HPBUV2@2@@Z
void Obj::Set(const V3* p, int n, const V2* q) {
    V3* d = a;
    d->x = p->x;
    d->y = p->y;
    d->z = p->z;
    *b = n;
    *c = *q;
    Update_0008ef00();
}


// 0x000c79a0 FUN_000c79a0 (8 B): matches/0x000c79a0.cpp
// sym: ?Fn@Container_c79a0@fn_f9a0caab@@QAEXXZ
void Container_c79a0::Fn() {
    member->f7();
}

} // namespace fn_f9a0caab

// 0x000c7a10 FUN_000c7a10 (57 B): equivalent/0x000c7a10.cpp [wrapped: conflict: Obj]
// sym: ?FUN_000c7a10@Obj@fn_000c7a10@@QAEPAU12@XZ @b42071f93db1 @wa4201efaa2a3
namespace fn_000c7a10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000c7a10 @ 0x000c7a10
struct Sub { void FUN_0027af00(); char data[8]; }; struct Obj { int a,b,c,d; Sub sub; int f18,f1c,f20,f24,f28,f2c,f30,f34; Obj* FUN_000c7a10(); }; Obj* Obj::FUN_000c7a10() { a=b=c=d=0; sub.FUN_0027af00(); f18=f1c=f20=f24=f28=f2c=0; f30=f34=-1; return this; }
} // namespace fn_000c7a10

namespace fn_f9a0caab {

// 0x000c7ac0 FUN_000c7ac0 (5 B): matches/0x000c7ac0.cpp
// sym: ?FUN_000c7ac0@fn_f9a0caab@@YIXPAVTarget_c7ac0@1@@Z
void __fastcall FUN_000c7ac0(Target_c7ac0* self) {
    self->value = 1;
}

} // namespace fn_f9a0caab

// 0x000c7ad0 FUN_000c7ad0 (5 B): matches/0x000c7ad0.cpp
// sym: ?FUN_000c7ad0@Target_c7ad0@owners@@QAEXXZ
void owners::Target_c7ad0::FUN_000c7ad0() {
    field = 0;
}


// 0x000c7ae0 FUN_000c7ae0 (13 B): matches/0x000c7ae0.cpp
// sym: ?FUN_000c7ae0@C_c7ae0@owners@@QAEXH@Z
void owners::C_c7ae0::FUN_000c7ae0(int x) {
    value = x;
}


// 0x000c7af0 FUN_000c7af0 (15 B): matches/0x000c7af0.cpp
// sym: ?FUN_000c7af0@C_c7af0@owners@@QAEXXZ
void owners::C_c7af0::FUN_000c7af0() {
    a = 1;
    b = 1;
}

namespace fn_f9a0caab {

// 0x000c7b00 FUN_000c7b00 (68 B): matches/0x000c7b00.cpp
// sym: ?Update@Obj@fn_f9a0caab@@QAEXM@Z
// data: scale = DAT_0049fbc0
void Obj::Update(float x) {
    enabled = 0;
    int n = holder->GetCount();
#if defined(__clang__)
    hulk_freg v = x * factor / ((float)n * DAT_0049fbc0);
    first = v;
    second = v * DAT_0049fbc0; // the original multiplies the unrounded quotient
#else
    float v = x * factor / ((float)n * DAT_0049fbc0);
    first = v;
    second = first * DAT_0049fbc0;
#endif
}


// 0x000c7b60 FUN_000c7b60 (4 B): matches/0x000c7b60.cpp
// sym: ?target@fn_f9a0caab@@YIIPAUX_c7b60@1@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
hulk_uintptr __fastcall target(X_c7b60* self) {
    return self->value;
}


// 0x000c7b70 FUN_000c7b70 (228 B): equivalent/0x000c7b70.cpp
// sym: ?FUN_000c7b70@Manager_c7b70@fn_f9a0caab@@QAEHHIII@Z @01f5e962dbf0 @wd78280316cf5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c7b70 @ 0x000c7b70
int Manager_c7b70::FUN_000c7b70(int id,unsigned int x,unsigned int y,unsigned int z) {
 int i;
 for(i=0;i<128;++i) if(entries[i].id==-1) break;
 if(i==128) return -1;
 Entry_c7b70 &e=entries[i];
 e.id=id;
 Timer temp;
 Timer* result=temp.FUN_0027af00();
 e.timer.FUN_0027af70(result);
 temp.FUN_0027af50();
 e.state=2;
 e.y=y;
 e.x=x;
 e.z=z;
 e.zero1=0;
 e.zero0=0;
 e.zero2=0;
 e.zero3=0;
 e.zero4=0;
 e.zero5=0;
 e.zero6=0;
 e.flag0=0;
 e.flag1=0;
 return i;
}

} // namespace fn_f9a0caab

// 0x000c7c60 FUN_000c7c60 (168 B): equivalent/0x000c7c60.cpp [wrapped: conflict: World]
// sym: ?FUN_000c7c60@Owner_c7c60@fn_000c7c60@@QAEHIPBX@Z @7bbd497d29cc @wbb3be02e3e6a
namespace fn_000c7c60 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 10/10)
// FUN_000c7c60 @ 0x000c7c60
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

struct __declspec(align(8)) Value_c7c60 { unsigned int low, high; bool FUN_0027af90(const void* other); void FUN_0027af50(); };
void __cdecl FUN_00096e50(Value_c7c60* result, const void* input);
struct Lookup_c7c60 { int FUN_00024280(unsigned int low, unsigned int high); };
struct Checker_c7c60 { bool FUN_001dd7b0(Value_c7c60* value); };
struct World { char pad[12]; Checker_c7c60* checker; char pad2[16]; Lookup_c7c60* lookup; };
struct Slot_c7c60 { unsigned int key; char padding[36]; char value[24]; };
struct Owner_c7c60 { char padding[0x258]; Slot_c7c60 slots[128]; int FUN_000c7c60(unsigned int key, const void* input); };
int Owner_c7c60::FUN_000c7c60(unsigned int key, const void* input) {
 Value_c7c60 value;
 FUN_00096e50(&value, input);
 if (DAT_004dd700->lookup->FUN_00024280(value.low, value.high) || DAT_004dd700->checker->FUN_001dd7b0(&value)) {
  for (int i=0;i<128;++i) {
   if (slots[i].key == key && value.FUN_0027af90(slots[i].value)) {
    value.FUN_0027af50();
    return i;
   }
  }
 }
 value.FUN_0027af50();
 return -1;
}
} // namespace fn_000c7c60
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000c7d10 FUN_000c7d10 (353 B): equivalent/0x000c7d10.cpp [wrapped: conflict: World]
// sym: ?FUN_000c7d10@Table_c7d10@fn_000c7d10@@QAEHHH@Z @37cbadbf78aa @wb08bbed53729
namespace fn_000c7d10 {
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 9/10, incomplete)
// FUN_000c7d10 @ 0x000c7d10
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

struct Key_c7d10 {
    int lo, hi;
    void FUN_0027af50();
};

struct Str8 {
    char pad[8];
    void FUN_0027af70(Key_c7d10 *k);
};

struct Entry_c7d10 {
    int key;
    int f4, f8, fc, f10, f14, f18, f1c, f20;
    char pad24[4];
    Str8 str;
    int flag;
    int f34;
    int f38;
    char b3c;
    char b3d;
    char pad3e[2];
};

struct Registry_c7d10 {
    int FUN_00024280(int id0, int id1);
};

struct Lookup_c7d10 {
    bool FUN_001dd7b0(Key_c7d10 *k);
};

struct World {
    char pad0[0xc];
    Lookup_c7d10 *lookup;
    char pad10[0x20 - 0x10];
    Registry_c7d10 *registry;
};


void __cdecl FUN_00096e50(Key_c7d10 *k, int name);

class Table_c7d10 {
public:
    char pad0[0x258];
    Entry_c7d10 entries[128];
    int FUN_000c7c60(int a, int b);
    int FUN_000c7d10(int a, hulk_intptr b);
};

int Table_c7d10::FUN_000c7d10(int a, hulk_intptr b)
{
    int slot = FUN_000c7c60(a, b);
    if (slot != -1)
        return slot;

    Key_c7d10 key;
    int flag;
    FUN_00096e50(&key, b);
    if (DAT_004dd700->registry->FUN_00024280(key.lo, key.hi)) {
        flag = 0;
    } else {
        if (!DAT_004dd700->lookup->FUN_001dd7b0(&key)) {
            key.FUN_0027af50();
            return -1;
        }
        flag = 1;
    }

    int i;
    for (i = 0; i < 128; i++) {
        if (entries[i].key == -1)
            break;
    }
    if (i == 128) {
        key.FUN_0027af50();
        return slot;
    }

    Entry_c7d10 *e = &entries[i];
    e->key = a;
    e->str.FUN_0027af70(&key);
    e->flag = flag;
    e->f4 = 0;
    e->f8 = 0;
    e->fc = 0;
    e->f10 = 0;
    e->f14 = 0;
    e->f18 = 0;
    e->f1c = 0;
    e->f20 = 0;
    e->f34 = 0;
    e->f38 = 0;
    e->b3c = 0;
    e->b3d = 0;
    key.FUN_0027af50();
    return i;
}
} // namespace fn_000c7d10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9a0caab {

// 0x000c7e80 FUN_000c7e80 (198 B): equivalent/0x000c7e80.cpp
// sym: ?target@Object@fn_f9a0caab@@QAEHII@Z @45fdde107449 @wa6ce94e7e9d8
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c7e80 @ 0x000c7e80
int Object::target(unsigned int arg1, unsigned int arg2) { int i; for(i=0;i<128;++i) if(entries[i].type==-1) break; if(i==128) return -1; Entry_c7e80& e=entries[i]; e.type=5; Resource_c7e80 temporary; Resource_c7e80* p=temporary.FUN_0027af00(); e.resource.FUN_0027af70(p); temporary.FUN_0027af50(); e.a=0; e.b=0; e.c=0; e.d=0; e.e=0; e.f=0; e.g=0; e.h=0; e.value=arg1; e.flag=0; return i; }

} // namespace fn_f9a0caab

// 0x000c7f50 FUN_000c7f50 (191 B): equivalent/0x000c7f50.cpp [wrapped: conflict: Object; World]
// sym: ?target@Object@fn_000c7f50@@QAEHEH@Z @9bb895a806b0 @webe3538e6f8e
namespace fn_000c7f50 {
// STATUS: equivalent (tools/equiv.py level 3: 795 inputs, branch coverage 32/32)
// FUN_000c7f50 @ 0x000c7f50
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

struct Item_c7f50 { int FUN_00204200(int, int, int); };
struct Manager_c7f50 {  };
struct World { char pad[0x54]; Manager_c7f50* manager; };
struct Entry_c7f50 { int active; int x; int y; int z; char pad[0x24]; int value; char tail[8]; };
struct Object { char pad[0x258]; Entry_c7f50 entries[128]; int target(unsigned char flag, int value); };
int Object::target(unsigned char flag, int value) {
 int result;
 for(int i=0;i<128;++i) {
  Entry_c7f50& e=entries[i];
  result=e.active;
  if(result>0) {
   int x=e.x,y=e.y,z=e.z;
   result=((Item_c7f50 *)((owners::Target_862a0 *)(DAT_004dd700->manager))->FUN_000862a0())->FUN_00204200(x,y,z);
   unsigned char selected=0;
   switch(result) {
    case 0x1e2: case 0x1ff: case 0x200: case 0x201: case 0x21d: case 0x21e: case 0x21f: case 0x220: case 0x23b: case 0x23c: case 0x23d: case 0x23e: case 0x25b: selected=1;
   }
   if(flag!=selected) { result=value; e.value=value; }
   else e.value=0;
  }
 }
 return result;
}
} // namespace fn_000c7f50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9a0caab {

// 0x000c8010 FUN_000c8010 (138 B): equivalent/0x000c8010.cpp
// sym: ?Reset@SlotTable_c8010@fn_f9a0caab@@QAEXXZ @37afff6ea2a3 @w3fc22216fe7a
// STATUS: equivalent (tools/equiv.py level 3: 663 inputs, branch coverage 4/4)
// FUN_000c8010 @ 0x000c8010
void SlotTable_c8010::Reset() {
    for (int i = 0; i < 0x80; i++) {
        Slot_c8010* s = &slot[i];
        if (s->used == 1) continue;
        s->tag = -1;
        Name_c8010 tmp;
        s->name.FUN_0027af70(tmp.FUN_0027af00());
        tmp.FUN_0027af50();
        s->g = -1;
        s->a = 0; s->b = 0; s->c = 0;
        unsigned __int64 zero = 0;
        s->id = zero;
        s->d = 0; s->e = 0; s->f = 0;
        s->h = 0;
        s->used = 0;
    }
}


// 0x000c80a0 FUN_000c80a0 (149 B): equivalent/0x000c80a0.cpp
// sym: ?Release@SlotTable_c80a0@fn_f9a0caab@@QAEXH@Z @290aa2d3ffff @w1c6d8b38438c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c80a0 @ 0x000c80a0
// Frees every slot holding the given tag.
void SlotTable_c80a0::Release(int tag) {
    for (int i = 0; i < 0x80; i++) {
        Slot_c80a0* s = &slot[i];
        if (s->tag != tag) continue;
        s->tag = -1;
        Name_c80a0 tmp;
        s->name.FUN_0027af70(tmp.FUN_0027af00());
        tmp.FUN_0027af50();
        s->g = -1;
        s->a = 0; s->b = 0; s->c = 0;
        unsigned __int64 zero = 0;
        s->id = zero;
        s->d = 0; s->e = 0; s->f = 0;
        s->h = 0;
        s->used = 0;
    }
}


// 0x000c8180 FUN_000c8180 (6 B): matches/0x000c8180.cpp
// sym: ?FUN_000c8180@fn_f9a0caab@@YAIPAX@Z
unsigned int FUN_000c8180(void* /*this, unused: callers pass it (unb4)*/) {
    return 0x80;
}

} // namespace fn_f9a0caab

// 0x000c8190 FUN_000c8190 (51 B): matches/0x000c8190.cpp
// sym: ?FUN_000c8190@X_c8190@owners@@QAEPAHH@Z
int* owners::X_c8190::FUN_000c8190(int i) {
    if (i < 0 || i >= 128)
        return 0;
    int* p = (int*)((char*)this + 0x258 + i * 64);
    return (int*)((hulk_uintptr)p & ((*p == -1) - 1));
}

