// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0029b120..0x0029b490 (kind game, layer engine, confidence high), dominant class pure3d::TextString
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f9d9ed06 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f9d9ed06 {} using namespace fn_f9d9ed06;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f9d9ed06 {
extern "C" char DAT_0042d548[];
class Base_29b120 {
  public:
    virtual void Call();
};
class TextString {
  public:
    virtual void V();
    char pad[0x3c];
    Base_29b120* obj;
    int x44;
    int a48;
    int a4c;
    unsigned char flag;
    void Init_002a5060();
    TextString* Foo(Base_29b120* p, int a, int b, unsigned char f);
};
class pddiObject_29b190 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_29b190 : public pddiObject_29b190 {};
class pddiBaseShader_29b190 : public pddiShader_29b190 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_29b190 : public pddiBaseShader_29b190 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
typedef unsigned int u32_29b1d0;
struct Base_29b1d0 {
    virtual void a();
    virtual void release();
};
struct Obj_29b1d0 {
    char pad[0x40];
    Base_29b1d0* base;
    char p44[4];
    u32_29b1d0 value;
    char p4c[4];
    unsigned char flag;
};
void cleanup_0008d340(u32_29b1d0);
extern "C" void __fastcall FUN_002a50a0(Obj_29b1d0*);
struct Font_29b210 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual void SetLayout(int a, int b);
    virtual void v12(); virtual void v13();
    virtual void GetColour(int* out);
    virtual void SetColour(int c);
};
struct Device_29b210 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void PushState(int a);
    virtual void PopState(int a);
};
struct Context_29b210 {
    Device_29b210* device;
    void FUN_00293da0(int a, int b, int c);
};
class Thing_29b300 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_29b300 {
  public:
    char pad[0x40];
    Thing_29b300* member;
    void Set(Thing_29b300* p);
};
struct Obj_29b330 {
    char pad[0x48];
    int value;
    char pad2[4];
    unsigned char flag;
};
void cleanup_0008d340(int);


// 0x0029b120 FUN_0029b120 (59 B): matches/0x0029b120.cpp
// sym: ?Foo@TextString@fn_f9d9ed06@@QAEPAV12@PAVBase_29b120@2@HHE@Z
TextString* TextString::Foo(Base_29b120* p, int a, int b, unsigned char f) {
    Init_002a5060();
    *(hulk_uintptr*)this = ((hulk_intptr)DAT_0042d548);
    this->x44 = -1;
    this->obj = p;
    p->Call();
    this->a48 = a;
    this->a4c = b;
    this->flag = f;
    return this;
}

} // namespace fn_f9d9ed06

// 0x0029b160 pure3d::TextString::vfunc_11 (3 B): matches/0x0029b160.cpp
// sym: ?vfunc_11@TextString@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::TextString::vfunc_11() {
    return 0;
}


// 0x0029b170 pure3d::TextString::vfunc_12 (3 B): matches/0x0029b170.cpp
// sym: ?vfunc_12@TextString@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::TextString::vfunc_12() {
    return 0;
}


// 0x0029b180 pure3d::TextString::vfunc_9 (3 B): matches/0x0029b180.cpp
// sym: ?vfunc_9@TextString@pure3d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char pure3d::TextString::vfunc_9() {
    return 0;
}


// 0x0029b190 pure3d::TextString::vfunc_5 (6 B): matches/0x0029b190.cpp
// sym: ?vfunc_5@TextString@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::TextString::vfunc_5() {
    return 1;
}

namespace fn_f9d9ed06 {

// 0x0029b1a0 pure3d::TextString::vfunc_7 (3 B): matches/0x0029b1a0.cpp
// sym: ?GetZero@fn_f9d9ed06@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f9d9ed06

// 0x0029b1b0 pure3d::TextString::vfunc_8 (3 B): matches/0x0029b1b0.cpp
// sym: ?vfunc_8@TextString@pure3d@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::TextString::vfunc_8(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}

namespace fn_f9d9ed06 {

// 0x0029b1c0 pure3d::TextString::vfunc_10 (1 B): matches/0x0029b1c0.cpp
// sym: ?FUN_0029b1c0@fn_f9d9ed06@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0029b1c0() {}


// 0x0029b1d0 FUN_0029b1d0 (51 B): matches/0x0029b1d0.cpp
// sym: ?target@fn_f9d9ed06@@YIXPAUObj_29b1d0@1@@Z
void __fastcall target(Obj_29b1d0* self) {
    *(hulk_uintptr*)self = ((hulk_intptr)DAT_0042d548);
    if (self->flag)
        cleanup_0008d340(self->value);
    self->base->release();
    self->base = 0;
    FUN_002a50a0(self);
}

} // namespace fn_f9d9ed06

// 0x0029b210 pure3d::TextString::vfunc_6 (129 B): equivalent/0x0029b210.cpp
// sym: ?vfunc_6@TextString@pure3d@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 4/4)
// pure3d::TextString::vfunc_6 @ 0x0029b210
// 0x0029b210: TextString::vfunc_6: draw the string through its font object, wrapping a scale if set
void pure3d::TextString::vfunc_6() {
    int saved = (int)this;
    if (this->f_4c != 0x3f800000) {
        (*(Context_29b210**)&DAT_0052c2ac)->device->PushState(0);
        (*(Context_29b210**)&DAT_0052c2ac)->FUN_00293da0(this->f_4c, this->f_4c, 0x3f800000);
    }
    (*(Font_29b210 * *)&this->f_40)->GetColour(&saved);
    (*(Font_29b210 * *)&this->f_40)->SetColour(this->f_44);
    (*(Font_29b210 * *)&this->f_40)->SetLayout(this->f_48, 0);
    (*(Font_29b210 * *)&this->f_40)->SetColour(saved);
    if (this->f_4c != 0x3f800000)
        (*(Context_29b210**)&DAT_0052c2ac)->device->PopState(0);
}

namespace fn_f9d9ed06 {

// 0x0029b300 FUN_0029b300 (26 B): matches/0x0029b300.cpp
// sym: ?Set@Owner_29b300@fn_f9d9ed06@@QAEXPAVThing_29b300@2@@Z
void Owner_29b300::Set(Thing_29b300* p) {
    member->Second();
    member = p;
    p->First();
}


// 0x0029b330 FUN_0029b330 (58 B): matches/0x0029b330.cpp
// sym: ?FUN_0029b330@fn_f9d9ed06@@YIXPAUObj_29b330@1@PAXHE@Z
void __fastcall FUN_0029b330(Obj_29b330* self, void*, int param2, unsigned char param3) {
    if (self->flag)
        cleanup_0008d340(self->value);
    self->value = param2;
    self->flag = param3;
}

} // namespace fn_f9d9ed06

// 0x0029b380 FUN_0029b380 (10 B): matches/0x0029b380.cpp
// sym: ?FUN_0029b380@Obj_29b380@owners@@QAEXH@Z
void owners::Obj_29b380::FUN_0029b380(int x) {
    mX = x;
}


// 0x0029b3a0 pure3d::TextString::vfunc_2 (72 B): matches/0x0029b3a0.cpp [wrapped: conflict: TextString]
// sym: ??_GTextString@fn_0029b3a0@@UAEPAXI@Z
namespace fn_0029b3a0 {
typedef unsigned char u8;
typedef unsigned int u32_29b3a0;
void ReleaseThing_0008d340(void* p);
class Base_29b3a0 {
  public:
    virtual void f0();
    virtual void f1();
};
class TextString {
  public:
    virtual void f0();
    virtual void f1();
    virtual ~TextString();
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
    char pad[0x3c];
    Base_29b3a0* mBase;
    char p44[4];
    hulk_uintptr mThing;
    char p4c[4];
    u8 mFlag;
    void cleanup_002a50a0();
};
TextString::~TextString() {
    if (mFlag)
        ReleaseThing_0008d340((void*)mThing);
    mBase->f1();
    mBase = 0;
    cleanup_002a50a0();
}
} // namespace fn_0029b3a0

