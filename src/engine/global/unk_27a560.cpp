// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027a560..0x0027ab50 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ff5ed045 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff5ed045 {} using namespace fn_ff5ed045;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_ff5ed045 {
extern void* IRefCount_vftable_27a560;
struct E_27a570 {
    void f();
};
struct Temp_27a590 {
    char data[8];
    void Build(int);
    void Finish();
};
struct Item_27a590 {
    char data[8];
    void Copy(Temp_27a590*);
};
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_0027aec0 {
    void FUN_0027aec0();
};
extern void thunk_FUN_00267090(CCollisionAction*);
class Slot_27a630 {
  public:
    char pad[8];
    void Init();
};
class Target_27a630 {
  public:
    Slot_27a630 slots[20];
    int values[21];
    Target_27a630* Fn();
};
class RDLObject {
  public:
    hulk_intptr vtable;
    char pad[0x10 - 4];
    int a;
    int b;
    char pad2[0x1f];
    unsigned char c;
    void Initialize();
    RDLObject();
};
extern int vtable_27a890;
} // namespace fn_ff5ed045
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strncmp(const char*, const char*, unsigned int);
#endif
namespace fn_ff5ed045 {
struct NameEntry_27a970 {
    char text[32];
};
struct NameRing {
    char pad0[0x10];
    unsigned int current;
    unsigned int capacity;
    char pad18[0x20];
    NameEntry_27a970 entries[1];
    bool FUN_0027a970(const char* name);
};
int __cdecl FUN_00345804(char* dst, const char* fmt, int value);
struct This_FUN_0027a970 {
    bool FUN_0027a970(int a);
};
typedef unsigned char bool8_27aac0;
extern int Format(char*, const char*, float*, float*, float*);


// 0x0027a560 FUN_0027a560 (7 B): matches/0x0027a560.cpp
// sym: @FUN_0027a560@4
// Same code shape as 0x001b6820 (propagated; names are from that function)
extern "C" void __fastcall FUN_0027a560(void* self) {
    *(void**)self = &IRefCount_vftable_27a560;
}

} // namespace fn_ff5ed045

// 0x0027a570 FUN_0027a570 (32 B): matches/0x0027a570.cpp
// sym: ?FUN_0027a570@X_27a570@owners@@QAEXXZ
void owners::X_27a570::FUN_0027a570() {
    E_27a570* p = (E_27a570*)((char*)this + 0xa0);
    int i = 0x14;
    do {
        p = (E_27a570*)((char*)p - 8);
        p->f();
        --i;
    } while (i != 0);
}


// 0x0027a590 FUN_0027a590 (87 B): matches/0x0027a590.cpp
// sym: ?FUN_0027a590@Obj_27a590@owners@@QAEXHH@Z
void owners::Obj_27a590::FUN_0027a590(hulk_intptr a, hulk_intptr b) {
    Temp_27a590 t;
    if (count < 20) {
        t.Build(((int)a));
        ((Item_27a590*)((char*)this + count * 8))->Copy(&t);
        t.Finish();
        values[count] = ((int)b);
        ++count;
    }
}

namespace fn_ff5ed045 {

// 0x0027a5f0 FUN_0027a5f0 (30 B): matches/0x0027a5f0.cpp
// sym: ?vfunc_2@CCollisionAction@fn_ff5ed045@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_0027aec0*)(this))->FUN_0027aec0();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x0027a630 FUN_0027a630 (167 B): matches/0x0027a630.cpp
// sym: ?Fn@Target_27a630@fn_ff5ed045@@QAEPAV12@XZ
Target_27a630* Target_27a630::Fn() {
    for (int i = 0; i < 20; ++i)
        slots[i].Init();
    values[20] = 0;
    for (int j = 0; j < 20; ++j)
        values[j] = 0;
    return this;
}

} // namespace fn_ff5ed045

// 0x0027a850 FUN_0027a850 (50 B): matches/0x0027a850.cpp [wrapped: conflict: strncpy]
// sym: ??0RDLObject@fn_0027a850@@QAE@PBD@Z
namespace fn_0027a850 {
/* size_t: tree_prelude.h */

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, size_t);
#endif

extern int DAT_0042c0f8;
class RDLObject {
  public:
    void init();
    int* vp;
    char pad[12];
    int a;
    int b;
    char rest[0x37 - 0x18];
    char flag;
    RDLObject(const char*);
};
RDLObject::RDLObject(const char* p) {
    init();
    a = 0;
    b = 0;
    flag = 0;
    vp = &DAT_0042c0f8;
    strncpy((char*)this + 0x18, p, 0x1f);
}
} // namespace fn_0027a850

namespace fn_ff5ed045 {

// 0x0027a890 FUN_0027a890 (29 B): matches/0x0027a890.cpp
// sym: ??0RDLObject@fn_ff5ed045@@QAE@XZ
RDLObject::RDLObject() {
    Initialize();
    a = 0;
    b = 0;
    c = 0;
    *(hulk_intptr*)this = (hulk_intptr)&vtable_27a890;
}

} // namespace fn_ff5ed045

// 0x0027a8c0 FUN_0027a8c0 (33 B): matches/0x0027a8c0.cpp
// sym: ?FUN_0027a8c0@Target_27a8c0@owners@@QAEXPBD@Z
void owners::Target_27a8c0::FUN_0027a8c0(const char* source) {
    field10 = 0;
    field14 = 0;
    flag = 0;
    strncpy(text, source, 0x1f);
}


// 0x0027a8f0 FUN_0027a8f0 (113 B): matches/0x0027a8f0.cpp
// sym: ?FUN_0027a8f0@Thing_27a8f0@owners@@QAEDPBD0@Z
char owners::Thing_27a8f0::FUN_0027a8f0(const char* a, const char* b) {
    if (count + 1 == 0x68)
        return 0;
    names[count * 32 + 31] = 0;
    strncpy(names + count * 32, a, 31);
    desc[count * 96 + 0x5f] = 0;
    strncpy(desc + count * 96, b, 95);
    ++count;
    return 1;
}

namespace fn_ff5ed045 {

// 0x0027a970 FUN_0027a970 (92 B): matches/0x0027a970.cpp
// sym: ?FUN_0027a970@NameRing@fn_ff5ed045@@QAE_NPBD@Z
bool NameRing::FUN_0027a970(const char* name) {
    unsigned int start = current;
    for (;;) {
        if (strncmp(entries[current].text, name, 32) == 0)
            return true;
        current = (current + 1U) % capacity;
        if (current == start)
            return false;
    }
}

} // namespace fn_ff5ed045

// 0x0027a9d0 FUN_0027a9d0 (68 B): matches/0x0027a9d0.cpp
// sym: ?FUN_0027a9d0@Obj_27a9d0@owners@@QAE_NHH@Z
// data: formatString_27a9d0 = DAT_0042c10c
bool owners::Obj_27a9d0::FUN_0027a9d0(hulk_intptr a, hulk_intptr b) {
    if (((This_FUN_0027a970*)this)->FUN_0027a970(((int)a))) {
        return FUN_00345804((char*)this + 0xd38 + index * 0x60, DAT_0042c10c, ((int)b)) == 1;
    }
    return false;
}


// 0x0027aa20 FUN_0027aa20 (68 B): matches/0x0027aa20.cpp
// sym: ?FUN_0027aa20@Obj_27aa20@owners@@QAE_NHH@Z
// Same code shape as 0x0027a9d0 (propagated; names are from that function)
// data: formatString_27aa20 = DAT_0042c110
bool owners::Obj_27aa20::FUN_0027aa20(hulk_intptr a, hulk_intptr b) {
    if (((This_FUN_0027a970*)this)->FUN_0027a970(((int)a))) {
        return FUN_00345804((char*)this + 0xd38 + index * 0x60, DAT_0042c110, ((int)b)) == 1;
    }
    return false;
}


// 0x0027aac0 FUN_0027aac0 (61 B): matches/0x0027aac0.cpp
// sym: ?FUN_0027aac0@Obj_27aac0@owners@@QAEEHPAH@Z
bool8_27aac0 owners::Obj_27aac0::FUN_0027aac0(hulk_intptr a, int* out) {
    if (Check(((int)a))) {
        *(hulk_intptr*)out = index * 0x60 + (hulk_intptr)this + 0xd38;
        return 1;
    }
    *out = 0;
    return 0;
}


// 0x0027ab00 FUN_0027ab00 (78 B): matches/0x0027ab00.cpp
// sym: ?FUN_0027ab00@Obj_27ab00@owners@@QAE_NHPAM@Z
// data: fmt_27ab00 = DAT_0042c120
bool owners::Obj_27ab00::FUN_0027ab00(hulk_intptr a, float* p) {
    if (Check(((int)a)))
        return Format((char*)((char*)this + 0xd38 + index * 0x60), DAT_0042c120, p, (float*)((char*)p + 4),
                      (float*)((char*)p + 8)) == 3;
    return false;
}

