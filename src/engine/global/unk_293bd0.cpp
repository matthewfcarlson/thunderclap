// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00293bd0..0x002940f0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/global.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fd6a08a7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fd6a08a7 {} using namespace fn_fd6a08a7;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_fd6a08a7 {
class Obj_293bd0 {
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
    virtual void f13(int);
};
class Holder_293bd0 {
  public:
    Obj_293bd0* p;
    Holder_293bd0* FUN_00293bd0(Obj_293bd0*);
};
struct Global_293bf0 {
    void Fna_0022b980();
    void Fnb_0022ba30(unsigned);
};
extern Global_293bf0 hulk_at_0052c2d8;
struct Obj_293bf0 {
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
    virtual void f17(unsigned, void*);
};
struct Target_293bf0 {
    Obj_293bf0* obj;
    void run(unsigned);
};
extern char g52c2d8[4];
struct Global_293c20 {
    void Fna_0022b980();
    void Fnb_0022ba70(unsigned);
};
extern Global_293c20 g_293c20;
struct Obj_293c20 {
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
    virtual void f17(unsigned, void*);
};
struct Target_293c20 {
    Obj_293c20* obj;
    void run(unsigned);
};
struct Global_293c50 {
    void Fna_0022b980();
    void Fnb_0022bab0(unsigned);
};
extern Global_293c50 g_293c50;
struct Obj_293c50 {
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
    virtual void f17(unsigned, void*);
};
struct Target_293c50 {
    Obj_293c50* obj;
    void run(unsigned);
};
struct V {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17(int, int);
};
struct G_293c80 {
    void Fna_0022b980();
    void Fnb_0022bc20(int, int, int);
};
struct T_293c80 {
    V* p;
    void f(int, int, int);
};
struct G_293cc0 {
    void Fna_0022b980();
    void Fnb_0022bcd0(int, int, int);
};
struct T_293cc0 {
    V* p;
    void f(int, int, int);
};
struct Data_293d00 {
    int a, b, c;
};
extern Data_293d00 gData_293d00;
extern int hulk_at_0052c308, hulk_at_0052c30c, hulk_at_0052c310;
struct InitObj_293d00 {
    void foo_0022b980();
};
extern InitObj_293d00 gInit_293d00;
class Host_293d00 {
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
    virtual void f17(int, Data_293d00*);
};
class Owner_293d00 {
  public:
    Host_293d00* host;
    void run(Data_293d00* p);
};
typedef unsigned int U_293d40;
struct Obj_293d40 {
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
    virtual void f17(int, void*);
};
struct Holder_293d40 {
    Obj_293d40* p;
};
struct Sub_293d40 {
    void init_0022b980();
};
struct C_293d40 {
    Holder_293d40 h;
    void run(U_293d40, U_293d40, U_293d40);
};
struct G_293da0 {
    void Fna_0022b980();
    void Fnb_0022be60(int, int, int);
};
struct T_293da0 {
    V* p;
    void f(int, int, int);
};
class Item_293ea0 {
  public:
    virtual void Use();
};
class Owner_293ea0 {
  public:
    virtual void V();
    char pad[0x38];
    Item_293ea0* volatile items[32];
    int Add(Item_293ea0* item);
};
struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void slot();
};
struct State {
    char pad[8];
    int value;
};
struct Owner {
    char pad[0x3c];
    Item* items[32];
    void func();
};
class Inner_2940d0 {
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
    virtual unsigned int Get();
};
class Helper_2940d0 {
  public:
};
class Owner_2940d0 {
  public:
    char pad[0x18];
    Inner_2940d0* ptr;
    void Target(void* out, Helper_2940d0* h);
};


// 0x00293bd0 FUN_00293bd0 (22 B): matches/0x00293bd0.cpp
// sym: ?FUN_00293bd0@Holder_293bd0@fn_fd6a08a7@@QAEPAV12@PAVObj_293bd0@2@@Z
Holder_293bd0* Holder_293bd0::FUN_00293bd0(Obj_293bd0* p) {
    this->p = p;
    p->f13(0);
    return this;
}


// 0x00293bf0 FUN_00293bf0 (46 B): matches/0x00293bf0.cpp
// sym: ?run@Target_293bf0@fn_fd6a08a7@@QAEXI@Z
void Target_293bf0::run(unsigned arg) {
    hulk_at_0052c2d8.Fna_0022b980();
    hulk_at_0052c2d8.Fnb_0022ba30(arg);
    obj->f17(0, g52c2d8);
}


// 0x00293c20 FUN_00293c20 (46 B): matches/0x00293c20.cpp
// sym: ?run@Target_293c20@fn_fd6a08a7@@QAEXI@Z
// Same code shape as 0x00293bf0 (propagated; names are from that function)
void Target_293c20::run(unsigned arg) {
    g_293c20.Fna_0022b980();
    g_293c20.Fnb_0022ba70(arg);
    obj->f17(0, g52c2d8);
}


// 0x00293c50 FUN_00293c50 (46 B): matches/0x00293c50.cpp
// sym: ?run@Target_293c50@fn_fd6a08a7@@QAEXI@Z
// Same code shape as 0x00293bf0 (propagated; names are from that function)
void Target_293c50::run(unsigned arg) {
    g_293c50.Fna_0022b980();
    g_293c50.Fnb_0022bab0(arg);
    obj->f17(0, g52c2d8);
}


// 0x00293c80 FUN_00293c80 (56 B): matches/0x00293c80.cpp
// sym: ?f@T_293c80@fn_fd6a08a7@@QAEXHHH@Z
// data: glob_293c80 = DAT_0052c2d8
void T_293c80::f(int a, int b, int c) {
    (*(G_293c80*)&DAT_0052c2d8).Fna_0022b980();
    (*(G_293c80*)&DAT_0052c2d8).Fnb_0022bc20(a, b, c);
    p->x17(0, (hulk_intptr)&(*(G_293c80*)&DAT_0052c2d8));
}


// 0x00293cc0 FUN_00293cc0 (56 B): matches/0x00293cc0.cpp
// sym: ?f@T_293cc0@fn_fd6a08a7@@QAEXHHH@Z
// Same code shape as 0x00293c80 (propagated; names are from that function)
// data: glob_293cc0 = DAT_0052c2d8
void T_293cc0::f(int a, int b, int c) {
    (*(G_293cc0*)&DAT_0052c2d8).Fna_0022b980();
    (*(G_293cc0*)&DAT_0052c2d8).Fnb_0022bcd0(a, b, c);
    p->x17(0, (hulk_intptr)&(*(G_293cc0*)&DAT_0052c2d8));
}


// 0x00293d00 FUN_00293d00 (60 B): matches/0x00293d00.cpp
// sym: ?run@Owner_293d00@fn_fd6a08a7@@QAEXPAUData_293d00@2@@Z
void Owner_293d00::run(Data_293d00* p) {
    gInit_293d00.foo_0022b980();
    hulk_at_0052c308 = p->a;
    hulk_at_0052c30c = p->b;
    hulk_at_0052c310 = p->c;
    host->f17(0, &gData_293d00);
}


// 0x00293d40 FUN_00293d40 (94 B): matches/0x00293d40.cpp
// sym: ?run@C_293d40@fn_fd6a08a7@@QAEXIII@Z
void C_293d40::run(U_293d40 a, U_293d40 b, U_293d40 c) {
    (*(U_293d40*)&DAT_0052c2c8) = a;
    (*(U_293d40*)&DAT_0052c2cc) = b;
    (*(U_293d40*)&DAT_0052c2d0) = c;
    (*(Sub_293d40*)&DAT_0052c2d8).init_0022b980();
    (*(U_293d40*)&DAT_0052c308) = (*(U_293d40*)&DAT_0052c2c8);
    (*(U_293d40*)&DAT_0052c30c) = (*(U_293d40*)&DAT_0052c2cc);
    (*(U_293d40*)&DAT_0052c310) = (*(U_293d40*)&DAT_0052c2d0);
    h.p->f17(0, (void*)&(*(Sub_293d40*)&DAT_0052c2d8));
}


// 0x00293da0 FUN_00293da0 (56 B): matches/0x00293da0.cpp
// sym: ?f@T_293da0@fn_fd6a08a7@@QAEXHHH@Z
// Same code shape as 0x00293c80 (propagated; names are from that function)
// data: glob_293da0 = DAT_0052c2d8
void T_293da0::f(int a, int b, int c) {
    (*(G_293da0*)&DAT_0052c2d8).Fna_0022b980();
    (*(G_293da0*)&DAT_0052c2d8).Fnb_0022be60(a, b, c);
    p->x17(0, (hulk_intptr)&(*(G_293da0*)&DAT_0052c2d8));
}

} // namespace fn_fd6a08a7

// 0x00293e40 FUN_00293e40 (31 B): matches/0x00293e40.cpp
// sym: ?FUN_00293e40@A_293e40@owners@@QAEXHHHH@Z
void owners::A_293e40::FUN_00293e40(int a, int b, int c, int d) {
    *(int*)((char*)this + 8) = a;
    *(int*)((char*)this + 12) = b;
    *(int*)((char*)this + 16) = c;
    *(int*)((char*)this + 20) = d;
}


// 0x00293e60 FUN_00293e60 (39 B): matches/0x00293e60.cpp
// sym: ?FUN_00293e60@Obj_293e60@owners@@QAEXPAH000@Z
void owners::Obj_293e60::FUN_00293e60(int* x, int* y, int* z, int* w) {
    *x = a;
    *y = b;
    *z = c;
    *w = d;
}


// 0x00293e90 FUN_00293e90 (10 B): matches/0x00293e90.cpp
// sym: ?FUN_00293e90@C_293e90@owners@@QAEXH@Z
// Same code shape as 0x001fb9b0 (propagated; names are from that function)
void owners::C_293e90::FUN_00293e90(int x) {
    value = x;
}

namespace fn_fd6a08a7 {

// 0x00293ea0 FUN_00293ea0 (61 B): matches/0x00293ea0.cpp
// sym: ?Add@Owner_293ea0@fn_fd6a08a7@@QAEHPAVItem_293ea0@2@@Z
int Owner_293ea0::Add(Item_293ea0* item) {
    int i = 0;
    do {
        if (items[i] == 0) {
            item->Use();
            items[i] = item;
            return i;
        }
        ++i;
    } while (i < 32);
    return -1;
}

} // namespace fn_fd6a08a7

// 0x00293ef0 FUN_00293ef0 (393 B): equivalent/0x00293ef0.cpp [wrapped: macros]
// sym: ?run@Target@fn_00293ef0@@QAEXXZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_00293ef0 {
// STATUS: equivalent (tools/equiv.py level 3: 2608 inputs, branch coverage 8/8)
// FUN_00293ef0 @ 0x00293ef0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Matrix { unsigned data[16];   };
#define V(n) virtual void s##n();
struct Provider { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) virtual Matrix* matrix(); V(15) V(16) V(17) V(18) V(19) V(20) V(21) virtual void activate(); };
struct Gfx { V(0) V(1) V(2) V(3) V(4) V(5) virtual void set20(unsigned); V(7) virtual void set24(unsigned); V(9) virtual void set28(unsigned); V(11) virtual void set2c(unsigned); V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23) V(24) V(25) virtual void viewport(unsigned,unsigned,unsigned,unsigned); V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) virtual void state(unsigned); V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) virtual void enable(unsigned); V(79) virtual void values(unsigned,unsigned,unsigned); };
struct Renderer { V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) virtual void reset(unsigned); V(17) V(18) V(19) V(20) V(21) virtual void transform(unsigned,Matrix*); };
struct Item { V(0) V(1) V(2) V(3) V(4) virtual void bind(unsigned); };
struct Target;
struct Context { char pad[8]; Target* current; void FUN_0028fa40(Matrix*,Matrix*); };
struct Target { char pad[8]; unsigned x,y,w,h; Provider* provider; unsigned state; unsigned a,b,c,d; unsigned v0,v1,v2; Item* items[32]; unsigned char enabled; char padbd[3]; Matrix first,second; void run(); };
void Target::run() {
 (*(Context**)&DAT_0052c2b4)->current=this;
 provider->activate();
 DAT_0052c2a8->viewport(x,y,w,h);
 DAT_0052c2a8->state(state);
 struct { Matrix inverse, original, next; } matrices;
 ((owners::Matrix_22ca90 *)&(matrices.original))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(provider->matrix()), (const owners::Matrix_22ca90 *)(Matrix *)(&first));
 matrices.inverse=matrices.original;
 ((owners::Matrix_22cdb0 *)&(matrices.inverse))->FUN_0022cdb0();
 (*(Context**)&DAT_0052c2b4)->FUN_0028fa40(&matrices.inverse,&matrices.original);
 ((owners::Matrix_22ca90 *)&(matrices.next))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(provider->matrix()), (const owners::Matrix_22ca90 *)(Matrix *)(&second));
 ((owners::Matrix_22cdb0 *)&(matrices.next))->FUN_0022cdb0();
 (*(*(Renderer***)&DAT_0052c2ac))->transform(0,&matrices.next);
 unsigned slot=0;
 Item** item=items;
 unsigned remaining=32;
 do { if(*item) { (*item)->bind(slot); ++slot; } ++item; } while(--remaining);
 (*(*(Renderer***)&DAT_0052c2ac))->reset(0);
 if(enabled) { DAT_0052c2a8->enable(1); DAT_0052c2a8->values(v0,v1,v2); } else DAT_0052c2a8->enable(0);
 if(d) { DAT_0052c2a8->set20(a); DAT_0052c2a8->set24(b); DAT_0052c2a8->set28(c); DAT_0052c2a8->set2c(d); }
}
} // namespace fn_00293ef0
#undef V
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fd6a08a7 {

// 0x00294080 FUN_00294080 (44 B): matches/0x00294080.cpp
// sym: ?func@Owner@fn_fd6a08a7@@QAEXXZ
// data: state = DAT_0052c2b4
void Owner::func() {
    (*(State**)&DAT_0052c2b4)->value = 0;
    for (int i = 0; i < 32; ++i) {
        if (items[i])
            items[i]->slot();
    }
}


// 0x002940d0 FUN_002940d0 (32 B): matches/0x002940d0.cpp
// sym: ?Target@Owner_2940d0@fn_fd6a08a7@@QAEXPAXPAVHelper_2940d0@2@@Z
void Owner_2940d0::Target(void* out, Helper_2940d0* h) {
    if (ptr)
        ((owners::C_22d240 *)h)->FUN_0022d240((hulk_intptr)out, (hulk_intptr)(ptr->Get()));
}

} // namespace fn_fd6a08a7
