// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
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
    void Init_002fca90() throw();
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
    virtual PhysicsJoint_30d590* d27();
    virtual void v28(PhysicsJoint_30d590* p);
    int m4, m8, mc, m10, m14, m18, m1c;
    int m20, m24, m28;
    char p2c[0x1c];
    SymMatrix_30d590 h48;
    SymMatrix_30d590 h64;
    char tail[0xf8 - 0x80];
    PhysicsJoint_30d590() throw() {
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
    PhysicsJoint0D_30d590() throw() {}
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
    *(int*)((char*)this + 0x118) = 0;
    *(int*)((char*)this + 0x114) = 0;
    *(int*)((char*)this + 0x110) = 0;
    *(int*)((char*)this + 0x10c) = 0;
}


// 0x003097d0 physics::PhysicsJoint3D::vfunc_2 (55 B): matches/0x003097d0.cpp
// sym: ?vfunc_2@PhysicsJoint3D@physics@@UAEXXZ
 // namespace physics
void physics::PhysicsJoint3D::vfunc_2() {
    vfunc_1();
    *(int*)((char*)this + 0x140) = 0;
    *(int*)((char*)this + 0x13c) = 0;
    *(int*)((char*)this + 0x138) = 0;
    *(int*)((char*)this + 0x14c) = 0;
    *(int*)((char*)this + 0x148) = 0;
    *(int*)((char*)this + 0x144) = 0;
    *((char*)this + 0x150) = 1;
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
// sym: ?FUN_00309940@Obj_309940@fn_fca90e00@@QAEXPAUSrc_309940@2@@Z
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
// sym: ?FUN_00309b20@Node_309b20@owners@@QAE_NPAU12@@Z
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
// sym: ?vfunc_17@PhysicsJoint1D@physics@fn_00309c10@@UAEXPAUV3_309c10@3@M0@Z
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
// sym: ?vfunc_12@PhysicsJoint3D@physics@fn_00309d00@@UAEXMMMMPAUV3_309d00@3@0M@Z
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
// sym: ?vfunc_26@PhysicsJoint3D@physics@fn_00309fc0@@UAE_NPBUVec3_309fc0@3@PAU43@@Z
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
// sym: ?FUN_0030a270@Node@fn_fca90e00@@QAEHPAUVec3_30a270@2@0@Z
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
// sym: ?vfunc_14@PhysicsJoint@physics@fn_0030a410@@UAE_NPAUVec3_30a410@3@0PAUBasis_30a410@3@@Z
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
        float dot = (f.b.y * p2->y + f.b.z * p2->z + f.b.x * p2->x) * inv;
        if (!(dot > 0.0f) || !(bmag > DAT_00555450)) {
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
        float r = vfunc_20(&f.c);
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
        float rest = 1.0f - weight;
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
// sym: ?FUN_0030a7b0@Mover_30a7b0@fn_fca90e00@@QAEXUVec3_30a7b0@2@0@Z
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
// sym: ?FUN_0030a9d0@Body_30a9d0@fn_fca90e00@@QAEXUVec3_30a9d0@2@0D@Z
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
// sym: ?target@Object@fn_fca90e00@@QAEXDPAM@Z
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
// sym: ?FUN_0030adc0@fn_fca90e00@@YGMMMMM@Z
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

// 0x0030aea0 physics::PhysicsJoint1D::vfunc_9 (77 B): matches/0x0030aea0.cpp
// sym: ?vfunc_9@PhysicsJoint1D@physics@@UAEXMM@Z
 // namespace physics
void physics::PhysicsJoint1D::vfunc_9(float x, float y) {
    (*(float *)&this->f_10) = x;
    (*(float *)&this->f_14) = y;
    if (y == x && y > 0.0f) {
        this->f_f8 = 0;
        (*(float *)&this->f_10) = -y;
        return;
    }
    this->f_f8 = 1;
}


// 0x0030aef0 physics::PhysicsJoint1D::vfunc_11 (670 B): equivalent/0x0030aef0.cpp [wrapped: conflict: PhysicsJoint1D]
// sym: ?vfunc_11@PhysicsJoint1D@fn_0030aef0@@UAEXMMM@Z
namespace fn_0030aef0 {
// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 35/36, incomplete)
// physics::PhysicsJoint1D::vfunc_11 @ 0x0030aef0
  // 1.0
  // 0.0
  // -pi
  // pi
  // 5.0
  // 0.0001
  // 0.01
  // 0.625
  // 0.625
  // 1.0

extern "C" float __cdecl FUN_00083d90(float *value);

static inline float Abs(float v)
{
    union {
        float f;
        unsigned int u;
    } b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class PhysicsJoint1D {
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
    virtual void vfunc_11(float a1, float a2, float a3);
    char pad04[0x10 - 4];
    float limit10;
    float limit14;
    char pad18[0xf4 - 0x18];
    int mode;
    char flag;
    char padf9[0x10c - 0xf9];
    float pos;      // 0x10c
    float posGoal;  // 0x110
    float vel;      // 0x114
    float velGoal;  // 0x118
};

void PhysicsJoint1D::vfunc_11(float a1, float a2, float a3)
{
    if (pos == (*(float*)&DAT_003f32e0) && vel == (*(float*)&DAT_003f32e0))
        return;

    float newVel = (velGoal - vel) * DAT_004d31a4 * a3 + vel;
    float newPos = ((posGoal - pos) * DAT_004d31a8 * a3 + pos) * a2;
    vel = newVel;
    pos = newPos;

    switch (mode) {
    case 0: {
        hulk_freg v = FUN_00083d90(&vel) * ((*(float*)&DAT_003f32dc) - a1) * DAT_004d31b4;
        if (Abs(v) < Abs(newVel))
            vel = newVel - v;
        else
            vel = 0.0f;
        break;
    }
    case 1:
        if (((*(float*)&DAT_003f32dc) - a1) * Abs(newVel) < DAT_004d31b4)
            vel = newVel * a1;
        else
            vel = ((*(float*)&DAT_003f32dc) - DAT_004d31b4 / Abs(newVel)) * newVel;
        break;
    }

    volatile float xs = newPos * a3 + vel;
    float x = xs;
    vel = x;
    if (x > (*(float*)&DAT_00431dbc)) {
        hulk_freg v = vel;
        do {
            v -= (*(float*)&DAT_00431dbc);
        } while (v > (*(float*)&DAT_00431dbc));
        vel = v;
    } else if (x < (*(float*)&DAT_00431dbc) && x < (*(float*)&DAT_00417e28)) {
        hulk_freg v = vel;
        do {
            v += (*(float*)&DAT_00431dbc);
        } while (v < (*(float*)&DAT_00417e28));
        vel = v;
    }

    if (Abs(vel) > DAT_004d3190) {
        if (Abs(vel) > DAT_004d318c)
            vel = FUN_00083d90(&vel) * DAT_004d318c;
        bool damp = false;
        if (flag) {
            if (limit14 - limit10 < vel)
                damp = true;
            else if (-(limit14 - limit10) > vel)
                damp = true;
        }
        if (!damp) {
            if (vel > limit14)
                damp = true;
            else if (-limit10 > vel)
                damp = true;
        }
        if (damp)
            vel = ((*(float*)&DAT_003f32dc) - DAT_004d31a0) * vel;
    } else {
        vfunc_2();
    }
    velGoal = vel;
    posGoal = pos;
}
} // namespace fn_0030aef0


// 0x0030b190 physics::PhysicsJoint1D::vfunc_25 (295 B): equivalent/0x0030b190.cpp
// sym: ?vfunc_25@PhysicsJoint1D@physics@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// physics::PhysicsJoint1D::vfunc_25 @ 0x0030b190
void physics::PhysicsJoint1D::vfunc_25() {
 union { float f; unsigned int u; } absolute;
 absolute.f = this->f_10c;
 absolute.u &= 0x7fffffff;
 if (absolute.f > DAT_004d3198) {
 float sign = 0.0f;
 if (this->f_10c < 0.0f) sign = -1.0f;
 else if (this->f_10c > 0.0f) sign = 1.0f;
 this->f_10c = sign * DAT_004d3198;
 }
 if (DAT_004d319c) {
 if (this->f_11c > (*(float *)&this->f_14)) {
 double delta = (double)this->f_11c - (*(float *)&this->f_14);
 this->f_11c = (*(float *)&this->f_14);
 this->f_114 = (float)((double)this->f_114 - delta * DAT_004d31a0);
 if (this->f_10c > 0.0f) this->f_10c = DAT_004d31d8 * this->f_10c;
 } else if (this->f_11c < (*(float *)&this->f_10)) {
 double delta = (double)this->f_11c - (*(float *)&this->f_10);
 this->f_11c = (*(float *)&this->f_10);
 this->f_114 = (float)((double)this->f_114 - delta * DAT_004d31a0);
 if (this->f_10c < 0.0f) this->f_10c = DAT_004d31d8 * this->f_10c;
 }
 }
}

namespace fn_fca90e00 {

// 0x0030b2c0 FUN_0030b2c0 (211 B): equivalent/0x0030b2c0.cpp
// sym: ?target@Object@fn_fca90e00@@QAEMM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0030b2c0 @ 0x0030b2c0
float Object::target(float delta) {
 float limit=1.0f;
 if(delta==0.0f || time+delta==0.0f) return limit;
 float result=FUN_0030adc0(time*settings->scale+offset,delta*settings->scale,lower,upper);
 if(result>0.0f) limit=FUN_0030adc0(time,delta,-DAT_004d3198,DAT_004d3198);
 return result<limit ? result:limit;
}

} // namespace fn_fca90e00

// 0x0030b3a0 FUN_0030b3a0 (188 B): equivalent/0x0030b3a0.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_0030b3a0@@QAEXXZ
namespace fn_0030b3a0 {
// STATUS: equivalent (tools/equiv.py level 3: 12336 inputs, branch coverage 4/4)
// FUN_0030b3a0 @ 0x0030b3a0
struct Vec3_30b3a0 { float x,y,z; };
struct ThisCall_0030ad10 {
    void FUN_0030ad10(unsigned int mode, float* result);
};
struct Provider_30b3a0 { void FUN_00310490(unsigned int id, Vec3_30b3a0* out, int flag); };
struct Object {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual float slot6();
 char pad04[8]; unsigned int id; char pad10[8]; Provider_30b3a0* provider; char pad1c[0x7c]; Vec3_30b3a0 axis; char pada4[0x54]; unsigned char mode; char padf9[3]; Vec3_30b3a0 direction; char pad108[0x14]; float result;
 void target();
};
void Object::target() {
 if (mode) {
  ((ThisCall_0030ad10*)(this))->FUN_0030ad10(mode, &result);
  Vec3_30b3a0 v;
  provider->FUN_00310490(id, &v, 0);
  if (((v.x*axis.y-v.y*axis.x)*direction.z + (v.z*axis.x-v.x*axis.z)*direction.y + (v.y*axis.z-v.z*axis.y)*direction.x) <= 0.0f) result=-result;
 } else result=slot6();
}
} // namespace fn_0030b3a0


// 0x0030b460 physics::PhysicsJoint3D::vfunc_9 (86 B): matches/0x0030b460.cpp
// sym: ?vfunc_9@PhysicsJoint3D@physics@@UAEXMM@Z
 // namespace physics
void physics::PhysicsJoint3D::vfunc_9(float a, float b) {
    (*(float *)&this->f_10) = a;
    (*(float *)&this->f_14) = b;
    if (b == a && b > 0.0f) {
        this->f_f8 = 0;
        (*(float *)&this->f_10) = -b;
    } else {
        this->f_f8 = 1;
        (*(float *)&this->f_10) = -b;
    }
}


// 0x0030b4c0 physics::PhysicsJoint3D::vfunc_11 (984 B): equivalent/0x0030b4c0.cpp [wrapped: conflict: physics::PhysicsJoint3D]
// sym: ?vfunc_11@PhysicsJoint3D@physics@fn_0030b4c0@@UAEXMMM@Z
namespace fn_0030b4c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 18/18; --wine 616 inputs)
// physics::PhysicsJoint3D::vfunc_11 @ 0x0030b4c0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_30b4c0 {
    float x, y, z;
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
    virtual void vfunc_11(float a1, float a2, float a3);
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

    char pad04[0x10 - 4];
    float f10;
    float f14;
    char pad18[0xf4 - 0x18];
    int mode;
    char padf8[0x120 - 0xf8];
    volatile Vec3_30b4c0 pos;
    Vec3_30b4c0 posTarget;
    volatile Vec3_30b4c0 vel;
    Vec3_30b4c0 velTarget;
    char settled;
    char flag151;
};

void PhysicsJoint3D::vfunc_11(float a1, float a2, float a3)
{
    if (flag151 == 1 && settled == 1) {
        return;
    }
    hulk_freg dx = posTarget.x - pos.x;
    hulk_freg dy = posTarget.y - pos.y;
    float dz = posTarget.z - pos.z;
    float step = DAT_004d31a8 * a3;
    pos.x = dx * (DAT_004d31a8 * a3) + pos.x;
    pos.y = dy * step + pos.y;
    pos.z = dz * step + pos.z;

    hulk_freg ex = velTarget.x - vel.x;
    hulk_freg ey = velTarget.y - vel.y;
    float ez = velTarget.z - vel.z;
    float step2 = DAT_004d31a4 * a3;
    vel.x = ex * (a3 * DAT_004d31a4) + vel.x;
    vel.y = ey * step2 + vel.y;
    vel.z = ez * step2 + vel.z;

    pos.x = a2 * pos.x;
    pos.y = a2 * pos.y;
    pos.z = a2 * pos.z;

    if (mode == 0) {
        double v = (1.0f - a1) * DAT_004d31b4;
        double s = vel.x * vel.x + (vel.y * vel.y + vel.z * vel.z);
        if (!(v * v >= s)) {
            double m = v * (-1.0f / sqrt(s));
            vel.x = m * vel.x + vel.x;
            vel.y = m * vel.y + vel.y;
            vel.z = m * vel.z + vel.z;
        } else {
            vel.z = 0.0f;
            vel.y = 0.0f;
            vel.x = 0.0f;
        }
    } else if (mode == 1) {
        double s = vel.x * vel.x + (vel.y * vel.y + vel.z * vel.z);
        double w = 1.0f - a1;
        if (DAT_004d31b8 > w * w * s) {
            vel.x = a1 * vel.x;
            vel.y = a1 * vel.y;
            vel.z = a1 * vel.z;
        } else {
            double u = 1.0f - sqrt(DAT_004d31b8 / s);
            vel.x = u * vel.x;
            vel.y = u * vel.y;
            vel.z = u * vel.z;
        }
    }

    vel.x = a3 * pos.x + vel.x;
    vel.y = a3 * pos.y + vel.y;
    vel.z = a3 * pos.z + vel.z;

    double s2 = vel.x * vel.x + (vel.y * vel.y + vel.z * vel.z);
    if (s2 > (double)DAT_004d3190 * DAT_004d3190) {
        double f;
        bool scale = true;
        if (s2 > (double)DAT_004d318c * DAT_004d318c) {
            f = DAT_004d318c / sqrt(s2);
        } else {
            double d = f14 - f10;
            if (s2 > d * d) {
                f = 1.0f - DAT_004d31a0;
            } else {
                scale = false;
            }
        }
        if (scale) {
            vel.x = f * vel.x;
            vel.y = f * vel.y;
            vel.z = f * vel.z;
        }
        settled = 0;
    } else {
        vfunc_2();
    }

    velTarget.x = vel.x;
    velTarget.y = vel.y;
    velTarget.z = vel.z;
    posTarget.x = pos.x;
    posTarget.y = pos.y;
    posTarget.z = pos.z;
}

}
} // namespace fn_0030b4c0

namespace fn_fca90e00 {

// 0x0030b8a0 physics::PhysicsJoint3D::vfunc_17 (71 B): matches/0x0030b8a0.cpp
// sym: ?vfunc_17@PhysicsJoint3D@fn_fca90e00@@UAEXPAMM0@Z
void PhysicsJoint3D::vfunc_17(float* a, float s, float* b) {
    hulk_freg d = b[2] * a[2];
    d = d + b[1] * a[1];
    d = d + a[0] * b[0];
    hulk_freg t = -(d / (s * s));
    b[0] = t * a[0] + b[0];
    b[1] = t * a[1] + b[1];
    b[2] = t * a[2] + b[2];
}


// 0x0030b8f0 physics::PhysicsJoint3D::vfunc_25 (453 B): equivalent/0x0030b8f0.cpp
// sym: ?FUN_0030b8f0@PhysicsJoint3D_30b8f0@fn_fca90e00@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// physics::PhysicsJoint3D::vfunc_25 @ 0x0030b8f0
void PhysicsJoint3D_30b8f0::FUN_0030b8f0()
{
    hulk_freg lenSq = (dir[0] * dir[0] + dir[1] * dir[1]) + dir[2] * dir[2];
    if (lenSq > (*(const float*)&DAT_004d31d4)) {
        hulk_freg s = (*(const float*)&DAT_004d3198) / (float)sqrt(lenSq);
        dir[0] = dir[0] * s;
        dir[1] = dir[1] * s;
        dir[2] = dir[2] * s;
    }

    if (!(*(const bool*)&DAT_004d319c))
        return;

    float a = slip < 0.0f ? -slip : slip;
    if (a > (*(const float*)&DAT_004d3194)) {
        float t;
        if (slip > 0.0f)
            t = slip - (*(const float*)&DAT_004d3194);
        else
            t = (*(const float*)&DAT_004d3194) + slip;
        t = t * (*(const float*)&DAT_004d31a0);
        float nt = -t;
        impulse[0] = nt * axis[0] + impulse[0];
        impulse[1] = nt * axis[1] + impulse[1];
        impulse[2] = nt * axis[2] + impulse[2];
        slip = slip - t;
    }

    if (speed > maxSpeed) {
        hulk_freg r = maxSpeed / speed;
        impulse[0] = impulse[0] * r;
        impulse[1] = impulse[1] * r;
        impulse[2] = impulse[2] * r;
        speed = maxSpeed;
    } else if (speed < minSpeed && minSpeed < 0.0f) {
        hulk_freg r = maxSpeed / speed;
        impulse[0] = impulse[0] * r;
        impulse[1] = impulse[1] * r;
        impulse[2] = impulse[2] * r;
        speed = minSpeed;
    }
}

} // namespace fn_fca90e00

// 0x0030bac0 physics::PhysicsJoint3D::vfunc_20 (968 B): equivalent/0x0030bac0.cpp [wrapped: conflict: physics::PhysicsJoint3D]
// sym: ?vfunc_20@PhysicsJoint3D@physics@fn_0030bac0@@UAEMPAUVec3_30bac0@3@@Z
namespace fn_0030bac0 {
// STATUS: equivalent (tools/equiv.py level 3: 20022 inputs, branch coverage 28/28)
// physics::PhysicsJoint3D::vfunc_20 @ 0x0030bac0

struct Vec3_30bac0 {
    float x, y, z;
};

struct World {
    char pad00[0x224];
    float dt;
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual hulk_freg vfunc_20(Vec3_30bac0 *dir);
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    float FUN_0030adc0(float a, float b, float lo, float hi);

    char pad04[0x10 - 4];
    float lo;
    float hi;
    World *world;
    char pad1c[0x98 - 0x1c];
    Vec3_30bac0 a;
    char pada4[0xfc - 0xa4];
    Vec3_30bac0 b;
    volatile Vec3_30bac0 c;
    char pad114[0x120 - 0x114];
    Vec3_30bac0 d;
    char pad12c[0x154 - 0x12c];
    float f154;
    float f158;
};

hulk_freg PhysicsJoint3D::vfunc_20(Vec3_30bac0 *dir)
{
    float cap = DAT_004d3198;
    float r1 = 1.0f;
    float r2 = 1.0f;
    float e1 = a.x * d.x + (a.y * d.y + a.z * d.z);
    float e2 = a.x * dir->x + (a.y * dir->y + a.z * dir->z);
    if (e2 != 0.0f) {
        World *w = world;
        r1 = FUN_0030adc0(e1 * w->dt + f158, e2 * w->dt, -DAT_004d3194, DAT_004d3194);
        if (!(r1 > 0.0f)) {
            return 0.0f;
        }
        r2 = FUN_0030adc0(e1, e2, -DAT_004d3198, cap);
        if (r2 == 0.0f) {
            return 0.0f;
        }
    }

    float r3 = 1.0f;
    float r4 = 1.0f;
    float e3 = b.x * d.x + (b.y * d.y + b.z * d.z);
    float e4 = b.x * dir->x + (b.y * dir->y + b.z * dir->z);
    if (e4 != 0.0f) {
        World *w = world;
        r3 = FUN_0030adc0(e3 * w->dt + f154, e4 * w->dt, lo, hi);
        if (r3 == 0.0f) {
            return 0.0f;
        }
        r4 = FUN_0030adc0(e3, e4, -DAT_004d3198, cap);
        if (r4 == 0.0f) {
            return 0.0f;
        }
    }

    c.x = b.y * a.z - b.z * a.y;
    c.y = a.x * b.z - a.z * b.x;
    c.z = a.y * b.x - a.x * b.y;
    float e5 = c.x * d.x + (c.y * d.y + c.z * d.z);
    float e6 = c.x * dir->x + (c.y * dir->y + c.z * dir->z);
    float m = 1.0f;
    if (e6 != 0.0f) {
        World *w = world;
        float r5 = FUN_0030adc0(e5 * w->dt, e6 * w->dt, lo, hi);
        if (r5 == 0.0f) {
            return 0.0f;
        }
        float r6 = FUN_0030adc0(e5, e6, -DAT_004d3198, cap);
        if (r6 == 0.0f) {
            return 0.0f;
        }
        m = (r5 < r6) ? r5 : r6;
    }
    m = (m < r3) ? m : r3;
    m = (m < r4) ? m : r4;
    m = (m < r1) ? m : r1;
    m = (m < r2) ? m : r2;
    return m;
}

}
} // namespace fn_0030bac0

namespace fn_fca90e00 {

// 0x0030be90 FUN_0030be90 (143 B): equivalent/0x0030be90.cpp
// sym: ?FUN_0030be90@PhysicsJoint3D_30be90@fn_fca90e00@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20001 inputs, branch coverage 4/4)
// FUN_0030be90 @ 0x0030be90
   // 0.0f
void PhysicsJoint3D_30be90::FUN_0030be90() {
    ((ThisCall_0030ad10*)(this))->FUN_0030ad10(flagF8, &f154);
    f158 = aa0 * n140 + a9c * n13c + a98 * n138;
    if (flagF8) {
        hulk_freg d = b104 * n140 + b100 * n13c + b0fc * n138;
        if (d < 0.0f)
            f154 = -f154;
    }
}


// 0x0030bf40 FUN_0030bf40 (36 B): matches/0x0030bf40.cpp
// sym: _FUN_0030bf40
extern "C" unsigned int * FUN_0030bf40(unsigned int * src, int count, unsigned int * dst) {
    U32_30bf40* out = dst;
    if (count != 0) {
        do {
            if (out != 0)
                *out = *src;
            ++src;
            ++out;
        } while (--count != 0);
    }
    return out;
}

} // namespace fn_fca90e00

// 0x0030bf70 FUN_0030bf70 (301 B): equivalent/0x0030bf70.cpp [wrapped: conflict: Store]
// sym: ?FUN_0030bf70@Mover_30bf70@fn_0030bf70@@QAEXXZ
namespace fn_0030bf70 {
// STATUS: equivalent (tools/equiv.py level 3: 204 inputs, branch coverage 12/12)
// FUN_0030bf70 @ 0x0030bf70
struct Vec3_30bf70 {
    float x, y, z;
};

struct Item_30bf70 {
    char pad[0x10];
    Vec3_30bf70 pos;
    char pad2[0x64 - 0x1c];
};

struct ItemTable_30bf70 {
    char pad[0x8c];
    Item_30bf70 *items;
};

struct Store {
    char pad[0x10];
    ItemTable_30bf70 *table;
};

struct Child_30bf70 {
    void FUN_0030a7b0(Vec3_30bf70 a, Vec3_30bf70 b);
};

struct Mover_30bf70 {
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
    virtual void getDelta(Vec3_30bf70 *out);
    virtual void afterDelta();

    char active;
    char pad0[3];
    int index;
    char pad1[0x18 - 0xc];
    Store *store;
    char pad2[4];
    Child_30bf70 **begin;
    Child_30bf70 **end;
    char pad3[0xe8 - 0x28];
    float pending;
    char hasPending;

    void FUN_0030bf70();
};

void Mover_30bf70::FUN_0030bf70()
{
    if ((unsigned)(end - begin) == 0)
        return;

    Vec3_30bf70 v;
    Vec3_30bf70 w;
    w.x = 0.0f;
    w.y = 0.0f;
    w.z = 0.0f;

    if ((pending > 0.0f || hasPending) && active) {
        getDelta(&v);
        afterDelta();
        Item_30bf70 *item = &store->table->items[index];
        pending = 0.0f;
        ((owners::Obj_2fd730 *)item)->FUN_002fd730();
        item->pos.x += v.x;
        item->pos.y += v.y;
        item->pos.z += v.z;
    } else {
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        clearDelta();
    }

    for (unsigned i = 0; i < (unsigned)(end - begin); i++)
        begin[i]->FUN_0030a7b0(w, v);
}
} // namespace fn_0030bf70


// 0x0030c0a0 physics::PhysicsJoint1D::vfunc_10 (100 B): matches/0x0030c0a0.cpp [wrapped: conflict: PhysicsJoint1D]
// sym: ?vfunc_10@PhysicsJoint1D@fn_0030c0a0@@UAEXH@Z
namespace fn_0030c0a0 {
struct C3_30c0a0 {
};
struct C2_30c0a0 {
    C3_30c0a0* FnG_0030f100();
};
struct C1_30c0a0 {
    C2_30c0a0* FnF_0030edf0();
};
struct Mgr_30c0a0 {
    C1_30c0a0* Find_0030f490(int id);
};
struct Tbl_30c0a0 {
    char pad[0x10];
    char* data;
};
struct Own_30c0a0 {
    char pad[0x208];
    Mgr_30c0a0* mgr;
    char pad2[0x220 - 0x20c];
    Tbl_30c0a0* tbl;
    C1_30c0a0* Find(int id) { return mgr->Find_0030f490(id); }
};
class PhysicsJoint {
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
    virtual void vfunc_10(int);
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
    char pad[4];
    int m8;
    int mC;
    char pad2[0x18 - 0x10];
    Own_30c0a0* mOwn;
};
class PhysicsJoint1D : public PhysicsJoint {
  public:
    virtual void vfunc_10(int);
    char pad3[0xfc - 0x1c];
    char blob[4];
    void Fin_0030b3a0();
};
void PhysicsJoint1D::vfunc_10(int a) {
    PhysicsJoint::vfunc_10(a);
    C3_30c0a0* c = mOwn->Find(mC)->FnF_0030edf0()->FnG_0030f100();
    ((owners::M_22c3b0 *)c)->FUN_0022c3b0((float *)(mOwn->tbl->data + m8 * 0x1c + 0xc), (float *)blob);
    Fin_0030b3a0();
    f25();
}
} // namespace fn_0030c0a0


// 0x0030c110 physics::PhysicsJoint1D::vfunc_12 (486 B): equivalent/0x0030c110.cpp [wrapped: conflict: PhysicsJoint1D]
// sym: ?vfunc_12@PhysicsJoint1D@fn_0030c110@@UAEXMMMMPAUV3_30c110@2@0M@Z
namespace fn_0030c110 {
// STATUS: equivalent (tools/equiv.py level 3: 3017 inputs, branch coverage 4/4; --wine 617 inputs)
// physics::PhysicsJoint1D::vfunc_12 @ 0x0030c110

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_30c110 {
    float x, y, z;
};

struct Part_30c110 {
    char pad0[0x10];
    float h0;
    float h1;
    float h2;
};

struct Mid_30c110 {
    char pad0[0x8c];
    Part_30c110 *part;
};

struct Gp {
    char pad0[0x1c];
    V3_30c110 vec;
};

struct Owner_30c110 {
    char pad0[0x10];
    Mid_30c110 *mid;
    char pad14[8];
    Gp *gp;
};

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
    virtual void vfunc_12(float a1, float a2, float a3, float a4, V3_30c110 *e, V3_30c110 *f, float a7);

    char pad4[0x14];
    Owner_30c110 *owner;
    char pad1c[0x80 - 0x1c];
    V3_30c110 bAxis;
    char pad8c[0xe4 - 0x8c];
    float k;
    char padE8[0xfc - 0xe8];
    V3_30c110 aAxis;
    char pad108[0x10c - 0x108];
    float accum;

    float FUN_0030b2c0(float x);
};

void PhysicsJoint1D::vfunc_12(float a1, float a2, float a3, float a4, V3_30c110 *e, V3_30c110 *f, float a7)
{
    float cx = aAxis.y * bAxis.z - aAxis.z * bAxis.y;
    float cy = aAxis.z * bAxis.x - aAxis.x * bAxis.z;
    hulk_freg czr = aAxis.x * bAxis.y - aAxis.y * bAxis.x;
    float cz = (float)czr;  // stored (`fst`), but the register copy is what the first square multiplies
    float len = (float)sqrt(czr * cz + cy * cy + cx * cx);
    Owner_30c110 *o = owner;
    float t5 = -((cz * e->z + cx * e->x + cy * e->y) * a1);
    float t6 = -((cz * f->z + cy * f->y + cx * f->x) * a2);
    V3_30c110 *g = &o->gp->vec;
    float t1 = (cz * g->z + cy * g->y + cx * g->x) * a3;
    if (a4 != 0.0f) {
        Part_30c110 *p = o->mid->part;
        ((owners::Obj_2fd730 *)p)->FUN_002fd730();
        if (p->h0 * p->h0 + p->h1 * p->h1 + p->h2 * p->h2 > 0.00001f) {
            p = owner->mid->part;
            ((owners::Obj_2fd730 *)p)->FUN_002fd730();
            t1 = ((e->x * p->h1 - e->y * p->h0) * cz + (e->z * p->h0 - e->x * p->h2) * cy +
                  (e->y * p->h2 - e->z * p->h1) * cx) * a4 + t1;
        }
    }
    float x = (t1 + t6 + t5) / len * k * a7;
    accum = accum + FUN_0030b2c0(x) * x;
}
} // namespace fn_0030c110


// 0x0030c300 physics::PhysicsJoint1D::vfunc_26 (237 B): equivalent/0x0030c300.cpp [wrapped: conflict: physics::PhysicsJoint1D]
// sym: ?vfunc_26@PhysicsJoint1D@physics@fn_0030c300@@QAE_NPBUVec3_30c300@3@PAU43@@Z
namespace fn_0030c300 {
// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 2/2)
// physics::PhysicsJoint1D::vfunc_26 @ 0x0030c300

struct Vec3_30c300 { float x,y,z; };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

namespace physics {
struct PhysicsJoint1D {
 char pad0[0x80]; Vec3_30c300 axis;
 char pad1[0xe4-0x8c]; float strength;
 char pad2[0xfc-0xe8]; Vec3_30c300 direction;
 float FUN_0030b2c0(float value);
 bool vfunc_26(const Vec3_30c300* input, Vec3_30c300* output);
};
}
bool physics::PhysicsJoint1D::vfunc_26(const Vec3_30c300* input, Vec3_30c300* output) {
 hulk_freg x = direction.y * axis.z - direction.z * axis.y;
 hulk_freg y = direction.z * axis.x - direction.x * axis.z;
 hulk_freg z = direction.x * axis.y - direction.y * axis.x;
 float amount = (float)(-(sqrt(z*z+y*y+x*x) * (z*input->z+y*input->y+x*input->x) * strength * DAT_004d31bc));
 union { float f; unsigned int u; } absolute;
 absolute.f = amount; absolute.u &= 0x7fffffff;
 if (!(absolute.f > (*(float*)&DAT_003f32e0))) return false;
 hulk_freg scale = FUN_0030b2c0(amount) * amount;
 output->x = scale * direction.x;
 output->y = scale * direction.y;
 output->z = scale * direction.z;
 return true;
}
} // namespace fn_0030c300


// 0x0030c3f0 physics::PhysicsJoint1D::vfunc_20 (79 B): matches/0x0030c3f0.cpp [wrapped: conflict: physics::PhysicsJoint; physics::PhysicsJoint1D]
// sym: ?vfunc_20@PhysicsJoint1D@physics@fn_0030c3f0@@UAEMPAM@Z
namespace fn_0030c3f0 {
// data: one = DAT_003f32dc, zero = DAT_003f32e0

namespace physics {
class PhysicsJoint {
  public:
    virtual void vfunc_0();
};
class PhysicsJoint1D : public PhysicsJoint {
  public:
    char pad[0xf8];
    float x, y, z;
    virtual float vfunc_20(float* p);
};
} // namespace physics
struct ThisCall_0030b2c0 {
    float other_0030b2c0(float);
};
float physics::PhysicsJoint1D::vfunc_20(float* p) {
    float d = z * p[2] + y * p[1] + x * p[0];
    if (d == DAT_003f32e0)
        return DAT_003f32dc;
    return ((ThisCall_0030b2c0*)(this))->other_0030b2c0(d);
}
} // namespace fn_0030c3f0


// 0x0030c440 physics::PhysicsJoint3D::vfunc_10 (320 B): equivalent/0x0030c440.cpp [wrapped: conflict: physics::PhysicsJoint; physics::PhysicsJoint3D]
// sym: ?vfunc_10@PhysicsJoint3D@physics@fn_0030c440@@UAEXPAX@Z
namespace fn_0030c440 {
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 4/4)
// physics::PhysicsJoint3D::vfunc_10 @ 0x0030c440

struct Vec3_30c440 {
    float x, y, z;
    float FUN_0022d110();
};


struct Matrix3_30c440 {
    // equiv-conv: FUN_0022c3b0 ecx stack stack
    void FUN_0022c3b0(Vec3_30c440 *in, Vec3_30c440 *out);
};

struct Chain3_30c440 {
    Matrix3_30c440 *FUN_0030f100();
};

struct Chain2_30c440 {
    Chain3_30c440 *FUN_0030edf0();
};

struct Skeleton {
    Chain2_30c440 *FUN_0030f490(int index);
};

struct Manager_30c440 {
    char pad0[0x208];
    Skeleton *skeleton;
    void FUN_00310490(int index, Vec3_30c440 *out, char flag);
};

namespace physics {

class PhysicsJoint {
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
    virtual void vfunc_10(void *arg);
};

class PhysicsJoint3D : public PhysicsJoint {
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
    virtual void vfunc_10(void *arg);
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

    char pad04[8];
    int index;
    char pad10[8];
    Manager_30c440 *manager;
    char pad1c[0x7c];
    Vec3_30c440 axis;
    char pada4[0x58];
    Vec3_30c440 normal;

    void FUN_0030be90();
};

struct Frame_30c440 {
    Vec3_30c440 v;
    Vec3_30c440 w;
};

void PhysicsJoint3D::vfunc_10(void *arg)
{
    Frame_30c440 f;

    PhysicsJoint::vfunc_10(arg);
    manager->FUN_00310490(index, &f.v, 0);
    normal.x = f.v.y * axis.z - f.v.z * axis.y;
    normal.y = f.v.z * axis.x - f.v.x * axis.z;
    normal.z = f.v.x * axis.y - f.v.y * axis.x;
    normal.FUN_0022d110();

    if ((DAT_00555490 & 1) == 0) {
        DAT_00555490 |= 1;
        (*(Vec3_30c440*)&DAT_00555484).x = 0;
        (*(Vec3_30c440*)&DAT_00555484).y = 1.0f;
        (*(Vec3_30c440*)&DAT_00555484).z = 0;
    }
    manager->skeleton->FUN_0030f490(index)->FUN_0030edf0()->FUN_0030f100()->FUN_0022c3b0(((Vec3_30c440*)&DAT_00555484), &f.w);

    if (f.w.z * normal.z + f.w.y * normal.y + f.w.x * normal.x < 0.0f) {
        normal.x = normal.x * (*(float*)&DAT_003f3388);
        normal.y = normal.y * (*(float*)&DAT_003f3388);
        normal.z = normal.z * (*(float*)&DAT_003f3388);
    }
    FUN_0030be90();
    v25();
}

}
} // namespace fn_0030c440


// 0x0030c580 FUN_0030c580 (212 B): equivalent/0x0030c580.cpp
// sym: ?FUN_0030c580@Buffer_30c580@owners@@QAEPAU12@PAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 97 inputs, branch coverage 16/16)
// FUN_0030c580 @ 0x0030c580
owners::Buffer_30c580* owners::Buffer_30c580::FUN_0030c580(owners::Buffer_30c580* source) {
 Word_30c580* sourceBegin = source->begin;
 Word_30c580* sourceEnd = source->end;
 Word_30c580* destination = begin;
 unsigned int count = (unsigned int)(sourceEnd-sourceBegin);
 unsigned int size = (unsigned int)(end-destination);
 if (count <= size) {
  while(sourceBegin != sourceEnd) { *destination++ = *sourceBegin++; }
  end = destination;
 } else {
  unsigned int capacity = (unsigned int)(capacityEnd-destination);
  if (count <= capacity) {
   Word_30c580* split = sourceBegin + size;
   while(sourceBegin != split) { *destination++ = *sourceBegin++; }
   Word_30c580* tail = end;
   end = FUN_0030bf40(source->begin + size, (unsigned int)(count-size), tail);
  } else if (destination) {
   end = destination;
  } else if (FUN_0030a130(count)) {
   end = FUN_0030bf40(source->begin, (unsigned int)count, begin);
  }
 }
 return this;
}


// 0x0030c670 physics::PhysicsJoint::vfunc_28 (21 B): matches/0x0030c670.cpp
// sym: ?vfunc_28@PhysicsJoint@physics@@UAEXPAX@Z
void physics::PhysicsJoint::vfunc_28(void* __p0) { char * p = (char *)__p0;

    *(int*)(p + 0x1c) = 0;
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x24) = *(int*)(p + 0x20);
}

namespace fn_fca90e00 {

// 0x0030c690 FUN_0030c690 (412 B): equivalent/0x0030c690.cpp
// sym: ?FUN_0030c690@State_30c690@fn_fca90e00@@QAEPAU12@PBU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0030c690 @ 0x0030c690
State_30c690 *State_30c690::FUN_0030c690(const State_30c690 *other)
{
    byte04 = other->byte04;
    word06 = other->word06;
    f08 = other->f08;
    f0c = other->f0c;
    f10 = other->f10;
    f14 = other->f14;
    f18 = other->f18;
    f1c = other->f1c;
    ((owners::Buffer_30c580 *)&vec20)->FUN_0030c580((owners::Buffer_30c580 *)(const IntVec_30c690 *)(&other->vec20));
    f30 = other->f30;
    f34 = other->f34;
    f38 = other->f38;
    f3c = other->f3c;
    f40 = other->f40;
    f44 = other->f44;
    f4c = other->f4c;
    f50 = other->f50;
    f54 = other->f54;
    f58 = other->f58;
    f5c = other->f5c;
    f60 = other->f60;
    f68 = other->f68;
    f6c = other->f6c;
    f70 = other->f70;
    f74 = other->f74;
    f78 = other->f78;
    f7c = other->f7c;
    f80 = other->f80;
    f84 = other->f84;
    f88 = other->f88;
    f8c = other->f8c;
    f90 = other->f90;
    f94 = other->f94;
    f98 = other->f98;
    f9c = other->f9c;
    fa0 = other->fa0;
    for (int i = 0; i < 16; i++)
        block[i] = other->block[i];
    fe4 = other->fe4;
    fe8 = other->fe8;
    bec = other->bec;
    bed = other->bed;
    bee = other->bee;
    bef = other->bef;
    ff0 = other->ff0;
    ff4 = other->ff4;
    return this;
}


// 0x0030c830 FUN_0030c830 (141 B): matches/0x0030c830.cpp
// sym: ?Copy@Obj_30c830@fn_fca90e00@@QAEAAV12@ABV12@@Z
Obj_30c830& Obj_30c830::Copy(const Obj_30c830& src) {
    CopyBase_0030c690(src);
    b = src.b;
    w0 = src.w0;
    w1 = src.w1;
    w2 = src.w2;
    w3 = src.w3;
    w4 = src.w4;
    w5 = src.w5;
    w6 = src.w6;
    w7 = src.w7;
    w8 = src.w8;
    return *this;
}

} // namespace fn_fca90e00

// 0x0030c8c0 FUN_0030c8c0 (333 B): equivalent/0x0030c8c0.cpp
// sym: ?FUN_0030c8c0@Obj_30c8c0@owners@@QAEPAU12@PAU12@@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0030c8c0 @ 0x0030c8c0
owners::Obj_30c8c0 *owners::Obj_30c8c0::FUN_0030c8c0(owners::Obj_30c8c0 *src)
{
    FUN_0030c690(src);
    b0 = src->b0;
    for (int i = 0; i < 0x15; i++)
        a[i] = src->a[i];
    c0 = src->c0;
    c1 = src->c1;
    d0 = src->d0;
    d1 = src->d1;
    return this;
}


// 0x0030ca30 FUN_0030ca30 (40 B): matches/0x0030ca30.cpp [wrapped: conflict: physics::PhysicsJoint]
// sym: ??0PhysicsJoint@physics@fn_0030ca30@@QAE@XZ
namespace fn_0030ca30 {
namespace physics {
struct Sub_30ca30 {
    char pad[0x1c];
    Sub_30ca30() throw();
};
struct Vec_30ca30 {
    float x, y, z;
    Vec_30ca30() throw() {}
    Vec_30ca30(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30ca30 v;
    char pad2[0x48 - 0x2c];
    Sub_30ca30 s1;
    Sub_30ca30 s2;
    PhysicsJoint() throw();
};
PhysicsJoint::PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
} // namespace physics
} // namespace fn_0030ca30


// 0x0030ca60 physics::PhysicsJoint::vfunc_7 (4 B): matches/0x0030ca60.cpp
// sym: ?vfunc_7@PhysicsJoint@physics@@UAEMXZ
// Same code shape as 0x000690f0 (propagated; names are from that function)
hulk_freg physics::PhysicsJoint::vfunc_7() {
    return this->f_3c;
}


// 0x0030ca70 physics::PhysicsJoint::vfunc_8 (4 B): matches/0x0030ca70.cpp
// sym: ?vfunc_8@PhysicsJoint@physics@@UAEMXZ
// Same code shape as 0x002f5620 (propagated; names are from that function)
 // namespace physics
hulk_freg physics::PhysicsJoint::vfunc_8() {
    return this->f_40;
}


// 0x0030ca80 FUN_0030ca80 (302 B): equivalent/0x0030ca80.cpp [wrapped: conflict: physics::PhysicsJoint]
// sym: ??0PhysicsJoint@physics@fn_0030ca80@@QAE@PBUVec3_30ca80@2@MH@Z
namespace fn_0030ca80 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0030ca80 @ 0x0030ca80

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_30ca80 {
    float x, y, z;
};

struct Mat4_30ca80 {
    float m[16];
    void FUN_0022b980();
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90();
    void FUN_002fd0a0();
};

namespace physics {

class PhysicsJoint {
public:
    virtual void vfunc_0();
    unsigned char flag4;
    unsigned char pad5;
    unsigned short word6;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
    float field_30;
    float field_34;
    float field_38;
    float field_3c;
    float field_40;
    float field_44;
    SymMatrix sym48;
    SymMatrix sym64;
    Vec3_30ca80 vec80;
    Vec3_30ca80 vec8c;
    char pad98[0xa4 - 0x98];
    Mat4_30ca80 mat_a4;
    int field_e4;
    int field_e8;
    unsigned char fieldEC;
    unsigned char fieldED;
    unsigned char fieldEE;
    unsigned char fieldEF;
    int field_f0;
    int field_f4;

    PhysicsJoint(const Vec3_30ca80 *axis, float mass, int id);
};

PhysicsJoint::PhysicsJoint(const Vec3_30ca80 *axis, float mass, int id)
{
    field_08 = id;
    flag4 = 1;
    word6 = 0;
    field_0c = -1;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1c = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
    field_30 = mass;
    field_34 = mass;
    field_3c = mass;
    sym48.FUN_002fca90();
    sym64.FUN_002fca90();
    vec80 = *axis;
    vec8c = *axis;
    field_e4 = 0;
    field_e8 = 0;
    fieldEC = 0;
    fieldED = 1;
    fieldEE = 0;
    fieldEF = 0;
    if (field_34 > 0.0f)
        field_40 = 1.0f / field_3c;
    else
        field_40 = 0;
    field_44 = (float)sqrt(vec8c.x * vec8c.x + vec8c.y * vec8c.y + vec8c.z * vec8c.z);
    mat_a4.FUN_0022b980();
    sym48.FUN_002fd0a0();
    sym64.FUN_002fd0a0();
    field_f0 = 0;
    field_f4 = 0;
    field_38 = field_3c;
}

}
} // namespace fn_0030ca80

namespace fn_fca90e00 {

// 0x0030cbb0 FUN_0030cbb0 (44 B): matches/0x0030cbb0.cpp
// sym: ?Target@fn_fca90e00@@YIXPAVPhysicsJoint@1@@Z
void __fastcall Target(PhysicsJoint* self) {
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00431de4);
    ((SymMatrix_30cbb0*)((char*)self + 0x64))->Init_002fcaa0();
    ((SymMatrix_30cbb0*)((char*)self + 0x48))->Init_002fcaa0();
    hulk_intptr value = self->m20;
    self->m24 = value;
    if (value)
        AddRef_0008d340((void*)value);
}


// 0x0030cc10 physics::PhysicsJoint0D::vfunc_1 (1 B): matches/0x0030cc10.cpp
// sym: ?FUN_0030cc10@fn_fca90e00@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0030cc10() {}


// 0x0030cc20 physics::PhysicsJoint0D::vfunc_3 (1 B): matches/0x0030cc20.cpp
// sym: ?FUN_0030cc20@fn_fca90e00@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0030cc20() {}


// 0x0030cc30 physics::PhysicsJoint0D::vfunc_2 (1 B): matches/0x0030cc30.cpp
// sym: ?FUN_0030cc30@fn_fca90e00@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0030cc30() {}

} // namespace fn_fca90e00

// 0x0030cc40 physics::PhysicsJoint0D::vfunc_4 (3 B): matches/0x0030cc40.cpp
// sym: ?vfunc_4@PhysicsJoint0D@physics@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool physics::PhysicsJoint0D::vfunc_4() {
    return true;
}


// 0x0030cc50 physics::PhysicsJoint0D::vfunc_6 (7 B): matches/0x0030cc50.cpp
// sym: ?vfunc_6@PhysicsJoint0D@physics@@UAEMXZ
// Same code shape as 0x000695a0 (propagated; names are from that function)
hulk_freg physics::PhysicsJoint0D::vfunc_6() {
    return DAT_003f32e0;
}


// 0x0030cc60 physics::PhysicsJoint0D::vfunc_5 (17 B): matches/0x0030cc60.cpp
// sym: ?vfunc_5@PhysicsJoint0D@physics@@UAEXPAX@Z
void physics::PhysicsJoint0D::vfunc_5(void* __p0) { void * p = (void *)__p0;

    int* q = (int*)p;
    q[2] = 0;
    q[1] = 0;
    q[0] = 0;
}


// 0x0030cc80 physics::PhysicsJoint0D::vfunc_11 (3 B): matches/0x0030cc80.cpp
// sym: ?vfunc_11@PhysicsJoint0D@physics@@UAEXHHH@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_11(int , int , int ) {}


// 0x0030cc90 physics::PhysicsJoint0D::vfunc_12 (3 B): matches/0x0030cc90.cpp
// sym: ?vfunc_12@PhysicsJoint0D@physics@@UAEXHHHHHHH@Z
void physics::PhysicsJoint0D::vfunc_12(int , int , int , int , int , int , int ) {}


// 0x0030cca0 physics::PhysicsJoint0D::vfunc_19 (3 B): matches/0x0030cca0.cpp
// sym: ?vfunc_19@PhysicsJoint0D@physics@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_19(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x0030ccb0 physics::PhysicsJoint0D::vfunc_18 (3 B): matches/0x0030ccb0.cpp
// sym: ?vfunc_18@PhysicsJoint0D@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_18(hulk_intptr a, hulk_intptr b) {}


// 0x0030ccc0 physics::PhysicsJoint0D::vfunc_20 (9 B): matches/0x0030ccc0.cpp
// sym: ?vfunc_20@PhysicsJoint0D@physics@@UAEMM@Z
hulk_freg physics::PhysicsJoint0D::vfunc_20(float x) {
    return 0.0f;
}


// 0x0030ccd0 physics::PhysicsJoint0D::vfunc_21 (3 B): matches/0x0030ccd0.cpp
// sym: ?vfunc_21@PhysicsJoint0D@physics@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_21(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x0030cce0 physics::PhysicsJoint0D::vfunc_15 (3 B): matches/0x0030cce0.cpp
// sym: ?vfunc_15@PhysicsJoint0D@physics@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_15(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}


// 0x0030ccf0 physics::PhysicsJoint0D::vfunc_16 (3 B): matches/0x0030ccf0.cpp
// sym: ?vfunc_16@PhysicsJoint0D@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_16(hulk_intptr a, hulk_intptr b) {}


// 0x0030cd00 physics::PhysicsJoint0D::vfunc_17 (3 B): matches/0x0030cd00.cpp
// sym: ?vfunc_17@PhysicsJoint0D@physics@@UAEXHHH@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_17(int , int , int ) {}


// 0x0030cd10 physics::PhysicsJoint0D::vfunc_22 (3 B): matches/0x0030cd10.cpp
// sym: ?vfunc_22@PhysicsJoint0D@physics@@UAEXPAX@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_22(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    (void)a;
}

namespace fn_fca90e00 {

// 0x0030cd20 physics::PhysicsJoint0D::vfunc_23 (1 B): matches/0x0030cd20.cpp
// sym: ?FUN_0030cd20@fn_fca90e00@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0030cd20() {}

} // namespace fn_fca90e00

// 0x0030cd30 physics::PhysicsJoint0D::vfunc_24 (3 B): matches/0x0030cd30.cpp
// sym: ?vfunc_24@PhysicsJoint0D@physics@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void physics::PhysicsJoint0D::vfunc_24(hulk_intptr a) {
    (void)a;
}

namespace fn_fca90e00 {

// 0x0030cd40 physics::PhysicsJoint0D::vfunc_25 (1 B): matches/0x0030cd40.cpp
// sym: ?FUN_0030cd40@fn_fca90e00@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0030cd40() {}

} // namespace fn_fca90e00

// 0x0030cd50 physics::PhysicsJoint0D::vfunc_26 (5 B): matches/0x0030cd50.cpp
// sym: ?vfunc_26@PhysicsJoint0D@physics@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool physics::PhysicsJoint0D::vfunc_26(int , int ) {
    return false;
}


// 0x0030cd60 FUN_0030cd60 (44 B): matches/0x0030cd60.cpp [wrapped: same definition as 0x0030cbb0 in this TU]
// sym: ?Target@fn_0030cd60@@YIXPAVPhysicsJoint@1@@Z
namespace fn_0030cd60 {
extern "C" char DAT_00431de4[];
// Same code shape as 0x0030cbb0 (propagated; names are from that function)
class SymMatrix_30cd60 {
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
void __fastcall Target(PhysicsJoint* self) {
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00431de4);
    ((SymMatrix_30cd60*)((char*)self + 0x64))->Init_002fcaa0();
    ((SymMatrix_30cd60*)((char*)self + 0x48))->Init_002fcaa0();
    hulk_intptr value = self->m20;
    self->m24 = value;
    if (value)
        AddRef_0008d340((void*)value);
}
} // namespace fn_0030cd60


// 0x0030cdb0 FUN_0030cdb0 (105 B): matches/0x0030cdb0.cpp [wrapped: conflict: PhysicsJoint1D]
// sym: ?Init1@PhysicsJoint1D@fn_0030cdb0@@QAEPAV12@HHH@Z
namespace fn_0030cdb0 {
extern "C" char DAT_00431ed4[];
class PhysicsJoint_30cdb0 {
  public:
    void Init_0030ca80(int, int, int);
};
class PhysicsJoint1D : public PhysicsJoint_30cdb0 {
  public:
    char pad0[0xf8];
    volatile unsigned char mFlag;
    char pad1[3];
    volatile int mFC, m100, m104, m108, m10c, m110, m114, m118, m11c;
    PhysicsJoint1D* Init1(int, int, int);
};
PhysicsJoint1D* PhysicsJoint1D::Init1(int a, int b, int c) {
    PhysicsJoint_30cdb0::Init_0030ca80(a, b, c);
    mFlag = 0;
    m108 = 0;
    m11c = 0;
    m118 = 0;
    m114 = 0;
    m110 = 0;
    m10c = 0;
    *(volatile hulk_intptr*)((char*)this) = ((hulk_intptr)DAT_00431ed4);
    *(volatile unsigned short*)((char*)this + 6) = 1;
    m104 = 0;
    m100 = 0;
    mFC = 0;
    return this;
}
} // namespace fn_0030cdb0


// 0x0030ce20 physics::PhysicsJoint1D::vfunc_1 (15 B): matches/0x0030ce20.cpp
// sym: ?vfunc_1@PhysicsJoint1D@physics@@UAEXXZ
 // namespace physics
void physics::PhysicsJoint1D::vfunc_1() {
    *(int*)((char*)this + 0x110) = 0;
    *(int*)((char*)this + 0x10c) = 0;
}

namespace fn_fca90e00 {

// 0x0030ce30 physics::PhysicsJoint1D::vfunc_3 (11 B): matches/0x0030ce30.cpp
// sym: ?FUN_0030ce30@fn_fca90e00@@YIXPAVX_30ce30@1@@Z
// Same code shape as 0x00089390 (propagated; names are from that function)
void __fastcall FUN_0030ce30(X_30ce30* self) {
    self->value = 0;
}

} // namespace fn_fca90e00

// 0x0030ce40 physics::PhysicsJoint1D::vfunc_4 (27 B): matches/0x0030ce40.cpp
// sym: ?vfunc_4@PhysicsJoint1D@physics@@UAE_NXZ
// data: zeroValue_30ce40 = DAT_003f32e0
 // namespace physics
bool physics::PhysicsJoint1D::vfunc_4() {
    if (this->f_114 == DAT_003f32e0)
        return true;
    return false;
}


// 0x0030ce60 physics::PhysicsJoint1D::vfunc_5 (43 B): matches/0x0030ce60.cpp
// sym: ?vfunc_5@PhysicsJoint1D@physics@@UAEXPAX@Z
void physics::PhysicsJoint1D::vfunc_5(void* __p0) { float * out = (float *)__p0;

    float v = this->f_114;
    out[0] = v * this->f_fc;
    out[1] = v * this->f_100;
    out[2] = v * this->f_104;
}


// 0x0030ce90 physics::PhysicsJoint1D::vfunc_15 (33 B): matches/0x0030ce90.cpp
// sym: ?vfunc_15@PhysicsJoint1D@physics@@UAEXPAX@Z
 // namespace physics
void physics::PhysicsJoint1D::vfunc_15(void* __p0) { void * out = (void *)__p0;

    unsigned int* p = (unsigned int*)out;
    p[0] = *(unsigned int*)((char*)this + 0xfc);
    p[1] = *(unsigned int*)((char*)this + 0x100);
    p[2] = *(unsigned int*)((char*)this + 0x104);
}


// 0x0030cec0 physics::PhysicsJoint1D::vfunc_16 (81 B): equivalent/0x0030cec0.cpp
// sym: ?vfunc_16@PhysicsJoint1D@physics@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19872 inputs, branch coverage 0/0)
// physics::PhysicsJoint1D::vfunc_16 @ 0x0030cec0
void physics::PhysicsJoint1D::vfunc_16(hulk_intptr __p0, hulk_intptr __p1) { const float * input = (const float *)__p0; float * output = (float *)__p1;
 hulk_freg projection = -(this->f_104*input[2]+this->f_100*input[1]+this->f_fc*input[0]); output[0]=projection*this->f_fc+input[0]; output[1]=projection*this->f_100+input[1]; output[2]=projection*this->f_104+input[2]; }


// 0x0030cf20 physics::PhysicsJoint1D::vfunc_19 (43 B): matches/0x0030cf20.cpp
// sym: ?vfunc_19@PhysicsJoint1D@physics@@UAEXPAX@Z
void physics::PhysicsJoint1D::vfunc_19(void* __p0) { float * p = (float *)__p0;

    *(float*)((char*)this + 0x108) = *(float*)((char*)this + 0x100) * p[1] +
                                     *(float*)((char*)this + 0x104) * p[2] +
                                     *(float*)((char*)this + 0xfc) * p[0];  // the listing's order (MSVC 7.1 reassociates; clang does not)
}


// 0x0030cf50 physics::PhysicsJoint1D::vfunc_22 (43 B): matches/0x0030cf50.cpp
// sym: ?vfunc_22@PhysicsJoint1D@physics@@UAEXPAX@Z
void physics::PhysicsJoint1D::vfunc_22(void* __p0) { float * out = (float *)__p0;

    float x = this->f_108;
    out[0] = x * this->f_fc;
    out[1] = x * this->f_100;
    out[2] = x * this->f_104;
}


// 0x0030cf80 physics::PhysicsJoint1D::vfunc_23 (19 B): matches/0x0030cf80.cpp
// sym: ?vfunc_23@PhysicsJoint1D@physics@@UAEXXZ
void physics::PhysicsJoint1D::vfunc_23() {
    this->f_10c = this->f_108 + this->f_10c;
}


// 0x0030cfa0 physics::PhysicsJoint1D::vfunc_24 (49 B): matches/0x0030cfa0.cpp
// sym: ?vfunc_24@PhysicsJoint1D@physics@@UAEXH@Z
void physics::PhysicsJoint1D::vfunc_24(hulk_intptr __p0) { float * p = (float *)__p0;

    this->f_10c = this->f_100 * p[1] + this->f_104 * p[2] + this->f_fc * p[0] + this->f_10c;  // the listing's order (MSVC 7.1 reassociates; clang does not)
}


// 0x0030cfe0 physics::PhysicsJoint1D::vfunc_6 (23 B): matches/0x0030cfe0.cpp
// sym: ?vfunc_6@PhysicsJoint1D@physics@@UAEMXZ
 // namespace physics
hulk_freg physics::PhysicsJoint1D::vfunc_6() {
    union U {
        float f;
        unsigned int i;
    } u;
    u.f = this->f_114;
    u.i &= 0x7fffffff;
    return u.f;
}


// 0x0030d000 FUN_0030d000 (44 B): matches/0x0030d000.cpp [wrapped: same definition as 0x0030cbb0 in this TU]
// sym: ?Target@fn_0030d000@@YIXPAVPhysicsJoint@1@@Z
namespace fn_0030d000 {
extern "C" char DAT_00431de4[];
// Same code shape as 0x0030cbb0 (propagated; names are from that function)
class SymMatrix_30d000 {
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
void __fastcall Target(PhysicsJoint* self) {
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00431de4);
    ((SymMatrix_30d000*)((char*)self + 0x64))->Init_002fcaa0();
    ((SymMatrix_30d000*)((char*)self + 0x48))->Init_002fcaa0();
    hulk_intptr value = self->m20;
    self->m24 = value;
    if (value)
        AddRef_0008d340((void*)value);
}
} // namespace fn_0030d000


// 0x0030d030 FUN_0030d030 (152 B): equivalent/0x0030d030.cpp [wrapped: conflict: physics::PhysicsJoint; physics::PhysicsJoint3D]
// sym: ??0PhysicsJoint3D@physics@fn_0030d030@@QAE@PBUVec3@2@MH@Z
namespace fn_0030d030 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0030d030 @ 0x0030d030
// equiv-map: ??0PhysicsJoint@physics@@QAE@PBUVec3@@MH@Z = 0x0030ca80

struct Vec3 {
    float x, y, z;
};

namespace physics {

class PhysicsJoint {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad04[2];
    unsigned short word6;
    char pad08[0xf0];
    PhysicsJoint(const Vec3 *axis, float mass, int id);
};

class PhysicsJoint3D : public PhysicsJoint {
public:
    unsigned char flagF8;
    char padf9[3];
    int fFC, f100, f104;
    char pad108[0xc];
    int f114, f118, f11c;
    char pad120[0x18];
    int f138, f13c, f140;
    int f144, f148, f14c;
    unsigned char enabled;      // 0x150
    char pad151[3];
    int f154, f158;
    PhysicsJoint3D(const Vec3 *axis, float mass, int id);
    virtual void vfunc_0();
    virtual void vfunc_1();
};

PhysicsJoint3D::PhysicsJoint3D(const Vec3 *axis, float mass, int id) : PhysicsJoint(axis, mass, id)
{
    flagF8 = 0;
    f154 = 0;
    f158 = 0;
    word6 = 3;
    // the original goes through the vftable here instead of calling the override directly
    PhysicsJoint *self = this;
    self->vfunc_1();
    f140 = 0;
    f13c = 0;
    f138 = 0;
    f14c = 0;
    f148 = 0;
    f144 = 0;
    enabled = 1;
    f104 = 0;
    f100 = 0;
    fFC = 0;
    f11c = 0;
    f118 = 0;
    f114 = 0;
}

}
} // namespace fn_0030d030


// 0x0030d0d0 physics::PhysicsJoint3D::vfunc_1 (46 B): matches/0x0030d0d0.cpp
// sym: ?vfunc_1@PhysicsJoint3D@physics@@UAEXXZ
void physics::PhysicsJoint3D::vfunc_1() {
    *(int*)((char*)this + 0x128) = 0;
    *(int*)((char*)this + 0x124) = 0;
    *(int*)((char*)this + 0x120) = 0;
    *(int*)((char*)this + 0x134) = 0;
    *(int*)((char*)this + 0x130) = 0;
    *(int*)((char*)this + 0x12c) = 0;
    *((char*)this + 0x151) = 1;
}


// 0x0030d100 physics::PhysicsJoint3D::vfunc_3 (21 B): matches/0x0030d100.cpp
// sym: ?vfunc_3@PhysicsJoint3D@physics@@UAEXXZ
void physics::PhysicsJoint3D::vfunc_3() {
    *(int*)((char*)this + 0x11c) = 0;
    *(int*)((char*)this + 0x118) = 0;
    *(int*)((char*)this + 0x114) = 0;
}


// 0x0030d120 physics::PhysicsJoint3D::vfunc_4 (7 B): matches/0x0030d120.cpp
// sym: ?vfunc_4@PhysicsJoint3D@physics@@UAE_NXZ
bool physics::PhysicsJoint3D::vfunc_4() {
    return this->f_150;
}


// 0x0030d130 physics::PhysicsJoint3D::vfunc_5 (33 B): matches/0x0030d130.cpp
// sym: ?vfunc_5@PhysicsJoint3D@physics@@UAEXPAX@Z
void physics::PhysicsJoint3D::vfunc_5(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    out[0] = this->f_138;
    out[1] = this->f_13c;
    out[2] = this->f_140;
}


// 0x0030d160 physics::PhysicsJoint3D::vfunc_15 (33 B): matches/0x0030d160.cpp
// sym: ?vfunc_15@PhysicsJoint3D@physics@@UAEXPAX@Z
// Same code shape as 0x0030ce90 (propagated; names are from that function)
 // namespace physics
void physics::PhysicsJoint3D::vfunc_15(void* __p0) { void * out = (void *)__p0;

    unsigned int* p = (unsigned int*)out;
    p[0] = *(unsigned int*)((char*)this + 0xfc);
    p[1] = *(unsigned int*)((char*)this + 0x100);
    p[2] = *(unsigned int*)((char*)this + 0x104);
}


// 0x0030d190 physics::PhysicsJoint3D::vfunc_16 (27 B): matches/0x0030d190.cpp
// sym: ?vfunc_16@PhysicsJoint3D@physics@@UAEXHH@Z
 // namespace physics
void physics::PhysicsJoint3D::vfunc_16(hulk_intptr __p0, hulk_intptr __p1) { unsigned int * src = (unsigned int *)__p0; unsigned int * dst = (unsigned int *)__p1;

    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}


// 0x0030d1b0 physics::PhysicsJoint3D::vfunc_19 (33 B): matches/0x0030d1b0.cpp
// sym: ?vfunc_19@PhysicsJoint3D@physics@@UAEXPAX@Z
void physics::PhysicsJoint3D::vfunc_19(void* __p0) { const unsigned int * p = (const unsigned int *)__p0;

    *(unsigned int*)((char*)this + 0x114) = p[0];
    *(unsigned int*)((char*)this + 0x118) = p[1];
    *(unsigned int*)((char*)this + 0x11c) = p[2];
}


// 0x0030d1e0 physics::PhysicsJoint3D::vfunc_18 (37 B): matches/0x0030d1e0.cpp
// sym: ?vfunc_18@PhysicsJoint3D@physics@@UAEXHH@Z
void physics::PhysicsJoint3D::vfunc_18(hulk_intptr __p0, hulk_intptr __p1) { float * a = (float *)__p0; float * b = (float *)__p1;

    float x = this->f_e8;
    b[0] = x * a[0];
    b[1] = x * a[1];
    b[2] = x * a[2];
}


// 0x0030d210 physics::PhysicsJoint3D::vfunc_22 (33 B): matches/0x0030d210.cpp
// sym: ?vfunc_22@PhysicsJoint3D@physics@@UAEXPAX@Z
void physics::PhysicsJoint3D::vfunc_22(void* __p0) { unsigned int * out = (unsigned int *)__p0;

    out[0] = *(unsigned int*)((char*)this + 0x114);
    out[1] = *(unsigned int*)((char*)this + 0x118);
    out[2] = *(unsigned int*)((char*)this + 0x11c);
}


// 0x0030d240 physics::PhysicsJoint3D::vfunc_23 (62 B): matches/0x0030d240.cpp
// sym: ?vfunc_23@PhysicsJoint3D@physics@@UAEXXZ
 // namespace physics
void physics::PhysicsJoint3D::vfunc_23() {
    (*(volatile float *)&this->f_120) = (*(volatile float *)&this->f_120) + (*(volatile float *)&this->f_114);
    (*(volatile float *)&this->f_124) = (*(volatile float *)&this->f_124) + (*(volatile float *)&this->f_118);
    (*(volatile float *)&this->f_128) = (*(volatile float *)&this->f_128) + (*(volatile float *)&this->f_11c);
    (*(volatile char *)&this->f_151) = 0;
}


// 0x0030d280 physics::PhysicsJoint3D::vfunc_24 (58 B): equivalent/0x0030d280.cpp
// sym: ?vfunc_24@PhysicsJoint3D@physics@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// physics::PhysicsJoint3D::vfunc_24 @ 0x0030d280
void physics::PhysicsJoint3D::vfunc_24(hulk_intptr __p0) { const Vec3 * delta = (const Vec3 *)__p0;

    (*(Vec3 *)&this->f_120).x += delta->x;
    (*(Vec3 *)&this->f_120).y += delta->y;
    (*(Vec3 *)&this->f_120).z += delta->z;
    (*(unsigned char *)&this->f_151) = 0;
}


// 0x0030d2c0 physics::PhysicsJoint3D::vfunc_6 (43 B): matches/0x0030d2c0.cpp
// sym: ?vfunc_6@PhysicsJoint3D@physics@@UAEMXZ
hulk_freg physics::PhysicsJoint3D::vfunc_6() {
    return sqrt((double)((hulk_freg)(*(float *)&this->f_138) * (*(float *)&this->f_138) + (hulk_freg)(*(float *)&this->f_13c) * (*(float *)&this->f_13c) + (hulk_freg)(*(float *)&this->f_140) * (*(float *)&this->f_140)));
}


// 0x0030d2f0 FUN_0030d2f0 (44 B): matches/0x0030d2f0.cpp [wrapped: same definition as 0x0030cbb0 in this TU]
// sym: ?Target@fn_0030d2f0@@YIXPAVPhysicsJoint@1@@Z
namespace fn_0030d2f0 {
extern "C" char DAT_00431de4[];
// Same code shape as 0x0030cbb0 (propagated; names are from that function)
class SymMatrix_30d2f0 {
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
void __fastcall Target(PhysicsJoint* self) {
    *(hulk_intptr*)self = ((hulk_intptr)DAT_00431de4);
    ((SymMatrix_30d2f0*)((char*)self + 0x64))->Init_002fcaa0();
    ((SymMatrix_30d2f0*)((char*)self + 0x48))->Init_002fcaa0();
    hulk_intptr value = self->m20;
    self->m24 = value;
    if (value)
        AddRef_0008d340((void*)value);
}
} // namespace fn_0030d2f0


// 0x0030d320 physics::PhysicsJoint::vfunc_0 (66 B): matches/0x0030d320.cpp [wrapped: conflict: PhysicsJoint]
// sym: ?vfunc_0@PhysicsJoint@fn_0030d320@@QAEPAXH@Z
namespace fn_0030d320 {
struct SymMatrix_30d320 {
    void Destruct_002fcaa0();
};

extern "C++" __declspec(nothrow) void __cdecl FreeBuf_0008d340(void*);
extern "C++" __declspec(nothrow) void __cdecl DeleteObj_0008d330(void*);
extern "C" char DAT_00431de4[];

class PhysicsJoint {
  public:
    void* vptr;
    char pad1[0x20 - 4];
    int m20;
    hulk_intptr m24;
    char pad2[0x48 - 0x28];
    SymMatrix_30d320 m48;
    char pad3[0x64 - 0x49];
    SymMatrix_30d320 m64;

    void* vfunc_0(int flags);
};

void* PhysicsJoint::vfunc_0(int flags) {
    SymMatrix_30d320* p = &m64;
    vptr = (void*)DAT_00431de4;
    p->Destruct_002fcaa0();
    m48.Destruct_002fcaa0();
    hulk_intptr v = m20;
    m24 = v;
    if (v)
        FreeBuf_0008d340((void*)v);
    if (flags & 1)
        DeleteObj_0008d330(this);
    return this;
}
} // namespace fn_0030d320


// 0x0030d370 FUN_0030d370 (46 B): matches/0x0030d370.cpp [wrapped: conflict: physics::PhysicsJoint; physics::PhysicsJoint0D]
// sym: ??0PhysicsJoint0D@physics@fn_0030d370@@QAE@XZ
namespace fn_0030d370 {
namespace physics {
struct Sub_30d370 {
    char pad[0x1c];
    Sub_30d370() throw();
};
struct Vec_30d370 {
    float x, y, z;
    Vec_30d370() throw() {}
    Vec_30d370(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30d370 v;
    char pad2[0x48 - 0x2c];
    Sub_30d370 s1;
    Sub_30d370 s2;
    PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
};
class PhysicsJoint0D : public PhysicsJoint {
  public:
    virtual ~PhysicsJoint0D() throw();
    PhysicsJoint0D() throw();
};
PhysicsJoint0D::PhysicsJoint0D() throw() {}
} // namespace physics
} // namespace fn_0030d370

namespace fn_fca90e00 {

// 0x0030d3a0 physics::PhysicsJoint0D::vfunc_0 (66 B): matches/0x0030d3a0.cpp
// sym: ?vfunc_0@PhysicsJoint0D_30d3a0@fn_fca90e00@@QAEPAXH@Z
// Same code shape as 0x0030d320 (propagated; names are from that function)
void* PhysicsJoint0D_30d3a0::vfunc_0(int flags) {
    SymMatrix_30d3a0* p = &m64;
    vptr = (void*)DAT_00431de4;
    p->Destruct_002fcaa0();
    m48.Destruct_002fcaa0();
    hulk_intptr v = m20;
    m24 = v;
    if (v)
        FreeBuf_0008d340((void*)v);
    if (flags & 1)
        DeleteObj_0008d330(this);
    return this;
}

} // namespace fn_fca90e00

// 0x0030d3f0 FUN_0030d3f0 (46 B): matches/0x0030d3f0.cpp [wrapped: conflict: physics::PhysicsJoint; physics::PhysicsJoint1D]
// sym: ??0PhysicsJoint1D@physics@fn_0030d3f0@@QAE@XZ
namespace fn_0030d3f0 {
namespace physics {
struct Sub_30d3f0 {
    char pad[0x1c];
    Sub_30d3f0() throw();
};
struct Vec_30d3f0 {
    float x, y, z;
    Vec_30d3f0() throw() {}
    Vec_30d3f0(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30d3f0 v;
    char pad2[0x48 - 0x2c];
    Sub_30d3f0 s1;
    Sub_30d3f0 s2;
    PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
};
class PhysicsJoint1D : public PhysicsJoint {
  public:
    virtual ~PhysicsJoint1D() throw();
    PhysicsJoint1D() throw();
};
PhysicsJoint1D::PhysicsJoint1D() throw() {}
} // namespace physics
} // namespace fn_0030d3f0

namespace fn_fca90e00 {

// 0x0030d420 physics::PhysicsJoint1D::vfunc_0 (66 B): matches/0x0030d420.cpp
// sym: ?vfunc_0@PhysicsJoint1D_30d420@fn_fca90e00@@QAEPAXH@Z
// Same code shape as 0x0030d320 (propagated; names are from that function)
void* PhysicsJoint1D_30d420::vfunc_0(int flags) {
    SymMatrix_30d420* p = &m64;
    vptr = (void*)DAT_00431de4;
    p->Destruct_002fcaa0();
    m48.Destruct_002fcaa0();
    hulk_intptr v = m20;
    m24 = v;
    if (v)
        FreeBuf_0008d340((void*)v);
    if (flags & 1)
        DeleteObj_0008d330(this);
    return this;
}

} // namespace fn_fca90e00

// 0x0030d470 FUN_0030d470 (46 B): matches/0x0030d470.cpp [wrapped: conflict: physics::PhysicsJoint; physics::PhysicsJoint3D]
// sym: ??0PhysicsJoint3D@physics@fn_0030d470@@QAE@XZ
namespace fn_0030d470 {
namespace physics {
struct Sub_30d470 {
    char pad[0x1c];
    Sub_30d470() throw();
};
struct Vec_30d470 {
    float x, y, z;
    Vec_30d470() throw() {}
    Vec_30d470(float a, float b, float c) throw() : x(a), y(b), z(c) {}
};
class PhysicsJoint {
  public:
    virtual ~PhysicsJoint() throw();
    char pad[0x1c];
    Vec_30d470 v;
    char pad2[0x48 - 0x2c];
    Sub_30d470 s1;
    Sub_30d470 s2;
    PhysicsJoint() throw() : v(0.0f, 0.0f, 0.0f) {}
};
class PhysicsJoint3D : public PhysicsJoint {
  public:
    virtual ~PhysicsJoint3D() throw();
    PhysicsJoint3D() throw();
};
PhysicsJoint3D::PhysicsJoint3D() throw() {}
} // namespace physics
} // namespace fn_0030d470

namespace fn_fca90e00 {

// 0x0030d4a0 physics::PhysicsJoint3D::vfunc_0 (66 B): matches/0x0030d4a0.cpp
// sym: ?vfunc_0@PhysicsJoint3D_30d4a0@fn_fca90e00@@QAEPAXH@Z
// Same code shape as 0x0030d320 (propagated; names are from that function)
void* PhysicsJoint3D_30d4a0::vfunc_0(int flags) {
    SymMatrix_30d4a0* p = &m64;
    vptr = (void*)DAT_00431de4;
    p->Destruct_002fcaa0();
    m48.Destruct_002fcaa0();
    hulk_intptr v = m20;
    m24 = v;
    if (v)
        FreeBuf_0008d340((void*)v);
    if (flags & 1)
        DeleteObj_0008d330(this);
    return this;
}

} // namespace fn_fca90e00

// 0x0030d4f0 FUN_0030d4f0 (159 B): equivalent/0x0030d4f0.cpp [wrapped: conflict: physics::PhysicsJoint; physics::PhysicsJoint0D; physics::PhysicsJoint1D; physics::PhysicsJoint3D]
// sym: ?FUN_0030d4f0@fn_0030d4f0@@YAPAVPhysicsJoint@physics@1@HHHH@Z
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_0030d4f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 12/12)
// FUN_0030d4f0 @ 0x0030d4f0
// FUN_0030d4f0: PhysicsJoint factory: 0 -> 0D, 1 -> 1D, 3 -> 3D
// equiv-map: ??0PhysicsJoint@physics@@QAE@HHH@Z = 0x0030ca80
// equiv-map: ??0PhysicsJoint1D@physics@@QAE@HHH@Z = 0x0030cdb0
// equiv-map: ??0PhysicsJoint3D@physics@@QAE@HHH@Z = 0x0030d030

void *__cdecl FUN_0008d690(unsigned int size);

namespace physics {

class PhysicsJoint {
public:
    PhysicsJoint(int a, int b, int c) throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(void *);
    char pad04[0xf8 - 4];
};

class PhysicsJoint0D : public PhysicsJoint {
public:
    PhysicsJoint0D(int a, int b, int c) throw() : PhysicsJoint(a, b, c) {}
    virtual void f5(void *);
};

class PhysicsJoint1D : public PhysicsJoint {
public:
    PhysicsJoint1D(int a, int b, int c) throw();
    virtual void f5(void *);
    char pad[0x120 - 0xf8];
};

class PhysicsJoint3D : public PhysicsJoint {
public:
    PhysicsJoint3D(int a, int b, int c) throw();
    virtual void f5(void *);
    char pad[0x15c - 0xf8];
};

} // namespace physics

physics::PhysicsJoint *__cdecl FUN_0030d4f0(int type, int a, int b, int c)
{
    if (type == 0) {
        void *mem = FUN_0008d690((int)sizeof(physics::PhysicsJoint0D));
        if (mem)
            return new (mem) physics::PhysicsJoint0D(a, b, c);
        return 0;
    }
    if (type == 1) {
        void *mem = FUN_0008d690((int)sizeof(physics::PhysicsJoint1D));
        if (mem)
            return new (mem) physics::PhysicsJoint1D(a, b, c);
        return 0;
    }
    if (type == 3) {
        void *mem = FUN_0008d690((int)sizeof(physics::PhysicsJoint3D));
        if (mem)
            return new (mem) physics::PhysicsJoint3D(a, b, c);
        return 0;
    }
    return 0;
}
} // namespace fn_0030d4f0

namespace fn_fca90e00 {

// 0x0030d590 physics::PhysicsJoint0D::vfunc_27 (87 B): matches/0x0030d590.cpp
// sym: ?d27@PhysicsJoint0D_30d590@fn_fca90e00@@UAEPAUPhysicsJoint_30d590@2@XZ
PhysicsJoint_30d590* PhysicsJoint0D_30d590::d27() {
    PhysicsJoint0D_30d590* r = new PhysicsJoint0D_30d590;
    r->Init_0030c690(this);
    this->v28(r);
    return r;
}

} // namespace fn_fca90e00

// 0x0030d5f0 physics::PhysicsJoint1D::vfunc_27 (87 B): matches/0x0030d5f0.cpp [wrapped: conflict: PhysicsJoint; PhysicsJoint1D; operatornew]
// sym: ?vf27@PhysicsJoint1D@fn_0030d5f0@@UAEPAVPhysicsJoint@2@XZ
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_0030d5f0 {
struct Trio_30d5f0 {
    int a, b, c;
    Trio_30d5f0() throw() {
        a = 0;
        b = 0;
        c = 0;
    }
};
struct SymMatrix_30d5f0 {
    char pad[0x1c];
    SymMatrix_30d5f0() throw();
};


class PhysicsJoint {
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
    virtual PhysicsJoint* vf27();
    virtual void vf28(PhysicsJoint*);
    PhysicsJoint() throw() {}
    char pad1[0x1c];
    Trio_30d5f0 t;
    char pad2[0x1c];
    SymMatrix_30d5f0 s48;
    SymMatrix_30d5f0 s64;
    char pad3[0x120 - 0x80];
};

class PhysicsJoint1D : public PhysicsJoint {
  public:
    PhysicsJoint1D() throw() {}
    void Init_0030c830(PhysicsJoint1D*);
    virtual PhysicsJoint* vf27();
};

PhysicsJoint* PhysicsJoint1D::vf27() {
    PhysicsJoint1D* clone = new PhysicsJoint1D;
    clone->Init_0030c830(this);
    this->vf28(clone);
    return clone;
}
} // namespace fn_0030d5f0


// 0x0030d650 physics::PhysicsJoint3D::vfunc_27 (87 B): matches/0x0030d650.cpp
// sym: ?vfunc_27@PhysicsJoint3D@physics@@UAEPAXXZ
void* physics::PhysicsJoint3D::vfunc_27() {
    Obj_30d650* p = (Obj_30d650*)ALLOC_0008d690(0x15c);
    if (p != 0) {
        *(void* volatile*)&p->m_vtable = (void*)&hulk_at_00431de4;
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->s1.Init_002fca90();
        p->s2.Init_002fca90();
        *(void* volatile*)&p->m_vtable = (void*)&hulk_at_00431f4c;
    } else {
        p = 0;
    }
    ((owners::Obj_30c8c0 *)p)->FUN_0030c8c0((owners::Obj_30c8c0 *)this);
    this->vfunc_28(p);
    return (void*)(p);
}

