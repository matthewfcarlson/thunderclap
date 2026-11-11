// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000989d0..0x0009f760 (kind game, layer game, confidence high), dominant class CCameraManager
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5ef2b3f {
#define TREE_TU_END }
namespace fn_f5ef2b3f {} using namespace fn_f5ef2b3f;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5ef2b3f {
class Obj_989d0 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31(void*);
    virtual void V32();
};
struct Triple_989d0 {
    int x, y, z;
    void Set(Triple_989d0* s) {
        x = s->x;
        y = s->y;
        z = s->z;
    }
};
class Owner_989d0 {
  public:
    char pad[0x170];
    Obj_989d0* a;
    Obj_989d0* b;
    char flag;
    char pad2[3];
    int zero;
    char pad3[0x28];
    Triple_989d0 t1a8;
    void helper(Obj_989d0*, void*);
    Triple_989d0* get(Obj_989d0*, Obj_989d0*);
    char F(void*, Obj_989d0*, char, Obj_989d0*);
};
class Sub {
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
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void _m_vf26();
    virtual void _m_vf27();
    virtual void _m_vf28();
    virtual void _m_vf29();
    virtual void _m_vf30();
    virtual void _m_vf31();
    virtual void f32(int a, int b);
    char _m_pad_4[0x1e4];
    int a;
    int b;
};
class Item_98e60 {
    char pad[0xf1];

  public:
    unsigned char value;
};
class Owner_98e60 {
    char pad[0xb0];

  public:
    Item_98e60* a;
    Item_98e60* b;
    Item_98e60* f;
    Item_98e60* c;
    Item_98e60* d;
    Item_98e60* e;
    void Clear();
};
class H {
  public:
    void A(void*);
    void B(void*);
};
class Obj_98ed0 {
  public:
    char pad[0xb0];
    H* a;
    H* b;
    H* f;
    H* c;
    H* d;
    H* e;
    void Run(void*);
};
class Obj_98f40 {
  public:
    char pad[0x19];
    char mVal;
    void Set(unsigned char v);
};
struct CDramaticCamera_nv_98f50 {
    CDramaticCamera* FUN_000a8400();
    void FUN_000a9110(int index, unsigned value);
};
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
struct Owner_98f50 {
    char padding[0xb0];
    CDramaticCamera* resource;
    void initialize(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f);
};
struct O_99030 {
    char pad[0x90];
    int m;
    void Set(int v);
};
class C_99040 {
  public:
    char pad[0x94];
    int field;
    void SetField(int value);
};
class Result_99050 {
  public:
    void Finish(int);
};
class Aux_99050 {
  public:
    Result_99050* Create();
};
class Anim_99050 {
  public:
    void A(int);
    void B(int);
};
class Holder_99050 {
  public:
    char pad[0x124];
    Anim_99050* anim;
};
class Target_99050 {
  public:
    void Do(int);
};
class Flagged_99050 {
  public:
    char pad[8];
    char flag;
};
class Arg_99050 {
  public:
    int pad0;
    Flagged_99050* f4;
    char pad8[0x18];
    Holder_99050* h20;
    char pad24[0x18];
    Target_99050* t3c;
};
class Obj_99050 {
  public:
    int pad0;
    unsigned flags;
    int pad8;
    Aux_99050* a;
    int p10;
    int p14;
    int pad18[32];
    int p98;
    void F(Arg_99050*);
};
struct CNISCamera_nv_990d0 {
    CNISCamera* FUN_000ac3c0();
    void FUN_000a9110(int index, unsigned int value);
};
struct Owner_990d0 {
    char padding[0xc0];
    CNISCamera* resource;
    void FUN_000990d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                      unsigned int f);
};
struct C_99180 {
    char p0[4];
    unsigned int flags;
    char p8[8];
    int a;
    char p14[0xa8];
    int b;
};
void *FUN_00263ea0(unsigned int size);
struct Vec3_991b0 {
    int x, y, z;
    void FUN_000a9050();
};
class Node {
  public:
    virtual void v0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void v6(int *out1, int *out2);
    virtual void _m_vf7();
    virtual float v8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual int v14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void _m_vf26();
    virtual void _m_vf27();
    virtual void v28();
    virtual void _m_vf29();
    virtual void v30(void *owner);
    virtual void v31(void *owner);
    void FUN_000361c0(int);
    void FUN_00036140(int);
};
class Target_991b0 {
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
    virtual void v30(void *owner);
    void FUN_000fd8a0(void *owner, int arg, int a, float b);
};
class CBlendCamera_991b0 {
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
    CBlendCamera_991b0 *FUN_000983d0();
    void FUN_00098480(void *owner);
    char FUN_000989d0(void *owner, Node *node, int zero, Node *target);
};
struct Sel {
    Target_991b0 *FUN_000fdc30();
};
struct Mgr_991b0 {
    char pad0[0x1ca0];
    Sel *sel;
};
struct Level_991b0 {
    char pad0[0x124];
    Mgr_991b0 *mgr;
};
struct Owner_991b0 {
    char pad0[0x20];
    Level_991b0 *level;
};
extern "C" Vec3_991b0 *__stdcall FUN_000a9170(Node *a, Node *b);
class Controller_991b0 {
public:
    char pad0[4];
    int flags;
    char pad8[8];
    Node *target;
    char pad14[0xbc - 0x14];
    CBlendCamera_991b0 *helper;
    void FUN_000991b0(Owner_991b0 *owner, Node *node, Node *tgt, bool arg4, bool arg5);
};
class Inner_99310 {
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
};
class Outer_99310 {
  public:
    char pad[0x10];
    Inner_99310* p;
};
class A_99320 {
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
    virtual void f37(int, float, float, float);
};
struct B_99320 {
    char pad[0x10];
    A_99320* p;
    void target(int mode, float a, float b, float c);
};
class Base_99330 {
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
};
class Obj_99330 {
  public:
    char pad[0x10];
    Base_99330* m;
    void target();
};
struct CScriptCamera_nv_99340 {
    CScriptCamera *FUN_000ac7d0();
};
class Panel_99340 {
public:
    char pad0[0xc4];
    CScriptCamera *range;
    void FUN_00099340();
};
struct Range_993f0 {
    void FUN_000a9110(int which, int v);
};
struct Panel_993f0 {
    char pad0[0xc4];
    Range_993f0* range;
    void FUN_000993f0(int a1, int a2, int a3, int a4, int a5, int a6);
};
struct Scaler_99470 {
};
struct Holder_99470 {
    char pad0[8];
    Scaler_99470 *scaler;         // 0x8
    Scaler_99470 *FUN_00086320();
};
struct Mode_99470 {
    bool FUN_001c3cb0();
};
Mode_99470 *FUN_001c3d90();
struct Anim_99470 {
    void FUN_000361c0(int a);
    void FUN_00036140(int a);
};
struct Status_99470 {
    char pad0[8];
    char flag;              // 0x8
};
struct Actor_99470 {
    char pad0[0x124];
    Anim_99470 *anim;             // 0x124
};
struct Ctx_99470 {
    char pad0[4];
    Status_99470 *status;         // 0x4
    char pad8[0x20 - 8];
    Actor_99470 *actor;           // 0x20
};
struct Target_99470 {
    char pad0[0x2c4];
    float scale;            // 0x2c4
};
class Handler_99470 {
public:
    char pad0[4];
    unsigned int flags;     // 0x4
    char pad8[4];
    Holder_99470 *holder;         // 0xc
    int arg0;               // 0x10
    int arg1;               // 0x14
    char pad18[0xc4 - 0x18];
    Target_99470 *target;         // 0xc4

    void FUN_000991b0(Ctx_99470 *ctx, int a, int b, int c, int d);
    void FUN_00099470(Ctx_99470 *ctx);
};
struct Inner_99500 {
    char p0[0x174];
    int a174;
    char p1[0x1ac - 0x178];
    int a1ac;
    char p2[0x1e4 - 0x1b0];
    int a1e4;
    char p3[0x21c - 0x1e8];
    int a21c;
    char p4[0x288 - 0x220];
    int a288;
    int a28c;
    int a290;
};
class C_99500 {
  public:
    void f(int a, int b, int c, int d, int e, int g);
    char p[0xc4];
    Inner_99500* m;
};
struct Triple { int a,b,c; };
class C_99730 {
  public:
    int pad;
    unsigned int m;
};
class A_99740 {
  public:
    int pad;
    unsigned int value;
};
class C_99750 {
  public:
    int pad;
    unsigned int x;
};
struct Callee {
    unsigned char FUN_000aca40(int);
};
struct A_99790 {
    int pad;
    unsigned int x;
};
class Obj_997a0 {
  public:
    int pad;
    unsigned int value;
};
class Thing {
  public:
    char _m_pad_0[0xc4];
    struct Inner* inner;
    void Set(int v);
    float Get();
};
class Owner {
  public:
    char _m_pad_0[0xb8];
    union { Sub* p; Thing* thing; };
    void Fn(hulk_intptr a, int b, int c);
    float Get();
};
struct Inner {
    char pad[0x2c4];
    int value;
};
struct Sub_99860 {
    void Fn(int, int);
};
struct Obj_99860 {
    char pad[0xc4];
    Sub_99860* sub;
    void Target(int, int);
};
class Obj_99880 {
  public:
    char pad[0xc4];
    struct Sub_99880* m;
    void Run(int, int);
};
struct Sub_99880 {
    char pad[0x1e0];
    void Fn(int, int);
};
class Sub_998a0 {
  public:
    void Fn(int, int);
};
class Obj_998a0 {
  public:
    void Fn(int, int);
    char pad[0xc4];
    Sub_998a0* mSub;
};
class Target {
  public:
    char pad[0xc4];
    struct Inner {
        char p[0x220];
        int a;
        int b;
    }* m;
    void Set(int a, int b);
};
struct Sub_998f0 {
    char d[0x70];
    void FUN_000ac790(float f);
};
struct Obj_998f0 {
    char pad0[0x218];
    Sub_998f0 sub;
    int i288;
    int i28c;
    int i290;
    int i294;
    int i298;
    int i29c;
};
struct Target_998f0 {
    char pad0[0xc4];
    Obj_998f0 *obj;
    void FUN_000998f0(int a1, int a2, int a3, int a4, int a5, int a6);
};
struct Sub_99960 {
    void Fn(int, int);
};
struct Obj_99960 {
    char pad[0xc4];
    Sub_99960* m;
    void Fn(int, int);
};
struct Obj_999f0 {
    void G(int, int);
};
class T_999f0 {
  public:
    char pad[0xc4];
    Obj_999f0* p;
    void Target(int, int);
};
class Obj_99a10 {
  public:
    char pad[0xc4];
    class Sub {
      public:
        virtual void a0();
        virtual void a1();
        virtual void a2();
        virtual void a3();
        virtual void a4();
        virtual void a5();
        virtual void a6();
        virtual void a7();
    }* m;
    void Fn();
};
class Sub_99a20 {
  public:
    virtual void A0();
    virtual void A1();
    virtual void A2();
    virtual void A3();
    virtual void A4();
    virtual void A5();
    virtual void A6();
    virtual void A7();
    virtual void A8();
    virtual void Vfunc9();
};
class Owner_99a20 {
  public:
    char pad[0xc4];
    Sub_99a20* mSub;
    void Target();
};
class Obj_99a30 {
  public:
    char pad[0xc4];
    char* ptr;
    void Set(unsigned char v);
};
class Result;
class Item {
  public:
};
class Result {
  public:
    float* Value();
};
class Host {
  public:
    char pad[0xb8];
    Item* item;
    float* Fun();
};
class Child_99aa0 {
  public:
    void run(int a, int b);
};
class Obj_99aa0 {
  public:
    char pad[0xb8];
    Child_99aa0* member;
    void f(hulk_intptr x);
};
extern int gValue_99aa0;
class Helper_99ae0 {
  public:
    void Run(float f);
};
class Obj_99ae0 {
  public:
    char pad[0xb8];
    Helper_99ae0* m;
    void Fn(float f);
};
class Sub_99b50 {
  public:
    float Get();
};
class Obj_99b50 {
  public:
    char pad[0xb8];
    Sub_99b50* p;
    float Get();
};
extern const float gMinusOne_99b70 = -1.0f;
struct X_99b70 {
    float f();
};
struct Obj_99b70 {
    char pad[0xb8];
    X_99b70* value;
};
class Inner_99b90 {
  public:
};
class Obj_99b90 {
  public:
    char pad[0xb8];
    Inner_99b90* m;
    void Fn(int a);
};
class Sub_99bb0 {
  public:
    float Fn();
};
class Obj_99bb0 {
  public:
    char pad[0xb8];
    Sub_99bb0* mSub;
    float Fn();
};
class Child {
  public:
    void Func(int);
};
class Obj {
  public:
    char _m_pad_0[0x80];
    int a;
    int b;
    int c;
    int d;
    char _m_pad_90[0x28];
    Child* child;
    char _m_pad_bc[0x8];
    union { Sub* p; Sub* sub; };
    void Set(int x, int y, int z, int w);
    void Fn(int a, int b);
    void Set(int x, int y);
    void Func(int);
};
struct Sub_99c60 {
    char pad[0x228];
    int value;
};
struct Obj_99c60 {
    char pad[0xc4];
    Sub_99c60* sub;
    void Set(int v);
};
struct Sub_99ca0 {
    char pad[0x1f0];
    int value;
};
class Obj_99ca0 {
  public:
    char pad[0xc4];
    Sub_99ca0* ptr;
    void Set(int x);
};
struct Sub_99cc0 {
    char pad[0x1b8];
    int value;
};
struct Obj_99cc0 {
    char pad[0xc4];
    Sub_99cc0* sub;
    void Set(int x);
};
class Obj_99ce0 {
  public:
    char pad[0xc4];
    void* m180;
    void Set(int value);
};
class V {
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
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void target(int, int, int);
};
class C_99d00 {
  public:
    char pad[0xb8];
    V* p;
    void f(hulk_intptr, hulk_intptr, int);
};
class Obj_99d20 {
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
    virtual int f34(int, int, int, int, int);
};
class Host_99d20 {
  public:
    char pad[0xb8];
    Obj_99d20* p;
};
class B_99d40 {
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
    virtual void f38(int, int, int);
};
class A_99d40 {
  public:
    char pad[0xb8];
    B_99d40* m;
    void target(int, int, int);
};
class Obj_9a090 {
  public:
    virtual void F0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void F28();
};
void* __cdecl Alloc(int);
Obj_9a090* __fastcall Construct(void* mem);
class Owner_9a090 {
  public:
    char p0[0x10];
    void* other;
    char p1[0xa4];
    Obj_9a090* item;
    void Prep();
    void Run();
};
struct Resource_9a0e0 {
    virtual void unused();
    virtual void release();
};
struct Owner_9a0e0 {
    char pad0[4];
    int state;
    int field8;
    char padc[4];
    int field10;
    int field14;
    unsigned char flag18, flag19;
    char pad1a[2];
    int count1;
    Resource_9a0e0* resources1[31];
    int count2;
    Resource_9a0e0* resources2[4];
    Resource_9a0e0* rB0;
    Resource_9a0e0* rB4;
    Resource_9a0e0* rB8;
    Resource_9a0e0* rBC;
    Resource_9a0e0* rC0;
    Resource_9a0e0* rC4;
    int FUN_0009a0e0();
};
class Item_9a220 {
  public:
    virtual void A();
    virtual void Release();
};
class CCameraManager_9a220 {
  public:
    char pad[0x80];
    volatile int a, b, c, d;
    volatile float f;
    volatile int g, unused, count;
    Item_9a220* items[1];
    void Clear();
};
struct Method0_9a400 {
    void FUN_000361c0(int flag);
    void FUN_00036140(int flag);
};
struct Scene_9a400 { void FUN_000ac560(int v); };
struct Stage_9a400 {  };
struct StageOwner { Stage_9a400* FUN_00086320(); };
struct Cast { char pad[0x124]; Method0_9a400* camera; };
struct Hud;
struct Player_9a400 { char pad[0x20]; Cast* cast; };
struct Widget_9a400 {
    char pad0[4];
    unsigned int flags;
    char pad8[4];
    StageOwner* owner;
    int f10;
    int f14;
    char pad18[0xc0 - 0x18];
    Scene_9a400* scene;
    void FUN_000991b0(Player_9a400* p, int a, int b, int c, int d);
    void FUN_0009a400(Player_9a400* p);
};
struct Target_9a480 { void FUN_000a0bc0(float v); };
struct State_9a480 { int FUN_00088fa0(); };
struct Provider_9a480 { char pad[0x80]; State_9a480 state; };
struct Root_9a480 {  };
} // namespace fn_f5ef2b3f
struct World { char pad[0x54]; Root_9a480* root; };
namespace fn_f5ef2b3f {
struct Slider_9a480 {
    char pad0[0xb8];
    Target_9a480* target;
    void FUN_0009a480(float v);
};
extern "C" char DAT_00404c00[];
class Owner_9a6e0 {};
typedef void (Owner_9a6e0::*Fn_9a6e0)(float, float, float, float, float, float);
class Method6_9a6e0 {
  public:
    void* v;
    ScriptFunctionFields f;
    Fn_9a6e0 m1c;
    void Init(const char*, int);
    Method6_9a6e0* Run(const char*, Fn_9a6e0);
};
struct Function_9a780 {
    virtual void f0();
    virtual void f1();
};
void FUN_0009a7a0(const char*, const char*, const char*, int);
typedef void (__stdcall *Callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" char DAT_00404c10[];
extern "C" char DAT_0048e10c[];
class Owner_9a800 {};
typedef void (Owner_9a800::*Fn_9a800)(float, float, int, float);
struct FUN_001d0480 {
    FUN_001d0480(const char*, int);
};
class Method4_9a800 : public FUN_001d0480 {
  public:
    void* vftable;
    ScriptFunctionFields f;
    Fn_9a800 value1c;
    Method4_9a800(const char* a, Fn_9a800 b);
};
struct Vector_9a890 { float x,y,z; };
struct Args { float first, second; Vector_9a890 direction; float last; };
struct CCameraManager_9a890 { int unused; };
extern "C" char DAT_00404c20[];
extern char __cdecl Convert(const char*);
class Method3_9a8e0 {
  public:
    void Init(void*, int);
    Method3_9a8e0(void*, hulk_intptr);
    hulk_intptr vtable;
    char a[0x10 - 4];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int field1c;
};
class CFEManager_9aa00 {
  public:
    void Call(const char*, int);
};
class Function_9aa00 {
  public:
    virtual void f0();
    virtual void f1();
};
extern "C" char DAT_00404c50[];
class Function_9aaf0 {
  public:
    void Init(int, int);
};
extern unsigned char __cdecl GetValue(const char*);
class Method3_9aaf0 : public Function_9aaf0 {
  public:
    hulk_intptr vt;
    char pad4[0x0c];
    unsigned char b10, b11, b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    int field1c;
    Method3_9aaf0(hulk_intptr a, hulk_intptr b);
};
extern "C" char DAT_00404c60[];
struct Function_9aba0 {
    void Init(const char*, int);
};
class Owner_9aba0 {};
typedef void (Owner_9aba0::*Fn_9aba0)(bool, bool, bool, float);
class Method4_9aba0 : public Function_9aba0 {
  public:
    Method4_9aba0* Init(const char*, Fn_9aba0);
    void* vf;
    ScriptFunctionFields f;
    Fn_9aba0 member1c;
};
struct CCameraManager_9ad00 { void FUN_0009ad00(unsigned, unsigned, unsigned, unsigned); };
struct Function_9ad00 { virtual void vfunc_0(); virtual void vfunc_1(); };
extern "C" char DAT_00404c80[];
class Owner_9ad40 {};
typedef void (Owner_9ad40::*Fn_9ad40)(bool, bool, bool, bool, float);
class Method5_9ad40 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9ad40 p1c;
    void FUN_001d0480(const char*, int);
    Method5_9ad40* Init(const char*, Fn_9ad40);
};
struct Function_9ade0 {
    virtual void f0();
    virtual void f1();
};
void FUN_0009ae00(const char*, const char*, const char*, int);
extern "C" char DAT_00404c90[];
class Owner_9ae50 {};
typedef void (Owner_9ae50::*Fn_9ae50)(bool, bool, bool, bool, bool, bool, float);
class Method7_9ae50 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9ae50 owner;
    void FUN_001d0480(const char*, int);
    Method7_9ae50* Init(const char*, Fn_9ae50);
};
struct Function_9af00 {
    virtual void f0();
    virtual void f1();
};
void FUN_0009af20(const char*, const char*, const char*, int);
struct B_9af20 {
    unsigned char v;
};
struct Obj_9af20 {
    void invoke(B_9af20, B_9af20, B_9af20, B_9af20, B_9af20, unsigned char, int);
};
typedef void (Obj_9af20::*CB)(B_9af20, B_9af20, B_9af20, B_9af20, B_9af20, unsigned char, int);
struct Rec_9af20 {
    B_9af20 a;
    char p[3];
};
class CActorManager_9aff0 {
  public:
    void f();
};
class CActorManager_9b060;
typedef unsigned char(__fastcall* Fn_9b060)(CActorManager_9b060*);
extern char DAT_00404cc0[];
class Owner_9b080 {};
typedef void (Owner_9b080::*Fn_9b080)(int, int, float, int, int, float);
class Method6_9b080 {
public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9b080 p1c;
    void FUN_001d0480(const char*, int);
    Method6_9b080* Init(const char* arg, Fn_9b080 value);
};
struct Function_9b120 {
    virtual void f0();
    virtual void f1();
};
void FUN_0009b140(const char*, const char*, const char*, int);
class Dummy_9b1e0 {
  public:
    void Call(void*);
};
} // namespace fn_f5ef2b3f
namespace math {
struct Vector_9b270 { float x, y, z; };
}
namespace fn_f5ef2b3f {
struct CCameraManager_9b270 { void FUN_0009b270(math::Vector_9b270, math::Vector_9b270); };
struct Function_9b270 { virtual void vfunc_0(); virtual void vfunc_1(); };
class CActorManager_9b310 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_9b310::*MFn_9b310)(unsigned char);
class Function_9b310 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
extern "C" char DAT_00404d00[];
class Helper_9b330 {
  public:
    void Init(const char*, int);
};
} // namespace fn_f5ef2b3f
extern "C" unsigned char FUN_001d04d0(hulk_intptr);
namespace fn_f5ef2b3f {
class Owner_9b330 {};
typedef void (Owner_9b330::*Fn_9b330)(int, float, float, float);
class Method4_9b330 {
  public:
    void* vtable;
    ScriptFunctionFields f;
    Fn_9b330 m1c;
    Method4_9b330* Fn(const char*, Fn_9b330);
};
struct Vector_9b450 {
    int x, y, z;
};
class CGameFlowManager_9b450 {
  public:
    virtual Vector_9b450* Get(Vector_9b450*);
};
typedef Vector_9b450* (CGameFlowManager_9b450::*Fn_9b450)(Vector_9b450*);
extern "C" char DAT_00404d20[];
struct ThisCall_001d0480 {
    void FUN_001d0480(const char*, int);
};
class Owner_9b4a0 {};
typedef bool (Owner_9b4a0::*Fn_9b4a0)(float, float, float, float, float, float);
class Method6_9b4a0 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9b4a0 p1c;
    Method6_9b4a0* Run(const char*, Fn_9b4a0);
};
struct Function_9b540 {
    virtual void f0();
    virtual void f1();
};
void FUN_0009b560(const char*, const char*, const char*, int);
class Target_9b560 {
public:
    char Dummy(int a0, int a1, int a2, int a3, int a4, int a5);
};
typedef char (Target_9b560::*Callback_9b560)(int a0, int a1, int a2, int a3, int a4, int a5);
union CallbackBits {
    unsigned int raw;
    Callback_9b560 fn;
};
class Dummy_9b630 {
  public:
    void Call(void*);
};
class Function_9b6b0 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Vector_9b740 {
    int x, y, z;
};
struct CCameraManager_9b740 {
    void f(Vector_9b740, unsigned char);
};
struct Function_9b740 {
    virtual void a();
    virtual void b();
};
} // namespace fn_f5ef2b3f
class type_info {
  public:
    virtual ~type_info();
};
namespace fn_f5ef2b3f {
extern int g_vftable_9b770;
class Owner_9b770 {};
typedef bool (Owner_9b770::*Fn_9b770)(float, float, float, float, bool);
} // namespace fn_f5ef2b3f
extern unsigned char __cdecl FUN_001d04d0(const type_info&);
namespace fn_f5ef2b3f {
class Method5_9b770 : public FUN_001d0480 {
  public:
    Method5_9b770(const char*, Fn_9b770);
    void* vftable;
    ScriptFunctionFields fields;
    Fn_9b770 n;
};
struct Function_9b810 {
    virtual void f0();
    virtual void f1();
};
void FUN_0009b830(const char*, const char*, const char*, int);
extern "C" char DAT_00404d80[];
class Owner_9b930 {};
typedef void (Owner_9b930::*Fn_9b930)(int, int, int, int);
class Method4_9b930 {
  public:
    void* vptr;
    ScriptFunctionFields f;
    Fn_9b930 fn;
    Method4_9b930* FUN_0009b930(const char*, Fn_9b930);
};
class CCameraManager_9b9c0 {
  public:
    void Fn(char*, char*, char*, char*);
};
class Function_9b9c0 {
  public:
    virtual void f0();
    virtual void f1();
};
inline char* next(char**& p) {
    return *p++;
}
class Function_9b9f0 {
  public:
    Function_9b9f0(int, int);
    virtual void f();
};
class Method0_9b9f0 : public Function_9b9f0 {
  public:
    Method0_9b9f0(int, int);
    virtual void f();
    char pad[0x14];
    unsigned char flag;
    char pad2[3];
    int value;
};
unsigned char __cdecl fun2(hulk_intptr);
struct Resource_9bc60 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void activate(unsigned); virtual void deactivate(unsigned);
 void FUN_000a08e0(unsigned);
};
struct Part_9bc60 { void FUN_000a91d0(unsigned); };
struct Owner_9bc60 {
 unsigned unknown0; unsigned flags; char pad8[8]; Resource_9bc60* current; Resource_9bc60* pending; unsigned char ready; unsigned char done; char pad1a[0xb0-0x1a]; Part_9bc60* part0; Part_9bc60* part1; Resource_9bc60* resource; Part_9bc60* part2; Part_9bc60* part3; Part_9bc60* part4;
 void FUN_000991b0(unsigned,Resource_9bc60*,Resource_9bc60*,unsigned,unsigned);
 void FUN_00099050(unsigned); void FUN_0009a400(unsigned); void FUN_00099470(unsigned);
 void FUN_0009bc60(hulk_uintptr);
};
struct Toggle { void FUN_000361c0(int); void FUN_00036140(int); };
struct Context_9bf50 { char pad[0x124]; Toggle* toggle; };
struct Arg_9bf50 { char pad[0x20]; Context_9bf50* context; };
struct CNISCamera_nv_9bf50 {
    CNISCamera* FUN_000ac3c0();
    void FUN_000ac560(void*);
};
struct Helper_9bf50 { void FUN_00098480(Arg_9bf50*); };
struct Target_9bf50 {
 char pad0[4]; unsigned flags; char pad8[8]; unsigned value; unsigned saved; unsigned char busy; char pad19[0xbc-0x19]; Helper_9bf50* helper; CNISCamera* item;
  void FUN_000991b0(Arg_9bf50*,unsigned,CNISCamera*,int,int);
 void run(Arg_9bf50* arg, void* input);
};
struct Details_9c060 { char pad[0x124]; Node* node; };
struct State_9c060 { char pad[8]; unsigned char active; };
struct Input_9c060 { char pad0[4]; State_9c060* state; char pad1[0x18]; Details_9c060* details; };
struct Worker_9c060 { char pad[0x2cc]; unsigned char active; void FUN_000ac9c0(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned); };
struct Result_9c060 { void FUN_00086100(unsigned); };
struct Lookup_9c060 { Result_9c060* FUN_00086320(); };
struct Helper_9c060 { void FUN_00098480(Input_9c060*); };
struct Object {
  public:
    char _m_pad_0[0x4];
    unsigned int flags;
    char _m_pad_8[0x4];
    Lookup_9c060* lookup;
    union { unsigned current; Callee* value; };
    unsigned previous;
    unsigned char disabled;
    char _m_pad_19[0xa3];
    Helper_9c060* helper;
    char _m_pad_c0[0x4];
    union { Callee* other; Worker_9c060* worker; };
    void FUN_00099500(int, int, Triple, int);
    void FUN_00099570(int a,int b,int c,int d,int e,int f);
    int FUN_00099760();
    void FUN_000991b0(Input_9c060*, unsigned, Worker_9c060*, int, int);
    void target(Input_9c060*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
extern int g;
class X {
  public:
    void callee(int, int, int, int, int, int, int, int);
    void target(int a, int b, int c, int d, int e, int f, int h);
};
class CCameraManager_9c2c0 {
  public:
    void Fn(float, float, float, float, float, float);
};
class Function_9c2c0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
} // namespace fn_f5ef2b3f
namespace math {
struct Vector_9c370 {
    float x, y, z;
};
}
namespace fn_f5ef2b3f {
class CCameraManager_9c370 {
  public:
    void fn(float, float, math::Vector_9c370, float);
};
struct CCameraManager_9c410 {
    void cameraMethod(float, float, bool);
};
struct CameraArgs {
    float first;
    float second;
    bool third;
};
class CActorManager_9c4c0 {
  public:
    void Method(const char*, float);
};
struct Pair_9c4c0 {
    const char* s;
    float f;
};
struct P9C5C0_9c5c0 {
    char a;
    char pad[3];
    char b;
    char pad2[3];
    char c;
};
class Mgr_9c5c0 {
  public:
    void f(unsigned char, unsigned char, unsigned char);
};
class Function_9c5c0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct CCameraManager_9c640 { void FUN_0009c640(unsigned int, unsigned int, unsigned int, float); };
struct Arguments { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; char pad2[3]; float fourth; };
struct CCameraManager_9c6d0 { void FUN_0009c6d0_placeholder(unsigned, unsigned, unsigned, unsigned); };
struct BoolArguments { unsigned char first; char pad0[3]; unsigned char second; char pad1[3]; unsigned char third; char pad2[3]; unsigned char fourth; };
class Function_9c800 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CActorManager_9c880 {
  public:
    void run();
};
class CActorManager_9c8f0;
typedef unsigned char(__fastcall* Fn_9c8f0)(CActorManager_9c8f0*);
class CActorManager_9ca10 {
  public:
    void invoke(const char*);
};
} // namespace fn_f5ef2b3f
namespace math {
struct Vector_9cab0 { float x,y,z; };
}
namespace fn_f5ef2b3f {
struct CCameraManager_9cab0 { void FUN_0009cab0(math::Vector_9cab0, math::Vector_9cab0); };
struct VectorPair { math::Vector_9cab0 first, second; };
class Actor_9cb60 {
  public:
    void fn(unsigned char);
};
class CCameraManager_9cbd0 {
  public:
    void Action(int, float, float, float);
};
} // namespace fn_f5ef2b3f
namespace math {
struct Vector_9cc60 { float x,y,z; };
}
namespace fn_f5ef2b3f {
struct CCameraManager_9cc60 { math::Vector_9cc60 *FUN_0009cc60(math::Vector_9cc60 *out); };
class Function_9ccf0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CActorManager_9cd80 {
  public:
    void invoke(const char*);
};
class CActorManager_9ce00 {
  public:
    int act();
};
class Vector_9cea0 {
  public:
    float x, y, z;
};
class CCameraManager_9cea0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c(Vector_9cea0, unsigned char);
};
class Function_9cf20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class CCameraManager_9d040 {
public:
    void method(char *, char *, char *, char *);
};
class CActorManager_9d0d0 {
  public:
    float Get();
};
typedef float (CActorManager_9d0d0::*Fn_9d0d0)();
extern "C" void* FUN_0008d690(unsigned int);
} // namespace fn_f5ef2b3f
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f5ef2b3f {
class CCameraManager_9d380 {};
typedef void (CCameraManager_9d380::*Fn_9d380)(float, float, float, float, float, float);
class Registry_9d380 { public:
    void FUN_0009d380(const char* a1, CCameraManager_9d380* a2, Fn_9d380 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_9d380;
template<> class Closure6_9d380<CCameraManager_9d380, void, float, float, float, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d380 fn; CCameraManager_9d380* owner; Closure6_9d380(CCameraManager_9d380* o) { owner = o; } };
class Raw_9d380 { public: void FUN_0009a6e0(const char*, Fn_9d380); };
} // namespace fn_f5ef2b3f
namespace math {
class Vector_9d3e0 { public: float x, y, z; };
}
namespace fn_f5ef2b3f {
class CCameraManager_9d3e0 {};
typedef void (CCameraManager_9d3e0::*Fn_9d3e0)(float, float, math::Vector_9d3e0, float);
class Registry_9d3e0 { public:
    void FUN_0009d3e0(const char* a1, CCameraManager_9d3e0* a2, Fn_9d3e0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_9d3e0;
template<> class Closure4_9d3e0<CCameraManager_9d3e0, void, float, float, math::Vector_9d3e0, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d3e0 fn; CCameraManager_9d3e0* owner; Closure4_9d3e0(CCameraManager_9d3e0* o) { owner = o; } };
class Raw_9d3e0 { public: void FUN_0009a800(const char*, Fn_9d3e0); };
class CCameraManager_9d440 {};
typedef void (CCameraManager_9d440::*Fn_9d440)(float, float, bool);
class Registry_9d440 { public:
    void FUN_0009d440(const char* a1, CCameraManager_9d440* a2, Fn_9d440 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_9d440;
template<> class Closure3_9d440<CCameraManager_9d440, void, float, float, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_9d440 fn; CCameraManager_9d440* owner; Closure3_9d440(CCameraManager_9d440* o) { owner = o; } };
class Raw_9d440 { public: void FUN_0009a8e0(const char*, Fn_9d440); };
class CCameraManager_9d4f0 {};
typedef void (CCameraManager_9d4f0::*Fn_9d4f0)(float, float, float, float);
class Registry_9d4f0 { public:
    void FUN_0009d4f0(const char* a1, CCameraManager_9d4f0* a2, Fn_9d4f0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_9d4f0;
template<> class Closure4_9d4f0<CCameraManager_9d4f0, void, float, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d4f0 fn; CCameraManager_9d4f0* owner; Closure4_9d4f0(CCameraManager_9d4f0* o) { owner = o; } };
class Raw_9d4f0 { public: void FUN_0009aa20(const char*, Fn_9d4f0); };
class CCameraManager_9d550 {};
typedef void (CCameraManager_9d550::*Fn_9d550)(bool, bool, bool);
class Registry_9d550 { public:
    void FUN_0009d550(const char* a1, CCameraManager_9d550* a2, Fn_9d550 a3);
};
template<class C, class R, class A1, class A2, class A3> class Closure3_9d550;
template<> class Closure3_9d550<CCameraManager_9d550, void, bool, bool, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_9d550 fn; CCameraManager_9d550* owner; Closure3_9d550(CCameraManager_9d550* o) { owner = o; } };
class Raw_9d550 { public: void FUN_0009aaf0(const char*, Fn_9d550); };
class CCameraManager_9d5b0 {};
typedef void (CCameraManager_9d5b0::*Fn_9d5b0)(bool, bool, bool, float);
class Registry_9d5b0 { public:
    void FUN_0009d5b0(const char* a1, CCameraManager_9d5b0* a2, Fn_9d5b0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_9d5b0;
template<> class Closure4_9d5b0<CCameraManager_9d5b0, void, bool, bool, bool, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d5b0 fn; CCameraManager_9d5b0* owner; Closure4_9d5b0(CCameraManager_9d5b0* o) { owner = o; } };
class Raw_9d5b0 { public: void FUN_0009aba0(const char*, Fn_9d5b0); };
class CCameraManager_9d610 {};
typedef void (CCameraManager_9d610::*Fn_9d610)(bool, bool, bool, bool);
class Registry_9d610 { public:
    void FUN_0009d610(const char* a1, CCameraManager_9d610* a2, Fn_9d610 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_9d610;
template<> class Closure4_9d610<CCameraManager_9d610, void, bool, bool, bool, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_9d610 fn; CCameraManager_9d610* owner; Closure4_9d610(CCameraManager_9d610* o) { owner = o; } };
class Raw_9d610 { public: void FUN_0009ac70(const char*, Fn_9d610); };
class CCameraManager_9d670 {};
typedef void (CCameraManager_9d670::*Fn_9d670)(bool, bool, bool, bool, float);
class Registry_9d670 { public:
    void FUN_0009d670(const char* a1, CCameraManager_9d670* a2, Fn_9d670 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_9d670;
template<> class Closure5_9d670<CCameraManager_9d670, void, bool, bool, bool, bool, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d670 fn; CCameraManager_9d670* owner; Closure5_9d670(CCameraManager_9d670* o) { owner = o; } };
class Raw_9d670 { public: void FUN_0009ad40(const char*, Fn_9d670); };
class CCameraManager_9d6d0 {};
typedef void (CCameraManager_9d6d0::*Fn_9d6d0)(bool, bool, bool, bool, bool, bool, float);
class Registry_9d6d0 { public:
    void FUN_0009d6d0(const char* a1, CCameraManager_9d6d0* a2, Fn_9d6d0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7_9d6d0;
template<> class Closure7_9d6d0<CCameraManager_9d6d0, void, bool, bool, bool, bool, bool, bool, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d6d0 fn; CCameraManager_9d6d0* owner; Closure7_9d6d0(CCameraManager_9d6d0* o) { owner = o; } };
class Raw_9d6d0 { public: void FUN_0009ae50(const char*, Fn_9d6d0); };
class CCameraManager_9d810 {};
typedef void (CCameraManager_9d810::*Fn_9d810)(int, int, float, int, int, float);
class Registry_9d810 { public:
    void FUN_0009d810(const char* a1, CCameraManager_9d810* a2, Fn_9d810 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_9d810;
template<> class Closure6_9d810<CCameraManager_9d810, void, int, int, float, int, int, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d810 fn; CCameraManager_9d810* owner; Closure6_9d810(CCameraManager_9d810* o) { owner = o; } };
class Raw_9d810 { public: void FUN_0009b080(const char*, Fn_9d810); };
class CCameraManager_9d960 {};
typedef void (CCameraManager_9d960::*Fn_9d960)(int, float, float, float);
class Registry_9d960 { public:
    void FUN_0009d960(const char* a1, CCameraManager_9d960* a2, Fn_9d960 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_9d960;
template<> class Closure4_9d960<CCameraManager_9d960, void, int, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9d960 fn; CCameraManager_9d960* owner; Closure4_9d960(CCameraManager_9d960* o) { owner = o; } };
class Raw_9d960 { public: void FUN_0009b330(const char*, Fn_9d960); };
class CCameraManager_9da30 {};
typedef bool (CCameraManager_9da30::*Fn_9da30)(float, float, float, float, float, float);
class Registry_9da30 { public:
    void FUN_0009da30(const char* a1, CCameraManager_9da30* a2, Fn_9da30 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6_9da30;
template<> class Closure6_9da30<CCameraManager_9da30, bool, float, float, float, float, float, float> : public ScriptFunctionFields { public: virtual void v(); Fn_9da30 fn; CCameraManager_9da30* owner; Closure6_9da30(CCameraManager_9da30* o) { owner = o; } };
class Raw_9da30 { public: void FUN_0009b4a0(const char*, Fn_9da30); };
class CCameraManager_9dba0 {};
typedef bool (CCameraManager_9dba0::*Fn_9dba0)(float, float, float, float, bool);
class Registry_9dba0 { public:
    void FUN_0009dba0(const char* a1, CCameraManager_9dba0* a2, Fn_9dba0 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5_9dba0;
template<> class Closure5_9dba0<CCameraManager_9dba0, bool, float, float, float, float, bool> : public ScriptFunctionFields { public: virtual void v(); Fn_9dba0 fn; CCameraManager_9dba0* owner; Closure5_9dba0(CCameraManager_9dba0* o) { owner = o; } };
class Raw_9dba0 { public: void FUN_0009b770(const char*, Fn_9dba0); };
class CCameraManager_9dc50 {};
typedef void (CCameraManager_9dc50::*Fn_9dc50)(char*, char*, char*, char*);
class Registry_9dc50 { public:
    void FUN_0009dc50(const char* a1, CCameraManager_9dc50* a2, Fn_9dc50 a3);
};
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4_9dc50;
template<> class Closure4_9dc50<CCameraManager_9dc50, void, char*, char*, char*, char*> : public ScriptFunctionFields { public: virtual void v(); Fn_9dc50 fn; CCameraManager_9dc50* owner; Closure4_9dc50(CCameraManager_9dc50* o) { owner = o; } };
class Raw_9dc50 { public: void FUN_0009b930(const char*, Fn_9dc50); };


// 0x000989d0 FUN_000989d0 (131 B): matches/0x000989d0.cpp
// sym: ?F@Owner_989d0@fn_f5ef2b3f@@QAEDPAXPAVObj_989d0@2@D1@Z
char Owner_989d0::F(void* p2, Obj_989d0* p3, char p4, Obj_989d0* p5) {
    p3->V0();
    a = p3;
    flag = p4;
    if (!p4) {
        helper(p3, (char*)this + 0x180);
        p3->V31(p2);
    }
    p5->V0();
    b = p5;
    Triple_989d0* q = get(a, p5);
    t1a8 = *q;
    zero = 0;
    return 1;
}

} // namespace fn_f5ef2b3f

// 0x00098e20 FUN_00098e20 (10 B): matches/0x00098e20.cpp
// sym: ?FUN_00098e20@A_98e20@owners@@QAEXH@Z
void owners::A_98e20::FUN_00098e20(hulk_intptr x) {
    value = ((int)x);
}

namespace fn_f5ef2b3f {

// 0x00098e30 FUN_00098e30 (33 B): matches/0x00098e30.cpp
// sym: ?Fn@Owner@fn_f5ef2b3f@@QAEXHHH@Z
void Owner::Fn(hulk_intptr a, int b, int c) {
    if (p)
        p->f32(b, c);
}


// 0x00098e60 FUN_00098e60 (99 B): matches/0x00098e60.cpp
// sym: ?Clear@Owner_98e60@fn_f5ef2b3f@@QAEXXZ
void Owner_98e60::Clear() {
    if (a)
        a->value = 0;
    if (b)
        b->value = 0;
    if (c)
        c->value = 0;
    if (d)
        d->value = 0;
    if (e)
        e->value = 0;
    if (f)
        f->value = 0;
}


// 0x00098ed0 FUN_00098ed0 (109 B): matches/0x00098ed0.cpp
// sym: ?Run@Obj_98ed0@fn_f5ef2b3f@@QAEXPAX@Z
void Obj_98ed0::Run(void* arg) {
    if (a)
        a->A(arg);
    if (b)
        b->A(arg);
    if (c)
        c->A(arg);
    if (d)
        d->A(arg);
    if (e)
        e->A(arg);
    if (f)
        f->B(arg);
}


// 0x00098f40 FUN_00098f40 (10 B): matches/0x00098f40.cpp
// sym: ?Set@Obj_98f40@fn_f5ef2b3f@@QAEXE@Z
void Obj_98f40::Set(unsigned char v) {
    mVal = (char)v;
}


// 0x00098f50 FUN_00098f50 (176 B): matches/0x00098f50.cpp
// sym: ?initialize@Owner_98f50@fn_f5ef2b3f@@QAEXIIIIII@Z
void Owner_98f50::initialize(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f) {
    if (!resource) {
        CDramaticCamera* memory = (CDramaticCamera*)thunk_FUN_0008d690(0x1c0);
        resource = memory ? ((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(memory))))->FUN_000a8400() : 0;
        resource->vfunc_0();
        resource->vfunc_28();
    }
    ((owners::Thing_a90f0 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a90f0(0, (int)a);
    ((owners::C_a9130 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a9130(0, (int)b);
    ((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))->FUN_000a9110(0, c);
    ((owners::Thing_a90f0 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a90f0(1, (int)d);
    ((owners::C_a9130 *)(((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))))->FUN_000a9130(1, (int)e);
    ((CDramaticCamera_nv_98f50*)(((CDramaticCamera*)(resource))))->FUN_000a9110(1, f);
}


// 0x00099000 FUN_00099000 (43 B): matches/0x00099000.cpp
// sym: ?Set@Obj@fn_f5ef2b3f@@QAEXHHHH@Z
void Obj::Set(int x, int y, int z, int w) {
    a = x;
    b = y;
    c = z;
    d = w;
}


// 0x00099030 FUN_00099030 (13 B): matches/0x00099030.cpp
// sym: ?Set@O_99030@fn_f5ef2b3f@@QAEXH@Z
void O_99030::Set(int v) {
    m = v;
}


// 0x00099040 FUN_00099040 (13 B): matches/0x00099040.cpp
// sym: ?SetField@C_99040@fn_f5ef2b3f@@QAEXH@Z
void C_99040::SetField(int value) {
    field = value;
}


// 0x00099050 FUN_00099050 (115 B): matches/0x00099050.cpp
// sym: ?F@Obj_99050@fn_f5ef2b3f@@QAEXPAVArg_99050@2@@Z
void Obj_99050::F(Arg_99050* arg) {
    bool on = ((flags >> 2) & 1) != 0;
    if (on) {
        a->Create()->Finish(0);
        arg->t3c->Do(p98);
        arg->f4->flag = 1;
        Anim_99050* an = arg->h20->anim;
        if (an) {
            an->A(0);
            an->B(0);
        }
        unsigned f = flags & 0xfffffffb;
        p10 = p14;
        p14 = 0;
        flags = f;
    }
}


// 0x000990d0 FUN_000990d0 (176 B): matches/0x000990d0.cpp
// sym: ?FUN_000990d0@Owner_990d0@fn_f5ef2b3f@@QAEXIIIIII@Z
void Owner_990d0::FUN_000990d0(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e,
                         unsigned int f) {
    if (!resource) {
        CNISCamera* allocated = static_cast<CNISCamera*>(thunk_FUN_0008d690(0x178));
        resource = allocated ? ((CNISCamera_nv_990d0*)(((CNISCamera*)(allocated))))->FUN_000ac3c0() : 0;
        resource->vfunc_0();
        resource->vfunc_28();
    }
    ((owners::Thing_a90f0 *)(((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))))->FUN_000a90f0(0, (int)a);
    ((owners::C_a9130 *)(((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))))->FUN_000a9130(0, (int)b);
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a9110(0, c);
    ((owners::Thing_a90f0 *)(((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))))->FUN_000a90f0(1, (int)d);
    ((owners::C_a9130 *)(((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))))->FUN_000a9130(1, (int)e);
    ((CNISCamera_nv_990d0*)(((CNISCamera*)(resource))))->FUN_000a9110(1, f);
}


// 0x00099180 FUN_00099180 (21 B): matches/0x00099180.cpp
// sym: ?FUN_00099180@fn_f5ef2b3f@@YIHPAUC_99180@1@@Z
hulk_intptr __fastcall FUN_00099180(C_99180* p) {
    unsigned int v = p->flags >> 5;
    if ((unsigned char)v & 1)
        return p->b;
    return p->a;
}


// 0x000991b0 FUN_000991b0 (350 B): equivalent/0x000991b0.cpp
// sym: ?FUN_000991b0@Controller_991b0@fn_f5ef2b3f@@QAEXPAUOwner_991b0@2@PAVNode@2@1_N2@Z
// STATUS: equivalent (tools/equiv.py level 3: 20025 inputs, branch coverage 24/24)
// FUN_000991b0 @ 0x000991b0
void Controller_991b0::FUN_000991b0(Owner_991b0 *owner, Node *node, Node *tgt, bool arg4, bool arg5)
{
    int out1, out2;
    Vec3_991b0 v;

    if (node == tgt || !tgt)
        return;

    if (arg4) {
        Mgr_991b0 *mgr = owner->level->mgr;
        if (mgr) {
            Target_991b0 *cur = mgr->sel->FUN_000fdc30();
            if (cur) {
                node->v6(&out1, &out2);
                float f = node->v8();
                cur->FUN_000fd8a0(owner, node->v14(), out1, f);
            }
        }
    }

    v.FUN_000a9050();
    if (node) {
        Vec3_991b0 *p = FUN_000a9170(node, tgt);
        v = *p;
        if (!arg5 && v.x != 0) {
            int fl = flags | 0x20;
            CBlendCamera_991b0 *h = helper;
            flags = fl;
            if (!h) {
                CBlendCamera_991b0 *mem = (CBlendCamera_991b0 *)FUN_00263ea0(0x1b8);
                if (mem)
                    h = mem->FUN_000983d0();
                else
                    h = 0;
                helper = h;
                h->v0();
                helper->v28();
            }
            if (!helper->FUN_000989d0(owner, node, 0, tgt)) {
                helper->FUN_00098480(owner);
                flags &= ~0x20;
            }
        } else {
            if (arg5)
                v.x = 0;
            if (helper)
                helper->FUN_00098480(owner);
            flags &= ~0x20;
            node->v31(owner);
        }
    }
    target = tgt;
    tgt->v30(owner);
}


// 0x00099310 FUN_00099310 (11 B): matches/0x00099310.cpp
// sym: ?FUN_00099310@fn_f5ef2b3f@@YIXPAVOuter_99310@1@@Z
void __fastcall FUN_00099310(Outer_99310* p) {
    p->p->f36();
}


// 0x00099320 FUN_00099320 (11 B): matches/0x00099320.cpp
// sym: ?target@B_99320@fn_f5ef2b3f@@QAEXHMMM@Z
void B_99320::target(int mode, float a, float b, float c) {
    p->f37(mode, a, b, c);
}


// 0x00099330 FUN_00099330 (11 B): matches/0x00099330.cpp
// sym: ?target@Obj_99330@fn_f5ef2b3f@@QAEXXZ
void Obj_99330::target() {
    m->f37();
}


// 0x00099340 FUN_00099340 (162 B): equivalent/0x00099340.cpp
// sym: ?FUN_00099340@Panel_99340@fn_f5ef2b3f@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 4/4)
// FUN_00099340 @ 0x00099340
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
void Panel_99340::FUN_00099340()
{
    if (range == 0) {
        CScriptCamera *r = (CScriptCamera *)thunk_FUN_0008d690((int)sizeof(CScriptCamera));
        if (r != 0)
            r = ((CScriptCamera_nv_99340*)(((CScriptCamera*)(r))))->FUN_000ac7d0();
        range = r;
        r->vfunc_0();
        range->vfunc_28();
    }
    ((owners::Thing_a90f0 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a90f0(0, 0);
    ((owners::C_a9130 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9130(0, 0);
    ((owners::C_a9110 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9110(0, 1.0f);
    ((owners::Thing_a90f0 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a90f0(1, 0);
    ((owners::C_a9130 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9130(1, 0);
    ((owners::C_a9110 *)(((CScriptCamera_nv_99340*)(((CScriptCamera*)(range))))))->FUN_000a9110(1, 1.0f);
}


// 0x000993f0 FUN_000993f0 (119 B): matches/0x000993f0.cpp
// sym: ?FUN_000993f0@Panel_993f0@fn_f5ef2b3f@@QAEXHHHHHH@Z
// FUN_000993f0 @ 0x000993f0
void Panel_993f0::FUN_000993f0(int a1, int a2, int a3, int a4, int a5, int a6) {
    ((owners::Thing_a90f0 *)range)->FUN_000a90f0(0, a1 - 1);
    ((owners::C_a9130 *)range)->FUN_000a9130(0, a2 - 1);
    range->FUN_000a9110(0, a3);
    ((owners::Thing_a90f0 *)range)->FUN_000a90f0(1, a4 - 1);
    ((owners::C_a9130 *)range)->FUN_000a9130(1, a5 - 1);
    range->FUN_000a9110(1, a6);
}


// 0x00099470 FUN_00099470 (144 B): equivalent/0x00099470.cpp
// sym: ?FUN_00099470@Handler_99470@fn_f5ef2b3f@@QAEXPAUCtx_99470@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 6/6)
// FUN_00099470 @ 0x00099470
void Handler_99470::FUN_00099470(Ctx_99470 *ctx)
{
    if ((flags >> 4 & 1) == 0)
        return;
    flags &= ~0x10u;
    ((owners::Thing_86100 *)(holder->FUN_00086320()))->FUN_00086100(1.0f);
    if (!FUN_001c3d90()->FUN_001c3cb0())
        ctx->status->flag = 1;
    Anim_99470 *a = ctx->actor->anim;
    if (a != 0) {
        a->FUN_000361c0(0);
        a->FUN_00036140(0);
    }
    FUN_000991b0(ctx, arg0, arg1, 0, 0);
    target->scale = 1.5f;
}


// 0x00099500 FUN_00099500 (97 B): matches/0x00099500.cpp
// sym: ?f@C_99500@fn_f5ef2b3f@@QAEXHHHHHH@Z
void C_99500::f(int a, int b, int c, int d, int e, int g) {
    m->a1e4 = a;
    m->a1ac = b;
    Inner_99500* i = m;
    i->a288 = c;
    i->a28c = d;
    i->a290 = e;
    i->a21c = 0;
    m->a174 = g;
}


// 0x00099570 FUN_00099570 (78 B): equivalent/0x00099570.cpp
// sym: ?FUN_00099570@Object@fn_f5ef2b3f@@QAEXHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00099570 @ 0x00099570
void Object::FUN_00099570(int a,int b,int c,int d,int e,int f) { Triple t; t.a=c; t.b=d; t.c=e; FUN_00099500(a,b,t,f); }

} // namespace fn_f5ef2b3f

// 0x000995c0 FUN_000995c0 (51 B): matches/0x000995c0.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_000995c0@@QAEXHHD@Z
namespace fn_000995c0 {
struct Data {
    char a[0x254];
    int x;
    char b[0x70];
    int y;
    char flag;
};
class Obj {
    char a[0xc4];
    Data* d;

  public:
    void Set(int x, int y, char flag);
};
void Obj::Set(int x, int y, char flag) {
    d->x = x;
    d->y = y;
    d->flag = flag;
}
} // namespace fn_000995c0

namespace fn_f5ef2b3f {

// 0x00099600 FUN_00099600 (51 B): matches/0x00099600.cpp
// sym: ?Fn@Obj@fn_f5ef2b3f@@QAEXHH@Z
void Obj::Fn(int a, int b) {
    Sub* q = (Sub*)((char*)p + 0x170);
    ((owners::Target_ac780 *)q)->FUN_000ac780(a);
    q = (Sub*)((char*)p + 0x170);
    ((owners::Target_ac790 *)q)->FUN_000ac790(b);
}

} // namespace fn_f5ef2b3f

// 0x00099640 FUN_00099640 (51 B): matches/0x00099640.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_00099640@@QAEXHH@Z
namespace fn_00099640 {
struct Part {
};
struct Obj {
    char pad[0xc4];
    struct Holder {
        char pad[0x1a8];
        Part part;
    }* holder;
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    ((owners::Target_ac780 *)&(holder->part))->FUN_000ac780(a);
    ((owners::Target_ac790 *)&(holder->part))->FUN_000ac790(b);
}
} // namespace fn_00099640


// 0x00099680 FUN_00099680 (51 B): matches/0x00099680.cpp [wrapped: same definition as 0x00099600 in this TU]
// sym: ?Fn@Obj@fn_00099680@@QAEXHH@Z
namespace fn_00099680 {
class Sub {
  public:
};
class Owner {
    char pad[0x1e0];

  public:
    Sub sub;
};
class Obj {
    char pad[0xc4];
    Owner* m;

  public:
    void Fn(int a, int b);
};
void Obj::Fn(int a, int b) {
    ((owners::Target_ac780 *)&(m->sub))->FUN_000ac780(a);
    ((owners::Target_ac790 *)&(m->sub))->FUN_000ac790(b);
}
} // namespace fn_00099680


// 0x000996c0 FUN_000996c0 (67 B): matches/0x000996c0.cpp [wrapped: same definition as 0x00099000 in this TU]
// sym: ?Set@Obj@fn_000996c0@@QAEXHHHH@Z
namespace fn_000996c0 {
struct Data {
    char pad[0x2b0];
    int a, b, c, d;
};
class Obj {
    char pad[0xc4];
    Data* data;

  public:
    void Set(int a, int b, int c, int d);
};
void Obj::Set(int a, int b, int c, int d) {
    data->a = a;
    data->b = b;
    data->c = c;
    data->d = d;
}
} // namespace fn_000996c0


// 0x00099710 FUN_00099710 (23 B): equivalent/0x00099710.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_00099710@Object@fn_00099710@@QAEXXZ
namespace fn_00099710 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00099710 @ 0x00099710
struct Object { char pad[4]; unsigned flags; void FUN_00099710(); void FUN_00099470(unsigned); }; 
#define DAT_004dd700 (*(unsigned *)&::DAT_004dd700)
 void Object::FUN_00099710() { if (flags & 0x10) FUN_00099470(DAT_004dd700); }
} // namespace fn_00099710
#undef DAT_004dd700

namespace fn_f5ef2b3f {

// 0x00099730 FUN_00099730 (9 B): matches/0x00099730.cpp
// sym: @FUN_00099730@4
extern "C" unsigned int __fastcall FUN_00099730(C_99730* p) {
    return (p->m >> 1) & 1;
}


// 0x00099740 FUN_00099740 (10 B): matches/0x00099740.cpp
// sym: @FUN_00099740@4
extern "C" unsigned int __fastcall FUN_00099740(A_99740* self) {
    return (self->value >> 2) & 1;
}


// 0x00099750 FUN_00099750 (10 B): matches/0x00099750.cpp
// sym: @FUN_00099750@4
extern "C" unsigned int __fastcall FUN_00099750(C_99750* p) {
    return (p->x >> 4) & 1;
}


// 0x00099760 FUN_00099760 (44 B): matches/0x00099760.cpp
// sym: ?FUN_00099760@Object@fn_f5ef2b3f@@QAEHXZ
int Object::FUN_00099760() {
    unsigned char f = (unsigned char)(flags >> 4);
    if ((f & 1) && value == other && !other->FUN_000aca40(0))
        return 1;
    return 0;
}


// 0x00099790 FUN_00099790 (10 B): matches/0x00099790.cpp
// sym: @FUN_00099790@4
extern "C" unsigned int __fastcall FUN_00099790(A_99790* a) {
    return (a->x >> 3) & 1;
}


// 0x000997a0 FUN_000997a0 (11 B): matches/0x000997a0.cpp
// sym: @FUN_000997a0@4
extern "C" int __fastcall FUN_000997a0(Obj_997a0* p) {
    return (p->value & 0x5e) == 0;
}

} // namespace fn_f5ef2b3f

// 0x000997b0 FUN_000997b0 (35 B): matches/0x000997b0.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_000997b0@@QAEXHH@Z
namespace fn_000997b0 {
class Obj {
  public:
    char pad[0xc4];
    void* m;
    void Set(int a, int b);
};

void Obj::Set(int a, int b) {
    *(int*)((char*)m + 0x1b0) = a;
    *(int*)((char*)m + 0x1b4) = b;
}
} // namespace fn_000997b0

namespace fn_f5ef2b3f {

// 0x000997e0 FUN_000997e0 (35 B): matches/0x000997e0.cpp
// sym: ?Set@Obj@fn_f5ef2b3f@@QAEXHH@Z
void Obj::Set(int x, int y) {
    sub->a = x;
    sub->b = y;
}

} // namespace fn_f5ef2b3f

// 0x00099810 FUN_00099810 (35 B): matches/0x00099810.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_00099810@@QAEXHH@Z
namespace fn_00099810 {
struct Inner {
    char pad[0x178];
    int a;
    int b;
};
class Obj {
  public:
    char pad[0xc4];
    Inner* m;
    void Set(int a, int b);
};
void Obj::Set(int a, int b) {
    m->a = a;
    m->b = b;
}
} // namespace fn_00099810

namespace fn_f5ef2b3f {

// 0x00099840 FUN_00099840 (19 B): matches/0x00099840.cpp
// sym: ?Set@Thing@fn_f5ef2b3f@@QAEXH@Z
void Thing::Set(int v) {
    inner->value = v;
}


// 0x00099860 FUN_00099860 (17 B): matches/0x00099860.cpp
// sym: ?Target@Obj_99860@fn_f5ef2b3f@@QAEXHH@Z
void Obj_99860::Target(int a0, int a1) {
    ((char*)sub + 0x170);
    ((Sub_99860*)((char*)sub + 0x170))->Fn(a0, a1);
}


// 0x00099880 FUN_00099880 (17 B): matches/0x00099880.cpp
// sym: ?Run@Obj_99880@fn_f5ef2b3f@@QAEXHH@Z
void Obj_99880::Run(int a0, int a1) {
    ((Sub_99880*)((char*)m + 0x1e0))->Fn(a0, a1);
}


// 0x000998a0 FUN_000998a0 (17 B): matches/0x000998a0.cpp
// sym: ?Fn@Obj_998a0@fn_f5ef2b3f@@QAEXHH@Z
void Obj_998a0::Fn(int a0, int a1) {
    ((char*)mSub + 0x1a8);
    ((Sub_998a0*)((char*)mSub + 0x1a8))->Fn(a0, a1);
}


// 0x000998c0 FUN_000998c0 (35 B): matches/0x000998c0.cpp
// sym: ?Set@Target@fn_f5ef2b3f@@QAEXHH@Z
void Target::Set(int a, int b) {
    m->a = a;
    m->b = b;
}


// 0x000998f0 FUN_000998f0 (108 B): equivalent/0x000998f0.cpp
// sym: ?FUN_000998f0@Target_998f0@fn_f5ef2b3f@@QAEXHHHHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2981 inputs, branch coverage 0/0)
// FUN_000998f0 @ 0x000998f0
void Target_998f0::FUN_000998f0(int a1, int a2, int a3, int a4, int a5, int a6)
{
    obj->i288 = a1;
    obj->i290 = a3;
    obj->i28c = a2;
    ((owners::Target_ac780 *)&(obj->sub))->FUN_000ac780(0);
    obj->i294 = a4;
    obj->i298 = a5;
    obj->i29c = a6;
    obj->sub.FUN_000ac790(1.0f);
}


// 0x00099960 FUN_00099960 (17 B): matches/0x00099960.cpp
// sym: ?Fn@Obj_99960@fn_f5ef2b3f@@QAEXHH@Z
void Obj_99960::Fn(int a0, int a1) {
    Sub_99960* p = m;
    p = (Sub_99960*)((char*)p + 0x218);
    p->Fn(a0, a1);
}

} // namespace fn_f5ef2b3f

// 0x000999b0 FUN_000999b0 (51 B): matches/0x000999b0.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_000999b0@@QAEXMM@Z
namespace fn_000999b0 {
class Elem {
  public:
    void A(float);
    void B(float);
};
class Obj {
    char pad[0xc4];
    Elem* p;

  public:
    void Fn(float a, float b);
};
void Obj::Fn(float a, float b) {
    ((Elem*)((char*)p + 0x250))->A(a);
    ((Elem*)((char*)p + 0x250))->B(b);
}
} // namespace fn_000999b0

namespace fn_f5ef2b3f {

// 0x000999f0 FUN_000999f0 (17 B): matches/0x000999f0.cpp
// sym: ?Target@T_999f0@fn_f5ef2b3f@@QAEXHH@Z
void T_999f0::Target(int a0, int a1) {
    ((Obj_999f0*)((char*)p + 0x250))->G(a0, a1);
}


// 0x00099a10 FUN_00099a10 (11 B): matches/0x00099a10.cpp
// sym: ?Fn@Obj_99a10@fn_f5ef2b3f@@QAEXXZ
void Obj_99a10::Fn() {
    m->a7();
}


// 0x00099a20 FUN_00099a20 (11 B): matches/0x00099a20.cpp
// sym: ?Target@Owner_99a20@fn_f5ef2b3f@@QAEXXZ
void Owner_99a20::Target() {
    mSub->Vfunc9();
}


// 0x00099a30 FUN_00099a30 (19 B): matches/0x00099a30.cpp
// sym: ?Set@Obj_99a30@fn_f5ef2b3f@@QAEXE@Z
void Obj_99a30::Set(unsigned char v) {
    ptr[0x2cd] = v;
}

} // namespace fn_f5ef2b3f

// 0x00099a50 FUN_00099a50 (30 B): matches/0x00099a50.cpp [wrapped: conflict: Obj]
// sym: ?Fn@Obj@fn_00099a50@@QAEXH@Z
namespace fn_00099a50 {
class Inner {
  public:
    void Work(void*, int);
};
class Obj {
  public:
    char pad[0xb8];
    Inner* p;
    void Fn(int x);
};
extern void* global;
void Obj::Fn(int x) {
    if (p)
        p->Work(global, x);
}
} // namespace fn_00099a50

namespace fn_f5ef2b3f {

// 0x00099a70 FUN_00099a70 (37 B): matches/0x00099a70.cpp
// sym: ?Fun@Host@fn_f5ef2b3f@@QAEPAMXZ
// data: gZero = DAT_003f335c
float* Host::Fun() {
    float* p = ((float*)&DAT_003f335c);
    Item* x = item;
    if (x) {
        Result* r = ((Result *)((owners::C_a0b70 *)x)->FUN_000a0b70());
        if (r)
            p = r->Value();
    }
    return p;
}


// 0x00099aa0 FUN_00099aa0 (52 B): matches/0x00099aa0.cpp
// sym: ?f@Obj_99aa0@fn_f5ef2b3f@@QAEXH@Z
void Obj_99aa0::f(hulk_intptr x) {
    if (member != 0) {
        int v = ((int)((owners::C_a0b70 *)member)->FUN_000a0b70());
        if (v != 0 && x == v)
            member->run(gValue_99aa0, x);
    }
}


// 0x00099ae0 FUN_00099ae0 (18 B): matches/0x00099ae0.cpp
// sym: ?Fn@Obj_99ae0@fn_f5ef2b3f@@QAEXM@Z
void Obj_99ae0::Fn(float f) {
    if (m)
        m->Run(f);
}

} // namespace fn_f5ef2b3f

// 0x00099b00 FUN_00099b00 (48 B): matches/0x00099b00.cpp [wrapped: lost its match in the tree (codegen differs (10 of 16 instructions))]
// sym: ?F@A@fn_00099b00@@QAEXUV@2@H@Z
namespace fn_00099b00 {
struct V {
    int x, y, z;
};
class A {
    char pad[0xb8];

  public:
    class B* b;
    void F(V v, int n);
};
class B {
  public:
    void G(V v, int n);
};
void A::F(V v, int n) {
    if (b)
        b->G(v, n);
}
} // namespace fn_00099b00

namespace fn_f5ef2b3f {

// 0x00099b30 FUN_00099b30 (22 B): matches/0x00099b30.cpp
// sym: ?Get@Owner@fn_f5ef2b3f@@QAEMXZ
float Owner::Get() {
    if (thing)
        return thing->Get();
    return -1.0f;
}


// 0x00099b50 FUN_00099b50 (22 B): matches/0x00099b50.cpp
// sym: ?Get@Obj_99b50@fn_f5ef2b3f@@QAEMXZ
float Obj_99b50::Get() {
    Sub_99b50* q = p;
    if (q)
        return q->Get();
    return -1.0f;
}


// 0x00099b70 FUN_00099b70 (22 B): matches/0x00099b70.cpp
// sym: @FUN_00099b70@4
extern "C" float __fastcall FUN_00099b70(Obj_99b70* self) {
    if (self->value)
        return self->value->f();
    return gMinusOne_99b70;
}


// 0x00099b90 FUN_00099b90 (18 B): matches/0x00099b90.cpp
// sym: ?Fn@Obj_99b90@fn_f5ef2b3f@@QAEXH@Z
void Obj_99b90::Fn(int a) {
    if (m)
        ((owners::Thing_a0c10 *)m)->FUN_000a0c10(a);
}


// 0x00099bb0 FUN_00099bb0 (22 B): matches/0x00099bb0.cpp
// sym: ?Fn@Obj_99bb0@fn_f5ef2b3f@@QAEMXZ
// data: gConstant = DAT_003f3388
float Obj_99bb0::Fn() {
    if (mSub)
        return mSub->Fn();
    return DAT_003f3388;
}


// 0x00099bd0 FUN_00099bd0 (18 B): matches/0x00099bd0.cpp
// sym: ?Func@Obj@fn_f5ef2b3f@@QAEXH@Z
void Obj::Func(int x) {
    if (child)
        child->Func(x);
}

} // namespace fn_f5ef2b3f

// 0x00099bf0 FUN_00099bf0 (110 B): equivalent/0x00099bf0.cpp [wrapped: conflict: Node]
// sym: ?FUN_00099bf0@Holder_99bf0@fn_00099bf0@@QAEXPAUVec3i@2@@Z
namespace fn_00099bf0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00099bf0 @ 0x00099bf0
struct Vec3i {
    int x, y, z;
};

struct Placement_99bf0 {
    char pad[0x30];
    Vec3i pos;
};

class Node {
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
    virtual Placement_99bf0 *vfunc_14();
};

struct Holder_99bf0 {
    char pad00[4];
    unsigned int flags;
    char pad08[8];
    Node *local;
    char pad14[0xbc - 0x14];
    Node *remote;
    void FUN_00099bf0(Vec3i *out);
};

void Holder_99bf0::FUN_00099bf0(Vec3i *out)
{
    Vec3i result = { 0, 0, 0 };
    Node *node;
    if ((flags >> 5) & 1)
        node = remote;
    else
        node = local;
    if (node != 0)
        result = node->vfunc_14()->pos;
    *out = result;
}
} // namespace fn_00099bf0

namespace fn_f5ef2b3f {

// 0x00099c60 FUN_00099c60 (19 B): matches/0x00099c60.cpp
// sym: ?Set@Obj_99c60@fn_f5ef2b3f@@QAEXH@Z
void Obj_99c60::Set(int v) {
    sub->value = v;
}

} // namespace fn_f5ef2b3f

// 0x00099c80 FUN_00099c80 (19 B): matches/0x00099c80.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_00099c80@@QAEXH@Z
namespace fn_00099c80 {
class Obj {
  public:
    char pad[0xc4];
    struct Sub {
        char pad[0x260];
        int value;
    }* sub;
    void Set(int x);
};
void Obj::Set(int x) {
    sub->value = x;
}
} // namespace fn_00099c80

namespace fn_f5ef2b3f {

// 0x00099ca0 FUN_00099ca0 (19 B): matches/0x00099ca0.cpp
// sym: ?Set@Obj_99ca0@fn_f5ef2b3f@@QAEXH@Z
void Obj_99ca0::Set(int x) {
    ptr->value = x;
}


// 0x00099cc0 FUN_00099cc0 (19 B): matches/0x00099cc0.cpp
// sym: ?Set@Obj_99cc0@fn_f5ef2b3f@@QAEXH@Z
void Obj_99cc0::Set(int x) {
    sub->value = x;
}


// 0x00099ce0 FUN_00099ce0 (19 B): matches/0x00099ce0.cpp
// sym: ?Set@Obj_99ce0@fn_f5ef2b3f@@QAEXH@Z
void Obj_99ce0::Set(int value) {
    *(int*)((char*)m180 + 0x180) = value;
}


// 0x00099d00 FUN_00099d00 (23 B): matches/0x00099d00.cpp
// sym: ?f@C_99d00@fn_f5ef2b3f@@QAEXHHH@Z
void C_99d00::f(hulk_intptr a, hulk_intptr b, int c) {
    if (p)
        p->target(a, b, c);
}


// 0x00099d20 FUN_00099d20 (23 B): matches/0x00099d20.cpp
// sym: ?FUN_00099d20@fn_f5ef2b3f@@YIHPAVHost_99d20@1@PAXHHHHH@Z
int __fastcall FUN_00099d20(Host_99d20* self, void*, int a, int b, int c, int d, int e) {
    if (self->p)
        return self->p->f34(a, b, c, d, e);
}


// 0x00099d40 FUN_00099d40 (23 B): matches/0x00099d40.cpp
// sym: ?target@A_99d40@fn_f5ef2b3f@@QAEXHHH@Z
void A_99d40::target(int a, int b, int c) {
    if (m)
        m->f38(a, b, c);
}

} // namespace fn_f5ef2b3f

// 0x00099d60 FUN_00099d60 (93 B): matches/0x00099d60.cpp [wrapped: conflict: FUN_001c3d90]
// sym: _FUN_00099d60@20
namespace fn_00099d60 {
typedef unsigned int U_99d60;
typedef unsigned char B;
struct Obj_99d60 {
    int B(U_99d60* p);
};
extern Obj_99d60* __cdecl FUN_001c3d90(void);
extern "C" int __stdcall FUN_00099d60(U_99d60 a, U_99d60 b, U_99d60 c, U_99d60 d, B flag) {
    U_99d60 x[7];
    x[0] = a;
    x[1] = b;
    x[2] = c;
    x[3] = a;
    x[4] = b;
    x[5] = c;
    x[6] = d;
    Obj_99d60* o = FUN_001c3d90();
    if (flag)
        return ((owners::Thing_1c4050 *)o)->FUN_001c4050((hulk_intptr)(&x[3]));
    return o->B(&x[3]);
}
} // namespace fn_00099d60

// 0x00099ef0 thunk_FUN_001d04a0 (5 B): not yet verified
// 0x0009a060 thunk_FUN_001d04a0 (5 B): not yet verified

// 0x0009a070 CCameraManager::vfunc_0 (31 B): matches/0x0009a070.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0009a070@@UAEPAV123@E@Z
namespace fn_0009a070 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0009a070

namespace fn_f5ef2b3f {

// 0x0009a090 FUN_0009a090 (70 B): matches/0x0009a090.cpp
// sym: ?Run@Owner_9a090@fn_f5ef2b3f@@QAEXXZ
void Owner_9a090::Run() {
    Prep();
    void* m = Alloc(0x4c0);
    item = m ? Construct(m) : 0;
    item->F0();
    item->F28();
    other = item;
}


// 0x0009a0e0 FUN_0009a0e0 (253 B): matches/0x0009a0e0.cpp
// sym: ?FUN_0009a0e0@Owner_9a0e0@fn_f5ef2b3f@@QAEHXZ
int Owner_9a0e0::FUN_0009a0e0() {
    if (rB8) {
        rB8->release();
        rB8 = 0;
    }
    if (rB0) {
        rB0->release();
        rB0 = 0;
    }
    if (rB4) {
        rB4->release();
        rB4 = 0;
    }
    if (rBC) {
        rBC->release();
        rBC = 0;
    }
    if (rC0) {
        rC0->release();
        rC0 = 0;
    }
    if (rC4) {
        rC4->release();
        rC4 = 0;
    }
    for (int i = 0; i < count1; ++i) {
        if (resources1[i]) {
            resources1[i]->release();
            resources1[i] = 0;
        }
    }
    int n = count2;
    count1 = 0;
    for (int j = 0; j < n; ++j) {
        if (resources2[j]) {
            resources2[j]->release();
            resources2[j] = 0;
        }
        n = count2;
    }
    count2 = 0;
    field10 = 0;
    flag18 = 0;
    field14 = 0;
    field8 = 0;
    state = 1;
    flag19 = 1;
    return 1;
}

} // namespace fn_f5ef2b3f

// 0x0009a1e0 FUN_0009a1e0 (56 B): equivalent/0x0009a1e0.cpp
// sym: ?FUN_0009a1e0@Obj_9a1e0@owners@@QAEXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0009a1e0 @ 0x0009a1e0
void owners::Obj_9a1e0::FUN_0009a1e0(hulk_uintptr arg) { if (flags & 2) { flags &= ~2u; FUN_000991b0(((unsigned)arg), value10, value14, 0, 0); value14 = 0; } }

namespace fn_f5ef2b3f {

// 0x0009a220 FUN_0009a220 (104 B): matches/0x0009a220.cpp
// sym: ?Clear@CCameraManager_9a220@fn_f5ef2b3f@@QAEXXZ
void CCameraManager_9a220::Clear() {
    c = 0;
    b = 0;
    a = 0;
    int n = count;
    int i = 0;
    d = 0;
    f = -1.0f;
    g = 0;
    if (n > 0) {
        do {
            if (items[i]) {
                items[i]->Release();
                items[i] = 0;
            }
            ++i;
        } while (i < count);
    }
    count = 0;
}

} // namespace fn_f5ef2b3f

// 0x0009a290 FUN_0009a290 (357 B): equivalent/0x0009a290.cpp [wrapped: compile error in a shared declaration (C3861)]
// sym: ?FUN_0009a290@CCameraManager_9a290@fn_0009a290@@QAEXPAUCtx_9a290@2@@Z
namespace fn_0009a290 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 10/10)
// FUN_0009a290 @ 0x0009a290


void* FUN_00263ea0(unsigned int size);


struct Matrix {
    char data[0x40];
    Matrix() { FUN_0022b980(); }
    void FUN_0022b980();
};

class __declspec(novtable) CHypnoticCamera_9a290 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    char FUN_000aa450(void* ctx, Matrix* m, void* pos, int a, void* b, int c, int d);
    CHypnoticCamera_9a290* FUN_000ac2c0();
    char body[0x480 - 4];
};

struct Obj1_9a290 {  };
struct Obj2_9a290 { void FUN_001bf860(char a); };
struct Obj5 { void FUN_000afe80(); };
struct Obj4_9a290 { Obj5* FUN_00086330(); };
struct Obj6_9a290 {   };
struct Obj3_9a290 { int FUN_000d6f50(); void FUN_000d7030(int a); };
struct Owner_9a290 {
    Obj1_9a290* FUN_00086320();
    Obj2_9a290* FUN_00086380();
};
struct Flag_9a290 { char pad[8]; char value; };
struct Ctx20_9a290 { char pad[0x124]; Obj6_9a290* obj; };

struct Ctx_9a290 {
    char pad00[4];
    Flag_9a290* flag;
    char pad08[0x18];
    Ctx20_9a290* p20;
    char pad24[0x18];
    Obj3_9a290* p3c;
    char pad40[0x14];
    Obj4_9a290* p54;
};

class CCameraManager_9a290 {
public:
    char pad00[4];
    unsigned int flags;
    char pad08[4];
    Owner_9a290* owner;
    CHypnoticCamera_9a290* slot10;
    CHypnoticCamera_9a290* slot14;
    char pad18[0x68];
    char vec80[0xc];
    float angle;
    int f90;
    int f94;
    int f98;
    int f9c;
    char vecA0[0x14];
    CHypnoticCamera_9a290* emitter;

    void FUN_0009a220();
    void FUN_0009a290(Ctx_9a290* ctx);
};

void CCameraManager_9a290::FUN_0009a290(Ctx_9a290* ctx)
{
    Matrix m;
    if (angle != (*(float*)&DAT_003f32e0))
        ((owners::Mat_22ba70 *)&m)->FUN_0022ba70(angle * (*(float*)&DAT_003f32b8));
    ((owners::Target_22be40 *)&m)->FUN_0022be40((const int *)vec80);
    if (emitter == 0) {
        void* mem = FUN_00263ea0(0x480);
        CHypnoticCamera_9a290* e = 0;
        if (mem)
            e = ((CHypnoticCamera_9a290*)mem)->FUN_000ac2c0();
        emitter = e;
        e->v00();
        emitter->v70();
    }
    Obj6_9a290* obj6 = ctx->p20->obj;
    if (emitter->FUN_000aa450(ctx, &m, vecA0, f9c, obj6, f94, f90)) {
        ((owners::Thing_85f50 *)(owner->FUN_00086320()))->FUN_00085f50(1);
        f98 = ctx->p3c->FUN_000d6f50();
        int bit = f98 & 0x100;
        owner->FUN_00086380()->FUN_001bf860(1);
        ctx->p3c->FUN_000d7030(bit);
        ctx->flag->value = 0;
        ctx->p54->FUN_00086330()->FUN_000afe80();
        if (obj6) {
            ((owners::C_361c0 *)obj6)->FUN_000361c0(1);
            ((owners::C_36140 *)obj6)->FUN_00036140(1);
        }
        CHypnoticCamera_9a290* e = emitter;
        CHypnoticCamera_9a290* old = slot10;
        slot10 = e;
        slot14 = old;
        flags |= 4;
    }
    FUN_0009a220();
}
} // namespace fn_0009a290

namespace fn_f5ef2b3f {

// 0x0009a400 FUN_0009a400 (118 B): equivalent/0x0009a400.cpp
// sym: ?FUN_0009a400@Widget_9a400@fn_f5ef2b3f@@QAEXPAUPlayer_9a400@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20004 inputs, branch coverage 4/4)
// FUN_0009a400 @ 0x0009a400
void Widget_9a400::FUN_0009a400(Player_9a400* p) {
    if (((flags >> 3) & 1) == 0)
        return;
    flags &= 0xfffffff7;
    ((owners::Thing_86100 *)(owner->FUN_00086320()))->FUN_00086100(1.0f);
    scene->FUN_000ac560(0);
    Method0_9a400* camera = p->cast->camera;
    if (camera != 0) {
        camera->FUN_000361c0(0);
        camera->FUN_00036140(0);
    }
    FUN_000991b0(p, f10, f14, 0, 0);
}


// 0x0009a480 FUN_0009a480 (119 B): equivalent/0x0009a480.cpp
// sym: ?FUN_0009a480@Slider_9a480@fn_f5ef2b3f@@QAEXM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 10/10)
// FUN_0009a480 @ 0x0009a480
void Slider_9a480::FUN_0009a480(float v) {
    if (((Provider_9a480 *)((owners::C_86310 *)(DAT_004dd700->root))->FUN_00086310())->state.FUN_00088fa0() != 10 || target == 0)
        return;
    if (v >= 5.0f) {
        if (v > 100.0f)
            v = 100.0f;
    } else {
        v = 5.0f;
    }
    target->FUN_000a0bc0(v);
}

} // namespace fn_f5ef2b3f

// 0x0009a500 FUN_0009a500 (194 B): equivalent/0x0009a500.cpp [wrapped: conflict: World]
// sym: ?target@Object@fn_0009a500@@QAEXMM@Z
namespace fn_0009a500 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 16/16)
// FUN_0009a500 @ 0x0009a500
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

struct Mode_9a500 { int FUN_00088fa0(); };
struct Context { char pad[0x80]; Mode_9a500 mode; };
struct Manager_9a500 {  };
struct World { char pad[0x54]; Manager_9a500* manager; };
struct Receiver_9a500 { void FUN_000a2c60(float,float); };
struct Object { char pad[0xb8]; Receiver_9a500* receiver; void target(float a,float b); };
void Object::target(float a,float b) {
 Context* context=((Context *)((owners::C_86310 *)(DAT_004dd700->manager))->FUN_00086310());
 if(context->mode.FUN_00088fa0()!=10) return;
 Receiver_9a500* r=receiver;
 if(!r) return;
 if(!(a>=30.0f && a<=120.0f)) a=(a>120.0f)?120.0f:30.0f;
 if(!(b>=0.0f && b<=10.0f)) b=(b>10.0f)?10.0f:0.0f;
 r->FUN_000a2c60(a,b);
}
} // namespace fn_0009a500
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009a5d0 FUN_0009a5d0 (258 B): equivalent/0x0009a5d0.cpp [wrapped: conflict: DAT_004dd700; World]
// sym: _FUN_0009a5d0@24
namespace fn_0009a5d0 {
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_0009a5d0 @ 0x0009a5d0
struct Vec_9a5d0 { float x,y,z; };
struct Matrix { float m[16]; void FUN_0022b980();   };
struct World { unsigned char FUN_00201e00(Vec_9a5d0*,Vec_9a5d0*,int,Vec_9a5d0*,Vec_9a5d0*,int,int); };
struct Globals_9a5d0 { char pad[0x24]; World* world; };

#define DAT_004dd700 (*(Globals_9a5d0* *)&::DAT_004dd700)

extern "C" int __stdcall FUN_0009a5d0(float x,float y,float z,float pitch,float yaw,float distance) {
 Vec_9a5d0 start; start.x=x; start.y=y; start.z=z;
 Matrix matrix; matrix.FUN_0022b980();
 ((owners::Matrix_22bc20 *)&matrix)->FUN_0022bc20(yaw*0.0174532924f, pitch*0.0174532924f, 0.0f);
 Vec_9a5d0 direction,forward; forward.x=0;forward.y=0;forward.z=-1.0f;
 ((owners::M_22c3b0 *)&matrix)->FUN_0022c3b0((float *)(Vec_9a5d0 *)(&forward), (float *)(Vec_9a5d0 *)(&direction));
 Vec_9a5d0 end; end.x=start.x+direction.x*distance; end.y=start.y+direction.y*distance; volatile float ez=direction.z*distance; /* the original rounds this product through its frame */ end.z=start.z+ez;
 Vec_9a5d0 out1,out2;
 return DAT_004dd700->world->FUN_00201e00(&end,&start,1,&out1,&out2,0,0)==0;
}
} // namespace fn_0009a5d0
#undef DAT_004dd700

namespace fn_f5ef2b3f {

// 0x0009a6e0 FUN_0009a6e0 (128 B): matches/0x0009a6e0.cpp
// sym: ?Run@Method6_9a6e0@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9a6e0@2@AEXMMMMMM@Z@Z
Method6_9a6e0* Method6_9a6e0::Run(const char* a, Fn_9a6e0 b) {
    Init(a, 6);
    v = (void*)DAT_00404c00;
    m1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009a760 Method6<CCameraManager,void,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x0009a760.cpp
// sym: ??_G?$Method6@VCCameraManager@@XMMMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CCameraManager, void, float, float, float, float, float, float>::~Method6() {}


// 0x0009a780 Method6<CCameraManager,void,float,float,float,float,float,float>::vfunc_2 (30 B): matches/0x0009a780.cpp
// sym: ?vfunc_2@?$Method6@VCCameraManager@@XMMMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CCameraManager, void, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0009a7a0(a, b, c, (*(int *)&this->f_1c));
}

namespace fn_f5ef2b3f {

// 0x0009a7a0 FUN_0009a7a0 (82 B): equivalent/0x0009a7a0.cpp
// sym: ?FUN_0009a7a0@fn_f5ef2b3f@@YAXIPBIIP6GXIIIIII@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009a7a0 @ 0x0009a7a0
void __cdecl FUN_0009a7a0(unsigned unused, const unsigned *values, unsigned unused2, Callback callback)
{
    callback(values[0], values[1], values[2], values[3], values[4], values[5]);
}


// 0x0009a800 FUN_0009a800 (102 B): matches/0x0009a800.cpp
// sym: ??0Method4_9a800@fn_f5ef2b3f@@QAE@PBDP8Owner_9a800@1@AEXMMHM@Z@Z
Method4_9a800::Method4_9a800(const char* a, Fn_9a800 b) : FUN_001d0480(a, 4) {
    *(void**)this = (void*)DAT_00404c10;
    value1c = b;
    f.retType = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((const char*)((hulk_intptr)DAT_0048e10c));
    f.argTypes[3] = FUN_001d04d0((const char*)((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_f5ef2b3f

// 0x0009a870 Method4<CCameraManager,void,float,float,math::Vector,float>::vfunc_0 (30 B): matches/0x0009a870.cpp
// sym: ??_G?$Method4@VCCameraManager@@XMMVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CCameraManager, void, float, float,math::Vector, float>::~Method4() {}


// 0x0009a890 Method4<CCameraManager,void,float,float,math::Vector,float>::vfunc_2 (73 B): equivalent/0x0009a890.cpp
// sym: ?vfunc_2@?$Method4@VCCameraManager@@XMMVVector@math@@M@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,float,float,math::Vector,float>::vfunc_2 @ 0x0009a890
template <> void Method4<CCameraManager, void, float, float,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9a890 * manager = (CCameraManager_9a890 *)__p0; const Args * args = (const Args *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CCameraManager_9a890::**)(float, float, Vector_9a890, float))&this->f_1c))(args->first,args->second,args->direction,args->last);
}

namespace fn_f5ef2b3f {

// 0x0009a8e0 FUN_0009a8e0 (89 B): matches/0x0009a8e0.cpp
// sym: ??0Method3_9a8e0@fn_f5ef2b3f@@QAE@PAXH@Z
Method3_9a8e0::Method3_9a8e0(void* p, hulk_intptr value) {
    Init(p, 3);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00404c20);
    field1c = value;
    b18 = Convert(((char*)&DAT_0048e100));
    b10 = Convert(((char*)&DAT_0048e128));
    b11 = Convert(((char*)&DAT_0048e128));
    b12 = Convert(((char*)&DAT_0048e0e4));
}

} // namespace fn_f5ef2b3f

// 0x0009a940 Method3<CCameraManager,void,float,float,bool>::vfunc_0 (30 B): matches/0x0009a940.cpp
// sym: ??_G?$Method3@VCCameraManager@@XMM_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CCameraManager, void, float, float, bool>::~Method3() {}


// 0x0009a9e0 Method2<CCameraManager,void,float,float>::vfunc_0 (30 B): matches/0x0009a9e0.cpp
// sym: ??_G?$Method2@VCCameraManager@@XMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CCameraManager, void, float, float>::~Method2() {}


// 0x0009aa00 Method2<CCameraManager,void,float,float>::vfunc_2 (23 B): matches/0x0009aa00.cpp
// sym: ?vfunc_2@?$Method2@VCCameraManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CCameraManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_9aa00* m = (CFEManager_9aa00*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_9aa00::**)(const char *, int))&this->f_1c))(s, x);
}


// 0x0009aa20 FUN_0009aa20 (102 B): matches/0x0009aa20.cpp [wrapped: conflict: CCameraManager; Method4]
// sym: ??0?$Method4@VCCameraManager@fn_0009aa20@@XMMMM@fn_0009aa20@@QAE@PBDP8CCameraManager@1@AEXMMMM@Z@Z
namespace fn_0009aa20 {
// FUN_0009aa20 @ 0x0009aa20
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

// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class CCameraManager {};
class Base_9aa20 : public ScriptFunctionFields {
public:
    virtual void v();
    Base_9aa20(const char*, int) throw();
};
template<class C, class R, class A1, class A2, class A3, class A4>
class Method4 : public Base_9aa20 {
public:
    R (C::*f)(A1, A2, A3, A4);
    Method4(const char* n, R (C::*x)(A1, A2, A3, A4));
    virtual void v();
};
template<> Method4<CCameraManager, void, float, float, float, float>::Method4(const char* n, void (CCameraManager::*x)(float, float, float, float)) : Base_9aa20(n, 4) {
    f = x;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e128));
}
} // namespace fn_0009aa20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009aa90 Method4<CCameraManager,void,float,float,float,float>::vfunc_0 (30 B): matches/0x0009aa90.cpp
// sym: ??_G?$Method4@VCCameraManager@@XMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CCameraManager, void, float, float, float, float>::~Method4() {}


// 0x0009aab0 Method4<CCameraManager,void,float,float,float,float>::vfunc_2 (53 B): matches/0x0009aab0.cpp [wrapped: conflict: CCameraManager; Function; Method4]
// sym: ?f2@Method4@fn_0009aab0@@UAEXPAVCCameraManager@2@PAMH@Z
namespace fn_0009aab0 {
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class CCameraManager {
  public:
    void act(float, float, float, float);
};
class Method4 : public Function {
  public:
    virtual void f0();
    virtual void f2(CCameraManager*, float*, int);
    char pad[24];
    typedef void (CCameraManager::*M)(float, float, float, float);
    M method;
};
void Method4::f2(CCameraManager* obj, float* p, int unused) {
    float a = *p++;
    float b = *p++;
    float c = *p++;
    float d = *p++;
    (obj->*method)(a, b, c, d);
}
} // namespace fn_0009aab0

namespace fn_f5ef2b3f {

// 0x0009aaf0 FUN_0009aaf0 (89 B): matches/0x0009aaf0.cpp
// sym: ??0Method3_9aaf0@fn_f5ef2b3f@@QAE@HH@Z
Method3_9aaf0::Method3_9aaf0(hulk_intptr a, hulk_intptr b) {
    Init(a, 3);
    vt = ((hulk_intptr)DAT_00404c50);
    field1c = b;
    b18 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e100)));
    b10 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b11 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    b12 = GetValue((const char*)((hulk_intptr)((char*)&DAT_0048e0e4)));
}

} // namespace fn_f5ef2b3f

// 0x0009ab50 Method3<CCameraManager,void,bool,bool,bool>::vfunc_0 (30 B): matches/0x0009ab50.cpp
// sym: ??_G?$Method3@VCCameraManager@@X_N_N_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method3<CCameraManager, void, bool, bool, bool>::~Method3() {}


// 0x0009ab70 Method3<CCameraManager,void,bool,bool,bool>::vfunc_2 (38 B): equivalent/0x0009ab70.cpp [wrapped: conflict: Method3]
// sym: ?vfunc_2@Method3@fn_0009ab70@@QAEXPAUCCameraManager@2@PBEPAX@Z
namespace fn_0009ab70 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CCameraManager,void,bool,bool,bool>::vfunc_2 @ 0x0009ab70
struct CCameraManager;
struct Method3 {
    char pad[0x1c];
    void (__fastcall *callback)(CCameraManager *, Method3 *, unsigned int, unsigned int, unsigned int);
    void vfunc_2(CCameraManager *camera, const unsigned char *arguments, void *unused);
};
void Method3::vfunc_2(CCameraManager *camera, const unsigned char *arguments, void *unused) {
    unsigned int first = ((hulk_uintptr)arguments & ~255u) | arguments[0];
    callback(camera, this, first, arguments[4], arguments[8]);
}
} // namespace fn_0009ab70

namespace fn_f5ef2b3f {

// 0x0009aba0 FUN_0009aba0 (102 B): matches/0x0009aba0.cpp
// sym: ?Init@Method4_9aba0@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9aba0@2@AEX_N11M@Z@Z
Method4_9aba0* Method4_9aba0::Init(const char* a, Fn_9aba0 p) {
    Function_9aba0::Init(a, 4);
    vf = (void*)DAT_00404c60;
    member1c = p;
    f.retType = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[3] = FUN_001d04d0((const void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009ac10 Method4<CCameraManager,void,bool,bool,bool,float>::vfunc_0 (30 B): matches/0x0009ac10.cpp
// sym: ??_G?$Method4@VCCameraManager@@X_N_N_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CCameraManager, void, bool, bool, bool, float>::~Method4() {}


// 0x0009ac30 Method4<CCameraManager,void,bool,bool,bool,float>::vfunc_2 (54 B): matches/0x0009ac30.cpp [wrapped: conflict: CCameraManager; Function; Method4]
// sym: ?vfunc_2@Method4@fn_0009ac30@@UAEXPAVCCameraManager@2@PAUArg@2@H@Z
namespace fn_0009ac30 {
class CCameraManager {
  public:
    void f();
};
struct Arg {
    bool b;
    char pad[3];
};
union Slot {
    unsigned int u;
    bool b;
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method4 : public Function {
  public:
    virtual void vfunc_2(CCameraManager*, Arg*, int);
    char pad[24];
    typedef void (CCameraManager::*Fn)(unsigned int, unsigned int, unsigned int, float);
    Fn fn;
};
void Method4::vfunc_2(CCameraManager* obj, Arg* p, int) {
    Slot a, b;
    a.b = p->b;
    ++p;
    b.b = p->b;
    ++p;
    (obj->*fn)(a.u, b.u, p->b, *(float*)(p + 1));
}
} // namespace fn_0009ac30


// 0x0009ac70 FUN_0009ac70 (102 B): matches/0x0009ac70.cpp [wrapped: conflict: CCameraManager; Method4]
// sym: ??0?$Method4@VCCameraManager@fn_0009ac70@@X_N_N_N_N@fn_0009ac70@@QAE@PBDP8CCameraManager@1@AEX_N111@Z@Z
namespace fn_0009ac70 {
// FUN_0009ac70 @ 0x0009ac70
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

// Method4's constructor (name, member function): Function's fields (include/decls/data/script.h), then the
// member-function pointer.
class CCameraManager {};
class Base_9ac70 : public ScriptFunctionFields {
public:
    virtual void v();
    Base_9ac70(const char*, int) throw();
};
template<class C, class R, class A1, class A2, class A3, class A4>
class Method4 : public Base_9ac70 {
public:
    R (C::*f)(A1, A2, A3, A4);
    Method4(const char* n, R (C::*x)(A1, A2, A3, A4));
    virtual void v();
};
template<> Method4<CCameraManager, void, bool, bool, bool, bool>::Method4(const char* n, void (CCameraManager::*x)(bool, bool, bool, bool)) : Base_9ac70(n, 4) {
    f = x;
    retType = FUN_001d04d0(((char*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(&DAT_0048e0e4);
    argTypes[1] = FUN_001d04d0(&DAT_0048e0e4);
    argTypes[2] = FUN_001d04d0(&DAT_0048e0e4);
    argTypes[3] = FUN_001d04d0(&DAT_0048e0e4);
}
} // namespace fn_0009ac70
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009ace0 Method4<CCameraManager,void,bool,bool,bool,bool>::vfunc_0 (30 B): matches/0x0009ace0.cpp
// sym: ??_G?$Method4@VCCameraManager@@X_N_N_N_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CCameraManager, void, bool, bool, bool, bool>::~Method4() {}


// 0x0009ad00 Method4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 (56 B): equivalent/0x0009ad00.cpp
// sym: ?vfunc_2@?$Method4@VCCameraManager@@X_N_N_N_N@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 @ 0x0009ad00
template <> void Method4<CCameraManager, void, bool, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9ad00 * manager = (CCameraManager_9ad00 *)__p0; const unsigned char * args = (const unsigned char *)__p1;

    (manager->*(*(void (CCameraManager_9ad00::**)(unsigned int, unsigned int, unsigned int, unsigned int))&this->f_1c))(((hulk_uintptr)this & 0xffffff00u) | args[0],
                         ((hulk_uintptr)args & 0xffffff00u) | args[4],
                         args[8], args[12]);
}

namespace fn_f5ef2b3f {

// 0x0009ad40 FUN_0009ad40 (115 B): matches/0x0009ad40.cpp
// sym: ?Init@Method5_9ad40@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9ad40@2@AEX_N111M@Z@Z
// FUN_0009ad40 @ 0x0009ad40
Method5_9ad40* Method5_9ad40::Init(const char* arg, Fn_9ad40 value) {
    FUN_001d0480(arg, 5);
    vptr = (void*)DAT_00404c80;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009adc0 Method5<CCameraManager,void,bool,bool,bool,bool,float>::vfunc_0 (30 B): matches/0x0009adc0.cpp
// sym: ??_G?$Method5@VCCameraManager@@X_N_N_N_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CCameraManager, void, bool, bool, bool, bool, float>::~Method5() {}


// 0x0009ade0 Method5<CCameraManager,void,bool,bool,bool,bool,float>::vfunc_2 (30 B): matches/0x0009ade0.cpp
// sym: ?vfunc_2@?$Method5@VCCameraManager@@X_N_N_N_NM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method5<CCameraManager, void, bool, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0009ae00(a, b, c, (*(int *)&this->f_1c));
}


// 0x0009ae00 FUN_0009ae00 (69 B): equivalent/0x0009ae00.cpp [wrapped: conflict: Callback]
// sym: ?FUN_0009ae00@fn_0009ae00@@YAXIPBEIP6GXIIIII@Z@Z
namespace fn_0009ae00 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009ae00 @ 0x0009ae00
typedef void (__stdcall *Callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
void __cdecl FUN_0009ae00(unsigned int unused, const unsigned char *data, unsigned int unused2, Callback callback)
{
    unsigned int first = 0x5a5a5a00u | data[0];
    unsigned int second = 0x5a5a5a00u | data[4];
    unsigned int third = ((hulk_uintptr)data & 0xffffff00u) | data[8];
    callback(first, second, third, data[12], *(const unsigned int *)(data + 16));
}
} // namespace fn_0009ae00

namespace fn_f5ef2b3f {

// 0x0009ae50 FUN_0009ae50 (141 B): matches/0x0009ae50.cpp
// sym: ?Init@Method7_9ae50@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9ae50@2@AEX_N11111M@Z@Z
// FUN_0009ae50 @ 0x0009ae50
// Method7 registration constructor: base init, vftable, then the seven result/argument type tags.
Method7_9ae50* Method7_9ae50::Init(const char* name, Fn_9ae50 value) {
    FUN_001d0480(name, 7);
    vptr = (void*)DAT_00404c90;
    owner = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[6] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009aee0 Method7<CCameraManager,void,bool,bool,bool,bool,bool,bool,float>::vfunc_0 (30 B): matches/0x0009aee0.cpp
// sym: ??_G?$Method7@VCCameraManager@@X_N_N_N_N_N_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method7<CCameraManager, void, bool, bool, bool, bool, bool, bool, float>::~Method7() {}


// 0x0009af00 Method7<CCameraManager,void,bool,bool,bool,bool,bool,bool,float>::vfunc_2 (30 B): matches/0x0009af00.cpp
// sym: ?vfunc_2@?$Method7@VCCameraManager@@X_N_N_N_N_N_NM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method7<CCameraManager, void, bool, bool, bool, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0009af20(a, b, c, (*(int *)&this->f_1c));
}

namespace fn_f5ef2b3f {

// 0x0009af20 FUN_0009af20 (98 B): matches/0x0009af20.cpp
// sym: ?f@fn_f5ef2b3f@@YAXPAUObj_9af20@1@PAURec_9af20@1@HP821@AEXUB_9af20@1@2222EH@Z@Z
void f(Obj_9af20* obj, Rec_9af20* r, int unused2, CB cb) {
    B_9af20 a = (r++)->a, b = (r++)->a, c = (r++)->a, d = (r++)->a, e = (r++)->a;
    (obj->*cb)(a, b, c, d, e, r->a.v, *(int*)(r + 1));
}

} // namespace fn_f5ef2b3f

// 0x0009afd0 Method0<CCameraManager,void>::vfunc_0 (30 B): matches/0x0009afd0.cpp
// sym: ??_G?$Method0@VCCameraManager@@X@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CCameraManager, void>::~Method0() {}


// 0x0009aff0 Method0<CCameraManager,void>::vfunc_2 (12 B): matches/0x0009aff0.cpp
// sym: ?vfunc_2@?$Method0@VCCameraManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002d950 (propagated; names are from that function)
template <> void Method0<CCameraManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_9aff0 * a = (CActorManager_9aff0 *)__p0;

    (a->*(*(void (CActorManager_9aff0::**)())&this->f_1c))();
}


// 0x0009b040 Method0<CCameraManager,bool>::vfunc_0 (30 B): matches/0x0009b040.cpp
// sym: ??_G?$Method0@VCCameraManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CCameraManager, bool>::~Method0() {}


// 0x0009b060 Method0<CCameraManager,bool>::vfunc_2 (22 B): matches/0x0009b060.cpp
// sym: ?vfunc_2@?$Method0@VCCameraManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002d750 (propagated; names are from that function)
template <> void Method0<CCameraManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_9b060 * obj = (CActorManager_9b060 *)__p0; void * a = (void *)__p1; unsigned char * out = (unsigned char *)__p2;

    Fn_9b060 fn = (*(Fn_9b060 *)&this->f_1c);
    unsigned char r = fn(obj);
    if (out)
        *out = r;
}

namespace fn_f5ef2b3f {

// 0x0009b080 FUN_0009b080 (128 B): matches/0x0009b080.cpp
// sym: ?Init@Method6_9b080@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9b080@2@AEXHHMHHM@Z@Z
// FUN_0009b080 @ 0x0009b080
// 0x0009b080: Method6 callback object constructor (bool/byte flags from the per-type descriptor words)
Method6_9b080* Method6_9b080::Init(const char* arg, Fn_9b080 value)
{
    FUN_001d0480(arg, 6);
    vptr = (void*)DAT_00404cc0;
    p1c = value;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0048e128));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[4] = FUN_001d04d0(((char*)&DAT_0048e134));
    f.argTypes[5] = FUN_001d04d0(((char*)&DAT_0048e128));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009b100 Method6<CCameraManager,void,int,int,float,int,int,float>::vfunc_0 (30 B): matches/0x0009b100.cpp
// sym: ??_G?$Method6@VCCameraManager@@XHHMHHM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CCameraManager, void, int, int, float, int, int, float>::~Method6() {}


// 0x0009b120 Method6<CCameraManager,void,int,int,float,int,int,float>::vfunc_2 (30 B): matches/0x0009b120.cpp
// sym: ?vfunc_2@?$Method6@VCCameraManager@@XHHMHHM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CCameraManager, void, int, int, float, int, int, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0009b140(a, b, c, (*(int *)&this->f_1c));
}


// 0x0009b140 FUN_0009b140 (58 B): equivalent/0x0009b140.cpp [wrapped: conflict: Callback]
// sym: ?FUN_0009b140@fn_0009b140@@YAXPAUReceiver@1@PAIIP821@AEXIIIIII@Z@Z
namespace fn_0009b140 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0009b140 @ 0x0009b140
struct Receiver {
    void callback(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
typedef void (Receiver::*Callback)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
void __cdecl FUN_0009b140(Receiver *receiver, unsigned *values, unsigned unused, Callback callback)
{
    (receiver->*callback)(values[0], values[1], values[2], values[3], values[4], values[5]);
}
} // namespace fn_0009b140


// 0x0009b1c0 Method1<CCameraManager,void,float>::vfunc_0 (30 B): matches/0x0009b1c0.cpp
// sym: ??_G?$Method1@VCCameraManager@@XM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CCameraManager, void, float>::~Method1() {}


// 0x0009b1e0 Method1<CCameraManager,void,float>::vfunc_2 (19 B): matches/0x0009b1e0.cpp
// sym: ?vfunc_2@?$Method1@VCCameraManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CCameraManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_9b1e0* d = (Dummy_9b1e0*)a;
    (d->*(*(void (Dummy_9b1e0::**)(void *))&this->f_1c))(*b);
}


// 0x0009b250 Method2<CCameraManager,void,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x0009b250.cpp
// sym: ??_G?$Method2@VCCameraManager@@XVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CCameraManager, void,math::Vector,math::Vector>::~Method2() {}


// 0x0009b270 Method2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 (61 B): equivalent/0x0009b270.cpp
// sym: ?vfunc_2@?$Method2@VCCameraManager@@XVVector@math@@V23@@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Method2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 @ 0x0009b270
template <> void Method2<CCameraManager, void,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9b270 * manager = (CCameraManager_9b270 *)__p0; const math::Vector_9b270 * args = (const math::Vector_9b270 *)__p1; void * unused = (void *)__p2;

    (manager->*(*(void (CCameraManager_9b270::**)(math::Vector_9b270, math::Vector_9b270))&this->f_1c))(args[0], args[1]);
}


// 0x0009b2f0 Method1<CCameraManager,void,bool>::vfunc_0 (30 B): matches/0x0009b2f0.cpp
// sym: ??_G?$Method1@VCCameraManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CCameraManager, void, bool>::~Method1() {}


// 0x0009b310 Method1<CCameraManager,void,bool>::vfunc_2 (21 B): matches/0x0009b310.cpp
// sym: ?vfunc_2@?$Method1@VCCameraManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x0002e290 (propagated; names are from that function)
template <> void Method1<CCameraManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_9b310 * obj = (CActorManager_9b310 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_9b310 *)&this->f_1c))(*b);
}

namespace fn_f5ef2b3f {

// 0x0009b330 FUN_0009b330 (102 B): matches/0x0009b330.cpp
// sym: ?Fn@Method4_9b330@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9b330@2@AEXHMMM@Z@Z
Method4_9b330* Method4_9b330::Fn(const char* a, Fn_9b330 b) {
    ((Helper_9b330*)this)->Init(a, 4);
    vtable = (void*)DAT_00404d00;
    m1c = b;
    f.retType = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e100)));
    f.argTypes[0] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e134)));
    f.argTypes[1] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0(((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009b3a0 Method4<CCameraManager,void,int,float,float,float>::vfunc_0 (30 B): matches/0x0009b3a0.cpp
// sym: ??_G?$Method4@VCCameraManager@@XHMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CCameraManager, void, int, float, float, float>::~Method4() {}


// 0x0009b3c0 Method4<CCameraManager,void,int,float,float,float>::vfunc_2 (46 B): equivalent/0x0009b3c0.cpp [wrapped: conflict: Args; CCameraManager; Function; Method4]
// sym: ?vfunc_2@Method4@fn_0009b3c0@@UAEXPAUCCameraManager@2@PAUArgs@2@M@Z
namespace fn_0009b3c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,int,float,float,float>::vfunc_2 @ 0x0009b3c0
struct CCameraManager {};
typedef void (CCameraManager::*CameraMethod)(int, float, float, float);
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Args { int mode; float a, b, c; };
struct Method4 : Function {
    virtual void vfunc_2(CCameraManager *, Args *, float);
    char padding[0x18];
    CameraMethod method;
};
void Method4::vfunc_2(CCameraManager *manager, Args *args, float unused) {
    (manager->*method)(args->mode, args->a, args->b, args->c);
}
} // namespace fn_0009b3c0


// 0x0009b430 Method0<CCameraManager,math::Vector>::vfunc_0 (30 B): matches/0x0009b430.cpp
// sym: ??_G?$Method0@VCCameraManager@@VVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CCameraManager,math::Vector>::~Method0() {}


// 0x0009b450 Method0<CCameraManager,math::Vector>::vfunc_2 (69 B): matches/0x0009b450.cpp
// sym: ?vfunc_2@?$Method0@VCCameraManager@@VVector@math@@@@UAEXPAX00@Z
// Same code shape as 0x0008a610 (propagated; names are from that function)
template <> void Method0<CCameraManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CGameFlowManager_9b450 * mgr = (CGameFlowManager_9b450 *)__p0; Vector_9b450 * out = (Vector_9b450 *)__p2;

    Fn_9b450 fn = (*(Fn_9b450 *)&this->f_1c);
    Vector_9b450 temp;
    volatile Vector_9b450 r;
    Vector_9b450* p = (mgr->*fn)(&temp);
    r.x = p->x;
    r.y = p->y;
    r.z = p->z;
    if (out) {
        out->x = r.x;
        out->y = r.y;
        out->z = r.z;
    }
}

namespace fn_f5ef2b3f {

// 0x0009b4a0 FUN_0009b4a0 (128 B): matches/0x0009b4a0.cpp
// sym: ?Run@Method6_9b4a0@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9b4a0@2@AE_NMMMMMM@Z@Z
Method6_9b4a0* Method6_9b4a0::Run(const char* arg, Fn_9b4a0 value) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(arg, 6);
    vptr = (void*)DAT_00404d20;
    p1c = value;
    f.retType = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e0e4)));
    f.argTypes[0] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[1] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[2] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[3] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[4] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    f.argTypes[5] = FUN_001d04d0((void*)((hulk_intptr)((char*)&DAT_0048e128)));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009b520 Method6<CCameraManager,bool,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x0009b520.cpp
// sym: ??_G?$Method6@VCCameraManager@@_NMMMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method6<CCameraManager, bool, float, float, float, float, float, float>::~Method6() {}


// 0x0009b540 Method6<CCameraManager,bool,float,float,float,float,float,float>::vfunc_2 (30 B): matches/0x0009b540.cpp
// sym: ?vfunc_2@?$Method6@VCCameraManager@@_NMMMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method6<CCameraManager, bool, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0009b560(a, b, c, (*(int *)&this->f_1c));
}

namespace fn_f5ef2b3f {

// 0x0009b560 FUN_0009b560 (104 B): equivalent/0x0009b560.cpp
// sym: ?FUN_0009b560@fn_f5ef2b3f@@YAXPAVTarget_9b560@1@PAHPADI@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0009b560 @ 0x0009b560
void __cdecl FUN_0009b560(Target_9b560* obj, int* args, char* result, unsigned int fnAddr) {
    CallbackBits cb;
    cb.raw = fnAddr;
    char r = (obj->*(cb.fn))(args[0], args[1], args[2], args[3], args[4], args[5]);
    if (result)
        *result = r;
}

} // namespace fn_f5ef2b3f

// 0x0009b610 Method1<CCameraManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0009b610.cpp
// sym: ??_G?$Method1@VCCameraManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CCameraManager, void, const char *>::~Method1() {}


// 0x0009b630 Method1<CCameraManager,void,const_char_*>::vfunc_2 (19 B): matches/0x0009b630.cpp
// sym: ?vfunc_2@?$Method1@VCCameraManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CCameraManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_9b630* d = (Dummy_9b630*)a;
    (d->*(*(void (Dummy_9b630::**)(void *))&this->f_1c))(*b);
}


// 0x0009b690 Method0<CCameraManager,const_char_*>::vfunc_0 (30 B): matches/0x0009b690.cpp
// sym: ??_G?$Method0@VCCameraManager@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CCameraManager, const char *>::~Method0() {}


// 0x0009b6b0 Method0<CCameraManager,const_char_*>::vfunc_2 (22 B): matches/0x0009b6b0.cpp
// sym: ?vfunc_2@?$Method0@VCCameraManager@@PBD@@UAEXPAX00@Z
// Same code shape as 0x0002ceb0 (propagated; names are from that function)
template <> void Method0<CCameraManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void * b = (void *)__p1; unsigned int * out = (unsigned int *)__p2;

    unsigned(__fastcall * p)(void*) = *(unsigned(__fastcall**)(void*))((char*)this + 0x1c);
    unsigned v = p(a);
    if (out)
        *out = v;
}


// 0x0009b720 Method2<CCameraManager,void,math::Vector,bool>::vfunc_0 (30 B): matches/0x0009b720.cpp
// sym: ??_G?$Method2@VCCameraManager@@XVVector@math@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CCameraManager, void,math::Vector, bool>::~Method2() {}


// 0x0009b740 Method2<CCameraManager,void,math::Vector,bool>::vfunc_2 (45 B): matches/0x0009b740.cpp
// sym: ?vfunc_2@?$Method2@VCCameraManager@@XVVector@math@@_N@@UAEXPAX00@Z
template <> void Method2<CCameraManager, void,math::Vector, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; Vector_9b740 * p = (Vector_9b740 *)__p1; hulk_intptr c = (hulk_intptr)__p2;

    ((CCameraManager_9b740*)a->*(*(void (CCameraManager_9b740::**)(Vector_9b740, unsigned char))&this->f_1c))(*p, *((unsigned char*)p + 12));
}

namespace fn_f5ef2b3f {

// 0x0009b770 FUN_0009b770 (115 B): matches/0x0009b770.cpp
// sym: ??0Method5_9b770@fn_f5ef2b3f@@QAE@PBDP8Owner_9b770@1@AE_NMMMM_N@Z@Z
Method5_9b770::Method5_9b770(const char* x, Fn_9b770 y) : FUN_001d0480(x, 5) {
    *(void**)this = &g_vftable_9b770;
    n = y;
    fields.retType = FUN_001d04d0(typeid(bool));
    fields.argTypes[0] = FUN_001d04d0(typeid(float));
    fields.argTypes[1] = FUN_001d04d0(typeid(float));
    fields.argTypes[2] = FUN_001d04d0(typeid(float));
    fields.argTypes[3] = FUN_001d04d0(typeid(float));
    fields.argTypes[4] = FUN_001d04d0(typeid(bool));
}

} // namespace fn_f5ef2b3f

// 0x0009b7f0 Method5<CCameraManager,bool,float,float,float,float,bool>::vfunc_0 (30 B): matches/0x0009b7f0.cpp
// sym: ??_G?$Method5@VCCameraManager@@_NMMMM_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method5<CCameraManager, bool, float, float, float, float, bool>::~Method5() {}


// 0x0009b810 Method5<CCameraManager,bool,float,float,float,float,bool>::vfunc_2 (30 B): matches/0x0009b810.cpp
// sym: ?vfunc_2@?$Method5@VCCameraManager@@_NMMMM_N@@UAEXPAX00@Z
// Same code shape as 0x0002caf0 (propagated; names are from that function)
template <> void Method5<CCameraManager, bool, float, float, float, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { const char * a = (const char *)__p0; const char * b = (const char *)__p1; const char * c = (const char *)__p2;

    FUN_0009b830(a, b, c, (*(int *)&this->f_1c));
}


// 0x0009b830 FUN_0009b830 (92 B): equivalent/0x0009b830.cpp [wrapped: conflict: Callback]
// sym: ?FUN_0009b830@fn_0009b830@@YAXPAUCallback@1@PAUData@1@PAEP821@AEEIIIII@Z@Z
namespace fn_0009b830 {
// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 2/2)
// FUN_0009b830 @ 0x0009b830
struct Callback {
    unsigned char invoke(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
struct Data {
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
    unsigned char tag;
};
void __cdecl FUN_0009b830(Callback* object, Data* data, unsigned char* result, unsigned char (Callback::*callback)(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int))
{
    unsigned int first = data->first;
    unsigned int second = data->second;
    unsigned int third = data->third;
    unsigned int fourth = data->fourth;
    unsigned char tag = data->tag;
    unsigned int taggedPointer = (reinterpret_cast<hulk_uintptr>(data) & 0xffffff00U) | tag;
    unsigned char value = (object->*callback)(first, second, third, fourth, taggedPointer);
    if (result) *result = value;
}
} // namespace fn_0009b830


// 0x0009b8e0 Method2<CCameraManager,void,math::Vector,float>::vfunc_0 (30 B): matches/0x0009b8e0.cpp
// sym: ??_G?$Method2@VCCameraManager@@XVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CCameraManager, void,math::Vector, float>::~Method2() {}


// 0x0009b900 Method2<CCameraManager,void,math::Vector,float>::vfunc_2 (43 B): matches/0x0009b900.cpp [wrapped: conflict: Args; CCameraManager; Function; Method2]
// sym: ?f2@Method2@fn_0009b900@@UAEXPAVCCameraManager@2@PBUArgs@2@H@Z
namespace fn_0009b900 {
namespace math {
struct Vector {
    float x, y, z;
};
} // namespace math
struct Args {
    math::Vector v;
    float f;
};
class CCameraManager {
  public:
    void Action(math::Vector, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(CCameraManager*, const Args*, int);
};
class Method2 : public Function {
  public:
    char pad[0x18];
    void (CCameraManager::*fn)(math::Vector, float);
    virtual void f2(CCameraManager*, const Args*, int);
};
void Method2::f2(CCameraManager* obj, const Args* args, int unused) {
    (obj->*fn)(args->v, args->f);
}
} // namespace fn_0009b900

namespace fn_f5ef2b3f {

// 0x0009b930 FUN_0009b930 (102 B): matches/0x0009b930.cpp
// sym: ?FUN_0009b930@Method4_9b930@fn_f5ef2b3f@@QAEPAV12@PBDP8Owner_9b930@2@AEXHHHH@Z@Z
// FUN_0009b930 @ 0x0009b930
Method4_9b930* Method4_9b930::FUN_0009b930(const char* name, Fn_9b930 fp) {
    ((ThisCall_001d0480*)(this))->FUN_001d0480(name, 4);
    vptr = (void*)DAT_00404d80;
    fn = fp;
    f.retType = FUN_001d04d0(((char*)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((char*)&DAT_0049cad8));
    f.argTypes[1] = FUN_001d04d0(((char*)&DAT_0049cad8));
    f.argTypes[2] = FUN_001d04d0(((char*)&DAT_0049cad8));
    f.argTypes[3] = FUN_001d04d0(((char*)&DAT_0049cad8));
    return this;
}

} // namespace fn_f5ef2b3f

// 0x0009b9a0 Method4<CCameraManager,void,char_*,char_*,char_*,char_*>::vfunc_0 (30 B): matches/0x0009b9a0.cpp
// sym: ??_G?$Method4@VCCameraManager@@XPADPADPADPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method4<CCameraManager, void, char *, char *, char *, char *>::~Method4() {}


// 0x0009b9c0 Method4<CCameraManager,void,char_*,char_*,char_*,char_*>::vfunc_2 (40 B): matches/0x0009b9c0.cpp
// sym: ?vfunc_2@?$Method4@VCCameraManager@@XPADPADPADPAD@@UAEXPAX00@Z
template <> void Method4<CCameraManager, void, char *, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { CCameraManager_9b9c0 * obj = (CCameraManager_9b9c0 *)__p0; char ** args = (char **)__p1;

    char* a = next(args);
    char* b = next(args);
    char* c = next(args);
    char* d = next(args);
    (obj->*(*(void (CCameraManager_9b9c0::**)(char *, char *, char *, char *))&this->f_1c))(a, b, c, d);
}

namespace fn_f5ef2b3f {

// 0x0009b9f0 FUN_0009b9f0 (50 B): matches/0x0009b9f0.cpp
// sym: ??0Method0_9b9f0@fn_f5ef2b3f@@QAE@HH@Z
// data: hulk_at_0048e128 = DAT_0048e128
Method0_9b9f0::Method0_9b9f0(int a, int b) : Function_9b9f0(a, 0) {
    value = b;
    flag = fun2(((hulk_intptr)((char*)&DAT_0048e128)));
}

} // namespace fn_f5ef2b3f

// 0x0009ba30 Method0<CCameraManager,float>::vfunc_0 (30 B): matches/0x0009ba30.cpp
// sym: ??_G?$Method0@VCCameraManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method0<CCameraManager, float>::~Method0() {}


// 0x0009ba50 Method0<CCameraManager,float>::vfunc_2 (34 B): matches/0x0009ba50.cpp [wrapped: conflict: Function]
// sym: ?f2@Method0Base_9ba50@fn_0009ba50@@UAEXPAX0PAM@Z
namespace fn_0009ba50 {
// Same code shape as 0x0002e080 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method0Base_9ba50 : public Function {
  public:
    char pad[0x18];
    float(__fastcall* fn)(void*);
    virtual void f2(void* a, void* b, float* out);
};
void Method0Base_9ba50::f2(void* a, void* b, float* out) {
    float(__fastcall * f)(void*) = fn;
    float value = f(a);
    if (out)
        *out = value;
}
} // namespace fn_0009ba50


// 0x0009bb50 FUN_0009bb50 (270 B): equivalent/0x0009bb50.cpp [wrapped: conflict: FUN_001c3d90]
// sym: ?FUN_0009bb50@CCameraManager_9bb50@fn_0009bb50@@QAEXHH@Z
namespace fn_0009bb50 {
// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 14/14)
// FUN_0009bb50 @ 0x0009bb50
class Camera {
public:
    int FUN_001c3970(int v);
};

class View {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(float *a, float *b);
    virtual void vf7();
    virtual float vf8();
    virtual void vf9();
    virtual float vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual int vf14();
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
    virtual void vf35(int a, int b, int c, int d);
};

class Transition_9bb50 {
public:
    char FUN_00098460(int a);
    View *FUN_00098480(int a);
};

Camera *FUN_001c3d90();

class CCameraManager_9bb50 {
public:
    void FUN_0009bb50(hulk_intptr a, hulk_intptr b);
    void FUN_00098e60();
    void FUN_0009a290(int a);

    char pad0[4];
    unsigned int flags;
    unsigned int state;
    char pad1[4];
    View *current;
    char pad2[4];
    char dirty;
    char pad3[0xb8 - 0x19];
    View *previous;
    Transition_9bb50 *transition;
};

void CCameraManager_9bb50::FUN_0009bb50(hulk_intptr a, hulk_intptr b)
{
    FUN_00098e60();
    View *view;
    dirty = 0;
    if (current == previous && !(flags & 0x60) && state != 0 && ((state >> 2) & 1)) {
        state &= ~4u;
        FUN_0009a290(a);
    }
    if ((flags >> 5) & 1) {
        if (transition->FUN_00098460(a)) {
            flags &= ~0x20u;
            current = transition->FUN_00098480(a);
            view = current;
        } else {
            view = (View *)transition;
        }
    } else {
        view = current;
    }
    view->vf35(a, b, 1, 1);
    if (view != previous)
        previous->vf35(a, b, 0, 0);
    Camera *cam = FUN_001c3d90();
    cam->FUN_001c3970(view->vf14());
    float x, y;
    view->vf6(&x, &y);
    ((owners::Obj_1c38b0 *)cam)->FUN_001c38b0(x, y);
    ((owners::Obj_1c3910 *)cam)->FUN_001c3910(view->vf8(), view->vf10());
}
} // namespace fn_0009bb50

namespace fn_f5ef2b3f {

// 0x0009bc60 FUN_0009bc60 (276 B): equivalent/0x0009bc60.cpp
// sym: ?FUN_0009bc60@Owner_9bc60@fn_f5ef2b3f@@QAEXI@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 22/22)
// FUN_0009bc60 @ 0x0009bc60
void Owner_9bc60::FUN_0009bc60(hulk_uintptr arg) {
 if(flags & 2) { flags &= ~2u; FUN_000991b0(arg,current,pending,0,0); pending=0; }
 if(flags & 4) FUN_00099050(arg);
 if(flags & 8) FUN_0009a400(arg);
 if(flags & 16) FUN_00099470(arg);
 if(part0) part0->FUN_000a91d0(arg);
 if(part1) part1->FUN_000a91d0(arg);
 if(part2) part2->FUN_000a91d0(arg);
 if(part3) part3->FUN_000a91d0(arg);
 if(part4) part4->FUN_000a91d0(arg);
 if(resource) resource->FUN_000a08e0(arg);
 Resource_9bc60* old=current;
 ready=1;
 if(old) { old->deactivate(arg); current=0; }
 current=resource;
 resource->activate(arg);
 FUN_000991b0(arg,current,resource,1,1);
 done=1;
}

} // namespace fn_f5ef2b3f

// 0x0009bd80 FUN_0009bd80 (457 B): equivalent/0x0009bd80.cpp [wrapped: compile error in a shared declaration (C3861)]
// sym: ?FUN_0009bd80@Tracker_9bd80@fn_0009bd80@@QAEHPAUOwner_9bd80@2@PAUMatrix@2@UV3_9bd80@2@H@Z
namespace fn_0009bd80 {
// STATUS: equivalent (tools/equiv.py level 3: 126 inputs, branch coverage 30/32, incomplete)
// FUN_0009bd80 @ 0x0009bd80
void* FUN_00263ea0(unsigned int size);

struct V3_9bd80 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct Releasable_9bd80 {
    virtual void r0();
    virtual void Release();
};

struct Owner2_9bd80 {
    char pad[0x124];
    struct Probe_9bd80* probe;
};

struct Owner_9bd80 {
    char pad[0x20];
    Owner2_9bd80* inner;
};

struct Probe_9bd80 {
    void FUN_000382c0(V3_9bd80* out);
};

struct Owner_9bd80;
struct Handle_9bd80 {
    void FUN_00098480(Owner_9bd80* owner);
};

class CDramaticCamera_9bd80 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void Start();
    char pad[0x1c0 - 4];
    CDramaticCamera_9bd80* FUN_000a8400();
    int FUN_000a89c0(Owner_9bd80* owner, Releasable_9bd80** items, void* data, int count, int arg5, Matrix* m, V3_9bd80* t);
    void FUN_000a84c0(Releasable_9bd80* a, int b, Matrix* m);
};

struct Frame_9bd80 {
    V3_9bd80 local;
    V3_9bd80 tmp;
    Matrix mat;
};

class Tracker_9bd80 {
public:
    char pad00[4];
    unsigned int flags;
    char pad08[8];
    int f10;
    int f14;
    char disabled;
    char enabled;
    char blocked;
    char pad1b;
    int count;
    Releasable_9bd80* items[8];
    int ids[8];
    char data[0x50];
    CDramaticCamera_9bd80* solver;
    char padb4[8];
    Handle_9bd80* handle;
    int FUN_0009bd80(Owner_9bd80* owner, Matrix* m, V3_9bd80 pos, int arg5);
    void FUN_000991b0(Owner_9bd80* owner, int a, CDramaticCamera_9bd80* s, int c, int d);
};

int Tracker_9bd80::FUN_0009bd80(Owner_9bd80* owner, Matrix* m, V3_9bd80 pos, int arg5)
{
    if (blocked != 0)
        return -1;
    Probe_9bd80* probe = owner->inner->probe;
    if (disabled == 0 && count != 0 && probe != 0 && enabled != 0) {
        unsigned int fl = flags;
        if (((fl >> 1) & 1) == 0 && ((fl >> 6) & 1) == 0 && (fl & 0x5e) == 0) {
            if ((fl >> 5) & 1)
                handle->FUN_00098480(owner);
            flags = flags & ~0x20u;
            Frame_9bd80 f;
            ((owners::Mat_22c2b0 *)m)->FUN_0022c2b0((float *)(const V3_9bd80 *)(&pos), (float *)(V3_9bd80 *)(&f.local));
            f.mat = *m;
            f.mat.m[12] = f.local.x;
            f.mat.m[13] = f.local.y;
            f.mat.m[14] = f.local.z;
            probe->FUN_000382c0(&f.tmp);
            if (solver == 0) {
                CDramaticCamera_9bd80* s = (CDramaticCamera_9bd80*)FUN_00263ea0(0x1c0);
                if (s != 0)
                    s = s->FUN_000a8400();
                solver = s;
                s->s0();
                solver->Start();
            }
            int idx = solver->FUN_000a89c0(owner, items, data, count, arg5, &f.mat, &f.tmp);
            if (idx >= 0) {
                f14 = f10;
                flags = flags | 2;
                solver->FUN_000a84c0(items[idx], ids[idx], &f.mat);
                FUN_000991b0(owner, f10, solver, 0, 0);
            }
        }
    }
    for (int i = 0; i < count; i++) {
        if (items[i] != 0) {
            items[i]->Release();
            items[i] = 0;
        }
    }
    count = 0;
    return -1;
}
} // namespace fn_0009bd80

namespace fn_f5ef2b3f {

// 0x0009bf50 FUN_0009bf50 (258 B): equivalent/0x0009bf50.cpp
// sym: ?run@Target_9bf50@fn_f5ef2b3f@@QAEXPAUArg_9bf50@2@PAX@Z
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 20/20)
// FUN_0009bf50 @ 0x0009bf50
void Target_9bf50::run(Arg_9bf50* arg, void* input) {
 if (!input || busy || (flags & 8) || (flags & 64)) return;
 if (flags & 2) ((owners::Obj_9a1e0 *)this)->FUN_0009a1e0((hulk_uintptr)(Arg_9bf50 *)arg);
 if (flags & 0x5e) return;
 if (flags & 32) helper->FUN_00098480(arg);
 flags = (flags & ~32u) | 8;
 saved = value;
 if (!item) {
  CNISCamera* p = (CNISCamera*)FUN_00263ea0(0x178);
  if (p) p = ((CNISCamera_nv_9bf50*)(((CNISCamera*)(p))))->FUN_000ac3c0();
  item = p;
  p->vfunc_0();
  item->vfunc_28();
 }
 ((CNISCamera_nv_9bf50*)(((CNISCamera*)(item))))->FUN_000ac560(input);
 Toggle* toggle = arg->context->toggle;
 if (toggle) { toggle->FUN_000361c0(1); toggle->FUN_00036140(1); }
 FUN_000991b0(arg,value,item,0,0);
}


// 0x0009c060 FUN_0009c060 (258 B): equivalent/0x0009c060.cpp
// sym: ?target@Object@fn_f5ef2b3f@@QAEXPAUInput_9c060@2@IIIIIII@Z
// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 14/14)
// FUN_0009c060 @ 0x0009c060
void Object::target(Input_9c060* input, unsigned a2, unsigned a3, unsigned a4, unsigned a5, unsigned a6, unsigned a7, unsigned a8) {
 if (disabled || (flags & 0x10) || (flags & 0x40)) return;
 if (flags & 2) ((owners::Obj_9a1e0 *)this)->FUN_0009a1e0((hulk_uintptr)(Input_9c060 *)input);
 if (flags & 0x5e) return;
 if (flags & 0x20) helper->FUN_00098480(input);
 previous = current;
 flags &= ~0x20u;
 worker->FUN_000ac9c0(a2,a3,a4,a5,a6,a7);
 lookup->FUN_00086320()->FUN_00086100(a8);
 input->state->active = worker->active;
 Node* node = input->details->node;
 if (node) { node->FUN_000361c0(1); node->FUN_00036140(1); }
 flags |= 0x10;
 FUN_000991b0(input,current,worker,0,0);
}

} // namespace fn_f5ef2b3f

// 0x0009c170 FUN_0009c170 (41 B): matches/0x0009c170.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_0009c170@Wrapper@fn_0009c170@@QAEXHHH@Z
namespace fn_0009c170 {

#define DAT_004dd700 (*(int *)&::DAT_004dd700)

struct Wrapper {
    void FUN_0009c060(int, int, int, int, int, int, int, float);
    void FUN_0009c170(int a, int b, int c);
};
void Wrapper::FUN_0009c170(int a, int b, int c) {
    FUN_0009c060(DAT_004dd700, a, b, c, 0, 0, 0, 1.0f);
}
} // namespace fn_0009c170
#undef DAT_004dd700


// 0x0009c1a0 FUN_0009c1a0 (40 B): matches/0x0009c1a0.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_0009c1a0@Object@fn_0009c1a0@@QAEXHHHH@Z
namespace fn_0009c1a0 {

#define DAT_004dd700 (*(int *)&::DAT_004dd700)

struct Object {
    void FUN_0009c060(int, int, int, int, int, int, int, int);
    void FUN_0009c1a0(int a, int b, int c, int d);
};
void Object::FUN_0009c1a0(int a, int b, int c, int d) {
    FUN_0009c060(DAT_004dd700, a, b, c, 0, 0, 0, d);
}
} // namespace fn_0009c1a0
#undef DAT_004dd700


// 0x0009c1d0 FUN_0009c1d0 (43 B): matches/0x0009c1d0.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_0009c1d0@Context@fn_0009c1d0@@QAEXHHHH@Z
namespace fn_0009c1d0 {

#define DAT_004dd700 (*(int *)&::DAT_004dd700)

struct Context {
    void FUN_0009c060(int, int, int, int, int, int, int, float);
    void FUN_0009c1d0(int a, int b, int c, int d);
};
void Context::FUN_0009c1d0(int a, int b, int c, int d) {
    FUN_0009c060(DAT_004dd700, a, b, c, d, 0, 0, 1.0f);
}
} // namespace fn_0009c1d0
#undef DAT_004dd700


// 0x0009c200 FUN_0009c200 (44 B): matches/0x0009c200.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_0009c200@Object@fn_0009c200@@QAEXHHHHH@Z
namespace fn_0009c200 {

#define DAT_004dd700 (*(int *)&::DAT_004dd700)

struct Object {
    void FUN_0009c060(int, int, int, int, int, int, int, int);
    void FUN_0009c200(int a, int b, int c, int d, int e);
};
void Object::FUN_0009c200(int a, int b, int c, int d, int e) {
    FUN_0009c060(DAT_004dd700, a, b, c, d, 0, 0, e);
}
} // namespace fn_0009c200
#undef DAT_004dd700

namespace fn_f5ef2b3f {

// 0x0009c230 FUN_0009c230 (50 B): matches/0x0009c230.cpp
// sym: ?target@X@fn_f5ef2b3f@@QAEXHHHHHHH@Z
void X::target(int a, int b, int c, int d, int e, int f, int h) {
    callee(g, a, b, c, d, e, f, h);
}

} // namespace fn_f5ef2b3f

// 0x0009c2a0 Closure6<CCameraManager,void,float,float,float,float,float,float>::vfunc_0 (30 B): matches/0x0009c2a0.cpp
// sym: ??_G?$Method4@VCCameraManager@@XMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CCameraManager, void, float, float, float, float, float, float>::~Closure6() {}


// 0x0009c2c0 Closure6<CCameraManager,void,float,float,float,float,float,float>::vfunc_2 (85 B): matches/0x0009c2c0.cpp
// sym: ?vfunc_2@?$Closure6@VCCameraManager@@XMMMMMM@@UAEXPAX00@Z
template <> void Closure6<CCameraManager, void, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { float * p = (float *)__p1;

    volatile float* q = p;
    float a = *q++;
    float b = *q++;
    float c = *q++;
    float d = *q++;
    float e = ((float*)q)[0], f = ((float*)q)[1];
    ((*(CCameraManager_9c2c0 * *)&this->f_20)->*(*(void (CCameraManager_9c2c0::**)(float, float, float, float, float, float))&this->f_1c))(a, b, c, d, e, f);
}


// 0x0009c350 Closure4<CCameraManager,void,float,float,math::Vector,float>::vfunc_0 (30 B): matches/0x0009c350.cpp
// sym: ??_G?$Method3@VCCameraManager@@X_N_N_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CCameraManager, void, float, float,math::Vector, float>::~Closure4() {}


// 0x0009c370 Closure4<CCameraManager,void,float,float,math::Vector,float>::vfunc_2 (72 B): matches/0x0009c370.cpp
// sym: ?vfunc_2@?$Closure4@VCCameraManager@@XMMVVector@math@@M@@UAEXPAX00@Z
template <> void Closure4<CCameraManager, void, float, float,math::Vector, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; float * p = (float *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    float a = *p++;
    float b = *p++;
    math::Vector_9c370 v = *(math::Vector_9c370*)p;
    p += 3;
    float c = *p;
    ((*(CCameraManager_9c370 * *)&this->f_20)->*(*(void (CCameraManager_9c370::**)(float, float, math::Vector_9c370, float))&this->f_1c))(a, b, v, c);
}


// 0x0009c3f0 Closure3<CCameraManager,void,float,float,bool>::vfunc_0 (30 B): matches/0x0009c3f0.cpp
// sym: ??_G?$Method4@VCCameraManager@@X_N_N_NM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CCameraManager, void, float, float, bool>::~Closure3() {}


// 0x0009c410 Closure3<CCameraManager,void,float,float,bool>::vfunc_2 (36 B): matches/0x0009c410.cpp
// sym: ?vfunc_2@?$Closure3@VCCameraManager@@XMM_N@@UAEXPAX00@Z
template <> void Closure3<CCameraManager, void, float, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; CameraArgs * args = (CameraArgs *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    float first = args->first;
    _ReadWriteBarrier();
    ((*(CCameraManager_9c410 * *)&this->f_20)->*(*(void (CCameraManager_9c410::**)(float, float, bool))&this->f_1c))(first, args->second, args->third);
    _ReadWriteBarrier();
}


// 0x0009c440 FUN_0009c440 (89 B): matches/0x0009c440.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_0009c440@@QAE@PBDPAVOwner_9c440@1@P821@AEXMM@Z@Z
namespace fn_0009c440 {
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

typedef unsigned char u8;
// Closure2<Owner, void, float, float>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_9c440 {};
typedef void (Owner_9c440::*Fn_9c440)(float, float);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
class Function_9c440 : public CtorV_001d0480 {
  public:
    Function_9c440(const char* a) : CtorV_001d0480(a, 2) { }
};
class Method2 : public Function_9c440 {
  public:
    virtual void Fn();
    Fn_9c440 p1;
    Owner_9c440* p2;
    Method2(const char* a, Fn_9c440 b) : Function_9c440(a) {
        p1 = b;
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(((int*)&DAT_0048e128));
        argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void Fn();
    Closure2(const char*, Owner_9c440*, Fn_9c440);
};
Closure2::Closure2(const char* a, Owner_9c440* b, Fn_9c440 c) : Method2(a, c) {
    p2 = b;
}
} // namespace fn_0009c440
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009c4a0 Closure2<CCameraManager,void,float,float>::vfunc_0 (30 B): matches/0x0009c4a0.cpp
// sym: ??_G?$Method4@VCCameraManager@@X_N_N_N_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CCameraManager, void, float, float>::~Closure2() {}


// 0x0009c4c0 Closure2<CCameraManager,void,float,float>::vfunc_2 (22 B): matches/0x0009c4c0.cpp
// sym: ?vfunc_2@?$Closure2@VCCameraManager@@XMM@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CCameraManager, void, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_9c4c0 * p = (Pair_9c4c0 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_9c4c0 * *)&this->f_20)->*(*(void (CActorManager_9c4c0::**)(const char *, float))&this->f_1c))(p->s, p->f);
}


// 0x0009c510 Closure4<CCameraManager,void,float,float,float,float>::vfunc_0 (30 B): matches/0x0009c510.cpp
// sym: ??_G?$Method0@VCCameraManager@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CCameraManager, void, float, float, float, float>::~Closure4() {}


// 0x0009c530 Closure4<CCameraManager,void,float,float,float,float>::vfunc_2 (52 B): matches/0x0009c530.cpp [wrapped: conflict: CCameraManager; Closure4; Function; Method4]
// sym: ?vfunc_2@Closure4@fn_0009c530@@UAEXHPAMH@Z
namespace fn_0009c530 {
class CCameraManager {
  public:
    void action(float, float, float, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Method4 : public Function {
  public:
    char pad[24];
};
class Closure4 : public Method4 {
  public:
    typedef void (CCameraManager::*Fn)(float, float, float, float);
    Fn fn;
    CCameraManager* obj;
    virtual void vfunc_2(int, float*, int);
};
void Closure4::vfunc_2(int, float* p, int) {
    float a = *p++;
    float b = *p++;
    float c = *p++;
    float d = *p++;
    (obj->*fn)(a, b, c, d);
}
} // namespace fn_0009c530


// 0x0009c5a0 Closure3<CCameraManager,void,bool,bool,bool>::vfunc_0 (30 B): matches/0x0009c5a0.cpp
// sym: ??_G?$Method6@VCCameraManager@@XHHMHHM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure3<CCameraManager, void, bool, bool, bool>::~Closure3() {}


// 0x0009c5c0 Closure3<CCameraManager,void,bool,bool,bool>::vfunc_2 (37 B): matches/0x0009c5c0.cpp
// sym: ?vfunc_2@?$Closure3@VCCameraManager@@X_N_N_N@@UAEXPAX00@Z
template <> void Closure3<CCameraManager, void, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; P9C5C0_9c5c0 * p = (P9C5C0_9c5c0 *)__p1; void * c = (void *)__p2;

    char t = p->a;
    p->a = t;
    ((*(Mgr_9c5c0 * *)&this->f_20)->*(*(void (Mgr_9c5c0::**)(unsigned char, unsigned char, unsigned char))&this->f_1c))((unsigned char)t, (unsigned char)p->b, (unsigned char)p->c);
}


// 0x0009c620 Closure4<CCameraManager,void,bool,bool,bool,float>::vfunc_0 (30 B): matches/0x0009c620.cpp
// sym: ??_G?$Method2@VCCameraManager@@XVVector@math@@V23@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CCameraManager, void, bool, bool, bool, float>::~Closure4() {}


// 0x0009c640 Closure4<CCameraManager,void,bool,bool,bool,float>::vfunc_2 (53 B): equivalent/0x0009c640.cpp
// sym: ?vfunc_2@?$Closure4@VCCameraManager@@X_N_N_NM@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,bool,bool,bool,float>::vfunc_2 @ 0x0009c640
template <> void Closure4<CCameraManager, void, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused = (hulk_intptr)__p0; Arguments * arguments = (Arguments *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    unsigned int first = (reinterpret_cast<hulk_uintptr>(this) & 0xffffff00u) | arguments->first;
    unsigned int second = (reinterpret_cast<hulk_uintptr>(arguments) & 0xffffff00u) | arguments->second;
    ((*(CCameraManager_9c640 * *)&this->f_20)->*(*(void (CCameraManager_9c640::**)(unsigned int, unsigned int, unsigned int, float))&this->f_1c))(first, second, arguments->third, arguments->fourth);
}


// 0x0009c6b0 Closure4<CCameraManager,void,bool,bool,bool,bool>::vfunc_0 (30 B): matches/0x0009c6b0.cpp
// sym: ??_G?$Method1@VCCameraManager@@X_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CCameraManager, void, bool, bool, bool, bool>::~Closure4() {}


// 0x0009c6d0 Closure4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 (55 B): equivalent/0x0009c6d0.cpp
// sym: ?vfunc_2@?$Closure4@VCCameraManager@@X_N_N_N_N@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 @ 0x0009c6d0
template <> void Closure4<CCameraManager, void, bool, bool, bool, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; BoolArguments * args = (BoolArguments *)__p1; void * other = (void *)__p2;

  unsigned first = ((hulk_uintptr)this & 0xffffff00U) | args->first;
  unsigned second = ((hulk_uintptr)args & 0xffffff00U) | args->second;
  ((*(CCameraManager_9c6d0 * *)&this->f_20)->*(*(void (CCameraManager_9c6d0::**)(unsigned int, unsigned int, unsigned int, unsigned int))&this->f_1c))(first, second, args->third, args->fourth);
}


// 0x0009c740 Closure5<CCameraManager,void,bool,bool,bool,bool,float>::vfunc_0 (30 B): matches/0x0009c740.cpp
// sym: ??_G?$Method4@VCCameraManager@@XHMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure5<CCameraManager, void, bool, bool, bool, bool, float>::~Closure5() {}


// 0x0009c7e0 Closure7<CCameraManager,void,bool,bool,bool,bool,bool,bool,float>::vfunc_0 (30 B): matches/0x0009c7e0.cpp
// sym: ??_G?$Method0@VCCameraManager@@VVector@math@@@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure7<CCameraManager, void, bool, bool, bool, bool, bool, bool, float>::~Closure7() {}


// 0x0009c800 Closure7<CCameraManager,void,bool,bool,bool,bool,bool,bool,float>::vfunc_2 (29 B): matches/0x0009c800.cpp
// sym: ?vfunc_2@?$Closure7@VCCameraManager@@X_N_N_N_N_N_NM@@UAEXPAX00@Z
// Same code shape as 0x0002ebc0 (propagated; names are from that function)
template <> void Closure7<CCameraManager, void, bool, bool, bool, bool, bool, bool, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}


// 0x0009c860 Closure0<CCameraManager,void>::vfunc_0 (30 B): matches/0x0009c860.cpp
// sym: ??_G?$Method6@VCCameraManager@@_NMMMMMM@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CCameraManager, void>::~Closure0() {}


// 0x0009c880 Closure0<CCameraManager,void>::vfunc_2 (11 B): matches/0x0009c880.cpp
// sym: ?vfunc_2@?$Closure0@VCCameraManager@@X@@UAEXPAX00@Z
// Same code shape as 0x0002f820 (propagated; names are from that function)
template <> void Closure0<CCameraManager, void>::vfunc_2(void* __p0, void* __p1, void* __p2) {
    ((*(CActorManager_9c880 * *)&this->f_20)->*(*(void (CActorManager_9c880::**)())&this->f_1c))();
}


// 0x0009c8d0 Closure0<CCameraManager,bool>::vfunc_0 (30 B): matches/0x0009c8d0.cpp
// sym: ??_G?$Method1@VCCameraManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CCameraManager, bool>::~Closure0() {}


// 0x0009c8f0 Closure0<CCameraManager,bool>::vfunc_2 (23 B): matches/0x0009c8f0.cpp
// sym: ?vfunc_2@?$Closure0@VCCameraManager@@_N@@UAEXPAX00@Z
// Same code shape as 0x0002f6a0 (propagated; names are from that function)
template <> void Closure0<CCameraManager, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * out = (unsigned char *)__p2;

    CActorManager_9c8f0* o = (*(CActorManager_9c8f0 * *)&this->f_20);
    Fn_9c8f0 fn = (*(Fn_9c8f0 *)&this->f_1c);
    unsigned char b = fn(o);
    if (out)
        *out = b;
}


// 0x0009c940 Closure6<CCameraManager,void,int,int,float,int,int,float>::vfunc_0 (30 B): matches/0x0009c940.cpp
// sym: ??_G?$Method0@VCCameraManager@@PBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure6<CCameraManager, void, int, int, float, int, int, float>::~Closure6() {}


// 0x0009c9a0 FUN_0009c9a0 (76 B): matches/0x0009c9a0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0009c9a0@@QAE@PBDPAVOwner_9c9a0@1@P821@AEXM@Z@Z
namespace fn_0009c9a0 {
// Closure1<Owner, R, A1>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_9c9a0 {};
typedef void (Owner_9c9a0::*Fn_9c9a0)(float);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char Check(const void*);
extern char gA[];
extern char gB[];
class Function_9c9a0 : public CtorV_001d0480 {
  public:
    Function_9c9a0(const char* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_9c9a0 {
  public:
    virtual void invoke(float);
    Fn_9c9a0 x;
    Method1(const char* p, Fn_9c9a0 v) : Function_9c9a0(p) {
        x = v;
        retType = Check(gB);
        argTypes[0] = Check(gA);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke(float);
    Owner_9c9a0* y;
    Closure1(const char* p, Owner_9c9a0* w, Fn_9c9a0 v);
};
Closure1::Closure1(const char* p, Owner_9c9a0* w, Fn_9c9a0 v) : Method1(p, v) {
    y = w;
}
} // namespace fn_0009c9a0


// 0x0009c9f0 Closure1<CCameraManager,void,float>::vfunc_0 (30 B): matches/0x0009c9f0.cpp
// sym: ??_G?$Method2@VCCameraManager@@XVVector@math@@_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CCameraManager, void, float>::~Closure1() {}


// 0x0009ca10 Closure1<CCameraManager,void,float>::vfunc_2 (18 B): matches/0x0009ca10.cpp
// sym: ?vfunc_2@?$Closure1@VCCameraManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CCameraManager, void, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_9ca10 * *)&this->f_20)->*(*(void (CActorManager_9ca10::**)(const char *))&this->f_1c))(*b);
}


// 0x0009ca30 FUN_0009ca30 (89 B): matches/0x0009ca30.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Closure2@fn_0009ca30@@QAE@PBDPAVCCameraManager@1@P821@AEXHH@Z@Z
namespace fn_0009ca30 {
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

// Closure2<CCameraManager, void, A1, A1>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class CCameraManager {};
typedef void (CCameraManager::*Fn_9ca30)(int, int);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern int g2;
class Base_9ca30 : public CtorV_001d0480 {
  public:
    Base_9ca30(const char* a) : CtorV_001d0480(a, 2) { }
};
class Closure2_9ca30 : public Base_9ca30 {
  public:
    virtual void invoke();
    Fn_9ca30 mgr;
    Closure2_9ca30(const char*, CCameraManager*, Fn_9ca30);
};
Closure2_9ca30::Closure2_9ca30(const char* a, CCameraManager* p, Fn_9ca30 m) : Base_9ca30(a) {
    mgr = m;
    retType = FUN_001d04d0(((int*)&DAT_0048e100));
    argTypes[0] = FUN_001d04d0(&g2);
    argTypes[1] = FUN_001d04d0(&g2);
}
class Closure2 : public Closure2_9ca30 {
  public:
    CCameraManager* extra;
    Closure2(const char*, CCameraManager*, Fn_9ca30);
    virtual void invoke();
};
Closure2::Closure2(const char* a, CCameraManager* p, Fn_9ca30 m) : Closure2_9ca30(a, p, m) {
    extra = p;
}
} // namespace fn_0009ca30
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009ca90 Closure2<CCameraManager,void,math::Vector,math::Vector>::vfunc_0 (30 B): matches/0x0009ca90.cpp
// sym: ??_G?$Method5@VCCameraManager@@_NMMMM_N@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure2<CCameraManager, void,math::Vector,math::Vector>::~Closure2() {}


// 0x0009cab0 Closure2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 (60 B): equivalent/0x0009cab0.cpp
// sym: ?vfunc_2@?$Closure2@VCCameraManager@@XVVector@math@@V23@@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure2<CCameraManager,void,math::Vector,math::Vector>::vfunc_2 @ 0x0009cab0
template <> void Closure2<CCameraManager, void,math::Vector,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr unused1 = (hulk_intptr)__p0; VectorPair * args = (VectorPair *)__p1; hulk_intptr unused2 = (hulk_intptr)__p2;

    ((*(CCameraManager_9cab0 * *)&this->f_20)->*(*(void (CCameraManager_9cab0::**)(math::Vector_9cab0, math::Vector_9cab0))&this->f_1c))(args->first, args->second);
}


// 0x0009caf0 FUN_0009caf0 (76 B): matches/0x0009caf0.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0009caf0@@QAE@PBDPAVOwner_9caf0@1@P821@AEX_N@Z@Z
namespace fn_0009caf0 {

// Closure1<Owner, void, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method1's member-function pointer and Closure1's object.
class Owner_9caf0 {};
typedef void (Owner_9caf0::*Fn_9caf0)(bool);
struct CtorV_001d0480 : public ScriptFunctionFields {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C++" __declspec(nothrow) unsigned char query(void*);
class Function_9caf0 : public CtorV_001d0480 {
  public:
    Function_9caf0(const char* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_9caf0 {
  public:
    virtual void invoke();
    Fn_9caf0 owner;
    Owner_9caf0* extra;
    Method1(const char* p, Fn_9caf0 o) : Function_9caf0(p) {
        owner = o;
        retType = query(((void**)&DAT_0048e100));
        argTypes[0] = query(((void**)&DAT_0048e0e4));
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    Closure1(const char* p, Owner_9caf0* x, Fn_9caf0 o);
};
Closure1::Closure1(const char* p, Owner_9caf0* x, Fn_9caf0 o) : Method1(p, o) {
    extra = x;
}
} // namespace fn_0009caf0


// 0x0009cb40 Closure1<CCameraManager,void,bool>::vfunc_0 (30 B): matches/0x0009cb40.cpp
// sym: ??_G?$Method2@VCCameraManager@@XVVector@math@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure1<CCameraManager, void, bool>::~Closure1() {}


// 0x0009cb60 Closure1<CCameraManager,void,bool>::vfunc_2 (20 B): matches/0x0009cb60.cpp
// sym: ?vfunc_2@?$Closure1@VCCameraManager@@X_N@@UAEXPAX00@Z
// Same code shape as 0x00030040 (propagated; names are from that function)
template <> void Closure1<CCameraManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { unsigned char * arg = (unsigned char *)__p1;

    ((*(Actor_9cb60 * *)&this->f_20)->*(*(void (Actor_9cb60::**)(unsigned char))&this->f_1c))(*arg);
}


// 0x0009cbb0 Closure4<CCameraManager,void,int,float,float,float>::vfunc_0 (30 B): matches/0x0009cbb0.cpp
// sym: ??_G?$Method4@VCCameraManager@@XPADPADPADPAD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure4<CCameraManager, void, int, float, float, float>::~Closure4() {}


// 0x0009cbd0 Closure4<CCameraManager,void,int,float,float,float>::vfunc_2 (45 B): matches/0x0009cbd0.cpp
// sym: ?vfunc_2@?$Closure4@VCCameraManager@@XHMMM@@UAEXPAX00@Z
template <> void Closure4<CCameraManager, void, int, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * p = (int *)__p1;

    int a = *p++;
    float b = *(float*)p++;
    float c = *(float*)p++;
    float d = *(float*)p++;
    ((*(CCameraManager_9cbd0 * *)&this->f_20)->*(*(void (CCameraManager_9cbd0::**)(int, float, float, float))&this->f_1c))(a, b, c, d);
}


// 0x0009cc00 FUN_0009cc00 (63 B): matches/0x0009cc00.cpp [wrapped: conflict: Check; Closure0; Method0]
// sym: ??0Closure0@fn_0009cc00@@QAE@PAX00@Z
namespace fn_0009cc00 {
extern float gFloat;
extern "C++" __declspec(nothrow) unsigned char __cdecl Check(const float*);
class Function_9cc00 {
  public:
    Function_9cc00(void*, int);
    virtual void Invoke();
};
class Method0 : public Function_9cc00 {
  public:
    Method0(void* p, void* q) : Function_9cc00(p, 0) {
        first = q;
        flag = Check(&gFloat);
    }
    virtual void Invoke();
    char pad[20];
    unsigned char flag;
    char pad2[3];
    void* first;
};
class Closure0 : public Method0 {
  public:
    Closure0(void* p, void* v, void* q);
    virtual void Invoke();
    void* second;
};
Closure0::Closure0(void* p, void* v, void* q) : Method0(p, q) {
    second = v;
}
} // namespace fn_0009cc00


// 0x0009cc40 Closure0<CCameraManager,math::Vector>::vfunc_0 (30 B): matches/0x0009cc40.cpp
// sym: ??_G?$Method0@VCCameraManager@@M@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Closure0<CCameraManager,math::Vector>::~Closure0() {}


// 0x0009cc60 Closure0<CCameraManager,math::Vector>::vfunc_2 (63 B): equivalent/0x0009cc60.cpp
// sym: ?vfunc_2@?$Closure0@VCCameraManager@@VVector@math@@@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure0<CCameraManager,math::Vector>::vfunc_2 @ 0x0009cc60
template <> void Closure0<CCameraManager,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { int unused0 = (int)__p0; int unused1 = (int)__p1; math::Vector_9cc60 * result = (math::Vector_9cc60 *)__p2;

    math::Vector_9cc60 temporary;
    math::Vector_9cc60 *value = ((*(CCameraManager_9cc60 * *)&this->f_20)->*(*(math::Vector_9cc60 *(CCameraManager_9cc60::**)(math::Vector_9cc60 *))&this->f_1c))(&temporary);
    math::Vector_9cc60 copy = *value;
    if (result) *result = copy;
}


// 0x0009ccf0 Closure6<CCameraManager,bool,float,float,float,float,float,float>::vfunc_2 (29 B): matches/0x0009ccf0.cpp
// sym: ?vfunc_2@?$Closure6@VCCameraManager@@_NMMMMMM@@UAEXPAX00@Z
// Same code shape as 0x0002ebc0 (propagated; names are from that function)
template <> void Closure6<CCameraManager, bool, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}


// 0x0009cd10 FUN_0009cd10 (76 B): matches/0x0009cd10.cpp [wrapped: conflict: Closure1; Method1]
// sym: ??0Closure1@fn_0009cd10@@QAE@PBDHH@Z
namespace fn_0009cd10 {
// data: nameA = DAT_0048e100, nameB = DAT_0048e0f0

extern char __cdecl lookup(const char*);
class Function_9cd10 {
  public:
    Function_9cd10(const char*, int);
    virtual void f();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    int p;
};
class Method1 : public Function_9cd10 {
  public:
    Method1(const char* n, int p) : Function_9cd10(n, 1) {
        this->p = p;
        b = lookup(((char*)&DAT_0048e100));
        a = lookup(((char*)&DAT_0048e0f0));
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char*, int, int);
    virtual void f();
    int q;
};
Closure1::Closure1(const char* n, int q, int p) : Method1(n, p) {
    this->q = q;
}
} // namespace fn_0009cd10


// 0x0009cd80 Closure1<CCameraManager,void,const_char_*>::vfunc_2 (18 B): matches/0x0009cd80.cpp
// sym: ?vfunc_2@?$Closure1@VCCameraManager@@XM@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CCameraManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_9cd80 * *)&this->f_20)->*(*(void (CActorManager_9cd80::**)(const char *))&this->f_1c))(*b);
}


// 0x0009ce00 Closure0<CCameraManager,const_char_*>::vfunc_2 (23 B): matches/0x0009ce00.cpp
// sym: ?vfunc_2@?$Closure0@VCCameraManager@@PBD@@UAEXPAX00@Z
// Same code shape as 0x0002ee10 (propagated; names are from that function)
template <> void Closure0<CCameraManager, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { int * out = (int *)__p2;

    CActorManager_9ce00* obj = (*(CActorManager_9ce00 * *)&this->f_20);
    int (CActorManager_9ce00::*fn)() = (*(int (CActorManager_9ce00::**)())&this->f_1c);
    int result = (obj->*fn)();
    if (out)
        *out = result;
}


// 0x0009ce20 FUN_0009ce20 (89 B): matches/0x0009ce20.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_0009ce20@@QAE@PBDPAVOwner_9ce20@1@P821@AEXH_N@Z@Z
namespace fn_0009ce20 {
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

extern int b;
// Closure2<Owner, void, A1, bool>'s constructor (name, object, member function): Function's fields
// (include/decls/data/script.h), then Method2's member-function pointer and Closure2's object.
class Owner_9ce20 {};
typedef void (Owner_9ce20::*Fn_9ce20)(int, bool);
class Function_9ce20 : public ScriptFunctionFields {
  public:
    Function_9ce20(const char*, int) throw();
    virtual void f();
    Fn_9ce20 p;
};
class Method2 : public Function_9ce20 {
  public:
    Method2(const char* arg1, Fn_9ce20 arg3) throw() : Function_9ce20(arg1, 2) {
        p = arg3;
        retType = FUN_001d04d0(((int*)&DAT_0048e100));
        argTypes[0] = FUN_001d04d0(&b);
        argTypes[1] = FUN_001d04d0(((int*)&DAT_0048e0e4));
    }
    virtual void f();
};
class Closure2 : public Method2 {
  public:
    Closure2(const char*, Owner_9ce20*, Fn_9ce20) throw();
    virtual void f();
    Owner_9ce20* q;
};
Closure2::Closure2(const char* arg1, Owner_9ce20* arg2, Fn_9ce20 arg3) throw() : Method2(arg1, arg3) {
    q = arg2;
}
} // namespace fn_0009ce20
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009cea0 Closure2<CCameraManager,void,math::Vector,bool>::vfunc_2 (44 B): matches/0x0009cea0.cpp
// sym: ?vfunc_2@?$Closure2@VCCameraManager@@XVVector@math@@_N@@UAEXPAX00@Z
template <> void Closure2<CCameraManager, void,math::Vector, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { Vector_9cea0 * p = (Vector_9cea0 *)__p1;

    ((*(CCameraManager_9cea0 * *)&this->f_20)->*(*(void (CCameraManager_9cea0::**)(Vector_9cea0, unsigned char))&this->f_1c))(*p, *((unsigned char*)p + 12));
}


// 0x0009cf20 Closure5<CCameraManager,bool,float,float,float,float,bool>::vfunc_2 (29 B): matches/0x0009cf20.cpp
// sym: ?vfunc_2@?$Closure5@VCCameraManager@@_NMMMM_N@@UAEXPAX00@Z
// Same code shape as 0x0002ebc0 (propagated; names are from that function)
template <> void Closure5<CCameraManager, bool, float, float, float, float, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr x = (hulk_intptr)__p0; hulk_intptr y = (hulk_intptr)__p1; hulk_intptr z = (hulk_intptr)__p2;

    invoke(this->f_20, y, z, (*(int *)&this->f_1c));
}


// 0x0009cf40 FUN_0009cf40 (89 B): matches/0x0009cf40.cpp [wrapped: conflict: Closure2; Method2]
// sym: ??0Closure2@fn_0009cf40@@QAE@PAX00@Z
namespace fn_0009cf40 {

extern char gB[];
char __cdecl check(const char*);
class Function_9cf40 {
  public:
    virtual void f();
    Function_9cf40(void*, int);
    char pad[12];
    char b10;
    char b11;
    char pad2[6];
    char b18;
    char pad3[3];
    void* p1;
    void* p2;
};
class Method2 : public Function_9cf40 {
  public:
    virtual void f();
    Method2(void* p, void* c) : Function_9cf40(p, 2) {
        p1 = c;
        b18 = check(((char*)&DAT_0048e100));
        b10 = check(gB);
        b11 = check(((char*)&DAT_0048e128));
    }
};
class Closure2 : public Method2 {
  public:
    virtual void f();
    Closure2(void*, void*, void*);
};
Closure2::Closure2(void* a, void* b, void* c) : Method2(a, c) {
    p2 = b;
}
} // namespace fn_0009cf40


// 0x0009cfc0 Closure2<CCameraManager,void,math::Vector,float>::vfunc_2 (42 B): matches/0x0009cfc0.cpp [wrapped: conflict: Closure2]
// sym: ?vfunc_2@Closure2@fn_0009cfc0@@QAEXPAXPAH0@Z
namespace fn_0009cfc0 {
// Same code shape as 0x0002f4d0 (propagated; names are from that function)
struct Vector {
    int a, b, c;
};
class CActorManager;
class Closure2 {
  public:
    char pad[0x1c];
    void(__fastcall* fn)(CActorManager*, Closure2*, Vector, float);
    CActorManager* object;
    void vfunc_2(void* unused, int* p, void* unused2);
};
void Closure2::vfunc_2(void* unused, int* p, void* unused2) {
    fn(object, this, *(Vector*)p, *(float*)(p + 3));
}
} // namespace fn_0009cfc0


// 0x0009d040 Closure4<CCameraManager,void,char_*,char_*,char_*,char_*>::vfunc_2 (39 B): equivalent/0x0009d040.cpp
// sym: ?vfunc_2@?$Closure4@VCCameraManager@@XPADPADPADPAD@@UAEXPAX00@Z
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure4<CCameraManager,void,char_*,char_*,char_*,char_*>::vfunc_2 @ 0x0009d040
template <> void Closure4<CCameraManager, void, char *, char *, char *, char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { char ** args = (char **)__p1;

    ((*(CCameraManager_9d040 * *)&this->f_20)->*(*(void (CCameraManager_9d040::**)(char *, char *, char *, char *))&this->f_1c))(args[0], args[1], args[2], args[3]);
}


// 0x0009d0d0 Closure0<CCameraManager,float>::vfunc_2 (35 B): matches/0x0009d0d0.cpp
// sym: ?vfunc_2@?$Closure0@VCCameraManager@@M@@UAEXPAX00@Z
// Same code shape as 0x0002fe60 (propagated; names are from that function)
template <> void Closure0<CCameraManager, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    CActorManager_9d0d0* m = (*(CActorManager_9d0d0 * *)&this->f_20);
    Fn_9d0d0 fn = (*(Fn_9d0d0 *)&this->f_1c);
    float v = (m->*fn)();
    if (out)
        *out = v;
}


// 0x0009d100 FUN_0009d100 (169 B): equivalent/0x0009d100.cpp [wrapped: conflict: World; content::LoadInventory::DynamicCaster; pure3d::Animation]
// sym: ?FUN_0009d100@Target_9d100@fn_0009d100@@QAE_NPAUKey_9d100@2@MM@Z
namespace fn_0009d100 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 8/8)
// FUN_0009d100 @ 0x0009d100
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

namespace pure3d { struct Animation { virtual void AddRef(); virtual void Release(); char pad[12]; float duration; float rate; }; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual T* Cast(void*); }; } }
struct Key_9d100 { unsigned low, high; };
struct Inventory_9d100 { virtual void v0(); virtual void v1(); virtual void v2(); virtual pure3d::Animation* Find(content::LoadInventory::DynamicCaster<pure3d::Animation>*, unsigned, unsigned); };
struct Manager_9d100 { Inventory_9d100* FUN_00203d70(); };
struct Subsystem_9d100 { Manager_9d100* FUN_000862a0(); };
struct World { char pad[0x54]; Subsystem_9d100* subsystem; };
struct Target_9d100 { char pad[0x1c]; int count; pure3d::Animation* animations[8]; float scales[8]; float offsets[8]; bool FUN_0009d100(Key_9d100* key, float scale, float offset); };
bool Target_9d100::FUN_0009d100(Key_9d100* key, float scale, float offset) { Inventory_9d100* inventory = DAT_004dd700->subsystem->FUN_000862a0()->FUN_00203d70(); content::LoadInventory::DynamicCaster<pure3d::Animation> caster; pure3d::Animation* anim = inventory->Find(&caster, key->low, key->high); if (!anim) return false; int index = count; if(index >= 8) return false; anim->AddRef(); if(animations[index]) animations[index]->Release(); animations[index] = anim; scales[count] = scale > 0.0f ? anim->duration / (scale * anim->rate) : 1.0f; offsets[count] = offset; ++count; return true; }
} // namespace fn_0009d100
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009d1b0 FUN_0009d1b0 (449 B): equivalent/0x0009d1b0.cpp [wrapped: conflict: World; content::LoadInventory::DynamicCaster]
// sym: ?FUN_0009d1b0@CCameraManager_9d1b0@fn_0009d1b0@@QAEXPBD000@Z
namespace fn_0009d1b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20026 inputs, branch coverage 32/34, incomplete)
// FUN_0009d1b0 @ 0x0009d1b0
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


namespace pure3d { class Animation; }
struct Loader_9d1b0;
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
    Loader_9d1b0 *pad4;
};
}
}

struct Anim {
    virtual void v0();
    virtual void v1();
};

struct Loader_9d1b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Anim *v3(content::LoadInventory::DynamicCaster<pure3d::Animation> *caster, int a, int b);
};

struct NameKey {
    int f0;
    int f4;
    void FUN_0027b0e0(const char *s);
    void FUN_0027af50();
};

struct Mid_9d1b0 {
    Loader_9d1b0 *FUN_00203d70();
};

struct Mgr54 {
    Mid_9d1b0 *FUN_000862a0();
};

struct Sub20 {
    char pad[0x124];
    int f124;
};

struct World {
    char pad0[0x20];
    Sub20 *f20;
    char pad1[0x54 - 0x24];
    Mgr54 *f54;
};

struct Tail_9d1b0 {
    void FUN_00098480(World *g);
};


class CCameraManager_9d1b0 {
public:
    char pad0[4];
    unsigned int flags;
    unsigned int f8;
    char pad1[0x18 - 0xc];
    char busy;
    char pad2[0x9c - 0x19];
    int count;
    Anim *slots[4];
    char pad3[0xbc - 0xb0];
    Tail_9d1b0 *tail;

    void FUN_0009a1e0(World *g);
    void FUN_0009a220();
    void FUN_0009a290(World *g);
    void FUN_0009d1b0(const char *n0, const char *n1, const char *n2, const char *n3);
};

void CCameraManager_9d1b0::FUN_0009d1b0(const char *n0, const char *n1, const char *n2, const char *n3)
{
    World *g = DAT_004dd700;
    if (busy)
        return;
    if (g->f20->f124 == 0)
        return;

    struct Locals {
        content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
        NameKey key;
        const char *names[4];
    } lo;
    lo.names[0] = n0;
    lo.names[1] = n1;
    lo.names[2] = n2;
    lo.names[3] = n3;
    count = 0;
    Loader_9d1b0 *loader = DAT_004dd700->f54->FUN_000862a0()->FUN_00203d70();
    for (int i = 0; i < 4; i++) {
        if (lo.names[i]) {
            lo.key.FUN_0027b0e0(lo.names[i]);
            new (&lo.caster) content::LoadInventory::DynamicCaster<pure3d::Animation>;
            lo.caster.pad4 = loader;
            Anim *a = loader->v3(&lo.caster, lo.key.f0, lo.key.f4);
            if (a) {
                int idx = count;
                Anim **slot = &slots[idx];
                a->v0();
                if (*slot)
                    (*slot)->v1();
                *slot = a;
                count = count + 1;
            }
            lo.key.FUN_0027af50();
        }
    }
    if (count <= 0)
        return;

    int r;
    if ((flags >> 2) & 1) {
        r = 1;
    } else if ((flags >> 6) & 1) {
        r = 1;
    } else {
        if ((flags >> 1) & 1)
            FUN_0009a1e0(g);
        unsigned int fl = flags;
        if ((fl >> 4) & 1) {
            r = ((f8 >> 2) & 1) ? 1 : 2;
        } else if (fl & 0x5e) {
            r = 1;
        } else {
            if ((fl >> 5) & 1)
                tail->FUN_00098480(g);
            flags &= 0xffffffdf;
            r = 0;
        }
    }
    if (r == 0)
        FUN_0009a290(g);
    else if (r == 1)
        FUN_0009a220();
    else if (r == 2)
        f8 |= 4;
}
} // namespace fn_0009d1b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5ef2b3f {

// 0x0009d380 FUN_0009d380 (83 B): equivalent/0x0009d380.cpp
// sym: ?FUN_0009d380@Registry_9d380@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d380@2@P832@AEXMMMMMM@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d380 @ 0x0009d380
// FUN_0009d380 @ 0x0009d380  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d380::FUN_0009d380(const char* a1, CCameraManager_9d380* a2, Fn_9d380 a3) {
    typedef Closure6_9d380<CCameraManager_9d380, void, float, float, float, float, float, float> Alloc_9d380;
    HULK_SIZE32(Alloc_9d380, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d380));
    void* x = 0;
    if (m) {
        ((Raw_9d380*)m)->FUN_0009a6e0(a1, a3);
        x = new (m) Closure6_9d380<CCameraManager_9d380, void, float, float, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d3e0 FUN_0009d3e0 (83 B): equivalent/0x0009d3e0.cpp
// sym: ?FUN_0009d3e0@Registry_9d3e0@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d3e0@2@P832@AEXMMVVector_9d3e0@math@@M@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d3e0 @ 0x0009d3e0
// FUN_0009d3e0 @ 0x0009d3e0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d3e0::FUN_0009d3e0(const char* a1, CCameraManager_9d3e0* a2, Fn_9d3e0 a3) {
    typedef Closure4_9d3e0<CCameraManager_9d3e0, void, float, float, math::Vector_9d3e0, float> Alloc_9d3e0;
    HULK_SIZE32(Alloc_9d3e0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d3e0));
    void* x = 0;
    if (m) {
        ((Raw_9d3e0*)m)->FUN_0009a800(a1, a3);
        x = new (m) Closure4_9d3e0<CCameraManager_9d3e0, void, float, float, math::Vector_9d3e0, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d440 FUN_0009d440 (83 B): equivalent/0x0009d440.cpp
// sym: ?FUN_0009d440@Registry_9d440@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d440@2@P832@AEXMM_N@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d440 @ 0x0009d440
// FUN_0009d440 @ 0x0009d440  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d440::FUN_0009d440(const char* a1, CCameraManager_9d440* a2, Fn_9d440 a3) {
    typedef Closure3_9d440<CCameraManager_9d440, void, float, float, bool> Alloc_9d440;
    HULK_SIZE32(Alloc_9d440, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d440));
    void* x = 0;
    if (m) {
        ((Raw_9d440*)m)->FUN_0009a8e0(a1, a3);
        x = new (m) Closure3_9d440<CCameraManager_9d440, void, float, float, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d4f0 FUN_0009d4f0 (83 B): equivalent/0x0009d4f0.cpp
// sym: ?FUN_0009d4f0@Registry_9d4f0@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d4f0@2@P832@AEXMMMM@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d4f0 @ 0x0009d4f0
// FUN_0009d4f0 @ 0x0009d4f0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d4f0::FUN_0009d4f0(const char* a1, CCameraManager_9d4f0* a2, Fn_9d4f0 a3) {
    typedef Closure4_9d4f0<CCameraManager_9d4f0, void, float, float, float, float> Alloc_9d4f0;
    HULK_SIZE32(Alloc_9d4f0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d4f0));
    void* x = 0;
    if (m) {
        ((Raw_9d4f0*)m)->FUN_0009aa20(a1, a3);
        x = new (m) Closure4_9d4f0<CCameraManager_9d4f0, void, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d550 FUN_0009d550 (83 B): equivalent/0x0009d550.cpp
// sym: ?FUN_0009d550@Registry_9d550@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d550@2@P832@AEX_N22@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d550 @ 0x0009d550
// FUN_0009d550 @ 0x0009d550  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d550::FUN_0009d550(const char* a1, CCameraManager_9d550* a2, Fn_9d550 a3) {
    typedef Closure3_9d550<CCameraManager_9d550, void, bool, bool, bool> Alloc_9d550;
    HULK_SIZE32(Alloc_9d550, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d550));
    void* x = 0;
    if (m) {
        ((Raw_9d550*)m)->FUN_0009aaf0(a1, a3);
        x = new (m) Closure3_9d550<CCameraManager_9d550, void, bool, bool, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d5b0 FUN_0009d5b0 (83 B): equivalent/0x0009d5b0.cpp
// sym: ?FUN_0009d5b0@Registry_9d5b0@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d5b0@2@P832@AEX_N22M@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d5b0 @ 0x0009d5b0
// FUN_0009d5b0 @ 0x0009d5b0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d5b0::FUN_0009d5b0(const char* a1, CCameraManager_9d5b0* a2, Fn_9d5b0 a3) {
    typedef Closure4_9d5b0<CCameraManager_9d5b0, void, bool, bool, bool, float> Alloc_9d5b0;
    HULK_SIZE32(Alloc_9d5b0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d5b0));
    void* x = 0;
    if (m) {
        ((Raw_9d5b0*)m)->FUN_0009aba0(a1, a3);
        x = new (m) Closure4_9d5b0<CCameraManager_9d5b0, void, bool, bool, bool, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d610 FUN_0009d610 (83 B): equivalent/0x0009d610.cpp
// sym: ?FUN_0009d610@Registry_9d610@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d610@2@P832@AEX_N222@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d610 @ 0x0009d610
// FUN_0009d610 @ 0x0009d610  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d610::FUN_0009d610(const char* a1, CCameraManager_9d610* a2, Fn_9d610 a3) {
    typedef Closure4_9d610<CCameraManager_9d610, void, bool, bool, bool, bool> Alloc_9d610;
    HULK_SIZE32(Alloc_9d610, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d610));
    void* x = 0;
    if (m) {
        ((Raw_9d610*)m)->FUN_0009ac70(a1, a3);
        x = new (m) Closure4_9d610<CCameraManager_9d610, void, bool, bool, bool, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d670 FUN_0009d670 (83 B): equivalent/0x0009d670.cpp
// sym: ?FUN_0009d670@Registry_9d670@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d670@2@P832@AEX_N222M@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d670 @ 0x0009d670
// FUN_0009d670 @ 0x0009d670  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d670::FUN_0009d670(const char* a1, CCameraManager_9d670* a2, Fn_9d670 a3) {
    typedef Closure5_9d670<CCameraManager_9d670, void, bool, bool, bool, bool, float> Alloc_9d670;
    HULK_SIZE32(Alloc_9d670, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d670));
    void* x = 0;
    if (m) {
        ((Raw_9d670*)m)->FUN_0009ad40(a1, a3);
        x = new (m) Closure5_9d670<CCameraManager_9d670, void, bool, bool, bool, bool, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d6d0 FUN_0009d6d0 (83 B): equivalent/0x0009d6d0.cpp
// sym: ?FUN_0009d6d0@Registry_9d6d0@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d6d0@2@P832@AEX_N22222M@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d6d0 @ 0x0009d6d0
// FUN_0009d6d0 @ 0x0009d6d0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d6d0::FUN_0009d6d0(const char* a1, CCameraManager_9d6d0* a2, Fn_9d6d0 a3) {
    typedef Closure7_9d6d0<CCameraManager_9d6d0, void, bool, bool, bool, bool, bool, bool, float> Alloc_9d6d0;
    HULK_SIZE32(Alloc_9d6d0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d6d0));
    void* x = 0;
    if (m) {
        ((Raw_9d6d0*)m)->FUN_0009ae50(a1, a3);
        x = new (m) Closure7_9d6d0<CCameraManager_9d6d0, void, bool, bool, bool, bool, bool, bool, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f5ef2b3f

// 0x0009d730 FUN_0009d730 (109 B): equivalent/0x0009d730.cpp [wrapped: conflict: CCameraManager; Closure0; Method0]
// sym: ?FUN_0009d730@Registry_9d730@fn_0009d730@@QAEXPBDPAVCCameraManager@2@P832@AEXXZ@Z
namespace fn_0009d730 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0009d730 @ 0x0009d730
// FUN_0009d730 @ 0x0009d730  (generated by work/closure/gen.py)
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CCameraManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_9d730 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_9d730(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_9d730 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_9d730(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e100));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_9d730 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0009d730(const char* name, CCameraManager* owner, void (CCameraManager::*fn)());
};

void Registry_9d730::FUN_0009d730(const char* name, CCameraManager* owner, void (CCameraManager::*fn)()) {
    typedef Closure0<CCameraManager, void> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CCameraManager, void>));
    Closure0<CCameraManager, void>* c = 0;
    if (mem)
        c = new (mem) Closure0<CCameraManager, void>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0009d730
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0009d7a0 FUN_0009d7a0 (109 B): equivalent/0x0009d7a0.cpp [wrapped: conflict: CCameraManager; Closure0; Method0]
// sym: ?FUN_0009d7a0@Registry_9d7a0@fn_0009d7a0@@QAEXPBDPAVCCameraManager@2@P832@AE_NXZ@Z
namespace fn_0009d7a0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0009d7a0 @ 0x0009d7a0
// FUN_0009d7a0 @ 0x0009d7a0  (generated by work/closure/gen.py)
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CCameraManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_9d7a0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_9d7a0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_9d7a0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_9d7a0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0e4));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_9d7a0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0009d7a0(const char* name, CCameraManager* owner, bool (CCameraManager::*fn)());
};

void Registry_9d7a0::FUN_0009d7a0(const char* name, CCameraManager* owner, bool (CCameraManager::*fn)()) {
    typedef Closure0<CCameraManager, bool> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CCameraManager, bool>));
    Closure0<CCameraManager, bool>* c = 0;
    if (mem)
        c = new (mem) Closure0<CCameraManager, bool>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0009d7a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5ef2b3f {

// 0x0009d810 FUN_0009d810 (83 B): equivalent/0x0009d810.cpp
// sym: ?FUN_0009d810@Registry_9d810@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d810@2@P832@AEXHHMHHM@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d810 @ 0x0009d810
// FUN_0009d810 @ 0x0009d810  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d810::FUN_0009d810(const char* a1, CCameraManager_9d810* a2, Fn_9d810 a3) {
    typedef Closure6_9d810<CCameraManager_9d810, void, int, int, float, int, int, float> Alloc_9d810;
    HULK_SIZE32(Alloc_9d810, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d810));
    void* x = 0;
    if (m) {
        ((Raw_9d810*)m)->FUN_0009b080(a1, a3);
        x = new (m) Closure6_9d810<CCameraManager_9d810, void, int, int, float, int, int, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009d960 FUN_0009d960 (83 B): equivalent/0x0009d960.cpp
// sym: ?FUN_0009d960@Registry_9d960@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9d960@2@P832@AEXHMMM@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009d960 @ 0x0009d960
// FUN_0009d960 @ 0x0009d960  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9d960::FUN_0009d960(const char* a1, CCameraManager_9d960* a2, Fn_9d960 a3) {
    typedef Closure4_9d960<CCameraManager_9d960, void, int, float, float, float> Alloc_9d960;
    HULK_SIZE32(Alloc_9d960, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9d960));
    void* x = 0;
    if (m) {
        ((Raw_9d960*)m)->FUN_0009b330(a1, a3);
        x = new (m) Closure4_9d960<CCameraManager_9d960, void, int, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f5ef2b3f

// 0x0009d9c0 FUN_0009d9c0 (109 B): equivalent/0x0009d9c0.cpp [wrapped: conflict: CCameraManager; Closure0; DAT_0048e10c; Method0 (+1)]
// sym: ?FUN_0009d9c0@Registry_9d9c0@fn_0009d9c0@@QAEXPBDPAVCCameraManager@2@P832@AE?AVVector@math@2@XZ@Z
namespace fn_0009d9c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0009d9c0 @ 0x0009d9c0
// FUN_0009d9c0 @ 0x0009d9c0  (generated by work/closure/gen.py)
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);
extern "C++" { extern const char DAT_0048e10c[]; }


class CCameraManager { public: float FUN_dummy(); };
namespace math {
class Vector { public: float FUN_dummy(); };
}

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_9d9c0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_9d9c0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_9d9c0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_9d9c0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(DAT_0048e10c);
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_9d9c0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0009d9c0(const char* name, CCameraManager* owner, math::Vector (CCameraManager::*fn)());
};

void Registry_9d9c0::FUN_0009d9c0(const char* name, CCameraManager* owner, math::Vector (CCameraManager::*fn)()) {
    typedef Closure0<CCameraManager, math::Vector> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CCameraManager, math::Vector>));
    Closure0<CCameraManager, math::Vector>* c = 0;
    if (mem)
        c = new (mem) Closure0<CCameraManager, math::Vector>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0009d9c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5ef2b3f {

// 0x0009da30 FUN_0009da30 (83 B): equivalent/0x0009da30.cpp
// sym: ?FUN_0009da30@Registry_9da30@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9da30@2@P832@AE_NMMMMMM@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009da30 @ 0x0009da30
// FUN_0009da30 @ 0x0009da30  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9da30::FUN_0009da30(const char* a1, CCameraManager_9da30* a2, Fn_9da30 a3) {
    typedef Closure6_9da30<CCameraManager_9da30, bool, float, float, float, float, float, float> Alloc_9da30;
    HULK_SIZE32(Alloc_9da30, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9da30));
    void* x = 0;
    if (m) {
        ((Raw_9da30*)m)->FUN_0009b4a0(a1, a3);
        x = new (m) Closure6_9da30<CCameraManager_9da30, bool, float, float, float, float, float, float>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f5ef2b3f

// 0x0009dae0 FUN_0009dae0 (109 B): equivalent/0x0009dae0.cpp [wrapped: conflict: CCameraManager; Closure0; Method0]
// sym: ?FUN_0009dae0@Registry_9dae0@fn_0009dae0@@QAEXPBDPAVCCameraManager@2@P832@AEPBDXZ@Z
namespace fn_0009dae0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_0009dae0 @ 0x0009dae0
// FUN_0009dae0 @ 0x0009dae0  (generated by work/closure/gen.py)
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

extern "C" void* __cdecl FUN_0008d690(unsigned int size);


class CCameraManager { public: float FUN_dummy(); };

// Function's fields: include/decls/data/script.h (ScriptFunctionFields).
class __declspec(novtable) MethodBase_9dae0 : public ScriptFunctionFields {
  public:
    virtual void m0();
    MethodBase_9dae0(const char* n, int k) { FUN_001d0480(n, k); }
    void FUN_001d0480(const char*, int);
};

template <class T, class R>
class Method0 : public MethodBase_9dae0 {
  public:
    typedef R (T::*Fn)();
    Method0(const char* name, Fn f) : MethodBase_9dae0(name, 0) {
        fn = f;
        retType = FUN_001d04d0(((const char*)&DAT_0048e0f0));
    }
    Fn fn;
};

template <class T, class R>
class Closure0 : public Method0<T, R> {
  public:
    Closure0(const char* name, T* o, typename Method0<T, R>::Fn f) : Method0<T, R>(name, f), owner(o) {}
    T* owner;
};

struct Registry_9dae0 {
    void FUN_001d3b70(const char*, void*);
    void FUN_0009dae0(const char* name, CCameraManager* owner, const char* (CCameraManager::*fn)());
};

void Registry_9dae0::FUN_0009dae0(const char* name, CCameraManager* owner, const char* (CCameraManager::*fn)()) {
    typedef Closure0<CCameraManager, const char*> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    void* mem = FUN_0008d690((int)sizeof(Closure0<CCameraManager, const char*>));
    Closure0<CCameraManager, const char*>* c = 0;
    if (mem)
        c = new (mem) Closure0<CCameraManager, const char*>(name, owner, fn);
    FUN_001d3b70(name, c);
}
} // namespace fn_0009dae0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f5ef2b3f {

// 0x0009dba0 FUN_0009dba0 (83 B): equivalent/0x0009dba0.cpp
// sym: ?FUN_0009dba0@Registry_9dba0@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9dba0@2@P832@AE_NMMMM_N@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009dba0 @ 0x0009dba0
// FUN_0009dba0 @ 0x0009dba0  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9dba0::FUN_0009dba0(const char* a1, CCameraManager_9dba0* a2, Fn_9dba0 a3) {
    typedef Closure5_9dba0<CCameraManager_9dba0, bool, float, float, float, float, bool> Alloc_9dba0;
    HULK_SIZE32(Alloc_9dba0, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9dba0));
    void* x = 0;
    if (m) {
        ((Raw_9dba0*)m)->FUN_0009b770(a1, a3);
        x = new (m) Closure5_9dba0<CCameraManager_9dba0, bool, float, float, float, float, bool>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}


// 0x0009dc50 FUN_0009dc50 (83 B): equivalent/0x0009dc50.cpp
// sym: ?FUN_0009dc50@Registry_9dc50@fn_f5ef2b3f@@QAEXPBDPAVCCameraManager_9dc50@2@P832@AEXPAD222@Z@Z
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// FUN_0009dc50 @ 0x0009dc50
// FUN_0009dc50 @ 0x0009dc50  (generated by tools/equiv_gen/reg_helper.py)
void Registry_9dc50::FUN_0009dc50(const char* a1, CCameraManager_9dc50* a2, Fn_9dc50 a3) {
    typedef Closure4_9dc50<CCameraManager_9dc50, void, char*, char*, char*, char*> Alloc_9dc50;
    HULK_SIZE32(Alloc_9dc50, 0x24);
    void* m = FUN_0008d690((int)sizeof(Alloc_9dc50));
    void* x = 0;
    if (m) {
        ((Raw_9dc50*)m)->FUN_0009b930(a1, a3);
        x = new (m) Closure4_9dc50<CCameraManager_9dc50, void, char*, char*, char*, char*>(a2);
    }
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)a1, (hulk_intptr)x);
}

} // namespace fn_f5ef2b3f

// 0x0009dcb0 FUN_0009dcb0 (109 B): matches/0x0009dcb0.cpp [wrapped: helper definitions (5 out-of-line function bodies)]
// sym: ?Make@Owner_9dcb0@fn_0009dcb0@@QAEXHHH@Z
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_0009dcb0 {


struct Function_9dcb0 {
    Function_9dcb0(int a, int b) throw();
    virtual void f();
    char pad[0x14];
};
struct Method0_9dcb0 : Function_9dcb0 {
    Method0_9dcb0(int id, int a, int b) throw();
    virtual void h();
    char c;
    int a;
    int b;
};
struct Closure0_9dcb0 : Method0_9dcb0 {
    Closure0_9dcb0(int id, int a, int b) throw();
    virtual void h();
};
char GetFlag(void*) throw();
struct Owner_9dcb0 {
    void Make(int id, int a, int b) throw();
};
Method0_9dcb0::Method0_9dcb0(int id, int x, int y) throw() : Function_9dcb0(id, 0) {
    this->a = y;
    c = GetFlag(((char*)&DAT_0048e128));
    b = x;
}
Closure0_9dcb0::Closure0_9dcb0(int id, int x, int y) throw() : Method0_9dcb0(id, x, y) {}
void Method0_9dcb0::h() {}
void Closure0_9dcb0::h() {}
void Owner_9dcb0::Make(int id, int a, int b) throw() {
    Closure0_9dcb0* p = new Closure0_9dcb0(id, a, b);
    ((owners::Obj_1d3b70 *)this)->FUN_001d3b70((hulk_uintptr)id, (hulk_intptr)(Closure0_9dcb0 *)p);
}
} // namespace fn_0009dcb0


// 0x0009dd20 FUN_0009dd20 (6657 B): equivalent/0x0009dd20.cpp [wrapped: macros]
// sym: ??0CCameraManager@fn_0009dd20@@QAE@XZ
namespace fn_0009dd20 {
// STATUS: equivalent (tools/equiv.py level 3: 252 inputs, branch coverage 126/126)
// FUN_0009dd20 @ 0x0009dd20


void* FUN_0008d690(unsigned int);
char FUN_001d04d0(const void*) throw();
class CCameraManager;
namespace math { class Vector { public: float x, y, z; }; }
typedef float Float; typedef bool Bool; typedef int Int; typedef void Void;
typedef const char* String; typedef char* CharPtr; typedef math::Vector Vector;
extern char DAT_0048e0e4, DAT_0048e0f0, DAT_0048e100, DAT_0048e10c, DAT_0048e128, DAT_0048e134, DAT_0049cad8;
#define tBool DAT_0048e0e4
#define tString DAT_0048e0f0
#define tVoid DAT_0048e100
#define tVector DAT_0048e10c
#define tFloat DAT_0048e128
#define tInt DAT_0048e134
#define tCharPtr DAT_0049cad8
// Function's fields (include/decls/data/script.h); Method<N> adds the member-function pointer (CCameraManager's,
// held as ScriptMemberFn), Closure<N> the object.
class Base : public ScriptFunctionFields { public: virtual void v(); Base(const char*, int) throw(); };
template<class C, class R> class Method0 : public Base { public: R (C::*f)(); Method0(const char* n, R (C::*x)(), const void* r) : Base(n, 0) { f = x; retType = FUN_001d04d0(r); } virtual void v(); };
template<class C, class R> class Closure0 : public Method0<C, R> { public: C* owner; Closure0(const char* n, C* o, R (C::*f)(), const void* r) : Method0<C, R>(n, f, r) { owner = o; } virtual void v(); };
template<class C, class R, class A1> class Method1 : public Base { public: R (C::*f)(A1); Method1(const char* n, R (C::*x)(A1), const void* r, const void* a1) : Base(n, 1) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); } virtual void v(); };
template<class C, class R, class A1> class Closure1 : public Method1<C, R, A1> { public: C* owner; Closure1(const char* n, C* o, R (C::*f)(A1), const void* r, const void* a1) : Method1<C, R, A1>(n, f, r, a1) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2> class Method2 : public Base { public: R (C::*f)(A1, A2); Method2(const char* n, R (C::*x)(A1, A2), const void* r, const void* a1, const void* a2) : Base(n, 2) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); } virtual void v(); };
template<class C, class R, class A1, class A2> class Closure2 : public Method2<C, R, A1, A2> { public: C* owner; Closure2(const char* n, C* o, R (C::*f)(A1, A2), const void* r, const void* a1, const void* a2) : Method2<C, R, A1, A2>(n, f, r, a1, a2) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Method3 : public Base { public: R (C::*f)(A1, A2, A3); Method3(const char* n, R (C::*x)(A1, A2, A3), const void* r, const void* a1, const void* a2, const void* a3) : Base(n, 3) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3> class Closure3 : public Method3<C, R, A1, A2, A3> { public: C* owner; Closure3(const char* n, C* o, R (C::*f)(A1, A2, A3), const void* r, const void* a1, const void* a2, const void* a3) : Method3<C, R, A1, A2, A3>(n, f, r, a1, a2, a3) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Method4 : public Base { public: R (C::*f)(A1, A2, A3, A4); Method4(const char* n, R (C::*x)(A1, A2, A3, A4), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Base(n, 4) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4> class Closure4 : public Method4<C, R, A1, A2, A3, A4> { public: C* owner; Closure4(const char* n, C* o, R (C::*f)(A1, A2, A3, A4), const void* r, const void* a1, const void* a2, const void* a3, const void* a4) : Method4<C, R, A1, A2, A3, A4>(n, f, r, a1, a2, a3, a4) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Method5 : public Base { public: R (C::*f)(A1, A2, A3, A4, A5); Method5(const char* n, R (C::*x)(A1, A2, A3, A4, A5), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Base(n, 5) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); argTypes[4] = FUN_001d04d0(a5); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5> class Closure5 : public Method5<C, R, A1, A2, A3, A4, A5> { public: C* owner; Closure5(const char* n, C* o, R (C::*f)(A1, A2, A3, A4, A5), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5) : Method5<C, R, A1, A2, A3, A4, A5>(n, f, r, a1, a2, a3, a4, a5) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Method6 : public Base { public: R (C::*f)(A1, A2, A3, A4, A5, A6); Method6(const char* n, R (C::*x)(A1, A2, A3, A4, A5, A6), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6) : Base(n, 6) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); argTypes[4] = FUN_001d04d0(a5); argTypes[5] = FUN_001d04d0(a6); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6> class Closure6 : public Method6<C, R, A1, A2, A3, A4, A5, A6> { public: C* owner; Closure6(const char* n, C* o, R (C::*f)(A1, A2, A3, A4, A5, A6), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6) : Method6<C, R, A1, A2, A3, A4, A5, A6>(n, f, r, a1, a2, a3, a4, a5, a6) { owner = o; } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Method7 : public Base { public: R (C::*f)(A1, A2, A3, A4, A5, A6, A7); Method7(const char* n, R (C::*x)(A1, A2, A3, A4, A5, A6, A7), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6, const void* a7) : Base(n, 7) { f = x; retType = FUN_001d04d0(r); argTypes[0] = FUN_001d04d0(a1); argTypes[1] = FUN_001d04d0(a2); argTypes[2] = FUN_001d04d0(a3); argTypes[3] = FUN_001d04d0(a4); argTypes[4] = FUN_001d04d0(a5); argTypes[5] = FUN_001d04d0(a6); argTypes[6] = FUN_001d04d0(a7); } virtual void v(); };
template<class C, class R, class A1, class A2, class A3, class A4, class A5, class A6, class A7> class Closure7 : public Method7<C, R, A1, A2, A3, A4, A5, A6, A7> { public: C* owner; Closure7(const char* n, C* o, R (C::*f)(A1, A2, A3, A4, A5, A6, A7), const void* r, const void* a1, const void* a2, const void* a3, const void* a4, const void* a5, const void* a6, const void* a7) : Method7<C, R, A1, A2, A3, A4, A5, A6, A7>(n, f, r, a1, a2, a3, a4, a5, a6, a7) { owner = o; } virtual void v(); };
#define FN(b) void FUN_##b();
#define CB(b) (&CCameraManager::FUN_##b)
#define G0(n, b, R) { typedef Closure0<CCameraManager, R> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R)); }
#define G1(n, b, R, A1) { typedef Closure1<CCameraManager, R, A1> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1)); }
#define G2(n, b, R, A1, A2) { typedef Closure2<CCameraManager, R, A1, A2> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2)); }
#define G3(n, b, R, A1, A2, A3) { typedef Closure3<CCameraManager, R, A1, A2, A3> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2, &t##A3)); }
#define G4(n, b, R, A1, A2, A3, A4) { typedef Closure4<CCameraManager, R, A1, A2, A3, A4> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2, &t##A3, &t##A4)); }
#define G5(n, b, R, A1, A2, A3, A4, A5) { typedef Closure5<CCameraManager, R, A1, A2, A3, A4, A5> Built_t; HULK_SIZE32(Built_t, 0x24); r->FUN_001d3b70(n, new Built_t(n, this, CB(b), &t##R, &t##A1, &t##A2, &t##A3, &t##A4, &t##A5)); }
#define M6(n, c, b, R, A1, A2, A3, A4, A5, A6) { typedef Closure6<CCameraManager, R, A1, A2, A3, A4, A5, A6> Built_t; HULK_SIZE32(Built_t, 0x24); void* m = FUN_0008d690((unsigned int)sizeof(Built_t)); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, CB(b)); x = new (m) Built_t(this); } r->FUN_001d3b70(n, x); }
#define M7(n, c, b, R, A1, A2, A3, A4, A5, A6, A7) { typedef Closure7<CCameraManager, R, A1, A2, A3, A4, A5, A6, A7> Built_t; HULK_SIZE32(Built_t, 0x24); void* m = FUN_0008d690((unsigned int)sizeof(Built_t)); void* x = 0; if (m) { ((Raw_##c*)m)->FUN_##c(n, CB(b)); x = new (m) Built_t(this); } r->FUN_001d3b70(n, x); }

class CCameraManager {
public:
    CCameraManager();
    virtual void v0();
    int i04;
    int i08;
    int i0c;
    int i10;
    int i14;
    char b18;
    char b19;
    char b1a;
    char pad1b;
    int i1c;
    int i20, i24, i28, i2c, i30, i34, i38, i3c;
    char pad40[0x60];
    int ia0, ia4, ia8, iac, ib0, ib4, ib8, ibc, ic0, ic4;
    void FUN_0009a220();
    // The member functions bound to Lua below.
    void FUN_00098f40(bool);
    void FUN_00099000(math::Vector, float);
    void FUN_00099030(float);
    void FUN_00099040(float);
    void FUN_00099330(int, float, float, float);
    void FUN_000993f0(int, int, float, int, int, float);
    void FUN_00099500(float, float, math::Vector, float);
    void FUN_00099570(float, float, float, float, float, float);
    void FUN_000995c0(float, float, bool);
    void FUN_00099600(float, float);
    void FUN_00099640(float, float);
    void FUN_00099680(float, float);
    void FUN_000996c0(float, float, float, float);
    void FUN_00099710();
    bool FUN_00099730();
    bool FUN_00099740();
    bool FUN_00099750();
    bool FUN_00099760();
    bool FUN_00099790();
    bool FUN_000997a0();
    void FUN_000997b0(float, float);
    void FUN_000997e0(float, float);
    void FUN_00099810(float, float);
    void FUN_00099840(float);
    void FUN_00099860(float, float);
    void FUN_00099880(float, float);
    void FUN_000998a0(float, float);
    void FUN_000998c0(float, float);
    void FUN_000998f0(math::Vector, math::Vector);
    void FUN_00099960(float, float);
    void FUN_00099980(float, float);
    void FUN_000999b0(float, float);
    void FUN_000999f0(float, float);
    void FUN_00099a10(float);
    void FUN_00099a20(float);
    void FUN_00099a30(bool);
    void FUN_00099a50(const char*);
    const char* FUN_00099a70();
    void FUN_00099ae0(bool);
    void FUN_00099b00(math::Vector, bool);
    float FUN_00099b30();
    float FUN_00099b50();
    float FUN_00099b70();
    void FUN_00099b90(float);
    float FUN_00099bb0();
    void FUN_00099bd0(float);
    math::Vector FUN_00099bf0();
    void FUN_00099c60(float);
    void FUN_00099c80(float);
    void FUN_00099ca0(float);
    void FUN_00099cc0(float);
    void FUN_00099ce0(float);
    bool FUN_00099d60(float, float, float, float, bool);
    void FUN_0009a480(float);
    void FUN_0009a500(float, float);
    bool FUN_0009a5d0(float, float, float, float, float, float);
    void FUN_0009c170(bool, bool, bool);
    void FUN_0009c1a0(bool, bool, bool, float);
    void FUN_0009c1d0(bool, bool, bool, bool);
    void FUN_0009c200(bool, bool, bool, bool, float);
    void FUN_0009c230(bool, bool, bool, bool, bool, bool, float);
    void FUN_0009d1b0(char*, char*, char*, char*);
};
template<> class Closure6<CCameraManager, bool, float, float, float, float, float, float> { public: virtual void v(); ScriptFunctionFields fields; bool (CCameraManager::*fn)(float, float, float, float, float, float); CCameraManager* owner; Closure6(CCameraManager* o) { owner = o; } };
template<> class Closure6<CCameraManager, void, float, float, float, float, float, float> { public: virtual void v(); ScriptFunctionFields fields; void (CCameraManager::*fn)(float, float, float, float, float, float); CCameraManager* owner; Closure6(CCameraManager* o) { owner = o; } };
template<> class Closure6<CCameraManager, void, int, int, float, int, int, float> { public: virtual void v(); ScriptFunctionFields fields; void (CCameraManager::*fn)(int, int, float, int, int, float); CCameraManager* owner; Closure6(CCameraManager* o) { owner = o; } };
template<> class Closure7<CCameraManager, void, bool, bool, bool, bool, bool, bool, float> { public: virtual void v(); ScriptFunctionFields fields; void (CCameraManager::*fn)(bool, bool, bool, bool, bool, bool, float); CCameraManager* owner; Closure7(CCameraManager* o) { owner = o; } };
class Registry { public:
    void FUN_001d3b70(const char*, void*);
};
class Entry { public:
};
class Raw_0009a6e0 { public: void FUN_0009a6e0(const char*, void (CCameraManager::*)(float, float, float, float, float, float)); };
class Raw_0009ae50 { public: void FUN_0009ae50(const char*, void (CCameraManager::*)(bool, bool, bool, bool, bool, bool, float)); };
class Raw_0009b080 { public: void FUN_0009b080(const char*, void (CCameraManager::*)(int, int, float, int, int, float)); };
class Raw_0009b4a0 { public: void FUN_0009b4a0(const char*, bool (CCameraManager::*)(float, float, float, float, float, float)); };
Registry* FUN_001d4c90();

CCameraManager::CCameraManager() {
    i04 = 1;
    i08 = 0;
    i1c = 0;
    i10 = 0;
    ib8 = 0;
    i14 = 0;
    ib0 = 0;
    ib4 = 0;
    ibc = 0;
    ic0 = 0;
    ic4 = 0;
    b19 = 1;
    b1a = 0;
    b18 = 0;
    i20 = 0; i24 = 0; i28 = 0; i2c = 0; i30 = 0; i34 = 0; i38 = 0; i3c = 0;
    ia0 = 0; ia4 = 0; ia8 = 0; iac = 0;
    FUN_0009a220();
    i0c = 0;
    Registry* r = FUN_001d4c90();
    if (r) {
M6("cm_SetScriptCamStatic", 0009a6e0, 00099570, Void, Float, Float, Float, Float, Float, Float)
G4("cm_SetScriptCamStaticV", 00099500, Void, Float, Float, Vector, Float)
G3("cm_SetScriptCamShot", 000995c0, Void, Float, Float, Bool)
G2("cm_SetScriptCamZoom", 00099600, Void, Float, Float)
G2("cm_SetScriptCamPan", 00099640, Void, Float, Float)
G2("cm_SetScriptCamPitch", 00099680, Void, Float, Float)
G4("cm_SetScriptCamShake", 000996c0, Void, Float, Float, Float, Float)
G3("cm_SwitchToScriptCamera", 0009c170, Void, Bool, Bool, Bool)
G4("cm_SwitchToScriptCameraTD", 0009c1a0, Void, Bool, Bool, Bool, Float)
G4("cm_SwitchToScriptCameraP", 0009c1d0, Void, Bool, Bool, Bool, Bool)
G5("cm_SwitchToScriptCameraTDP", 0009c200, Void, Bool, Bool, Bool, Bool, Float)
M7("cm_SwitchToScriptCameraAll", 0009ae50, 0009c230, Void, Bool, Bool, Bool, Bool, Bool, Bool, Float)
G0("cm_AbortScriptCamera", 00099710, Void)
G0("cm_IsScriptCameraPlaying", 00099760, Bool)
G2("cm_SetScriptCamPanTiming", 000997b0, Void, Float, Float)
G2("cm_SetScriptCamPitchTiming", 000997e0, Void, Float, Float)
G2("cm_SetScriptCamZoomTiming", 00099810, Void, Float, Float)
M6("cm_SetScriptCamBlending", 0009b080, 000993f0, Void, Int, Int, Float, Int, Int, Float)
G2("cm_SetScriptCamZoomEaseInOut", 00099860, Void, Float, Float)
G2("cm_SetScriptCamPitchEaseInOut", 00099880, Void, Float, Float)
G2("cm_SetScriptCamPanEaseInOut", 000998a0, Void, Float, Float)
G1("cm_SetScriptCamSkipTime", 00099840, Void, Float)
G2("cm_SetScriptCamTargetTiming", 000998c0, Void, Float, Float)
G2("cm_SetScriptCamTarget", 000998f0, Void, Vector, Vector)
G2("cm_SetScriptCamTargetEaseInOut", 00099960, Void, Float, Float)
G2("cm_SetScriptCamFovaTiming", 00099980, Void, Float, Float)
G2("cm_SetScriptCamFova", 000999b0, Void, Float, Float)
G2("cm_SetScriptCamFovaEaseInOut", 000999f0, Void, Float, Float)
G1("cm_SetScriptCamNearPlane", 00099a10, Void, Float)
G1("cm_SetScriptCamFarPlane", 00099a20, Void, Float)
G1("cm_SetScriptCamDontSwitch", 00099a30, Void, Bool)
G1("cm_EnableDramaticCamera", 00098f40, Void, Bool)
G4("cm_CameraShake", 00099330, Void, Int, Float, Float, Float)
G0("cm_GetCurrentCameraPosition", 00099bf0, Vector)
G0("cm_IsDramaticCameraActive", 00099730, Bool)
G0("cm_IsHypnoticCameraActive", 00099740, Bool)
G0("cm_IsScriptCameraActive", 00099750, Bool)
G0("cm_IsNISCameraActive", 00099790, Bool)
G0("cm_IsGameCameraActive", 000997a0, Bool)
G1("cm_SetScriptCamTargetBias", 00099c60, Void, Float)
G1("cm_SetScriptCamFovaBias", 00099c80, Void, Float)
G1("cm_SetScriptCamPitchBias", 00099ca0, Void, Float)
G1("cm_SetScriptCamPanBias", 00099cc0, Void, Float)
G1("cm_SetScriptCamZoomBias", 00099ce0, Void, Float)
M6("cm_CanScriptCamSeeTarget", 0009b4a0, 0009a5d0, Bool, Float, Float, Float, Float, Float, Float)
G1("cm_SetChaseCamTarget", 00099a50, Void, String)
G0("cm_GetChaseCamTarget", 00099a70, String)
G1("cm_ResetChaseCam", 00099ae0, Void, Bool)
G2("cm_ResetChaseCamFacing", 00099b00, Void, Vector, Bool)
G5("cm_IsPointInCameraView", 00099d60, Bool, Float, Float, Float, Float, Bool)
G2("cm_SetHypnoticCamTarget", 00099000, Void, Vector, Float)
G1("cm_SetHypnoticCamSoundTrigger", 00099030, Void, Float)
G1("cm_SetHypnoticCamMinHeight", 00099040, Void, Float)
G4("cm_StartHypnoticCam", 0009d1b0, Void, CharPtr, CharPtr, CharPtr, CharPtr)
G0("cm_GetChaseCamBaseDist", 00099b30, Float)
G0("cm_GetChaseCamFOV", 00099b50, Float)
G1("cm_SetChaseCamBaseDist", 0009a480, Void, Float)
G2("cm_SetChaseCamFOV", 0009a500, Void, Float, Float)
G0("cm_GetChaseCamMaxHeight", 00099b70, Float)
G1("cm_SetChaseCamMaxHeight", 00099b90, Void, Float)
G0("cm_GetChaseCamMinHeight", 00099bb0, Float)
G1("cm_SetChaseCamMinHeight", 00099bd0, Void, Float)
    }
}
} // namespace fn_0009dd20
#undef CB
#undef FN
#undef G0
#undef G1
#undef G2
#undef G3
#undef G4
#undef G5
#undef M6
#undef M7
#undef tBool
#undef tCharPtr
#undef tFloat
#undef tInt
#undef tString
#undef tVector
#undef tVoid

