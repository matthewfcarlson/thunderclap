// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00048680..0x00049140 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f92e4dc5 {
#define TREE_TU_END }
namespace fn_f92e4dc5 {} using namespace fn_f92e4dc5;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f92e4dc5 {
extern int* hulk_at_004dc410;
class CCondition_486a0 {
  public:
    virtual int vfunc_0(int);
};
extern "C" char DAT_003f6d50[];
class Obj_486e0 {
  public:
    void* vptr;
    void BaseF_002345b0();
};
extern int* hulk_at_004dc418;
class CCondition_48710 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc420;
class CCondition_48780 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc428;
class CCondition_488b0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc430;
class CCondition_48930 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc438;
class CCondition_489b0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc440;
class CCondition_48a20 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc448;
class CCondition_48a90 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc450;
class CCondition_48b60 {
  public:
    virtual int vfunc_0(int);
};
struct Target_48bb0 { char pad[0x74]; int value; };
struct Ctx_48bb0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual Target_48bb0* GetTarget(); };
extern int* hulk_at_004dc458;
class CCondition_48c70 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc460;
class CCondition_48ce0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc468;
class CCondition_48d50 {
  public:
    virtual int vfunc_0(int);
};
struct Obj_48db0 {
    char _pad[0x2098];
    int f1;
    int f2;
};
struct Stage_48db0 {
    Obj_48db0* Get_00059a30();
};
struct Lookup_48db0 {
};
extern int* hulk_at_004dc470;
class CCondition_48e80 {
  public:
    virtual int vfunc_0(int);
};
class Result_48ec0 {
    char pad[0x24];

  public:
    unsigned char value;
};
class Input_48ec0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Result_48ec0* f3();
};
extern int* hulk_at_004dc478;
class CCondition_48f10 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc480;
class CCondition_48f80 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc488;
class CCondition_48ff0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc490;
class CCondition_49060 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004dc498;
class CCondition_490d0 {
  public:
    virtual int vfunc_0(int);
};


// 0x00048680 FUN_00048680 (19 B): matches/0x00048680.cpp
// sym: ?FUN_00048680@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048680() {
    FUN_00234810(((char*)&DAT_004dc410), ((char*)&DAT_004dc414));
}

} // namespace fn_f92e4dc5

// 0x000486a0 CAxisTimeCondition::vfunc_0 (16 B): matches/0x000486a0.cpp
// sym: ?vfunc_0@CAxisTimeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAxisTimeCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc410;
    return p[index];
}


// 0x000486b0 FUN_000486b0 (41 B): matches/0x000486b0.cpp [wrapped: conflict: CAxisTimeCondition]
// sym: ??0CAxisTimeCondition@fn_000486b0@@QAE@XZ
namespace fn_000486b0 {
extern "C" char DAT_003f6e4c[];
struct CAxisTimeCondition {
    void* vtable;
    int pad0[2];
    int fieldC;
    int field10;
    int field14;
    CAxisTimeCondition();
};
struct ThisCall_00234590 {
    void Init_00234590(int);
};
CAxisTimeCondition::CAxisTimeCondition() {
    ((ThisCall_00234590*)(this))->Init_00234590(0);
    fieldC = 0;
    vtable = (void*)((hulk_intptr)DAT_003f6e4c);
    field10 = 4;
    field14 = 0;
}
} // namespace fn_000486b0

namespace fn_f92e4dc5 {

// 0x000486e0 FUN_000486e0 (11 B): matches/0x000486e0.cpp
// sym: ?FUN_000486e0@fn_f92e4dc5@@YIXPAVObj_486e0@1@@Z
void __fastcall FUN_000486e0(Obj_486e0* p) {
    p->vptr = (void*)DAT_003f6d50;
    _ReadWriteBarrier();
    p->BaseF_002345b0();
}


// 0x000486f0 FUN_000486f0 (19 B): matches/0x000486f0.cpp
// sym: ?FUN_000486f0@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000486f0() {
    FUN_00234810(((char*)&DAT_004dc418), ((char*)&DAT_004dc41c));
}

} // namespace fn_f92e4dc5

// 0x00048710 CAxisSpeedCondition::vfunc_0 (16 B): matches/0x00048710.cpp
// sym: ?vfunc_0@CAxisSpeedCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAxisSpeedCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc418;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048760 FUN_00048760 (19 B): matches/0x00048760.cpp
// sym: ?FUN_00048760@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048760() {
    FUN_00234810(((char*)&DAT_004dc420), ((char*)&DAT_004dc424));
}

} // namespace fn_f92e4dc5

// 0x00048780 CAxisValueCondition::vfunc_0 (16 B): matches/0x00048780.cpp
// sym: ?vfunc_0@CAxisValueCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAxisValueCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc420;
    return p[index];
}


// 0x00048790 FUN_00048790 (52 B): matches/0x00048790.cpp [wrapped: conflict: CButtonValueCondition]
// sym: ?FUN_00048790@fn_00048790@@YIPAVCButtonValueCondition@1@PAV21@@Z
namespace fn_00048790 {
// Same code shape as 0x00048520 (propagated; names are from that function)
extern int hulk_at_003f6ea8;
class CButtonValueCondition {
  public:
    hulk_intptr vf;
    int x1;
    int x2;
    int x3;
    int x4;
    int x5;
    int x6;
    int x7;
};
struct ThisCall_00234590 {
    void FUN_00234590(int);
};
CButtonValueCondition* __fastcall FUN_00048790(CButtonValueCondition* self) {
    ((ThisCall_00234590*)(self))->FUN_00234590(0);
    self->x4 = 4;
    self->x6 = 4;
    self->x3 = 0;
    self->x5 = 0;
    self->vf = (hulk_intptr)&hulk_at_003f6ea8;
    self->x7 = 0;
    return self;
}
} // namespace fn_00048790


// 0x000487e0 CAxisPressCondition::vfunc_10 (17 B): matches/0x000487e0.cpp
// sym: ?vfunc_10@CAxisPressCondition@@UAE_NPAXH@Z
// Same code shape as 0x00048570 (propagated; names are from that function)
bool CAxisPressCondition::vfunc_10(void* __p0, hulk_intptr unused) { int * param = (int *)__p0;

    return *param == 1;
}


// 0x00048800 CAxisDownCondition::vfunc_10 (46 B): matches/0x00048800.cpp
// sym: ?vfunc_10@CAxisDownCondition@@UAE_NPAXH@Z
// Same code shape as 0x00048590 (propagated; names are from that function)
bool CAxisDownCondition::vfunc_10(void* __p0, hulk_intptr __p1) { int * p = (int *)__p0; int * out = (int *)__p1;

    switch (*p) {
    case 1:
        *out = 0;
        return true;
    case 2:
        *out = p[1];
        return true;
    default:
        return false;
    }
}


// 0x00048830 CAxisReleaseCondition::vfunc_10 (17 B): matches/0x00048830.cpp
// sym: ?vfunc_10@CAxisReleaseCondition@@UAE_NPAXH@Z
// Same code shape as 0x000485c0 (propagated; names are from that function)
bool CAxisReleaseCondition::vfunc_10(void* __p0, hulk_intptr unused) { int * param = (int *)__p0;

    return *param == 3;
}


// 0x00048850 CAxisUpCondition::vfunc_10 (49 B): matches/0x00048850.cpp
// sym: ?vfunc_10@CAxisUpCondition@@UAE_NPAXH@Z
// Same code shape as 0x000485e0 (propagated; names are from that function)
bool CAxisUpCondition::vfunc_10(void* __p0, hulk_intptr __p1) { int * p = (int *)__p0; int * out = (int *)__p1;

    int n = *p;
    if (n != 0) {
        if (n != 3)
            return (bool)(false);
        *out = 0;
    } else {
        *out = p[1];
    }
    return (bool)(true);
}

namespace fn_f92e4dc5 {

// 0x00048890 FUN_00048890 (19 B): matches/0x00048890.cpp
// sym: ?FUN_00048890@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048890() {
    FUN_00234810(((char*)&DAT_004dc428), ((char*)&DAT_004dc42c));
}

} // namespace fn_f92e4dc5

// 0x000488b0 CAxisArcCondition::vfunc_0 (16 B): matches/0x000488b0.cpp
// sym: ?vfunc_0@CAxisArcCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAxisArcCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc428;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048910 FUN_00048910 (19 B): matches/0x00048910.cpp
// sym: ?FUN_00048910@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048910() {
    FUN_00234810(((char*)&DAT_004dc430), ((char*)&DAT_004dc434));
}

} // namespace fn_f92e4dc5

// 0x00048930 CAxisDoubleTapCondition::vfunc_0 (16 B): matches/0x00048930.cpp
// sym: ?vfunc_0@CAxisDoubleTapCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAxisDoubleTapCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc430;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048990 FUN_00048990 (19 B): matches/0x00048990.cpp
// sym: ?FUN_00048990@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048990() {
    FUN_00234810(((char*)&DAT_004dc438), ((char*)&DAT_004dc43c));
}

} // namespace fn_f92e4dc5

// 0x000489b0 CAxisDirectionCondition::vfunc_0 (16 B): matches/0x000489b0.cpp
// sym: ?vfunc_0@CAxisDirectionCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CAxisDirectionCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc438;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048a00 FUN_00048a00 (19 B): matches/0x00048a00.cpp
// sym: ?FUN_00048a00@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048a00() {
    FUN_00234810(((char*)&DAT_004dc440), ((char*)&DAT_004dc444));
}

} // namespace fn_f92e4dc5

// 0x00048a20 CGroundDistanceCondition::vfunc_0 (16 B): matches/0x00048a20.cpp
// sym: ?vfunc_0@CGroundDistanceCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CGroundDistanceCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc440;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048a70 FUN_00048a70 (19 B): matches/0x00048a70.cpp
// sym: ?FUN_00048a70@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048a70() {
    FUN_00234810(((char*)&DAT_004dc448), ((char*)&DAT_004dc44c));
}

} // namespace fn_f92e4dc5

// 0x00048a90 CCharacterSizeCondition::vfunc_0 (16 B): matches/0x00048a90.cpp
// sym: ?vfunc_0@CCharacterSizeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCharacterSizeCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc448;
    return p[index];
}


// 0x00048ae0 CCharacterSizeCondition::vfunc_7 (81 B): equivalent/0x00048ae0.cpp [wrapped: conflict: CCharacterSizeCondition]
// sym: ?vfunc_7@CCharacterSizeCondition@fn_00048ae0@@QAEIPAUInput@2@@Z
namespace fn_00048ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 10/10)
// CCharacterSizeCondition::vfunc_7 @ 0x00048ae0
struct Character { char pad[0x14]; unsigned int size; };
struct Actor { char pad[0x11c]; Character* character; };
struct Context { Actor* FUN_00059a30(); };
struct Input { Context* FUN_000592a0(); };
class CCharacterSizeCondition {
public:
 char pad[0xc];
 int comparison;
 unsigned int size;
 unsigned int vfunc_7(Input* arg);
};
unsigned int CCharacterSizeCondition::vfunc_7(Input* arg) {
 Context* context = arg->FUN_000592a0();
 Actor* actor = context->FUN_00059a30();
 Character* character = actor->character;
 if (!character) return 0;
 unsigned int value = character->size;
 unsigned int result = 0;
 if (comparison == 0) result = value == size;
 else if (comparison == 1) result = value != size;
 return (value & 0xffffff00U) | result;
}
} // namespace fn_00048ae0

namespace fn_f92e4dc5 {

// 0x00048b40 FUN_00048b40 (19 B): matches/0x00048b40.cpp
// sym: ?FUN_00048b40@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048b40() {
    FUN_00234810(((char*)&DAT_004dc450), ((char*)&DAT_004dc454));
}

} // namespace fn_f92e4dc5

// 0x00048b60 CCollisionHitLocationCondition::vfunc_0 (16 B): matches/0x00048b60.cpp
// sym: ?vfunc_0@CCollisionHitLocationCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionHitLocationCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc450;
    return p[index];
}


// 0x00048bb0 CCollisionHitLocationCondition::vfunc_7 (136 B): equivalent/0x00048bb0.cpp
// sym: ?vfunc_7@CCollisionHitLocationCondition@@UAE_NPAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// CCollisionHitLocationCondition::vfunc_7 @ 0x00048bb0
bool CCollisionHitLocationCondition::vfunc_7(void* __p0) { Ctx_48bb0 * ctx = (Ctx_48bb0 *)__p0;

 Target_48bb0* t = ctx->GetTarget();
 if (t) {
  int v = t->value;
  switch ((*(unsigned int *)&this->f_0c)) {
  case 0: return v < this->f_10;
  case 1: return v <= this->f_10;
  case 2: return v == this->f_10;
  case 3: return v != this->f_10;
  case 4: return v >= this->f_10;
  case 5: return v > this->f_10;
  }
 }
 return false;
}

namespace fn_f92e4dc5 {

// 0x00048c50 FUN_00048c50 (19 B): matches/0x00048c50.cpp
// sym: ?FUN_00048c50@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048c50() {
    FUN_00234810(((char*)&DAT_004dc458), ((char*)&DAT_004dc45c));
}

} // namespace fn_f92e4dc5

// 0x00048c70 CCollisionDirectionCondition::vfunc_0 (16 B): matches/0x00048c70.cpp
// sym: ?vfunc_0@CCollisionDirectionCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionDirectionCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc458;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048cc0 FUN_00048cc0 (19 B): matches/0x00048cc0.cpp
// sym: ?FUN_00048cc0@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048cc0() {
    FUN_00234810(((char*)&DAT_004dc460), ((char*)&DAT_004dc464));
}

} // namespace fn_f92e4dc5

// 0x00048ce0 CCollisionPushbackDirectionCondition::vfunc_0 (16 B): matches/0x00048ce0.cpp
// sym: ?vfunc_0@CCollisionPushbackDirectionCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionPushbackDirectionCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc460;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048d30 FUN_00048d30 (19 B): matches/0x00048d30.cpp
// sym: ?FUN_00048d30@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048d30() {
    FUN_00234810(((char*)&DAT_004dc468), ((char*)&DAT_004dc46c));
}

} // namespace fn_f92e4dc5

// 0x00048d50 CNameFlagConditionBase::vfunc_0 (16 B): matches/0x00048d50.cpp
// sym: ?vfunc_0@CNameFlagConditionBase@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CNameFlagConditionBase::vfunc_0(int index) {
    int* p = hulk_at_004dc468;
    return p[index];
}


// 0x00048d60 FUN_00048d60 (35 B): matches/0x00048d60.cpp [wrapped: conflict: CNameFlagConditionBase]
// sym: ??0CNameFlagConditionBase@fn_00048d60@@QAE@XZ
namespace fn_00048d60 {
extern "C" char DAT_003f7010[];
class Sub_48d60 {
  public:
    void Init_0027af00();
};
class CNameFlagConditionBase {
  public:
    hulk_intptr m0;
    char pad[8];
    int mC;
    Sub_48d60 sub;
    CNameFlagConditionBase();
};
struct ThisCall_00234590 {
    void FUN_00234590(int);
};
CNameFlagConditionBase::CNameFlagConditionBase() {
    ((ThisCall_00234590*)(this))->FUN_00234590(0);
    m0 = ((hulk_intptr)DAT_003f7010);
    mC = 0;
    sub.Init_0027af00();
}
} // namespace fn_00048d60


// 0x00048d90 FUN_00048d90 (31 B): matches/0x00048d90.cpp [wrapped: conflict: CCondition]
// sym: ?Run@CNameFlagConditionBase_48d90@fn_00048d90@@QAEXXZ
namespace fn_00048d90 {
// Same code shape as 0x0004a030 (propagated; names are from that function)
extern int hulk_at_003f7010;
extern int hulk_at_003f6d50;
class Part_48d90 {
  public:
    void Init_0027af50();
};
class CCondition {
  public:
    virtual void F();
};
class CNameFlagConditionBase_48d90 : public CCondition {
  public:
    char pad[12];
    Part_48d90 part;
    void Run();
    void Finish_002345b0();
};
void CNameFlagConditionBase_48d90::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f7010;
    part.Init_0027af50();
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f6d50;
    Finish_002345b0();
}
} // namespace fn_00048d90


// 0x00048db0 CNameFlagCondition::vfunc_7 (95 B): matches/0x00048db0.cpp
// sym: ?vfunc_7@CNameFlagCondition@@UAE_NPAX@Z
bool CNameFlagCondition::vfunc_7(void* __p0) { hulk_intptr arg = (hulk_intptr)__p0;

    Obj_48db0* obj = ((Stage_48db0 *)((owners::Object_592a0 *)(((Lookup_48db0*)arg)))->FUN_000592a0())->Get_00059a30();
    switch (this->f_0c) {
    case 1:
        return (this->f_10 != obj->f1 || this->f_14 != obj->f2);
    case 0:
        return (this->f_10 == obj->f1 && this->f_14 == obj->f2);
    }
    return false;
}


// 0x00048e10 CCollisionFlagCondition::vfunc_7 (78 B): equivalent/0x00048e10.cpp [wrapped: conflict: CCollisionFlagCondition]
// sym: ?vfunc_7@CCollisionFlagCondition@fn_00048e10@@QAEIPAUCollisionContext@2@@Z
namespace fn_00048e10 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 14/14)
// CCollisionFlagCondition::vfunc_7 @ 0x00048e10
struct CollisionFlags { int name; int flags; };
struct CollisionContext {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual CollisionFlags* vfunc_3();
};
struct CCollisionFlagCondition {
    void* vtable;
    char pad[8];
    int mode;
    int name;
    int flags;
    unsigned int vfunc_7(CollisionContext* context);
};
unsigned int CCollisionFlagCondition::vfunc_7(CollisionContext* context) {
    CollisionFlags* collision = context->vfunc_3();
    if (!collision || (mode != 0 && mode != 1)) return (hulk_uintptr)collision & ~255u;
    if (mode == 0) return collision->name == name && collision->flags == flags;
    return collision->name != name || collision->flags != flags;
}
} // namespace fn_00048e10

namespace fn_f92e4dc5 {

// 0x00048e60 FUN_00048e60 (19 B): matches/0x00048e60.cpp
// sym: ?FUN_00048e60@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048e60() {
    FUN_00234810(((char*)&DAT_004dc470), ((char*)&DAT_004dc474));
}

} // namespace fn_f92e4dc5

// 0x00048e80 CCollisionInterruptCondition::vfunc_0 (16 B): matches/0x00048e80.cpp
// sym: ?vfunc_0@CCollisionInterruptCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionInterruptCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc470;
    return p[index];
}


// 0x00048ec0 CCollisionInterruptCondition::vfunc_7 (37 B): matches/0x00048ec0.cpp
// sym: ?vfunc_7@CCollisionInterruptCondition@@UAE_NPAX@Z
bool CCollisionInterruptCondition::vfunc_7(void* __p0) { Input_48ec0 * param = (Input_48ec0 *)__p0;

    Result_48ec0* result = param->f3();
    if (!result)
        return false;
    return result->value == this->f_0c;
}

namespace fn_f92e4dc5 {

// 0x00048ef0 FUN_00048ef0 (19 B): matches/0x00048ef0.cpp
// sym: ?FUN_00048ef0@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048ef0() {
    FUN_00234810(((char*)&DAT_004dc478), ((char*)&DAT_004dc47c));
}

} // namespace fn_f92e4dc5

// 0x00048f10 CCollisionHeightCondition::vfunc_0 (16 B): matches/0x00048f10.cpp
// sym: ?vfunc_0@CCollisionHeightCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionHeightCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc478;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048f60 FUN_00048f60 (19 B): matches/0x00048f60.cpp
// sym: ?FUN_00048f60@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048f60() {
    FUN_00234810(((char*)&DAT_004dc480), ((char*)&DAT_004dc484));
}

} // namespace fn_f92e4dc5

// 0x00048f80 CCollisionPushbackVelocityCondition::vfunc_0 (16 B): matches/0x00048f80.cpp
// sym: ?vfunc_0@CCollisionPushbackVelocityCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionPushbackVelocityCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc480;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00048fd0 FUN_00048fd0 (19 B): matches/0x00048fd0.cpp
// sym: ?FUN_00048fd0@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00048fd0() {
    FUN_00234810(((char*)&DAT_004dc488), ((char*)&DAT_004dc48c));
}

} // namespace fn_f92e4dc5

// 0x00048ff0 CCollisionPushbackYCondition::vfunc_0 (16 B): matches/0x00048ff0.cpp
// sym: ?vfunc_0@CCollisionPushbackYCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionPushbackYCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc488;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00049040 FUN_00049040 (19 B): matches/0x00049040.cpp
// sym: ?FUN_00049040@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049040() {
    FUN_00234810(((char*)&DAT_004dc490), ((char*)&DAT_004dc494));
}

} // namespace fn_f92e4dc5

// 0x00049060 CCollisionPushbackYAngleCondition::vfunc_0 (16 B): matches/0x00049060.cpp
// sym: ?vfunc_0@CCollisionPushbackYAngleCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionPushbackYAngleCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc490;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x000490b0 FUN_000490b0 (19 B): matches/0x000490b0.cpp
// sym: ?FUN_000490b0@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_000490b0() {
    FUN_00234810(((char*)&DAT_004dc498), ((char*)&DAT_004dc49c));
}

} // namespace fn_f92e4dc5

// 0x000490d0 CCollisionStunTimeCondition::vfunc_0 (16 B): matches/0x000490d0.cpp
// sym: ?vfunc_0@CCollisionStunTimeCondition@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr CCollisionStunTimeCondition::vfunc_0(int index) {
    int* p = hulk_at_004dc498;
    return p[index];
}

namespace fn_f92e4dc5 {

// 0x00049120 FUN_00049120 (19 B): matches/0x00049120.cpp
// sym: ?FUN_00049120@fn_f92e4dc5@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_00049120() {
    FUN_00234810(((char*)&DAT_004dc4a0), ((char*)&DAT_004dc4a4));
}

} // namespace fn_f92e4dc5
