// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00045820..0x00047970 (kind game, layer game, confidence high), dominant class CCharacterTemplateManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/content.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8b6a7cf {
#define TREE_TU_END }
namespace fn_f8b6a7cf {} using namespace fn_f8b6a7cf;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8b6a7cf {
class X_45820 {
  public:
    virtual void a();
    virtual void b();
};
struct C_45820 {
    X_45820* p;
    void f();
};
struct Key_45da0 {
    unsigned lo;
    unsigned hi;
    void FUN_0027af50();
};
struct Bone_45da0 {
    char pad0[0x34];
    float offset;            // 0x34
    char pad38[8];
};
struct Skeleton {
    char pad0[0x1c];
    Bone_45da0 *bones;             // 0x1c
    int FUN_0027b200(unsigned __int64 id);
};
struct ModelHolder {
    char pad0[8];
    Skeleton *skeleton;      // 0x08
};
class Owner_45da0 {
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
    virtual ModelHolder *v11();
    char pad4[4];
    unsigned keyLo;          // 0x08
    unsigned keyHi;          // 0x0c
};
struct Registry_45da0 {
    int FUN_001c5b00(Key_45da0 *k);
};
struct Manager_45da0 {
    char pad0[0xc];
    Registry_45da0 *registry;      // 0x0c
    void FUN_001c4190(Key_45da0 *k);
};
extern "C" Manager_45da0 *__cdecl FUN_001c3d90();
struct Tracker_45da0 {
    char pad0[8];
    Owner_45da0 *owner;            // 0x08
    Owner_45da0 *pending;          // 0x0c
    char pad10[0x10];
    int rootIdx;             // 0x20
    int balanceIdx;          // 0x24
    int headIdx;             // 0x28
    float rootOffset;        // 0x2c

    char FUN_00045da0(Owner_45da0 *newOwner);
};
struct Obj {
    virtual void FUN_0();
    virtual void FUN_1();
    virtual void FUN_2();
    virtual void FUN_3();
    virtual void FUN_4();
    virtual void FUN_5();
    virtual void FUN_6();
    virtual void FUN_7();
    virtual void FUN_8();
    virtual void FUN_9();
    virtual void FUN_10();
    virtual void FUN_11();
    virtual void FUN_12();
    virtual void FUN_13();
    virtual void FUN_14();
    virtual void FUN_15();
    virtual void FUN_16();
    virtual void FUN_17();
    virtual void FUN_18();
    virtual void FUN_19();
    virtual void FUN_20();
    virtual void FUN_21();
    virtual void FUN_22();
    virtual void FUN_23();
    virtual void FUN_24();
    virtual void FUN_25();
    virtual void* FUN_26();
};
struct Provider {
    virtual void FUN_0();
    virtual void FUN_1();
    virtual void FUN_2();
    virtual void FUN_3();
    virtual void FUN_4();
    virtual void FUN_5();
    virtual void FUN_6();
    virtual void FUN_7();
    virtual void FUN_8();
    virtual void FUN_9();
    virtual void FUN_10();
    virtual char* FUN_11();
};
struct Target {
    char pad0[8];
    Provider* provider;
    Obj* held;
    bool FUN_00045f30(Obj* incoming);
};
} // namespace fn_f8b6a7cf
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int atexit(void (*)());
#endif
namespace fn_f8b6a7cf {
extern "C" void FUN_00363bd0();
struct NameKey_45f90 {
    unsigned lo, hi;
    void FUN_0027af00();
};
struct Entry_45f90 {
    unsigned lo, hi;
    float value;
    int pad;
};
class Table_45f90 {
public:
    char pad0[0x480];
    Entry_45f90 entries[14];
    int count;
    float FUN_00045f90(const char *name);
};
struct Key_46030 {
 unsigned int first, second;
 void FUN_0027af00();
 void FUN_0027af70(const Key_46030* other);
};
extern "C" void __cdecl FUN_00363be0();
} // namespace fn_f8b6a7cf
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl _atexit(void (__cdecl *callback)());
#endif
namespace fn_f8b6a7cf {
struct Entry_46030 { Key_46030 key; float value; unsigned int reserved; };
struct Object {
 char padding[0x480];
 Entry_46030 entries[14];
 int count;
 void FUN_00046030(const char* text, float value);
};
extern void* hulk_at_003f60b8[];
class RDLHandler_46110 {
  public:
    void Destroy_0027a560(); // FUN_00236d60, __thiscall, this in ecx
};
class CCharacterTemplateManager_46110 : public RDLHandler_46110 {
  public:
    CCharacterTemplateManager_46110* vfunc_5(signed char flags);
};
typedef unsigned __int64 u64_46140;
struct Entry_46140 {
    virtual void v0();
    virtual void Release();
    char pad04[0x3b0 - 4];
    char key[8];
    void FUN_00044430();
};
class CCharacterTemplateManager_46140 {
public:
    char pad00[0xc];
    int count;
    Entry_46140 **entries;

    void FUN_00046140(void *name);
};
} // namespace fn_f8b6a7cf
u64_46140 __cdecl FUN_0027b020(void *p);
namespace fn_f8b6a7cf {
class Item_461e0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_461e0 {
  public:
    char pad[8];
    int mCapacity;
    int mCount;
    Item_461e0** mItems;
    bool Add(Item_461e0* item);
};
struct Item { virtual void slot0(); virtual void release(); };
struct Container { char pad[12]; int count; Item **items; unsigned char FUN_00046230(); };
typedef unsigned int u32_46280;
extern void __cdecl Cast(hulk_uintptr, int, const int*, const int*, int);
extern "C" char hulk_at_003f6334[];
class DynamicCaster_462a0 {
  public:
    hulk_intptr vptr;
    DynamicCaster_462a0();
    int data;
};
typedef unsigned int u32_462b0;
typedef unsigned int u32_462e0;
class Dummy_46360 {
  public:
    void Call(void*);
};
class DynamicCaster_463a0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D(void*, int, int);
};
class X_463a0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D(void*, int, int);
    void F(int a, int b);
};
class DynamicCaster_46400 {
  public:
    DynamicCaster_46400() {}
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class Loader {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Load(DynamicCaster_46400*, int, int);
    hulk_intptr Go(int x, int y);
};
class CActorManager_464a0 {
  public:
    void invoke(const char*);
};
} // namespace fn_f8b6a7cf
void* operator new(hulk_uintptr) throw();
namespace fn_f8b6a7cf {
class Owner {};
typedef void (Owner::*Fn_47840)(const char*);
class Closure1_47840 : public ScriptClosureView {
  public:

    Closure1_47840(const char*, Owner*, Fn_47840) throw();
};
class Registry_47840 {
  public:
    void FUN_00047840(const char* a1, Owner* a2, Fn_47840 a3);
};


// 0x00045820 FUN_00045820 (22 B): matches/0x00045820.cpp
// sym: ?f@C_45820@fn_f8b6a7cf@@QAEXXZ
void C_45820::f() {
    if (p) {
        p->b();
        p = 0;
    }
}

} // namespace fn_f8b6a7cf

// 0x00045840 FUN_00045840 (1172 B): equivalent/0x00045840.cpp [wrapped: conflict: CCharacterTemplate]
// sym: ??0CCharacterTemplate@fn_00045840@@QAE@XZ
namespace fn_00045840 {
// STATUS: equivalent (tools/equiv.py level 3: 2775 inputs, branch coverage 4/4)
// FUN_00045840 @ 0x00045840
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);

struct V3_45840 {
    float x;
    float y;
    float z;
    void FUN_00233dd0();
};

struct Slot20_45840 {
    char flag;
    char pad[0x1f];
};

struct Elem28 {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
};

struct Str16 {
    char pad[16];
    void FUN_0027af00();
};

class CCharacterTemplate {
public:
    CCharacterTemplate();
    virtual void v0();
    int f4;
    int f8;
    int fc;
    char f10;
    char pad11[0x3];
    int f14;
    int f18;
    float f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    Slot20_45840 slots[3];
    int a[3];
    V3_45840 v[3];
    int c[3];
    V3_45840 objs[6];
    int f128;
    float f12c;
    int f130;
    int f134;
    int f138;
    int f13c;
    int f140;
    int f144;
    int f148;
    int f14c;
    int f150;
    int f154;
    int f158;
    float f15c;
    int f160;
    int f164;
    int f168;
    char pad16c[0x4];
    float f170;
    float f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    float f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    char pad1b4[0x4];
    Elem28 elems[8];
    char f2f8;
    char pad2f9[0x3];
    int f2fc;
    int f300;
    int f304;
    int f308;
    float f30c;
    float f310;
    float f314;
    float f318;
    float f31c;
    float f320;
    float f324;
    float f328;
    int f32c;
    int f330;
    int f334;
    int f338;
    int f33c;
    int f340;
    int f344;
    int f348;
    int f34c;
    int f350;
    int f354;
    int f358;
    int f35c;
    int f360;
    int f364;
    int f368;
    int f36c;
    float f370;
    float f374;
    float f378;
    char f37c;
    char f37d;
    char f37e;
    char f37f;
    int f380;
    char f384;
    char pad385[0x3];
    float f388;
    char f38c;
    char f38d;
    char f38e;
    char f38f;
    char f390;
    char pad391[0x3];
    int f394;
    int f398;
    int f39c;
    int f3a0;
    int f3a4;
    int f3a8;
    int f3ac;
    char f3b0;
    char pad3b1[0x3f];
    char f3f0;
    char pad3f1[0x3f];
    char buf430[8];
    float f438;
    float f43c;
    int f440;
    int f444;
    int f448;
    int f44c;
    int f450;
    char f454;
    char pad455[0x3];
    float f458;
    float f45c;
    float f460;
    float f464;
    float f468;
    int f46c;
    float f470;
    char pad474[0x4];
    float f478;
    float f47c;
    Str16 strs[14];
    int f560;
};

CCharacterTemplate::CCharacterTemplate()
{
    f4 = 0;
    f8 = 0;
    fc = 0;
    f10 = 0;
    f14 = 0;
    f18 = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0xffff;
    f2c = 0;
    f30 = 0;
    f34 = 0;
    f1c = 1.0f;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    objs[0].FUN_00233dd0();
    objs[1].FUN_00233dd0();
    objs[2].FUN_00233dd0();
    objs[3].FUN_00233dd0();
    objs[4].FUN_00233dd0();
    objs[5].FUN_00233dd0();
    f128 = 0;
    f12c = 1.0f;
    f130 = 0;
    f134 = 0;
    f138 = 0;
    f13c = 0;
    f140 = 0;
    f144 = 0;
    f148 = 0;
    f14c = 0;
    f150 = 0;
    f154 = 0;
    f158 = 0;
    f15c = 30.0f;
    f160 = 0;
    f164 = 0;
    f168 = 0;
    f170 = 1.0f;
    f174 = 1.0f;
    f178 = 0;
    f17c = 0;
    f180 = 0;
    f184 = 0;
    f188 = 1.0f;
    f18c = 0;
    f190 = 0;
    f194 = 0;
    f198 = 0;
    f19c = 0;
    f1a0 = 0;
    f1a4 = 0;
    f1a8 = 0;
    f1ac = 0;
    f1b0 = 0;
    for (int i = 0; i < 8; i++) {
        elems[i].f0 = 0;
        elems[i].f8 = 0;
        elems[i].fc = 0;
        elems[i].f18 = 0;
        elems[i].f14 = 0;
        elems[i].f10 = 0;
        elems[i].f24 = 0;
        elems[i].f20 = 0;
        elems[i].f1c = 0;
    }
    f2f8 = 0;
    f2fc = 0;
    f300 = 0;
    f304 = 0;
    f308 = 0;
    f30c = 1.0f;
    f310 = 1.0f;
    f314 = 1.0f;
    f318 = 1.0f;
    f31c = 1.0f;
    f320 = 0.5f;
    f324 = 5.0f;
    f328 = 5.0f;
    f370 = 1.0f;
    f388 = 1.0f;
    f32c = 0;
    f330 = 0;
    f334 = 0;
    f338 = 0;
    f33c = 0;
    f340 = 0;
    f344 = 0;
    f348 = 0;
    f34c = 0;
    f350 = 0;
    f354 = 0;
    f358 = 0;
    f35c = 0;
    f360 = 0;
    f364 = 0;
    f368 = 0;
    f36c = 0;
    f37d = 0;
    f37e = 0;
    f37f = 0;
    f384 = 0;
    f38c = 0;
    f38d = 0;
    f38e = 0;
    f38f = 0;
    f390 = 0;
    f394 = 0;
    f398 = 0;
    f39c = 0;
    f3a0 = 0;
    f3a4 = 0;
    f3a8 = 0;
    f3ac = 0;
    f438 = 1.2f;
    f374 = 2.0f;
    f378 = 2.0f;
    f37c = 1;
    f380 = 1;
    f43c = 20.0f;
    f440 = 0;
    f444 = 0;
    f448 = 0;
    f44c = 0;
    f450 = 0;
    f454 = 0;
    f458 = 1.0f;
    f45c = 1.0f;
    f460 = -1.0f;
    f464 = -1.0f;
    f468 = -1.0f;
    f46c = 0;
    f470 = 20.0f;
    f478 = 65.0f;
    f47c = 165.0f;
    for (int i = 0; i < 14; i++)
        strs[i].FUN_0027af00();
    f560 = 0;
    for (int i = 0; i < 3; i++) {
        slots[i].flag = 0;
        a[i] = -1;
        v[i].z = v[i].y = v[i].x = 0.0f;
        c[i] = 0;
    }
    f3b0 = 0;
    f3f0 = 0;
    FUN_00267760(buf430, 5, "NONE");
}
} // namespace fn_00045840


// 0x00045ce0 FUN_00045ce0 (185 B): equivalent/0x00045ce0.cpp [wrapped: conflict: CCharacterTemplate; core::IRefCount]
// sym: ??1CCharacterTemplate@fn_00045ce0@@QAE@XZ
namespace fn_00045ce0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00045ce0 @ 0x00045ce0
namespace core { struct IRefCount { virtual void slot0(); virtual void slot1(); }; }
struct Item_45ce0 { virtual void slot0(); virtual void slot1(); };
struct Block_45ce0 { char data[16]; void FUN_0027af50(); };
struct Small_45ce0 { char data[12]; void FUN_00234150(); };
struct Entry_45ce0 { Item_45ce0* object; char data[36]; };
struct CCharacterTemplate : core::IRefCount {
 int unused; Item_45ce0* a; Item_45ce0* b;
 char pad[0xd0]; Small_45ce0 small[6]; char gap[0x90]; Entry_45ce0 entries[8]; char gap2[0x188]; Block_45ce0 blocks[14];
 virtual void slot0(); virtual void slot1(); ~CCharacterTemplate();
};
CCharacterTemplate::~CCharacterTemplate() {
 if(b) { b->slot1(); b=0; }
 if(a) { a->slot1(); a=0; }
 for(int i=13;i>=0;--i) blocks[i].FUN_0027af50();
 for(int j=7;j>=0;--j) if(entries[j].object) { entries[j].object->slot1(); entries[j].object=0; }
 for(int k=5;k>=0;--k) small[k].FUN_00234150();
 this->core::IRefCount::IRefCount();
}
} // namespace fn_00045ce0

namespace fn_f8b6a7cf {

// 0x00045da0 FUN_00045da0 (393 B): equivalent/0x00045da0.cpp
// sym: ?FUN_00045da0@Tracker_45da0@fn_f8b6a7cf@@QAEDPAVOwner_45da0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 24/24)
// FUN_00045da0 @ 0x00045da0
char Tracker_45da0::FUN_00045da0(Owner_45da0 *newOwner)
{
    if (newOwner == owner)
        return 1;

    bool sameSkeleton = false;
    if (newOwner) {
        Skeleton *a = newOwner->v11()->skeleton;
        Skeleton *b = 0;
        if (owner)
            b = owner->v11()->skeleton;
        sameSkeleton = (a == b);
    }
    if (!sameSkeleton && pending) {
        pending->v1();
        pending = 0;
    }

    if (newOwner)
        newOwner->v0();
    if (owner)
        owner->v1();
    owner = newOwner;
    rootIdx = 0;
    balanceIdx = 0;
    headIdx = 0xffff;
    rootOffset = 0;
    if (owner == 0)
        return 1;

    Skeleton *skel = newOwner->v11()->skeleton;
    if (skel) {
        rootIdx = skel->FUN_0027b200(FUN_002672f0("Character_Root", 0, 0));
        if (rootIdx != 0xffff) {
            float v = skel->bones[rootIdx].offset;
            rootOffset = v;
            rootOffset = v - skel->bones[0].offset;
        } else {
            rootIdx = 0;
        }
        balanceIdx = skel->FUN_0027b200(FUN_002672f0("Balance_Root", 0, 0));
        if (balanceIdx == 0xffff)
            balanceIdx = rootIdx;
        headIdx = skel->FUN_0027b200(FUN_002672f0("Head", 0, 0));
    }

    {
        Key_45da0 k;
        ((owners::Pair_27af10 *)&k)->FUN_0027af10((unsigned int)(owner->keyLo), (unsigned int)(owner->keyHi));
        bool found = FUN_001c3d90()->registry->FUN_001c5b00(&k) == 0;
        k.FUN_0027af50();
        if (!found)
            return 1;
    }
    {
        Key_45da0 k;
        ((owners::Pair_27af10 *)&k)->FUN_0027af10((unsigned int)(owner->keyLo), (unsigned int)(owner->keyHi));
        FUN_001c3d90()->FUN_001c4190(&k);
        k.FUN_0027af50();
    }
    return 1;
}


// 0x00045f30 FUN_00045f30 (86 B): equivalent/0x00045f30.cpp
// sym: ?FUN_00045f30@Target@fn_f8b6a7cf@@QAE_NPAUObj@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 11/12, incomplete)
// FUN_00045f30 @ 0x00045f30
bool Target::FUN_00045f30(Obj* incoming) {
    if (incoming) {
        if (!provider) return false;
        char* value = provider->FUN_11();
        void* expected = *(void**)(value + 8);
        if (!expected || incoming->FUN_26() != expected) return false;
        incoming->FUN_0();
    }
    if (held) held->FUN_1();
    held = incoming;
    return true;
}


// 0x00045f90 FUN_00045f90 (154 B): equivalent/0x00045f90.cpp
// sym: ?FUN_00045f90@Table_45f90@fn_f8b6a7cf@@QAEMPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 76 inputs, branch coverage 10/10)
// FUN_00045f90 @ 0x00045f90
float Table_45f90::FUN_00045f90(const char *name)
{
    if (((*(unsigned int*)&DAT_004dc338) & 1) == 0) {
        (*(unsigned int*)&DAT_004dc338) |= 1;
        (*(NameKey_45f90*)&DAT_004dc330).FUN_0027af00();
        atexit(FUN_00363bd0);
    }
    ((owners::Target_27b040 *)&((*(NameKey_45f90*)&DAT_004dc330)))->FUN_0027b040((hulk_uintptr)name);
    for (int i = 0; i < count; i++) {
        if (entries[i].lo == (*(NameKey_45f90*)&DAT_004dc330).lo && entries[i].hi == (*(NameKey_45f90*)&DAT_004dc330).hi)
            return entries[i].value;
    }
    return -1.0f;
}


// 0x00046030 FUN_00046030 (214 B): equivalent/0x00046030.cpp
// sym: ?FUN_00046030@Object@fn_f8b6a7cf@@QAEXPBDM@Z
// STATUS: equivalent (tools/equiv.py level 3: 48 inputs, branch coverage 12/12)
// FUN_00046030 @ 0x00046030
void Object::FUN_00046030(const char* text, float value) {
 if (!((*(unsigned int*)&DAT_004dc348) & 1)) {
  (*(unsigned int*)&DAT_004dc348) |= 1;
  (*(Key_46030*)&DAT_004dc340).FUN_0027af00();
  _atexit(FUN_00363be0);
 }
 ((owners::Target_27b040 *)&((*(Key_46030*)&DAT_004dc340)))->FUN_0027b040((hulk_uintptr)text);
 int oldCount = count;
 for (int i=0; i<count; ++i) {
  if (entries[i].key.first == (*(Key_46030*)&DAT_004dc340).first && entries[i].key.second == (*(Key_46030*)&DAT_004dc340).second) {
   entries[i].value = value;
   return;
  }
 }
 if (oldCount < 14) {
  entries[oldCount].key.FUN_0027af70(((Key_46030*)&DAT_004dc340));
  entries[count].value = value;
  ++count;
 }
}


// 0x00046110 CCharacterTemplateManager::vfunc_1 (36 B): matches/0x00046110.cpp
// sym: ?vfunc_5@CCharacterTemplateManager_46110@fn_f8b6a7cf@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CCharacterTemplateManager_46110* CCharacterTemplateManager_46110::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_003f60b8;
    Destroy_0027a560();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x00046140 FUN_00046140 (155 B): equivalent/0x00046140.cpp
// sym: ?FUN_00046140@CCharacterTemplateManager_46140@fn_f8b6a7cf@@QAEXPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 1862 inputs, branch coverage 12/12)
// FUN_00046140 @ 0x00046140
// FUN_00046140: destroy every entry whose key matches
void CCharacterTemplateManager_46140::FUN_00046140(void *name)
{
    u64_46140 key = FUN_0027b020(name);
    for (int i = 0; i < count; i++) {
        if (entries[i] != 0 && FUN_0027b020(entries[i]->key) == key) {
            entries[i]->FUN_00044430();
            Entry_46140 **slot = entries + i;
            Entry_46140 *e = *slot;
            if (e != 0) {
                e->Release();
                *slot = 0;
            }
            entries[i] = 0;
        }
    }
}


// 0x000461e0 FUN_000461e0 (67 B): matches/0x000461e0.cpp
// sym: ?Add@Container_461e0@fn_f8b6a7cf@@QAE_NPAVItem_461e0@2@@Z
bool Container_461e0::Add(Item_461e0* item) {
    int index = mCount;
    if (index >= mCapacity)
        return false;
    Item_461e0** slot = mItems + index;
    if (item)
        item->A();
    if (*slot)
        (*slot)->B();
    *slot = item;
    ++mCount;
    return true;
}


// 0x00046230 FUN_00046230 (61 B): equivalent/0x00046230.cpp
// sym: ?FUN_00046230@Container@fn_f8b6a7cf@@QAEEXZ
// STATUS: equivalent (tools/equiv.py level 3: 100 inputs, branch coverage 7/8, incomplete)
// FUN_00046230 @ 0x00046230
unsigned char Container::FUN_00046230() {
    for (int i = count - 1; i >= 0; --i) {
        Item **slot = &items[i];
        Item *item = *slot;
        if (item) {
            item->release();
            *slot = 0;
        }
    }
    count = 0;
    return 1;
}

} // namespace fn_f8b6a7cf

// 0x00046280 content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>::vfunc_0 (30 B): matches/0x00046280.cpp
// sym: ?vfunc_0@?$DynamicCaster@VDrawableHierarchy@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}

namespace fn_f8b6a7cf {

// 0x000462a0 FUN_000462a0 (9 B): matches/0x000462a0.cpp
// sym: ??0DynamicCaster_462a0@fn_f8b6a7cf@@QAE@XZ
DynamicCaster_462a0::DynamicCaster_462a0() {
    vptr = ((hulk_intptr)(hulk_at_003f6334 + 0x4));
}

} // namespace fn_f8b6a7cf

// 0x000462b0 content::LoadInventory::DynamicCaster<pure3d::ShadowSkin>::vfunc_0 (30 B): matches/0x000462b0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VShadowSkin@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::ShadowSkin>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x000462e0 content::LoadInventory::DynamicCaster<CSPHulkProp>::vfunc_0 (30 B): matches/0x000462e0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VCSPHulkProp@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<CSPHulkProp>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x00046340 Method1<CCharacterTemplateManager,void,const_char_*>::vfunc_0 (30 B): matches/0x00046340.cpp
// sym: ??_G?$Method1@VCCharacterTemplateManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CCharacterTemplateManager, void, const char *>::~Method1() {}


// 0x00046360 Method1<CCharacterTemplateManager,void,const_char_*>::vfunc_2 (19 B): matches/0x00046360.cpp
// sym: ?vfunc_2@?$Method1@VCCharacterTemplateManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CCharacterTemplateManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_46360* d = (Dummy_46360*)a;
    (d->*(*(void (Dummy_46360::**)(void *))&this->f_1c))(*b);
}


// 0x00046380 CCharacterTemplate::vfunc_2 (30 B): matches/0x00046380.cpp
// sym: ??_GCCharacterTemplate@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CCharacterTemplate::~CCharacterTemplate() {}

namespace fn_f8b6a7cf {

// 0x000463a0 FUN_000463a0 (33 B): matches/0x000463a0.cpp
// sym: ?F@X_463a0@fn_f8b6a7cf@@QAEXHH@Z
void X_463a0::F(int a, int b) {
    DynamicCaster_463a0 o;
    D(&o, a, b);
}


// 0x00046400 FUN_00046400 (33 B): matches/0x00046400.cpp
// sym: ?Go@Loader@fn_f8b6a7cf@@QAEHHH@Z
hulk_intptr Loader::Go(int x, int y) {
    DynamicCaster_46400 caster;
    return Load(&caster, x, y);
}

} // namespace fn_f8b6a7cf

// 0x00046430 FUN_00046430 (76 B): matches/0x00046430.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure1@fn_00046430@@QAE@PBDPAVOwner_46430@1@P821@AEXXZ@Z
namespace fn_00046430 {
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

// Closure1's constructor (name, object, member function): Function's fields (include/decls/data/script.h), then
// Method1's member-function pointer and Closure1's object.
class Owner_46430 {};
typedef void (Owner_46430::*Fn_46430)();
class Base : public ScriptFunctionFields {
  public:
    virtual void f();
    Base(const char*, int);
    Fn_46430 c;
};
class Closure1_46430 : public Base {
  public:
    Closure1_46430(const char*, Fn_46430);
    virtual void f();
};
Closure1_46430::Closure1_46430(const char* s, Fn_46430 x) : Base(s, 1) {
    c = x;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e0f0));
}
class Closure1 : public Closure1_46430 {
  public:
    Owner_46430* d;
    Closure1(const char*, Owner_46430*, Fn_46430);
    virtual void f();
};
Closure1::Closure1(const char* s, Owner_46430* x, Fn_46430 y) : Closure1_46430(s, y) {
    d = x;
}
} // namespace fn_00046430
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000464a0 Closure1<CCharacterTemplateManager,void,const_char_*>::vfunc_2 (18 B): matches/0x000464a0.cpp
// sym: ?vfunc_2@?$Closure1@VCCharacterTemplateManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CCharacterTemplateManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_464a0 * *)&this->f_20)->*(*(void (CActorManager_464a0::**)(const char *))&this->f_1c))(*b);
}


// 0x00047770 CCharacterTemplateManager::vfunc_0 (203 B): equivalent/0x00047770.cpp [wrapped: conflict: CCharacterTemplateManager; RDLHandler]
// sym: ?vfunc_0@CCharacterTemplateManager@fn_00047770@@UAEXPAUContext@2@PAUNode@2@@Z
namespace fn_00047770 {
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 12/12)
// CCharacterTemplateManager::vfunc_0 @ 0x00047770
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

struct Context { char pad[32]; void* data; };
struct Node { char pad[24]; char name[21]; void FUN_0027aac0(const char*, const char**); };
struct CCharacterTemplate_47770 { virtual void retain(); virtual void release(); CCharacterTemplate_47770* FUN_00045840(); void FUN_000464c0(void*, Node*); };
extern void* __cdecl FUN_0008d690(unsigned);
struct RDLHandler { virtual void vfunc_0(Context*,Node*); virtual void vfunc_1(); };
struct CCharacterTemplateManager : RDLHandler { int unknown; int capacity; int count; CCharacterTemplate_47770** entries; CCharacterTemplate_47770* FUN_00044ad0(unsigned __int64); virtual void vfunc_0(Context*,Node*); };
void CCharacterTemplateManager::vfunc_0(Context* context, Node* node) {
 void* data=context->data;
 const char* expected="RdlCharacterTemplate";
 for(int i=0;i<21;++i) { if(node->name[i]!=expected[i]) return; }
 const char* variation=0;
 node->FUN_0027aac0("VariationName", &variation);
 CCharacterTemplate_47770* item=FUN_00044ad0(FUN_0027b020(variation));
 if(!item) { void* memory=FUN_0008d690(0x568); item=memory ? ((CCharacterTemplate_47770*)memory)->FUN_00045840() : 0; }
 item->retain();
 item->FUN_000464c0(data,node);
 if(count<capacity) { CCharacterTemplate_47770** slot=entries+count; item->retain(); if(*slot) (*slot)->release(); *slot=item; ++count; }
 item->release();
}
} // namespace fn_00047770
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f8b6a7cf {

// 0x00047840 FUN_00047840 (70 B): matches/0x00047840.cpp
// sym: ?FUN_00047840@Registry_47840@fn_f8b6a7cf@@QAEXPBDPAVOwner@2@P832@AEX0@Z@Z
void Registry_47840::FUN_00047840(const char* a1, Owner* a2, Fn_47840 a3) {
    HULK_SIZE32(Closure1_47840, 0x24);
    Closure1_47840* e = new Closure1_47840(a1, a2, a3);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)(Closure1_47840 *)e);
}

} // namespace fn_f8b6a7cf

// 0x00047890 FUN_00047890 (192 B): equivalent/0x00047890.cpp [wrapped: conflict: CCharacterTemplateManager; Closure1; Method1]
// sym: ??0CCharacterTemplateManager@fn_00047890@@QAE@II@Z
inline void* __cdecl operator new(hulk_uintptr,void* p) { return p; }
namespace fn_00047890 {
// STATUS: equivalent (tools/equiv.py level 3: 22 inputs, branch coverage 4/4)
// FUN_00047890 @ 0x00047890
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

typedef unsigned int uint_47890;

extern "C" void* __cdecl FUN_0008d6d0(uint_47890);
void* __cdecl FUN_0008d690(uint_47890);
struct Registry_47890 { void FUN_001d3b70(const char*,void*); };
extern "C" Registry_47890* __cdecl FUN_001d4c90();
class CCharacterTemplateManager {
public:
 virtual void slot0();
 uint_47890 owner,count,used;
 uint_47890* entries;
 void FUN_00046140(const char*);
 CCharacterTemplateManager(uint_47890,uint_47890);
};
template<class T,class R,class A> class Method1 : public ScriptFunctionFields {
public:
 virtual void slot0();
 void (T::*method)(A);
};
template<class T,class R,class A> class Closure1 : public Method1<T,R,A> {
public:
 T* object;
};
struct CallbackBase { void FUN_001d0480(const char*,int); };
CCharacterTemplateManager::CCharacterTemplateManager(uint_47890 arg,uint_47890 n) {
 owner=arg; count=n; used=0;
 entries=(uint_47890*)FUN_0008d6d0(n*4);
 uint_47890* p=entries;
 uint_47890 total=(count*4)>>2;
 for(uint_47890 i=0;i<total;++i) p[i]=0;
 Registry_47890* r=FUN_001d4c90();
 if(r) {
  typedef Closure1<CCharacterTemplateManager,void,const char*> Alloc_47890;
  HULK_SIZE32(Alloc_47890,0x24);
  void* mem=FUN_0008d690((int)sizeof(Closure1<CCharacterTemplateManager,void,const char*>));
  Closure1<CCharacterTemplateManager,void,const char*>* cb=0;
  if(mem) {
   ((CallbackBase*)mem)->FUN_001d0480("ctm_UnloadCharacterTemplate",1);
   Method1<CCharacterTemplateManager,void,const char*>* m=new(mem) Method1<CCharacterTemplateManager,void,const char*>;
   m->method=&CCharacterTemplateManager::FUN_00046140;
   m->retType=FUN_001d04d0(((void**)&DAT_0048e100));
   m->argTypes[0]=FUN_001d04d0(((void**)&DAT_0048e0f0));
   cb=new(mem) Closure1<CCharacterTemplateManager,void,const char*>;
   cb->object=this;
  }
  r->FUN_001d3b70("ctm_UnloadCharacterTemplate",cb);
 }
}
} // namespace fn_00047890
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

