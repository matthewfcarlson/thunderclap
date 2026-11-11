// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c5e20..0x001c60b0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f493c7ef {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f493c7ef {} using namespace fn_f493c7ef;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f493c7ef {
class Obj_1c5e20 {
  public:
    void Fn(hulk_intptr a);
    char pad[16];
    struct Sub_1c5e20* m;
};
struct Sub_1c5e20 {
    void Helper(int a);
};
struct Result { char pad[0x30]; };
struct Registry {
  public:
    void FUN_001c3bb0(void*, unsigned int);
    Result* FUN_001c3bd0(void* key);
};
Registry* FUN_001c3d90();
struct Obj_1c5e60 {
    char pad[8];
    Result* target();
};
struct Data_1c5e80 {
    unsigned int a, b, c;
};
struct Buffer_1c5e80 {
    char data[48];
    unsigned int a, b, c;
    char extra[4];
    void Init();
};
class Child_1c5e80 {
  public:
};
class Obj_1c5e80 {
  public:
    char pad[0x10];
    Child_1c5e80* m;
    void f(Data_1c5e80* p);
};
class Thing {
  public:
    Thing();
    int a, b, c, d;
};
typedef unsigned int u32_1c5f20;
void __cdecl thunk_FUN_00267090(u32_1c5f20);
extern "C" void* Alloc(hulk_uintptr);
extern "C" void Free(void*);
class Item_1c5fb0 {
  public:
    char pad[8];
};
class Checker_1c5fb0 {
  public:
    bool test(void*);
};
class Owner_1c5fb0 {
  public:
    char pad0[4];
    Item_1c5fb0** items;
    unsigned int count;
    hulk_intptr Find(Checker_1c5fb0*);
};
class Item_1c6000 {
  public:
    virtual void Done(int);
};
class Bag_1c6000 {
  public:
    int pad;
    Item_1c6000** items;
    unsigned int count;
    void Remove(Item_1c6000* p);
};
extern "C" char DAT_00421990[];
struct Item_1c6050 {
    char pad[0x23];
    char flag;
};
struct Holder_1c6050 {
    Item_1c6050* Find(int);
};
struct Obj_1c6050 {
    char pad[12];
    Holder_1c6050* h;
    void Poke(int a, int b);
};
struct Sub_1c6050 {
    char pad[8];
    void Init();
    void Set(int);
};
Obj_1c6050* __stdcall Make2();
Obj_1c6050* __stdcall Make0();
struct CRenderableCharacter_1c6050 {
    void* vf;
    char pad[4];
    Sub_1c6050 s;
    hulk_intptr b;
    CRenderableCharacter_1c6050* Target(int arg1, int arg2);
};


// 0x001c5e20 FUN_001c5e20 (15 B): matches/0x001c5e20.cpp
// sym: ?Fn@Obj_1c5e20@fn_f493c7ef@@QAEXH@Z
void Obj_1c5e20::Fn(hulk_intptr a) {
    if (m)
        m->Helper(a);
}

} // namespace fn_f493c7ef

// 0x001c5e40 FUN_001c5e40 (24 B): matches/0x001c5e40.cpp
// sym: ?FUN_001c5e40@Obj_1c5e40@owners@@QAEXI@Z
// FUN_001c3d90 is the 0-argument singleton getter; the two pushed values are arguments of the method call.
void owners::Obj_1c5e40::FUN_001c5e40(hulk_uintptr arg) {
    FUN_001c3d90()->FUN_001c3bb0((char*)this + 8, ((unsigned int)arg));
}

namespace fn_f493c7ef {

// 0x001c5e60 FUN_001c5e60 (17 B): matches/0x001c5e60.cpp
// sym: ?target@Obj_1c5e60@fn_f493c7ef@@QAEPAUResult@2@XZ
Result* Obj_1c5e60::target() {
    return FUN_001c3d90()->FUN_001c3bd0((char*)this + 8);
}


// 0x001c5e80 FUN_001c5e80 (66 B): matches/0x001c5e80.cpp
// sym: ?f@Obj_1c5e80@fn_f493c7ef@@QAEXPAUData_1c5e80@2@@Z
void Obj_1c5e80::f(Data_1c5e80* p) {
    if (m) {
        Buffer_1c5e80 b;
        b.Init();
        b.a = p->a;
        b.b = p->b;
        b.c = p->c;
        ((owners::X_1c4d60 *)m)->FUN_001c4d60((unsigned int *)(Buffer_1c5e80 *)(&b));
    }
}

} // namespace fn_f493c7ef

// 0x001c5ed0 FUN_001c5ed0 (31 B): matches/0x001c5ed0.cpp
// sym: ?FUN_001c5ed0@Owner_1c5ed0@owners@@QAEXPAX@Z
void owners::Owner_1c5ed0::FUN_001c5ed0(void* src) {
    int* d = target;
    if (d) {
        int* s = (int*)src;
        d[9] = s[0];
        d[10] = s[1];
        d[11] = s[2];
    }
}


// 0x001c5ef0 FUN_001c5ef0 (17 B): matches/0x001c5ef0.cpp
// sym: ?FUN_001c5ef0@Obj_1c5ef0@owners@@QAEXE@Z
void owners::Obj_1c5ef0::FUN_001c5ef0(unsigned char v) {
    if (ptr)
        *((unsigned char*)ptr + 0x21) = v;
}

namespace fn_f493c7ef {

// 0x001c5f10 FUN_001c5f10 (14 B): matches/0x001c5f10.cpp
// sym: ??0Thing@fn_f493c7ef@@QAE@XZ
Thing::Thing() : b(0), c(0), d(0) {}

} // namespace fn_f493c7ef

// 0x001c5f20 FUN_001c5f20 (11 B): matches/0x001c5f20.cpp
// sym: ?FUN_001c5f20@Target_1c5f20@owners@@QAEXXZ
void owners::Target_1c5f20::FUN_001c5f20() {
    thunk_FUN_00267090(value);
}


// 0x001c5f30 FUN_001c5f30 (117 B): matches/0x001c5f30.cpp
// sym: ?FUN_001c5f30@Thing_1c5f30@owners@@QAEXI@Z
void owners::Thing_1c5f30::FUN_001c5f30(hulk_uintptr value) {
    unsigned int* p;
    unsigned int n;
    if (count >= capacity) {
        if (capacity == 0)
            capacity = 0x32;
        capacity = capacity * 2;
        p = (unsigned int*)Alloc(capacity * 4);
        if (data != 0) {
            n = 0;
            while (n < count) {
                p[n] = data[n];
                ++n;
            }
            Free(data);
        }
        data = p;
    }
    data[count] = ((unsigned int)value);
    ++count;
}

namespace fn_f493c7ef {

// 0x001c5fb0 FUN_001c5fb0 (67 B): matches/0x001c5fb0.cpp
// sym: ?Find@Owner_1c5fb0@fn_f493c7ef@@QAEHPAVChecker_1c5fb0@2@@Z
hulk_intptr Owner_1c5fb0::Find(Checker_1c5fb0* arg) {
    unsigned int i = 0;
    if (count > 0) {
        do {
            if (arg->test((char*)items[i] + 8))
                return (hulk_intptr)items[i];
            ++i;
        } while (i < count);
    }
    return 0;
}


// 0x001c6000 FUN_001c6000 (80 B): matches/0x001c6000.cpp
// sym: ?Remove@Bag_1c6000@fn_f493c7ef@@QAEXPAVItem_1c6000@2@@Z
void Bag_1c6000::Remove(Item_1c6000* p) {
    unsigned int i = 0;
    while (i < count) {
        if (p == items[i]) {
            items[i] = items[count - 1];
            items[count] = 0;
            --count;
        }
        ++i;
    }
    if (p)
        p->Done(1);
}


// 0x001c6050 FUN_001c6050 (82 B): matches/0x001c6050.cpp
// sym: ?Target@CRenderableCharacter_1c6050@fn_f493c7ef@@QAEPAU12@HH@Z
CRenderableCharacter_1c6050* CRenderableCharacter_1c6050::Target(int arg1, int arg2) {
    vf = (void*)((hulk_intptr)DAT_00421990);
    s.Init();
    s.Set(arg1);
    Make2()->Poke(arg1, arg2);
    Obj_1c6050* p = Make0();
    Holder_1c6050* h = p->h;
    Item_1c6050* it = h->Find(arg1);
    b = (hulk_intptr)it;
    it->flag = 1;
    return this;
}

} // namespace fn_f493c7ef
