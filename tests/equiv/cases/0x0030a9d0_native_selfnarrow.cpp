// STATUS: equivalent (tools/equiv.py --wine level 3)
// (integ2, selfnarrow) 0x0030a9d0 passes its own char flag on to itself: MSVC pushes the whole incoming slot (stale upper
// bytes), clang zero-extends; the recursive call's char parameter is compared at its declared width (8 bits).
// object 0x003097b0..0x0030d760 (kind game, layer engine, confidence high), dominant class physics::PhysicsJoint3D
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/Render.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fca90e00 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fca90e00 {} using namespace fn_fca90e00;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace physics {
class PhysicsJoint_3097b0 {
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
    virtual void a26();
    virtual void a27();
    virtual void a28();
    char pad[0x10c - 4];
};
}
namespace fn_fca90e00 {
class PhysicsJoint_3097d0 {
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
    char pad[0x138 - 4];
};
struct Obj_309820 {
    int x;
    int* target();
};
class Obj_309830 {
  public:
    char pad[0x10];
    Obj_309830* target();
};
union Word_309940 {
    int i;
    float f;
};
struct Src_309940 {
    char pad0[4];
    int f4, f8, fc, f10, f14, f18;
};
class Obj_309940 {
public:
    char pad0[0x4c];
    Word_309940 f4c, f50, f54, f58, f5c, f60;
    char pad64[4];
    int f68, f6c, f70, f74, f78, f7c;
    char pad80[0xf0 - 0x80];
    float ff0;

    void FUN_00309940(Src_309940 *s);
};
struct Sub_3099d0 {
    char data[0x1c];
};
struct Source_3099d0 {
    char pad[0x0c];
    float value;
};
struct Holder_3099d0 {
    char pad[0x18];
    Source_3099d0 *source;
};
struct Anim_3099d0 {
    char pad00[0x18];
    Holder_3099d0 *holder;
    char pad1c[0x30 - 0x1c];
    float rate;
    char pad34[4];
    float current;
    float length;
    float inverse;
    char pad44[4];
    Sub_3099d0 subA;
    Sub_3099d0 subB;
    char pad80[0xf0 - 0x80];
    float weight;
    void FUN_003099d0();
};
struct Block_309a40 {
    unsigned int x[16];
};
class Buf_309a40 {
  public:
};
struct Node_309a40 {
    char pad[0x10];
    char* base;
};
struct Manager_309a40 {
    char pad[0x220];
    Node_309a40* node;
};
struct Vec_309aa0 {
    char p[4];
    float a;
    char q[8];
    float b;
    char r[4];
    float c;
};
class PhysicsJoint_309aa0;
struct Manager_309aa0 {
    char p[0x218];
    PhysicsJoint_309aa0* joint;
};
class PhysicsJoint_309aa0 {
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
    virtual void v13(void* x, Vec_309aa0* y);
    char flag;
    char pad5[0x18 - 5];
    Manager_309aa0* mgr;
    PhysicsJoint_309aa0* other;
    char q[0xe8 - 0x20];
    float limit;
    char r[4];
    float force;
};
class Thing_309b80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual bool Check();
    virtual void Get(int*);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void Apply(int);
};
extern "C" void FUN_00305800(int*, int, float);
extern "C" void* alloc(hulk_uintptr);
struct ThisCall_003099d0 {
    void called_003099d0();
};
union FloatBits_30a270 {
    float f;
    int i;
};
struct Vec3_30a270 {
    float x, y, z;
};
struct Row_30a270 {
    char pad00[0x18];
    float limit;
};
struct Mgr220 {
    char pad00[0x10];
    Row_30a270 *rows;
};
struct Context {
    char pad00[0x218];
    Node *active;
    char pad21c[4];
    Mgr220 *table;
};
class Node {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void vfunc_16(Vec3_30a270 *in, Vec3_30a270 *out);
    char _m_pad_4[0x4];
    union { int f8; int index; };
    char _m_pad_c[0xc];
    Context *ctx;
    union { Node* next; Node *parent; };
    char _m_pad_20[0xb4];
    Vec3_30a270 origin;
    char _m_pad_e0[0x4];
    float radius;
    float weight;
    char flagEC;
    char flagED;
    char flagEE;
    char _m_pad_ef[0x1];
    int FUN_0030a270(Vec3_30a270 *pos, Vec3_30a270 *dir);
};
struct Vec3_30a7b0 {
    float x, y, z;
};
struct Item_30a7b0 {
    char pad0[4];
    Vec3_30a7b0 delta;
    Vec3_30a7b0 pos;
    char pad2[0x64 - 0x1c];
};
struct ItemTable_30a7b0 {
    char pad[0x8c];
    Item_30a7b0 *items;
};
struct Store {
    char pad0[0x10];
    ItemTable_30a7b0 *table;
    char pad1[0x98 - 0x14];
    Vec3_30a7b0 refPos;
};
struct Mover_30a7b0;
struct Anchor_30a7b0 {
    char pad[0xd4];
    Vec3_30a7b0 pos;
};
struct Mover_30a7b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void clearDelta();
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
    virtual void getDelta(Vec3_30a7b0 *out);
    virtual void afterDelta();

    char active;
    char pad0[3];
    int index;
    char pad1[0x18 - 0xc];
    Store *store;
    Anchor_30a7b0 *anchor;
    Mover_30a7b0 **begin;
    Mover_30a7b0 **end;
    char pad3[0xd4 - 0x28];
    Vec3_30a7b0 target;
    char pad4[0xe8 - 0xe0];
    float pending;
    char hasPending;

    void FUN_0030a7b0(Vec3_30a7b0 a, Vec3_30a7b0 b);
};
struct Vec3_30a9d0 {
    float x, y, z;
    void FUN_000111b0(Vec3_30a9d0* a, Vec3_30a9d0* b);
};
struct Elem_30a9d0 {
    char pad00[4];
    Vec3_30a9d0 p4;
    Vec3_30a9d0 p10;
    char pad1c[0x64 - 0x1c];
    void FUN_002fd730();
};
struct Table_30a9d0 {
    char pad00[0x8c];
    Elem_30a9d0* elems;
};
struct Owner_30a9d0 {
    char pad00[0x10];
    Table_30a9d0* table;
    char pad14[0x98 - 0x14];
    Vec3_30a9d0 pos98;
    char padA4[0x214 - 0xa4];
    Node* list;
    char pad218[0x224 - 0x218];
    float f224;
};
struct Link_30a9d0 {
    char pad00[0xd4];
    Vec3_30a9d0 pos;
};
class Body_30a9d0;
class Body_30a9d0 {
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
    virtual void v22(Vec3_30a9d0* out);
    virtual void v23();
    virtual void v24(Vec3_30a9d0* v);
    virtual void v25();
    virtual char v26(Vec3_30a9d0* c, Vec3_30a9d0* v);
    char b4;
    char pad05;
    short w6;
    int f8;
    char pad0c[0x18 - 0xc];
    Owner_30a9d0* owner;
    Link_30a9d0* link;
    Body_30a9d0** childBegin;
    Body_30a9d0** childEnd;
    char pad28[0x80 - 0x28];
    Vec3_30a9d0 v80;
    char pad8c[0xd4 - 0x8c];
    Vec3_30a9d0 pos;
    char pade0[0xe8 - 0xe0];
    float fe8;
    char bec;
    void FUN_0030a9d0(Vec3_30a9d0 a, Vec3_30a9d0 b, char flag);
};
struct Vec3_30ad10 { float x,y,z; };
struct Helper_30ad10 { void FUN_00310490(int, Vec3_30ad10*, int); };
} // namespace fn_fca90e00
namespace physics {
class PhysicsJoint_30aea0 {
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
};
}
namespace fn_fca90e00 {
struct Settings_30b2c0 { char pad[0x224]; float scale; };
struct Object {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual float v6();
    char _m_pad_4[0x8];
    int value;
    float lower;
    float upper;
    union { Helper_30ad10* helper; Settings_30b2c0* settings; };
    char _m_pad_1c[0x7c];
    float x;
    float y;
    float z;
    char _m_pad_a4[0x68];
    float time;
    char _m_pad_110[0xc];
    float offset;
    void target(char mode, float* out);
    hulk_freg FUN_0030adc0(float start, float delta, float lower, float upper);
    float target(float delta);
};
class PhysicsJoint3D {
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
    virtual void vfunc_17(float*, float, float*);
};
class PhysicsJoint3D_30b8f0 {
public:
    int vptr;
    char pad04[0x0c];
    float minSpeed;
    float maxSpeed;
    char pad18[0x80];
    float axis[3];
    char padA4[0x7c];
    float dir[3];
    char pad12c[0x0c];
    float impulse[3];
    char pad144[0x10];
    float speed;
    float slip;

    void FUN_0030b8f0();
};
class PhysicsJoint3D_30be90 {
public:
    char pad00[0x98];
    float a98, a9c, aa0;     // 0x98
    char pada4[0x54];
    unsigned char flagF8;    // 0xf8
    char padf9[3];
    float b0fc, b100, b104;  // 0xfc
    char pad108[0x30];
    float n138, n13c, n140;  // 0x138
    char pad144[0x10];
    float f154;              // 0x154
    float f158;              // 0x158
    void FUN_0030be90();
};
struct ThisCall_0030ad10 {
    void FUN_0030ad10(int mode, float *out);
};
typedef unsigned int U32_30bf40;
typedef unsigned int Word_30c580;
extern "C" unsigned int * __cdecl FUN_0030bf40(unsigned int *, int, unsigned int *);
struct IntVec_30c690 {
    char data[0x10];
};
struct State_30c690 {
    int word00;              // 0x00 (not copied)
    char byte04;
    char byte05;             // not copied
    short word06;

    int f08;  // 0x8
    int f0c;  // 0xc
    int f10;  // 0x10
    int f14;  // 0x14
    int f18;  // 0x18
    int f1c;  // 0x1c
    IntVec_30c690 vec20;            // 0x20
    int f30;  // 0x30
    int f34;  // 0x34
    int f38;  // 0x38
    int f3c;  // 0x3c
    int f40;  // 0x40
    int f44;  // 0x44
    char skip48[0x4];
    int f4c;  // 0x4c
    int f50;  // 0x50
    int f54;  // 0x54
    int f58;  // 0x58
    int f5c;  // 0x5c
    int f60;  // 0x60
    char skip64[0x4];
    int f68;  // 0x68
    int f6c;  // 0x6c
    int f70;  // 0x70
    int f74;  // 0x74
    int f78;  // 0x78
    int f7c;  // 0x7c
    int f80;  // 0x80
    int f84;  // 0x84
    int f88;  // 0x88
    int f8c;  // 0x8c
    int f90;  // 0x90
    int f94;  // 0x94
    int f98;  // 0x98
    int f9c;  // 0x9c
    int fa0;  // 0xa0
    int block[16];           // 0xa4
    int fe4;  // 0xe4
    int fe8;  // 0xe8
    char bec;  // 0xec
    char bed;  // 0xed
    char bee;  // 0xee
    char bef;  // 0xef
    int ff0;  // 0xf0
    int ff4;  // 0xf4
    State_30c690 *FUN_0030c690(const State_30c690 *other);
};
class Obj_30c830 {
  public:
    char pad[0xf8];
    unsigned char b;
    unsigned int w0, w1, w2, w3, w4, w5, w6, w7, w8;
    void CopyBase_0030c690(const Obj_30c830&);
    Obj_30c830& Copy(const Obj_30c830&);
};
extern "C" char DAT_00431de4[];
class SymMatrix_30cbb0 {
  public:
    void Init_002fcaa0();
};
class PhysicsJoint {
  public:
    char pad[0x20];
    int m20;
    hulk_intptr m24;
};
extern void __cdecl AddRef_0008d340(void*);
} // namespace fn_fca90e00
namespace physics {
class PhysicsJoint_30ce20 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    char pad[0x10c - 4];
};
}
namespace fn_fca90e00 {
class X_30ce30 {
    char pad[0x108];

  public:
    int value;
};
class PhysicsJoint_30ce60 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void vfunc_13();
    virtual void vfunc_14();
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
    virtual void vfunc_28();
};
} // namespace fn_fca90e00
namespace physics {
class PhysicsJoint1D_30ce90 : public physics::PhysicsJoint1D {};
}
namespace physics {
struct PhysicsJoint_30cec0 { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); };
}
namespace fn_fca90e00 {
class PhysicsJoint1D_30cf20 : public physics::PhysicsJoint1D {};
class PhysicsJoint_30cf80 {
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
    virtual void vfunc_23();
};
class PhysicsJoint_30d100 {
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
};
class physics_PhysicsJoint {
  public:
    virtual void vfunc_0();
};
} // namespace fn_fca90e00
namespace physics {
class PhysicsJoint1D_30d160 : public physics::PhysicsJoint3D {};
}
namespace fn_fca90e00 {
class PhysicsJoint_30d1b0 {
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
};
} // namespace fn_fca90e00
namespace physics {
struct Vec3 { float x, y, z; };
}
namespace fn_fca90e00 {
struct SymMatrix_30d3a0 {
    void Destruct_002fcaa0();
};
extern "C" void __cdecl FreeBuf_0008d340(void*);
extern "C" void __cdecl DeleteObj_0008d330(void*);
class PhysicsJoint0D_30d3a0 {
  public:
    void* vptr;
    char pad1[0x20 - 4];
    int m20;
    hulk_intptr m24;
    char pad2[0x48 - 0x28];
    SymMatrix_30d3a0 m48;
    char pad3[0x64 - 0x49];
    SymMatrix_30d3a0 m64;

    void* vfunc_0(int flags);
};
struct SymMatrix_30d420 {
    void Destruct_002fcaa0();
};
class PhysicsJoint1D_30d420 {
  public:
    void* vptr;
    char pad1[0x20 - 4];
    int m20;
    hulk_intptr m24;
    char pad2[0x48 - 0x28];
    SymMatrix_30d420 m48;
    char pad3[0x64 - 0x49];
    SymMatrix_30d420 m64;

    void* vfunc_0(int flags);
};
struct SymMatrix_30d4a0 {
    void Destruct_002fcaa0();
};
class PhysicsJoint3D_30d4a0 {
  public:
    void* vptr;
    char pad1[0x20 - 4];
    int m20;
    hulk_intptr m24;
    char pad2[0x48 - 0x28];
    SymMatrix_30d4a0 m48;
    char pad3[0x64 - 0x49];
    SymMatrix_30d4a0 m64;

    void* vfunc_0(int flags);
};
struct SymMatrix_30d590 {
    void Init_002fca90();
    char b[0x1c];
};
struct PhysicsJoint0D_30d590;
struct PhysicsJoint_30d590 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7_0030ca60();
    virtual void v8_0030ca70();
    virtual void v9_003099b0(int, int);
    virtual void v10_00309a40(hulk_intptr);
    virtual void v11();
    virtual void v12();
    virtual void v13_00309aa0(void*, void*);
    virtual bool v14_0030a410(void*, void*, void*);
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
    virtual PhysicsJoint_30d590* d27() HULK_PURE64;
    virtual void v28_0030c670(PhysicsJoint_30d590* p);
    int m4, m8, mc, m10, m14, m18, m1c;
    int m20, m24, m28;
    char p2c[0x1c];
    SymMatrix_30d590 h48;
    SymMatrix_30d590 h64;
    char tail[0xf8 - 0x80];
    PhysicsJoint_30d590() {
        _ReadWriteBarrier();
        m20 = 0;
        m24 = 0;
        m28 = 0;
        h48.Init_002fca90();
        h64.Init_002fca90();
    }
    void Init_0030c690(PhysicsJoint_30d590* owner);
};
struct PhysicsJoint0D_30d590 : PhysicsJoint_30d590 {
    PhysicsJoint0D_30d590() {}
    virtual PhysicsJoint_30d590* d27();
};
} // namespace fn_fca90e00
void* operator new(size_t);
namespace fn_fca90e00 {
extern "C" void* ALLOC_0008d690(int);
extern int hulk_at_00431de4;
extern int hulk_at_00431f4c;
class Sub_30d650 {
  public:
    char data[0x1c];
    void Init_002fca90();
};
struct Obj_30d650 {
    void* m_vtable;
    char pad1[0x1c];
    int a, b, c;
    char pad2[0x1c];
    Sub_30d650 s1;
    Sub_30d650 s2;
    char pad3[0xdc];
};
class PhysicsJoint_30d650 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual Obj_30d650* vfunc_27();
    virtual void vfunc_28(Obj_30d650*);
};

} // namespace fn_fca90e00

// 0x003097b0 physics::PhysicsJoint1D::vfunc_2 (27 B): matches/0x003097b0.cpp
// sym: ?vfunc_2@PhysicsJoint1D@physics@@UAEXXZ
 // namespace physics
void physics::PhysicsJoint1D::vfunc_2() {
    *(int*)((char*)&this->f_118) = 0;
    *(int*)((char*)&this->f_114) = 0;
    *(int*)((char*)&this->f_110) = 0;
    *(int*)((char*)&this->f_10c) = 0;
}


// 0x003097d0 physics::PhysicsJoint3D::vfunc_2 (55 B): matches/0x003097d0.cpp
// sym: ?vfunc_2@PhysicsJoint3D@physics@@UAEXXZ
 // namespace physics
void physics::PhysicsJoint3D::vfunc_2() {
    vfunc_1();
    *(int*)((char*)&this->f_140) = 0;
    *(int*)((char*)&this->f_13c) = 0;
    *(int*)((char*)&this->f_138) = 0;
    *(int*)((char*)&this->f_14c) = 0;
    *(int*)((char*)&this->f_148) = 0;
    *(int*)((char*)&this->f_144) = 0;
    *((char*)&this->f_150) = 1;
}

namespace fn_fca90e00 {

// 0x00309820 FUN_00309820 (13 B): matches/0x00309820.cpp
// sym: ?target@Obj_309820@fn_fca90e00@@QAEPAHXZ
int* Obj_309820::target() {
    ((owners::Obj_2fd730 *)this)->FUN_002fd730();
    return &x + 1;
}


// 0x00309830 FUN_00309830 (13 B): matches/0x00309830.cpp
// sym: ?target@Obj_309830@fn_fca90e00@@QAEPAV12@XZ
Obj_309830* Obj_309830::target() {
    ((owners::Obj_2fd730 *)this)->FUN_002fd730();
    return (Obj_309830*)((char*)this + 0x10);
}


// 0x00309940 FUN_00309940 (100 B): equivalent/0x00309940.cpp
// sym: ?FUN_00309940@Obj_309940@fn_fca90e00@@QAEXPAUSrc_309940@2@@Z @656228e61239 @wfed35b1a9611 @v1dc551c0deb0
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_00309940 @ 0x00309940
void Obj_309940::FUN_00309940(Src_309940 *s)
{
    f68 = s->f4;
    f6c = s->f8;
    f70 = s->fc;
    f74 = s->f10;
    f78 = s->f14;
    f7c = s->f18;
    f4c.i = f68;
    f50.i = f6c;
    f54.i = f70;
    f58.i = f74;
    f5c.i = f78;
    f60.i = f7c;
    double partial = ((volatile Word_309940 *)&f60)->f + ((volatile Word_309940 *)&f58)->f; // MSVC reorders three-term sums
    ff0 = (partial + ((volatile Word_309940 *)&f4c)->f) * 0.33f;
}

} // namespace fn_fca90e00

// 0x003099b0 physics::PhysicsJoint::vfunc_9 (17 B): matches/0x003099b0.cpp [wrapped: conflict: physics::PhysicsJoint]
// sym: ?vfunc_9@PhysicsJoint@physics@fn_003099b0@@UAEXHH@Z
namespace fn_003099b0 {
namespace physics {
class PhysicsJoint {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9(int, int);
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    char pad[12];
    int a;
    int b;
};
void PhysicsJoint::vfunc_9(int x, int y) {
    a = x;
    b = y;
}
} // namespace physics
} // namespace fn_003099b0

namespace fn_fca90e00 {

// 0x003099d0 FUN_003099d0 (112 B): matches/0x003099d0.cpp
// sym: ?FUN_003099d0@Anim_3099d0@fn_fca90e00@@QAEXXZ
// FUN_003099d0 @ 0x003099d0
void Anim_3099d0::FUN_003099d0()
{
    if (length > 0.0f) {
        float previous = current;
        hulk_freg product = holder->source->value * rate;
        current = product;
        float ratio = product / previous;
        hulk_freg newLength = ratio * length;
        length = newLength;
        inverse = 1.0f / newLength;
        weight = ratio * weight;
        ((owners::X_2fcb80 *)&subA)->FUN_002fcb80(ratio);
        ((owners::X_2fcb80 *)&subB)->FUN_002fcb80(ratio);
    }
}

} // namespace fn_fca90e00

// 0x00309a40 physics::PhysicsJoint::vfunc_10 (88 B): matches/0x00309a40.cpp
// sym: ?vfunc_10@PhysicsJoint@physics@@UAEXH@Z
void physics::PhysicsJoint::vfunc_10(hulk_intptr __p0) { void * arg = (void *)__p0;

    char* p = (char*)this;
    *(Block_309a40*)(p + 0xa4) = *(Block_309a40*)arg;
    ((owners::M_22c3b0 *)(((Buf_309a40*)(p + 0xa4))))->FUN_0022c3b0((float *)(p + 0x8c), (float *)(p + 0x80));
    Manager_309a40* m = (Manager_309a40*)(*(void * *)&this->f_18);
    char* base = m->node->base;
    ((owners::M_22c3b0 *)(((Buf_309a40*)(p + 0xa4))))->FUN_0022c3b0((float *)(base + this->f_08 * 0x1c), (float *)(p + 0x98));
}

namespace fn_fca90e00 {

// 0x00309aa0 physics::PhysicsJoint::vfunc_13 (127 B): matches/0x00309aa0.cpp
// sym: ?v13@PhysicsJoint_309aa0@fn_fca90e00@@UAEXPAXPAUVec_309aa0@2@@Z
void PhysicsJoint_309aa0::v13(void* x, Vec_309aa0* y) {
    if (this == mgr->joint)
        return;
    if (other)
        other->v13(x, y);
    if (limit > 1e-5f && flag) {
        ((owners::X_2fcb80 *)y)->FUN_002fcb80(1.0f - limit);
        hulk_freg t = force * limit;
        y->a += t;
        y->b += t;
        y->c += t;
    }
}

} // namespace fn_fca90e00

// 0x00309b20 FUN_00309b20 (40 B): equivalent/0x00309b20.cpp
// sym: ?FUN_00309b20@Node_309b20@owners@@QAE_NPAU12@@Z @b6c55144e853 @w64d5adcb03f1 @v77282a9ac477
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_00309b20 @ 0x00309b20
bool owners::Node_309b20::FUN_00309b20(owners::Node_309b20* other) { int valueToFind = value; if (valueToFind >= other->value) return false; while (other->value > valueToFind) { other = other->next; if (!other) return false; if (other->value == valueToFind) return true; } return false; }

namespace fn_fca90e00 {

// 0x00309b80 FUN_00309b80 (69 B): matches/0x00309b80.cpp
// sym: ?Apply@Thing_309b80@fn_fca90e00@@UAEXH@Z
// data: gHalf = DAT_004d3188
void Thing_309b80::Apply(int x) {
    int local[3];
    if (!Check()) {
        Get(&local[0]);
        FUN_00305800(&local[0], x, (*(float*)&DAT_004d3188));
        Apply(x);
    }
}

} // namespace fn_fca90e00

// 0x00309bd0 physics::PhysicsJoint1D::vfunc_18 (52 B): matches/0x00309bd0.cpp [wrapped: merged class would differ: PhysicsJoint1D: field scale: Field(+0x10c float scale) vs Field(+0xe8 float scale)]
// sym: ?vfunc_18@PhysicsJoint1D@fn_00309bd0@@UAEXIPAM@Z
namespace fn_00309bd0 {
struct PhysicsJoint {
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
};
struct PhysicsJoint1D : PhysicsJoint {
    virtual void b15();
    virtual void b16(unsigned int, float*);
    virtual void b17();
    virtual void vfunc_18(unsigned int, float*);
    char pad[0xe4];
    float scale;
};
void PhysicsJoint1D::vfunc_18(unsigned int p, float* v) {
    b16(p, v);
    float f = scale;
    v[0] = f * v[0];
    v[1] = f * v[1];
    v[2] = f * v[2];
}
} // namespace fn_00309bd0


// 0x00309c10 physics::PhysicsJoint1D::vfunc_17 (149 B): equivalent/0x00309c10.cpp [wrapped: conflict: physics::PhysicsJoint1D]
// sym: ?vfunc_17@PhysicsJoint1D@physics@fn_00309c10@@UAEXPAUV3_309c10@3@M0@Z @52e65bd501a1 @w3faa4a87c496 @va547398c504b
namespace fn_00309c10 {
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 0/0)
// physics::PhysicsJoint1D::vfunc_17 @ 0x00309c10
struct V3_309c10 {
    float x, y, z;
};

namespace physics {

class PhysicsJoint1D {
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
    virtual void GetAxis(V3_309c10 *out);
    virtual void v16();
    virtual void vfunc_17(V3_309c10 *a, float s, V3_309c10 *out);
};

void PhysicsJoint1D::vfunc_17(V3_309c10 *a, float s, V3_309c10 *out)
{
    V3_309c10 l;
    GetAxis(&l);
    hulk_freg cx = l.y * a->z - l.z * a->y;
    hulk_freg cy = l.z * a->x - l.x * a->z;
    l.z = l.x * a->y - l.y * a->x;
    volatile float inv = 1.0f / s;
    l.x = cx * inv;
    hulk_freg sy = cy * inv;
    hulk_freg sz = l.z * inv;
    hulk_freg dot = sy * out->y + l.x * out->x + sz * out->z;
    out->x = l.x * dot;
    out->y = sy * dot;
    out->z = sz * dot;
}

}
} // namespace fn_00309c10


// 0x00309cb0 physics::PhysicsJoint1D::vfunc_21 (77 B): matches/0x00309cb0.cpp
// sym: ?vfunc_21@PhysicsJoint1D@physics@@UAEXPAX@Z
// data: zero_309cb0 = DAT_003f32e0
void physics::PhysicsJoint1D::vfunc_21(void* __p0) { float * p = (float *)__p0;

    if ((this->f_100 * p[1] + this->f_104 * p[2] + this->f_fc * p[0]) * this->f_10c < DAT_003f32e0) {
        this->f_ec = 1;
        this->f_108 = -this->f_10c;
    }
}


// 0x00309d00 physics::PhysicsJoint3D::vfunc_12 (699 B): equivalent/0x00309d00.cpp [wrapped: conflict: physics::PhysicsJoint3D]
// sym: ?vfunc_12@PhysicsJoint3D@physics@fn_00309d00@@UAEXMMMMPAUV3_309d00@3@0M@Z @753ac4ae018e @wff72609af44d @v32334db3e7e9
namespace fn_00309d00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::PhysicsJoint3D::vfunc_12 @ 0x00309d00

struct V3_309d00 {
    float x, y, z;
};

struct Frame_309d00 {
    char pad0[0x10];
    V3_309d00 v;
    void FUN_002fd730();
};

struct Mid_309d00 {
    char pad0[0x8c];
    Frame_309d00 *frame;
};

struct Basis_309d00 {
    char pad0[0x1c];
    V3_309d00 w;
};

struct Body_309d00 {
    char pad0[0x10];
    Mid_309d00 *mid;
    char pad14[8];
    Basis_309d00 *basis;
    void FUN_00310490(void *a, V3_309d00 *out, int z);
};

namespace physics {

class PhysicsJoint3D {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(float a1, float a2, float a3, float a4, V3_309d00 *p5, V3_309d00 *p6, float a7);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual float vfunc_20(V3_309d00 *t);
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    char pad4[4];
    void *target;       // 8
    char padc[0xc];
    Body_309d00 *body;         // 0x18
    char pad1c[0xc8];
    float scale;        // 0xe4
    char pade8[0x38];
    V3_309d00 accum;           // 0x120
    char pad12c[0x25];
    char flag151;
};

void PhysicsJoint3D::vfunc_12(float a1, float a2, float a3, float a4, V3_309d00 *p5, V3_309d00 *p6, float a7)
{
    // Values the original keeps in x87 registers are double (80-bit); spills are volatile float.
    V3_309d00 u;
    body->FUN_00310490(target, &u, 0);
    double cx = u.y * p5->z - u.z * p5->y;
    double cy = u.z * p5->x - u.x * p5->z;
    volatile float cz = u.x * p5->y - u.y * p5->x;
    volatile float na1 = -a1;
    V3_309d00 t;
    t.x = (float)(cx * na1);
    double cyn = cy * na1;
    double czn = cz * na1;
    double vx = u.y * p6->z - u.z * p6->y;
    double vy = u.z * p6->x - u.x * p6->z;
    volatile float vz = u.x * p6->y - u.y * p6->x;
    volatile float na2 = -a2;
    t.x = (float)(vx * na2 + t.x);
    t.y = (float)(vy * na2 + cyn);
    t.z = (float)(vz * na2 + czn);
    V3_309d00 *w = &body->basis->w;
    double wx = u.y * w->z - u.z * w->y;
    double wy = u.z * w->x - u.x * w->z;
    volatile float wz = u.x * w->y - u.y * w->x;
    t.x = (float)(wx * a3 + t.x);
    t.y = (float)(wy * a3 + t.y);
    t.z = (float)(wz * a3 + t.z);
    if (a4 != 0.0f) {
        Frame_309d00 *q = body->mid->frame;
        q->FUN_002fd730();
        if (q->v.x * q->v.x + q->v.y * q->v.y + q->v.z * q->v.z > (*(float*)&DAT_004218f0)) {
            q = body->mid->frame;
            q->FUN_002fd730();
            double r1 = q->v.z * p5->y - q->v.y * p5->z;
            double r2 = p5->z * q->v.x - q->v.z * p5->x;
            double r3 = q->v.y * p5->x - p5->y * q->v.x;
            volatile float x = (float)(u.y * r3 - r2 * u.z);
            volatile float y = (float)(u.z * r1 - r3 * u.x);
            double z = r2 * u.x - u.y * r1;
            t.x = (float)(x * a4 + t.x);
            t.y = (float)(y * a4 + t.y);
            t.z = (float)(z * a4 + t.z);
        }
    }
    double m = a7 * scale;
    t.x = (float)(t.x * m);
    t.y = (float)(t.y * m);
    t.z = (float)(t.z * m);
    float r = vfunc_20(&t);
    if (r > 0.0f) {
        accum.x = t.x * r + accum.x;
        accum.y = t.y * r + accum.y;
        accum.z = t.z * r + accum.z;
        flag151 = 0;
    }
}

}
} // namespace fn_00309d00


// 0x00309fc0 physics::PhysicsJoint3D::vfunc_26 (202 B): equivalent/0x00309fc0.cpp [wrapped: conflict: physics::PhysicsJoint3D]
// sym: ?vfunc_26@PhysicsJoint3D@physics@fn_00309fc0@@UAE_NPBUVec3_309fc0@3@PAU43@@Z @4e55851ff1a2 @w0919afdde998 @vd238979ec14d
namespace fn_00309fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::PhysicsJoint3D::vfunc_26 @ 0x00309fc0
struct Vec3_309fc0 { float x,y,z; };
struct JointData_309fc0 { void FUN_00310490(void*, Vec3_309fc0*, int); };
namespace physics {
struct PhysicsJoint3D {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual float vfunc_20(Vec3_309fc0*); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual bool vfunc_26(const Vec3_309fc0*,Vec3_309fc0*);
 char pad4[4]; void* body; char padc[12]; JointData_309fc0* data; char pad1c[200]; float strength;
};
bool PhysicsJoint3D::vfunc_26(const Vec3_309fc0* axis,Vec3_309fc0* output) {
 Vec3_309fc0 v;
 data->FUN_00310490(body,&v,0);
 double cy=(double)v.z*axis->x-(double)v.x*axis->z;
 double cz=(double)v.x*axis->y-(double)v.y*axis->x;
 double cx=(double)v.y*axis->z-(double)v.z*axis->y;
 output->x=(float)cx; output->y=(float)cy; output->z=(float)cz;
 double scale=-(2.0*(double)strength);
 output->x=(float)(scale*output->x);
 output->y=(float)(scale*cy);
 output->z=(float)(scale*cz);
 vfunc_20(output);
 float factor=vfunc_20(output);
 if(factor>0.0f) { output->x*=factor; output->y*=factor; output->z*=factor; return true; }
 return false;
}
}
} // namespace fn_00309fc0


// 0x0030a090 physics::PhysicsJoint3D::vfunc_21 (99 B): matches/0x0030a090.cpp
// sym: ?vfunc_21@PhysicsJoint3D@physics@@UAEXPAX@Z
// data: zero_30a090 = DAT_003f32e0
void physics::PhysicsJoint3D::vfunc_21(void* __p0) { float * p = (float *)__p0;

    if (((*(volatile float (*)[3])&this->f_120)[2] * p[2] + (*(volatile float (*)[3])&this->f_120)[1] * p[1]) + (*(volatile float (*)[3])&this->f_120)[0] * p[0] < DAT_003f32e0) {
        this->f_ec = 1;
        (*(float (*)[3])&this->f_114)[0] = -(*(volatile float (*)[3])&this->f_120)[0];
        (*(float (*)[3])&this->f_114)[1] = -(*(volatile float (*)[3])&this->f_120)[1];
        (*(float (*)[3])&this->f_114)[2] = -(*(volatile float (*)[3])&this->f_120)[2];
    }
}


// 0x0030a130 FUN_0030a130 (76 B): matches/0x0030a130.cpp
// sym: ?FUN_0030a130@Buffer_30a130@owners@@QAE_NH@Z
bool owners::Buffer_30a130::FUN_0030a130(int n) {
    if (n != 0) {
        int* p = (int*)alloc(n * 4);
        begin = p;
        if (p != 0) {
            limit = (int*)((char*)p + n * 4);
            end = p;
            return true;
        }
    } else {
        begin = 0;
    }
    end = 0;
    limit = 0;
    return false;
}


// 0x0030a260 FUN_0030a260 (15 B): matches/0x0030a260.cpp
// sym: ?FUN_0030a260@C_30a260@owners@@QAEXH@Z
void owners::C_30a260::FUN_0030a260(hulk_intptr x) {
    value = ((int)x);
    ((ThisCall_003099d0*)(this))->called_003099d0();
}

namespace fn_fca90e00 {

// 0x0030a270 FUN_0030a270 (416 B): equivalent/0x0030a270.cpp
// sym: ?FUN_0030a270@Node@fn_fca90e00@@QAEHPAUVec3_30a270@2@0@Z @cffb5def8980 @w140094af5815 @vfbca51948024
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 16/16)
// FUN_0030a270 @ 0x0030a270
int Node::FUN_0030a270(Vec3_30a270 *pos, Vec3_30a270 *dir)
{
    weight = 0.0f;
    flagEE = 0;
    flagEC = 0;
    if (this != ctx->active) {
        if (radius > 0.0f) {
            Vec3_30a270 d;
            d.x = pos->x - origin.x;
            d.y = pos->y - origin.y;
            d.z = pos->z - origin.z;
            vfunc_16(&d, &d);
            float len = (float)sqrt(d.z * d.z + d.y * d.y + d.x * d.x);
            if (len > DAT_004d3178 * ctx->table->rows[index].limit) {
                d.x = d.x * (1.0f / len);
                d.y = d.y * (1.0f / len);
                d.z = d.z * (1.0f / len);
                if (parent && parent == ctx->active) {
                    weight = 1.0f;
                } else {
                    float dot = d.z * dir->z + d.y * dir->y + d.x * dir->x;
                    FloatBits_30a270 u;
                    u.f = dot;
                    u.i &= 0x7fffffff;
                    if (u.f >= DAT_004d317c)
                        weight = 0.0f;
                    else
                        weight = radius;
                }
            }
        }
        if (parent)
            parent->FUN_0030a270(pos, dir);
    }
    int r = (weight == 0.0f);
    flagED = (char)r;
    return r;
}

} // namespace fn_fca90e00

// 0x0030a410 physics::PhysicsJoint::vfunc_14 (919 B): equivalent/0x0030a410.cpp [wrapped: conflict: physics::PhysicsJoint]
// sym: ?vfunc_14@PhysicsJoint@physics@fn_0030a410@@UAE_NPAUVec3_30a410@3@0PAUBasis_30a410@3@@Z @1676e210bd64 @w3cdb710d911d @v22c7966d33a2
namespace fn_0030a410 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 27/28, incomplete)
// physics::PhysicsJoint::vfunc_14 @ 0x0030a410


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_30a410 {
    float x, y, z;
    void FUN_000111b0(Vec3_30a410* a, Vec3_30a410* b);
};

struct Basis_30a410 {
    void FUN_002fd020(Vec3_30a410* in, Vec3_30a410* out);
};


namespace physics {

class PhysicsJoint;

struct JointEntry {
    char pad00[0x18];
    float limit;
};

struct JointTable {
    char pad00[0x10];
    JointEntry* entries;
};

class PhysicsJoint {
public:
    virtual void vfunc_0();
    char active;
    char pad05[3];
    int index;
    char pad0c[0x18 - 0xc];
    class PhysicsObjectBase* owner;
    PhysicsJoint* child;
    char pad20[0xd4 - 0x20];
    Vec3_30a410 anchor;
    char padE0[0xe8 - 0xe0];
    float weight;
    char padEC;
    char flagED;
    char flagEE;
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13();
    virtual bool vfunc_14(Vec3_30a410* p1, Vec3_30a410* p2, Basis_30a410* basis);
    virtual void vfunc_15();
    virtual void vfunc_16(Vec3_30a410* in, Vec3_30a410* out);
    virtual void vfunc_17(Vec3_30a410* a, float len, Vec3_30a410* b);
    virtual void vfunc_18();
    virtual void vfunc_19(Vec3_30a410* v);
    virtual float vfunc_20(Vec3_30a410* v);
    virtual void vfunc_21(Vec3_30a410* v);
};

class PhysicsObjectBase {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26();
    virtual void vfunc_27(int a);
    char pad04[0x218 - 4];
    PhysicsJoint* current;
    char pad21c[4];
    JointTable* table;
    float scale;
};

bool PhysicsJoint::vfunc_14(Vec3_30a410* p1, Vec3_30a410* p2, Basis_30a410* basis)
{
    if (this == owner->current)
        return true;

    if (weight > 0.0f && !flagED && active) {
        struct Frame {
            Vec3_30a410 b;
            Vec3_30a410 a;
            Vec3_30a410 c;
            Vec3_30a410 d;
        } f;
        float len;

        f.a.x = p1->x - anchor.x;
        f.a.y = p1->y - anchor.y;
        f.a.z = p1->z - anchor.z;
        vfunc_16(&f.a, &f.a);
        len = (float)sqrt(f.a.z * f.a.z + f.a.y * f.a.y + f.a.x * f.a.x);
        basis->FUN_002fd020(p2, &f.b);

        f.b.x = f.b.x * weight;
        f.b.y = f.b.y * weight;
        f.b.z = f.b.z * weight;
        vfunc_17(&f.a, len, &f.b);

        double bmag = sqrt(f.b.z * f.b.z + f.b.y * f.b.y + f.b.x * f.b.x);
        float limit = owner->table->entries[index].limit;
        if (limit < len)
            limit = len;
        double t = limit / owner->scale * DAT_004d31b0;
        if (bmag > t) {
            flagEE = 1;
            weight = weight / bmag * t * 0.99f;
            return false;
        }

        float inv = 1.0f / bmag;
        hulk_freg dotx = (f.b.y * p2->y + f.b.z * p2->z + f.b.x * p2->x) * inv;
        float dot = dotx;                    // stored (fst), but compared unrounded (fcomp of st0)
        if (!(dotx > 0.0f) || !(bmag > DAT_00555450)) {
            weight = 0.0f;
            return false;
        }

        double s = inv * weight * dot;
        f.d.x = f.b.x * s;
        f.d.y = f.b.y * s;
        f.d.z = f.b.z * s;
        f.c.FUN_000111b0(&f.a, &f.b);
        double k = 1.0f / (len * len);
        f.c.x = f.c.x * k;
        f.c.y = f.c.y * k;
        f.c.z = f.c.z * k;
        hulk_freg r = vfunc_20(&f.c);         // st0 (fcom, fld st(0); fmul)
        if (r < DAT_004d3184) {
            weight = r * weight;
            if (r == 0.0f)
                vfunc_21(&f.c);
            return false;
        }
        p2->x = p2->x - f.d.x;
        p2->y = p2->y - f.d.y;
        p2->z = p2->z - f.d.z;
        vfunc_19(&f.c);
        flagED = 1;
    } else if (weight > 0.0f) {
        hulk_freg rest = 1.0f - weight;      // st0 (fld st(0); fmul)
        p2->x = p2->x * rest;
        p2->y = p2->y * rest;
        p2->z = p2->z * rest;
    }

    float ax = p2->x < 0 ? -p2->x : p2->x;
    float ay = p2->y < 0 ? -p2->y : p2->y;
    float az = p2->z < 0 ? -p2->z : p2->z;
    PhysicsJoint* c = child;
    if (az + ay + ax > 0.000001f) {
        if (c)
            return c->vfunc_14(p1, p2, basis);
        return true;
    }
    if (c)
        c->vfunc_3();
    else
        owner->vfunc_27(-1);
    return true;
}

}
} // namespace fn_0030a410

namespace fn_fca90e00 {

// 0x0030a7b0 FUN_0030a7b0 (532 B): equivalent/0x0030a7b0.cpp
// sym: ?FUN_0030a7b0@Mover_30a7b0@fn_fca90e00@@QAEXUVec3_30a7b0@2@0@Z @6e354f286391 @wd431a25a517b @v48c2dc241004
// STATUS: equivalent (tools/equiv.py level 3: 190 inputs, branch coverage 13/14, incomplete)
// FUN_0030a7b0 @ 0x0030a7b0
void Mover_30a7b0::FUN_0030a7b0(Vec3_30a7b0 a, Vec3_30a7b0 b)
{
    Vec3_30a7b0 ref;
    if (anchor) {
        ref = anchor->pos;
    } else {
        ref = store->refPos;
    }

    struct Frame {
        Vec3_30a7b0 v;
        volatile float dx;
        float spare[2];
    } f;
    Vec3_30a7b0 &v = f.v;
    f.dx = target.x - ref.x;
    float dx = f.dx;
    double dy = target.y - ref.y;
    double dz = target.z - ref.z;

    v.x = b.y * dz - b.z * dy;
    v.z = b.x * dy - b.y * dx;
    double cy = b.z * dx - b.x * dz;

    a.x += v.x;
    a.y += cy;
    a.z += v.z;

    Item_30a7b0 *item = &store->table->items[index];
    ((owners::Obj_2fd730 *)item)->FUN_002fd730();
    item->delta.x += a.x;
    item->delta.y += a.y;
    item->delta.z += a.z;

    if ((pending > 0.0f || hasPending) && active) {
        getDelta(&v);
        afterDelta();
        b.x += v.x;
        pending = 0.0f;
        b.y += v.y;
        b.z += v.z;
    }

    item = &store->table->items[index];
    ((owners::Obj_2fd730 *)item)->FUN_002fd730();
    item->pos.x += b.x;
    item->pos.y += b.y;
    item->pos.z += b.z;

    for (unsigned i = 0; i < (unsigned)(end - begin); i++)
        begin[i]->FUN_0030a7b0(a, b);

    clearDelta();
}


// 0x0030a9d0 FUN_0030a9d0 (825 B): equivalent/0x0030a9d0.cpp
// sym: ?FUN_0030a9d0@Body_30a9d0@fn_fca90e00@@QAEXUVec3_30a9d0@2@0D@Z @6d113a570789 @w24e4e712fa98
// STATUS: equivalent (tools/equiv.py level 3: 2142 inputs, branch coverage 35/36, incomplete)
// FUN_0030a9d0 @ 0x0030a9d0
void Body_30a9d0::FUN_0030a9d0(Vec3_30a9d0 a, Vec3_30a9d0 b, char flag)
{
    struct Frame {
        Vec3_30a9d0 c;
        Vec3_30a9d0 v;
        float dx;
        float spare[2];
    } f;
    float px, py;
    if (link != 0) {
        px = link->pos.x;
        py = link->pos.y;
        f.v.z = link->pos.z;
    } else {
        px = owner->pos98.x;
        py = owner->pos98.y;
        f.v.z = owner->pos98.z;
    }
    f.dx = pos.x - px;
    double dy = pos.y - py;
    double dz = pos.z - f.v.z;
    float dx = f.dx;
    Vec3_30a9d0& c = f.c;
    c.x = b.y * dz - b.z * dy;
    c.y = b.z * dx - dz * b.x;
    c.z = dy * b.x - b.y * dx;
    Elem_30a9d0* e = owner->table->elems + f8;
    a.x = c.x + a.x;
    a.y = a.y + c.y;
    a.z = a.z + c.z;
    e->FUN_002fd730();
    e->p4.x = a.x + e->p4.x;
    e->p4.y = a.y + e->p4.y;
    e->p4.z = a.z + e->p4.z;
    if (flag == 1) {
        Node* n = owner->list;
        char found = 0;
        if (f8 < n->f8) {
            while (n->f8 > f8) {
                n = n->next;
                if (n == 0)
                    break;
                if (n->f8 == f8) {
                    found = 1;
                    break;
                }
            }
        }
        flag = found;
    }
    if (b4) {
        if (!bec && !flag && w6 > 0 && (void*)this != (void*)owner->list) {
            Owner_30a9d0* o = owner;
            c.FUN_000111b0(&b, &v80);
            c.x = c.x + a.x;
            c.y = a.y + c.y;
            c.z = a.z + c.z;
            float k = DAT_004d3180 * o->f224;
            if (c.z * c.z + c.y * c.y + c.x * c.x > k * k) {
                Vec3_30a9d0& v = f.v;
                if (v26(&c, &v)) {
                    b.x = v.x + b.x;
                    b.y = v.y + b.y;
                    b.z = v.z + b.z;
                    v24(&v);
                }
            }
        }
        if (fe8 > 0.0f || bec) {
            Vec3_30a9d0& v = f.v;
            v22(&v);
            v23();
            fe8 = 0.0f;
            b.x = v.x + b.x;
            b.y = v.y + b.y;
            b.z = v.z + b.z;
        }
    }
    Elem_30a9d0* e2 = owner->table->elems + f8;
    e2->FUN_002fd730();
    e2->p10.x = b.x + e2->p10.x;
    e2->p10.y = b.y + e2->p10.y;
    e2->p10.z = b.z + e2->p10.z;
    hulk_uintptr n = childEnd - childBegin;
    if (n != 0) {
        for (unsigned int i = 0; i < (unsigned int)(childEnd - childBegin); i++)
            childBegin[i]->FUN_0030a9d0(a, b, flag);
    }
    v3();
}


// 0x0030ad10 FUN_0030ad10 (175 B): equivalent/0x0030ad10.cpp
// sym: ?target@Object@fn_fca90e00@@QAEXDPAM@Z @2f0486852b36 @w6e1c927d1d29 @ve727afcf87d4
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0030ad10 @ 0x0030ad10
void Object::target(char mode, float* out) {
 if (!mode) { *out=v6(); return; }
 Vec3_30ad10 v;
 helper->FUN_00310490(value,&v,0);
 float a=v.z*z + v.y*y + v.x*x;
 *out=a;
 float r;
 if (!(a >= 1.0f)) r=FUN_00018a20(a); else r=0.0f;
 *out=r;
 union { float f; unsigned int u; } bits;
 bits.f=r; bits.u &= 0x7fffffff;
 if (bits.f < 0.1f) *out=0.0f;
}


// 0x0030adc0 FUN_0030adc0 (220 B): equivalent/0x0030adc0.cpp
// sym: ?FUN_0030adc0@fn_fca90e00@@YGMMMMM@Z @d68e9193d9ae @we10a83d996e8 @v6c2508114c98
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 18/18)
// FUN_0030adc0 @ 0x0030adc0
hulk_freg __stdcall FUN_0030adc0(float start, float delta, float lower, float upper)
{
    union { float f; unsigned int u; } magnitude;
    magnitude.f = delta;
    magnitude.u &= 0x7fffffff;
    if (!(magnitude.f > 0.0f)) return 1.0f;
    double end = (double)start + (double)delta;
    if (end <= upper && end >= lower) return 1.0f;
    if (start >= upper && delta > 0.0f) return 0.0f;
    if (start <= lower && delta < 0.0f) return 0.0f;
    double fraction = ((double)(delta > 0.0f ? upper : lower) - (double)start) / (double)delta;
    if (fraction > 1.0f) return 1.0f;
    return (hulk_freg)fraction;
}

} // namespace fn_fca90e00
