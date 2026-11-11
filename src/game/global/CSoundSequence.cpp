// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001e8c20..0x001e9de0 (kind game, layer game, confidence high), dominant class CSoundSequence
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/core.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9e85a4e {
#define TREE_TU_END }
namespace fn_f9e85a4e {} using namespace fn_f9e85a4e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9e85a4e {
class IRefCount_1e8c20 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
typedef unsigned int U_1e8c70;
extern U_1e8c70 __cdecl F40750();
extern void __cdecl F416c0(U_1e8c70, hulk_uintptr, int);
extern void __cdecl F43090(U_1e8c70, hulk_uintptr);
extern void __cdecl F42ca0(U_1e8c70, hulk_uintptr);
class Obj_1e8c70 {
  public:
    char pad[0x34];
    int field;
};
class Target_1e8c70 {
  public:
    char pad[0xc];
    Obj_1e8c70* p;
};
extern "C" int __cdecl get();
extern "C" void __cdecl action(int, int, float);
class Obj {
    char pad[12];
    int value;

  public:
    void fn(unsigned int n);
};
void *__cdecl FUN_00240750();
extern "C" void __cdecl FUN_002416c0(void*, void*, float);
class Manager_1e8e00 {
  public:
    bool Ready();
    void Finish();
};
class State_1e8e00 {
  public:
    int value;
    void update();
};
struct X_1e9000 {
    int a, b;
    X_1e9000* copy(X_1e9000* p);
};
class CSoundSequence_1e9180 : public core::IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual CSoundSequence_1e9180* f2(unsigned char);
    char pad[0x18];
    void* member;
};
extern int seq_vftable_1e9180, base_vftable;
struct LevelKeys {
    unsigned __int64 keys[28];
};
extern "C" void *FUN_0008d6d0(unsigned int size);
} // namespace fn_f9e85a4e
unsigned __int64 FUN_002672f0(const char *s, unsigned __int64 seed);
namespace fn_f9e85a4e {
struct Counted_1e9680 {
    char pad0[0xc];
    int refs;
};
class Item_1e9680 {
public:
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int freeMemory);
    char pad04[0x20];
    int users;
    char pad28[4];
    Counted_1e9680 *list[0x40];
    int listCount;
};
struct Node {
    char pad0[0x34];
    void *next;
};
class Entry_1e9680 {
public:
    virtual void v0();
    virtual void v1();
    virtual void Destroy(int freeMemory);
    char pad04[8];
    Node *node;
};
void __cdecl FUN_002416c0(void *a, Node *node, int flag);
void __cdecl FUN_00243090(void *a, float f);
void __cdecl FUN_00242ca0(void *a, Node **node);
class Manager_1e9680;
struct Renderer_1e9680 {
    void FUN_00265560(Manager_1e9680 *m);
};
extern "C" void __cdecl FUN_00240eb0();
extern "C" void __cdecl FUN_00240a10();
class Manager_1e9680 {
public:
    char pad0[8];
    Item_1e9680 *items[100];
    int itemCount;
    void *blocks[200];
    int blockCount;
    Entry_1e9680 *entries[20];
    int entryCount;
    void FUN_001e9680();
};
struct Entry { char pad[0x10]; int first; int second; };
struct Owner { char pad[8]; Entry* entries[100]; int count; Entry* FUN_001e9860(int first, int second); };
struct Key_1e98b0 {
    int a;
    int b;
};
struct Entry_1e98b0 {
    char pad[0x10];
    int a;
    int b;
};
class Obj_1e98b0 {
  public:
    char pad[8];
    void* items[100];
    int count;
    void* find(Key_1e98b0* key);
};
struct Pair_1e9900 {
    int a, b;
};
struct Item_1e9900 {
    char pad[4];
    Pair_1e9900* pair;
};
class Obj_1e9900 {
  public:
    char pad[0x19c];
    Item_1e9900* items[200];
    int count;
    void* Find(int* key);
};
int CheckThing();
void ApplyThing(int, int, float);
struct Obj_1e9a90 {
    char pad[12];
    int value;
    void Reset(int);
};
struct ThisCall_001e9960 {
    void* FUN_001e9960(int);
};
struct Sound_1e9b20 { char pad[0xc]; int handle; };
void __cdecl FUN_002416c0(void *mixer, int handle, float volume);
void __cdecl FUN_00242f60(void *mixer, int handle, float volume);
class Mixer {
public:
    char pad0[0x514];
    Sound_1e9b20 *current;
    void FUN_001e9b20(unsigned int volume);
};
struct Pair_1e9bc0 {
    int a;
    int b;
};
struct Clock_1e9bf0 { float FUN_001e8730(); };
struct Entry_1e9bf0 { int state; int unused; unsigned int amount; int blockedC; int blocked10;  };
struct Worker_1e9bf0 { bool FUN_00266750(); void FUN_00263e90(); };
struct Item_1e9bf0 { void FUN_000bd1b0(int); };
struct Manager_1e9bf0 { Item_1e9bf0* FUN_00086280(); };
} // namespace fn_f9e85a4e
struct World { char pad[0x54]; Manager_1e9bf0* manager; };
namespace fn_f9e85a4e {
struct Owner_1e9bf0 { char pad[0x29]; bool done; char pad2[2]; Entry_1e9bf0* entries[64]; int count; bool FUN_001e9bf0(); };

} // namespace fn_f9e85a4e

// 0x001e8c20 CSoundSequence::vfunc_0 (4 B): matches/0x001e8c20.cpp
// sym: ?vfunc_0@CSoundSequence@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void CSoundSequence::vfunc_0() {
    ++this->f_04;
}


// 0x001e8c30 CSoundSequence::vfunc_1 (13 B): matches/0x001e8c30.cpp [wrapped: conflict: CSoundSequence]
// sym: ?vfunc_1@CSoundSequence@fn_001e8c30@@UAEXXZ
namespace fn_001e8c30 {
// Same code shape as 0x001e86c0 (propagated; names are from that function)
class CSoundSequence {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int);
    int mRefCount;
};
void CSoundSequence::vfunc_1() {
    if (--mRefCount == 0)
        vfunc_2(1);
}
} // namespace fn_001e8c30

namespace fn_f9e85a4e {

// 0x001e8c70 FUN_001e8c70 (80 B): matches/0x001e8c70.cpp
// sym: ?target@fn_f9e85a4e@@YIXPAVTarget_1e8c70@1@@Z
void __fastcall target(Target_1e8c70* self) {
    U_1e8c70 x = F40750();
    Obj_1e8c70** q = &self->p;
    F416c0(x, (hulk_uintptr)*q, 0);
    while ((*q)->field != 0) {
        F43090(F40750(), 0x3a83126f);
    }
    F42ca0(F40750(), (hulk_uintptr)q);
}


// 0x001e8cc0 FUN_001e8cc0 (56 B): matches/0x001e8cc0.cpp
// sym: ?fn@Obj@fn_f9e85a4e@@QAEXI@Z
void Obj::fn(unsigned int n) {
    if (get()) {
        int x = get();
        float f = (float)n;
        action(x, value, f);
    }
}

} // namespace fn_f9e85a4e

// 0x001e8d00 FUN_001e8d00 (56 B): matches/0x001e8d00.cpp
// sym: ?FUN_001e8d00@Thing_1e8d00@owners@@QAEXI@Z
void owners::Thing_1e8d00::FUN_001e8d00(unsigned int n) {
    if (FUN_00240750()) {
        void* p = FUN_00240750();
        FUN_002416c0(p, value, (float)n);
    }
}

namespace fn_f9e85a4e {

// 0x001e8e00 FUN_001e8e00 (52 B): matches/0x001e8e00.cpp
// sym: ?update@State_1e8e00@fn_f9e85a4e@@QAEXXZ
// data: gObject_1e8e00 = DAT_004e3694
void State_1e8e00::update() {
    int n = value;
    --n;
    if (n == 0) {
        if ((*(Manager_1e8e00**)&DAT_004e3694)->Ready()) {
            value = 3;
            (*(Manager_1e8e00**)&DAT_004e3694)->Finish();
            (*(Manager_1e8e00**)&DAT_004e3694) = 0;
        }
    }
}


// 0x001e9000 FUN_001e9000 (19 B): matches/0x001e9000.cpp
// sym: ?copy@X_1e9000@fn_f9e85a4e@@QAEPAU12@PAU12@@Z
X_1e9000* X_1e9000::copy(X_1e9000* p) {
    a = p->a;
    b = p->b;
    return this;
}


// 0x001e9180 CSoundSequence::vfunc_2 (56 B): matches/0x001e9180.cpp
// sym: ?f2@CSoundSequence_1e9180@fn_f9e85a4e@@UAEPAV12@E@Z
CSoundSequence_1e9180* CSoundSequence_1e9180::f2(unsigned char flag) {
    *(hulk_ulongptr*)this = (hulk_ulongptr)&seq_vftable_1e9180;
    if (member) {
        struct X {
            virtual void a();
            virtual void b();
        };
        ((X*)member)->b();
        member = 0;
    }
    *(hulk_ulongptr*)this = (hulk_ulongptr)&base_vftable;
    if (flag & 1)
        thunk(this);
    return this;
}


// 0x001e91c0 FUN_001e91c0 (1018 B): equivalent/0x001e91c0.cpp
// sym: _FUN_001e91c0
// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 2/2)
// FUN_001e91c0 @ 0x001e91c0
extern "C" void FUN_001e91c0(void)
{
    LevelKeys *k = (LevelKeys *)FUN_0008d6d0(sizeof(LevelKeys));
    if (k != 0) {
        unsigned int *w = (unsigned int *)k;
        w[0] = 0;
        w[1] = 0;
        for (int i = 0; i < 0x36; i++) {
            w[i + 2] = w[i];
        }
    }
    (*(LevelKeys**)&DAT_004e2788) = k;
    (*(LevelKeys**)&DAT_004e2788)->keys[0] = FUN_002672f0("ghk", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[1] = FUN_002672f0("ghk_sidemissions", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[2] = FUN_002672f0("ghk_c0m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[3] = FUN_002672f0("ghk_c0m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[4] = FUN_002672f0("ghk_c1m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[5] = FUN_002672f0("ghk_c1m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[6] = FUN_002672f0("ghk_c1m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[7] = FUN_002672f0("ghk_c1m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[8] = FUN_002672f0("ghk_c1m5", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[9] = FUN_002672f0("ghk_c2m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[10] = FUN_002672f0("ghk_c2m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[11] = FUN_002672f0("ghk_c2m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[12] = FUN_002672f0("ghk_c2m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[13] = FUN_002672f0("ghk_c3m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[14] = FUN_002672f0("ghk_c3m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[15] = FUN_002672f0("ghk_c3m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[16] = FUN_002672f0("ghk_c4m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[17] = FUN_002672f0("ghk_c4m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[18] = FUN_002672f0("ghk_c4m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[19] = FUN_002672f0("ghk_c4m5", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[20] = FUN_002672f0("ghk_c5m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[21] = FUN_002672f0("ghk_c5m4", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[22] = FUN_002672f0("ghk_c6m1", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[23] = FUN_002672f0("ghk_c6m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[24] = FUN_002672f0("ghk_c6m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[25] = FUN_002672f0("ghk_c7m2", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[26] = FUN_002672f0("ghk_c7m3", 0);
    (*(LevelKeys**)&DAT_004e2788)->keys[27] = FUN_002672f0("ghk_c10m30", 0);
}


// 0x001e9680 FUN_001e9680 (365 B): equivalent/0x001e9680.cpp
// sym: ?FUN_001e9680@Manager_1e9680@fn_f9e85a4e@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 51 inputs, branch coverage 28/28)
// FUN_001e9680 @ 0x001e9680
void Manager_1e9680::FUN_001e9680()
{
    FUN_0008d340((*(void**)&DAT_004e2788));
    for (int i = 0; i < itemCount; i++) {
        Item_1e9680 *item = items[i];
        if (item->users > 0) {
            for (int j = 0; j < item->listCount; j++) {
                Counted_1e9680 *c = item->list[j];
                if (c != 0)
                    c->refs--;
            }
            item->users--;
        }
        if (items[i] != 0)
            items[i]->Destroy(1);
        items[i] = 0;
    }
    itemCount = 0;
    for (int i = 0; i < blockCount; i++) {
        FUN_0008d330(blocks[i]);
        blocks[i] = 0;
    }
    blockCount = 0;
    for (int i = 0; i < entryCount; i++) {
        Entry_1e9680 *e = entries[i];
        void *ctx = FUN_00240750();
        FUN_002416c0(ctx, e->node, 0);
        if (e->node->next != 0) {
            do {
                FUN_00243090(FUN_00240750(), 0.001f);
            } while (e->node->next != 0);
        }
        FUN_00242ca0(FUN_00240750(), &e->node);
        if (entries[i] != 0)
            entries[i]->Destroy(1);
        entries[i] = 0;
    }
    entryCount = 0;
    (*(Renderer_1e9680**)&DAT_00527c58)->FUN_00265560(this);
    FUN_00240eb0();
    FUN_00240a10();
    (*(hulk_intptr*)&DAT_004e3690) = 0;
}

} // namespace fn_f9e85a4e

// 0x001e97f0 FUN_001e97f0 (109 B): matches/0x001e97f0.cpp [wrapped: conflict: CSoundSequence]
// sym: ?Add@Owner_1e97f0@fn_001e97f0@@QAEPAUCSoundSequence@2@XZ
namespace fn_001e97f0 {
extern "C" char DAT_00423f38[];
extern "C" void* __cdecl FUN_0008d710(unsigned int, unsigned int);
struct CSoundSequence {
    hulk_uintptr vt;
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;
    unsigned char pad[4];
    unsigned char j;
    unsigned char k;
    unsigned char pad2[0x102];
    unsigned int z;
};
class Owner_1e97f0 {
  public:
    char pad0[8];
    CSoundSequence* slots[100];
    int count;
    CSoundSequence* Add();
};
CSoundSequence* Owner_1e97f0::Add() {
    if (count >= 100)
        return 0;
    CSoundSequence* r0 = (CSoundSequence*)FUN_0008d710(0x130, 6);
    CSoundSequence* p;
    if (r0) {
        r0->vt = ((hulk_intptr)DAT_00423f38);
        r0->a = 0;
        r0->d = 0;
        r0->e = 0;
        r0->f = 0;
        r0->g = 0;
        r0->h = 0;
        r0->j = 0;
        r0->k = 0;
        r0->z = 0;
        r0->b = 0;
        p = r0;
    } else
        p = 0;
    slots[count] = p;
    CSoundSequence* r = slots[count];
    ++count;
    return r;
}
} // namespace fn_001e97f0

namespace fn_f9e85a4e {

// 0x001e9860 FUN_001e9860 (73 B): equivalent/0x001e9860.cpp
// sym: ?FUN_001e9860@Owner@fn_f9e85a4e@@QAEPAUEntry@2@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 1739 inputs, branch coverage 10/10)
// FUN_001e9860 @ 0x001e9860
Entry* Owner::FUN_001e9860(int first, int second) {
    for (int i = 0; i < count; ++i) {
        Entry* entry = entries[i];
        if (entry && entry->first == first && entry->second == second)
            return entries[i];
    }
    return 0;
}


// 0x001e98b0 FUN_001e98b0 (72 B): matches/0x001e98b0.cpp
// sym: ?find@Obj_1e98b0@fn_f9e85a4e@@QAEPAXPAUKey_1e98b0@2@@Z
void* Obj_1e98b0::find(Key_1e98b0* key) {
    for (int i = 0; i < count; ++i) {
        Entry_1e98b0* e = (Entry_1e98b0*)items[i];
        if (e && e->a == key->a && e->b == key->b)
            return items[i];
    }
    return 0;
}


// 0x001e9900 FUN_001e9900 (86 B): matches/0x001e9900.cpp
// sym: ?Find@Obj_1e9900@fn_f9e85a4e@@QAEPAXPAH@Z
void* Obj_1e9900::Find(int* key) {
    int i = 0;
    if (count > 0) {
        do {
            Item_1e9900* p = items[i];
            if (p && p->pair->a == key[0] && p->pair->b == key[1])
                return items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}

} // namespace fn_f9e85a4e

// 0x001e9a90 FUN_001e9a90 (102 B): matches/0x001e9a90.cpp
// sym: ?FUN_001e9a90@ThisWrap_001e9a90@owners@@QAEXHI@Z
// data: gCurrent = DAT_004e3698
void owners::ThisWrap_001e9a90::FUN_001e9a90(hulk_intptr a, unsigned int b) {
    Obj_1e9a90* p = (Obj_1e9a90*)this->GetThing(((int)a));
    if (p && p != (*(Obj_1e9a90**)&DAT_004e3698)) {
        if ((*(Obj_1e9a90**)&DAT_004e3698))
            (*(Obj_1e9a90**)&DAT_004e3698)->Reset(b);
        if (CheckThing()) {
            int y = CheckThing();
            ApplyThing(y, p->value, (float)b);
        }
        (*(Obj_1e9a90**)&DAT_004e3698) = p;
    }
}


// 0x001e9b00 FUN_001e9b00 (27 B): matches/0x001e9b00.cpp
// sym: ?FUN_001e9b00@Obj_1e9b00@owners@@QAEXH@Z
void owners::Obj_1e9b00::FUN_001e9b00(hulk_intptr x) {
    void* p = ((ThisCall_001e9960*)(this))->FUN_001e9960(((int)x));
    if (p)
        value = p;
}

namespace fn_f9e85a4e {

// 0x001e9b20 FUN_001e9b20 (154 B): matches/0x001e9b20.cpp
// sym: ?FUN_001e9b20@Mixer@fn_f9e85a4e@@QAEXI@Z
// FUN_001e9b20 @ 0x001e9b20
// Fades the previous sound out, starts the new one at `volume`, and makes it current.
void Mixer::FUN_001e9b20(unsigned int volume)
{
    if (current == 0)
        return;
    Sound_1e9b20 *old = (*(Sound_1e9b20**)&DAT_004e3698);
    if (old != 0) {
        if (FUN_00240750() != 0) {
            void *mixer = FUN_00240750();
            FUN_002416c0(mixer, old->handle, (float)volume);
        }
    }
    Sound_1e9b20 *next = current;
    if (FUN_00240750() != 0) {
        void *mixer = FUN_00240750();
        FUN_00242f60(mixer, next->handle, (float)volume);
    }
    (*(Sound_1e9b20**)&DAT_004e3698) = current;
}


// 0x001e9bc0 FUN_001e9bc0 (42 B): matches/0x001e9bc0.cpp
// sym: _FUN_001e9bc0
// data: g_pairs = DAT_004e2788
extern "C" bool FUN_001e9bc0(int a, int b) {
    for (int i = 0; i < 28; ++i) {
        if (a == (*(Pair_1e9bc0**)&DAT_004e2788)[i].a && b == (*(Pair_1e9bc0**)&DAT_004e2788)[i].b)
            return true;
    }
    return false;
}


// 0x001e9bf0 FUN_001e9bf0 (274 B): equivalent/0x001e9bf0.cpp
// sym: ?FUN_001e9bf0@Owner_1e9bf0@fn_f9e85a4e@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 744 inputs, branch coverage 24/24)
// FUN_001e9bf0 @ 0x001e9bf0
bool Owner_1e9bf0::FUN_001e9bf0() {
 for(int i=0;i<count;++i) {
  Entry_1e9bf0* e=entries[i];
  if(e && !e->blocked10 && !e->blockedC) {
   int raw=(int)e->amount;
   float amount=raw<0 ? (double)raw+DAT_003f3f18 : (double)raw;
   float available=(*(Clock_1e9bf0**)&DAT_004e3690)->FUN_001e8730();
   e=entries[i];
   if(available<=amount) {
    int v=(int)e->amount;
    (*(float*)&DAT_004e36ac)=(v<0 ? (double)v+DAT_003f3f18 : (double)v)+(*(float*)&DAT_004e36ac);
   } else {
    ((owners::Clip_1e8d40 *)e)->FUN_001e8d40();
    while(entries[i]->state!=3) {
     FUN_002656a0();
     thunk_FUN_00270a50();
     DAT_004dd700->manager->FUN_00086280()->FUN_000bd1b0(0);
     Entry_1e9bf0* current=entries[i];
     if(current->state==1 && (*(Worker_1e9bf0**)&DAT_004e3694)->FUN_00266750()) {
      current->state=3;
      (*(Worker_1e9bf0**)&DAT_004e3694)->FUN_00263e90();
      (*(Worker_1e9bf0**)&DAT_004e3694)=0;
     }
    }
   }
  }
 }
 done=true;
 return true;
}

} // namespace fn_f9e85a4e
