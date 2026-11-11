// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00106170..0x00106550 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f6c21f8f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f6c21f8f {} using namespace fn_f6c21f8f;
#include "game/hulkfight.h"

// ---- declarations shared by the functions below
namespace fn_f6c21f8f {
class C_1061a0 {
  public:
    char pad0[0x10];
    char* data;
    int count;
    void f(int index, int a, float b, float c, int d, float e, float f);
};
struct Key {
    char pad[8];
    unsigned __int64 key;
};
struct Obj {
    char pad[8];
    int count;
    Key** items;
    Key* find(const char* name);
};
extern "C" unsigned __int64 __cdecl FUN_0027afb0(const char* name);
struct Entry { char pad[8]; int first; int second; };
struct Search { char pad[8]; int count; Entry **entries; int FUN_00106290(int first, int second); };
struct Entry_1062d0 {
    virtual void AddRef();
    char pad04[4];
    int a;
    int b;
};
class EntrySet {
public:
    char pad00[4];
    int capacity;
    int count;
    Entry_1062d0 **items;
    int Add(Entry_1062d0 *item);
};
} // namespace fn_f6c21f8f
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memmove(void*, const void*, unsigned int);
#endif
namespace fn_f6c21f8f {
class Item_106360 {
  public:
    virtual void f();
    virtual void Release();
};
class Container_106360 {
  public:
    char pad0[8];
    int count;
    Item_106360** items;
    bool Remove(int index);
};
class Item_1063b0 {
  public:
    virtual void A();
    virtual void B();
};
class Container_1063b0 {
  public:
    char pad[8];
    int count;
    Item_1063b0** items;
    bool Clear();
};
class Item_106400 {
  public:
    virtual void F0();
    virtual void F1();
};
class Container_106400 {
  public:
    char pad0[8];
    int count;
    Item_106400** items;
    void Clear();
};
struct physics_CollisionRay_106430 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(hulk_intptr a, hulk_intptr b);
    virtual void vfunc_6();
};
struct Vec3_106440 { float x, y, z; };
struct Path_106440 {
    char pad0[0x14];
    int count;
    char loops;
    void FUN_00106170(int idx, Vec3_106440 pos);
    void FUN_001061a0(int from, int to, int a, int b, int c, int d, float e);
};
struct ThisWrap_00106440 {
    Path_106440* FUN_00106230(int id);
    bool FUN_00106440(int id, int idx, Vec3_106440 pos);
};
extern "C" void* FUN_0008d6d0(hulk_uintptr);
extern int hulk_at_0040d564;
class CPatrolPath : public Entity_0027b070 {
  public:
    hulk_intptr vt;
    char pad4[12];
    void* mData;
    int mCount;
    char pad18[4];
    CPatrolPath(int count);
};

} // namespace fn_f6c21f8f

// 0x00106170 FUN_00106170 (48 B): matches/0x00106170.cpp
// sym: ?FUN_00106170@C_106170@owners@@QAE_NHHHH@Z
bool owners::C_106170::FUN_00106170(int index, int a, int b, int c) {
    if (index < count) {
        int* p = (int*)((char*)items + index * 0x24);
        p[0] = a;
        p[1] = b;
        p[2] = c;
        return true;
    }
    return false;
}

namespace fn_f6c21f8f {

// 0x001061a0 FUN_001061a0 (86 B): matches/0x001061a0.cpp
// sym: ?f@C_1061a0@fn_f6c21f8f@@QAEXHHMMHMM@Z
void C_1061a0::f(int index, int a, float b, float c, int d, float e, float f) {
    if (index < count) {
        int off = index * 36;
        *(int*)(data + off + 12) = a;
        *(float*)(data + off + 20) = b;
        *(float*)(data + off + 24) = c;
        *(int*)(data + off + 32) = d;
        *(float*)(data + off + 28) = e;
        *(float*)(data + off + 16) = f;
    }
}

} // namespace fn_f6c21f8f

// 0x00106210 FUN_00106210 (27 B): matches/0x00106210.cpp
// sym: ?FUN_00106210@C_106210@owners@@QAEHH@Z
hulk_intptr owners::C_106210::FUN_00106210(int index) {
    if (index >= 0 && index < count)
        return values[index];
    return 0;
}

namespace fn_f6c21f8f {

// 0x00106230 FUN_00106230 (84 B): matches/0x00106230.cpp
// sym: ?find@Obj@fn_f6c21f8f@@QAEPAUKey@2@PBD@Z
// the entry whose key is the name's hash key (0x0027afb0)
Key* Obj::find(const char* name) {
    unsigned __int64 k = FUN_0027afb0(name);
    for (int i = 0; i < count; ++i) {
        Key* p = items[i];
        if (p->key == k)
            return items[i];
    }
    return 0;
}


// 0x00106290 FUN_00106290 (58 B): equivalent/0x00106290.cpp
// sym: ?FUN_00106290@Search@fn_f6c21f8f@@QAEHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 1569 inputs, branch coverage 8/8)
// FUN_00106290 @ 0x00106290
int Search::FUN_00106290(int first, int second) { for (int i = 0; i < count; ++i) { Entry *entry = entries[i]; if (entry->first == first && entry->second == second) return i; } return -1; }


// 0x001062d0 FUN_001062d0 (132 B): equivalent/0x001062d0.cpp
// sym: ?Add@EntrySet@fn_f6c21f8f@@QAEHPAUEntry_1062d0@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 681 inputs, branch coverage 11/12, incomplete)
// FUN_001062d0 @ 0x001062d0
int EntrySet::Add(Entry_1062d0 *item)
{
    int n = count;
    if (n >= capacity)
        return -1;
    int a = item->a;
    if (n > 0) {
        int i = 0;
        Entry_1062d0 **p = items;
        do {
            Entry_1062d0 *e = *p;
            if (e->a == a && e->b == item->b)
                return -1;
            i++;
            p++;
        } while (i < count);
    }
    items[n] = item;
    items[n]->AddRef();
    count++;
    return n;
}


// 0x00106360 FUN_00106360 (74 B): matches/0x00106360.cpp
// sym: ?Remove@Container_106360@fn_f6c21f8f@@QAE_NH@Z
bool Container_106360::Remove(int index) {
    if (index < 0 || index >= count)
        return false;
    items[index]->Release();
    --count;
    memmove(&items[index], &items[index + 1], (count - index) * 4);
    return true;
}


// 0x001063b0 FUN_001063b0 (42 B): matches/0x001063b0.cpp
// sym: ?Clear@Container_1063b0@fn_f6c21f8f@@QAE_NXZ
bool Container_1063b0::Clear() {
    int i = count;
    while (--i >= 0)
        items[i]->B();
    count = 0;
    return true;
}


// 0x001063e0 FUN_001063e0 (1 B): matches/0x001063e0.cpp
// sym: ?FUN_001063e0@fn_f6c21f8f@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001063e0() {}


// 0x001063f0 FUN_001063f0 (1 B): matches/0x001063f0.cpp
// sym: ?FUN_001063f0@fn_f6c21f8f@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001063f0() {}


// 0x00106400 FUN_00106400 (40 B): matches/0x00106400.cpp
// sym: ?Clear@Container_106400@fn_f6c21f8f@@QAEXXZ
void Container_106400::Clear() {
    int i = count;
    while (--i >= 0)
        items[i]->F1();
    count = 0;
}


// 0x00106430 FUN_00106430 (3 B): matches/0x00106430.cpp
// sym: ?vfunc_5@physics_CollisionRay_106430@fn_f6c21f8f@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics_CollisionRay_106430::vfunc_5(hulk_intptr a, hulk_intptr b) {}


// 0x00106440 FUN_00106440 (152 B): equivalent/0x00106440.cpp
// sym: ?FUN_00106440@ThisWrap_00106440@fn_f6c21f8f@@QAE_NHHUVec3_106440@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 10/10)
// FUN_00106440 @ 0x00106440
bool ThisWrap_00106440::FUN_00106440(int id, int idx, Vec3_106440 pos) {
    Path_106440* p = this->FUN_00106230(id);
    if (p == 0)
        return false;
    int n = p->count;
    if (idx < 0 || idx >= n)
        return false;
    p->FUN_00106170(idx, pos);
    int next;
    if (idx == n - 1)
        next = p->loops ? 0 : -1;
    else
        next = idx + 1;
    p->FUN_001061a0(idx, next, 0, 0, 0, 0, 0.5f);
    return true;
}


// 0x00106510 FUN_00106510 (51 B): matches/0x00106510.cpp
// sym: ??0CPatrolPath@fn_f6c21f8f@@QAE@H@Z
CPatrolPath::CPatrolPath(int count) : Entity_0027b070() {
    unsigned int size = count * 0x24;
    vt = (hulk_intptr)&hulk_at_0040d564;
    *(char*)((char*)this + 0x18) = 0;
    mData = FUN_0008d6d0(size);
    mCount = count;
}

} // namespace fn_f6c21f8f
