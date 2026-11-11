// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00092120..0x000933a0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9a5903c {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9a5903c {} using namespace fn_f9a5903c;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f9a5903c {
extern "C" void __cdecl FUN_0008d340(void *);
extern "C" void * __cdecl FUN_0008d6d0(unsigned int);
extern void* gB_92190[];
extern void* gM[];
struct S_92190 {
    int a, b;
    void Init();
};
class CUnlockableMovie_92190 {
  public:
    void* vptr;
    char pad[4];
    unsigned char m8;
    char pad2[7];
    S_92190 s10;
    int m18;
    char pad3[4];
    unsigned char m20;
    int m24;
    unsigned char m28;
    char pad4[7];
    unsigned char m30;
    CUnlockableMovie_92190* ctor();
};
class CUnlockable {
  public:
    char _m_pad_0[0x18];
    void* m18;
    char _m_pad_1c[0x4];
    int value;
    void Destroy();
};
extern void __cdecl thunk_FUN_00267090(void*);
struct Tail_921d0 {
    void f();
};
extern "C" char DAT_004044cc[];
class Sub_92230 {
  public:
    void Init();
};
class CUnlockableGallery {
  public:
    hulk_ulongptr v;
    char pad4[4];
    unsigned char flag;
    char pad9[7];
    char at10[8];
    unsigned long m18;
    char pad1c[4];
    unsigned long m20;
    char pad24[0x80];
    char atA4[4];
    char atA8[8];
    unsigned char mB0;
    char padB1[0x13];
    unsigned char mC4;
    char padC5[0x3f];
    unsigned char m104;
};
class C_92310 {
    char pad[0x20];

  public:
    unsigned int value;
};
struct Obj_92320 {
    char pad[0x24];
};
struct Called {
    void F(void*);
};
struct Obj_92340 {
    char pad[0xa8];
    hulk_uintptr Target(Called* param);
};
class Obj_92410 {
  public:
    void Setup(const char*, int, int);
};
class Host_92410 {
  public:
    Obj_92410* GetObject();
    void AddThing(Obj_92410*, const char*, int);
    void Target();
};
struct Triple_92540 {
    int a;
    int b;
    int c;
    void FUN_0027af50();
};
class Registry_92540 {
public:
    bool FUN_00092470(int lo, int hi, const char* fmt, int a, int b, int c);
    void FUN_00092540(int kind, Triple_92540 t);
};
extern "C" char DAT_0049dab8[];
extern "C" char DAT_0049dafc[];
extern "C" char DAT_0049db1c[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);
struct Env {
    void FUN_000c2c10(int id);
};
struct Flagged_92870 {
    char pad0[0x20];
    char flag;      // 0x20
};
class Container_92870 {
public:
    void* items[0x362];     // 0x000
    Env* env;               // 0xd88
    void FUN_00092870(int index, char flag);
};
typedef unsigned int u32_928f0;
struct H {
    void call(int);
};
struct C_928f0 {
    char pad[0xD88];
    H* member;
    void f(int, int);
};
extern char RTTI1_928f0;
extern char RTTI2_928f0;
extern void* Cast(void*, int, const void*, const void*, int);
typedef unsigned char u8_92940;
struct Obj_92940 {
    char pad[32];
    u8_92940 value;
};
extern char TypeUnlockable[];
extern char TypeCheat[];
extern char TypeMove[];
class Container_92940 {
  public:
    Obj_92940* items[1];
    u8_92940 Get(int index);
};
extern "C" char DAT_0049dad4[];
extern "C" char DAT_0049db80[];
class X_92bc0 {
  public:
    char pad[0x18];
    int value;
};
class C_92bc0 {
  public:
    X_92bc0* items[1];
    hulk_intptr f(int index);
};
struct Entry { int first; int second; char rest[0x48]; };
struct Object { char pad[0xd90]; Entry entries[32]; int FUN_00092c40(int first, int second); };
extern "C" int __cdecl FUN_00345804(const char *str, const char *fmt, ...);
struct Slot_92c80 {
    unsigned __int64 key;
    int chapter;
    int mission;
    int values[16];
};
class SlotTable_92c80 {
public:
    char pad0[0xd90];
    Slot_92c80 slots[32];
    void FUN_00092c80(const char *name, int value);
};
typedef unsigned char u8_92dc0;
typedef int i32_92dc0;
struct Entry_92dc0 {
    char pad[8];
    u8_92dc0 value;
};
struct Table_92dc0 {
    Entry_92dc0* items[0x2fe];
    u8_92dc0 Get(i32_92dc0 index);
};
class Obj_92e00 {
  public:
    void FUN_00092870(int a);
    void FUN_00092e00(int a, int b);
};
struct ThisCall_00092870 {
    void Helper(int a, int b);
};
struct Game {
    void FUN_000928f0(int x, int y);
    void FUN_00092e20(int x, int y);
};
struct Name_92e50 {
    char data[8];
};
class CUnlockable_92e50 {
public:
    virtual void v0();
};
class CUnlockableBlonskyFile_92e50 : public CUnlockable_92e50 {
public:
    char pad04[0xc];
    Name_92e50 title;
    char pad18[8];
    Name_92e50 subtitle;
    char text[0x40];
    char pad68[1];
};
class UnlockableList_92e50 {
public:
    CUnlockable_92e50 *items[1];
    void FUN_00092c80(const char *s, int idx);
    void FUN_00092e50(const char *id, int idx, const char *title, const char *subtitle,
                      const char *file, const char *text);
};
} // namespace fn_f9a5903c
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f9a5903c {
void* __cdecl FUN_00344e74(int id, int a, const char* b, const char* c, int d);
struct Name_92ef0 {
    char data[8];
};
struct Entry_92ef0 {
    char pad00[0x10];
    Name_92ef0 name10;
    char pad18[8];
    char flag20;
    char pad21[3];
    int value24;
    char pad28[0x10];
    Name_92ef0 name38;
    Name_92ef0 name40;
    char text48[0x40];
};
class Table_92ef0 {
public:
    int ids[0x300];
    void FUN_00092ef0(int index, const char* a, const char* b, const char* c, const char* text, int value);
};
typedef unsigned char u8_92f70;
struct Thing_92f70 {
    char p[0x2c];
    u8_92f70 field;
};
struct Desc_92f70 {
    int x;
};
extern Thing_92f70* Cast(Thing_92f70*, int, const Desc_92f70*, const Desc_92f70*, int);
class C_92f70 {
  public:
    int values[1];
    char rest[0xbf4];
    void F(int c, int b, u8_92f70 d);
};
extern Desc_92f70 descA;
extern Desc_92f70 descB;
extern char gA, gB;
struct Inner {
};
struct Result {
    char pad[16];
    Inner inner;
};
extern "C" Result* __cdecl Make(void*, int, void*, void*, int);
struct Owner {
    void* items[734];
    void Run(int, void*, void*);
};
struct Obj_93110 {
    int slots[0x32];
};
struct Type {};
extern Type CUnlockable_RTTI_Type_Descriptor;
extern Type CUnlockableCheat_RTTI_Type_Descriptor;
extern "C" int __cdecl FUN_00344e74(void*, int, Type*, Type*, int);
struct Name_93150 {
    char data[8];
};
class CUnlockable_93150 {
public:
    virtual void v0();
};
class CUnlockableGallery_93150 : public CUnlockable_93150 {
public:
    char pad04[0xc];
    Name_93150 title;
    char pad18[8];
    int flags;
    char caption[0x40];
    char path[0x40];
    char pada4[4];
    Name_93150 subtitle;
};
class UnlockableList_93150 {
public:
    CUnlockable_93150 *items[1];
    void FUN_00092c80(const char *s, int idx);
    void FUN_00093150(const char *id, int idx, const char *title, const char *subtitle,
                      const char *caption, const char *path, int flags);
};
struct Owner_93260 {
    int values[0x2ca];
};
extern int typeA_93260;
extern int typeB_93260;
extern void* FindType(void*, int, void*, void*, int);

} // namespace fn_f9a5903c

// 0x00092120 FUN_00092120 (81 B): equivalent/0x00092120.cpp
// sym: ?FUN_00092120@TextOwner_92120@owners@@QAEXPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 8/8)
// FUN_00092120 @ 0x00092120
void owners::TextOwner_92120::FUN_00092120(const char *source) {
    if (text) {
        FUN_0008d340(text);
        text = 0;
    }
    if (source) {
        const char *end = source;
        while (*end) ++end;
        char *destination = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
        text = destination;
        do {
            *destination++ = *source;
        } while (*source++);
    }
}

namespace fn_f9a5903c {

// 0x00092190 FUN_00092190 (52 B): matches/0x00092190.cpp
// sym: ?ctor@CUnlockableMovie_92190@fn_f9a5903c@@QAEPAV12@XZ
CUnlockableMovie_92190* CUnlockableMovie_92190::ctor() {
    vptr = gB_92190;
    m8 = 1;
    s10.Init();
    m18 = 0;
    m20 = 0;
    m28 = 0;
    m30 = 0;
    m24 = -1;
    vptr = gM;
    return this;
}


// 0x000921d0 FUN_000921d0 (41 B): matches/0x000921d0.cpp
// sym: ?Destroy@CUnlockable@fn_f9a5903c@@QAEXXZ
void CUnlockable::Destroy() {
    *(void**)this = (void*)((hulk_intptr)DAT_0040449c);
    if (m18) {
        thunk_FUN_00267090(m18);
        m18 = 0;
    }
    ((Tail_921d0*)((char*)this + 0x10))->f();
}


// 0x00092230 FUN_00092230 (64 B): matches/0x00092230.cpp
// sym: ?FUN_00092230@fn_f9a5903c@@YIPAVCUnlockableGallery@1@PAV21@@Z
CUnlockableGallery* __fastcall FUN_00092230(CUnlockableGallery* p) {
    p->v = ((hulk_intptr)DAT_0040449c);
    p->flag = 1;
    ((Sub_92230*)((char*)p + 0x10))->Init();
    p->m18 = 0;
    p->v = ((hulk_intptr)DAT_004044cc);
    p->m20 = 0;
    ((Sub_92230*)((char*)p + 0xa8))->Init();
    p->mB0 = 0;
    *((unsigned char*)p + 0x24) = 0;
    *((unsigned char*)p + 0x64) = 0;
    return p;
}

} // namespace fn_f9a5903c

// 0x00092270 FUN_00092270 (58 B): matches/0x00092270.cpp [wrapped: conflict: CUnlockableGallery]
// sym: ?destroy@CUnlockableGallery@fn_00092270@@QAEXXZ
namespace fn_00092270 {
extern "C" char DAT_0040449c[];
extern "C" char DAT_004044cc[];
void ReleaseThing(void*);
class Sub_92270 {
  public:
    void Fin();
};
class CUnlockableGallery {
  public:
    void destroy();
    char pad[0x10];
    Sub_92270 sub10;
    char pad2[0x7];
    void* m18;
};
void CUnlockableGallery::destroy() {
    *(void**)this = (void*)((hulk_intptr)DAT_004044cc);
    ((Sub_92270*)((char*)this + 0xa8))->Fin();
    *(void**)this = (void*)((hulk_intptr)DAT_0040449c);
    if (m18) {
        ReleaseThing(m18);
        m18 = 0;
    }
    sub10.Fin();
}
} // namespace fn_00092270

namespace fn_f9a5903c {

// 0x00092310 FUN_00092310 (4 B): matches/0x00092310.cpp
// sym: ?target@fn_f9a5903c@@YIIPAVC_92310@1@@Z
// Same code shape as 0x00086280 (propagated; names are from that function)
unsigned int __fastcall target(C_92310* self) {
    return self->value;
}


// 0x00092320 FUN_00092320 (4 B): matches/0x00092320.cpp
// sym: ?FUN_00092320@fn_f9a5903c@@YIPAUObj_92320@1@PAU21@@Z
Obj_92320* __fastcall FUN_00092320(Obj_92320* self) {
    return (Obj_92320*)((char*)self + 0x24);
}


// 0x00092330 FUN_00092330 (4 B): matches/0x00092330.cpp
// sym: ?FUN_00092330@fn_f9a5903c@@YIHPAX@Z
hulk_intptr __fastcall FUN_00092330(void* p) {
    return (hulk_intptr)p + 100;
}


// 0x00092340 FUN_00092340 (25 B): matches/0x00092340.cpp
// sym: ?Target@Obj_92340@fn_f9a5903c@@QAEIPAUCalled@2@@Z
hulk_uintptr Obj_92340::Target(Called* param) {
    param->F((char*)this + 0xa8);
    return (hulk_uintptr)param;
}

} // namespace fn_f9a5903c

// 0x00092360 FUN_00092360 (13 B): matches/0x00092360.cpp
// sym: ?FUN_00092360@Target_92360@owners@@QAEXE@Z
void owners::Target_92360::FUN_00092360(unsigned char x) {
    value = x;
}


// 0x00092370 FUN_00092370 (7 B): matches/0x00092370.cpp
// sym: ?FUN_00092370@C_92370@owners@@QAEEXZ
unsigned char owners::C_92370::FUN_00092370() {
    return value;
}

namespace fn_f9a5903c {

// 0x00092410 FUN_00092410 (89 B): matches/0x00092410.cpp
// sym: ?Target@Host_92410@fn_f9a5903c@@QAEXXZ
// data: gItems_92410 = DAT_0049ceb0
void Host_92410::Target() {
    Obj_92410* obj = GetObject();
    if (obj) {
        obj->Setup("constants", 1, 1);
        obj->Setup("unlockables", 0, 1);
        int i = 0;
        do {
            AddThing(obj, ((const char**)&DAT_0049ceb0)[i], i);
            ++i;
        } while (i < 0x2fe);
        ((owners::Obj_1d19d0 *)obj)->FUN_001d19d0(2);
    }
}


// 0x00092540 FUN_00092540 (788 B): equivalent/0x00092540.cpp
// sym: ?FUN_00092540@Registry_92540@fn_f9a5903c@@QAEXHUTriple_92540@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 135 inputs, branch coverage 36/36)
// FUN_00092540 @ 0x00092540
void Registry_92540::FUN_00092540(int kind, Triple_92540 t)
{
    if (kind == 3) {
        this->FUN_00092470(0x52, 0x8d, "comic_%d", t.a, t.b, t.c);
    } else if (kind == 4) {
        if (this->FUN_00092470(0x8f, 0x94, "hint_EXPERIENCE_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x95, 0x98, "hint_COLLECTIBLES_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x99, 0x9b, "hint_WEAPONIZATION_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x9c, 0xa1, "hint_FRSM_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xa2, 0xa4, "hint_CHURCH_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xa5, 0xa9, "hint_CAMERAS_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xaa, 0xae, "hint_RAGE_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xaf, 0xb3, "hint_MOVEMENT_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xb4, 0xc7, "hint_COMBAT_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xc8, 0xcb, "hint_NAVIGATION_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xcc, 0xcf, "hint_HUD_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xd0, 0xd0, "hint_WEAPON_PODS_C4M5_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0xd1, 0xd8, "hint_TARGETING_%d_marker", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        this->FUN_00092470(0xd9, 0xdd, "hint_COMBO_%d_marker", t.a, t.b, t.c);
    } else if (kind == 5) {
        if (this->FUN_00092470(0xe0, 0x11c, "smashMedium%d", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        if (this->FUN_00092470(0x11d, 0x1af, "smash_%d", t.a, t.b, t.c))
            { t.FUN_0027af50(); return; }
        this->FUN_00092470(0x1b0, 0x1bd, "smashMajor%d", t.a, t.b, t.c);
    }
    t.FUN_0027af50();
}

} // namespace fn_f9a5903c

// 0x00092860 FUN_00092860 (13 B): matches/0x00092860.cpp
// sym: ?FUN_00092860@C_92860@owners@@QAEEH@Z
unsigned char owners::C_92860::FUN_00092860(hulk_intptr i) {
    return *((unsigned char*)(((char**)this)[((int)i)]) + 8);
}

namespace fn_f9a5903c {

// 0x00092870 FUN_00092870 (125 B): matches/0x00092870.cpp
// sym: ?FUN_00092870@Container_92870@fn_f9a5903c@@QAEXHD@Z
// FUN_00092870 @ 0x00092870
// equiv-map: ?FUN_000c21b0@Env@@QAEXH@Z = 0x000c2c10
// Sets the flag byte on the two kinds of object held at items[index] and notifies the env on change.
void Container_92870::FUN_00092870(int index, char flag)
{
    bool changed = false;
    Flagged_92870* a = (Flagged_92870*)FUN_00344e74(items[index], 0, DAT_0049dab8, DAT_0049dafc, 0);
    if (a && a->flag != flag) {
        a->flag = flag;
        changed = true;
    }
    Flagged_92870* b = (Flagged_92870*)FUN_00344e74(items[index], 0, DAT_0049dab8, DAT_0049db1c, 0);
    if (b && b->flag != flag) {
        b->flag = flag;
        changed = true;
    }
    if (changed && env)
        env->FUN_000c2c10(index);
}


// 0x000928f0 FUN_000928f0 (66 B): matches/0x000928f0.cpp
// sym: ?f@C_928f0@fn_f9a5903c@@QAEXHH@Z
void C_928f0::f(int index, int value) {
    void* p = Cast((void*)*(hulk_uintptr*)((char*)this + index * 4), 0, &RTTI1_928f0, &RTTI2_928f0, 0);
    if (p) {
        *(u32_928f0*)((char*)p + 0x28) = value;
        if (member)
            member->call(index);
    }
}


// 0x00092940 FUN_00092940 (81 B): matches/0x00092940.cpp
// sym: ?Get@Container_92940@fn_f9a5903c@@QAEEH@Z
u8_92940 Container_92940::Get(int index) {
    Obj_92940* r = (Obj_92940*)Cast(items[index], 0, TypeUnlockable, TypeCheat, 0);
    if (!r)
        r = (Obj_92940*)Cast(items[index], 0, TypeUnlockable, TypeMove, 0);
    if (r)
        return r->value;
    return 0;
}

} // namespace fn_f9a5903c

// 0x00092a40 FUN_00092a40 (135 B): matches/0x00092a40.cpp
// sym: ?FUN_00092a40@C_92a40@owners@@QAEEH@Z
unsigned char owners::C_92a40::FUN_00092a40(int index) {
    void* p = FUN_00344e74(items[index], 0, (const char*)((hulk_intptr)DAT_0049dab8), (const char*)((hulk_intptr)DAT_0049db80), 0);
    if (p)
        return *((unsigned char*)p + 0xb0);
    p = FUN_00344e74(items[index], 0, (const char*)((hulk_intptr)DAT_0049dab8), (const char*)((hulk_intptr)DAT_0049db1c), 0);
    if (p)
        return *((unsigned char*)p + 0x2d);
    p = FUN_00344e74(items[index], 0, (const char*)((hulk_intptr)DAT_0049dab8), (const char*)((hulk_intptr)DAT_0049dad4), 0);
    if (p)
        return *((unsigned char*)p + 0xa8);
    return 0;
}


// 0x00092ad0 FUN_00092ad0 (10 B): matches/0x00092ad0.cpp
// sym: ?FUN_00092ad0@C_92ad0@owners@@QAEHH@Z
hulk_intptr owners::C_92ad0::FUN_00092ad0(hulk_intptr i) {
    return m[((int)i)];
}


// 0x00092bb0 FUN_00092bb0 (13 B): matches/0x00092bb0.cpp
// sym: ?FUN_00092bb0@C_92bb0@owners@@QAEHH@Z
hulk_intptr owners::C_92bb0::FUN_00092bb0(int index) {
    return ((int*)this)[index] + 0x10;
}

namespace fn_f9a5903c {

// 0x00092bc0 FUN_00092bc0 (13 B): matches/0x00092bc0.cpp
// sym: ?f@C_92bc0@fn_f9a5903c@@QAEHH@Z
hulk_intptr C_92bc0::f(int index) {
    return items[index]->value;
}

} // namespace fn_f9a5903c

// 0x00092bd0 FUN_00092bd0 (13 B): matches/0x00092bd0.cpp
// sym: ?FUN_00092bd0@C_92bd0@owners@@QAEXH@Z
void owners::C_92bd0::FUN_00092bd0(hulk_intptr value) {
    *(int*)(pad + 0xd88) = ((int)value);
}


// 0x00092be0 FUN_00092be0 (11 B): matches/0x00092be0.cpp
// sym: ?FUN_00092be0@C_92be0@owners@@QAEXXZ
void owners::C_92be0::FUN_00092be0() {
    value = 0;
}

namespace fn_f9a5903c {

// 0x00092c40 FUN_00092c40 (52 B): equivalent/0x00092c40.cpp
// sym: ?FUN_00092c40@Object@fn_f9a5903c@@QAEHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00092c40 @ 0x00092c40
int Object::FUN_00092c40(int first, int second) {
    for (int i = 0; i < 32; ++i) {
        if (entries[i].first == first && entries[i].second == second)
            return i;
    }
    return -1;
}


// 0x00092c80 FUN_00092c80 (311 B): equivalent/0x00092c80.cpp
// sym: ?FUN_00092c80@SlotTable_92c80@fn_f9a5903c@@QAEXPBDH@Z
// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 40/42, incomplete)
// FUN_00092c80 @ 0x00092c80
void SlotTable_92c80::FUN_00092c80(const char *name, int value)
{
    if (*name == 0)
        return;
    if (value < 0 || value >= 0x2fe)
        return;

    unsigned __int64 key = FUN_0027b020(name);
    int i = 0;
    while (slots[i].key != 0 && slots[i].key != key) {
        i++;
        if (i >= 32)
            return;
    }

    Slot_92c80 *s = &slots[i];
    s->key = key;
    if (FUN_00345804(name, "c%dm%d", &s->chapter, &s->mission) != 2)
        return;
    for (int j = 0; j < 16; j++) {
        if (s->values[j] == value)
            return;
        if (s->values[j] == -1) {
            s->values[j] = value;
            return;
        }
    }
}


// 0x00092dc0 FUN_00092dc0 (29 B): matches/0x00092dc0.cpp
// sym: ?Get@Table_92dc0@fn_f9a5903c@@QAEEH@Z
u8_92dc0 Table_92dc0::Get(i32_92dc0 index) {
    if (index < 0 || index >= 0x2fe)
        return 0;
    return items[index]->value;
}

} // namespace fn_f9a5903c

// 0x00092de0 FUN_00092de0 (29 B): matches/0x00092de0.cpp
// sym: ?FUN_00092de0@ThisWrap_00092de0@owners@@QAEEI@Z
unsigned char owners::ThisWrap_00092de0::FUN_00092de0(unsigned int x) {
    if ((int)x >= 0 && (int)x < 0x2fe)
        return (unsigned char)this->FUN_00092940(x);
    return 0;
}

namespace fn_f9a5903c {

// 0x00092e00 FUN_00092e00 (27 B): matches/0x00092e00.cpp
// sym: ?FUN_00092e00@Obj_92e00@fn_f9a5903c@@QAEXHH@Z
void Obj_92e00::FUN_00092e00(int a, int b) {
    if (a >= 0 && a < 0x2fe) {
        a = a;
        ((ThisCall_00092870*)(this))->Helper(a, b);
    }
}


// 0x00092e20 FUN_00092e20 (47 B): matches/0x00092e20.cpp
// sym: ?FUN_00092e20@Game@fn_f9a5903c@@QAEXHH@Z
void Game::FUN_00092e20(int x, int y) {
    if (x >= 0 && x < 0x2fe && y >= 0 && y < 0x2fe)
        FUN_000928f0(x, y);
}


// 0x00092e50 FUN_00092e50 (153 B): equivalent/0x00092e50.cpp
// sym: ?FUN_00092e50@UnlockableList_92e50@fn_f9a5903c@@QAEXPBDH0000@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_00092e50 @ 0x00092e50
void UnlockableList_92e50::FUN_00092e50(const char *id, int idx, const char *title, const char *subtitle,
                                  const char *file, const char *text)
{
    if (idx < 0x34 || idx > 0x51)
        return;
    CUnlockableBlonskyFile_92e50 *g = dynamic_cast<CUnlockableBlonskyFile_92e50 *>(items[idx]);
    if (g == 0)
        return;
    ((owners::Target_27b040 *)&(g->title))->FUN_0027b040((hulk_uintptr)title);
    ((owners::Target_27b040 *)&(g->subtitle))->FUN_0027b040((hulk_uintptr)subtitle);
    {
        const char *s = file;
        char *d = (char *)g + 0x68;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    if (text) {
        const char *s = text;
        char *d = g->text;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    if (*id)
        FUN_00092c80(id, idx);
}


// 0x00092ef0 FUN_00092ef0 (128 B): matches/0x00092ef0.cpp
// sym: ?FUN_00092ef0@Table_92ef0@fn_f9a5903c@@QAEXHPBD000H@Z
// FUN_00092ef0 @ 0x00092ef0
// 0x00092ef0: fill in a table entry (names, text and flag) for one of the ids 0x266..0x2c9
void Table_92ef0::FUN_00092ef0(int index, const char* a, const char* b, const char* c, const char* text, int value)
{
    if (index < 0x266 || index > 0x2c9)
        return;
    Entry_92ef0* e = (Entry_92ef0*)FUN_00344e74(ids[index], 0, DAT_0049dab8, DAT_0049db1c, 0);
    if (e == 0)
        return;
    ((owners::Target_27b040 *)&(e->name10))->FUN_0027b040((hulk_uintptr)a);
    ((owners::Target_27b040 *)&(e->name38))->FUN_0027b040((hulk_uintptr)b);
    ((owners::Target_27b040 *)&(e->name40))->FUN_0027b040((hulk_uintptr)c);
    strncpy(e->text48, text, 0x40);
    e->value24 = value;
    if (value == 0)
        e->flag20 = 1;
}


// 0x00092f70 FUN_00092f70 (84 B): matches/0x00092f70.cpp
// sym: ?F@C_92f70@fn_f9a5903c@@QAEXHHE@Z
void C_92f70::F(int c, int b, u8_92f70 d) {
    if (b < 100 && c >= 0x266 && c <= 0x2c9) {
        Thing_92f70* t = Cast((Thing_92f70*)values[c], 0, &descA, &descB, 0);
        if (t) {
            *(int*)((char*)this + 0xbf8 + b * 4) = c;
            t->field = d;
        }
    }
}


// 0x00092fd0 FUN_00092fd0 (80 B): matches/0x00092fd0.cpp
// sym: ?Run@Owner@fn_f9a5903c@@QAEXHPAX0@Z
void Owner::Run(int index, void* x, void* y) {
    if (index >= 0x2ca && index <= 0x2dd) {
        Result* r = Make(items[index], 0, &gA, &gB, 0);
        if (r) {
            ((owners::Target_27b040 *)&(r->inner))->FUN_0027b040((hulk_uintptr)x);
            ((owners::TextOwner_92120 *)r)->FUN_00092120((const char *)y);
        }
    }
}

} // namespace fn_f9a5903c

// 0x00093020 FUN_00093020 (227 B): equivalent/0x00093020.cpp [wrapped: conflict: DAT_0049dab8; DAT_0049dafc]
// sym: ?FUN_00093020@Container_93020@fn_00093020@@QAEXHPAX0@Z
namespace fn_00093020 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_00093020 @ 0x00093020
extern char DAT_0049dab8;
extern char DAT_0049dafc;
struct Value_93020 {  char bytes[20]; };
struct Item_93020 { char pad[16]; Value_93020 value; int kind; char data[8]; };
extern Item_93020* __cdecl FUN_00344e74(void*, int, void*, void*, int);
extern void __cdecl FUN_00267760(void*, int, void*, ...);
struct Container_93020 { void* items[50]; void FUN_00093020(int index, void* source, void* data); };
void Container_93020::FUN_00093020(int index, void* source, void* data) {
 if (index < 0 || index > 49) return;
 Item_93020* item = FUN_00344e74(items[index], 0, &DAT_0049dab8, &DAT_0049dafc, 0);
 if (!item) return;
 ((owners::Target_27b040 *)&(item->value))->FUN_0027b040((hulk_uintptr)source);
 FUN_00267760(item->data, 8, data);
 switch(index) {
 case 2: item->kind=0x58; break;
 case 26: item->kind=0x67; break;
 case 37: item->kind=0x77; break;
 case 47: item->kind=0x87; break;
 case 38: item->kind=0x88; break;
 case 20: item->kind=0x89; break;
 case 19: item->kind=0x8d; break;
 case 1: item->kind=0x21; break;
 }
}
} // namespace fn_00093020

namespace fn_f9a5903c {

// 0x00093110 FUN_00093110 (57 B): matches/0x00093110.cpp
// sym: @FUN_00093110@12
extern "C" float* __fastcall FUN_00093110(Obj_93110* self, void*, int index) {
    if (index < 0 || index > 0x31)
        return (float*)((hulk_intptr)((char*)&DAT_003f335c));
    hulk_intptr result = FUN_00344e74((void*)self->slots[index], 0, &CUnlockable_RTTI_Type_Descriptor,
                              &CUnlockableCheat_RTTI_Type_Descriptor, 0);
    if (result != 0)
        return (float*)(result + 0x28);
    return (float*)((hulk_intptr)((char*)&DAT_003f335c));
}


// 0x00093150 FUN_00093150 (153 B): equivalent/0x00093150.cpp
// sym: ?FUN_00093150@UnlockableList_93150@fn_f9a5903c@@QAEXPBDH0000H@Z
// STATUS: equivalent (tools/equiv.py level 3: 1169 inputs, branch coverage 12/12)
// FUN_00093150 @ 0x00093150
void UnlockableList_93150::FUN_00093150(const char *id, int idx, const char *title, const char *subtitle,
                                  const char *caption, const char *path, int flags)
{
    CUnlockableGallery_93150 *g = dynamic_cast<CUnlockableGallery_93150 *>(items[idx]);
    if (g == 0)
        return;
    ((owners::Target_27b040 *)&(g->title))->FUN_0027b040((hulk_uintptr)title);
    ((owners::Target_27b040 *)&(g->subtitle))->FUN_0027b040((hulk_uintptr)subtitle);
    if (caption) {
        const char *s = caption;
        char *d = g->caption;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    if (path) {
        const char *s = path;
        char *d = g->path;
        char c;
        do {
            c = *s++;
            *d++ = c;
        } while (c);
    }
    g->flags = flags;
    if (*id)
        FUN_00092c80(id, idx);
}

} // namespace fn_f9a5903c

// 0x000931f0 FUN_000931f0 (106 B): matches/0x000931f0.cpp [wrapped: conflict: Cast]
// sym: ?F@C_931f0@fn_000931f0@@QAEXPADH0H@Z
namespace fn_000931f0 {
extern "C++" __declspec(nothrow) void* __cdecl Cast(void*, int, void*, void*, int);
void __cdecl Setup(void* p, int n, int v, ...);
extern char TdA[], TdB[];
inline void Copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        *d = c;
        s++;
        d++;
    } while (c);
}
class C_931f0 {
  public:
    void* arr[1];
    void F(char* a, int idx, char* name, int v);
    void G(char*, int);
};
struct M_931f0 {
    char pad[0x28];
    char a[8];
    char name[1];
};
void C_931f0::F(char* a, int idx, char* name, int v) {
    M_931f0* o = (M_931f0*)Cast(arr[idx], 0, TdA, TdB, 0);
    if (o) {
        if (name)
            Copy(o->name, name);
        Setup(o->a, 8, v);
        if (*a)
            G(a, idx);
    }
}
} // namespace fn_000931f0

namespace fn_f9a5903c {

// 0x00093260 FUN_00093260 (59 B): matches/0x00093260.cpp
// sym: @FUN_00093260@12
extern "C" int __fastcall FUN_00093260(Owner_93260* self, void*, int id) {
    if (id >= 0x2ca && id <= 0x2dd) {
        CUnlockable* p = (CUnlockable*)FindType((void*)self->values[id], 0, &typeA_93260, &typeB_93260, 0);
        if (p)
            return p->value;
    }
    return 0;
}

} // namespace fn_f9a5903c

// 0x000932a0 FUN_000932a0 (25 B): matches/0x000932a0.cpp
// sym: ?FUN_000932a0@C_932a0@owners@@QAEHH@Z
int owners::C_932a0::FUN_000932a0(int index) {
    if (index >= 100)
        return -1;
    return values[index];
}

