// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e2800..0x000e2db0 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb20b5f7 {
#define TREE_TU_END }
namespace fn_fb20b5f7 {} using namespace fn_fb20b5f7;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb20b5f7 {
class Obj_e2800;
class Inner_e2800 {
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
    virtual void f14(unsigned int, Obj_e2800*);
};
class Obj_e2800 {
  public:
    char pad[0x14];
    Inner_e2800* member;
    unsigned int run(unsigned int);
};
class Obj_e2820;
class Inner_e2820 {
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
    virtual void f15(int, Obj_e2820*);
};
class Obj_e2820 {
  public:
    char pad[0x14];
    Inner_e2820* m;
    hulk_intptr method(hulk_intptr);
};
class Outer_e2840;
class Inner_e2840 {
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
    virtual float invoke(Outer_e2840*);
};
class Outer_e2840 {
  public:
    char pad[0x14];
    Inner_e2840* p;
    hulk_freg call();
};
class Outer_e2850;
class Inner_e2850 {
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
    virtual float f17(Outer_e2850*);
};
class Outer_e2850 {
  public:
    char pad[0x14];
    Inner_e2850* p;
    hulk_freg call();
};
struct BasePart_e2940 {
    void Copy(BasePart_e2940*);
};
struct Item_e2940 {
    char pad[0x38];
    int value;
};
struct Thing_e2940 {
    char pad00[0x14];
    Item_e2940* item;
    BasePart_e2940 base;
    char pad1c[0x20];
    unsigned int color3c;
    unsigned char flag40;
    char p41[3];
    unsigned int color44;
    unsigned char flag48;
    char p49[3];
    unsigned int field4c;
    char p50[0x1c];
    unsigned int field6c, field70;
    unsigned char flag74;
    char p75[3];
    unsigned int field78, field7c, field80;
    char p84[4];
    unsigned int field88, field8c, field90, field94;
    void Copy(Thing_e2940*);
};
class Provider {
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
    virtual int v44();
};
struct Mid {
    char pad[4];
    Provider* provider;
};
struct Outer {
    char pad[8];
    Mid* mid;
};
class Elem {
  public:
    void Set(int, int, int);
};
class Obj {
    char pad[0x14];
    Outer* outer;
    Elem elem;

  public:
    void Fn(hulk_intptr);
};
void ReleaseThing(int);
struct State_e2c90 { bool FUN_000b4f20();  };
struct Manager_e2c90 { State_e2c90* FUN_00086280(); };
} // namespace fn_fb20b5f7
struct World { char pad[0x54]; Manager_e2c90* manager; };
namespace fn_fb20b5f7 {
struct Controller_e2c90 {
 virtual void slot0();
 virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39(); virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void slot47(); virtual void setMode(int);
};
struct Link_e2c90 { char pad[4]; Controller_e2c90* controller; };
struct Owner_e2c90 { char pad[8]; Link_e2c90* link; };
struct Entry_e2c90 { virtual void slot0(); virtual void finish(); virtual void slot2(); virtual void slot3(); virtual bool update(int, int, int, int); };
struct Target_e2c90 {
 char pad0[0x14]; Owner_e2c90* owner; char pad18[0x90]; int value; char padAC[0x6c]; Entry_e2c90* entries[10]; unsigned char enabled;
 void FUN_000e2c90(int mode,int arg2,int arg3);
};
typedef unsigned int uint_e2d50;
struct Result_e2d60 {
    int header;
    int slots[4];
};
struct Final_e2d60 {
};
struct Mid_e2d60 {
    char pad[8];
    Final_e2d60* f;
};
struct First_e2d60 {
    char pad[4];
    Mid_e2d60* m;
};
struct Root_e2d60 {
    char pad[8];
    First_e2d60* first;
};
class Owner_e2d60 {
  public:
    char pad[0x14];
    Root_e2d60* root;
    char pad2[0x168];
    Result_e2d60* result;
    void Run(int);
};


// 0x000e2800 FUN_000e2800 (23 B): matches/0x000e2800.cpp
// sym: ?run@Obj_e2800@fn_fb20b5f7@@QAEII@Z
unsigned int Obj_e2800::run(unsigned int param) {
    member->f14(param, this);
    return param;
}


// 0x000e2820 FUN_000e2820 (23 B): matches/0x000e2820.cpp
// sym: ?method@Obj_e2820@fn_fb20b5f7@@QAEHH@Z
hulk_intptr Obj_e2820::method(hulk_intptr param) {
    m->f15(param, this);
    return param;
}


// 0x000e2840 FUN_000e2840 (12 B): matches/0x000e2840.cpp
// sym: ?call@Outer_e2840@fn_fb20b5f7@@QAEMXZ
hulk_freg Outer_e2840::call() {
    Outer_e2840* self = this;
    return p->invoke(self);
}


// 0x000e2850 FUN_000e2850 (12 B): matches/0x000e2850.cpp
// sym: ?call@Outer_e2850@fn_fb20b5f7@@QAEMXZ
hulk_freg Outer_e2850::call() {
    return p->f17(this);
}

} // namespace fn_fb20b5f7

// 0x000e2860 FUN_000e2860 (180 B): equivalent/0x000e2860.cpp [wrapped: conflict: FEObject]
// sym: ??0FEObject@fn_000e2860@@QAE@H@Z
namespace fn_000e2860 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e2860 @ 0x000e2860
struct SubObject_e2860 {
    char data[0x24];
    void FUN_000f7930();
};
struct FEObject {
    virtual void slot0();
    unsigned int baseFields[4]; // 04
    unsigned int field14;
    SubObject_e2860 sub; // 18
    int field3c;
    unsigned char field40;
    char pad41[3];
    int field44;
    unsigned char field48;
    char pad49[3];
    unsigned int color;
    unsigned int field50;
    float scale54, scale58, scale5c;
    unsigned int field60, field64;
    unsigned char field68;
    char pad69[7];
    unsigned int field70;
    unsigned char field74;
    char pad75[3];
    unsigned int field78, field7c, field80;
    char pad84[4];
    unsigned int field88, field8c, field90, field94;
    unsigned char field98;
    char pad99[11];
    unsigned int fielda4;
    char pada8[4];
    unsigned int fieldac;
    unsigned int block[12];
    unsigned int fielde0;
    FEObject(int unused);
};
FEObject::FEObject(int unused) {
    baseFields[0] = baseFields[1] = baseFields[2] = baseFields[3] = 0;
    sub.FUN_000f7930();
    fielde0 = 0;
    field3c = field44 = -1;
    field14 = 0;
    fielda4 = 0;
    field74 = 1;
    field98 = 0;
    field90 = field94 = 0;
    field40 = field48 = 0;
    color = 0xff000000;
    field50 = 0;
    scale54 = scale58 = scale5c = 1.0f;
    field60 = field64 = 0;
    field68 = 0;
    field88 = field8c = fieldac = 0;
    for (int i = 0; i < 12; ++i) block[i] = 0;
    field70 = 2;
    field80 = field7c = field78 = 0;
}
} // namespace fn_000e2860

namespace fn_fb20b5f7 {

// 0x000e2940 FUN_000e2940 (172 B): matches/0x000e2940.cpp
// sym: ?Copy@Thing_e2940@fn_fb20b5f7@@QAEXPAU12@@Z
void Thing_e2940::Copy(Thing_e2940* src) {
    base.Copy(&src->base);
    flag74 = src->flag74;
    field90 = src->field90;
    field94 = src->field94;
    color3c = 0xffc0c0c0;
    flag40 = src->flag40;
    color44 = 0xffc0c0c0;
    flag48 = src->flag48;
    field4c = src->field4c;
    field6c = src->field6c;
    field70 = src->field70;
    field88 = src->field88;
    field8c = src->field8c;
    field78 = src->field78;
    field7c = src->field7c;
    *(unsigned int volatile*)&field80 = src->field80;
    Item_e2940* d = *(Item_e2940* volatile*)&item;
    if (d) {
        Item_e2940* s = src->item;
        d->value = s->value;
        s = src->item;
        d = item;
        d->value = s->value;
    }
}


// 0x000e2a60 FUN_000e2a60 (40 B): matches/0x000e2a60.cpp
// sym: ?Fn@Obj@fn_fb20b5f7@@QAEXH@Z
void Obj::Fn(hulk_intptr x) {
    elem.Set(x, outer->mid->provider->v44(), 1);
}

} // namespace fn_fb20b5f7

// 0x000e2ac0 FUN_000e2ac0 (60 B): matches/0x000e2ac0.cpp
// sym: ?FUN_000e2ac0@Obj_e2ac0@owners@@QAEXH@Z
void owners::Obj_e2ac0::FUN_000e2ac0(hulk_intptr value) {
    int old = field;
    if (old != 0) {
        ReleaseThing(old);
        field = 0;
        field = ((int)value);
    } else {
        field = ((int)value);
    }
}


// 0x000e2bd0 FEControl::vfunc_18 (143 B): matches/0x000e2bd0.cpp [wrapped: conflict: FEControl]
// sym: ?vfunc_18@FEControl@fn_000e2bd0@@UAEXXZ
namespace fn_000e2bd0 {
// data: kNegSmall = DAT_003f5cf0, kSmall = DAT_00405708

class FEControl {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual float GetX();
    virtual float GetY();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void Draw(float, float, float, float);
    virtual void vfunc_18();
};
void FEControl::vfunc_18() {
    float a = (GetY() * 0.5f) * DAT_003f5cf0;
    float b = (GetX() * 0.5f) * DAT_0040bf64;
    float c = (GetY() * 0.5f) * DAT_00405708;
    float d = GetY();
    d = d + c;
    float e = (GetX() * 0.5f) * DAT_0040c230;
    Draw(a, b, d, e);
}
} // namespace fn_000e2bd0


// 0x000e2c60 FUN_000e2c60 (41 B): matches/0x000e2c60.cpp
// sym: ?FUN_000e2c60@C_e2c60@owners@@QAEXH@Z
void owners::C_e2c60::FUN_000e2c60(hulk_intptr x) {
    int i = 0;
    while (i < 10 && slots[i] != 0)
        ++i;
    if (i != 10)
        slots[i] = ((int)x);
}

namespace fn_fb20b5f7 {

// 0x000e2c90 FUN_000e2c90 (170 B): equivalent/0x000e2c90.cpp
// sym: ?FUN_000e2c90@Target_e2c90@fn_fb20b5f7@@QAEXHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000e2c90 @ 0x000e2c90
void Target_e2c90::FUN_000e2c90(int mode,int arg2,int arg3) {
 if (enabled && (mode==0 || mode==1)) {
 State_e2c90* s=DAT_004dd700->manager->FUN_00086280();
 if(s->FUN_000b4f20() && ((owners::Foo_b8c90 *)s)->FUN_000b8c90()) return;
 }
 if(enabled && mode==0) owner->link->controller->setMode(mode);
 for(int i=0;i<10;++i) {
 if(!entries[i]) break;
 if(entries[i]->update(mode,value,arg2,arg3)) entries[i]->finish();
 }
}


// 0x000e2d40 FEControl::vfunc_4 (1 B): matches/0x000e2d40.cpp
// sym: ?FUN_000e2d40@fn_fb20b5f7@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000e2d40() {}

} // namespace fn_fb20b5f7

// 0x000e2d50 TextButton::vfunc_12 (9 B): matches/0x000e2d50.cpp
// sym: ?vfunc_12@TextButton@@UAE_NHH@Z
bool TextButton::vfunc_12(int __p0, int __p1) { uint_e2d50 a = (uint_e2d50)__p0; uint_e2d50 b = (uint_e2d50)__p1;

    vfunc_0();
    return false;
}

namespace fn_fb20b5f7 {

// 0x000e2d60 FUN_000e2d60 (67 B): matches/0x000e2d60.cpp
// sym: ?Run@Owner_e2d60@fn_fb20b5f7@@QAEXH@Z
void Owner_e2d60::Run(int arg) {
    Result_e2d60* p = ((Result_e2d60 *)((owners::ThisWrap_000f8d40 *)(root->first->m->f))->FUN_000f8d40(arg));
    result = p;
    if (p) {
        int i = 0;
        while (i < 4 && p->slots[i] != 0)
            ++i;
        if (i != 4)
            p->slots[i] = (hulk_intptr)this;
    }
}

} // namespace fn_fb20b5f7
