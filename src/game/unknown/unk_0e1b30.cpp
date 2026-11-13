// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1b30..0x000e1d20 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f5f1b679 {
#define TREE_TU_END }
namespace fn_f5f1b679 {} using namespace fn_f5f1b679;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f5f1b679 {
struct Inner_e1b70 {
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
    virtual void f29(void*);
};
struct Holder_e1b70 {
    char pad[4];
    Inner_e1b70* p;
};
extern int hulk_at_0040c0a4;
class FEDoBackMenu_e1c60 {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    char e;
    FEDoBackMenu_e1c60(hulk_intptr);
};
class Base_e1c80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class Inner_e1c80 {
  public:
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad();
    virtual void ae();
    virtual void af();
    virtual void ag();
    virtual void ah();
    virtual void ai();
    virtual void aj();
    virtual void ak();
};
class Container_e1c80 {
  public:
    int pad;
    Inner_e1c80* p;
};
class FEDoAction_e1c80 {
  public:
    char pad[0x10];
    Container_e1c80* m;
};
struct R_e1cd0 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void go(void*);
};
struct Q_e1cd0 {
    char pad[4];
    R_e1cd0* r;
};

} // namespace fn_f5f1b679

// 0x000e1b30 FUN_000e1b30 (59 B): matches/0x000e1b30.cpp [wrapped: conflict: FEDoMenu]
// sym: ??0FEDoMenu@fn_000e1b30@@QAE@HPBD@Z
namespace fn_000e1b30 {
extern "C" char DAT_0040c05c[];
class FEDoMenu {
  public:
    hulk_intptr a;
    int gap;
    int b;
    int c;
    int d;
    char e;
    char pad[31];
    int f;
    FEDoMenu(hulk_intptr x, const char* s);
};
extern void __cdecl FUN_000dfcc0(char*, int, const char*, ...);
FEDoMenu::FEDoMenu(hulk_intptr x, const char* s) {
    b = -1;
    c = -1;
    d = x;
    e = 0;
    a = ((hulk_intptr)DAT_0040c05c);
    FUN_000dfcc0((char*)&this->f, 0x20, "%s", s);
}
} // namespace fn_000e1b30


// 0x000e1b70 FEDoMenu::vfunc_1 (18 B): matches/0x000e1b70.cpp
// sym: ?vfunc_1@FEDoMenu@@UAEXXZ
void FEDoMenu::vfunc_1() {
    (*(Holder_e1b70 * *)&this->f_10)->p->f29((char*)this + 0x34);
}


// 0x000e1b90 FUN_000e1b90 (168 B): equivalent/0x000e1b90.cpp [wrapped: conflict: FEDoPushDialog; FUN_000dfcc0]
// sym: ??0FEDoPushDialog@fn_000e1b90@@QAE@HPBD0000H@Z @532299616043 @w387b2d0a754a
namespace fn_000e1b90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e1b90 @ 0x000e1b90
extern "C" int __cdecl FUN_000dfcc0(char*, int, const char*, ...);
struct FEDoPushDialog {
 virtual void* placeholder_000e8be0(char);
 int unused;
 int stateA;
 int stateB;
 int owner;
 char flag;
 char padding[31];
 char text1[32];
 char text2[256];
 char text3[32];
 char text4[32];
 char text5[32];
 int finalValue;
 FEDoPushDialog(hulk_intptr, const char*, const char*, const char*, const char*, const char*, int);
};
FEDoPushDialog::FEDoPushDialog(hulk_intptr value, const char* a, const char* b, const char* c, const char* d, const char* e, int last) {
 stateA = -1;
 stateB = -1;
 owner = value;
 flag = 0;
 FUN_000dfcc0(text1,32,"%s",a);
 FUN_000dfcc0(text2,256,"%s",b);
 FUN_000dfcc0(text3,32,"%s",c);
 FUN_000dfcc0(text4,32,"%s",d);
 FUN_000dfcc0(text5,32,"%s",e);
 finalValue = last;
}
} // namespace fn_000e1b90


// 0x000e1c40 FUN_000e1c40 (31 B): matches/0x000e1c40.cpp [wrapped: conflict: FEDoPopDialog]
// sym: ??0FEDoPopDialog@fn_000e1c40@@QAE@H@Z
namespace fn_000e1c40 {
extern int hulk_at_0040c08c;
class FEDoPopDialog {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    char e;
    FEDoPopDialog(hulk_intptr);
};
FEDoPopDialog::FEDoPopDialog(hulk_intptr x) {
    b = -1;
    c = -1;
    d = x;
    e = 0;
    vptr = (hulk_intptr)&hulk_at_0040c08c;
}
} // namespace fn_000e1c40

namespace fn_f5f1b679 {

// 0x000e1c60 FUN_000e1c60 (31 B): matches/0x000e1c60.cpp
// sym: ??0FEDoBackMenu_e1c60@fn_f5f1b679@@QAE@H@Z
// Same code shape as 0x000e1c40 (propagated; names are from that function)
FEDoBackMenu_e1c60::FEDoBackMenu_e1c60(hulk_intptr x) {
    b = -1;
    c = -1;
    d = x;
    e = 0;
    vptr = (hulk_intptr)&hulk_at_0040c0a4;
}

} // namespace fn_f5f1b679

// 0x000e1c80 FEDoBackMenu::vfunc_1 (11 B): matches/0x000e1c80.cpp
// sym: ?vfunc_1@FEDoBackMenu@@UAEXXZ
void FEDoBackMenu::vfunc_1() {
    (*(Container_e1c80 * *)&this->f_10)->p->ak();
}


// 0x000e1c90 FUN_000e1c90 (59 B): matches/0x000e1c90.cpp [wrapped: conflict: FEDoScreen]
// sym: ??0FEDoScreen@fn_000e1c90@@QAE@HPBD@Z
namespace fn_000e1c90 {
extern "C" char DAT_0040c0bc[];
class FEDoScreen {
  public:
    int pad0[2];
    int a, b, c;
    char e;
    char pad[31];
    FEDoScreen(hulk_intptr, const char*);
};
extern void Format_000dfcc0(char*, int, const char*, ...);
FEDoScreen::FEDoScreen(hulk_intptr x, const char* s) {
    a = -1;
    b = -1;
    c = x;
    e = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0040c0bc);
    Format_000dfcc0((char*)this + 0x34, 0x20, "%s", s);
}
} // namespace fn_000e1c90


// 0x000e1cd0 FEDoScreen::vfunc_1 (18 B): matches/0x000e1cd0.cpp
// sym: ?vfunc_1@FEDoScreen@@UAEXXZ
void FEDoScreen::vfunc_1() {
    (*(Q_e1cd0 * *)&this->f_10)->r->go((char*)this + 0x34);
}


// 0x000e1cf0 FUN_000e1cf0 (45 B): matches/0x000e1cf0.cpp [wrapped: conflict: FEDoBackScreen]
// sym: ??0FEDoBackScreen@fn_000e1cf0@@QAE@HEE@Z
namespace fn_000e1cf0 {
extern "C" char DAT_0040c0d4[];
class FEDoBackScreen {
  public:
    virtual void f();
    FEDoBackScreen(hulk_intptr, unsigned char, unsigned char);
    char pad[0x38];
};
FEDoBackScreen::FEDoBackScreen(hulk_intptr a, unsigned char b, unsigned char c) {
    *(int*)((char*)this + 8) = -1;
    *(int*)((char*)this + 12) = -1;
    *(int*)((char*)this + 16) = a;
    *((char*)this + 20) = 0;
    *(hulk_intptr*)((char*)this + 0) = ((hulk_intptr)DAT_0040c0d4);
    *((char*)this + 0x34) = b;
    *((char*)this + 0x35) = c;
}
} // namespace fn_000e1cf0

