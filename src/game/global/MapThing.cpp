// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e36a0..0x000e3ac0 (kind game, layer game, confidence high), dominant class MapThing
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_ffa3e06c {
#define TREE_TU_END }
namespace fn_ffa3e06c {} using namespace fn_ffa3e06c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ffa3e06c {
struct X_e36a0 {
    X_e36a0* Target();
};
struct Label { char pad[0x24];  };
void __cdecl thunk_FUN_00267090(void* p);
struct Group {
    Label* items;
    char pad[4];
    int f8, fc;
    char pad2[4];
    int f14;
    char pad3[0x38 - 0x18];
};
class HintList {
public:
    char pad[0x154];
    int f154;
    char pad1[0x17c - 0x158];
    Group group[0x80];
    void FUN_000e36c0();
};
struct Obj_e3770 {
    char pad0[0x40];
    char pad40[4];
    unsigned int c;
    unsigned char b;
    char pad49[3];
    unsigned int d;
};
struct Owner_e3770 {
    char pad0[0x4c];
    unsigned int value4c;
    char pad50[0xf8];
    unsigned int value148;
    char pad14c[0x1d88 - 0x14c];
    Obj_e3770* volatile item;
    void Set(Obj_e3770*);
};
struct C_e37f0;
struct B_e37f0;
struct A_e37f0;
class C_e37f0 {
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual int GetResult();
};
class B_e37f0 {
  public:
    char pad[4];
    C_e37f0* c;
};
class A_e37f0 {
  public:
    char pad[8];
    B_e37f0* b;
};
class Item_e37f0 {
  public:
    int M(int a, int b);
    char pad[0x38];
};
extern "C" void f7810(int a, int b, int c);
class Obj_e37f0 {
  public:
    char pad1[0x14];
    A_e37f0* a;
    char pad2[0x154 - 0x18];
    int idx;
    Item_e37f0 items[1];
    void target(int p2, int p3);
};
class Provider {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual int get();
};
struct Middle {
    char pad[4];
    Provider* provider;
};
struct Outer {
    char pad[8];
    Middle* middle;
};
class Elem {
    char pad[0x38];

  public:
    int get(int, int);
};
extern "C" void __cdecl finish(int, int, int);
class Obj {
    char pad[0x14];
    Outer* outer;
    char pad2[0x140];
    Elem elements[1];

  public:
    void work(int, int, int);
};
struct Notifier_e3890 { void Notify(int); };
inline void Copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        ++s;
        *d = c;
        ++d;
    } while (c);
}
class Obj_e3890 {
  public:
    virtual void Fn();
    char pad4[0x14c];
    int m150;
    int m154;
    char pad158[0x1d58 - 0x158];
    int count;
    char pad1d5c[0x38];
    hulk_intptr callback;
    char pad1d98[0x11];
    char entries[0x2000];
    void Target(const char*, char);
};
struct Vec3_e3900 { float x, y, z; };
struct Entity_e3900 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void GetPosition(Vec3_e3900* out);
};
struct Registry_e3900 { Entity_e3900* FUN_001fd780(int id); };
struct Region_e3900 { char data[4]; bool FUN_0022d2b0(const Vec3_e3900* pos, unsigned tag); };
struct RegionNode { char pad[4]; Region_e3900 region; };
struct RegionList {
    int FUN_000c8180();
};
struct RegionManager {  };
struct Holder3c { char pad[8]; RegionManager* mgr; };
} // namespace fn_ffa3e06c
struct World {
    char pad0[0x28];
    Registry_e3900* registry;
    char pad2c[0x10];
    Holder3c* holder;
};
namespace fn_ffa3e06c {
class FEObject_e39b0 {
  public:
    char pad[0x118];
};


// 0x000e36a0 FUN_000e36a0 (12 B): matches/0x000e36a0.cpp
// sym: ?Target@X_e36a0@fn_ffa3e06c@@QAEPAU12@XZ
// Same code shape as 0x00034ad0 (propagated; names are from that function)
X_e36a0* X_e36a0::Target() {
    ((owners::State_f7930 *)this)->FUN_000f7930();
    return this;
}


// 0x000e36c0 FUN_000e36c0 (138 B): equivalent/0x000e36c0.cpp
// sym: ?FUN_000e36c0@HintList@fn_ffa3e06c@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 77 inputs, branch coverage 8/8)
// FUN_000e36c0 @ 0x000e36c0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void HintList::FUN_000e36c0() {
    for (int g = 0; g < 0x80; g++) {
        Group* e = &group[g];
        if (e->items) {
            int* hdr = (int*)e->items - 1;
            int n = *hdr;
            Label* p = e->items + n;
            for (int k = n; k > 0; k--) {
                p--;
                ((owners::Thing_f7960 *)p)->FUN_000f7960();
            }
            thunk_FUN_00267090(hdr);
            e->items = 0;
        }
        e->f8 = 0;
        e->fc = 0;
    }
    group[0x7f].f14 = 0;   // this+0x1d58
    f154 = 0;
}

} // namespace fn_ffa3e06c

// 0x000e3750 FUN_000e3750 (21 B): matches/0x000e3750.cpp
// sym: ?FUN_000e3750@C_e3750@owners@@QAEXPAX@Z
void owners::C_e3750::FUN_000e3750(void* x) {
    p = x;
    if (x)
        *((char*)x + 0x74) = 0;
}

namespace fn_ffa3e06c {

// 0x000e3770 FUN_000e3770 (58 B): matches/0x000e3770.cpp
// sym: ?Set@Owner_e3770@fn_ffa3e06c@@QAEXPAUObj_e3770@2@@Z
void Owner_e3770::Set(Obj_e3770* p) {
    item = p;
    if (p) {
        ((unsigned char*)p)[0x40] = 1;
        ((unsigned char*)item)[0x48] = 1;
        unsigned int a = value148;
        ((unsigned int*)(((char*)item) + 0x44))[0] = a;
        unsigned int b = value4c;
        ((unsigned int*)(((char*)item) + 0x4c))[0] = b;
    }
}


// 0x000e37f0 FUN_000e37f0 (67 B): matches/0x000e37f0.cpp
// sym: ?target@Obj_e37f0@fn_ffa3e06c@@QAEXHH@Z
void Obj_e37f0::target(int p2, int p3) {
    C_e37f0* c = a->b->c;
    int r = c->GetResult();
    f7810(items[idx].M(r, 0), p2, p3);
}


// 0x000e3840 FUN_000e3840 (65 B): matches/0x000e3840.cpp
// sym: ?work@Obj@fn_ffa3e06c@@QAEXHHH@Z
void Obj::work(int index, int a, int b) {
    int v = outer->middle->provider->get();
    finish(elements[index].get(v, 0), a, b);
}


// 0x000e3890 FUN_000e3890 (100 B): matches/0x000e3890.cpp
// sym: ?Target@Obj_e3890@fn_ffa3e06c@@QAEXPBDD@Z
void Obj_e3890::Target(const char* s, char flag) {
    if (count < 0x80) {
        Copy(entries + count * 0x40, s);
        if (flag) {
            int n = count;
            m154 = n;
            m150 = n;
            if (callback)
                ((Notifier_e3890*)callback)->Notify(n);
            Fn();
        }
        ++count;
    }
}

} // namespace fn_ffa3e06c

// 0x000e3900 MapThing::vfunc_11 (152 B): equivalent/0x000e3900.cpp
// sym: ?vfunc_11@MapThing@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// MapThing::vfunc_11 @ 0x000e3900
// Finds the region that contains the entity's position and selects it.
void MapThing::vfunc_11(int id) {
    Entity_e3900* e = DAT_004dd700->registry->FUN_001fd780(id);
    if (e == 0)
        return;
    Vec3_e3900 pos;
    e->GetPosition(&pos);
    RegionList* list = ((RegionList *)((owners::C_cae70 *)(DAT_004dd700->holder->mgr))->FUN_000cae70());
    for (int i = 0; i < list->FUN_000c8180(); i++) {
        RegionNode* n = ((RegionNode *)((owners::X_c8190 *)list)->FUN_000c8190(i));
        if (n && n->region.FUN_0022d2b0(&pos, 0x3727c5ac)) {
            vfunc_10(i);
            break;
        }
    }
}


// 0x000e39a0 MapThing::vfunc_10 (13 B): matches/0x000e39a0.cpp
// sym: ?vfunc_10@MapThing@@UAEXI@Z
void MapThing::vfunc_10(unsigned int value) {
    this->f_118 = value;
}


// 0x000e39b0 MapThing::vfunc_12 (7 B): matches/0x000e39b0.cpp
// sym: ?vfunc_12@MapThing@@UAEHXZ
int MapThing::vfunc_12() {
    return *(int*)((char*)this + 0x118);
}


// 0x000e3a90 MapThing::vfunc_14 (19 B): matches/0x000e3a90.cpp [wrapped: conflict: MapThing]
// sym: ?vfunc_14@MapThing@fn_000e3a90@@UAEHXZ
namespace fn_000e3a90 {
class MapThing {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int vfunc_13();
    virtual int vfunc_14();
};
class Helper_e3a90 {
  public:
    int go();
};
int MapThing::vfunc_14() {
    hulk_intptr x = vfunc_13();
    if (x)
        return ((Helper_e3a90*)x)->go();
    return 0;
}
} // namespace fn_000e3a90

