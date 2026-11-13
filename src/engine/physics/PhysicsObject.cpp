// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002f5130..0x002f79f0 (kind game, layer engine, confidence high), dominant class physics::PhysicsObject
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/content.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_ff237b18 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_ff237b18 {} using namespace fn_ff237b18;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_ff237b18 {
class SymMatrix_2f5460 : public CAction {
  public:
    SymMatrix_2f5460* vfunc_2(unsigned char);
};
extern void __fastcall FUN_002fcaa0(void*);
extern void thunk_FUN_00267090(SymMatrix_2f5460*);
namespace fight {
class Condition_2f5590 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
}
namespace fight {
class Param_2f5590 {
  public:
    virtual void pvfunc_0();
    virtual void pvfunc_1();
};
}
} // namespace fn_ff237b18
namespace physics {
struct Part_2f55b0 {
    void work_00308ba0(int);
};
}
namespace fn_ff237b18 {
class PhysicsObject {
    char pad[0x1c4];

  public:
    void vfunc_10();
};
struct Vec3_2f57d0 {
    float x, y, z;
};
class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Notify(int arg);
    char pad8[0x10 - 4];
    void* listener;
    char pad14[0xa4 - 0x14];
    char nearZero;
    char pada5[3];
    Vec3_2f57d0 base;
    Vec3_2f57d0 target;

    void FUN_002f57d0(const Vec3_2f57d0* offset);
};
class Elem_2f5870 {
  public:
};
typedef unsigned int u32_2f59f0;
struct V3_2f5a20 {
    float x, y, z;
};
struct Body_2f5a20 {
    char pad00[0x40];
    float x, y, z;
    char pad4c[4];
    V3_2f5a20 pos;
    float ax, ay, az;
};
class PhysicsObject_2f5a20 {
public:
    char pad00[0x10];
    Body_2f5a20 *body;
    char pad14[0x84];
    float px, py, pz;
    char locked;

    void FUN_002f5a20(V3_2f5a20 *target);
};
struct Vec_2f5ac0 { float x,y,z; };
struct Vec_2f5c70 { float x,y,z; };
class Helper_2f5f60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i(float*, float*, int);
};
struct Manager_2f5fe0 {
};
struct Owner_2f5fe0 {
    char pad[0x284];
    Manager_2f5fe0* mgr;
};
} // namespace fn_ff237b18
namespace physics {
struct SimCGSValue_2f60f0 {
    void *vptr;
    float value;
    int extra;
    void FUN_002ecca0();
    void FUN_002ecf20(float);
    void FUN_002ecf40(float);
};
}
namespace fn_ff237b18 {
extern int hulk_at_0043119c;
} // namespace fn_ff237b18
namespace physics {
struct SimCGSValue_2f6170 {
    void* vtable;
    float value;
    unsigned int extra;
    void Init_002ecf20(float);
    void Done_002ecca0();
};
}
namespace fn_ff237b18 {
struct Data_2f6940 {
    char p[0x68];
    float x;
};
extern int hulk_at_00431680;
class PhysicsObjectLoader {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    PhysicsObjectLoader();
};
struct Vec3_2f70a0 {
    float x, y, z;
};
struct Key_2f70a0 {
    unsigned int lo;
    unsigned int hi;
};
struct SymMatrix_2f70a0 {
    int vptr;
    float m[6];
    void FUN_002fca90();
    void FUN_002fcaa0();
};
struct Stream_2f70a0 {
    char pad[0xc];
};
struct Reader_2f70a0 {
    char pad000[0x284];
    Stream_2f70a0 *stream;                  // 0x284
    char FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
};
class Part_2f70a0 {
public:
    virtual ~Part_2f70a0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(unsigned int a, unsigned int b);
    char pad04[2];
    short f6;
    char pad08[0xe4 - 8];
    unsigned int fe4;
    void FUN_00309940(SymMatrix_2f70a0 *sm);
};
struct Props;
struct SimObject {
    char pad00[8];
    Key_2f70a0 key8;
    char pad10[0x30 - 0x10];
    Key_2f70a0 key30;
    void FUN_002fe6b0(void *world);
};
struct Composite_2f70a0 : SimObject {
    Composite_2f70a0 *FUN_00309520(Props *props, Part_2f70a0 **parts, int count);
};
struct Articulated : SimObject {
    Articulated *FUN_002f6220(Props *props, Vec3_2f70a0 *center, SymMatrix_2f70a0 *sm, unsigned int c);
};
extern "C" void __cdecl FUN_002f5fe0(void *, float *);
extern "C" Part_2f70a0 *__cdecl FUN_0030d4f0(unsigned int a, Vec3_2f70a0 *v, unsigned int b, unsigned int c);
Props *__cdecl FUN_002f2750(unsigned __int64 key);
extern "C" int __cdecl FUN_00266da0(int sel);
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
void __cdecl thunk_FUN_00267090(void *p);
extern "C" int __cdecl FUN_00267760(char *buf, int n, const char *fmt, ...);
struct Name_2f75d0 {
    char data[8];
    void FUN_0027af70(Name_2f75d0 *other);
};
struct Block16_2f75d0 {
    int w[16];
};
struct Block4_2f75d0 {
    int w[4];
};
class Obj_2f75d0;
struct Sub_2f75d0 {
    char data[0x64];
    void FUN_002f7530(Sub_2f75d0 *other);
};
class Obj_2f75d0 {
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
    virtual void Reset();
    char pad04[0x2c];
    Name_2f75d0 name;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    Block16_2f75d0 blk58;
    int f98;
    int f9c;
    int fa0;
    char b_a4;
    char pada5[0x3];
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    Block4_2f75d0 blkcc;
    char paddc[0x4];
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    char padf8[0x4];
    int ffc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    char pad114[0x4];
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    char pad130[0x18];
    char b148;
    char pad149[0x1b];
    int f164;
    Sub_2f75d0 sub;
    int f1cc;
    char b1d0;
    char pad1d1[0x3];
    int f1d4;
    float f1d8;
    int f1dc;
    float f1e0;
    int f1e4;
    int f1e8;
    char pad1ec[0x4];
    union {
        unsigned dw1f0;
        unsigned char b1f0;
    };
    char b1f4;

    void FUN_002fe6f0(Obj_2f75d0 *dst, int arg);
    void FUN_002f75d0(Obj_2f75d0 *dst, int arg);
};

} // namespace fn_ff237b18

// 0x002f5130 FUN_002f5130 (254 B): equivalent/0x002f5130.cpp [wrapped: conflict: physics::ExportInfoLoader]
// sym: _FUN_002f5130 @ddf64b3781d6 @w8659200e81f6
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_002f5130 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_002f5130 @ 0x002f5130

extern "C" void* __cdecl FUN_00263ea0(unsigned int size);


class __declspec(novtable) SimpleChunkHandler_2f5130 {
  public:
    virtual void slot0();
    int f04;
    int id;
    int f0c;
    int f10;
    SimpleChunkHandler_2f5130(int i) { f04 = 0; id = i; f0c = 0; f10 = 0; }
};

namespace physics {
class ExportInfoLoader : public SimpleChunkHandler_2f5130 {
  public:
    ExportInfoLoader() : SimpleChunkHandler_2f5130(0x7030) {}
    virtual void slot0();
    virtual void slot1_000382a0();
    virtual void* slot2_002f5110(char);
    virtual void slot3_00265ff0(int, int, int, int, int);
    virtual void slot4_0008db50();
    virtual void slot5_002f4eb0(void*, void*, void*, hulk_intptr);
};
}

struct Raw_2f5130 {
    SimpleChunkHandler_2f5130* FUN_00308020();
    SimpleChunkHandler_2f5130* FUN_00308060();
    SimpleChunkHandler_2f5130* FUN_002f7060();
    SimpleChunkHandler_2f5130* FUN_002f2c70();
};

struct Registry_2f5130 { void FUN_00265210(SimpleChunkHandler_2f5130*, int); };

extern "C" void FUN_002f5130(){
    void* mem = FUN_00263ea0(0x14);
    SimpleChunkHandler_2f5130* l = 0;
    if (mem) l = new (mem) physics::ExportInfoLoader();
    (*(Registry_2f5130**)&DAT_00527c58)->FUN_00265210(l, 0x7030);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_2f5130*)mem)->FUN_00308020() : 0;
    (*(Registry_2f5130**)&DAT_00527c58)->FUN_00265210(l, 0x7010000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_2f5130*)mem)->FUN_00308060() : 0;
    (*(Registry_2f5130**)&DAT_00527c58)->FUN_00265210(l, 0x7010025);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_2f5130*)mem)->FUN_002f7060() : 0;
    (*(Registry_2f5130**)&DAT_00527c58)->FUN_00265210(l, 0x7011000);
    mem = FUN_00263ea0(0x14);
    l = mem ? ((Raw_2f5130*)mem)->FUN_002f2c70() : 0;
    (*(Registry_2f5130**)&DAT_00527c58)->FUN_00265210(l, 0x7011010);
}
} // namespace fn_002f5130


// 0x002f5360 physics::PhysicsObject::vfunc_27 (48 B): matches/0x002f5360.cpp
// sym: ?vfunc_27@PhysicsObject@physics@@UAEXH@Z
void physics::PhysicsObject::vfunc_27(int x) {
    this->f_154 = 0;
    this->f_150 = 0;
    this->f_14c = 0;
    this->f_160 = 0;
    this->f_15c = 0;
    this->f_158 = 0;
    this->f_148 = 1;
}

namespace fn_ff237b18 {

// 0x002f5400 FUN_002f5400 (31 B): equivalent/0x002f5400.cpp
// sym: ?FUN_002f5400@fn_ff237b18@@YAXXZ @a4ae9a9a8c29 @w09e53dc03c43
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002f5400 @ 0x002f5400
void FUN_002f5400() {
    (*(int*)&DAT_00555450) = 0;
    (*(int*)&DAT_00555454) = 0;
    (*(int*)&DAT_00555458) = 0;
}


// 0x002f5460 physics::SymMatrix::vfunc_0 (30 B): matches/0x002f5460.cpp
// sym: ?vfunc_2@SymMatrix_2f5460@fn_ff237b18@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
SymMatrix_2f5460* SymMatrix_2f5460::vfunc_2(unsigned char flags) {
    FUN_002fcaa0((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_ff237b18

// 0x002f5480 FUN_002f5480 (230 B): equivalent/0x002f5480.cpp [wrapped: conflict: physics::PhysicsObject]
// sym: ??0PhysicsObject@physics@fn_002f5480@@QAE@XZ @2463b2525c8b @w9b7887c438bc
namespace fn_002f5480 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002f5480 @ 0x002f5480

struct Part30_2f5480 { char data[0xac]; void FUN_0027af00(); };
struct SymMatrix_2f5480 { char data[0x1c]; void FUN_002fca90(); };
struct SimpleFilterAbs3D_2f5480 { char data[0x6c]; void FUN_00308cc0(); };
struct FUN_002fe640 {
 virtual void slot0();
 char pad04[0x20];
 unsigned int field24;
 char pad28[8];
 FUN_002fe640();
};
namespace physics {
struct PhysicsObject : FUN_002fe640 {
 virtual void slot0();
 Part30_2f5480 part30;
 SymMatrix_2f5480 partdc, partf8, part114;
 char pad130[0x38];
 SimpleFilterAbs3D_2f5480 part168;
 unsigned int field1d4;
 float field1d8;
 unsigned int field1dc;
 float field1e0, field1e4, field1e8;
 unsigned int field1ec, field1f0;
 unsigned char field1f4;
 PhysicsObject();
};
PhysicsObject::PhysicsObject() {
 part30.FUN_0027af00();
 partdc.FUN_002fca90();
 partf8.FUN_002fca90();
 part114.FUN_002fca90();
 part168.FUN_00308cc0();
 field1d4=0;
 field1d8=1.0f / (double)(*(unsigned int*)&DAT_004d2b74);
 field1dc=0;
 field1e0=1.0f / (double)(*(unsigned int*)&DAT_004d2b74);
 field1e4=(*(float*)&DAT_004d2b80);
 field1e8=(*(float*)&DAT_004d2b7c);
 field1f0 &= 0xffffff00;
 field1ec=0;
 field24=0;
 field1f0 |= 0xff00;
 field1f4 |= 3;
}
}
} // namespace fn_002f5480

namespace fn_ff237b18 {

// 0x002f5570 physics::SimulatedObject::vfunc_16 (3 B): matches/0x002f5570.cpp
// sym: ?GetZero@fn_ff237b18@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_ff237b18

// 0x002f5580 physics::SimulatedObject::vfunc_23 (3 B): matches/0x002f5580.cpp
// sym: ?vfunc_23@SimulatedObject@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::SimulatedObject::vfunc_23(int a, int b) {}


// 0x002f5590 physics::SimulatedObject::vfunc_24 (5 B): matches/0x002f5590.cpp
// sym: ?vfunc_24@SimulatedObject@physics@@UAE_NHHH@Z
// Same code shape as 0x0023d2e0 (propagated; names are from that function)
 // namespace fight
bool physics::SimulatedObject::vfunc_24(hulk_intptr , hulk_intptr , int ) {
    return false;
}


// 0x002f55a0 physics::SimulatedObject::vfunc_29 (10 B): matches/0x002f55a0.cpp
// sym: ?vfunc_29@SimulatedObject@physics@@UAEXH@Z
// Same code shape as 0x00083d20 (propagated; names are from that function)
void physics::SimulatedObject::vfunc_29(int x) {
    this->f_10 = x;
}


// 0x002f55b0 physics::PhysicsObject::vfunc_9 (18 B): matches/0x002f55b0.cpp
// sym: ?vfunc_9@PhysicsObject@physics@@UAEXH@Z
 // namespace physics
void physics::PhysicsObject::vfunc_9(int a0) {
    (*(char *)&this->f_1c4) = 1;
    ((Part_2f55b0*)((char*)this + 0x168))->work_00308ba0(a0);
}


// 0x002f55d0 physics::PhysicsObject::vfunc_11 (11 B): matches/0x002f55d0.cpp
// sym: ?vfunc_11@PhysicsObject@physics@@UAEEXZ
unsigned char physics::PhysicsObject::vfunc_11() {
    volatile unsigned char* p = &this->f_1f4;
    unsigned char x = *p;
    x >>= 1;
    x &= 1;
    return x;
}

namespace fn_ff237b18 {

// 0x002f55e0 physics::PhysicsObject::vfunc_10 (8 B): matches/0x002f55e0.cpp
// sym: ?vfunc_10@PhysicsObject@fn_ff237b18@@QAEXXZ
void PhysicsObject::vfunc_10() {
    pad[0x1c4] = 1;
}

} // namespace fn_ff237b18

// 0x002f55f0 physics::PhysicsObject::vfunc_17 (10 B): matches/0x002f55f0.cpp
// sym: ?vfunc_17@PhysicsObject@physics@@UAEXHHHHH@Z
void physics::PhysicsObject::vfunc_17(int , int , int , int , int ) {
    (*(char *)&this->f_148) = 1;
}


// 0x002f5600 physics::PhysicsObject::vfunc_26 (9 B): matches/0x002f5600.cpp [wrapped: conflict: physics::PhysicsObject]
// sym: ?vfunc_26@PhysicsObject@physics@fn_002f5600@@UAEEH@Z
namespace fn_002f5600 {
namespace physics {
class PhysicsObject {
  public:
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
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual unsigned char vfunc_26(int);
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    char pad[0x144];
    unsigned char value;
};
unsigned char PhysicsObject::vfunc_26(int) {
    return value;
}
} // namespace physics
} // namespace fn_002f5600


// 0x002f5610 physics::PhysicsObject::vfunc_34 (5 B): matches/0x002f5610.cpp
// sym: ?vfunc_34@PhysicsObject@physics@@UAE_NPAX@Z
// Same code shape as 0x00013980 (propagated; names are from that function)
bool physics::PhysicsObject::vfunc_34(void* __p0) {
    return true;
}


// 0x002f5620 physics::PhysicsObject::vfunc_36 (4 B): matches/0x002f5620.cpp
// sym: ?vfunc_36@PhysicsObject@physics@@UAEMXZ
 // namespace physics
hulk_freg physics::PhysicsObject::vfunc_36() {
    return this->f_40;
}


// 0x002f5630 physics::PhysicsObject::vfunc_21 (4 B): matches/0x002f5630.cpp
// sym: ?vfunc_21@PhysicsObject@physics@@UAEMXZ
// Same code shape as 0x00069110 (propagated; names are from that function)
hulk_freg physics::PhysicsObject::vfunc_21() {
    return *(float*)((char*)&this->f_44);
}


// 0x002f5640 FUN_002f5640 (69 B): matches/0x002f5640.cpp [wrapped: conflict: PhysicsObject]
// sym: ?Setup@PhysicsObject@fn_002f5640@@QAEXXZ
namespace fn_002f5640 {
extern "C" char DAT_004315dc[];
class Big_2f5640 {
  public:
    void Init_00308a60();
};
class SymMatrix_2f5640 {
  public:
    void Init_002fcaa0();
};
class Base_2f5640 {
  public:
    void Init_0027af50();
};
class PhysicsObject {
  public:
    void* vt;
    char pad[0x168 - 4];
    void Finish_002fe680();
    void Setup();
};
void PhysicsObject::Setup() {
    vt = (void*)((hulk_intptr)DAT_004315dc);
    ((Big_2f5640*)((char*)this + 0x168))->Init_00308a60();
    ((SymMatrix_2f5640*)((char*)this + 0x114))->Init_002fcaa0();
    ((SymMatrix_2f5640*)((char*)this + 0xf8))->Init_002fcaa0();
    ((SymMatrix_2f5640*)((char*)this + 0xdc))->Init_002fcaa0();
    ((Base_2f5640*)((char*)this + 0x30))->Init_0027af50();
    Finish_002fe680();
}
} // namespace fn_002f5640


// 0x002f56b0 physics::PhysicsObject::vfunc_6 (286 B): equivalent/0x002f56b0.cpp [wrapped: conflict: physics::PhysicsObject]
// sym: ?vfunc_6@PhysicsObject@physics@fn_002f56b0@@UAEXE@Z @d41db7686f43 @we44ff0b31aa6
namespace fn_002f56b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::PhysicsObject::vfunc_6 @ 0x002f56b0
struct Vec_2f56b0 { float x,y,z; };
struct Matrix { unsigned int words[16]; void FUN_0022c1b0(); void FUN_0022b9f0(); void FUN_0022c2b0(Vec_2f56b0*,Vec_2f56b0*); };
struct Bounds_2f56b0 { char data[44]; void FUN_0022b370(Matrix*); };
struct Filter_2f56b0 { void FUN_002fd020(Vec_2f56b0*,Vec_2f56b0*); };
struct Body_2f56b0 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
 char pad[12]; Matrix transform; char pad50[12]; Vec_2f56b0 velocity; unsigned int scaleBits;
};
namespace physics {
struct PhysicsObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(unsigned char reset);
 virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(unsigned int); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
 char pad04[12]; Body_2f56b0* body; char pad14[44]; unsigned int value40; char pad44[20]; Matrix inverse; Vec_2f56b0 position; unsigned char useTranslation; char padA5[3]; Vec_2f56b0 offset; Vec_2f56b0 adjustment; Vec_2f56b0 velocity; Bounds_2f56b0 bounds; Filter_2f56b0 filter;
};
void PhysicsObject::vfunc_6(unsigned char reset) {
 Body_2f56b0* source=body;
 for(int i=0;i<16;++i) inverse.words[i]=source->transform.words[i];
 if(source->scaleBits!=0x3f800000) inverse.FUN_0022c1b0();
 inverse.FUN_0022b9f0();
 vfunc_39();
 bounds.FUN_0022b370(&inverse);
 if(useTranslation) {
 position = *reinterpret_cast<Vec_2f56b0*>(&body->transform.words[12]);
 } else {
 Vec_2f56b0 sum;
 sum.x=offset.x+adjustment.x;
 sum.y=offset.y+adjustment.y;
 sum.z=offset.z+adjustment.z;
 body->transform.FUN_0022c2b0(&sum,&position);
 }
 if(reset) {
 vfunc_37();
 velocity.z=0.0f; velocity.y=0.0f; velocity.x=0.0f;
 body->s7();
 } else filter.FUN_002fd020(&body->velocity,&velocity);
 vfunc_35(value40);
}
}
} // namespace fn_002f56b0

namespace fn_ff237b18 {

// 0x002f57d0 FUN_002f57d0 (140 B): equivalent/0x002f57d0.cpp
// sym: ?FUN_002f57d0@Node@fn_ff237b18@@QAEXPBUVec3_2f57d0@2@@Z @de77401e454e @w1ff390788d62
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002f57d0 @ 0x002f57d0
// Store a new target offset and note whether it is (nearly) zero; if a listener is attached, notify it.
void Node::FUN_002f57d0(const Vec3_2f57d0* offset)
{
    target = *offset;
    float x = target.x + base.x;
    float y = base.y + target.y;
    float z = base.z + target.z;
    nearZero = (z * z + y * y + x * x < 1e-05f);
    if (listener) {
        Notify(0);
    }
}

} // namespace fn_ff237b18

// 0x002f5860 physics::PhysicsObject::vfunc_8 (8 B): matches/0x002f5860.cpp [wrapped: same definition as 0x002f55e0 in this TU]
// sym: ?vfunc_10@PhysicsObject@fn_002f5860@@QAEXXZ
namespace fn_002f5860 {
// Same code shape as 0x002f55e0 (propagated; names are from that function)
class PhysicsObject {
    char pad[0x1c4];

  public:
    void vfunc_10();
};
void PhysicsObject::vfunc_10() {
    pad[0x1c4] = 1;
}
} // namespace fn_002f5860


// 0x002f5870 physics::PhysicsObject::vfunc_7 (105 B): matches/0x002f5870.cpp
// sym: ?vfunc_7@PhysicsObject@physics@@UAEXXZ
void physics::PhysicsObject::vfunc_7() {
    if (this->f_3c > DAT_003f32e0) {
        float old = this->f_40;
        // x87: the reciprocal is taken of the product still in its register (53 bits), not of the stored f_40
        hulk_freg p = *(float*)((char*)this->f_18 + 0xc) * this->f_3c;
        ((owners::X_2fcb80 *)(((Elem_2f5870*)((char*)this + 0xdc))))->FUN_002fcb80(((this->f_40 = p), (this->f_44 = DAT_003f32dc / p), *(volatile float*)&this->f_40) / old);
        vfunc_39();
        *((char*)&this->f_1c4) = 1;
    } else {
        this->f_40 = 0.0f;
        this->f_44 = 0.0f;
        *((char*)&this->f_1c4) = 1;
    }
}


// 0x002f58e0 physics::PhysicsObject::vfunc_12 (272 B): equivalent/0x002f58e0.cpp [wrapped: conflict: physics::PhysicsObject]
// sym: ?vfunc_12@PhysicsObject@physics@fn_002f58e0@@UAE_NH@Z @413050a3e4bb @wa1d2babc9d06
namespace fn_002f58e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// physics::PhysicsObject::vfunc_12 @ 0x002f58e0

struct Motion_2f58e0 { char pad[0x50]; float vx,vy,vz,wx,wy,wz; };
namespace physics {
struct PhysicsObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual bool vfunc_11(); virtual bool vfunc_12(int);
 char pad04[12]; Motion_2f58e0* motion; char pad14[12]; unsigned char active; char pad21[0x1cc-0x21]; float value; char pad1d0[4]; float linearAverage,linearWeight,angularAverage,angularWeight,linearThreshold,angularThreshold; char pad1ec[4]; unsigned char countdown; char pad1f1[3]; unsigned char flags;
};
bool PhysicsObject::vfunc_12(int) {
 if(active && !vfunc_11() && value < DAT_00555454) {
 Motion_2f58e0* m=motion;
 double angular=(double)m->wx*m->wx+(double)m->wy*m->wy+(double)m->wz*m->wz;
 double linear=((double)m->vx*m->vx+(double)m->vy*m->vy+(double)m->vz*m->vz)*linearWeight+(1.0-(double)linearWeight)*linearAverage;
 linearAverage=(float)linear;
 double filteredAngular=(1.0-(double)angularWeight)*angularAverage+angular*angularWeight;
 angularAverage=(float)filteredAngular;
 if(countdown) --countdown;
 else if((float)linear < linearThreshold && filteredAngular < angularThreshold) flags |= 2;
 }
 return (flags >> 1)&1;
}
}
} // namespace fn_002f58e0


// 0x002f59f0 physics::PhysicsObject::vfunc_13 (33 B): matches/0x002f59f0.cpp
// sym: ?vfunc_13@PhysicsObject@physics@@UAEXXZ
// data: global_4d2b78 = DAT_004d2b78
void physics::PhysicsObject::vfunc_13() {
    *((char*)&this->f_1f4) &= 0xfd;
    *((u32_2f59f0*)this + 0x75) = 0;
    *((u32_2f59f0*)this + 0x77) = 0;
    *((char*)&this->f_1f0) = (*(u8*)&DAT_004d2b78);
}

namespace fn_ff237b18 {

// 0x002f5a20 FUN_002f5a20 (157 B): equivalent/0x002f5a20.cpp
// sym: ?FUN_002f5a20@PhysicsObject_2f5a20@fn_ff237b18@@QAEXPAUV3_2f5a20@2@@Z @f0c347abbf39 @w36c58057e742
// STATUS: equivalent (tools/equiv.py level 3: 19923 inputs, branch coverage 2/2)
// FUN_002f5a20 @ 0x002f5a20
// FUN_002f5a20: move the pivot (or, when free, the cross product of the offset and the axis) onto a position
void PhysicsObject_2f5a20::FUN_002f5a20(V3_2f5a20 *target)
{
    Body_2f5a20 *b = body;
    if (locked) {
        b->pos = *target;
        return;
    }
    // x87: the differences and cz stay in registers (53 bits); cx and cy are rounded frame copies
    hulk_freg dx = b->x - px;
    hulk_freg dy = b->y - py;
    hulk_freg dz = b->z - pz;
    volatile float cx = dz * b->ay - dy * b->az;
    volatile float cy = dx * b->az - dz * b->ax;
    hulk_freg cz = dy * b->ax - dx * b->ay;
    b->pos.x = cx + target->x;
    b->pos.y = cy + target->y;
    b->pos.z = cz + target->z;
}

} // namespace fn_ff237b18

// 0x002f5ac0 physics::PhysicsObject::vfunc_32 (198 B): equivalent/0x002f5ac0.cpp
// sym: ?vfunc_32@PhysicsObject@physics@@UAEXHH@Z @33e0a108143e @w446f3bda3a3c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// physics::PhysicsObject::vfunc_32 @ 0x002f5ac0
void physics::PhysicsObject::vfunc_32(hulk_intptr __p0, hulk_intptr __p1) { Vec_2f5ac0 * f = (Vec_2f5ac0 *)__p0; Vec_2f5ac0 * p = (Vec_2f5ac0 *)__p1;

(*(Vec_2f5ac0 *)&this->f_130).x += f->x; (*(Vec_2f5ac0 *)&this->f_130).y += f->y; (*(Vec_2f5ac0 *)&this->f_130).z += f->z;
if(p) {
 double x=(double)p->x-(*(Vec_2f5ac0 *)&this->f_98).x, y=(double)p->y-(*(Vec_2f5ac0 *)&this->f_98).y, z=(double)p->z-(*(Vec_2f5ac0 *)&this->f_98).z;
 float ty=(float)(z*f->x-x*f->z);
 float tz=(float)(x*f->y-y*f->x);
 (*(Vec_2f5ac0 *)&this->f_13c).x=(float)(y*f->z-z*f->y+(*(Vec_2f5ac0 *)&this->f_13c).x);
 (*(Vec_2f5ac0 *)&this->f_13c).y += ty; (*(Vec_2f5ac0 *)&this->f_13c).z += tz; (*(unsigned char *)&this->f_1d0)=1;
}
if(vfunc_11()) vfunc_13();
}


// 0x002f5b90 physics::PhysicsObject::vfunc_33 (78 B): equivalent/0x002f5b90.cpp
// sym: ?vfunc_33@PhysicsObject@physics@@UAEXH@Z @b680ccdc717a @w608f004eabc4
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 2/2)
// physics::PhysicsObject::vfunc_33 @ 0x002f5b90
void physics::PhysicsObject::vfunc_33(hulk_intptr __p0) { const float * delta = (const float *)__p0;
 (*(float *)&this->f_13c) += delta[0]; (*(float *)&this->f_140) += delta[1]; (*(float *)&this->f_144) += delta[2]; (*(unsigned char *)&this->f_1d0) = 1; if (vfunc_11()) vfunc_13(); }


// 0x002f5be0 physics::PhysicsObject::vfunc_39 (93 B): matches/0x002f5be0.cpp [wrapped: conflict: PhysicsObject]
// sym: ?vfunc_39@PhysicsObject@fn_002f5be0@@UAEXXZ
namespace fn_002f5be0 {
class BlockA {
  public:
    int m_x;
    int m_y;
    int m_data[5];
    void Set_002fcd60(void* p);
};

class BlockB {
  public:
};

class PhysicsObject {
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vfunc_39();

    char pad1[0x54];
    int m_58;
    char pad2[0x84];
    int m_e0;
    int m_src[5];
    BlockA m_blockA;
    BlockB m_blockB;
};

void PhysicsObject::vfunc_39() {
    m_blockA.m_y = m_e0;
    int* ps = &m_src[0];
    BlockA* p = &m_blockA;
    p->m_data[0] = ps[0];
    p->m_data[1] = ps[1];
    p->m_data[2] = ps[2];
    p->m_data[3] = ps[3];
    p->m_data[4] = ps[4];
    p->Set_002fcd60(&m_58);
    ((owners::Sym3_2fd0c0 *)&m_blockB)->FUN_002fd0c0((const owners::Sym3_2fd0c0 *)(BlockA *)p);
}
} // namespace fn_002f5be0


// 0x002f5c40 physics::PhysicsObject::vfunc_37 (45 B): matches/0x002f5c40.cpp
// sym: ?vfunc_37@PhysicsObject@physics@@UAEXXZ
void physics::PhysicsObject::vfunc_37() {
    (*(volatile int *)&this->f_138) = 0;
    (*(volatile int *)&this->f_134) = 0;
    (*(volatile int *)&this->f_130) = 0;
    (*(volatile int *)&this->f_144) = 0;
    (*(volatile int *)&this->f_140) = 0;
    (*(volatile int *)&this->f_13c) = 0;
    (*(volatile char *)&this->f_1d0) = 0;
}


// 0x002f5c70 physics::PhysicsObject::vfunc_18 (175 B): equivalent/0x002f5c70.cpp
// sym: ?vfunc_18@PhysicsObject@physics@@UAE_NHHHHHH@Z @a9f15ee65bae @w2e63e8d886d7
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 0/0)
// physics::PhysicsObject::vfunc_18 @ 0x002f5c70
bool physics::PhysicsObject::vfunc_18(hulk_intptr __p0, hulk_intptr __p1, int __p2, int __p3, int __p4, int __p5) { const Vec_2f5c70 * point = (const Vec_2f5c70 *)__p0; const Vec_2f5c70 * force = (const Vec_2f5c70 *)__p1; unsigned int a = (unsigned int)__p2; unsigned int b = (unsigned int)__p3; unsigned int c = (unsigned int)__p4; unsigned int d = (unsigned int)__p5;

 float scale=this->f_44;
 this->f_148=0;
 (*(Vec_2f5c70 *)&this->f_14c).x=scale*force->x;
 (*(Vec_2f5c70 *)&this->f_14c).y=scale*force->y;
 (*(Vec_2f5c70 *)&this->f_14c).z=scale*force->z;
 (*(Vec_2f5c70 *)&this->f_158).x=point->x-(*(Vec_2f5c70 *)&this->f_98).x;
 (*(Vec_2f5c70 *)&this->f_158).y=point->y-(*(Vec_2f5c70 *)&this->f_98).y;
 (*(Vec_2f5c70 *)&this->f_158).z=point->z-(*(Vec_2f5c70 *)&this->f_98).z;
 double az=*(volatile float*)&(*(Vec_2f5c70 *)&this->f_158).z; // the original reads the rounded member back
 double y=(double)force->x*az-(double)(*(Vec_2f5c70 *)&this->f_158).x*force->z;
 double z=(double)force->y*(*(Vec_2f5c70 *)&this->f_158).x-(double)force->x*(*(Vec_2f5c70 *)&this->f_158).y;
 double x=(double)(*(Vec_2f5c70 *)&this->f_158).y*force->z-(double)force->y*az;
 (*(Vec_2f5c70 *)&this->f_158).x=(float)x;
 (*(Vec_2f5c70 *)&this->f_158).y=(float)y;
 (*(Vec_2f5c70 *)&this->f_158).z=(float)z;
 return true;
}


// 0x002f5d20 physics::PhysicsObject::vfunc_25 (73 B): matches/0x002f5d20.cpp [wrapped: conflict: PhysicsObject]
// sym: ?vfunc_25@PhysicsObject@fn_002f5d20@@QAE_NPAKKK@Z
namespace fn_002f5d20 {
class Sub_2f5d20 {
  public:
    char pad[0x34];
};
class PhysicsObject {
  public:
    virtual void dummy();
    char pad[0x114 - 4];
    Sub_2f5d20 sub;
    unsigned char flag;
    unsigned long a, b, c;
    bool vfunc_25(unsigned long* out, unsigned long arg, unsigned long unused);
};
bool PhysicsObject::vfunc_25(unsigned long* out, unsigned long arg, unsigned long unused) {
    if (flag)
        return false;
    out[0] = a;
    out[1] = b;
    out[2] = c;
    ((owners::Transform_2fd020 *)&sub)->FUN_002fd020((float *)((char*)this + 0x158), (float *)(hulk_uintptr)(unsigned long)arg);
    return true;
}
} // namespace fn_002f5d20


// 0x002f5d70 physics::PhysicsObject::vfunc_35 (50 B): matches/0x002f5d70.cpp
// sym: ?vfunc_35@PhysicsObject@physics@@UAEXM@Z
 // namespace physics
void physics::PhysicsObject::vfunc_35(float x) {
    this->f_40 = x;
    if (x > 0.0f)
        this->f_44 = 1.0f / x;
    else
        this->f_44 = 0.0f;
}


// 0x002f5db0 physics::PhysicsObject::vfunc_19 (272 B): equivalent/0x002f5db0.cpp [wrapped: conflict: physics::PhysicsObject]
// sym: ?vfunc_19@PhysicsObject@physics@fn_002f5db0@@UAEXHHH@Z @0f4c20d804c6 @w2a60e0f22ad7
namespace fn_002f5db0 {
// STATUS: equivalent (tools/equiv.py level 3: 19979 inputs, branch coverage 4/4)
// physics::PhysicsObject::vfunc_19 @ 0x002f5db0
struct Vec_2f5db0 { float x,y,z; };
struct Matrix { char pad[0x24]; void FUN_002fd020(Vec_2f5db0*,Vec_2f5db0*); };
struct State_2f5db0 { char pad[0x40]; Vec_2f5db0 position; char gap[4]; Vec_2f5db0 velocity; Vec_2f5db0 result; };
namespace physics {
struct PhysicsObject {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual bool vfunc_11(); virtual void v12(); virtual void vfunc_13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void vfunc_19(int,int,int);
 char p4[12]; State_2f5db0* state; char p14[0x84]; Vec_2f5db0 position; char pa4[0x1c]; Vec_2f5db0 angular; char pcc[0x48]; Matrix matrix; char p138[0x10]; unsigned char applied; char p149[3]; Vec_2f5db0 linearImpulse; Vec_2f5db0 angularImpulse; char p164[0x68]; int pending;
};
void PhysicsObject::vfunc_19(int,int,int) {
 if (!applied) {
  if(vfunc_11()) vfunc_13();
  Vec_2f5db0 transformed; matrix.FUN_002fd020(&angularImpulse,&transformed);
  State_2f5db0* s=state;
  double dx=position.x-s->position.x;
  double dy=position.y-s->position.y;
  double dz=position.z-s->position.z;
  volatile float cx=dy*transformed.z-dz*transformed.y;
  volatile float cy=dz*transformed.x-dx*transformed.z;
  hulk_freg cz=dx*transformed.y-dy*transformed.x;
  double vx=cx+linearImpulse.x; // stays in a register (unrounded) in the original
  volatile float vy=cy+linearImpulse.y;
  volatile float vz=cz+linearImpulse.z;
  s->velocity.x=vx+s->velocity.x;
  s->velocity.y=vy+s->velocity.y;
  s->velocity.z=vz+s->velocity.z;
  angular.x=angular.x+angularImpulse.x;
  angular.y=angularImpulse.y+angular.y;
  angular.z=angularImpulse.z+angular.z;
  matrix.FUN_002fd020(&angular,&state->result);
  pending=0;
 }
 applied=1;
}
}
} // namespace fn_002f5db0


// 0x002f5ec0 physics::PhysicsObject::vfunc_20 (154 B): matches/0x002f5ec0.cpp [wrapped: conflict: PhysicsObject]
// sym: ?f20@PhysicsObject@fn_002f5ec0@@UAEXPAMPAUOut_2f5ec0@2@HHH@Z
namespace fn_002f5ec0 {
struct Out_2f5ec0 {
    char pad[4];
    float a, b, c, d, e, f;
};
class Helper_2f5ec0 {
  public:
    void Transform_002fcf30(float*);
};
class PhysicsObject {
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
    virtual void f20(float*, Out_2f5ec0*, int, int, int);
    char pad[0x44 - 4];
    float offset;
    char pad2[0x98 - 0x48];
    float x, y, z;
    char pad3[0x118 - 0xa4];
    unsigned int m0, m1, m2, m3, m4, m5;
};
void PhysicsObject::f20(float* p, Out_2f5ec0* out, int, int, int) {
    float t[3];
    t[0] = p[0] - x;
    t[1] = p[1] - y;
    t[2] = p[2] - z;
    out->a = *(float*)&m0;
    out->b = *(float*)&m1;
    out->c = *(float*)&m2;
    out->d = *(float*)&m3;
    out->e = *(float*)&m4;
    out->f = *(float*)&m5;
    ((Helper_2f5ec0*)out)->Transform_002fcf30(t);
    out->a = offset + out->a;
    out->d = offset + out->d;
    out->f = out->f + offset;
}
} // namespace fn_002f5ec0


// 0x002f5f60 physics::PhysicsObject::vfunc_31 (90 B): matches/0x002f5f60.cpp
// sym: ?vfunc_31@PhysicsObject@physics@@UAEMXZ
hulk_freg physics::PhysicsObject::vfunc_31() {
    float t[3];
    if (vfunc_11()) {
        (*(class Helper_2f5f60 * *)&this->f_10)->i((*(float (*)[3])&this->f_98), t, -1);
        return (t[1] * t[1] + (t[0] * t[0] + t[2] * t[2])) * this->f_40 * 0.5f;
    }
    return 0.0f;
}

namespace fn_ff237b18 {

// 0x002f5fe0 FUN_002f5fe0 (187 B): matches/0x002f5fe0.cpp
// sym: _FUN_002f5fe0
extern "C" void __cdecl FUN_002f5fe0(void * owner, float* dst) {
    float value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[1] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[2] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[3] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[4] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[5] = value;
    ((owners::X_2647e0 *)(((Owner_2f5fe0 *)owner)->mgr))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
    dst[6] = value;
}

} // namespace fn_ff237b18

// 0x002f60d0 physics::PhysicsObject::vfunc_14 (22 B): matches/0x002f60d0.cpp [wrapped: conflict: PhysicsObject]
// sym: ?vfunc_14@PhysicsObject@fn_002f60d0@@UAEMXZ
namespace fn_002f60d0 {
class SimulatedObject {
  public:
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
    virtual float vfunc_14();
};
class PhysicsObject : public SimulatedObject {
  public:
    char pad[0x1a8 - 4];
    float value;
    char pad2[0x1c4 - 0x1ac];
    unsigned char flag;
    float vfunc_14();
};
float PhysicsObject::vfunc_14() {
    if (flag)
        return SimulatedObject::vfunc_14();
    return value;
}
} // namespace fn_002f60d0


// 0x002f60f0 physics::SimulatedObject::vfunc_14 (91 B): equivalent/0x002f60f0.cpp
// sym: ?vfunc_14@SimulatedObject@physics@@UAEMXZ @7bf6d3859ce0 @w7eb6c300af0f
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::SimulatedObject::vfunc_14 @ 0x002f60f0
hulk_freg physics::SimulatedObject::vfunc_14() {
    SimCGSValue_2f60f0 numerator;
    numerator.FUN_002ecf20(0.1f);
    SimCGSValue_2f60f0 denominator;
    denominator.FUN_002ecf40(1.0f);
    float a = numerator.value;
    float b = denominator.value;
    numerator.FUN_002ecca0();
    denominator.FUN_002ecca0();
    return a / b;
}


// 0x002f6150 physics::PhysicsObject::vfunc_15 (22 B): matches/0x002f6150.cpp [wrapped: conflict: PhysicsObject]
// sym: ?vfunc_15@PhysicsObject@fn_002f6150@@QAEMXZ
namespace fn_002f6150 {
class SimulatedObject {
  public:
    virtual float v0();
    virtual float v1();
    virtual float v2();
    virtual float v3();
    virtual float v4();
    virtual float v5();
    virtual float v6();
    virtual float v7();
    virtual float v8();
    virtual float v9();
    virtual float v10();
    virtual float v11();
    virtual float v12();
    virtual float v13();
    virtual float v14();
    virtual float v15();
};
class PhysicsObject : public SimulatedObject {
  public:
    char pad[0x1a8];
    float value;
    char pad2[0x14];
    unsigned char flag;
    float vfunc_15();
};
float PhysicsObject::vfunc_15() {
    if (flag)
        return SimulatedObject::v15();
    return value;
}
} // namespace fn_002f6150


// 0x002f6170 physics::SimulatedObject::vfunc_15 (69 B): matches/0x002f6170.cpp
// sym: ?vfunc_15@SimulatedObject@physics@@UAEMXZ
 // namespace physics
hulk_freg physics::SimulatedObject::vfunc_15() {
    SimCGSValue_2f6170 value;
    value.Init_002ecf20(10.0f);
    float denom = value.value;
    float result = vfunc_14() / denom;
    value.vtable = &hulk_at_0043119c;
    value.Done_002ecca0();
    return result;
}


// 0x002f61c0 physics::PhysicsObject::vfunc_2 (90 B): matches/0x002f61c0.cpp [wrapped: conflict: PhysicsObject]
// sym: ??0PhysicsObject@fn_002f61c0@@QAE@E@Z
namespace fn_002f61c0 {
class PhysicsObject {
  public:
    virtual void f0_00038290();
    virtual void f1_000382a0();
    virtual void* f2_002f61c0(char);
    virtual void f3_0027afe0();
    virtual void f4_0027aff0();
    virtual void f5_002f6960(float);
    virtual void f6_002f56b0(char);
    virtual void f7_002f5870();
    virtual void f8_002f5860();
    virtual void f9_002f55b0(int);
    virtual void f10_002f55e0();
    virtual void f11_002f55d0();
    virtual bool f12_002f58e0(int);
    virtual void f13_002f59f0();
    virtual void f14_002f60d0();
    virtual void f15_002f6150();
    virtual void f16();
    virtual void f17_002f55f0(int, int, int, int, int);
    virtual bool f18_002f5c70(hulk_intptr, hulk_intptr, int, int, int, int);
    virtual void f19_002f5db0(int, int, int);
    virtual void f20_002f5ec0(void*, void*, int, int, int);
    virtual void f21_002f5630();
    virtual void f22_002fe6e0(int, int, int, int, int, int);
    virtual void f23_002f5580(int, int);
    virtual bool f24_002f5590(hulk_intptr, hulk_intptr, int);
    virtual bool f25_002f5d20(void*, int, int);
    virtual char f26_002f5600(int);
    virtual void f27_002f5360(int);
    virtual void* f28_002f78c0(int);
    virtual void f29_002f55a0(int);
    virtual void f30_002f6940();
    virtual void f31_002f5f60();
    virtual void f32_002f5ac0(hulk_intptr, hulk_intptr);
    virtual void f33_002f5b90(hulk_intptr);
    virtual bool f34_002f5610(void*);
    virtual void f35_002f5d70(float);
    virtual void f36_002f5620();
    virtual void f37_002f5c40();
    virtual void f38_002f6af0(float);
    virtual void f39_002f5be0();
    PhysicsObject(unsigned char);
    void finish_002fe680();
};
struct A_2f61c0 {
    void Fna_00308a60();
};
struct SymMatrix_2f61c0 {
    void Fnb_002fcaa0();
};
struct C_2f61c0 {
    void Fnc_002fcaa0();
};
struct D {
    void Fnd_002fcaa0();
};
struct E_2f61c0 {
    void Fne_0027af50();
};
extern void destroy_00263f30(PhysicsObject*);
PhysicsObject::PhysicsObject(unsigned char flag) {
    ((A_2f61c0*)((char*)this + 0x168))->Fna_00308a60();
    ((SymMatrix_2f61c0*)((char*)this + 0x114))->Fnb_002fcaa0();
    ((C_2f61c0*)((char*)this + 0xf8))->Fnc_002fcaa0();
    ((D*)((char*)this + 0xdc))->Fnd_002fcaa0();
    ((E_2f61c0*)((char*)this + 0x30))->Fne_0027af50();
    finish_002fe680();
    if (flag & 1)
        destroy_00263f30(this);
}
} // namespace fn_002f61c0


// 0x002f6220 FUN_002f6220 (966 B): equivalent/0x002f6220.cpp [wrapped: conflict: physics::PhysicsObject; physics::SimCGSValue; physics::SimLength; physics::SimTime (+3)]
// sym: ??0PhysicsObject@physics@fn_002f6220@@QAE@HPAUV3_2f6220@2@PAVSymMatrix@12@H@Z @1e8573166258 @w5d49a836bfb5
namespace fn_002f6220 {
// STATUS: equivalent (tools/equiv.py level 3: 20012 inputs, branch coverage 10/10)
// FUN_002f6220 @ 0x002f6220
// equiv-map: ??0SymMatrix@physics@@QAE@XZ = 0x002fca90
// equiv-map: ??0SimulatedObject@physics@@QAE@H@Z = 0x002fe570
// equiv-map: ??0SimTime@physics@@QAE@M@Z = 0x002ecf40
// equiv-map: ??0SimLength@physics@@QAE@M@Z = 0x002ecf20
// equiv-map: ??1SimUnits@physics@@UAE@XZ = 0x002ecca0




struct V3_2f6220 {
    float x, y, z;
};

struct Id64_2f6220 {
    int lo, hi;
    void FUN_0027af00() throw();
};

struct Matrix {
    float m[16];
    void FUN_0022b980() throw();
};


struct SimpleFilterAbs3D_2f6220 {
    char data[0x64];
    void FUN_00308cc0() throw();
    void FUN_00308a70(void *owner) throw();
};

namespace physics {

class SimUnits {
public:
    virtual ~SimUnits() throw();
};

class SimCGSValue : public SimUnits {
public:
    virtual void vfunc_1(float v) throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual ~SimCGSValue() throw() {}
    float value;
    float scale;
};

class SimTime : public SimCGSValue {
public:
    SimTime(float v) throw();
    virtual ~SimTime() throw() {}
    virtual void vfunc_1(float v) throw();
};

class SimLength : public SimCGSValue {
public:
    SimLength(float v) throw();
    virtual ~SimLength() throw() {}
    virtual void vfunc_1(float v) throw();
};

class SymMatrix {
public:
    SymMatrix() throw();
    virtual ~SymMatrix() throw() {}
    float m[6];
};

class SimulatedObject {
public:
    SimulatedObject(int v) throw();
    virtual ~SimulatedObject() throw();
    virtual void vfunc_1_000382a0() throw();
    char pad4[0xc];
    int f10;
    char pad14[0x10];
    int f24;
    int f28;
    int f2c;
};

class PhysicsObject : public SimulatedObject {
public:
    virtual void* vfunc_2_002f61c0(char);
    virtual void vfunc_3_0027afe0() throw();
    virtual void vfunc_4_0027aff0() throw();
    virtual void vfunc_5_002f6960(float);
    virtual void hulk_slot_vfunc_6_002f56b0(char); void vfunc_6_002f56b0(int v) throw();
    virtual void hulk_slot_vfunc_7_002f5870() throw(); void vfunc_7_002f5870() throw();
    virtual void vfunc_8_002f5860() throw();
    virtual void vfunc_9_002f55b0(int);
    virtual void vfunc_10_002f55e0() throw();
    virtual void vfunc_11_002f55d0() throw();
    virtual bool vfunc_12_002f58e0(int);
    virtual void vfunc_13_002f59f0() throw();
    virtual void vfunc_14_002f60d0() throw();
    virtual void vfunc_15_002f6150() throw();
    virtual void vfunc_16() throw();
    virtual void vfunc_17_002f55f0(int, int, int, int, int);
    virtual bool vfunc_18_002f5c70(hulk_intptr, hulk_intptr, int, int, int, int);
    virtual void vfunc_19_002f5db0(int, int, int);
    virtual void vfunc_20_002f5ec0(void*, void*, int, int, int);
    virtual void vfunc_21_002f5630() throw();
    virtual void vfunc_22_002fe6e0(int, int, int, int, int, int);
    virtual void vfunc_23_002f5580(int, int);
    virtual bool vfunc_24_002f5590(hulk_intptr, hulk_intptr, int);
    virtual bool vfunc_25_002f5d20(void*, int, int);
    virtual char vfunc_26_002f5600(int);
    virtual void vfunc_27_002f5360(int);
    virtual void* vfunc_28_002f78c0(int);
    virtual void vfunc_29_002f55a0(int);
    virtual void vfunc_30_002f6940() throw();
    virtual void vfunc_31_002f5f60() throw();
    virtual void vfunc_32_002f5ac0(hulk_intptr, hulk_intptr);
    virtual void vfunc_33_002f5b90(hulk_intptr);
    virtual bool vfunc_34_002f5610(void*);
    virtual void vfunc_35_002f5d70(float);
    virtual void vfunc_36_002f5620() throw();
    virtual void vfunc_37_002f5c40() throw();
    virtual void vfunc_38_002f6af0(float);
    virtual void hulk_slot_vfunc_39_002f5be0() throw(); void vfunc_39_002f5be0() throw();
    Id64_2f6220 id30;
    int f38;
    int f3c;
    int f40;
    float f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    Matrix m58;
    V3_2f6220 v98;
    char pada4;
    char pada5[3];
    V3_2f6220 va8;
    V3_2f6220 vb4;
    V3_2f6220 vc0;
    V3_2f6220 vcc;
    float fd8;
    char symdc[0x1c];
    char symf8[0x1c];
    char sym114[0x1c];
    V3_2f6220 v130;
    V3_2f6220 v13c;
    char b148;
    char pad149[3];
    V3_2f6220 v14c;
    V3_2f6220 v158;
    float f164;
    SimpleFilterAbs3D_2f6220 filt168;
    int f1cc;
    char b1d0;
    char pad1d1[3];
    int f1d4;
    float f1d8;
    int f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    int f1ec;
    union {
        unsigned int dw;
        unsigned char b[4];
    } w1f0;
    unsigned char b1f4;

    PhysicsObject(int arg, V3_2f6220 *pos, SymMatrix *inertia, int owner);
};

PhysicsObject::PhysicsObject(int arg, V3_2f6220 *pos, SymMatrix *inertia, int owner) : SimulatedObject(arg)
{
    id30.FUN_0027af00();
    f38 = owner;
    f44 = 1.0f;
    f48 = 5;
    f40 = owner;
    f3c = owner;
    new (symdc) SymMatrix(*inertia);
    new (symf8) SymMatrix();
    new (sym114) SymMatrix();
    b148 = 1;
    v14c.x = 0;
    v14c.y = 0;
    v14c.z = 0;
    v158.x = 0;
    v158.y = 0;
    v158.z = 0;
    filt168.FUN_00308cc0();
    f1cc = 0;
    b1d0 = 0;
    f1d4 = 0;
    f1d8 = 1.0f / (float)(*(unsigned int*)&DAT_004d2b74);
    f1dc = 0;
    f1e0 = 1.0f / (float)(*(unsigned int*)&DAT_004d2b74);
    f1e4 = (*(float*)&DAT_004d2b80);
    f1e8 = (*(float*)&DAT_004d2b7c);
    w1f0.b[0] = 0;
    b1f4 |= 3;
    f1ec = 0;
    w1f0.dw |= 0xff00;
    f24 = 0;
    f4c = 0;
    f50 = 0;
    f54 = 0;
    SimTime a(2.0f);
    f164 = 1.0f / a.value;
    if (DAT_00555450 == 0.0f) {
        SimLength b(0.1f);
        a.vfunc_1(1.0f);
        DAT_00555450 = b.value / a.value;
        a.vfunc_1(0.5f);
        DAT_00555454 = a.value;
        a.vfunc_1(0.1f);
        DAT_00555458 = a.value;
    }
    *(SymMatrix *)symf8 = *(SymMatrix *)symdc;
    filt168.FUN_00308a70(this);
    m58.FUN_0022b980();
    va8.z = 0;
    va8.y = 0;
    va8.x = 0;
    vb4.z = 0;
    vb4.y = 0;
    vb4.x = 0;
    v98 = *pos;
    va8.x = v98.x;
    va8.y = v98.y;
    va8.z = v98.z;
    pada4 = (va8.x * va8.x + va8.y * va8.y + va8.z * va8.z < 1e-05f) ? 1 : 0;
    if (f10) {
        vfunc_6_002f56b0(0);
    }
    vcc.z = 0;
    vcc.y = 0;
    vcc.x = 0;
    fd8 = 1.0f;
    v14c.z = 0;
    v14c.y = 0;
    v14c.x = 0;
    v158.z = 0;
    v158.y = 0;
    v158.x = 0;
    b148 = 1;
    vc0.z = 0;
    vc0.y = 0;
    vc0.x = 0;
    v130.z = 0;
    v130.y = 0;
    v130.x = 0;
    v13c.z = 0;
    v13c.y = 0;
    v13c.x = 0;
    b1d0 = 0;
    vfunc_39_002f5be0();
    vfunc_7_002f5870();
}

}
} // namespace fn_002f6220


// 0x002f65f0 FUN_002f65f0 (707 B): equivalent/0x002f65f0.cpp [wrapped: conflict: physics::PhysicsObject; physics::SimCGSValue; physics::SimLength; physics::SimTime (+2)]
// sym: ??0PhysicsObject@physics@fn_002f65f0@@QAE@H@Z @1356a3b5657e @w80b993bbd0be
namespace fn_002f65f0 {
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 6/6)
// FUN_002f65f0 @ 0x002f65f0
// equiv-map: ??0SimulatedObject@physics@@QAE@H@Z = 0x002fe570
// equiv-map: ??0SimTime@physics@@QAE@M@Z = 0x002ecf40
// equiv-map: ??0SimLength@physics@@QAE@M@Z = 0x002ecf20
// equiv-map: ??1SimUnits@physics@@UAE@XZ = 0x002ecca0

struct V3_2f65f0 {
    float x, y, z;
};

struct Id64_2f65f0 {
    int lo, hi;
    void FUN_0027af00() throw();
};

struct Matrix {
    float m[16];
    void FUN_0022b980() throw();
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90() throw();
};

struct SimpleFilterAbs3D_2f65f0 {
    char data[0x64];
    void FUN_00308cc0() throw();
    void FUN_00308a70(void *owner) throw();
};

namespace physics {

class SimUnits {
public:
    virtual ~SimUnits() throw();
};

class SimCGSValue : public SimUnits {
public:
    virtual void vfunc_1(float v) throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual ~SimCGSValue() throw() {}
    float value;
    float scale;
};

class SimTime : public SimCGSValue {
public:
    SimTime(float v) throw();
    virtual ~SimTime() throw() {}
    virtual void vfunc_1(float v) throw();
};

class SimLength : public SimCGSValue {
public:
    SimLength(float v) throw();
    virtual ~SimLength() throw() {}
    virtual void vfunc_1(float v) throw();
};

class SimulatedObject {
public:
    SimulatedObject(int v) throw();
    virtual ~SimulatedObject() throw();
    virtual void vfunc_1_000382a0() throw();
    char pad4[0x20];
    int f24;
    int f28;
    int f2c;
};

class PhysicsObject : public SimulatedObject {
public:
    Id64_2f65f0 id30;
    int f38;
    int f3c;
    int f40;
    float f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    Matrix m58;
    V3_2f65f0 v98;
    char pada4[4];
    V3_2f65f0 va8;
    V3_2f65f0 vb4;
    V3_2f65f0 vc0;
    V3_2f65f0 vcc;
    float fd8;
    SymMatrix symdc;
    SymMatrix symf8;
    SymMatrix sym114;
    V3_2f65f0 v130;
    V3_2f65f0 v13c;
    char b148;
    char pad149[3];
    V3_2f65f0 v14c;
    V3_2f65f0 v158;
    float f164;
    SimpleFilterAbs3D_2f65f0 filt168;
    int f1cc;
    char b1d0;
    char pad1d1[3];
    int f1d4;
    float f1d8;
    int f1dc;
    float f1e0;
    float f1e4;
    float f1e8;
    int f1ec;
    union {
        unsigned int dw;
        unsigned char b[4];
    } w1f0;
    unsigned char b1f4;

    PhysicsObject(int arg);
};

PhysicsObject::PhysicsObject(int arg) : SimulatedObject(arg)
{
    id30.FUN_0027af00();
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 1.0f;
    f48 = 5;
    symdc.FUN_002fca90();
    symf8.FUN_002fca90();
    sym114.FUN_002fca90();
    b148 = 1;
    v14c.x = 0;
    v14c.y = 0;
    v14c.z = 0;
    v158.x = 0;
    v158.y = 0;
    v158.z = 0;
    filt168.FUN_00308cc0();
    f1cc = 0;
    b1d0 = 0;
    f1d4 = 0;
    f1d8 = 1.0f / (float)(*(unsigned int*)&DAT_004d2b74);
    f1dc = 0;
    f1e0 = 1.0f / (float)(*(unsigned int*)&DAT_004d2b74);
    f1e4 = (*(float*)&DAT_004d2b80);
    f1e8 = (*(float*)&DAT_004d2b7c);
    w1f0.b[0] = 0;
    b1f4 |= 3;
    f1ec = 0;
    w1f0.dw |= 0xff00;
    f24 = 0;
    f4c = 0;
    f50 = 0;
    f54 = 0;
    SimTime a(10.0f);
    f164 = 1.0f / a.value;
    if (DAT_00555450 == 0.0f) {
        SimLength b(0.1f);
        a.vfunc_1(1.0f);
        DAT_00555450 = b.value / a.value;
        a.vfunc_1(0.5f);
        DAT_00555454 = a.value;
        a.vfunc_1(0.1f);
        DAT_00555458 = a.value;
    }
    va8.x = 0;
    va8.y = 0;
    va8.z = 0;
    vb4.x = 0;
    vb4.y = 0;
    vb4.z = 0;
    v98.x = 0;
    v98.y = 0;
    v98.z = 0;
    filt168.FUN_00308a70(this);
    m58.FUN_0022b980();
    vcc.x = 0;
    vcc.y = 0;
    vcc.z = 0;
    fd8 = 1.0f;
    v14c.x = 0;
    v14c.y = 0;
    v14c.z = 0;
    v158.x = 0;
    v158.y = 0;
    v158.z = 0;
    b148 = 1;
    vc0.x = 0;
    vc0.y = 0;
    vc0.z = 0;
    v130.x = 0;
    v130.y = 0;
    v130.z = 0;
    v13c.x = 0;
    v13c.y = 0;
    v13c.z = 0;
    b1d0 = 0;
}

}
} // namespace fn_002f65f0


// 0x002f6940 physics::PhysicsObject::vfunc_30 (31 B): matches/0x002f6940.cpp
// sym: ?vfunc_30@PhysicsObject@physics@@UAEXXZ
void physics::PhysicsObject::vfunc_30() {
    float f = ((Data_2f6940*)(*(float * *)&this->f_10))->x;
    this->f_3c = f * this->f_38 * f * f;
    this->f_1b0 = f * this->f_1b0;
}


// 0x002f6960 physics::PhysicsObject::vfunc_5 (395 B): equivalent/0x002f6960.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?vfunc_5@PhysicsObject@fn_002f6960@@UAEXM@Z @ef7d25d66097 @wf75101ffd225
namespace fn_002f6960 {
// STATUS: equivalent (tools/equiv.py level 3: 102 inputs, branch coverage 21/24, incomplete)
// physics::PhysicsObject::vfunc_5 @ 0x002f6960

struct Vec3_2f6960 {
    float x, y, z;
};

class Part_2f6960;
struct PartList {
    Part_2f6960 **parts;
};

struct Probe_2f6960 {
    char pad0[0x1c];
    float a;                 // 0x1c
    char pad20[8];
    float b;                 // 0x28
    char pad2c[8];
    float c;                 // 0x34
};

class Part_2f6960 {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual int GetKind();           // slot 6
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual Probe_2f6960 *GetProbe();       // slot 15
    char pad4[0x10];
    PartList *list;                  // 0x14
};

struct Rig_2f6960 {
    char pad0[0x20];
    Part_2f6960 *part;                      // 0x20
};

struct Body_2f6960 {
    char pad0[0x50];
    Vec3_2f6960 force;                      // 0x50
    Vec3_2f6960 torque;                     // 0x5c
    char pad68[4];
    int mode;                        // 0x6c
    char pad70[4];
    Rig_2f6960 *rig;                        // 0x74
};

struct Contact_2f6960 {
    char pad0[0x1c];
    char data1c[1];                  // 0x1c
};

struct Solver_2f6960 {
    void FUN_00011160(int a, char *b);
};

class PhysicsObject {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5(float dt);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual bool v11();
    virtual bool v12(float dt);
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
    virtual void v38(float dt);
    virtual void v39();
    char pad4[0xc];
    Body_2f6960 *body;                      // 0x10
    char pad14[8];
    Contact_2f6960 *contact;                // 0x1c
    char pad20[0x20];
    int param40;                     // 0x40
    char pad44[0xec];
    Solver_2f6960 solver;                   // 0x130
    char pad131[0x1cc - 0x131];
    float accum;                     // 0x1cc
    char pad1d0[0x1ec - 0x1d0];
    int timer;                       // 0x1ec
    char pad1f0;
    unsigned char partIndex;         // 0x1f1
    char pad1f2[2];
    unsigned char flags;             // 0x1f4
};

static float absf(float v)
{
    union { float f; unsigned int u; } x;
    x.f = v;
    x.u &= 0x7fffffff;
    return x.f;
}

void PhysicsObject::vfunc_5(float dt)
{
    if (body->mode != 1)
        return;
    if (v11())
        return;
    if (!(dt > (*(float*)&DAT_003f32e0)))
        return;

    if (contact != 0) {
        if (v12(dt)) {
            bool ok = (flags & 1) != 0;
            if (ok) {
                Part_2f6960 *part = body->rig->part;
                if (partIndex != 0xff) {
                    PartList *list = part->list;
                    if (list != 0)
                        part = list->parts[partIndex];
                }
                ok = (part->GetKind() == 5);
                if (ok) {
                    Probe_2f6960 *p = part->GetProbe();
                    ok = absf(p->a) < DAT_004d2bc8 && absf(p->b) < DAT_004d2bc8 && absf(p->c) < DAT_004d2bc8;
                }
            }
            if (!ok) {
                Vec3_2f6960 *f = &body->force;
                f->z = 0;
                f->y = 0;
                f->x = 0;
                Vec3_2f6960 *t = &body->torque;
                t->z = 0;
                t->y = 0;
                t->x = 0;
                return;
            }
            v13();
        }
        solver.FUN_00011160(param40, contact->data1c);
    }
    v38(dt);
    v37();
    accum = dt + accum;
    timer = 0;
    flags |= 1;
}
} // namespace fn_002f6960


// 0x002f6af0 physics::PhysicsObject::vfunc_38 (1383 B): equivalent/0x002f6af0.cpp [wrapped: conflict: PhysicsObject]
// sym: ?vfunc_38@PhysicsObject@fn_002f6af0@@UAEXM@Z @1c469351c10b @w8b01a6058c25
namespace fn_002f6af0 {
// STATUS: equivalent (tools/equiv.py level 3: 19953 inputs, branch coverage 35/36, incomplete)
// physics::PhysicsObject::vfunc_38 @ 0x002f6af0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


struct Vec3_2f6af0 {
    float x, y, z;
    void FUN_0022d260(struct Mat_2f6af0 *m) throw();
};

struct Quat_2f6af0 {
    float q[4];
    void FUN_0022b120() throw();
    void FUN_0022b650(struct Mat_2f6af0 *m) throw();
};

struct Mat_2f6af0 {
    float m[16];
    void FUN_0022c3b0(Vec3_2f6af0 *in, Vec3_2f6af0 *out) throw();
    void FUN_0022be40(Vec3_2f6af0 *p) throw();
};

struct Integ {
    void FUN_002fd020(Vec3_2f6af0 *a, Vec3_2f6af0 *b) throw();
};

class Body_2f6af0 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6(Mat_2f6af0 *m, float dt) throw();
    virtual void v7() throw();
    virtual void v8(Vec3_2f6af0 *p, Vec3_2f6af0 *q, int z) throw();
    char pad04[0x58];
    Vec3_2f6af0 a;
    union {
        float f68;
        unsigned int u68;
    };
};

extern "C" char __cdecl FUN_003059c0(Vec3_2f6af0 *a, Quat_2f6af0 *z) throw();
extern "C" void *__cdecl FUN_0022b080(void *a, void *b, void *c) throw();
extern "C" void __cdecl FUN_00305700(unsigned int s, Mat_2f6af0 *src, Mat_2f6af0 *dst) throw();

class PhysicsObject {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual void vfunc_5() throw();
    virtual void vfunc_6() throw();
    virtual void vfunc_7() throw();
    virtual void vfunc_8() throw();
    virtual void vfunc_9() throw();
    virtual void vfunc_10() throw();
    virtual void vfunc_11() throw();
    virtual void vfunc_12() throw();
    virtual void vfunc_13() throw();
    virtual void vfunc_14() throw();
    virtual void vfunc_15() throw();
    virtual void vfunc_16() throw();
    virtual void vfunc_17() throw();
    virtual void vfunc_18() throw();
    virtual void vfunc_19() throw();
    virtual void vfunc_20() throw();
    virtual void vfunc_21() throw();
    virtual void vfunc_22() throw();
    virtual void vfunc_23() throw();
    virtual void vfunc_24() throw();
    virtual void vfunc_25() throw();
    virtual void vfunc_26() throw();
    virtual void vfunc_27() throw();
    virtual void vfunc_28() throw();
    virtual void vfunc_29() throw();
    virtual void vfunc_30() throw();
    virtual void vfunc_31() throw();
    virtual void vfunc_32() throw();
    virtual void vfunc_33() throw();
    virtual void vfunc_34() throw();
    virtual void vfunc_35() throw();
    virtual void vfunc_36() throw();
    virtual void vfunc_37() throw();
    virtual void vfunc_38(float dt);
    virtual void vfunc_39() throw();
    char pad04[0xc];
    Body_2f6af0 *f10;
    char pad14[0x10];
    int f24;
    char pad28[0x1c];
    float f44;
    int f48;
    Vec3_2f6af0 v4c;
    Mat_2f6af0 mat58;
    Vec3_2f6af0 v98;
    char ba4;
    char pada5[3];
    Vec3_2f6af0 va8;
    Vec3_2f6af0 vb4;
    Vec3_2f6af0 vc0;
    Quat_2f6af0 vcc;
    char padDC[0xf8 - 0xdc];
    Integ m_f8;
    char padF9[0x114 - 0xf9];
    Integ m_114;
    char pad115[0x130 - 0x115];
    Vec3_2f6af0 v130;
    Vec3_2f6af0 v13c;
    char pad148[0x164 - 0x148];
    float f164;
    char pad168[0x1cc - 0x168];
    float f1cc;
    char b1d0;
    void FUN_002f5a20(Vec3_2f6af0 *q) throw();
};

void PhysicsObject::vfunc_38(float dt)
{
    struct Frame {
        float s0;
        Vec3_2f6af0 A;
        Vec3_2f6af0 Y;
        Vec3_2f6af0 Q;
        Quat_2f6af0 Z;
        Mat_2f6af0 M2;
    } f;

    double kk = 1.0f - dt * f164;
    f.s0 = (float)kk;
    bool run = true;
    if (kk < 1.0f) {
        if (!(f.s0 > 0.0f))
            run = false;
    } else {
        f.s0 = 1.0f;
    }
    if (run) {
        if (!(f1cc < DAT_00555458) || f24 != 0 || f48 >= 4) {
            vc0.x = f.s0 * vc0.x;
            vc0.y = f.s0 * vc0.y;
            vc0.z = f.s0 * vc0.z;
        } else {
            int m = f48;
            if (m >= 0) {
                if (m > 2) {
                    mat58.FUN_0022c3b0(&v4c, &f.Y);
                } else {
                    f.Y = *(Vec3_2f6af0 *)((char*)&this->mat58.m[0] + (m << 4));
                }
            }
            Body_2f6af0 *o = f10;
            double dotAY = o->a.z * f.Y.z + o->a.y * f.Y.y + o->a.x * f.Y.x;
            double s = -((1.0f - f.s0) * dotAY);
            double ypx = f.Y.x * s;
            f.Z.q[1] = f.Y.y * s;
            f.Z.q[2] = f.Y.z * s;
            o->a.x = ypx + o->a.x;
            o->a.y = f.Z.q[1] + o->a.y;
            o->a.z = f.Z.q[2] + o->a.z;
            m_f8.FUN_002fd020(&f10->a, &vc0);
        }
    }
    f10->v8(&v98, &f.Q, -1);
    double qxo = f.Q.x;
    double qyo = f.Q.y;
    hulk_freg qzo = f.Q.z;
    f.A.z = qzo;
    double h = dt * f44;
    f.Q.x = h * v130.x + f.Q.x;
    f.Q.y = h * v130.y + f.Q.y;
    f.Q.z = h * v130.z + f.Q.z;
    Vec3_2f6af0 *a = &f10->a;
    f.A.x = a->x;
    f.A.y = a->y;
    f.A.z = a->z;
    char b = b1d0;
    struct { float x; hulk_freg y, z; } sum;   // old + new: x goes through Y.x (rounded), y and z stay in registers
    sum.x = qxo + f.Q.x;
    sum.y = qyo + f.Q.y;
    sum.z = f.Q.z + qzo;
    hulk_freg half = dt * 0.5f;
    f.s0 = half;
    f.Y.x = sum.x * half;
    f.Y.y = sum.y * half;
    f.Y.z = sum.z * half;
    if (b != 0) {
        vc0.x = dt * v13c.x + vc0.x;
        vc0.y = dt * v13c.y + vc0.y;
        vc0.z = dt * v13c.z + vc0.z;
    }
    m_114.FUN_002fd020(&vc0, &f10->a);
    Body_2f6af0 *ec = f10;
    double sum2 = ec->a.x * ec->a.x + ec->a.y * ec->a.y + ec->a.z * ec->a.z;
    bool skipNext = false;
    if (sum2 > DAT_004d2ba0) {
        double sc = DAT_004d2b84 / sqrt(sum2);
        ec->a.x = sc * ec->a.x;
        ec->a.y = sc * ec->a.y;
        ec->a.z = sc * ec->a.z;
        m_f8.FUN_002fd020(&f10->a, &vc0);
    } else if (sum2 < DAT_004d2ba4) {
        if (sum2 > 0.0f) {
            ec->a.z = 0.0f;
            ec->a.y = 0.0f;
            ec->a.x = 0.0f;
            vc0.z = 0.0f;
            vc0.y = 0.0f;
            vc0.x = 0.0f;
        }
        if (f.A.z * f.A.z + f.A.y * f.A.y + f.A.x * f.A.x < DAT_004d2ba4) {
            f.A.z = 0.0f;
            f.A.y = 0.0f;
            f.A.x = 0.0f;
            skipNext = true;
        }
    }
    if (!skipNext) {
        Vec3_2f6af0 *pa = &f10->a;
        f.A.x = f.A.x + pa->x;
        f.A.y = f.A.y + pa->y;
        double azs = f.A.z + pa->z;
        f.A.x = f.A.x * f.s0;
        f.A.y = f.A.y * f.s0;
        f.A.z = azs * f.s0;
        if (FUN_003059c0(&f.A, &f.Z)) {
            Quat_2f6af0 *edi = &vcc;
            FUN_0022b080(&f.Z, &f.Z, edi);
            vcc.q[0] = f.Z.q[0];
            vcc.q[1] = f.Z.q[1];
            vcc.q[2] = f.Z.q[2];
            vcc.q[3] = f.Z.q[3];
            vcc.FUN_0022b120();
            vcc.FUN_0022b650(&mat58);
        }
        vfunc_39();
    }
    if (b1d0 == 0)
        m_114.FUN_002fd020(&vc0, &f10->a);
    else
        m_f8.FUN_002fd020(&f10->a, &vc0);
    v98.x = f.Y.x + v98.x;
    v98.y = f.Y.y + v98.y;
    v98.z = f.Y.z + v98.z;
    if (f10->u68 != 0x3f800000)
        FUN_00305700(f10->u68, &mat58, &f.M2);
    else
        memcpy(&f.M2, &mat58, 64);
    if (ba4 == 0) {
        f.Y.x = va8.x + vb4.x;
        f.Y.y = va8.y + vb4.y;
        f.Y.z = va8.z + vb4.z;
        f.Y.FUN_0022d260(&mat58);
        double sc = f10->f68;
        struct { hulk_freg x; float y, z; } ts;   // Y * sc: x stays in a register, y and z are stored
        ts.x = f.Y.x * sc;
        ts.y = f.Y.y * sc;
        ts.z = f.Y.z * sc;
        f.Y.x = v98.x - ts.x;
        f.Y.y = v98.y - ts.y;
        f.Y.z = v98.z - ts.z;
        f.M2.FUN_0022be40(&f.Y);
    } else {
        f.M2.FUN_0022be40(&v98);
    }
    f10->v6(&f.M2, dt);
    FUN_002f5a20(&f.Q);
}
} // namespace fn_002f6af0

namespace fn_ff237b18 {

// 0x002f7060 FUN_002f7060 (27 B): matches/0x002f7060.cpp
// sym: ??0PhysicsObjectLoader@fn_ff237b18@@QAE@XZ
PhysicsObjectLoader::PhysicsObjectLoader() {
    a = 0;
    b = 0x7011000;
    c = 0;
    d = 0;
    vptr = (hulk_intptr)&hulk_at_00431680;
}

} // namespace fn_ff237b18

// 0x002f7080 physics::PhysicsObjectLoader::vfunc_2 (31 B): matches/0x002f7080.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002f7080@@UAEPAV123@E@Z
namespace fn_002f7080 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2f7080 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2f7080 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002f7080


// 0x002f70a0 physics::PhysicsObjectLoader::vfunc_5 (1088 B): equivalent/0x002f70a0.cpp
// sym: ?vfunc_5@PhysicsObjectLoader@physics@@UAEXPAX00H@Z @2d44a90e2176 @w4990d370eefe
// STATUS: equivalent (tools/equiv.py level 3: 236 inputs, branch coverage 44/44)
// physics::PhysicsObjectLoader::vfunc_5 @ 0x002f70a0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void physics::PhysicsObjectLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr unused) { void ** outObj = (void **)__p0; Key_2f70a0 * outKey = (Key_2f70a0 *)__p1; Reader_2f70a0 * r = (Reader_2f70a0 *)__p2;

    struct Frame {
        char pad00[3];
        unsigned char len;           // 0x03
        int b;                       // 0x04   number of articulated parts
        unsigned int d;              // 0x08
        unsigned int c;              // 0x0c
        unsigned int v1;             // 0x10
        unsigned int v0;             // 0x14
        unsigned int v2;             // 0x18
        int a;                       // 0x1c   kind
        unsigned int v3;             // 0x20
        unsigned int v5;             // 0x24
        Vec3_2f70a0 zero;                   // 0x28
        SymMatrix_2f70a0 sm;                // 0x34
        Vec3_2f70a0 center;                 // 0x50
        char name1[0x100];           // 0x5c
        char name2[0x100];           // 0x15c
        char msg[0x12c];             // 0x25c
    } f;

    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
    unsigned int n = f.len;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name1), (hulk_intptr)n, 1, (hulk_intptr)1));
    f.name1[n] = 0;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.a), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
    n = f.len;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name2), (hulk_intptr)n, 1, (hulk_intptr)1));
    f.name2[n] = 0;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.b), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.c), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.d), (hulk_intptr)1, 4, (hulk_intptr)1));

    Part_2f70a0 **parts = 0;
    int count = 0;
    if (f.b > 0) {
        int prev = FUN_00266da0(1);
        parts = (Part_2f70a0 **)FUN_0008d6d0(f.b * sizeof(Part_2f70a0 *));
        FUN_00266da0(prev);
    }
    f.sm.FUN_002fca90();

    while (r->FUN_002669f0()) {
        r->FUN_00266a30();
        int id = r->FUN_00266c30();
        if (id == 0x7011001) {
            FUN_002f5fe0((Reader_2f70a0 *)r, (float *)(SymMatrix_2f70a0 *)(&f.sm));
        } else if (id == 0x7011002) {
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.center), (hulk_intptr)3, 4, (hulk_intptr)1));
        } else if (id == 0x7011020) {
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v0), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v1), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v2), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v3), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.d), (hulk_intptr)1, 4, (hulk_intptr)1));
            ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.v5), (hulk_intptr)1, 4, (hulk_intptr)1));
            f.zero.x = 0.0f;
            f.zero.y = 0.0f;
            f.zero.z = 0.0f;
            ((owners::C_2fd0a0 *)&(f.sm))->FUN_002fd0a0();
            while (r->FUN_002669f0()) {
                r->FUN_00266a30();
                int sub = r->FUN_00266c30();
                if (sub == 0x7011001)
                    FUN_002f5fe0((Reader_2f70a0 *)r, (float *)(SymMatrix_2f70a0 *)(&f.sm));
                else if (sub == 0x7011002)
                    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.zero), (hulk_intptr)3, 4, (hulk_intptr)1));
                r->FUN_00266be0();
            }
            int prev = FUN_00266da0(1);
            Part_2f70a0 *p = FUN_0030d4f0(f.v5, &f.zero, f.v1, f.v0);
            parts[count] = p;
            if (p->f6 > 0)
                p->fe4 = f.v2;
            parts[count]->v9(f.d, f.v3);
            parts[count]->FUN_00309940(&f.sm);
            FUN_00266da0(prev);
            count++;
        }
        r->FUN_00266be0();
    }

    Props *props = FUN_002f2750(FUN_0027b020(f.name2));
    if (props == 0)
        props = FUN_002f2750(FUN_0027b020(count == 0 ? "defaultPhysicsProperties" : "defaultArtPhysicsProperties"));

    SimObject *res = 0;
    if (f.a == 2) {
        void *mem = thunk_FUN_0008d690(0x200);
        Composite_2f70a0 *c = 0;
        if (mem != 0)
            c = ((Composite_2f70a0 *)mem)->FUN_00309520(props, parts, count);
        res = c;
        for (int i = 0; i < f.b; i++) {
            if (parts[i] != 0)
                delete parts[i];
        }
        thunk_FUN_00267090(parts);
    } else if (f.b == 0) {
        void *mem = thunk_FUN_0008d690(0x1f8);
        if (mem != 0)
            res = ((Articulated *)mem)->FUN_002f6220(props, &f.center, &f.sm, f.c);
    } else if (count > 0) {
        FUN_00267760(f.msg, 0x12c, "Found an ArticulatedPhysicsObject named %s.", f.name1);
    }

    unsigned int lo = 0;
    unsigned int hi = 0;
    if (res != 0) {
        ((owners::Target_27b040 *)&(res->key8))->FUN_0027b040((hulk_uintptr)(f.name1));
        ((owners::Target_27b040 *)&(res->key30))->FUN_0027b040((hulk_uintptr)(f.name2));
        res->FUN_002fe6b0((*(void**)&DAT_00554c10));
        lo = res->key8.lo;
        hi = res->key8.hi;
    }
    *outObj = res;
    outKey->lo = lo;
    outKey->hi = hi;
    f.sm.FUN_002fcaa0();
}


// 0x002f7530 FUN_002f7530 (153 B): matches/0x002f7530.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ??4Obj_2f7530@fn_002f7530@@QAEPAV01@ABV01@@Z
namespace fn_002f7530 {
class Obj_2f7530 {
  public:
    virtual void f0();
    Obj_2f7530* operator=(const Obj_2f7530& o_2f7530);
    int a4, a8, ac, a10, a14, a18, a1c, a20, a24, a28;
    int a2c;
    int a30, a34, a38, a3c, a40, a44, a48, a4c, a50, a54, a58;
    char b5c, b5d;
    int a60;
};

Obj_2f7530* Obj_2f7530::operator=(const Obj_2f7530& o_2f7530) {
    a4 = o_2f7530.a4;
    a8 = o_2f7530.a8;
    ac = o_2f7530.ac;
    a10 = o_2f7530.a10;
    a14 = o_2f7530.a14;
    a18 = o_2f7530.a18;
    a1c = o_2f7530.a1c;
    a20 = o_2f7530.a20;
    a24 = o_2f7530.a24;
    a28 = o_2f7530.a28;
    a30 = o_2f7530.a30;
    a34 = o_2f7530.a34;
    a38 = o_2f7530.a38;
    a3c = o_2f7530.a3c;
    a40 = o_2f7530.a40;
    a44 = o_2f7530.a44;
    a48 = o_2f7530.a48;
    a4c = o_2f7530.a4c;
    a50 = o_2f7530.a50;
    a54 = o_2f7530.a54;
    a58 = o_2f7530.a58;
    b5c = o_2f7530.b5c;
    b5d = o_2f7530.b5d;
    a60 = o_2f7530.a60;
    return this;
}
} // namespace fn_002f7530

namespace fn_ff237b18 {

// 0x002f75d0 FUN_002f75d0 (747 B): equivalent/0x002f75d0.cpp
// sym: ?FUN_002f75d0@Obj_2f75d0@fn_ff237b18@@QAEXPAV12@H@Z @9d4fc2fa7e22 @w35af60c32f7c
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002f75d0 @ 0x002f75d0
void Obj_2f75d0::FUN_002f75d0(Obj_2f75d0 *dst, int arg)
{
    FUN_002fe6f0(dst, arg);
    dst->name.FUN_0027af70(&name);
    dst->f38 = f38;
    dst->f3c = f3c;
    dst->f40 = f40;
    dst->f44 = f44;
    dst->f4c = f4c;
    dst->f50 = f50;
    dst->f54 = f54;
    dst->f48 = f48;
    dst->blk58 = blk58;
    dst->f98 = f98;
    dst->f9c = f9c;
    dst->fa0 = fa0;
    dst->b_a4 = b_a4;
    dst->fa8 = fa8;
    dst->fac = fac;
    dst->fb0 = fb0;
    dst->fb4 = fb4;
    dst->fb8 = fb8;
    dst->fbc = fbc;
    dst->fc0 = fc0;
    dst->fc4 = fc4;
    dst->fc8 = fc8;
    dst->blkcc = blkcc;
    dst->fe0 = fe0;
    dst->fe4 = fe4;
    dst->fe8 = fe8;
    dst->fec = fec;
    dst->ff0 = ff0;
    dst->ff4 = ff4;
    dst->ffc = ffc;
    dst->f100 = f100;
    dst->f104 = f104;
    dst->f108 = f108;
    dst->f10c = f10c;
    dst->f110 = f110;
    dst->f118 = f118;
    dst->f11c = f11c;
    dst->f120 = f120;
    dst->f124 = f124;
    dst->f128 = f128;
    dst->f12c = f12c;
    dst->b148 = 1;
    dst->sub.FUN_002f7530(&sub);
    ((owners::C_308a70 *)&(dst->sub))->FUN_00308a70((hulk_intptr)(Obj_2f75d0 *)dst);
    dst->fc8 = 0;
    dst->fc4 = 0;
    dst->fc0 = 0;
    dst->Reset();
    dst->f1cc = 0;
    dst->b1d0 = b1d0;
    dst->f164 = f164;
    dst->f1e4 = f1e4;
    dst->f1e8 = f1e8;
    f1d4 = 0;
    f1d8 = 1.0f / (float)(*(unsigned int*)&DAT_004d2b74);
    f1dc = 0;
    f1e0 = 1.0f / (float)(*(unsigned int*)&DAT_004d2b74);
    char flags = b1f4;
    b1f0 = 0;
    unsigned int bits = dw1f0 | 0xff00;
    flags |= 2;
    b1f4 = flags;
    dw1f0 = bits;
}

} // namespace fn_ff237b18
