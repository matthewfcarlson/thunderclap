// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e8710..0x001e8c20 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c09d09 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9c09d09 {} using namespace fn_f9c09d09;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f9c09d09 {
struct Info {
    char data[24];
    unsigned int a, b;
    char extra[8];
};
extern "C" void FUN_00240ca0(Info*);
extern "C" const float g_bias = 4294967296.0f;
struct Data { char pad[0x38]; void *buffer; unsigned int count; };
extern "C" int __cdecl FUN_00266eb0(int, void *, unsigned int);
extern "C" int __cdecl FUN_00266e00(int, void *);
struct Obj {
    char pad[0x3c];
    unsigned int n;
};
extern "C" void __cdecl FUN_00267070(void*);
extern "C" void __cdecl FUN_00267090(void*);
class Item_1e8880 {
  public:
    virtual void F0();
    virtual void F1();
    virtual void Destroy(int flag);
};
class Holder_1e8880 {
  public:
    char pad[8];
    Item_1e8880* mItems[100];
    int mCount;
    void Remove(Item_1e8880* item);
};
extern int __cdecl MakeThing_0008d710(int, int);
class Thing_1e8910 {
  public:
    char pad[0x19c];
    int items[200];
    int count;
};
extern "C" char DAT_00423f28[];
typedef unsigned int u32_1e8960;
extern void* __cdecl alloc_0008d710(unsigned int, unsigned int);
struct SoundMix {
    u32_1e8960* vptr;
    u32_1e8960 a;
    u32_1e8960 b;
};
class Manager_1e8960 {
  public:
    char pad[0x4c0];
    SoundMix* slots[20];
    int count;
    SoundMix* Add();
};
class Sub_1e8a60 {
  public:
};
class Obj_1e8b00 {
  public:
    char pad[0x10];
    int mValue;
};
struct IRefCount {
    virtual void a();
    virtual void Release();
};
struct CSoundSequence {
    void** vptr;
    char pad[0x18];
    IRefCount* member;
    void cleanup();
};
extern void* hulk_at_00423f38[];
extern void* hulk_at_003f6098[];

} // namespace fn_f9c09d09

// 0x001e8710 FUN_001e8710 (14 B): matches/0x001e8710.cpp
// sym: ?FUN_001e8710@Obj_1e8710@owners@@QAE_NXZ
bool owners::Obj_1e8710::FUN_001e8710() {
    void* p = member;
    return p != 0;
}

namespace fn_f9c09d09 {

// 0x001e8730 FUN_001e8730 (73 B): matches/0x001e8730.cpp
// sym: ?calc@fn_f9c09d09@@YANPAX@Z
double calc(void* /*this, unused: callers pass it (unb4)*/) {
    Info info;
    FUN_00240ca0(&info);
    return (float)info.a * (float)info.b - DAT_004e36a4 - DAT_004e36a0 - DAT_004e369c;
}


// 0x001e8780 FUN_001e8780 (55 B): matches/0x001e8780.cpp
// sym: _FUN_001e8780@4
// data: g_accum = DAT_004e36a8, g_limit_1e8780 = DAT_004e36a4
extern "C" bool __stdcall FUN_001e8780(int value) {
    hulk_freg next = (hulk_freg)value;
    if (value < 0)
        next += g_bias;
    next += (*(float*)&DAT_004e36a8);
    if (next < DAT_004e36a4) {
        (*(float*)&DAT_004e36a8) = next;
        return true;
    }
    return false;
}


// 0x001e87c0 FUN_001e87c0 (33 B): matches/0x001e87c0.cpp
// sym: ?FUN_001e87c0@fn_f9c09d09@@YGXH@Z
// data: gBias = DAT_003f3f18, gValue_1e87c0 = DAT_004e36a8
void __stdcall FUN_001e87c0(int amount) {
    if (amount < 0) {
        (*(float*)&DAT_004e36a8) -= (float)amount + DAT_003f3f18;
    } else {
        (*(float*)&DAT_004e36a8) -= (float)amount;
    }
}


// 0x001e8800 FUN_001e8800 (45 B): equivalent/0x001e8800.cpp
// sym: _FUN_001e8800 @1558f6d9b5dc @w059a1feee1a7
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001e8800 @ 0x001e8800
extern "C" int __cdecl FUN_001e8800(int unused, Data *data) {
    if (data->count > 4)
        return FUN_00266eb0(6, data->buffer, data->count);
    return FUN_00266e00(6, data->buffer);
}


// 0x001e8830 FUN_001e8830 (36 B): matches/0x001e8830.cpp
// sym: _FUN_001e8830
extern "C" void __cdecl FUN_001e8830(void* unused, Obj* obj, void* arg) {
    if (obj->n > 4)
        FUN_00267070(arg);
    else
        FUN_00267090(arg);
}


// 0x001e8880 FUN_001e8880 (143 B): matches/0x001e8880.cpp
// sym: ?Remove@Holder_1e8880@fn_f9c09d09@@QAEXPAVItem_1e8880@2@@Z
void Holder_1e8880::Remove(Item_1e8880* item) {
    if (!item)
        return;
    int i;
    for (i = 0; i < mCount; i++) {
        if (mItems[i] == item) {
            Item_1e8880* p = mItems[i];
            Item_1e8880** slot = &mItems[i];
            if (p)
                p->Destroy(1);
            *slot = 0;
            int j = i;
            while (j < mCount - 1) {
                mItems[j] = mItems[j + 1];
                j++;
            }
            mCount--;
            mItems[mCount] = 0;
            return;
        }
    }
}


// 0x001e8910 FUN_001e8910 (66 B): matches/0x001e8910.cpp
// sym: ?Target@fn_f9c09d09@@YIHPAVThing_1e8910@1@@Z
int __fastcall Target(Thing_1e8910* self) {
    if (self->count >= 200)
        return 0;
    int value = MakeThing_0008d710(0x14, 6);
    self->items[self->count] = value;
    value = self->items[self->count];
    ++self->count;
    return value;
}


// 0x001e8960 FUN_001e8960 (85 B): matches/0x001e8960.cpp
// sym: ?Add@Manager_1e8960@fn_f9c09d09@@QAEPAUSoundMix@2@XZ
SoundMix* Manager_1e8960::Add() {
    if (count >= 20)
        return 0;
    SoundMix* p = (SoundMix*)alloc_0008d710(0x10, 6);
    if (p != 0) {
        p->vptr = (u32_1e8960*)((hulk_intptr)DAT_00423f28);
        p->a = 0;
        p->b = 0;
    } else {
        p = 0;
    }
    slots[count] = p;
    SoundMix* result = slots[count];
    ++count;
    return result;
}

} // namespace fn_f9c09d09

// 0x001e8a50 FUN_001e8a50 (3 B): matches/0x001e8a50.cpp
// sym: ?FUN_001e8a50@X_1e8a50@owners@@QAEXH@Z
void owners::X_1e8a50::FUN_001e8a50(int) {}

namespace fn_f9c09d09 {

// 0x001e8a60 FUN_001e8a60 (11 B): matches/0x001e8a60.cpp
// sym: _FUN_001e8a60
// data: g_sub_1e8a60 = DAT_00527c58
extern "C" void __cdecl FUN_001e8a60() {
    ((owners::Q_264d20 *)((*(Sub_1e8a60**)&DAT_00527c58)))->FUN_00264d20();
}

} // namespace fn_f9c09d09

// 0x001e8a90 FUN_001e8a90 (48 B): matches/0x001e8a90.cpp [wrapped: conflict: Obj]
// sym: ?AddRef@Obj@fn_001e8a90@@QAEXXZ
namespace fn_001e8a90 {
struct Item {
    char pad[12];
    int refs;
};
class Obj {
  public:
    char pad0[0x24];
    int refs;
    char pad1[4];
    Item* items[64];
    int count;
    void AddRef();
};
void Obj::AddRef() {
    ++refs;
    for (int i = 0; i < count; ++i) {
        if (items[i])
            ++items[i]->refs;
    }
}
} // namespace fn_001e8a90


// 0x001e8ac0 FUN_001e8ac0 (44 B): matches/0x001e8ac0.cpp [wrapped: conflict: Obj]
// sym: ?Release@Obj@fn_001e8ac0@@QAEXXZ
namespace fn_001e8ac0 {
struct Item {
    char pad[12];
    int refs;
};
class Obj {
  public:
    char a[0x24];
    int count;
    char b[4];
    Item* items[64];
    void Release();
};
void Obj::Release() {
    for (int i = 0; i < *(int*)((char*)this + 0x12c); ++i) {
        if (items[i])
            --items[i]->refs;
    }
    --count;
}
} // namespace fn_001e8ac0

namespace fn_f9c09d09 {

// 0x001e8b00 FUN_001e8b00 (4 B): matches/0x001e8b00.cpp
// sym: ?FUN_001e8b00@fn_f9c09d09@@YIPAHPAVObj_1e8b00@1@@Z
int* __fastcall FUN_001e8b00(Obj_1e8b00* self) {
    return &self->mValue;
}


// 0x001e8bf0 FUN_001e8bf0 (36 B): matches/0x001e8bf0.cpp
// sym: ?cleanup@CSoundSequence@fn_f9c09d09@@QAEXXZ
void CSoundSequence::cleanup() {
    vptr = hulk_at_00423f38;
    if (member) {
        member->Release();
        member = 0;
    }
    vptr = hulk_at_003f6098;
}

} // namespace fn_f9c09d09
