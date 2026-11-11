// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000f8df0..0x000f9820 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f696183f {
#define TREE_TU_END }
namespace fn_f696183f {} using namespace fn_f696183f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f696183f {
class Mgr_f8df0 {
  public:
    int Check_000dfa60(int x);
};
class Inner_f8df0 {
  public:
    int pad;
    Mgr_f8df0* mMgr;
};
struct NamedValueFloat_nv_f8df0 {
    NamedValueFloat* Init_000f8a90(Inner_f8df0* a, int b, int c, int d);
};
} // namespace fn_f696183f
void* operator new(size_t n);
namespace fn_f696183f {
class Owner_f8df0 {
  public:
    Inner_f8df0* mInner;
    NamedValueFloat* Create(int a, int b, int c);
};
class Mgr_f8e70 {
  public:
    int Check_000df9e0(int x);
};
class Inner_f8e70 {
  public:
    int pad;
    Mgr_f8e70* mMgr;
};
struct NamedValueInt_nv_f8e70 {
    NamedValueInt* Init_000f8b20(Inner_f8e70* a, int b, int c, int d);
};
class Owner_f8e70 {
  public:
    Inner_f8e70* mInner;
    NamedValueInt* Create(int a, int b, int c);
};
struct Entry { int key1; int key2; int value; int reserved; };
struct Table { int count; int unused; Entry entries[1]; int FUN_000f9140(int key1, int key2); };
typedef unsigned char u8_f92b0;
typedef unsigned int u32_f92b0;
struct Inner_f92b0 {
    char pad[0x458];
    int Find_000f9140(u32_f92b0, u32_f92b0);
};
struct Record_f92f0 {
    int a;
    int b;
    int index;
    int pad;
};
struct List_f92f0 {
    int count;
    int pad4;
    Record_f92f0 recs[64];
    int FUN_000f9140(int a, int b);
};
struct Owner_f92f0 {
    char pad0[0x458];
    List_f92f0 list;
    int size;
    char flags[1];
    int FUN_000f92f0(int a, int b, char value);
};
struct Sub_f94f0 {
    int Find_000f9140(int a, int b);
};
struct Obj_f94f0 {
    char pad[0x1248];
    Sub_f94f0 sub;
    char pad2[0x1654 - 0x1249];
    unsigned int vals[1];
    bool Get(int a, int b, unsigned int* out);
};
struct Entry_f9530 {
    int a;
    int b;
    int nextSlot;
    int pad;
};
struct Map_f9530 {
    int count;
    int pad04;
    Entry_f9530 entries[1];
    int FUN_000f9140(int a, int b);
};
struct Store {
    char pad[0x1248];
    Map_f9530 map;
    char padMap[0x1650 - 0x1248 - sizeof(Map_f9530)];
    int numValues;
    float values[1];
    void FUN_000f9530(int a, int b, float value);
};
typedef unsigned int U_f95e0;
struct D {
    U_f95e0 Fnf_002647e0(U_f95e0* out, int a, int b, int c);
};
struct C_f95e0 {
    char pad[0x284];
    D* member;
    U_f95e0 g();
};
struct Sub_f9600 {
};
struct Owner_f9600 {
    char pad[0x284];
    Sub_f9600* sub;
    hulk_intptr Fn(hulk_intptr p);
};
struct Inner_f9650 {
};
struct Obj_f9650 {
    char pad[0x284];
    Inner_f9650* p;
    void Target(hulk_intptr a, hulk_intptr b, int c);
};


// 0x000f8df0 FUN_000f8df0 (121 B): matches/0x000f8df0.cpp
// sym: ?Create@Owner_f8df0@fn_f696183f@@QAEPAVNamedValueFloat@@HHH@Z
NamedValueFloat* Owner_f8df0::Create(int a, int b, int c) {
    if (((owners::Table_f8cc0 *)this)->FUN_000f8cc0((const char *)(hulk_uintptr)(int)a))
        return 0;
    NamedValueFloat* r = 0;
    if (c && mInner->mMgr->Check_000dfa60(c)) {
        NamedValueFloat* p = (NamedValueFloat*)operator new(sizeof(NamedValueFloat));
        if (p) {
            r = ((NamedValueFloat_nv_f8df0*)(((NamedValueFloat*)(p))))->Init_000f8a90(mInner, a, b, c);
        } else {
            r = 0;
        }
        ((owners::C_f8c00 *)this)->FUN_000f8c00((hulk_intptr)(NamedValueFloat *)r);
    }
    return r;
}


// 0x000f8e70 FUN_000f8e70 (121 B): matches/0x000f8e70.cpp
// sym: ?Create@Owner_f8e70@fn_f696183f@@QAEPAVNamedValueInt@@HHH@Z
NamedValueInt* Owner_f8e70::Create(int a, int b, int c) {
    if (((owners::Table_f8cc0 *)this)->FUN_000f8cc0((const char *)(hulk_uintptr)(int)a))
        return 0;
    NamedValueInt* r = 0;
    if (c && mInner->mMgr->Check_000df9e0(c)) {
        NamedValueInt* p = (NamedValueInt*)operator new(sizeof(NamedValueInt));
        if (p) {
            r = ((NamedValueInt_nv_f8e70*)(((NamedValueInt*)(p))))->Init_000f8b20(mInner, a, b, c);
        } else {
            r = 0;
        }
        ((owners::C_f8c00 *)this)->FUN_000f8c00((hulk_intptr)(NamedValueInt *)r);
    }
    return r;
}


// 0x000f9140 FUN_000f9140 (68 B): equivalent/0x000f9140.cpp
// sym: ?FUN_000f9140@Table@fn_f696183f@@QAEHHH@Z @056ecf67ee28 @wc7a0b9094480
// STATUS: equivalent (tools/equiv.py level 3: 2341 inputs, branch coverage 8/8)
// FUN_000f9140 @ 0x000f9140
int Table::FUN_000f9140(int key1, int key2) { for (int i = 0; i < count; ++i) { if (entries[i].key1 == key1 && entries[i].key2 == key2) return entries[i].value; } return -1; }

} // namespace fn_f696183f

// 0x000f92b0 FUN_000f92b0 (54 B): matches/0x000f92b0.cpp
// sym: ?FUN_000f92b0@Obj_f92b0@owners@@QAE_NIIPAE@Z
bool owners::Obj_f92b0::FUN_000f92b0(u32_f92b0 a, u32_f92b0 b, u8_f92b0* out) {
    int i = ((Inner_f92b0*)((char*)this + 0x458))->Find_000f9140(a, b);
    if (i == -1)
        return false;
    *out = *((u8_f92b0*)this + i + 0x864);
    return true;
}

namespace fn_f696183f {

// 0x000f92f0 FUN_000f92f0 (114 B): equivalent/0x000f92f0.cpp
// sym: ?FUN_000f92f0@Owner_f92f0@fn_f696183f@@QAEHHHD@Z @d893587bc3b1 @wf943413bcdc0
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 2/2)
// FUN_000f92f0 @ 0x000f92f0
int Owner_f92f0::FUN_000f92f0(int a, int b, char value)
{
    int found = list.FUN_000f9140(a, b);
    if (found != -1) {
        flags[found] = value;
        return found;
    }
    flags[size] = value;
    int index = size;
    int n = list.count;
    list.recs[n].a = a;
    list.recs[n].b = b;
    list.recs[n].index = index;
    list.count++;
    size++;
    return size;
}


// 0x000f94f0 FUN_000f94f0 (54 B): matches/0x000f94f0.cpp
// sym: ?Get@Obj_f94f0@fn_f696183f@@QAE_NHHPAI@Z
bool Obj_f94f0::Get(int a, int b, unsigned int* out) {
    int i = sub.Find_000f9140(a, b);
    if (i == -1)
        return false;
    *out = vals[i];
    return true;
}


// 0x000f9530 FUN_000f9530 (110 B): equivalent/0x000f9530.cpp
// sym: ?FUN_000f9530@Store@fn_f696183f@@QAEXHHM@Z @09beec2292f6 @wa4e3c38d197a
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// FUN_000f9530 @ 0x000f9530
void Store::FUN_000f9530(int a, int b, float value)
{
    int idx = map.FUN_000f9140(a, b);
    if (idx != -1) {
        values[idx] = value;
        return;
    }
    values[numValues] = value;
    int slot = numValues;
    map.entries[map.count].a = a;
    map.entries[map.count].b = b;
    map.entries[map.count].nextSlot = slot;
    map.count++;
    numValues = numValues + 1;
}


// 0x000f95e0 FUN_000f95e0 (28 B): matches/0x000f95e0.cpp
// sym: ?g@C_f95e0@fn_f696183f@@QAEIXZ
U_f95e0 C_f95e0::g() {
    U_f95e0 local;
    member->Fnf_002647e0(&local, 1, 4, 1);
    return local;
}


// 0x000f9600 FUN_000f9600 (67 B): matches/0x000f9600.cpp
// sym: ?Fn@Owner_f9600@fn_f696183f@@QAEHH@Z
hulk_intptr Owner_f9600::Fn(hulk_intptr p) {
    unsigned char tmp[4];
    ((owners::X_2647e0 *)sub)->FUN_002647e0((hulk_intptr)((char*)tmp + 3), (hulk_intptr)1, 1, (hulk_intptr)1);
    unsigned int n = tmp[3];
    ((owners::X_2647e0 *)sub)->FUN_002647e0((hulk_intptr)((char*)p), (hulk_intptr)n, 1, (hulk_intptr)1);
    *((char*)p + n) = 0;
    return p;
}


// 0x000f9650 FUN_000f9650 (31 B): matches/0x000f9650.cpp
// sym: ?Target@Obj_f9650@fn_f696183f@@QAEXHHH@Z
void Obj_f9650::Target(hulk_intptr a, hulk_intptr b, int c) {
    ((owners::X_2647e0 *)p)->FUN_002647e0((hulk_intptr)a, (hulk_intptr)b, c, (hulk_intptr)1);
}

} // namespace fn_f696183f

// 0x000f9670 FUN_000f9670 (55 B): matches/0x000f9670.cpp
// sym: ?FUN_000f9670@Table_f9670@owners@@QAEHHH@Z
hulk_intptr owners::Table_f9670::FUN_000f9670(int a, int b) {
    int i = 0;
    do {
        int x = ((int*)this)[i * 4];
        int y = ((int*)this)[i * 4 + 1];
        if (a == x && b == y)
            return ((int*)this)[i * 4 + 2];
        ++i;
    } while (i < 128);
    return 0;
}


// 0x000f96b0 FUN_000f96b0 (54 B): matches/0x000f96b0.cpp [wrapped: conflict: Entry]
// sym: ?put@Pool@fn_000f96b0@@QAEPAHHH@Z
namespace fn_000f96b0 {
struct Entry {
    volatile int a;
    int b;
    int pad[2];
};
class Pool {
  public:
    Entry entries[128];
    int* put(int a, int b);
};
int* Pool::put(int a, int b) {
    for (int i = 0; i < 128; i++) {
        if (!(entries[i].a | entries[i].b)) {
            entries[i].a = a;
            entries[i].b = b;
            return (int*)&entries[i].pad[0];
        }
    }
    return 0;
}
} // namespace fn_000f96b0


// 0x000f9700 FUN_000f9700 (22 B): matches/0x000f9700.cpp
// sym: ?FUN_000f9700@X_f9700@owners@@QAEXH@Z
void owners::X_f9700::FUN_000f9700(int x) {
    if (count < 4) {
        ++count;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + count * 4) = x;
    }
}


// 0x000f9720 FUN_000f9720 (18 B): matches/0x000f9720.cpp
// sym: ?FUN_000f9720@Stack_f9720@owners@@QAEHXZ
int owners::Stack_f9720::FUN_000f9720() {
    int n = count;
    if (n <= 0)
        return 0;
    int v = ((int*)this)[n];
    count = n - 1;
    return v;
}

