// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00266690..0x00266900 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/scenegraph.h"
#include "gen/content.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4a58842 {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f4a58842 {} using namespace fn_f4a58842;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f4a58842 {
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042aee4[];
class Ref_266690 {
  public:
    virtual void A();
    virtual void Release();
};
struct Obj_2666d0 {
    char pad[0x20];
};
struct Obj_2666f0 {
    char pad[0x20];
};
struct X_266710 {
    char pad[0x14];
    unsigned value;
};
class C_266750 {
  public:
    char pad[0x14];
    int x;
};
class Thing_266760 {
    char pad[0x14];

  public:
    int state;
    void Wait();
};
void thunk_002696a0();
void step_002656a0();
class Sub_266790 {
  public:
    int Fnf_00263fc0();
    int Fng_00263fb0();
};
class Obj_266790 {
    char pad0[0x14];
    int mode;
    char pad18[4];
    Sub_266790* sub;

  public:
    hulk_freg run();
};
extern const float zero_266790;
extern const float fix;
class Item_266820 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_266820 {
    char pad[0x18];

  public:
    Item_266820* item;
    void Set(Item_266820* p);
};
struct Ref_266850 {
    virtual void A();
    virtual void B();
};
struct Owner_266850 {
    char pad[0x1c];
    Ref_266850* member;
    void Set(Ref_266850*);
};

} // namespace fn_f4a58842

// 0x00266690 FUN_00266690 (56 B): matches/0x00266690.cpp
// sym: ?FUN_00266690@LoadRequest@content@@QAEXXZ
void content::LoadRequest::FUN_00266690() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042aee4);
    if ((*(Ref_266690 * *)&this->f_18))
        (*(Ref_266690 * *)&this->f_18)->Release();
    if ((*(Ref_266690 * *)&this->f_124))
        (*(Ref_266690 * *)&this->f_124)->Release();
    if ((*(Ref_266690 * *)&this->f_1c))
        (*(Ref_266690 * *)&this->f_1c)->Release();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
}

namespace fn_f4a58842 {

// 0x002666d0 FUN_002666d0 (4 B): matches/0x002666d0.cpp
// sym: ?FUN_002666d0@fn_f4a58842@@YIPAXPAUObj_2666d0@1@@Z
// Same code shape as 0x000897e0 (propagated; names are from that function)
void* __fastcall FUN_002666d0(Obj_2666d0* p) {
    return (char*)p + 0x20;
}

} // namespace fn_f4a58842

// 0x002666e0 FUN_002666e0 (8 B): matches/0x002666e0.cpp
// sym: ?FUN_002666e0@C_2666e0@owners@@QAEXXZ
void owners::C_2666e0::FUN_002666e0() {
    value = 4;
}

namespace fn_f4a58842 {

// 0x002666f0 FUN_002666f0 (4 B): matches/0x002666f0.cpp
// sym: @FUN_002666f0@4
// Same code shape as 0x000897e0 (propagated; names are from that function)
extern "C" void* __fastcall FUN_002666f0(Obj_2666f0* p) {
    return (char*)p + 0x20;
}


// 0x00266700 FUN_00266700 (4 B): matches/0x00266700.cpp
// sym: ?FUN_00266700@fn_f4a58842@@YIHH@Z
// Same code shape as 0x00059a40 (propagated; names are from that function)
int __fastcall FUN_00266700(hulk_intptr object) {
    return *(int*)(object + 0x18);
}


// 0x00266710 FUN_00266710 (4 B): matches/0x00266710.cpp
// sym: ?target@fn_f4a58842@@YIIPAUX_266710@1@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
unsigned __fastcall target(X_266710* self) {
    return self->value;
}


// 0x00266750 FUN_00266750 (12 B): matches/0x00266750.cpp
// sym: ?target@fn_f4a58842@@YI_NPAVC_266750@1@@Z
bool __fastcall target(C_266750* self) {
    return self->x == 3;
}


// 0x00266760 FUN_00266760 (34 B): matches/0x00266760.cpp
// sym: ?Wait@Thing_266760@fn_f4a58842@@QAEXXZ
void Thing_266760::Wait() {
    while (state != 3) {
        thunk_002696a0();
        step_002656a0();
    }
}


// 0x00266790 FUN_00266790 (108 B): matches/0x00266790.cpp
// sym: ?run@Obj_266790@fn_f4a58842@@QAEMXZ
// data: one = DAT_004c9f38
hulk_freg Obj_266790::run() {
    switch (mode) {
    case 3:
        return 1.0f;
    case 2:
        if (sub) {
            // x87: the original stores f() as a float (rounded) and divides it by g() unrounded. A float local, not a
            // cast: clang's x87 code leaves `(float)` of an unsigned unrounded in the register
            float n = (float)(unsigned int)sub->Fnf_00263fc0();
            return n / (hulk_freg)(unsigned int)sub->Fng_00263fb0();
        }
        return 0.0f;
    default:
        return 0.0f;
    }
}

} // namespace fn_f4a58842

// 0x00266800 FUN_00266800 (29 B): matches/0x00266800.cpp
// sym: ?FUN_00266800@C_266800@owners@@QAEXPAD@Z
void owners::C_266800::FUN_00266800(char* p) {
    if (p)
        strncpy((char*)this + 0x20, p, 0xff);
}

namespace fn_f4a58842 {

// 0x00266820 FUN_00266820 (38 B): matches/0x00266820.cpp
// sym: ?Set@Owner_266820@fn_f4a58842@@QAEXPAVItem_266820@2@@Z
// Same code shape as 0x00059d00 (propagated; names are from that function)
void Owner_266820::Set(Item_266820* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x00266850 FUN_00266850 (38 B): matches/0x00266850.cpp
// sym: ?Set@Owner_266850@fn_f4a58842@@QAEXPAURef_266850@2@@Z
void Owner_266850::Set(Ref_266850* p) {
    if (p)
        p->A();
    if (member)
        member->B();
    member = p;
}

} // namespace fn_f4a58842

// 0x00266880 FUN_00266880 (4 B): matches/0x00266880.cpp
// sym: ?FUN_00266880@PartitionDriver_266880@owners@@QAEHXZ
// Same code shape as 0x00222300 (propagated; names are from that function)
hulk_intptr owners::PartitionDriver_266880::FUN_00266880() {
    return *(int*)((char*)this + 0x1c);
}


// 0x00266890 FUN_00266890 (104 B): matches/0x00266890.cpp [wrapped: helper definitions (3 out-of-line function bodies)]
// sym: ??0LoadRequest@fn_00266890@@QAE@PBUData_266890@1@@Z
namespace fn_00266890 {
extern "C" int FUN_00267f80();
struct Obj_266890 {
    virtual void V();
};
struct Data_266890 {
    char c;
    char pad[0xff];
    hulk_intptr a, b, d;
    char e;
    char pad2[3];
};
class Base_266890 {
  public:
    virtual void W();
    Base_266890() { a1 = 0; }
    int a1;
};
void Base_266890::W() {}
class LoadRequest : public Base_266890 {
  public:
    virtual void W();
    LoadRequest(const Data_266890*);
    int a2;
    int a3, a4, a5, a6, a7;
    Data_266890 d;
};
void LoadRequest::W() {}
LoadRequest::LoadRequest(const Data_266890* src) {
    Data_266890* p = &d;
    p->c = 0;
    p->a = 0;
    p->b = 0;
    p->d = 0;
    p->e = 0;
    *p = *src;
    a2 = FUN_00267f80();
    a3 = 0;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
    Obj_266890* o = (Obj_266890*)d.b;
    if (o)
        o->V();
}
} // namespace fn_00266890

