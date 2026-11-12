// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0009f760..0x000a75d0 (kind game, layer game, confidence high), dominant class CChaseCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f69c308d {
#define TREE_TU_END }
namespace fn_f69c308d {} using namespace fn_f69c308d;
namespace fn_f69c308d { extern "C" char DAT_00405604[]; }   // (x64t7) the game vftables the TU's placeholder names stood for (verify_relocs)
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f69c308d {
struct Vec3_9f7d0 {
    float x, y, z;
    bool IsSmall_0022d330();
};
} // namespace fn_f69c308d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif
namespace fn_f69c308d {
struct St_9fa00 {
    int a;
    char p1[8];
    int b;
    char p2[0x30 - 0x10];
    int c;
    char p3[0x48 - 0x34];
    int d;
    char p4[0xa4 - 0x4c];
};
struct Dev_9fa00 {
};
struct Mgr_9fa00 {
};
struct Root_9fa00 {
    char pad[0x54];
    Mgr_9fa00* mgr;
};
struct Sys_9fa00 {
    Mgr_9fa00* Get();
};
struct Glob_9fa00 {
    char pad[0x54];
    Sys_9fa00* sys;
};
extern Glob_9fa00* hulk_at_004dd700;
struct Vec3_9fbd0 { float x, y, z; };
struct V3_9fd50 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Vec_9fef0 { float x,y,z; hulk_freg FUN_0022d110(); };
} // namespace fn_f69c308d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" float asinf(float);
#endif
namespace fn_f69c308d {
extern "C" int __cdecl FUN_0009fa70(int*, int*, int*);
union FloatBits_a0330 {
    float f;
    unsigned int u;
};
hulk_freg __cdecl FUN_000a0330(float);
float __cdecl Wrap_000a02a0(float v);
union Bits_a0450 {
    float f;
    unsigned long u;
};
struct Vec_a04c0 { float x,y,z; };
extern float __cdecl FnA_000a02a0(float);
extern float __cdecl FnC_000a02a0(float);
extern float __cdecl FnB_000a00e0(float, float, int, int, int);
struct Vec3_a0940 {
    union { float x; int xi; };
    union { float y; int yi; };
    union { float z; int zi; };
};
Vec3_a0940* FUN_0009fbd0(Vec3_a0940* out, Vec3_a0940* a, Vec3_a0940* b, Vec3_a0940* c, float tau, float dt);
struct Mover_a0940 {
    char pad000[0x170];
    Vec3_a0940 prev;
    Vec3_a0940 f17c;
    Vec3_a0940 saved;
    Vec3_a0940 pos;
    char pad1a0[0x1c4 - 0x1a0];
    float off1c4;
    float off1c8;
    union { float off1cc; int off1cci; };
    char pad1d0[0x234 - 0x1d0];
    float tau;
    char pad238[0x254 - 0x238];
    Vec3_a0940 v254;
    Vec3_a0940 v260;
    char pad26c[0x346 - 0x26c];
    char clamped;
    char pad347[0x444 - 0x347];
    float base444;
    char pad448[0x498 - 0x448];
    union { float hi; int hii; };
    union { float lo; int loi; };
    void FUN_000a0940(float dt);
};
struct Vec3_a0ac0 { float x, y, z; };
extern void __cdecl FUN_000a04c0(Vec3_a0ac0* d, float* a, float* b, float* len);
struct Aim_a0ac0 {
    char pad0[0x194];
    Vec3_a0ac0 origin;          // 0x194
    char pad1[0x1e8 - 0x1a0];
    Vec3_a0ac0 target;          // 0x1e8
    char pad2[0x20c - 0x1f4];
    float yawBase;        // 0x20c
    float pitchBase;      // 0x210
    float yawOut;         // 0x214
    char pad3[0x21c - 0x218];
    float yawBias;        // 0x21c
    char pad4[0x224 - 0x220];
    float pitchOut;       // 0x224
    char pad5[0x2ec - 0x228];
    float s2ec, s2f0;
    char pad6[0x2fc - 0x2f4];
    float s2fc, s300;

    void FUN_000a0ac0(float pitch0, float yaw);
};
class CChaseCamera_a0bb0 {
    char pad[0x440];

  public:
    float value;
};
class C_a0bd0 {
    char pad[0x454];

  public:
    float value;
};
class CGameCamera_a0be0 {
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
struct Obj_a0c00 {
    char pad[0x498];
    float value;
};
class Obj_a0c20 {
  public:
    char pad[0x49c];
    float value;
};
class CChaseCamera_a0c40 {
  public:
    char pad[0x320];
    int state;
    int prev;
    int value;
    char rest[0x68];
    int reset;
    void f(int x);
};
class A_a0d40 {
  public:
    virtual void f();
    virtual void g();
};
extern void* hulk_at_00405604[];
class Ref_a0d80 {
  public:
    virtual void F0();
    virtual void Release();
};
class CGameCamera_a0d80 {
  public:
    void* vptr;
    void Fin_000a9620();
    void Fin29_000a91b0();
};
class CChaseCamera_a0d80 : public CGameCamera_a0d80 {
  public:
    char pad[0x350 - 4];
    Ref_a0d80* m350;
    ~CChaseCamera_a0d80();
};
struct Vec3_a0dc0 { float x, y, z; };
Vec3_a0dc0 *FUN_0009fbd0(Vec3_a0dc0 *out, Vec3_a0dc0 *a, Vec3_a0dc0 *b, Vec3_a0dc0 *c, float d, float e);
class Body_a0dc0 {
public:
    char pad000[0x1e8];
    Vec3_a0dc0 pos;
    Vec3_a0dc0 prev;
    Vec3_a0dc0 vel;
    char pad20c[0xc0];
    Vec3_a0dc0 refB;
    Vec3_a0dc0 refA;
    char pad2e4[0x15c];
    float limit;
    void FUN_000a0dc0(float a1, float a2, float a3);
};
class Ref {
  public:
    virtual void f0();
    virtual void release();
    int pad;
    int a;
    int b;
};
struct CChaseCamera_a0fe0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual float v8();
 char pad0[0xd8-4]; float horizontal; float vertical; char pad1[0x450-0xe0];
 float value; char pad2[8]; float x; float y; float z; float radius; float angleX; float angleY; float angleZ;
 void FUN_000a9090(float);
 void update(float);
};
struct Vec3_a1760 { float x, y, z; };
Vec3_a1760* FUN_0009f8c0(Vec3_a1760* out, float x, float y, float z);
void FUN_000a04c0(Vec3_a1760* d, float* a, float* b, float* c);
class Mover_a1760 {
public:
    char pad000[0x194];
    float f194, f198, f19c;
    char pad1a0[0x24];
    float f1c4, f1c8, f1cc;
    char pad1d0[0x18];
    float f1e8, f1ec, f1f0;
    char pad1f4[0x18];
    float f20c, f210;
    char pad214[0x10c];
    int f320;
    char pad324[4];
    int f328;
    char pad32c[0x68];
    float f394, f398, f39c, f3a0, f3a4, f3a8, f3ac, f3b0;
    char pad3b4[0x94];
    int f448;
    char pad44c[0x2c];
    float f478, f47c;
    int f480, f484;

    void FUN_000a0dc0(float, float, float);
    void FUN_000a0940(float);
    void Update(float a1, float a2);
};
struct V3_a1930 {
    float x, y, z;
};
struct Block_a1930 {
    V3_a1930 pos;                 // 0x170
    float f17c;
    float f180;
    float f184;
    float f188;
    float f18c;
    float f190;
    float f194;
    float f198;
    float f19c;
    char pad1a0[0x1c4 - 0x1a0];
    float f1c4;
    float f1c8;
    float f1cc;
    char pad1d0[0x1e8 - 0x1d0];
    float f1e8;
    float f1ec;
    float f1f0;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    float f214;
    float f218;
    float f21c;
    float f220;
    float f224;
    float f228;
    float f22c;
    float f230;
    char pad234[0x248 - 0x234];
};
struct Target_a1930 {
    void FUN_000fd8a0(World* world, void* mat, int scratch, float f8);
};
struct Inner_a1930 {
    Target_a1930* FUN_000fdc30();
};
struct Holder_a1930 {
    char pad0[0x1ca0];
    Inner_a1930* inner;
};
struct Game_a1930 {
    char pad0[0x124];
    Holder_a1930* holder;
};
} // namespace fn_f69c308d
struct World {
    char pad0[0x20];
    Game_a1930* game;
};
namespace fn_f69c308d {
void __cdecl FUN_000a04c0(V3_a1930* dir, float* p1, float* p0, float* scratch);
class Mover_a1930 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float* scratch, V3_a1930* pos);
    virtual void v7();
    virtual float v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void* v14();
    char pad4[0x170 - 4];
    Block_a1930 b;
    Block_a1930 f248;
    int mode;
    int prevMode;
    int f328;
    char pad32c[0x394 - 0x32c];
    int f394;
    char pad398[0x3bc - 0x398];
    float f3bc;
    float f3c0;
    float f3c4;
    char pad3c8[0x448 - 0x3c8];
    float f448;
    char pad44c[0x490 - 0x44c];
    char f490;
    char pad491[0x4ac - 0x491];
    int f4ac;
    int f4b0;
    void FUN_000a1930(V3_a1930 pos, int newMode);
};
struct Counter_a1b30 {
    int FUN_00026e30(float radius, void *list, int max);
};
struct Owner_a1b30 {
    char pad0[0x20];
    Counter_a1b30 *counter;
};
hulk_freg __cdecl FUN_0009faa0(float cur, float target, float dt, float rate);
class Smoother {
public:
    char pad0[0x345];
    char active;
    char pad346[2];
    char locked;
    char pad349[0x424 - 0x349];
    char list[4];
    int count;
    int nearA;
    int nearB;
    char pad434[8];
    float timer;
    float base;
    float value;
    float ratio;
    void FUN_000a1b30(Owner_a1b30 *owner, float dt, bool snap);
};
float __cdecl FUN_000a0450(void *v) throw();
union Bits_a1ca0 {
    float f;
    unsigned int u;
};
struct V3_a1ca0 {
    float x, y, z;
};
struct Fighter_a1ca0 {
    void FUN_00059a50(V3_a1ca0 *out);
};
struct Info_a1ca0 {
    char pad0[8];
    unsigned __int64 id;        // 0x08
};
struct Node {
    char pad0[0xec];
    Info_a1ca0 *info;                 // 0xec
};
struct Stats_a1ca0 {
    char pad0[0x10];
    Fighter_a1ca0 *fighter;           // 0x10
    char pad14[0x338 - 0x14];
    int f338;
    char pad33c[0x1a64 - 0x33c];
    Bits_a1ca0 f1a64;
    char FUN_00035550(V3_a1ca0 *out);
};
struct Holder124_a1ca0 {
    char pad0[0x124];
    Stats_a1ca0 *stats;
};
struct Owner_a1ca0 {
    char pad0[0x20];
    Holder124_a1ca0 *f20;
};
class CChaseCamera_a1ca0 {
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
    virtual char *getTarget();
    char pad04[0x190];
    V3_a1ca0 v194;                    // 0x194
    char pad1a0[0x18];
    V3_a1ca0 v1b8;                    // 0x1b8
    V3_a1ca0 v1c4;                    // 0x1c4
    V3_a1ca0 v1d0;                    // 0x1d0
    V3_a1ca0 v1dc;                    // 0x1dc
    V3_a1ca0 v1e8;                    // 0x1e8
    char pad1f4[0xc];
    V3_a1ca0 v200;                    // 0x200
    char pad20c[8];
    int f214;
    char pad218[4];
    int f21c;
    char pad220[4];
    int f224;
    char pad228[4];
    int f22c;
    char pad230[4];
    Bits_a1ca0 dt234;                 // 0x234
    float f238;
    Bits_a1ca0 f23c;                  // 0x23c
    char pad240[0x5c];
    V3_a1ca0 v29c;                    // 0x29c
    V3_a1ca0 v2a8;                    // 0x2a8
    char pad2b4[0x345 - 0x2b4];
    char b345;
    char pad346;
    char b347;
    char b348;
    char pad349[3];
    float f34c;
    Stats_a1ca0 *stats;               // 0x350
    char pad354[0x448 - 0x354];
    int f448;
    char pad44c[4];
    float f450;
    float f454;
    float f458;
    char pad45c[0x488 - 0x45c];
    float f488;
    V3_a1ca0 *FUN_000a92c0(V3_a1ca0 *out, Owner_a1ca0 *owner, Stats_a1ca0 *st);
    void FUN_000a1b30(Owner_a1ca0 *owner, float dt, bool snap);
    void FUN_000a0fe0(float v);
    void FUN_000a1ca0(Owner_a1ca0 *owner, float dt);
};
extern const float gZero_a2370;
extern void* g_vftable_a27b0[];
class Ref_a27b0 {
  public:
    virtual void F0();
    virtual void Release();
};
class CChaseCamera_a27b0 {
  public:
    void* vptr;
    char pad[0x34c];
    Ref_a27b0* m350;
    void Cam29_000a91b0();
    void Fin_000a9620();
    CChaseCamera_a27b0* f2(unsigned char flags);
};
class CChaseCamera_a2c60 {
    char pad[0x450];
    float oldVal;
    float target;
    float speed;

  public:
    void Set(float value, float time);
    void helper_000a0fe0(float);
};
struct V3_a2de0 {
    float x, y, z;
};
V3_a2de0 *__cdecl FUN_0009f8c0(V3_a2de0 *out, int a, int b, int c);
class Obj_a2de0 {
public:
    char pad0[0x1c4];
    float ox, oy, oz;
    void FUN_000a1930(V3_a2de0 pos, int d);
    void FUN_000a2de0(int a, int b, int c, int d);
};
struct CChaseCamera_a2e60 {
    char pad0[0x1f4];
    unsigned a[6];
    char pad1[8];
    unsigned b214, b218;
    float b21c, b220;
    unsigned b224, b228, b22c, b230;
    char pad2[0x2cc - 0x234];
    unsigned c[6];
    char pad3[0x444 - 0x2e4];
    unsigned field444;
    float field448;
    unsigned field44c;
    char pad4[0x488 - 0x450];
    unsigned field488;
    void FUN_000a2cc0(unsigned, unsigned, unsigned, float, unsigned);
    void FUN_000a2de0(unsigned, unsigned, unsigned, unsigned);
    void FUN_000a2e60(unsigned arg, unsigned char flag);
};
struct Local_a2f30 {
    char pad[12];
};
struct Helper_a2f30 {
    bool Read_00035550(Local_a2f30*);
};
struct CChaseCamera_nv_a2f30 {
    void Apply_000a2e60(float, int);
};
extern float __cdecl GetVal_000a0450(Local_a2f30*);
extern float __cdecl Transform_000a02a0(float);
struct V3_a2f90 {
    float x, y, z;
};
hulk_freg __cdecl FUN_000a0450(V3_a2f90 *v);
class CChaseCamera_a2f90 {
public:
    char pad0[0x1b8];
    float baseX;            // 0x1b8
    char pad1bc[4];
    float baseZ;            // 0x1c0
    char pad1c4[0x350 - 0x1c4];
    int target;             // 0x350
    void FUN_000a2e60(float angle, int arg);
    void FUN_000a2f90(float x, int unused, float z, int arg);
};
struct V3_a5400 {
    float x, y, z;
};
V3_a5400 *__cdecl FUN_0009f8c0(V3_a5400 *out, float a, float b, float c);
void __cdecl FUN_000a04c0(V3_a5400 *dir, float *p1, float *p0, float *scratch);
struct Sampler_a5400 {
    bool FUN_000a2370(int a, float *dx, float *dy, char *flag);
};
class CChaseCamera_a5400 {
public:
    char pad0[0x194];
    float f194;
    float f198;
    float f19c;
    char pad1a0[0x1c4 - 0x1a0];
    float f1c4;
    float f1c8;
    float f1cc;
    char pad1d0[0x1e8 - 0x1d0];
    float f1e8;
    float f1ec;
    float f1f0;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    char pad214[0x32c - 0x214];
    Sampler_a5400 sampler;
    char pad32d[0x444 - 0x32d];
    float f444;
    unsigned f448;
    char pad44c[0x478 - 0x44c];
    float f478;
    float f47c;
    float f480;
    unsigned f484;
    float f488;

    void FUN_000a0dc0(int zero, float t, int arg);
    void FUN_000a0940(float t);
    void FUN_000a5400(int arg, int flagWord);
};
struct Vec3_a5a90 {
    float x;
    float y;
    float z;
    hulk_freg FUN_0022d110();
    void FUN_00067930(Vec3_a5a90 *other, float t);
};
struct Sweeper_a5a90 {
    void FUN_00035550(Vec3_a5a90 *out);
    char FUN_00038e30(Vec3_a5a90 *from, Vec3_a5a90 *to, float radius, int flag, Vec3_a5a90 *hit, Vec3_a5a90 *normal);
};
struct Frame_a5a90 {
    float f0;                // S+0
    float f4;                // S+4
    Vec3_a5a90 tmpA;         // S+8
    Vec3_a5a90 vB;           // S+20
    float f32;               // S+32
    Vec3_a5a90 d;            // S+36
    Vec3_a5a90 dir;          // S+48
    Vec3_a5a90 n;            // S+60
    Vec3_a5a90 hit;          // S+72
    Vec3_a5a90 pos;          // S+84
    Vec3_a5a90 saved;        // S+96
    Vec3_a5a90 q;            // S+108
    Vec3_a5a90 r;            // S+120
    Vec3_a5a90 nrm;          // S+132
};
Vec3_a5a90 *__cdecl FUN_0009f7d0(Vec3_a5a90 *out, Vec3_a5a90 *cur, Vec3_a5a90 *dir, float a, float b);
void __cdecl FUN_000a04c0(Vec3_a5a90 *v, float *o1, float *o2, float *o3);
struct Obj_a5a90 {
    char pad000[0x17c];
    Vec3_a5a90 v17c;
    char pad188[0x194 - 0x188];
    Vec3_a5a90 v194;
    char pad1a0[0x1c4 - 0x1a0];
    Vec3_a5a90 v1c4;
    Vec3_a5a90 v1d0;
    char pad1dc[0x244 - 0x1dc];
    char flagA;
    char flagB;
    char pad246[0x254 - 0x246];
    Vec3_a5a90 v254;
    char pad260[0x26c - 0x260];
    Vec3_a5a90 v26c;
    char pad278[0x31c - 0x278];
    char b31c;
    char pad31d[0x320 - 0x31d];
    int mode;
    char pad324[0x349 - 0x324];
    char b349;
    char pad34a[0x34c - 0x34a];
    float f34c;
    Sweeper_a5a90 *sweeper;
    char pad354[0x444 - 0x354];
    float f444;
    char pad448[0x468 - 0x448];
    float f468;
    char pad46c[0x488 - 0x46c];
    float f488;
    char pad48c[0x4a0 - 0x48c];
    Vec3_a5a90 v4a0;

    char FUN_000a2800(unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, float p6, float p7,
                      Vec3_a5a90 *pos, Vec3_a5a90 *outV, float *outF);
    void FUN_000a2cc0(float a, float b, float c, float d, int mode);
    void FUN_000a1930(Vec3_a5a90 v, int mode);
    char FUN_000a5a90(unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, char a6, float a7);
};
struct V3_a62c0 { float x, y, z; };
struct Target_a62c0 { char pad[0x1a64]; float f1a64; };
struct Sub_a62c0 { void FUN_00059a50(V3_a62c0* p); };
struct Holder_a62c0 { char pad[0x10]; Sub_a62c0* sub; char pad2[0x1a64 - 0x14]; float f1a64; };
class CChaseCamera_a62c0 {
public:
    V3_a62c0* FUN_000a92c0(V3_a62c0* out, int a, Holder_a62c0* b);
    void FUN_000a1b30(int a, int b, int c);
    void run(hulk_intptr a, Holder_a62c0* b);
    char p0[0x1b8];
    V3_a62c0 v1b8;
    V3_a62c0 v1c4;
    V3_a62c0 v1d0;
    V3_a62c0 v1dc;
    V3_a62c0 v1e8;
    char p1[0x23c - 0x1f4];
    float f23c;
    char p2[0x29c - 0x240];
    V3_a62c0 v29c;
    V3_a62c0 v2a8;
    V3_a62c0 v2b4;
    char p3[0x314 - 0x2c0];
    float f314;
    char p4[0x344 - 0x318];
    char c344;
    char p5[0x350 - 0x345];
    Holder_a62c0* h350;
    char p6[0x4a0 - 0x354];
    V3_a62c0 v4a0;
};
typedef unsigned __int64 Key_a74c0;
extern "C" void __cdecl FUN_00267830(char*, const char*, int);
struct Data_a74c0 { void FUN_00059a50(void*); };
struct Item_a74c0 { virtual void add(); virtual void release(); char pad[12]; Data_a74c0* data; const char* FUN_00036d00(); };
struct Manager_a74c0 { char pad[0x124]; Item_a74c0* fallback; Item_a74c0* FUN_00024280(Key_a74c0); };
struct Context { char pad[0x20]; Manager_a74c0* manager; };
struct CChaseCamera_a74c0 { char pad0[0x1b8]; char value[0x18c]; unsigned char dirty; unsigned char isDefault; char pad1[10]; Item_a74c0* item; char name[64]; void FUN_000a62c0(Context*,Item_a74c0*); void target(Context*,const char*); };


// 0x0009f760 FUN_0009f760 (27 B): matches/0x0009f760.cpp
// sym: ?FUN_0009f760@fn_f69c308d@@YANM@Z
double __cdecl FUN_0009f760(float x) {
    return exp(x);
}


// 0x0009f790 FUN_0009f790 (59 B): matches/0x0009f790.cpp
// sym: _FUN_0009f790
// data: ratio = DAT_003f3f10, scaleOut = DAT_00405578
extern "C" void FUN_0009f790(float a, float b, float* c, float* d) {
    double t = tan(a * 0.008726646f) * DAT_003f3f10;
    *c = (float)(atan(b * t) * DAT_00405578);
    *d = (float)(atan(t) * DAT_00405578);
}


// 0x0009f7d0 FUN_0009f7d0 (183 B): matches/0x0009f7d0.cpp
// sym: ?Func@fn_f69c308d@@YA?AUVec3_9f7d0@1@PBU21@0MM@Z
Vec3_9f7d0 Func(const Vec3_9f7d0* a, const Vec3_9f7d0* b, float t, float tau) {
    hulk_freg f = 1.0f;
    if (tau != 0.0f) {
        f = 1.0f - (hulk_freg)exp((double)(-(t / tau)));
    }
    Vec3_9f7d0 r;
    r.x = (b->x - a->x) * f + a->x;
    r.y = (b->y - a->y) * f + a->y;
    r.z = (b->z - a->z) * f + a->z;
    if (r.IsSmall_0022d330()) {
        r.z = 0.0f;
        r.y = 0.0f;
        r.x = 0.0f;
    }
    return r;
}


// 0x0009f8c0 FUN_0009f8c0 (69 B): matches/0x0009f8c0.cpp
// sym: ?FUN_0009f8c0@fn_f69c308d@@YAPAMPAMMMM@Z
// data: rad = DAT_003f32b8
float* FUN_0009f8c0(float* out, volatile float a, volatile float b, float r) {
    hulk_freg aa = a * DAT_003f32b8;
    hulk_freg bb = b * DAT_003f32b8;
    a = (hulk_freg)cos(bb);
    out[0] = (float)(sin(aa) * a * r);
    out[1] = (float)(sin(bb) * r);
    out[2] = (float)(cos(aa) * a * r);
    return out;
}


// 0x0009f910 FUN_0009f910 (237 B): matches/0x0009f910.cpp
// sym: ?FUN_0009f910@fn_f69c308d@@YAXHPAMPAI@Z
void __cdecl FUN_0009f910(int count, float* keys, unsigned int* values) {
    int gap = 1;
    int limit = count / 9;
    while (gap <= limit)
        gap = gap * 3 + 1;
    while (gap > 0) {
        for (int i = gap; i < count; ++i) {
            float key = keys[i];
            unsigned int value = values[i];
            int j = i;
            while (j >= gap && key < keys[j - gap]) {
                keys[j] = keys[j - gap];
                values[j] = values[j - gap];
                j -= gap;
            }
            keys[j] = key;
            values[j] = value;
        }
        gap /= 3;
    }
}


// 0x0009fa00 FUN_0009fa00 (111 B): matches/0x0009fa00.cpp
// sym: _FUN_0009fa00
// data: gFlag_9fa00 = DAT_004e222c
extern "C" bool FUN_0009fa00() {
    Mgr_9fa00* m = hulk_at_004dd700->sys->Get();
    int i = 0;
    do {
        St_9fa00 s;
        Dev_9fa00* d = ((Dev_9fa00 *)((owners::C_af3a0 *)m)->FUN_000af3a0(i));
        ((owners::C_af0f0 *)d)->FUN_000af0f0((St_9fa00 *)(&s));
        if (s.a == 1 || s.c == 1 || s.b == 1 || s.d == 1) {
            DAT_004e222c = 1;
            return true;
        }
        i++;
    } while (i < 1);
    return false;
}


// 0x0009fa70 FUN_0009fa70 (36 B): matches/0x0009fa70.cpp
// sym: _FUN_0009fa70
extern "C" int FUN_0009fa70(int* a, int* b, int* c) {
    int x = *a;
    int y = *b;
    if (x >= y && x <= *c)
        return x;
    {
        int z = *c;
        if (x > z)
            return z;
        return y;
    }
}


// 0x0009faa0 FUN_0009faa0 (117 B): equivalent/0x0009faa0.cpp
// sym: ?FUN_0009faa0@fn_f69c308d@@YAMMMMM@Z @4c478b5f1506 @w9a87bf26124e
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 4/4; Wine build: input 71 differs only past the double exponent range (80-bit st0 overflow), HEAD failed at input 0)
// FUN_0009faa0 @ 0x0009faa0
hulk_freg __cdecl FUN_0009faa0(float from, float to, float a, float b)
{
    // the original keeps t and r in st0: t = 1 - exp(-(a/b)) and r = from + (to - from) * t are never rounded;
    // only the dead-zone test uses r stored to float (fst), and the unrounded r is returned
    hulk_freg t;
    if (b == 0.0f)
        t = 1.0f;
    else
        t = 1.0f - exp(-(a / b));
    hulk_freg r = from + (to - from) * t;
    float rf = (float)r;
    if (rf < 0.0f ? -rf <= 1e-05f : rf <= 1e-05f)
        return 0.0f;
    return r;
}


// 0x0009fb20 FUN_0009fb20 (176 B): equivalent/0x0009fb20.cpp
// sym: ?FUN_0009fb20@fn_f69c308d@@YAMMMMMM@Z @6fc3bd4bac6a @w2c171d510baf
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// FUN_0009fb20 @ 0x0009fb20
hulk_freg __cdecl FUN_0009fb20(float a, float b, float c, float dt, float tau) {
    double factor = 1.0;
    if (tau != 0.0f) factor = 1.0 - exp(-(double)dt / tau);
    double second = 0.0;
    if (dt != 0.0f) {
        double q = factor / dt;     // the listing divides first, then multiplies by tau
        second = 1.0 - q * tau;
    }
    double result = ((double)b - a) * factor + ((double)c - b) * second + a;
    union { float f; unsigned int u; } magnitude;
    magnitude.f = (float)result;
    magnitude.u &= 0x7fffffff;
    if (magnitude.f <= 1e-5f) return 0.0f;
    return result;                  // st(0) unrounded
}


// 0x0009fbd0 FUN_0009fbd0 (381 B): equivalent/0x0009fbd0.cpp
// sym: ?FUN_0009fbd0@fn_f69c308d@@YAPAUVec3_9fbd0@1@PAU21@000MM@Z @3c2309f93188 @w47957c490a00
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 9/10, incomplete)
// FUN_0009fbd0 @ 0x0009fbd0
Vec3_9fbd0* FUN_0009fbd0(Vec3_9fbd0* out, Vec3_9fbd0* a, Vec3_9fbd0* b, Vec3_9fbd0* c, float tau, float dt)
{
    volatile float k = 1.0f;
    if (dt != 0.0f)
        k = (float)(1.0 - exp(-(double)(tau / dt)));
    double m = 0.0;
    if (tau != 0.0f)
        m = 1.0 - (double)k / tau * dt;
    double px = ((double)b->x - a->x) * k + a->x;
    double py = ((double)b->y - a->y) * k + a->y;
    volatile float pz = (float)(((double)b->z - a->z) * k + a->z);
    double dx = (double)c->x - b->x;
    volatile float dy = c->y - b->y;
    volatile float dz = c->z - b->z;
    volatile float ox = (float)(dx * m + px);
    volatile float oy = (float)(dy * m + py);
    volatile float oz = (float)(dz * m + pz);
    float ax = ox < 0.0f ? -ox : ox;
    float ay = oy < 0.0f ? -oy : oy;
    float az = oz < 0.0f ? -oz : oz;
    if (ax <= 1e-05f && ay <= 1e-05f && az <= 1e-05f) {
        ox = 0.0f;
        oy = 0.0f;
        oz = 0.0f;
    }
    out->x = ox;
    out->y = oy;
    out->z = oz;
    return out;
}


// 0x0009fd50 FUN_0009fd50 (402 B): equivalent/0x0009fd50.cpp
// sym: ?FUN_0009fd50@fn_f69c308d@@YAPAUV3_9fd50@1@PAU21@00M@Z @3f52729c4db3 @wdae88b7f85a6
// STATUS: equivalent (tools/equiv.py level 3: 20027 inputs, branch coverage 7/8, incomplete)
// FUN_0009fd50 @ 0x0009fd50
V3_9fd50 *FUN_0009fd50(V3_9fd50 *out, V3_9fd50 *a, V3_9fd50 *b, float t)
{
    hulk_freg dot = a->x * b->x + b->z * a->z;
    dot = dot + b->y * a->y;
    if (!(dot >= -1.0f))
        dot = -1.0f;
    else if (!(dot <= 1.0f))
        dot = 1.0f;

    hulk_freg gap = dot - 1.0f;
    if (gap < 0.0f)
        gap = -gap;

    if (gap <= 1e-05f) {
        volatile float tx = (b->x - a->x) * t;
        volatile float ty = (b->y - a->y) * t;
        volatile float dz = b->z - a->z;
        hulk_freg rz = dz * t + a->z;
        hulk_freg ry = ty + a->y;
        hulk_freg rx = tx + a->x;
        out->x = rx;
        out->y = ry;
        out->z = rz;
        return out;
    }

    volatile float py = dot * a->y;
    volatile float pz = dot * a->z;
    V3_9fd50 perp;
    perp.x = b->x - dot * a->x;
    perp.y = b->y - py;
    perp.z = b->z - pz;
    perp.FUN_0022d110();

    double theta = FUN_00018a20(dot) * t;
    double s = sin(theta);
    double c = cos(theta);
    // sx, sy, cy, cz (and py, pz above) are rounded frame copies in the original; sz stays in a register
    volatile float sx = (float)(perp.x * s);
    volatile float sy = (float)(perp.y * s);
    double sz = perp.z * s;
    volatile float cy = (float)(c * a->y);
    volatile float cz = (float)(c * a->z);
    out->x = (float)(c * a->x + sx);
    out->y = cy + sy;
    out->z = (float)(cz + sz);
    return out;
}


// 0x0009fef0 FUN_0009fef0 (206 B): equivalent/0x0009fef0.cpp
// sym: ?FUN_0009fef0@fn_f69c308d@@YAPAUVec_9fef0@1@PAU21@PBU21@1M@Z @7256b1ff1261 @wa5184b4dcab9
// STATUS: equivalent (tools/equiv.py level 3: 19772 inputs, branch coverage 0/0)
// FUN_0009fef0 @ 0x0009fef0
// FUN_0009fef0 @ 0x0009fef0
Vec_9fef0* __cdecl FUN_0009fef0(Vec_9fef0* out, const Vec_9fef0* axis, const Vec_9fef0* v, float degrees) {
    double dot = (double)axis->x*v->x + (double)v->z*axis->z + (double)v->y*axis->y;
    volatile float px = (float)(dot*axis->x);
    volatile float py = (float)(dot*axis->y);
    Vec_9fef0 tangent;
    tangent.x = v->x-px;
    tangent.y = v->y-py;
    tangent.z = (float)(v->z-dot*axis->z);
    tangent.FUN_0022d110();
    double angle = degrees*0.01745329238474369f;
    double s = sin(angle);
    volatile float sx = (float)(tangent.x*s);
    volatile float sy = (float)(tangent.y*s);
    double sz = tangent.z*s;
    double c = cos(angle);
    double cx = c*axis->x;
    volatile float cy = (float)(c*axis->y);
    volatile float cz = (float)(c*axis->z);
    out->x = (float)(cx+sx);
    out->y = cy+sy;
    out->z = (float)(cz+sz);
    return out;
}


// 0x0009ffc0 FUN_0009ffc0 (68 B): matches/0x0009ffc0.cpp
// sym: _FUN_0009ffc0
extern "C" char FUN_0009ffc0(float a, float b, float c, float* out) {
    float v = (float)(sin(b * 0.017453292519943295f) / a * c);
    if (v > 1.0f)
        return 0;
    *out = asinf(v) * 57.295776f;
    return 1;
}


// 0x000a0010 FUN_000a0010 (208 B): matches/0x000a0010.cpp
// sym: ?FUN_000a0010@fn_f69c308d@@YAHMMHPAM@Z
// data: Zero_a0010 = DAT_003f32e0
int __cdecl FUN_000a0010(float length, float spacing, int maxCount, float* out) {
    if (length < DAT_003f32e0 || maxCount <= 0 || spacing <= DAT_003f32e0)
        return -1;
    int count;
    hulk_freg step;
    if (length == DAT_003f32e0 || maxCount == 1) {
        count = 1;
        step = DAT_003f32e0;
    } else {
        int local4 = (int)(length / spacing) + 1;
        int local8 = 2;
        count = FUN_0009fa70(&local4, &local8, &maxCount);
        step = length / (float)(count - 1);
    }
    for (int i = 0; i < count; ++i)
        out[i] = (float)i * step;
    return count;
}

} // namespace fn_f69c308d

// 0x000a00e0 FUN_000a00e0 (444 B): equivalent/0x000a00e0.cpp [wrapped: conflict: FUN_0009f760]
// sym: ?FUN_000a00e0@fn_000a00e0@@YAMMMMMM@Z @11abeeca2f0e @w827c384403cc
namespace fn_000a00e0 {
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 18/18)
// FUN_000a00e0 @ 0x000a00e0
float FUN_000186b0(float *p0, float *p1, float *p2);
float FUN_0009f760(float x);

struct Frame_a00e0 { float L0, t, q, vc; };

hulk_freg FUN_000a00e0(float a, float b, float c, float d, float e)
{
    Frame_a00e0 f;
    f.L0 = b - a;
    if (f.L0 == 0.0f || c == 0.0f || d == 0.0f)
        return a;

    f.vc = a;
    double vcd = a; // the register copy of f.vc (unrounded)
    unsigned bits = *(unsigned *)&f.L0 & 0x7fffffff;
    f.t = *(float *)&bits - e;
        if (f.t > 0.0f) {
        f.q = f.t / c;
        bool lim = !(f.q < d);
        if (!lim) {
            f.vc = -f.t;
        } else {
            f.t = c * d;
            f.vc = -(c * d);
        }
        f.t = FUN_000186b0(&f.L0, &f.vc, &f.t);
        if (lim)
            f.q = d;
        vcd = f.t + a;
        f.vc = vcd;
        f.L0 = f.L0 - f.t;
        d = d - f.q;
    }
    double x = vcd; // returned unrounded (st0) by the original
    if (e > 0.0f && d > 0.0f) {
        unsigned bits2 = *(unsigned *)&f.L0 & 0x7fffffff;
        if (!(e * 0.001f >= *(float *)&bits2)) {
            float tmp = -(c / e * d);
            x = (1.0f - FUN_0009f760(tmp)) * f.L0 + f.vc;
        } else {
            x = b;
        }
    }
    volatile float xs = x;
    unsigned bits3 = *(unsigned *)&xs & 0x7fffffff;
    if (!(*(float *)&bits3 <= 1e-5f))
        return x;
    return 0.0f;
}
} // namespace fn_000a00e0

namespace fn_f69c308d {

// 0x000a02a0 FUN_000a02a0 (141 B): matches/0x000a02a0.cpp
// sym: ?FUN_000a02a0@fn_f69c308d@@YAMM@Z
hulk_freg FUN_000a02a0(float a) {
    if (!__isnan((double)a)) {
        hulk_freg b = a;
        *(unsigned*)&b &= 0x7fffffff;
        if (!(b > 3600.0f)) {
            while (a < -180.0f)
                a += 360.0f;
            while (a >= 180.0f)
                a -= 360.0f;
            return a;
        }
    }
    return 0.0f;
}


// 0x000a0330 FUN_000a0330 (141 B): equivalent/0x000a0330.cpp
// sym: ?FUN_000a0330@fn_f69c308d@@YAMM@Z @16990ec69ec7 @wc71e94a0eaad
// STATUS: equivalent (tools/equiv.py level 3: 20016 inputs, branch coverage 12/12)
// FUN_000a0330 @ 0x000a0330
// Wrap an angle in degrees into [0, 360). NaN and values beyond +-3600 give 0.
hulk_freg FUN_000a0330(float degrees)
{
    if (_isnan(degrees)) {
        return 0.0f;
    }
    FloatBits_a0330 magnitude;
    magnitude.f = degrees;
    magnitude.u &= 0x7fffffff;
    if (magnitude.f > 3600.0f) {
        return 0.0f;
    }
    while (degrees < 0.0f) {
        degrees += 360.0f;
    }
    while (degrees >= 360.0f) {
        degrees -= 360.0f;
    }
    return degrees;
}


// 0x000a03c0 FUN_000a03c0 (136 B): equivalent/0x000a03c0.cpp
// sym: ?Clamp3@fn_f69c308d@@YAMMMM@Z @65e49c49363d @w1371a037bb90
// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 4/4)
// FUN_000a03c0 @ 0x000a03c0
hulk_freg Clamp3(float a, float b, float c) {
 float span = FUN_000a0330(c - b);
 if (FUN_000a0330(a - b) > span) {
  if (FUN_000a02a0(a - (span * (*(float*)&DAT_003f32f4) + b)) > (*(float*)&DAT_003f32e0))
   return FUN_000a02a0(c);
  return FUN_000a02a0(b);
 }
 return FUN_000a02a0(a);
}


// 0x000a0450 FUN_000a0450 (99 B): matches/0x000a0450.cpp
// sym: ?Fn@fn_f69c308d@@YAMPAM@Z
// data: gZero_a0450 = DAT_003f32e0
hulk_freg __cdecl Fn(float* p) {
    Bits_a0450 a;
    a.f = p[0];
    a.u &= 0x7fffffffUL;
    if (a.f <= DAT_00405564) {
        Bits_a0450 b;
        b.f = p[2];
        b.u &= 0x7fffffffUL;
        if (b.f <= DAT_00405564)
            return DAT_003f32e0;
    }
    return Wrap_000a02a0((float)(atan2(p[0], p[2]) * DAT_003f3ef4));
}


// 0x000a04c0 FUN_000a04c0 (231 B): equivalent/0x000a04c0.cpp
// sym: ?FUN_000a04c0@fn_f69c308d@@YAXPAUVec_a04c0@1@PAM11@Z @61cf7bd5dd05 @w83bea55dc013
// STATUS: equivalent (tools/equiv.py level 3: 20017 inputs, branch coverage 6/6)
// FUN_000a04c0 @ 0x000a04c0
void __cdecl FUN_000a04c0(Vec_a04c0* v, float* yaw, float* pitch, float* length) {
 float len = (float)sqrt((double)v->x*v->x + (double)v->y*v->y + (double)v->z*v->z);
 *length = len;
 if (len < 0.00001f) { *yaw=0.0f; *pitch=0.0f; return; }
 union Bits { float f; unsigned int u; } a,b;
 a.f=v->x; a.u &= 0x7fffffff;
 b.f=v->z; b.u &= 0x7fffffff;
 if (a.f <= 0.00001f && b.f <= 0.00001f) *yaw=0.0f;
 else *yaw=FUN_000a02a0((float)(atan2(v->x,v->z)*57.2957764f));
 *pitch=FUN_000189c0(v->y/len)*57.2957764f;
}


// 0x000a05b0 FUN_000a05b0 (89 B): matches/0x000a05b0.cpp
// sym: ?Target@fn_f69c308d@@YAMMMHHH@Z
hulk_freg __cdecl Target(float p1, float p2, int p3, int p4, int p5) {
    float f1 = FnA_000a02a0(p2 - p1);
    float f2 = FnA_000a02a0(p1);
    return FnC_000a02a0(FnB_000a00e0(f2, f2 + f1, p3, p4, p5));
}

} // namespace fn_f69c308d

// 0x000a06d0 FUN_000a06d0 (475 B): equivalent/0x000a06d0.cpp
// sym: ?FUN_000a06d0@Obj000a06d0_a06d0@owners@@QAEPAU12@PBU12@@Z @e7ab13963fd2 @wff719a589748
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000a06d0 @ 0x000a06d0
owners::Obj000a06d0_a06d0* owners::Obj000a06d0_a06d0::FUN_000a06d0(const owners::Obj000a06d0_a06d0* src)
{
    for (int i = 0; i < 0x35; i++) {
        words[i] = src->words[i];
    }
    b0 = src->b0;
    b1 = src->b1;
    return this;
}

// 0x000a08b0 CChaseCamera::vfunc_28 (5 B): not yet verified
// 0x000a08c0 CChaseCamera::vfunc_29 (5 B): not yet verified

// 0x000a08d0 FUN_000a08d0 (3 B): matches/0x000a08d0.cpp [wrapped: conflict: CAgent]
// sym: ?vfunc_7@CAgent@fn_000a08d0@@UAEXH@Z
namespace fn_000a08d0 {
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};

void CAgent::vfunc_7(int a) {
    (void)a;
}
} // namespace fn_000a08d0


// 0x000a08e0 FUN_000a08e0 (3 B): matches/0x000a08e0.cpp [wrapped: conflict: CAgent]
// sym: ?vfunc_7@CAgent@fn_000a08e0@@UAEXH@Z
namespace fn_000a08e0 {
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};

void CAgent::vfunc_7(int a) {
    (void)a;
}
} // namespace fn_000a08e0

namespace fn_f69c308d {

// 0x000a0940 FUN_000a0940 (376 B): equivalent/0x000a0940.cpp
// sym: ?FUN_000a0940@Mover_a0940@fn_f69c308d@@QAEXM@Z @1bd4bd37a33c @w6ed0cf7553c2
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 10/10)
// FUN_000a0940 @ 0x000a0940
void Mover_a0940::FUN_000a0940(float dt)
{
    Vec3_a0940 out;
    if (_isnan(pos.x) || _isnan(pos.y) || _isnan(pos.z)) {
        pos.x = base444 + off1c4;
        pos.y = off1c8;
        pos.zi = off1cci;
        out.zi = off1cci;
    }
    prev.xi = pos.xi;
    prev.yi = pos.yi;
    prev.zi = pos.zi;
    if (pos.y > hi) {
        pos.yi = hii;
        clamped = 1;
    } else if (pos.y < lo) {
        pos.yi = loi;
        clamped = 1;
    }
    f17c.xi = pos.xi;
    f17c.yi = pos.yi;
    f17c.zi = pos.zi;
    Vec3_a0940* r = FUN_0009fbd0(&out, &v260, &v254, &f17c, tau, dt);
    pos.xi = r->xi;
    pos.yi = r->yi;
    pos.zi = r->zi;
    saved.xi = pos.xi;
    saved.yi = pos.yi;
    saved.zi = pos.zi;
}


// 0x000a0ac0 FUN_000a0ac0 (166 B): matches/0x000a0ac0.cpp
// sym: ?FUN_000a0ac0@Aim_a0ac0@fn_f69c308d@@QAEXMM@Z
// FUN_000a0ac0 @ 0x000a0ac0
void Aim_a0ac0::FUN_000a0ac0(float pitch0, float yaw)
{
    Vec3_a0ac0 d;
    float len;
    d.x = target.x - origin.x;
    d.y = target.y - origin.y;
    d.z = target.z - origin.z;
    FUN_000a04c0(&d, &pitchBase, &yawBase, &len);
    float pitch = FUN_000a02a0(pitch0 - pitchBase);
    pitchOut = pitch;
    float v = (yaw - yawBase) - yawBias;
    yawOut = v;
    s300 = pitch;
    s2fc = pitch;
    s2f0 = v;
    s2ec = v;
}

} // namespace fn_f69c308d

// 0x000a0b70 FUN_000a0b70 (7 B): matches/0x000a0b70.cpp
// sym: ?FUN_000a0b70@C_a0b70@owners@@QAEIXZ
hulk_uintptr owners::C_a0b70::FUN_000a0b70() {
    return value;
}


// 0x000a0b80 CChaseCamera::vfunc_30 (41 B): matches/0x000a0b80.cpp
// sym: ?vfunc_30@CChaseCamera@@UAEXH@Z
void CChaseCamera::vfunc_30(int x) {
    *(int*)((char*)this + 0x32c) = 0;
    *(int*)((char*)this + 0x330) = 0;
    *(int*)((char*)this + 0x338) = 0;
    *(int*)((char*)this + 0x334) = 0;
    *(int*)((char*)this + 0x33c) = 0;
    *((char*)this + 0x340) = 0;
}

namespace fn_f69c308d {

// 0x000a0bb0 FUN_000a0bb0 (7 B): matches/0x000a0bb0.cpp
// sym: ?FUN_000a0bb0@fn_f69c308d@@YIMPAVCChaseCamera_a0bb0@1@@Z
float __fastcall FUN_000a0bb0(CChaseCamera_a0bb0* self) {
    return self->value;
}

} // namespace fn_f69c308d

// 0x000a0bc0 FUN_000a0bc0 (13 B): matches/0x000a0bc0.cpp
// sym: ?FUN_000a0bc0@Target_a0bc0@owners@@QAEXH@Z
void owners::Target_a0bc0::FUN_000a0bc0(int x) {
    value = x;
}

namespace fn_f69c308d {

// 0x000a0bd0 FUN_000a0bd0 (7 B): matches/0x000a0bd0.cpp
// sym: ?FUN_000a0bd0@fn_f69c308d@@YIMPAVC_a0bd0@1@@Z
float __fastcall FUN_000a0bd0(C_a0bd0* self) {
    return self->value;
}

} // namespace fn_f69c308d

// 0x000a0be0 CChaseCamera::vfunc_38 (29 B): matches/0x000a0be0.cpp
// sym: ?vfunc_38@CChaseCamera@@UAEXPAXH0@Z
void CChaseCamera::vfunc_38(void* __p0, int p3, void* __p2) { void * p4 = (void *)__p2;

    if (this->f_350 != 0 && p3 == this->f_350)
        this->f_3cc = (hulk_intptr)p4;
}

namespace fn_f69c308d {

// 0x000a0c00 FUN_000a0c00 (7 B): matches/0x000a0c00.cpp
// sym: ?FUN_000a0c00@fn_f69c308d@@YIMPAUObj_a0c00@1@@Z
float __fastcall FUN_000a0c00(Obj_a0c00* self) {
    return self->value;
}

} // namespace fn_f69c308d

// 0x000a0c10 FUN_000a0c10 (13 B): matches/0x000a0c10.cpp
// sym: ?FUN_000a0c10@Thing_a0c10@owners@@QAEXH@Z
void owners::Thing_a0c10::FUN_000a0c10(int x) {
    value = x;
}

namespace fn_f69c308d {

// 0x000a0c20 FUN_000a0c20 (7 B): matches/0x000a0c20.cpp
// sym: ?target@fn_f69c308d@@YIMPAVObj_a0c20@1@@Z
float __fastcall target(Obj_a0c20* self) {
    return self->value;
}

} // namespace fn_f69c308d

// 0x000a0c30 FUN_000a0c30 (13 B): matches/0x000a0c30.cpp
// sym: ?FUN_000a0c30@C_a0c30@owners@@QAEXH@Z
void owners::C_a0c30::FUN_000a0c30(int x) {
    value = x;
}

namespace fn_f69c308d {

// 0x000a0c40 FUN_000a0c40 (65 B): matches/0x000a0c40.cpp
// sym: ?f@CChaseCamera_a0c40@fn_f69c308d@@QAEXH@Z
void CChaseCamera_a0c40::f(int x) {
    reset = 0;
    if (state == 7) {
        prev = value;
        state = x;
    } else {
        prev = state;
        state = x;
    }
}


// 0x000a0d40 FUN_000a0d40 (24 B): matches/0x000a0d40.cpp
// sym: ?FUN_000a0d40@fn_f69c308d@@YAXPAPAVA_a0d40@1@@Z
// Same code shape as 0x000187d0 (propagated; names are from that function)
void FUN_000a0d40(A_a0d40** p) {
    if (*p) {
        (*p)->g();
        *p = 0;
    }
}


// 0x000a0d80 FUN_000a0d80 (49 B): matches/0x000a0d80.cpp
// sym: ??1CChaseCamera_a0d80@fn_f69c308d@@QAE@XZ
CChaseCamera_a0d80::~CChaseCamera_a0d80() {
    vptr = hulk_at_00405604;
    _ReadWriteBarrier();
    if (m350) {
        m350->Release();
        m350 = 0;
    }
    Fin29_000a91b0();
    Fin_000a9620();
}


// 0x000a0dc0 FUN_000a0dc0 (382 B): equivalent/0x000a0dc0.cpp
// sym: ?FUN_000a0dc0@Body_a0dc0@fn_f69c308d@@QAEXMMM@Z @174c8b2d25ee @wc85db1d6017a
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 6/6)
// FUN_000a0dc0 @ 0x000a0dc0
void Body_a0dc0::FUN_000a0dc0(float a1, float a2, float a3)
{
    float eps = 1e-05f;
    float absA3 = a3 < 0.0f ? -a3 : a3;
    if (!(absA3 <= eps)) {
        float len = (float)sqrt(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
        hulk_freg inv = 1.0f / a3;
        hulk_freg t = inv * a1;
        if (inv * len > 20.0f)
            t = a1 / len * 20.0f;
        float m = limit * 0.6f;
        if (len * t > m)
            t = m / len;
        vel.x = vel.x * t;
        vel.y = vel.y * t;
        vel.z = vel.z * t;
        prev = vel;
        Vec3_a0dc0 tmp;
        Vec3_a0dc0 *r = FUN_0009fbd0(&tmp, &refA, &refB, &prev, a3, a2);
        vel.x = r->x;
        vel.y = r->y;
        vel.z = r->z;
        pos.x = vel.x + pos.x;
        pos.y = vel.y + pos.y;
        pos.z = vel.z + pos.z;
    }
}

} // namespace fn_f69c308d

// 0x000a0f40 CChaseCamera::vfunc_27 (93 B): equivalent/0x000a0f40.cpp [wrapped: conflict: CChaseCamera]
// sym: ?vfunc_27@CChaseCamera@fn_000a0f40@@QAEXPAUVector3@2@@Z @d26f23136b67 @we496b6a6919d
namespace fn_000a0f40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// CChaseCamera::vfunc_27 @ 0x000a0f40
struct Vector3 { float x,y,z; }; struct CameraData { char pad[0x20]; Vector3 direction; char pad2[4]; Vector3 position; }; class CChaseCamera { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual CameraData* vfunc_14(); char pad[0x23c]; float distance; void vfunc_27(Vector3* result); }; void CChaseCamera::vfunc_27(Vector3* result) { CameraData* first = vfunc_14(); float x = distance * first->direction.x; float y = distance * first->direction.y; float z = distance * first->direction.z; CameraData* second = vfunc_14(); result->x = x + second->position.x; result->y = y + second->position.y; result->z = z + second->position.z; }
} // namespace fn_000a0f40


// 0x000a0fa0 CChaseCamera::vfunc_32 (60 B): matches/0x000a0fa0.cpp
// sym: ?vfunc_32@CChaseCamera@@UAEXHH@Z
void CChaseCamera::vfunc_32(int a, int b) {
    Ref* q = (*(Ref *volatile *)&this->f_350);
    if (q && q->a == a && q->b == b) {
        Ref* r = (*(Ref *volatile *)&this->f_350);
        if (r) {
            r->release();
            (*(Ref *volatile *)&this->f_350) = 0;
        }
    }
}

namespace fn_f69c308d {

// 0x000a0fe0 FUN_000a0fe0 (261 B): equivalent/0x000a0fe0.cpp
// sym: ?update@CChaseCamera_a0fe0@fn_f69c308d@@QAEXM@Z @b645e2fe9403 @w670340d6050d
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 2/2)
// FUN_000a0fe0 @ 0x000a0fe0
void CChaseCamera_a0fe0::update(float v) {
 if (v == value) return;
 value=v;
 FUN_000a9090(v);
 volatile float tx=(float)tan(horizontal * 0.008726646192371845f);
 angleX=(float)(atan(0.5f * tx)*114.591552734375f);
 angleZ=(float)(atan(0.24f * tx)*114.591552734375f);
 volatile float ty=(float)tan(vertical * 0.008726646192371845f);
 angleY=(float)(atan(0.45f * ty)*114.591552734375f);
 float distance=v8();
 x=tx*distance; y=ty*distance; z=distance;
 // the original reloads the stored (rounded) x, y, z for the radius: volatile reads keep MSVC from reusing its registers
 float rz=*(volatile float*)&z, ry=*(volatile float*)&y, rx=*(volatile float*)&x;
 radius=(float)(sqrt((hulk_freg)rx*rx+(hulk_freg)ry*ry+(hulk_freg)rz*rz)+0.1f);
}

} // namespace fn_f69c308d

// 0x000a10f0 CChaseCamera::vfunc_33 (1031 B): equivalent/0x000a10f0.cpp [wrapped: conflict: CChaseCamera]
// sym: ?vfunc_33@CChaseCamera@fn_000a10f0@@UAEXHPAUOwner_a10f0@2@H@Z @934aa8800140 @w3f2f15de7ae1
namespace fn_000a10f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3116 inputs, branch coverage 44/44)
// CChaseCamera::vfunc_33 @ 0x000a10f0
struct Vec3_a10f0 {
    float x, y, z;
    void FUN_00011250(Vec3_a10f0 *out, const Vec3_a10f0 *other);
};

struct Owner_a10f0 {
    char pad000[0x338];
    Owner_a10f0 *other;
};

class CChaseCamera {
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
    virtual void vfunc_33(int a1, Owner_a10f0 *who, int event);
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    char pad04[0x194 - 4];
    Vec3_a10f0 pos;
    char pad1a0[0x1b8 - 0x1a0];
    Vec3_a10f0 savedA;
    Vec3_a10f0 lookAt;
    char pad1d0[0x1e8 - 0x1d0];
    Vec3_a10f0 savedB;
    char pad1f4[0x23c - 0x1f4];
    float f23c;
    char pad240[0x320 - 0x240];
    int mode;
    char pad324[0x350 - 0x324];
    Owner_a10f0 *owner;
    char pad354[0x3b4 - 0x354];
    int state;
    int state2;
    float outA;
    float outB;
    float outC;
    char pad3c8[0x3d0 - 0x3c8];
    Vec3_a10f0 snapA;
    Vec3_a10f0 snapB;
    Vec3_a10f0 snapPos;
    char pad3f4[0x400 - 0x3f4];
    int f400;
    int f404;
    int f408;
    float f40c;
    unsigned int mask;
    char pad414[0x478 - 0x414];
    float out2A;
    float out2B;
    float out2C;
    int f484;
    int field488;
    void FUN_000a0c40(int v);
};

void __cdecl FUN_000a04c0(Vec3_a10f0 *delta, float *a, float *b, float *c);

void CChaseCamera::vfunc_33(int a1, Owner_a10f0 *who, int event)
{
    if (owner == 0)
        return;
    if (who != owner) {
        Owner_a10f0 *o2 = owner->other;
        if (o2 == 0 || who != o2)
            return;
    }
    unsigned int bit = 1 << event;
    mask = mask | bit;
    int m = mode;
    if (m == 6)
        return;
    if ((unsigned int)event > 7)
        return;
    Vec3_a10f0 delta;
    switch (event) {
    case 0:
    case 5:
        if (m == 4)
            return;
        FUN_000a0c40(4);
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &out2A, &out2B, &out2C);
        return;
    case 1:
        if (m == 1)
            return;
        if (!(savedA.y - f23c > 5.0f))
            return;
        FUN_000a0c40(1);
        state = 2;
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        field488 = 0;
        return;
    case 2:
        if (m == 3) {
            if (f40c == 0.0f)
                f40c = 0.6f;
            return;
        }
        if (m == 1)
            return;
        FUN_000a0c40(1);
        state2 = 0;
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        field488 = 0;
        return;
    case 3:
        if (m == 2 || m == 7)
            return;
        if (m != 3)
            field488 = 0;
        FUN_000a0c40(2);
        f408 = 0;
        f404 = 0;
        f400 = 0;
        return;
    case 4:
        f40c = 0.0f;
        if (m == 3)
            return;
        field488 = 0;
        FUN_000a0c40(3);
        return;
    case 7:
        if (m == 1) {
            if (state == 0)
                return;
            state = 0;
            snapB = savedB;
            return;
        }
        FUN_000a0c40(1);
        state = 0;
        state2 = 0;
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        pos.FUN_00011250(&delta, &lookAt);
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        return;
    }
}
} // namespace fn_000a10f0


// 0x000a1520 CChaseCamera::vfunc_34 (565 B): equivalent/0x000a1520.cpp [wrapped: conflict: CChaseCamera]
// sym: ?vfunc_34@CChaseCamera@fn_000a1520@@UAEXHHMMM@Z @e3ba9ec81a00 @w34315c5dba35
namespace fn_000a1520 {
// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 22/22)
// CChaseCamera::vfunc_34 @ 0x000a1520

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double atan2(double y, double x);
#endif


struct Vec3_a1520 {
    float x, y, z;
};

class CChaseCamera {
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
    virtual void vfunc_34(int a1, int a2, float a3, float a4, float a5);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    char pad04[0x194 - 4];
    Vec3_a1520 pos;
    char pad1a0[0x1b8 - 0x1a0];
    Vec3_a1520 savedA;
    Vec3_a1520 lookAt;
    char pad1d0[0x1e8 - 0x1d0];
    Vec3_a1520 savedB;
    char pad1f4[0x320 - 0x1f4];
    int mode;
    char pad324[0x350 - 0x324];
    int owner;
    char pad354[0x3b4 - 0x354];
    int state;
    int state2;
    float outA;
    float outB;
    float outC;
    float value;
    char pad3cc[0x3d0 - 0x3cc];
    Vec3_a1520 snapA;
    Vec3_a1520 snapB;
    Vec3_a1520 snapPos;
    char pad3f4[0x40c - 0x3f4];
    int field40c;
    char pad410[0x440 - 0x410];
    float limit;
    char pad444[0x488 - 0x444];
    int field488;
    char pad48c[0x4bb - 0x48c];
    unsigned char flag4bb;
    void FUN_000a0c40(int v);
};

void __cdecl FUN_000a04c0(Vec3_a1520 *delta, float *a, float *b, float *c);

void CChaseCamera::vfunc_34(int a1, int a2, float a3, float a4, float a5)
{
    if (owner == 0 || a2 != owner) {
        return;
    }
    double inv = 1.0f / a5;
    float ratio = a4 * inv;
    float energy = inv * a4 * a4 * 0.5f;
    float angle = atan2(a4, a3) * 57.2957764f;

    if (mode == 3 && (ratio < 0.5f || angle < 60.0f)) {
        FUN_000a0c40(1);
        state = 2;
        state2 = 0;
        snapA = savedA;
        snapB = savedB;
        snapPos = pos;
        Vec3_a1520 delta;
        delta.x = pos.x - lookAt.x;
        delta.y = pos.y - lookAt.y;
        delta.z = pos.z - lookAt.z;
        FUN_000a04c0(&delta, &outA, &outB, &outC);
        field40c = 0;
        field488 = 0;
        if (angle < 60.0f) {
            flag4bb = 1;
        }
        return;
    }

    if (mode == 0 && ratio < 0.5f && 0.9f * limit > energy && angle > 70.0f) {
        state = 0;
        value = a5;
        return;
    }
    if (angle < 80.0f) {
        state = 2;
    } else {
        state = 1;
    }
    value = a5;
}
} // namespace fn_000a1520

namespace fn_f69c308d {

// 0x000a1760 FUN_000a1760 (455 B): equivalent/0x000a1760.cpp
// sym: ?Update@Mover_a1760@fn_f69c308d@@QAEXMM@Z @2aa1cda4c2c1 @wdd69fe09868e
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2; Wine build 601 inputs, 2/2)
// FUN_000a1760 @ 0x000a1760
void Mover_a1760::Update(float a1, float a2) {
    float px, py, pz;
    if (f394 <= 0.0f) {
        px = f3a0;
        py = f3a8;
        *(int*)&pz = *(int*)&f3b0;
        f478 = f3a0;
        f47c = f3a8;
        f480 = *(int*)&f3b0;
        f484 = f448;
        f394 = 0.0f;
        f320 = f328;
    } else {
        // x87: the original keeps 1 - t/T unrounded in st(1) for (2 - u) * u; only w is stored
        hulk_freg u = 1.0f - f394 / f398;
        float w = (2.0f - u) * u;
        px = FUN_000a02a0(f3a0 - f39c) * w + f39c;
        py = (f3a8 - f3a4) * w + f3a4;
        pz = (f3b0 - f3ac) * w + f3ac;
        f394 = f394 - a2;
    }
    Vec3_a1760 t;
    Vec3_a1760* r = FUN_0009f8c0(&t, px, py, pz);
    f194 = r->x + f1c4;
    f198 = r->y + f1c8;
    f19c = r->z + f1cc;
    FUN_000a0dc0((*(float*)&DAT_0049ec78), DAT_0049ec7c, a2);
    FUN_000a0940((*(float*)&DAT_0049ec80));
    Vec3_a1760 d;
    d.x = f1e8 - f194;
    d.y = f1ec - f198;
    d.z = f1f0 - f19c;
    FUN_000a04c0(&d, &f210, &f20c, &a2);
}


// 0x000a1930 FUN_000a1930 (508 B): equivalent/0x000a1930.cpp
// sym: ?FUN_000a1930@Mover_a1930@fn_f69c308d@@QAEXUV3_a1930@2@H@Z @8a32cd771eb9 @wa6df9e9ceb54
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 8/8)
// FUN_000a1930 @ 0x000a1930
void Mover_a1930::FUN_000a1930(V3_a1930 pos, int newMode)
{
    int m = mode;
    if (m == 7)
        m = f328;
    prevMode = m;
    mode = newMode;
    f394 = 0;
    b.f18c = pos.y;
    b.f190 = pos.z;
    b.f188 = pos.x;
    b.f17c = pos.x;
    b.f180 = b.f18c;
    b.f184 = b.f190;
    b.pos.x = pos.x;
    b.pos.y = b.f180;
    b.pos.z = b.f184;
    b.f194 = pos.x;
    b.f198 = b.pos.y;
    b.f19c = b.pos.z;
    if (mode == 1) {
        pos.x = b.f194 - b.f1c4;
        pos.y = b.f198 - b.f1c8;
        pos.z = b.f19c - b.f1cc;
        FUN_000a04c0(&pos, &f3bc, &f3c0, &f3c4);
    }
    pos.x = b.f1e8 - b.f194;
    pos.y = b.f1ec - b.f198;
    pos.z = b.f1f0 - b.f19c;
    float* scratch = (float*)&newMode;
    FUN_000a04c0(&pos, &b.f210, &b.f20c, scratch);
    b.f220 = f448;
    b.f21c = f448;
    b.f228 = 0;
    b.f224 = 0;
    b.f218 = 0;
    b.f214 = 0;
    b.f230 = 0;
    b.f22c = 0;
    ((Block_a1930 *)((owners::Obj000a06d0_a06d0 *)&f248)->FUN_000a06d0((const owners::Obj000a06d0_a06d0 *)(const Block_a1930 *)(&b)));
    f490 = 0;
    f4ac = 0;
    f4b0 = 0;
    Holder_a1930* holder = DAT_004dd700->game->holder;
    if (holder) {
        Target_a1930* t = holder->inner->FUN_000fdc30();
        if (t) {
            v6(scratch, &pos);
            World* world = DAT_004dd700;
            float f8 = v8();
            void* mat = v14();
            t->FUN_000fd8a0(world, mat, newMode, f8);
        }
    }
}


// 0x000a1b30 FUN_000a1b30 (354 B): equivalent/0x000a1b30.cpp
// sym: ?FUN_000a1b30@Smoother@fn_f69c308d@@QAEXPAUOwner_a1b30@2@M_N@Z @0098808b04a9 @wb99888763580
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 23/24, incomplete)
// FUN_000a1b30 @ 0x000a1b30
void Smoother::FUN_000a1b30(Owner_a1b30 *owner, float dt, bool snap)
{
    if (snap)
        timer = 0.0f;

    if (active) {
        int n = owner->counter->FUN_00026e30(20.0f, list, 6);
        if (locked || (n > 0 && (nearA != 0 || nearB != 0 || count >= 3))) {
            timer = 3.0f;
        } else {
            timer = timer - dt;
            if (timer < 0.0f)
                timer = 0.0f;
        }
    } else {
        timer = 0.0f;
    }

    float target = base;
    if (timer > 0.0f)
        target = DAT_0049eca4 * base;

    if (snap) {
        value = target;
    } else if (!(target == value)) {
        value = FUN_0009faa0(value, target, dt, (*(float*)&DAT_0049ec8c));
        union { float f; unsigned int u; } d;
        d.f = value - target;
        d.u &= 0x7fffffff;
        if (d.f <= 0.00001f)
            value = target;
    }
    ratio = (value - base) / base * 10.0f;
}


// 0x000a1ca0 FUN_000a1ca0 (1074 B): equivalent/0x000a1ca0.cpp
// sym: ?FUN_000a1ca0@CChaseCamera_a1ca0@fn_f69c308d@@QAEXPAUOwner_a1ca0@2@M@Z @57a7bfe627eb @we67a6b9a321a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// FUN_000a1ca0 @ 0x000a1ca0
void CChaseCamera_a1ca0::FUN_000a1ca0(Owner_a1ca0 *owner, float dt)
{
    struct Frame {
        V3_a1ca0 tmp1;
        V3_a1ca0 tmp2;
    } fr;

    dt234.f = dt;
    stats->fighter->FUN_00059a50(&v1b8);
    f23c = stats->f1a64;
    f23c.f = (f23c.f < -1000.0f) ? -1000.0f : f23c.f;

    Stats_a1ca0 *st = stats;
    v1c4 = *FUN_000a92c0(&fr.tmp1, owner, st);

    Bits_a1ca0 ab;
    ab.f = dt;
    ab.u &= 0x7fffffff;
    if (!(ab.f <= 0.00001f)) {
        double inv = 1.0f / dt;
        volatile V3_a1ca0 *d0 = &v1d0;
        volatile V3_a1ca0 *d1 = &v1dc;
        d0->x = v1c4.x - v29c.x;
        d0->y = v1c4.y - v29c.y;
        d0->z = v1c4.z - v29c.z;
        d0->x = inv * d0->x;
        d0->y = inv * d0->y;
        d0->z = inv * d0->z;
        d1->x = d0->x - v2a8.x;
        d1->y = d0->y - v2a8.y;
        d1->z = d0->z - v2a8.z;
        d1->x = inv * d1->x;
        d1->y = inv * d1->y;
        d1->z = inv * d1->z;
    }

    b345 = (stats == owner->f20->stats);
    v1e8 = v1c4;
    b347 = 0;
    b348 = 0;
    if (b345) {
        v200.x = v1c4.x - v29c.x;
        v200.y = v1c4.y - v29c.y;
        v200.z = v1c4.z - v29c.z;
        if (stats->f338 != 0)
            b347 = 1;
        if (((*(unsigned int*)&DAT_004dd9f8) & 1) == 0) {
            (*(unsigned int*)&DAT_004dd9f8) |= 1;
            (*(unsigned __int64*)&DAT_004dd9f0) = FUN_0027b020("gorilla_gorilla");
        }
        Node *n = ((Node *)((owners::C_35ef0 *)stats)->FUN_00035ef0((hulk_intptr)0));
        if (n != 0 && n->info->id == (*(unsigned __int64*)&DAT_004dd9f0))
            b348 = 1;
    } else {
        v200.z = 0.0f;
        v200.y = 0.0f;
        v200.x = 0.0f;
    }

    f21c = f448;
    f224 = 0;
    f214 = 0;
    f22c = 0;
    v194 = *(V3_a1ca0 *)(getTarget() + 0x30);
    f238 = 0.0f;
    if (stats->FUN_00035550(&fr.tmp2))
        f238 = FUN_000a0450(&fr.tmp2);
    FUN_000a1b30(owner, dt, false);

    if (f458 != 0.0f) {
        float nv = dt * f458 + f450;
        if ((f458 > 0.0f && nv >= f454) || (f458 < 0.0f && nv < f454)) {
            nv = f454;
            f458 = 0.0f;
        }
        FUN_000a0fe0(nv);
    }
    if (f488 > 0.0f) {
        double r = f488 - dt;
        f488 = r;
        if (r < 0.0)
            f488 = 0.0f;
    }
    if (f34c > 0.0f) {
        double r = f34c - dt;
        f34c = r;
        if (r < 0.0)
            f34c = 0.0f;
    }
}

} // namespace fn_f69c308d

// 0x000a2100 FUN_000a2100 (612 B): equivalent/0x000a2100.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_000a2100@Axis_a2100@fn_000a2100@@QAEXPAUOwner_a2100@2@DMMM@Z @5b1059a3c948 @w6fffa9e71430
namespace fn_000a2100 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 26/26)
// FUN_000a2100 @ 0x000a2100
// FUN_000a2100 @ 0x000a2100
// Stick/axis tracker: samples a 0x43-dword input record, keeps two axis values (a dead zone resets them to the
// defaults passed in), and ramps a charge value `c` towards 1 / -1 / 0 depending on whether the axis keeps its
// direction.

struct Sample_a2100 {
    unsigned pad0[0x1e];
    unsigned a;          // +0x78
    unsigned b;          // +0x7c
    unsigned pad1[0x17];
    unsigned c;          // +0xdc
    unsigned d;          // +0xe0
    unsigned pad2[10];
};

struct Source_a2100 {
    void FUN_000b3660(Sample_a2100 *dst);
};

struct Table_a2100 {
};

struct Owner_a2100 {
    unsigned pad;
    Table_a2100 *table;
};

union Word_a2100 {
    unsigned u;
    float f;
};

static float Abs_a2100(float v)
{
    Word_a2100 w;
    w.f = v;
    w.u &= 0x7fffffff;
    return w.f;
}

class Axis_a2100 {
public:
    unsigned x;
    unsigned y;
    Word_a2100 ax;
    Word_a2100 ay;
    volatile float charge;
    char valid;

    void FUN_000a2100(Owner_a2100 *owner, char enable, float dt, float defX, float defY);
};

void Axis_a2100::FUN_000a2100(Owner_a2100 *owner, char enable, float dt, float defX, float defY)
{
    if (!enable) {
        x = 0;
        y = 0;
        ay.u = 0;
        ax.u = 0;
        charge = 0;
        valid = 0;
        return;
    }

    float oldX = ax.f;
    Sample_a2100 s;
    ((Source_a2100 *)((owners::C_b3d20 *)(owner->table))->FUN_000b3d20(0))->FUN_000b3660(&s);

    x = s.a;
    y = s.b;
    ax.u = s.c;
    ay.u = s.d;
    if (!DAT_004dd83a)
        ax.f = *(volatile float *)&s.c * -1.0f;
    if (DAT_004dd83b)
        ay.f = *(volatile float *)&s.d * -1.0f;

    valid = 1;
    if (Abs_a2100(ax.f) <= 0.01f && Abs_a2100(ay.f) <= 0.01f) {
        ax.u = *(unsigned *)&defX;
        ay.u = *(unsigned *)&defY;
        valid = 0;
    }

    if (Abs_a2100(ax.f) >= 0.9f && oldX * ax.f > 0.0f) {
        if (ax.f > 0.0f) {
            charge = dt + charge;
            if (charge < 1.0f) {
            } else {
                charge = 1.0f;
            }
        } else {
            charge = charge - dt;
            if (charge < -1.0f)
                charge = -1.0f;
        }
    } else {
        if (charge >= 0.0f) {
            charge = charge - dt * 10.0f;
            if (charge < 0.0f)
                charge = 0.0f;
        } else {
            charge = dt * 10.0f + charge;
            if (charge < 0.0f) {
            } else {
                charge = 0.0f;
            }
        }
    }
}
} // namespace fn_000a2100


// 0x000a2370 FUN_000a2370 (177 B): matches/0x000a2370.cpp
// sym: ?FUN_000a2370@Obj_a2370@owners@@QAEEMPAM0PAE@Z
unsigned char owners::Obj_a2370::FUN_000a2370(float scale, float* out1, float* out2, unsigned char* outflag) {
    *out1 = 0.0f;
    *out2 = 0.0f;
    union {
        float f;
        unsigned int i;
    } x;
    x.f = a;
    x.i &= 0x7fffffff;
    unsigned char r = 0;
    if (x.f > 0.0f || c != 0.0f) {
        r = 1;
        *out1 = (c + c + x.f * a) * scale * 100.0f;
    }
    union {
        float f;
        unsigned int i;
    } y;
    y.f = b;
    y.i &= 0x7fffffff;
    if (x.f * 0.4f < y.f) {
        r = 1;
        *out2 = y.f * b * scale * 150.0f;
    }
    *outflag = flag;
    return r;
}


// 0x000a2430 FUN_000a2430 (881 B): equivalent/0x000a2430.cpp [wrapped: conflict: CChaseCamera; World]
// sym: ??0CChaseCamera@fn_000a2430@@QAE@XZ @1f76a6302932 @w56672965a486
namespace fn_000a2430 {
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_000a2430 @ 0x000a2430
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

struct ResourceName_a2430 {
    int word;
    void FUN_0027b040(const char *name);
};

class __declspec(novtable) CGameCamera_a2430 {
public:
    virtual void v0();
    char pad04[4];
    ResourceName_a2430 name;
    char pad0c[0xd0 - 0xc];
    int mode;
    float f0d4;
    char padd8[0x170 - 0xd8];
    CGameCamera_a2430 *FUN_000a9400();
    CGameCamera_a2430() { FUN_000a9400(); }
};


struct Sub248 {
    char pad[0xd8];
    void FUN_000a06d0(const void *p);
};

struct Stage_a2430 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Level_a2430 {
    char pad[0x80];
    Stage_a2430 stage;
};

struct Window_a2430 {
    Level_a2430 *FUN_00086310();
};

struct World {
    char pad[0x54];
    Window_a2430 *window;
};


class CChaseCamera : public CGameCamera_a2430 {
public:
    virtual void v0();
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    int f230;
    char pad234[0x4];
    int f238;
    int f23c;
    float f240;
    unsigned char f244;
    unsigned char f245;
    char pad246[0x2];
    Sub248 sub248;
    int f320;
    int f324;
    int f328;
    int f32c;
    int f330;
    int f334;
    int f338;
    int f33c;
    unsigned char f340;
    char pad341[0x3];
    unsigned char f344;
    unsigned char f345;
    unsigned char f346;
    unsigned char f347;
    unsigned char f348;
    unsigned char f349;
    char pad34a[0x2];
    int f34c;
    int f350;
    unsigned char f354;
    char pad355[0x3f];
    int f394;
    char pad398[0x1c];
    int f3b4;
    int f3b8;
    int f3bc;
    int f3c0;
    float f3c4;
    float f3c8;
    float f3cc;
    char pad3d0[0x3c];
    int f40c;
    int f410;
    int f414;
    char pad418[0xc];
    int f424;
    int f428;
    int f42c;
    int f430;
    int f434;
    int f438;
    int f43c;
    float f440;
    float f444;
    int f448;
    float f44c;
    int f450;
    float f454;
    int f458;
    char pad45c[0x1c];
    int f478;
    int f47c;
    float f480;
    int f484;
    int f488;
    char pad48c[0x4];
    unsigned char f490;
    char pad491[0x7];
    float f498;
    float f49c;
    int f4a0;
    int f4a4;
    int f4a8;
    int f4ac;
    int f4b0;
    int f4b4;
    unsigned char f4b8;
    unsigned char f4b9;
    unsigned char f4ba;
    unsigned char f4bb;
    CChaseCamera();
    void FUN_000a0fe0(float v);
};

CChaseCamera::CChaseCamera()
{
    f320 = 0;
    f324 = 0;
    f328 = 0;
    f32c = 0;
    f330 = 0;
    f338 = 0;
    f334 = 0;
    f33c = 0;
    f340 = 0;
    f344 = 0;
    f345 = 0;
    f346 = 0;
    f347 = 0;
    f348 = 0;
    f349 = 0;
    f34c = 0;
    f350 = 0;
    f394 = 0;
    f3b4 = 0;
    f3b8 = 0;
    f3bc = 0;
    f3c0 = 0;
    f40c = 0;
    f410 = 0;
    f414 = 0;
    f43c = 0;
    f448 = 0;
    f478 = 0;
    f47c = 0;
    f484 = 0;
    f488 = 0;
    f490 = 0;
    f498 = 3.4028235e+38f;
    f49c = -3.4028235e+38f;
    f3c8 = 50.0f;
    f3cc = 50.0f;
    f44c = (*(float*)&DAT_0049ec58);
    f3c4 = 10.0f;
    f440 = 10.0f;
    f444 = 10.0f;
    f480 = 10.0f;
    f4a0 = 0;
    f4a4 = 0;
    f4a8 = 0;
    f4ac = 0;
    f4b0 = 0;
    f4b4 = 0;
    f4b8 = 0;
    f4b9 = 0;
    f4ba = 0;
    f4bb = 0;
    f19c = 0;
    f198 = 0;
    f194 = 0;
    f178 = 0;
    f174 = 0;
    f170 = 0;
    f184 = 0;
    f180 = 0;
    f17c = 0;
    f190 = 0;
    f18c = 0;
    f188 = 0;
    f1a8 = 0;
    f1a4 = 0;
    f1a0 = 0;
    f1b4 = 0;
    f1b0 = 0;
    f1ac = 0;
    f1c0 = 0;
    f1bc = 0;
    f1b8 = 0;
    f1cc = 0;
    f1c8 = 0;
    f1c4 = 0;
    f1d8 = 0;
    f1d4 = 0;
    f1d0 = 0;
    f1e4 = 0;
    f1e0 = 0;
    f1dc = 0;
    f1f0 = 0;
    f1ec = 0;
    f1e8 = 0;
    f208 = 0;
    f204 = 0;
    f200 = 0;
    f1fc = 0;
    f1f8 = 0;
    f1f4 = 0;
    f20c = 0;
    f210 = 0;
    f218 = 0;
    f214 = 0;
    f220 = 0;
    f21c = 0;
    f228 = 0;
    f224 = 0;
    f230 = 0;
    f22c = 0;
    f238 = 0;
    f23c = 0;
    f240 = f444;
    f244 = 0;
    f245 = 0;
    sub248.FUN_000a06d0(&f170);
    f454 = f0d4;
    f450 = 0;
    FUN_000a0fe0(f0d4);
    f458 = 0;
    f354 = 0;
    mode = 0;
    name.FUN_0027b040((*(const char**)&DAT_0049ec40));
    f424 = 0;
    f428 = 0;
    f42c = 0;
    f430 = 0;
    f434 = 0;
    f438 = 0;
    World *g = DAT_004dd700;
    if (g != 0) {
        Level_a2430 *lv = g->window->FUN_00086310();
        if (lv != 0) {
            Stage_a2430 *st = &lv->stage;
            if (st->FUN_00088fa0() == 10) {
                if (st->FUN_00088fb0() == 0x2a)
                    f44c = 20.0f;
            }
        }
    }
}
} // namespace fn_000a2430
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f69c308d {

// 0x000a27b0 CChaseCamera::vfunc_2 (70 B): matches/0x000a27b0.cpp
// sym: ?f2@CChaseCamera_a27b0@fn_f69c308d@@QAEPAV12@E@Z
CChaseCamera_a27b0* CChaseCamera_a27b0::f2(unsigned char flags) {
    vptr = ((void**)DAT_00405604);
    _ReadWriteBarrier();
    if (m350) {
        m350->Release();
        m350 = 0;
    }
    Cam29_000a91b0();
    Fin_000a9620();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f69c308d

// 0x000a2800 FUN_000a2800 (1113 B): equivalent/0x000a2800.cpp [wrapped: conflict: FUN_000a02a0; FUN_000a0330; Target]
// sym: ?FUN_000a2800@Target@fn_000a2800@@QAE_NMMMMMMMHPAM0@Z @f6012fe30722 @w995ce258d361
namespace fn_000a2800 {
// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 38/40, incomplete)
// FUN_000a2800 @ 0x000a2800
// FUN_000a2800 @ 0x000a2800: search sample directions around a target for the best visible point


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


extern float __cdecl FUN_000a0330(float);
extern float __cdecl FUN_000a02a0(float);
extern int __cdecl FUN_000a0010(float range, float step, int max, float *out);
extern void __cdecl FUN_000a04c0(float *v, float *yaw, float *pitch, float *len);
extern void __cdecl FUN_0009f910(int n, float *keys, int *vals);
extern float *__cdecl FUN_0009f8c0(float *out, float a, float b, float radius);

struct Caster {
    bool FUN_00038e30(int a, float *p, float t, int one, float *o1, float *o2);
};

struct Frame {
    float dist;        // 0x0c
    float best;        // 0x10
    float q[3];        // 0x14
    float b[3];        // 0x20
    union {
        float tmp2c;   // 0x2c
        unsigned tmp2cbits;
    };
    float arr30[4];    // 0x30
    union {
        float len;     // 0x40
        int r;
    };
    int total;         // 0x44
    float pitch;       // 0x48
    float cspill;      // 0x4c
    float yaw;         // 0x50
    float o2[3];       // 0x54
    float o1[3];       // 0x60
    float arr6c[8];    // 0x6c
    float sp[3];       // 0x8c
    int idx[32];       // 0x98
    float cost[32];    // 0x118
};

class Target {
public:
    char pad0[0x194];
    float t0, t1, t2;      // 0x194
    char pad1a0[0x1c4 - 0x1a0];
    float c0, c1, c2;      // 0x1c4
    char pad1d0[0x350 - 0x1d0];
    Caster *caster;        // 0x350
    char pad354[0x468 - 0x354];
    float scale;           // 0x468
    bool FUN_000a2800(float a0, float a1, float a2, float a3, float a4, float a5, float a6, int a7, float *a8, float *a9);
};

bool Target::FUN_000a2800(float a0, float a1, float a2, float a3, float a4, float a5, float a6, int a7, float *a8, float *a9)
{
    Frame f;
    int i, k;
    f.dist = FUN_000a0330(a1 - a0);
    if ((f.dist == 0.0f && a0 != a1) || f.dist > 315.0f)
        f.dist = 315.0f;
    int n = FUN_000a0010(f.dist, 30.0f, 8, f.arr6c);
    for (i = 0; i < n; i++)
        f.arr6c[i] = FUN_000a02a0(a0 + f.arr6c[i]);
    int m = FUN_000a0010(a4 - a3, 20.0f, 4, f.arr30);
    for (i = 0; i < m - 3; i += 4) {
        f.arr30[i] = a3 + f.arr30[i];
        f.arr30[i + 1] = a3 + f.arr30[i + 1];
        f.arr30[i + 2] = a3 + f.arr30[i + 2];
        f.arr30[i + 3] = a3 + f.arr30[i + 3];
    }
    for (; i < m; i++)
        f.arr30[i] = a3 + f.arr30[i];
    if (n <= 0)
        return false;
    if (m <= 0)
        return false;
    f.b[0] = t0 - c0;
    f.b[1] = t1 - c1;
    f.b[2] = t2 - c2;
    FUN_000a04c0(f.b, &f.yaw, &f.pitch, &f.len);
    f.total = m * n;
    for (k = 0; k < f.total; k++) {
        int q = k / m;
        f.r = k % m;
        f.cspill = FUN_000a02a0(f.arr6c[q] - f.yaw);
        f.tmp2cbits = *(unsigned *)&f.cspill & 0x7fffffff;
        f.best = f.arr30[f.r] - f.pitch;
        *(unsigned *)&f.best &= 0x7fffffff;
        f.tmp2c = f.best * 1.5f + f.tmp2c;
        if (a2 >= -180.0f) {
            f.dist = FUN_000a02a0(f.arr6c[q] - a2);
            *(unsigned *)&f.dist &= 0x7fffffff;
            f.cost[k] = f.dist + f.dist + f.tmp2c;
        } else {
            f.cost[k] = f.tmp2c;
        }
        f.idx[k] = k;
    }
    FUN_0009f910(f.total, f.cost, f.idx);
    f.best = 0.0f;
    f.b[0] = 0.0f;
    f.b[1] = 0.0f;
    f.b[2] = 0.0f;
    for (k = 0; k < f.total; k++) {
        f.dist = a6;
        int q = f.idx[k] / m;
        int r = f.idx[k] % m;
        float *p = FUN_0009f8c0(f.sp, f.arr6c[q], f.arr30[r], a6);
        f.q[0] = c0 + p[0];
        f.q[1] = p[1] + c1;
        f.q[2] = p[2] + c2;
        if (caster->FUN_00038e30(a7, f.q, (*(float*)&DAT_0049ecb0), 1, f.o1, f.o2)) {
            float sc = scale;
            f.q[0] = f.o2[0] * sc + f.o1[0];
            f.q[1] = f.o2[1] * sc + f.o1[1];
            f.q[2] = f.o2[2] * sc + f.o1[2];
            f.dist = (float)sqrt((double)((f.q[2] - c2) * (f.q[2] - c2) + (f.q[1] - c1) * (f.q[1] - c1) + (f.q[0] - c0) * (f.q[0] - c0)));
        }
        if (f.dist > f.best) {
            f.best = f.dist;
            f.b[0] = f.q[0];
            f.b[1] = f.q[1];
            f.b[2] = f.q[2];
            if (!(f.dist < a6))
                break;
        }
    }
    if (f.best < a5)
        return false;
    a8[0] = f.b[0];
    a8[1] = f.b[1];
    a8[2] = f.b[2];
    *a9 = f.best;
    return true;
}
} // namespace fn_000a2800

namespace fn_f69c308d {

// 0x000a2c60 FUN_000a2c60 (92 B): matches/0x000a2c60.cpp
// sym: ?Set@CChaseCamera_a2c60@fn_f69c308d@@QAEXMM@Z
// data: zero_a2c60 = DAT_003f32e0
void CChaseCamera_a2c60::Set(float value, float time) {
    target = value;
    speed = 0.0f;
    if (oldVal != value) {
        if (time <= DAT_003f32e0) {
            helper_000a0fe0(value);
            return;
        }
        speed = (value - oldVal) / time;
    }
}

} // namespace fn_f69c308d

// 0x000a2cc0 FUN_000a2cc0 (278 B): equivalent/0x000a2cc0.cpp [wrapped: conflict: FUN_000a02a0]
// sym: ?update@CChaseCamera_a2cc0@fn_000a2cc0@@QAEXMMMMH@Z @e71bf9b69f3c @we2db8b804e8c
namespace fn_000a2cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a2cc0 @ 0x000a2cc0
struct Vec3_a2cc0 { float x,y,z; };
void __cdecl FUN_000a04c0(Vec3_a2cc0*, float*, float*, float*);
float __cdecl FUN_000a02a0(float);
struct CChaseCamera_a2cc0 {
 char pad0[0x170]; Vec3_a2cc0 position; char pad1[0x1c4-0x17c]; Vec3_a2cc0 previous; char pad2[0x320-0x1d0];
 int state, savedState, nextState; char pad3[0x394-0x32c];
 float speed, targetSpeed, angle, targetAngle, elevation, targetElevation, distance, targetDistance;
 void update(float a, float b, float c, float speedValue, int next);
};
void CChaseCamera_a2cc0::update(float a,float b,float c,float speedValue,int next) {
 savedState = state == 7 ? nextState : state;
 state = 7;
 speed = 0.0f;
 Vec3_a2cc0 delta;
 delta.x = position.x - previous.x;
 delta.y = position.y - previous.y;
 delta.z = position.z - previous.z;
 FUN_000a04c0(&delta, &angle, &elevation, &distance);
 float normalized = FUN_000a02a0(a);
 targetAngle = normalized;
 float difference = normalized - angle;
 targetElevation = b;
 targetDistance = c;
 float magnitude = FUN_000a02a0(difference);
 union { float f; unsigned int u; } bits;
 bits.f = magnitude;
 bits.u &= 0x7fffffff;
 magnitude = bits.f;
 if (magnitude < 90.0f) targetSpeed = speedValue;
 else targetSpeed = magnitude * speedValue * 0.011111111f;
 speed = targetSpeed;
 nextState = next;
}
} // namespace fn_000a2cc0

namespace fn_f69c308d {

// 0x000a2de0 FUN_000a2de0 (116 B): equivalent/0x000a2de0.cpp
// sym: ?FUN_000a2de0@Obj_a2de0@fn_f69c308d@@QAEXHHHH@Z @7d9aea6b5cdb @w7dd8b675419e
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 0/0)
// FUN_000a2de0 @ 0x000a2de0
void Obj_a2de0::FUN_000a2de0(int a, int b, int c, int d)
{
    V3_a2de0 tmp;
    V3_a2de0 *r = FUN_0009f8c0(&tmp, a, b, c);
    V3_a2de0 p;
    p.x = r->x + ox;
    p.y = r->y + oy;
    p.z = r->z + oz;
    FUN_000a1930(p, d);
}


// 0x000a2e60 FUN_000a2e60 (200 B): matches/0x000a2e60.cpp
// sym: ?FUN_000a2e60@CChaseCamera_a2e60@fn_f69c308d@@QAEXIE@Z
void CChaseCamera_a2e60::FUN_000a2e60(unsigned arg, unsigned char flag) {
    if (flag)
        FUN_000a2cc0(arg, field44c, field444, (*(float*)&DAT_0049ec64), 0);
    else
        FUN_000a2de0(arg, field44c, field444, 0);
    for (int i = 5; i >= 0; --i)
        a[i] = 0;
    for (int j = 5; j >= 0; --j)
        c[j] = 0;
    float value = field448;
    b220 = value;
    b228 = 0;
    b224 = 0;
    b21c = value;
    b218 = 0;
    b214 = 0;
    b230 = 0;
    b22c = 0;
    field488 = 0;
}

} // namespace fn_f69c308d

// 0x000a2f30 FUN_000a2f30 (85 B): matches/0x000a2f30.cpp
// sym: ?FUN_000a2f30@CChaseCamera@@QAEXH@Z
void CChaseCamera::FUN_000a2f30(int arg) {
    Local_a2f30 local;
    if ((*(Helper_a2f30 * *)&this->f_350) && (*(Helper_a2f30 * *)&this->f_350)->Read_00035550(&local)) {
        float x = GetVal_000a0450(&local);
        x = Transform_000a02a0(x + 180.0f);
        ((CChaseCamera_nv_a2f30*)this)->Apply_000a2e60(x, arg);
    }
}

namespace fn_f69c308d {

// 0x000a2f90 FUN_000a2f90 (166 B): matches/0x000a2f90.cpp
// sym: ?FUN_000a2f90@CChaseCamera_a2f90@fn_f69c308d@@QAEXMHMH@Z
// FUN_000a2f90 @ 0x000a2f90
void CChaseCamera_a2f90::FUN_000a2f90(float x, int unused, float z, int arg)
{
    if (target == 0)
        return;
    V3_a2f90 d;
    d.y = 0.0f;
    d.x = x - baseX;
    volatile float *dz = &d.z;
    *dz = z - baseZ;
    float len = (float)sqrt(*dz * *dz + d.x * d.x);
    if (len < 0.01f)
        return;
    if (len > 10000.0f)
        return;
    x = FUN_000a02a0(FUN_000a0450(&d) + 180.0f);
    FUN_000a2e60(x, arg);
}

} // namespace fn_f69c308d

// 0x000a38c0 FUN_000a38c0 (2950 B): equivalent/0x000a38c0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?Update@CChaseCamera_a38c0@fn_000a38c0@@QAEXMM@Z @4fe3c43dd133 @we76e486943ef
namespace fn_000a38c0 {
// STATUS: equivalent (tools/equiv.py level 3: 20097 inputs, branch coverage 96/100, incomplete)
// FUN_000a38c0 @ 0x000a38c0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

struct V3_a38c0 {
    float x, y, z;
    hulk_freg FUN_000259c0();
    hulk_freg FUN_0022d110();
};

V3_a38c0 *__cdecl FUN_0009f8c0(V3_a38c0 *out, float yaw, float pitch, float scale);
hulk_freg __cdecl FUN_0009faa0(float cur, float target, float dt, float rate);
void __cdecl FUN_000a04c0(V3_a38c0 *dir, float *yaw, float *pitch, float *len);
hulk_freg __cdecl FUN_000a0450(V3_a38c0 *v);
hulk_freg __cdecl FUN_000a03c0(float v, float lo, float hi);
hulk_freg __cdecl FUN_000189c0(float v);
float __cdecl FUN_000186b0(float *v, float *lo, float *hi);
char __cdecl FUN_00018960(float a, float b, float eps);
hulk_freg __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);
hulk_freg __cdecl FUN_000a05b0(float a, float b, float c, float d, float e);

struct Input32c_a38c0 {
    char pad00[0x14];
};

struct Frame_a38c0 {
    float pitch;   // E-0x50
    float outB;    // E-0x4c
    float yaw;     // E-0x48
    float len;     // E-0x44
    float angC;    // E-0x40 (also inv)
    float angB;    // E-0x3c
    float angA;    // E-0x38
    float outA;    // E-0x34
    V3_a38c0 dv;         // E-0x30
    V3_a38c0 w;          // E-0x24
    V3_a38c0 u;          // E-0x18
    V3_a38c0 o;          // E-0x0c
};

class CChaseCamera_a38c0 {
public:
    char pad000[0x194];
    V3_a38c0 p194;
    char pad1a0[0x1b8 - 0x1a0];
    V3_a38c0 p1b8;
    V3_a38c0 p1c4;
    char pad1d0[0x1e8 - 0x1d0];
    V3_a38c0 p1e8;
    char pad1f4[0x204 - 0x1f4];
    float f204;
    char pad208[0x20c - 0x208];
    float f20c;
    float f210;
    char pad214[0x23c - 0x214];
    float f23c;
    char pad240[0x248 - 0x240];
    V3_a38c0 p248;
    char pad254[0x29c - 0x254];
    V3_a38c0 p29c;
    char pad2a8[0x32c - 0x2a8];
    Input32c_a38c0 in32c;
    char pad340[0x346 - 0x340];
    char b346;
    char pad347;
    char b348;
    char pad349[0x3b4 - 0x349];
    int state;
    float f3b8;
    float f3bc;
    float f3c0;
    float f3c4;
    float f3c8;
    float f3cc;
    V3_a38c0 p3d0;
    char pad3dc[0x3e0 - 0x3dc];
    float f3e0;
    char pad3e4[0x3f4 - 0x3e4];
    V3_a38c0 p3f4;
    char pad400[0x444 - 0x400];
    float f444;
    float f448;
    char pad44c[0x478 - 0x44c];
    float f478;
    float f47c;
    float f480;
    float f484;
    float f488;
    char pad48c[0x498 - 0x48c];
    float f498;
    float f49c;
    char pad4a0[0x4b4 - 0x4a0];
    float f4b4;
    char pad4b8[0x4bb - 0x4b8];
    char f4bb;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float a);
    void FUN_000a0ac0(float a, float b);
    void Update(float unused, float dt);
};

void CChaseCamera_a38c0::Update(float unused, float dt)
{
    Frame_a38c0 f;
    float dt0 = dt;

    f.dv.x = p1c4.x - p29c.x;
    f.dv.y = p1c4.y - p29c.y;
    f.dv.z = p1c4.z - p29c.z;
    f.yaw = 0.0f;
    f3b8 = dt + f3b8;
    switch (state) {
    case 0:
        f.yaw = DAT_0049ec74;
        break;
    case 1:
        f.yaw = DAT_0049ec74 * 0.5f;
        f204 = DAT_0049ec90 / f.yaw * dt + f204;
        break;
    case 2:
        f.yaw = DAT_0049ec74;
        f204 = DAT_0049ec90 / DAT_0049ec74 * dt - f204 * 0.75f;
        break;
    }
    FUN_000a0dc0(f.yaw, DAT_0049ec7c, dt0);

    if (f488 > 0.0f) {
        f.yaw = f478;
        f.pitch = f47c;
        f.len = f480;
    } else {
        f.len = f444;
        f.yaw = f3bc;
        f.pitch = f3c0;
        switch (state) {
        case 0: {
            f.dv.y = 0.0f;
            dt = f.dv.FUN_0022d110();
            f.w.x = p194.x - p1c4.x;
            f.w.y = 0.0f;
            f.w.z = p194.z - p1c4.z;
            f.w.FUN_0022d110();
            p194.x = p248.x;
            p194.y = p248.y;
            p194.z = p248.z;
            double k = f.w.x * f.dv.x;      // the projection length, once, in a register (double: MSVC spills it)
            k += f.w.y * f.dv.y;
            k += f.w.z * f.dv.z;
            k *= dt;
            p194.x = f.w.x * k + p194.x;
            p194.y = f.w.y * k + p194.y;
            p194.z = f.w.z * k + p194.z;
            // the original reloads the stored (rounded) components
            f.u.x = *(volatile float *)&p194.x - p1c4.x;
            f.u.y = *(volatile float *)&p194.y - p1c4.y;
            f.u.z = *(volatile float *)&p194.z - p1c4.z;
            FUN_000a04c0(&f.u, &f.yaw, &f.pitch, &f.len);
            f.pitch = FUN_000186b0(&f.pitch, &DAT_0049ec60, &DAT_0049ec5c);
            f3c0 = f.pitch;
            if (p3d0.y - 0.1f > p1b8.y)
                state = (b348 != 0) + 1;
            break;
        }
        case 1:
            if (f4b4 > 0.0f) {
                f.pitch = FUN_000186b0(&f3c0, &DAT_0049ec60, &DAT_0049ec5c);
            } else {
                p194.x = f.dv.x + p248.x;
                p194.y = f.dv.y + p248.y;
                f.o.z = f.dv.z + p248.z;
                p194.z = f.o.z;
                f.w.x = p194.x - p1c4.x;
                f.w.y = p194.y - p1c4.y;
                f.w.z = p194.z - p1c4.z;
                f.w.FUN_0022d110();
                f.outA = -1.0f;
                dt = 1.0f;
                f.pitch = FUN_000189c0(FUN_000186b0(&f.w.y, &f.outA, &dt)) * 57.2957764f;
                f.pitch = FUN_000186b0(&f.pitch, &DAT_0049ec60, &DAT_0049ec94);
            }
            break;
        case 2:
            if (AbsF(dt) > 1e-005f) {
                hulk_freg inv = 1.0f / dt;
                f.w.y = 0.0f;
                f.dv.x = f.dv.x * inv;
                f.dv.y = f.dv.y * inv;
                f.dv.z = f.dv.z * inv;
                f.w.x = p3d0.x - p1b8.x;
                f.w.z = p3d0.z - p1b8.z;
                if (f3b8 > 0.1f) {
                    if (f.w.FUN_000259c0() > 5.0f)
                        f.yaw = FUN_000a0450(&f.w);
                }
                if (f4bb && f3b8 < DAT_0049ecd8)
                    f.yaw = FUN_0009faa0(f3bc, f.yaw, dt0, DAT_0049ecd8);
                else
                    f4bb = 0;
                if (p3d0.y < f23c)
                    f.angA = p3d0.y;
                else
                    f.angA = f23c;
                f.outA = p1b8.y;
                if (f3c8 > 0.0f && f3cc > 0.0f) {
                    float sc = (f.dv.y < 0.0f) ? f3cc : f3c8;
                    f.outA = f.dv.y / sc + sqrt(((f.dv.y * (f.dv.y / sc)) * 0.5f + f.outA - f.angA) / f3cc * 2.0);
                    if (f.outA >= 0.0f) {
                        p3f4.x = p1b8.x;
                        p3f4.y = p1b8.y;
                        p3f4.z = p1b8.z;
                        ((owners::Vec3_11160 *)&p3f4)->FUN_00011160(f.outA, (const owners::Vec3_11160 *)(V3_a38c0 *)(&f.dv));
                        p3f4.y = f.angA;
                        f.outA = f.dv.FUN_000259c0();
                        if (!FUN_00018960(f.outA, 0.0f, 1e-005f)) {
                            f.angA = f.dv.y / f.outA;
                            f.angA = AbsF(f.angA);
                            if (f.angA < 0.95f) {
                                ((owners::Vec3_11250 *)&p1c4)->FUN_00011250((owners::Vec3_11250 *)(V3_a38c0 *)(&f.o), (owners::Vec3_11250 *)(V3_a38c0 *)(&p3f4));
                                FUN_000a04c0(&f.o, &f.outA, &f.angA, &f.angB);
                                f.yaw = FUN_000a03c0(f.yaw, f.outA - 45.0f, f.outA + 45.0f);
                                f.pitch = f.angA;
                            } else if (f.dv.y / f.outA < -0.985f) {      // the signed cosine, before the fabs
                                state = 1;
                            }
                            dt = dt0;
                        }
                        dt = dt0;
                    }
                }
            }
            if (f4b4 > 0.0f)
                f.pitch = FUN_000186b0(&f3c0, &DAT_0049ec60, &DAT_0049ec5c);
            else
                f.pitch = FUN_000186b0(&f.pitch, &DAT_0049ec60, &DAT_0049ec94);
            break;
        }
    }
    f.angC = 1.0f / f.len;

    dt = (f49c - p1c4.y) * f.angC;
    if (!(dt >= -1.0f && dt <= 1.0f))
        dt = (dt > 1.0f) ? 1.0f : -1.0f;
    f.angA = FUN_000189c0(dt) * 57.2957764f;

    dt = (f498 - p1c4.y) * f.angC;
    if (!(dt >= -0.94f && dt <= 1.0f))
        dt = (dt > 1.0f) ? 1.0f : -0.94f;
    f.angB = FUN_000189c0(dt) * 57.2957764f;

    dt = (f23c + 0.3f - p1c4.y) * f.angC;
    if (!(dt >= -1.0f && dt <= 1.0f))
        dt = (dt > 1.0f) ? 1.0f : -1.0f;
    f.angC = FUN_000189c0(dt) * 57.2957764f;

    if (!((char)((owners::Obj_a2370 *)&in32c)->FUN_000a2370(dt0, &f.outA, &f.outB, (unsigned char *)((char *)&dt))) && !(f488 > 0.0f)) {
        f3bc = FUN_000a05b0(f3bc, f.yaw, (*(float*)&DAT_0049ec44), dt0, 5.0f);
        if (f.pitch < f.angC)
            f.pitch = f.angC;
        if (f.pitch > f.angB) {
            f.pitch = f.angB;
            b346 = 1;
        } else if (f.pitch < f.angA) {
            f.pitch = f.angA;
            b346 = 1;
        }
        f3c0 = FUN_000a00e0(f3c0, f.pitch, (*(float*)&DAT_0049ec48), dt0, 5.0f);
        f3c4 = FUN_000a00e0(f3c4, f.len, DAT_0049ec54, dt0, 1.5f);
    } else {
        f3bc = f.outA + f3bc;
        f.outA = f.outB + f3c0;
        f3c0 = f.outA;
        if (f3c0 >= DAT_0049ec60 && f3c0 <= DAT_0049ec5c)
            f.outB = f.outA;
        else if (f3c0 > DAT_0049ec5c)
            f.outB = DAT_0049ec5c;
        else
            f.outB = DAT_0049ec60;
        if (f.outB < f.angC)
            f.outB = f.angC;
        if (f.outB > f.angB) {
            f.outB = f.angB;
            b346 = 1;
        } else if (f.outB < f.angA) {
            f.outB = f.angA;
            b346 = 1;
        }
        if (f.outA != f.outB)
            f3c0 = FUN_000a00e0(f.outA, f.outB, 240.0f, dt0, 0.0f);
        f47c = f3c0;
        f478 = f3bc;
        f480 = f3c4;
        if (*(char *)&dt)
            f488 = (*(float*)&DAT_0049ec98);
    }

    f484 = f448;
    V3_a38c0 *r = FUN_0009f8c0(&f.o, f3bc, f3c0, f3c4);
    p194.x = r->x + p1c4.x;
    p194.y = r->y + p1c4.y;
    f.o.z = r->z + p1c4.z;
    p194.z = f.o.z;
    FUN_000a0940((*(float*)&DAT_0049ec80));

    if (state == 0) {
        hulk_freg t = f3e0 - p1e8.y;
        if (t >= -10.0f) {
            if (t > 0.0f)
                t = 0.0f;
        } else {
            t = -10.0f;
        }
        f.w.x = p1e8.x;
        f.w.y = p1e8.y;
        f.w.z = p1e8.z;
        f.u.y = t + f.w.y - p194.y;
        f.u.x = f.w.x - p194.x;
        f.u.z = f.w.z - p194.z;
        FUN_000a04c0(&f.u, &f.outA, &dt, &f.angA);
        FUN_000a0ac0(f.outA, dt);
    } else {
        f.u.x = p1e8.x - p194.x;
        f.u.y = p1e8.y - p194.y;
        f.u.z = p1e8.z - p194.z;
        FUN_000a04c0(&f.u, &f210, &f20c, &dt);
    }
}
} // namespace fn_000a38c0


// 0x000a4450 FUN_000a4450 (1846 B): equivalent/0x000a4450.cpp [wrapped: conflict: FUN_00018a20; FUN_000a00e0; FUN_000a02a0]
// sym: ?FUN_000a4450@Ctl_a4450@fn_000a4450@@QAEXHM@Z @35f739e73c03 @w04a3d09e096c
namespace fn_000a4450 {
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 48/50, incomplete)
// FUN_000a4450 @ 0x000a4450


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double fabs(double);
#endif


struct V3_a4450 {
    float x, y, z;
    float FUN_0022d110();
};

struct Obj350_a4450 {
    void FUN_00035550(V3_a4450 *out);
};

struct Sub32c_a4450 {
    char pad[0x24];
    bool FUN_000a2370(float dt, float *a, float *b, char *flag);
};


V3_a4450 *__cdecl FUN_0009f8c0(V3_a4450 *out, float a, float b, float c);
V3_a4450 *__cdecl FUN_0009fef0(V3_a4450 *out, V3_a4450 *from, V3_a4450 *to, float maxAngle);
void __cdecl FUN_000a04c0(V3_a4450 *v, float *a, float *b, float *c);
float __cdecl FUN_000a0450(V3_a4450 *v);
float __cdecl FUN_000a02a0(float v);
float __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);
float __cdecl FUN_00018a20(float v);
bool __cdecl FUN_00018960(float a, float b, float c);
float __cdecl FUN_000186b0(float *v, float *lo, float *hi);

struct Frame_a4450 {
    char pad0[3];
    char flag;      // 0x03
    float f48;      // 0x04
    float f44;      // 0x08
    float f40;      // 0x0c
    V3_a4450 C;           // 0x10
    V3_a4450 A;           // 0x1c
    V3_a4450 B;           // 0x28
    V3_a4450 D;           // 0x34
    V3_a4450 F;           // 0x40
};

class Ctl_a4450 {
public:
    char pad0[0x194];
    float f194, f198, f19c;
    char pad1a0[0x1b8 - 0x1a0];
    float f1b8, f1bc, f1c0;
    float f1c4, f1c8, f1cc;
    char pad1d0[0x1e8 - 0x1d0];
    float f1e8, f1ec, f1f0;
    char pad1f4[0x20c - 0x1f4];
    float f20c, f210;
    char pad214[0x248 - 0x214];
    float f248, f24c, f250;
    char pad254[0x290 - 0x254];
    float f290, f294, f298;
    char pad29c[0x32c - 0x29c];
    Sub32c_a4450 s32c;
    Obj350_a4450 *f350;
    char pad354[0x400 - 0x354];
    float f400, f404, f408;
    char pad40c[0x444 - 0x40c];
    float f444, f448;
    char pad44c[0x478 - 0x44c];
    float f478, f47c, f480, f484, f488;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float v);
    void FUN_000a4450(int unused, float dt);
};

void Ctl_a4450::FUN_000a4450(int unused, float dt)
{
    Frame_a4450 f;
    float dt0 = dt;

    FUN_000a0dc0(DAT_0049ec74, DAT_0049ec7c * 0.5f, dt0);
    if (f488 > 0.0f) {
        V3_a4450 *r = FUN_0009f8c0(&f.D, f478, f47c, 1.0f);
        f.A = *r;
    } else {
        f.A.x = f248 - f1c4;
        f.A.y = f24c - f1c8;
        f.D.z = f250 - f1cc;
        f.A.z = f.D.z;
        f.A.FUN_0022d110();
        FUN_000a04c0(&f.A, &f478, &f47c, &f.f40);
    }
    f.C = f.A;
    f480 = f444;
    f484 = f448;
    f350->FUN_00035550(&f.B);
    f.B.FUN_0022d110();
    f.B.x = f.B.x * -1.0f;
    f.B.y = f.B.y * -1.0f;
    f.B.z = f.B.z * -1.0f;

    if (f.B.x != f400 || f.B.y != f404 || f.B.z != f408) {
        if (f400 != 0.0f || f404 != 0.0f || f408 != 0.0f) {
            if (f.B.z * f408 + f.B.y * f404 + f.B.x * f400 < 0.5f)
                f488 = 0.0f;
        }
    }
    f400 = f.B.x;
    f404 = f.B.y;
    f408 = f.B.z;
    f.f48 = 60.0f;

    if (s32c.FUN_000a2370(dt0, &f.f40, &f.f44, &f.flag)) {
        f.f40 = f.f40 + f478;
        f478 = f.f40;
        f47c = f.f44 + f47c;
        float val;
        if (f47c >= -75.0f && f47c <= 75.0f)
            val = f47c;
        else if (f47c > 75.0f)
            val = 75.0f;
        else
            val = -75.0f;
        f.f44 = val;
        f47c = val;
        V3_a4450 *r = FUN_0009f8c0(&f.D, f.f40, val, 1.0f);
        f.C = *r;
        f.A = *r;
        if (f.flag)
            f488 = (*(float*)&DAT_0049ec98);
    } else if (f488 > 0.0f) {
        float val;
        if (f47c >= -75.0f && f47c <= 75.0f)
            val = f47c;
        else if (f47c > 75.0f)
            val = 75.0f;
        else
            val = -75.0f;
        float p478 = f478;
        f.f44 = val;
        f47c = val;
        V3_a4450 *r = FUN_0009f8c0(&f.D, p478, val, 1.0f);
        f.C = *r;
        f.A = *r;
    } else if (f.A.z * f.B.z + f.A.y * f.B.y + f.A.x * f.B.x < 0.0f) {
        V3_a4450 *r = FUN_0009fef0(&f.D, &f.B, &f.A, 89.9f);
        f.C = *r;
        f.f48 = 200.0f;
    } else if (fabs(f47c) > 75.0f) {
        f.f40 = -75.0f;
        float res = FUN_000186b0(&f47c, &f.f40, ((float*)&DAT_004056f0));
        f.f40 = res;
        f47c = res;
        V3_a4450 *r = FUN_0009f8c0(&f.D, f478, res, 1.0f);
        f.C = *r;
        f.f48 = 200.0f;
    } else {
        f.D.x = f1b8 - f290;
        f.D.y = f1bc - f294;
        f.D.z = f1c0 - f298;
        f.f44 = 1.0f;
        if (!FUN_00018960(dt, 0.0f, 1e-5f))
            f.f44 = 1.0f / dt;
        if (f.D.FUN_0022d110() * f.f44 >= DAT_0049ed2c) {
            f.f44 = f.D.z * f.B.z + f.D.y * f.B.y + f.D.x * f.B.x;
            if (fabs(f.f44) <= 0.1f) {
                V3_a4450 *r = FUN_0009fef0(&f.F, &f.B, &f.D, -60.0f);
                f.C = *r;
            }
        }
    }

    f.f40 = f.C.z * f.A.z + f.C.y * f.A.y + f.C.x * f.A.x;
    f.f44 = f.f40 - 1.0f;
    if (fabs(f.f44) <= 1e-5f) {
        f.C = f.A;
    } else {
        f.f44 = f.f48 * dt;
        dt = FUN_00018a20(f.f40) * 57.2957763671875f;
        f.f40 = FUN_000a0450(&f.A);
        f.f40 = FUN_000a02a0(f.f40 - FUN_000a0450(&f.C));
        f.f40 = fabs(f.f40);
        double ret = FUN_000a00e0(0.0f, dt, f.f48, dt0, f.f48 * 0.2f);
        dt = dt * ret;
        double mx = ret * f.f40;
        double X = dt;
        if (dt < mx)
            X = mx;
        if (X > f.f44)
            dt = (dt / X) * f.f44;
        V3_a4450 *r = FUN_0009fef0(&f.F, &f.A, &f.C, dt);
        f.C = *r;
    }

    f.D.x = f.C.x * f444;
    f.D.y = f.C.y * f444;
    f.D.z = f444 * f.C.z + f1cc;
    f194 = f.D.x + f1c4;
    f198 = f.D.y + f1c8;
    f19c = f.D.z;
    FUN_000a0940((*(float*)&DAT_0049ec80));
    f.D.x = f1e8 - f194;
    f.D.y = f1ec - f198;
    f.D.z = f1f0 - f19c;
    FUN_000a04c0(&f.D, &f210, &f20c, &dt);
}
} // namespace fn_000a4450

namespace fn_f69c308d {

// 0x000a5400 FUN_000a5400 (401 B): equivalent/0x000a5400.cpp
// sym: ?FUN_000a5400@CChaseCamera_a5400@fn_f69c308d@@QAEXHH@Z @9924e725988c @we174c429bbc0
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 10/10)
// FUN_000a5400 @ 0x000a5400
void CChaseCamera_a5400::FUN_000a5400(int arg, int flagWord)
{
    struct {
        float dx;
        float dy;
        V3_a5400 out;
    } fr;
    float t;

    FUN_000a0dc0(0, DAT_0049ec7c, flagWord);
    if (sampler.FUN_000a2370(flagWord, &fr.dx, &fr.dy, (char *)&flagWord)) {
        f478 = fr.dx + f478;
        f47c = fr.dy + f47c;
        float v = f47c;
        if (!(v >= -40.0f))
            v = -40.0f;
        else if (!(v <= 60.0f))
            v = 60.0f;
        f47c = v;
        if (*(char *)&flagWord)
            f488 = (*(float*)&DAT_0049ec98);
    }
    t = f444;
    f480 = t;
    f484 = f448;
    V3_a5400 *p = FUN_0009f8c0(&fr.out, f478, f47c, t);
    f19c = f1cc + p->z;
    f194 = f1c4 + p->x;
    f198 = f1c8 + p->y;
    FUN_000a0940((*(float*)&DAT_0049ec80));
    fr.out.x = f1e8 - f194;
    fr.out.y = f1ec - f198;
    fr.out.z = f1f0 - f19c;
    FUN_000a04c0(&fr.out, &f210, &f20c, &t);
}

} // namespace fn_f69c308d

// 0x000a55a0 FUN_000a55a0 (1253 B): equivalent/0x000a55a0.cpp [wrapped: conflict: FUN_000186b0; FUN_000a02a0]
// sym: ?FUN_000a55a0@CChaseCamera_a55a0@fn_000a55a0@@QAEXHTSlot_a55a0@2@@Z @dcc919edb35a @wace44dc2fe32
namespace fn_000a55a0 {
// STATUS: equivalent (tools/equiv.py level 3: 20052 inputs, branch coverage 37/38, incomplete)
// FUN_000a55a0 @ 0x000a55a0
// FUN_000a55a0 @ 0x000a55a0

struct V3_a55a0 {
    float x, y, z;
};

struct Sub32c_a55a0 {
    char pad0[0x345 - 0x32c];
    char FUN_000a2370(int dt, float *a, float *b, float *c);
};

struct Inner18 {
    char pad0[0x18];
    int kind;
};

struct Inner11c {
    char pad0[0x11c];
    Inner18 *f11c;
};

struct Stats_a55a0 {
    char pad0[0x338];
    Inner11c *f338;
    char FUN_00035550(V3_a55a0 *out);
};

union Slot_a55a0 {
    int i;
    float f;
    unsigned int u;
};


struct ThisCall_000a0dc0 {
    void FUN_000a0dc0(int a, int b, int c);
};
void __cdecl FUN_000a04c0(V3_a55a0 *v, float *p1, float *p2, float *p3);
double __cdecl FUN_000a00e0(int a, int b, int c, int d, int e);
double __cdecl FUN_000186b0(float *v, float *lo, float *hi);
double __cdecl FUN_000a0450(V3_a55a0 *v);
double __cdecl FUN_000a02a0(float v);
double __cdecl FUN_000a03c0(int v, float lo, float hi);
double __cdecl FUN_000a05b0(int a, float b, int c, int d, int e);
V3_a55a0 *__cdecl FUN_0009f8c0(V3_a55a0 *out, int a, int b, int c);

class CChaseCamera_a55a0 {
public:
    char pad0[0x194];
    V3_a55a0 out194;
    char pad1a0[0x1c4 - 0x1a0];
    V3_a55a0 pos;
    char pad1d0[0x1e8 - 0x1d0];
    V3_a55a0 tgt;
    char pad1f4[0x26c - 0x1f4];
    V3_a55a0 v26c;
    char pad278[0x2e4 - 0x278];
    float f2e4;
    float f2e8;
    float f2ec;
    char pad2f0[0x2f4 - 0x2f0];
    float f2f4;
    char pad2f8[0x2fc - 0x2f8];
    float f2fc;
    char pad300[0x32c - 0x300];
    Sub32c_a55a0 sub32c;
    char b345;
    char pad346[0x350 - 0x346];
    Stats_a55a0 *f350;
    char pad354[0x444 - 0x354];
    float f444;
    int f448;
    char pad44c[0x46c - 0x44c];
    float f46c;
    float f470;
    char pad474[4];
    int f478;
    int f47c;
    int f480;
    int f484;
    int f488;
    void FUN_000a0940(int z);
    void FUN_000a0ac0(float a, float b);
    void FUN_000a55a0(int a1, Slot_a55a0 a2);
};

void CChaseCamera_a55a0::FUN_000a55a0(int a1, Slot_a55a0 a2)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        float s12;
        float s16;
        float s20;
        float s24;
        float s28;
        float s32;
        V3_a55a0 d;
        V3_a55a0 v;
    } f;

    int dt = a2.i;
    ((ThisCall_000a0dc0*)(this))->FUN_000a0dc0(0, *(int *)&DAT_0049ec7c, dt);
    f.d.x = v26c.x - pos.x;
    f.d.y = v26c.y - pos.y;
    f.d.z = v26c.z - pos.z;
    FUN_000a04c0(&f.d, &f.s4, &f.s0, &f.s8);
    f.s12 = f2fc + f2e8;
    a2.f = 5.0f;
    *(int *)&f.s16 = *(int *)&f444;
    f.s20 = f2f4 + f2ec + f2e4;
    double m08 = f444 * 0.8f;
    f.s32 = f444 * 1.2f;
    if (f.s8 < m08) {
        f.s16 = (float)m08;
        a2.i = *(int *)&DAT_0049ec54;
    } else if (f.s8 > f.s32) {
        f.s16 = f.s32;
        a2.i = *(int *)&DAT_0049ec54;
    }
    f.s8 = (float)FUN_000a00e0(*(int *)&f.s8, *(int *)&f.s16, a2.i, dt, 0x3f800000);

    if (!(DAT_0049ec60 - 2.0f > f.s0) && !(DAT_0049ec5c + 2.0f < f.s0)) {
        if (sub32c.FUN_000a2370(dt, &f.s32, &f.s16, &a2.f)) {
            f.s4 = (float)((double)f.s32 + f.s4);
            f.s16 = (float)((double)f.s16 + f.s0);
            double clamp = FUN_000186b0(&f.s16, &DAT_0049ec60, &DAT_0049ec5c);
            char flag = *(char *)&a2.i;
            double delta = clamp - f.s0;
            f.s0 = (float)clamp;
            f.s12 = (float)((double)f.s32 + f.s12);
            f.s20 = (float)((double)f.s20 - delta);
            if (flag)
                f488 = *(int *)&(*(float*)&DAT_0049ec98);
        } else if (b345) {
            Stats_a55a0 *e = f350;
            Inner11c *i1 = e->f338;
            if (i1 != 0) {
                Inner18 *i2 = i1->f11c;
                if (i2 != 0 && (i2->kind == 3 || i2->kind == 2)) {
                    if (e->FUN_00035550(&f.v)) {
                        double r1 = FUN_000a0450(&f.v);
                        double r2 = FUN_000a02a0((float)(r1 + 180.0f));
                        double x = FUN_000a03c0(*(int *)&f.s4, (float)(r2 - 70.0f), (float)(70.0f + r2));
                        if (!(f.s4 == x)) {
                            double r5 = FUN_000a05b0(0, (float)(x - f.s4), *(int *)&(*(float*)&DAT_0049ec44), dt,
                                                     0x40a00000);
                            f.s4 = (float)((double)f.s4 + r5);
                            f.s12 = (float)(r5 + f.s12);
                        }
                    }
                }
            }
        }
    } else {
        if (f.s0 >= DAT_0049ec60 && f.s0 <= DAT_0049ec5c)
            a2.f = f.s0;
        else if (f.s0 > DAT_0049ec5c)
            a2.i = *(int *)&DAT_0049ec5c;
        else
            a2.i = *(int *)&DAT_0049ec60;
        f.s0 = (float)FUN_000a00e0(*(int *)&f.s0, a2.i, *(int *)&(*(float*)&DAT_0049ec48), dt, 0);
    }

    V3_a55a0 *p = FUN_0009f8c0(&f.v, *(int *)&f.s4, *(int *)&f.s0, *(int *)&f.s8);
    float nx = pos.x + p->x;
    float ny = pos.y + p->y;
    f.v.z = pos.z + p->z;
    out194.z = f.v.z;
    out194.x = nx;
    out194.y = ny;
    FUN_000a0940(0);
    f478 = *(int *)&f.s4;
    f47c = *(int *)&f.s0;
    f480 = *(int *)&f.s8;
    f484 = f448;
    f488 = 0;

    f.v.x = tgt.x - out194.x;
    f.v.y = tgt.y - out194.y;
    f.v.z = tgt.z - out194.z;
    FUN_000a04c0(&f.v, &f.s28, &f.s24, &a2.f);
    a2.f = (float)FUN_000a00e0(*(int *)&f.s20, *(int *)&f.s24, *(int *)&(*(float*)&DAT_0049eca8), dt, 0x41200000);
    f.s16 = (float)FUN_000a05b0(*(int *)&f.s12, f.s28, *(int *)&(*(float*)&DAT_0049eca8), dt, 0x41200000);
    double h = f470 * 0.5f;
    f.s20 = (float)(f.s24 + h);
    double low = f.s24 - h;
    if (!(a2.f >= low)) {
        if (!(a2.f <= f.s20))
            a2.f = f.s20;
        else
            a2.f = (float)low;
    } else if (!(a2.f <= f.s20)) {
        a2.f = f.s20;
    }
    double h2 = f46c * 0.5f;
    int vbits = a2.i;
    f.s16 = (float)FUN_000a03c0(*(int *)&f.s16, (float)(f.s28 - h2), (float)(f.s28 + h2));
    FUN_000a0ac0(f.s16, *(float *)&vbits);
}
} // namespace fn_000a55a0

namespace fn_f69c308d {

// 0x000a5a90 FUN_000a5a90 (2083 B): equivalent/0x000a5a90.cpp
// sym: ?FUN_000a5a90@Obj_a5a90@fn_f69c308d@@QAEDIIIIIDM@Z @dfb1cec1c077 @w15fff9829921
// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 55/56, incomplete)
// FUN_000a5a90 @ 0x000a5a90
// 0xa5a90: character-controller step: slide the position v194 along the ground / walls with sweep tests.
char Obj_a5a90::FUN_000a5a90(unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, char a6, float a7)
{
    Frame_a5a90 f;
    Vec3_a5a90 *prev = &v1c4;
    Vec3_a5a90 *dirv = &v1d0;
    Vec3_a5a90 *cur = &v4a0;
    flagA = 0;
    if (mode == 3) {
        sweeper->FUN_00035550(&f.tmpA);
        f.tmpA.FUN_0022d110();
    }
    f.pos = *prev;
    f.dir = *dirv;
    f.f32 = (float)sqrt(f.dir.y * f.dir.y + (f.dir.x * f.dir.x + f.dir.z * f.dir.z));
    f.f0 = (float)sqrt(f.dir.x * f.dir.x + f.dir.z * f.dir.z);
    hulk_freg scale = f.f0 * 0.05f > DAT_0049ecdc ? DAT_0049ecdc / f.f0 : 0.05f;
    f.dir.x = f.dir.x * scale;
    f.dir.y = 0.0f * scale;
    f.dir.z = f.dir.z * scale;
    *cur = *FUN_0009f7d0(&f.tmpA, cur, &f.dir, a7, (*(float*)&DAT_0049ece0));
    f.pos.x = f.pos.x - cur->x;
    f.pos.y = f.pos.y - cur->y;
    f.pos.z = f.pos.z - cur->z;
    cur = &v194;

    if (sweeper->FUN_00038e30(&f.pos, cur, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
        *cur = f.hit;
        cur->x = f.nrm.x * f468 + cur->x;
        cur->y = f.nrm.y * f468 + cur->y;
        cur->z = f.nrm.z * f468 + cur->z;
        flagA = 1;
        f.d.x = cur->x - prev->x;
        f.d.y = cur->y - prev->y;
        f.d.z = cur->z - prev->z;
        hulk_freg dist = f.d.FUN_0022d110();
        hulk_freg dot = (f.d.z * dirv->z + f.d.y * dirv->y + f.d.x * dirv->x) * 0.1f;
        hulk_freg c = dot >= -1.0f ? (dot > DAT_0049eca0 ? DAT_0049eca0 : dot) : (dot > DAT_0049eca0 ? DAT_0049eca0 : -1.0f);
        if (dist < DAT_0049eca0 + c && mode != 7 && f488 == 0.0f && f34c == 0.0f &&
            FUN_000a2800(a1, a2, a3, a4, a5, DAT_0049eca0 + 2.0f, f444 + 5.0f, &f.pos, &f.vB, &f.f4)) {
            if (f.f4 > f444) {
                f.vB.FUN_00067930(prev, 1.0f - f444 / f.f4);
                f.f4 = f444;
            }
            if (a6 == 0 && !(f.f32 >= 11.0f)) {
                f.saved.x = f.vB.x - prev->x;
                f.saved.y = f.vB.y - prev->y;
                f.saved.z = f.vB.z - prev->z;
                FUN_000a04c0(&f.saved, &f.f4, &f.f0, &f.f32);
                FUN_000a2cc0(f.f4, f.f0, f.f32, (*(float*)&DAT_0049ec64), mode);
            } else {
                FUN_000a1930(f.vB, mode);
                flagA = f.f4 < f444;
            }
            b349 = 1;
            hulk_freg k = DAT_0049ecac;
            if (mode == 6)
                k = k + k;
            f34c = k;
        }
    }

    f.saved = *cur;
    if (b31c == 0 && flagA == 0) {
        f.d.x = cur->x - v26c.x;
        f.d.y = cur->y - v26c.y;
        f.d.z = cur->z - v26c.z;
    } else {
        f.d.x = v17c.x - v254.x;
        f.d.y = v17c.y - v254.y;
        f.d.z = v17c.z - v254.z;
    }
    flagB = 0;

    hulk_freg sign = f.d.y < 0.0f ? -1.0f : (f.d.y > 0.0f ? 1.0f : 0.0f);
    f.n.x = 0.0f;
    f.n.y = sign;
    f.n.z = 0.0f;
    f.f0 = (float)fabs(f.d.y);
    if (!(f.f0 <= 1e-5f)) {
        f.vB.x = f.n.x * f468;
        f.vB.y = f.n.y * f468;
        f.vB.z = f.n.z * f468;
        f.tmpA.x = f.n.x * f.f0;
        f.tmpA.y = f.n.y * f.f0;
        f.tmpA.z = f.n.z * f.f0;
        f.q.x = cur->x - f.tmpA.x;
        f.q.y = cur->y - f.tmpA.y;
        f.q.z = cur->z - f.tmpA.z;
        f.r.x = f.vB.x + cur->x;
        f.r.y = f.vB.y + cur->y;
        f.r.z = f.vB.z + cur->z;
        if (sweeper->FUN_00038e30(&f.q, &f.r, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
            cur->x = f.hit.x - f.vB.x;
            cur->y = f.hit.y - f.vB.y;
            cur->z = f.hit.z - f.vB.z;
            flagB = 1;
        }
    }

    f.n.x = f.d.x;
    f.n.y = 0.0f;
    f.n.z = f.d.z;
    hulk_freg len = f.n.FUN_0022d110();
    f.f0 = (float)fabs(len);
    if (!(f.f0 <= 1e-5f)) {
        f.vB.x = f.n.x * f468;
        f.vB.y = f.n.y * f468;
        f.vB.z = f.n.z * f468;
        f.q.x = cur->x - f.n.x * len;
        f.tmpA.y = f.n.y * len;
        f.tmpA.z = f.n.z * len;
        f.q.y = cur->y - f.tmpA.y;
        f.q.z = cur->z - f.tmpA.z;
        f.r.x = f.vB.x + cur->x;
        f.r.y = f.vB.y + cur->y;
        f.r.z = f.vB.z + cur->z;
        if (sweeper->FUN_00038e30(&f.q, &f.r, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
            cur->x = f.hit.x - f.vB.x;
            cur->y = f.hit.y - f.vB.y;
            cur->z = f.hit.z - f.vB.z;
            flagB = 1;
        }
    }

    if (flagB != 0) {
        if (sweeper->FUN_00038e30(&f.pos, cur, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
            *cur = f.saved;
            flagB = 0;
        }
    }
    if (flagA != 0 || flagB != 0)
        return 1;
    return 0;
}


// 0x000a62c0 FUN_000a62c0 (313 B): equivalent/0x000a62c0.cpp
// sym: ?run@CChaseCamera_a62c0@fn_f69c308d@@QAEXHPAUHolder_a62c0@2@@Z @2db10b673458 @w9b001dbaa01b
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 4/4)
// FUN_000a62c0 @ 0x000a62c0
void CChaseCamera_a62c0::run(hulk_intptr a, Holder_a62c0* b)
{
    if (h350 != 0 && b == h350) {
        h350->sub->FUN_00059a50(&v1b8);
        V3_a62c0 tmp; V3_a62c0* r = FUN_000a92c0(&tmp, a, h350);
        v1c4 = *r;
        v1e8 = v1c4;
        f314 = f23c = h350->f1a64;
        v1d0.x = 0; v1d0.y = 0; v1d0.z = 0;
        v1dc.x = 0; v1dc.y = 0; v1dc.z = 0;
        v29c = v1c4;
        v2a8.x = 0; v2a8.y = 0; v2a8.z = 0;
        v2b4.x = 0; v2b4.y = 0; v2b4.z = 0;
        v4a0.x = 0; v4a0.y = 0; v4a0.z = 0;
        ((::CChaseCamera *)this)->FUN_000a2f30(0);
        FUN_000a1b30(a, 0, 1);
        c344 = 0;
    }
}

} // namespace fn_f69c308d

// 0x000a6400 FUN_000a6400 (4283 B): equivalent/0x000a6400.cpp [wrapped: macros]
// sym: ?FUN_000a6400@Camera@fn_000a6400@@QAEXMM@Z @1acf359ce675 @w07380777f653
namespace fn_000a6400 {
// STATUS: equivalent (tools/equiv.py level 3: 3149 inputs, branch coverage 142/148, incomplete)
// FUN_000a6400 @ 0x000a6400


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};

struct V3v {
    volatile float x, y, z;
};

union Bits {
    float f;
    unsigned int u;
};

struct Radius {
    char pad0[0x30];
    float f30;
};

struct Sub338 {
    char FUN_00035a90();
};

class Ent {
  public:
    char pad0[0x11c];
    Radius* f11c;
    char pad120[0x338 - 0x120];
    Sub338* f338;
    void FUN_000382c0(V3* out);
    void FUN_00035550(V3* out);
};

class Actor {
  public:
    char pad0[0x148];
    Ent* f148;
    void FUN_001d69f0(V3* out);
};

struct Mode {
    char pad0[8];
    void* obj;
    int kind;
    char pad10[0x40 - 0x10];
    V3 v40;
};

hulk_freg __cdecl FUN_000189c0(float v);
void __cdecl FUN_000a04c0(V3* delta, float* a, float* b, float* c);
hulk_freg __cdecl FUN_000a00e0(float a, float b, float c, float d, float e);
hulk_freg __cdecl FUN_000a02a0(float v);
hulk_freg __cdecl FUN_000a03c0(float v, float lo, float hi);
hulk_freg __cdecl FUN_000a0450(V3* v);
extern "C++" __declspec(nothrow) char __cdecl FUN_0009ffc0(float a, float b, float c, float* out);
hulk_freg __cdecl FUN_000a05b0(float a, float b, float c, float d, float e);
V3* __cdecl FUN_0009f8c0(V3* out, float a, float b, float c);

#define CLAMP(v, lo, hi)                                                                                     \
    do {                                                                                                     \
        if ((v) >= (lo) && (v) <= (hi)) {                                                                    \
        } else if ((v) > (hi))                                                                               \
            (v) = (hi);                                                                                      \
        else                                                                                                 \
            (v) = (lo);                                                                                      \
    } while (0)

struct Frame {
    union {
        float hlen;
        float u;
        float k3;
        float k4;
        float mm;
        float r2;
        unsigned int abits;
        float afl;
    };
    float q;
    char pad8[3];
    char b17;
    union {
        float ang2;
        float k2;
        float scratch;
        float k5;
        float hh;
        float k6;
        float tmp;
    };
    union {
        float inv;
        float lo;
        float limLo;
        float oa3;
        float b3f;
        unsigned int b3u;
    };
    union {
        float q20;
        float hd;
        float len3;
        float lo2;
    };
    float v;
    union {
        float p1c;
        float ey1;
    };
    union {
        float k1;
        float s2;
    };
    union {
        float limHi;
        float b2f;
        unsigned int b2u;
    };
    union {
        V3 o;
        V3 dd;
        V3 d2;
        V3 d3;
    };
    float dist;
    float angC;
    union {
        float o48;
        float hi3;
    };
    float angA;
    float angB;
    V3 e;
    float f60;
    float p2;
    float oa2;
    V3 t2;
    union {
        V3 w;
        V3 w2;
    };
    union {
        V3 d;
        V3 nv;
    };
    float oa1;
    float p3;
    float p1;
    V3 t1;
};

class Camera {
  public:
    char pad0[0x170];
    V3 v170;
    char pad17c[0x194 - 0x17c];
    V3 v194;
    V3v v1a0;
    V3v v1ac;
    char pad1b8[0x1c4 - 0x1b8];
    V3 pos;
    V3 v1d0;
    char pad1dc[0x1e8 - 0x1dc];
    V3 tgt;
    char pad1f4[0x20c - 0x1f4];
    float f20c;
    float f210;
    float f214;
    char pad218[4];
    float f21c;
    char pad220[4];
    float f224;
    char pad228[0x238 - 0x228];
    float f238;
    float f23c;
    char pad240[0x248 - 0x240];
    V3 v248;
    char pad254[0x278 - 0x254];
    V3 v278;
    char pad284[0x2e4 - 0x284];
    float f2e4;
    float f2e8;
    float f2ec;
    char pad2f0[4];
    float f2f4;
    char pad2f8[4];
    float f2fc;
    char pad300[0x346 - 0x300];
    char f346;
    char f347;
    char pad348[0x350 - 0x348];
    Ent* f350;
    char pad354[0x414 - 0x354];
    Mode* f414;
    V3 v418;
    char pad424[0x444 - 0x424];
    float f444;
    float f448;
    float f44c;
    char pad450[0x46c - 0x450];
    float f46c;
    float f470;
    float f474;
    float f478;
    float f47c;
    float f480;
    char pad484[4];
    int f488;
    char pad48c[0x498 - 0x48c];
    float f498;
    float f49c;

    void FUN_000a0dc0(float a, float b, float c);
    void FUN_000a0940(float a);
    void FUN_000a0ac0(float a, float b);
    char FUN_000a5a90(float a, float b, float c, float d, float e, int f, float g);
    void FUN_000a6400(float a1, float a2);
};

void Camera::FUN_000a6400(float a1, float a2) {
    Frame f;
    f.b17 = 0;
    if (f347 && f350 && f350->f338 && !f350->f338->FUN_00035a90())
        f.b17 = 1;

    Mode* m = f414;
    f.f60 = 3.0f;
    V3* cp = &v418;
    if (m->kind == 5) {
        Actor* a = (Actor*)m->obj;
        Ent* e = a->f148;
        if (e) {
            e->FUN_000382c0(cp);
            f.f60 = e->f11c->f30;
        } else {
            a->FUN_001d69f0(cp);
        }
    } else if (m->kind == 1) {
        Ent* e = (Ent*)m->obj;
        e->FUN_000382c0(cp);
        f.f60 = e->f11c->f30;
    } else if (m->kind == 7) {
        v418 = *(V3*)((char*)m->obj + 0x64);
        f.f60 = 0.8f;
    } else {
        v418 = m->v40;
    }

    FUN_000a0dc0(DAT_0049ec74 * 0.6f, DAT_0049ec7c * 0.5f, a2);

    V3* dp = &v1d0;
    f.w = *dp;
    f.hlen = (float)sqrt((hulk_freg)f.w.z * f.w.z + (hulk_freg)f.w.x * f.w.x);
    f.d.x = v248.x - pos.x;
    f.d.y = v248.y - pos.y;
    f.d.z = v248.z - pos.z;
    FUN_000a04c0(&f.d, &f.p1, &f.p2, &f.p3);
    f.p1c = f.p1;

    f.dist = FUN_000a00e0(f.p3, f444, 10.0f, a2, 0.5f);
    float hi = f444 * 1.1f;
    f.lo = (float)(f444 * 0.9f);
    CLAMP(f.dist, f.lo, hi);
    f.inv = 1.0f / f.dist;

    f.v = (float)(((hulk_freg)f49c - pos.y) * f.inv);
    CLAMP(f.v, -1.0f, 1.0f);
    f.angA = FUN_000189c0(f.v) * 57.2957763671875f;
    f.v = (float)(((hulk_freg)f498 - pos.y) * f.inv);
    CLAMP(f.v, -0.94f, 1.0f);
    f.angB = FUN_000189c0(f.v) * 57.2957763671875f;
    f.v = (float)((((hulk_freg)f23c + 0.3f) - pos.y) * f.inv);
    CLAMP(f.v, -1.0f, 1.0f);
    f.angC = FUN_000189c0(f.v) * 57.2957763671875f;

    f.q = f.p2;
    if (f.b17) {
        f47c = f.q;
    } else if (f.hlen >= DAT_0049ed38 || f.q < f.angC || f.q < f.angA || f.q > f.angB) {
        f.tmp = DAT_0049ed34 * f.hlen;
        f.s2 = FUN_000a00e0(f.q, f44c, f.tmp, a2, 2.0f);
        f.q20 = f.q;
        if (f.q < f.angC)
            f.q20 = f.angC;
        if (f.q20 > f.angB) {
            f.q20 = f.angB;
            f346 = 1;
        } else if (f.q20 < f.angA) {
            f.q20 = f.angA;
            f346 = 1;
        }
        if (f.q == f.q20) {
            f.q = f.s2;
        } else {
            float s3 = FUN_000a00e0(f.q, f.q20, (*(float*)&DAT_0049ec48), a2, 2.0f);
            hulk_freg e3 = (hulk_freg)s3 - f.q; // both kept in st for the product's sign
            hulk_freg e2 = (hulk_freg)f.s2 - f.q;
            f.b3f = (float)e3;
            f.b2f = (float)e2;
            f.b3u &= 0x7fffffff;
            f.b2u &= 0x7fffffff;
            if (f.b3f > f.b2f)
                f.q = s3;
            else if (e3 * e2 < 0.0f)
                f.q = s3;
            else
                f.q = f.s2;
        }
    }

    if (((int)((owners::Widget_35910 *)f350)->FUN_00035910()) == 2 || ((int)((owners::Widget_35910 *)f350)->FUN_00035910()) == 3) {
        hulk_freg R = FUN_000a02a0(f238 + 180.0f); // st(0) for both limits
        f.p1c = FUN_000a03c0(f.p1c, (float)(R - 70.0f), (float)(70.0f + R));
    }

    FUN_000a02a0(f.p1c + 180.0f);
    f.t1.x = cp->x - v248.x;
    f.t1.y = cp->y - v248.y;
    f.t1.z = cp->z - v248.z;
    FUN_000a0450(&f.t1);

    f.t2.x = cp->x - pos.x;
    f.t2.y = cp->y - pos.y;
    f.t2.z = cp->z - pos.z;
    // fst: the original multiplies the unrounded difference in st(0) by the stored float
    f.hd = (float)sqrt(((hulk_freg)cp->z - pos.z) * f.t2.z + (hulk_freg)f.t2.x * f.t2.x);
    f.ang2 = FUN_000a0450(&f.t2);
    f.limLo = -180.0f;
    f.limHi = 135.0f;
    if (f.hlen >= 5.0f) {
        hulk_freg X = FUN_000a0450(dp) + 180.0f; // st(0) for both limits
        f.limLo = (float)(X - 90.0f);
        f.limHi = (float)(X + 90.0f);
    }

    if (FUN_0009ffc0(f.hd, f46c, f.dist, &f.o48)) {
        bool pass = true;
        if (((int)((owners::Widget_35910 *)f350)->FUN_00035910()) == 2 || ((int)((owners::Widget_35910 *)f350)->FUN_00035910()) == 3) {
            f350->FUN_00035550(&f.nv);
            f.nv.FUN_0022d110();
            f350->FUN_000382c0(&f.o);
            f.w2.x = cp->x - f.o.x;
            f.w2.y = cp->y - f.o.y;
            f.w2.z = cp->z - f.o.z;
            f.w2.FUN_0022d110();
            hulk_freg dot =
                (hulk_freg)f.nv.z * f.w2.z + (hulk_freg)f.nv.y * f.w2.y + (hulk_freg)f.nv.x * f.w2.x;
            pass = !(dot < 0.2f);
        }
        if (pass) {
            f.u = f.o48 + f46c;
            hulk_freg R2 = FUN_000a02a0(f.ang2 + 180.0f); // st(0) for both limits
            f.limLo = (float)(R2 - f.u);
            f.limHi = (float)(R2 + f.u);
            f.p1c = FUN_000a03c0(f.p1c, f.limLo, f.limHi);
        }
    }

    f.k1 = -10.0f;
    f.k2 = 30.0f;
    f.len3 =
        (float)sqrt((hulk_freg)f.t2.y * f.t2.y + (hulk_freg)f.t2.z * f.t2.z + (hulk_freg)f.t2.x * f.t2.x);
    f.v = f.t2.y / f.len3;
    CLAMP(f.v, -1.0f, 1.0f);
    if (FUN_0009ffc0(f.len3, f470, f.dist, &f.o48)) {
        f.u = f.o48 + f470;
        hulk_freg deg = (hulk_freg)FUN_000189c0(f.v) * 57.2957763671875f; // st(0) for both limits
        f.lo2 = (float)(-deg - f.u);
        hulk_freg hi2 = -deg + f.u; // compared (and stored) from st(0)
        CLAMP(f.q, f.lo2, hi2);
    }
    CLAMP(f.q, -60.0f, 60.0f);

    if (f.q < f.angC) {
        f.q = f.angC;
        if (f.k1 < f.angC)
            f.k1 = f.angC;
    }
    if (f.q > f.angB) {
        f.q = f.angB;
        if (!(f.k2 < f.angB))
            f.k2 = f.angB;
        f346 = 1;
    } else if (f.q < f.angA) {
        f.q = f.angA;
        if (f.k1 < f.angA)
            f.k1 = f.angA;
        f346 = 1;
    }

    f478 = FUN_000a05b0(f478, f.p1c, (*(float*)&DAT_0049ec4c), a2, 10.0f);
    f47c = FUN_000a00e0(f47c, f.q, (*(float*)&DAT_0049ec50), a2, 10.0f);
    f.r2 = FUN_000a00e0(f480, f.dist, 20.0f, a2, 0.5f);
    f480 = f.r2;
    V3* pp = FUN_0009f8c0(&f.dd, f478, f47c, f.r2);
    float nx = pos.x + pp->x;
    float ny = pos.y + pp->y;
    float nz = pos.z + pp->z;
    v194.z = nz;
    v194.x = nx;
    v194.y = ny;
    FUN_000a0940((*(float*)&DAT_0049ec80));

    f.afl = a2;
    f.abits &= 0x7fffffff;
    f488 = 0;
    if (!(f.afl <= 1e-05f)) {
        hulk_freg ia = 1.0f / a2; // st(0) for all six products (the original never stores it)
        float x0 = v170.x - v248.x;
        float y0 = v170.y - v248.y;
        float z0 = v170.z - v248.z;
        v1a0.z = z0;
        v1a0.x = x0;
        v1a0.y = y0;
        v1a0.x = ia * v1a0.x;
        v1a0.y = ia * v1a0.y;
        v1a0.z = ia * v1a0.z;
        float x1 = v1a0.x - v278.x;
        float y1 = v1a0.y - v278.y;
        float z1 = v1a0.z - v278.z;
        v1ac.z = z1;
        v1ac.x = x1;
        v1ac.y = y1;
        v1ac.x = ia * v1ac.x;
        v1ac.y = ia * v1ac.y;
        v1ac.z = ia * v1ac.z;
    }

    f.k3 = -200.0f;
    {
        hulk_freg S = (hulk_freg)dp->x * dp->x + (hulk_freg)dp->z * dp->z; // st(0) for both compares
        if ((hulk_freg)dp->y * dp->y < S && S >= 25.0f)
            f.k3 = FUN_000a02a0(FUN_000a0450(dp) + 180.0f);
    }

    if (FUN_000a5a90(f.limLo, f.limHi, f.k3, f.k1, f.k2, 1, a2)) {
        f.dd.x = v194.x - pos.x;
        f.dd.y = v194.y - pos.y;
        f.dd.z = v194.z - pos.z;
        FUN_000a04c0(&f.dd, &f478, &f47c, &f480);
    }

    if (f.b17) {
        FUN_000a0ac0(f2fc + f2e8, (float)((hulk_freg)f2f4 + f2ec + f2e4));
    } else {
        f.dd.x = tgt.x - v194.x;
        f.dd.y = tgt.y - v194.y;
        f.dd.z = tgt.z - v194.z;
        FUN_000a04c0(&f.dd, &f210, &f20c, &f.scratch);
    }

    f.d2.x = cp->x - v194.x;
    f.d2.y = cp->y - v194.y;
    f.d2.z = cp->z - v194.z;
    f.k4 = (float)((hulk_freg)FUN_000a02a0(FUN_000a0450(&f.d2) - f210) * 0.5f + f210);
    if (f.b17)
        f.k4 = FUN_000a00e0(f2fc + f2e8, f.k4, (*(float*)&DAT_0049eca8), a2, 10.0f);

    f.k5 = f46c;
    if (((int)((owners::Widget_35910 *)f350)->FUN_00035910()) == 2 || ((int)((owners::Widget_35910 *)f350)->FUN_00035910()) == 3)
        f.k5 = f474;

    f.d3.x = pos.x - v194.x;
    f.d3.y = pos.y - v194.y;
    f.d3.z = pos.z - v194.z;
    FUN_000a04c0(&f.d3, &f.oa1, &f.oa2, &f.oa3);
    hulk_freg hh2 = (hulk_freg)f.k5 * 0.5f; // st(1) for both limits
    f224 = FUN_000a02a0(FUN_000a03c0(f.k4, (float)(f.oa1 - hh2), (float)(f.oa1 + hh2)) - f210);

    f.e.x = pos.x - v194.x;
    f.e.y = (float)(((hulk_freg)pos.y - v194.y) - 2.7f);
    f.e.z = pos.z - v194.z;
    f.e.FUN_0022d110();
    f.ey1 = f.e.y;
    f.e.x = cp->x - v194.x;
    f.e.z = cp->z - v194.z;
    f.hh = f.f60 * 0.5f;
    f.e.y = (float)(((hulk_freg)cp->y - v194.y) - f.hh); // the difference stays in st
    f.e.FUN_0022d110();
    f.mm = (f.ey1 < f.e.y) ? f.ey1 : f.e.y;
    CLAMP(f.mm, -1.0f, 1.0f);
    f.f60 = FUN_000189c0(f.mm);

    f.e.x = pos.x - v194.x;
    f.e.y = (float)(((hulk_freg)pos.y - v194.y) + 0.3f);
    f.e.z = pos.z - v194.z;
    f.e.FUN_0022d110();
    f.ey1 = f.e.y;
    f.e.x = cp->x - v194.x;
    f.e.z = cp->z - v194.z;
    f.e.y = (float)(f.hh + ((hulk_freg)cp->y - v194.y)); // the difference stays in st
    f.e.FUN_0022d110();
    f.mm = (f.ey1 < f.e.y) ? f.e.y : f.ey1;
    CLAMP(f.mm, -1.0f, 1.0f);
    hulk_freg X6 = ((hulk_freg)FUN_000189c0(f.mm) + f.f60) * 28.64788818359375f + f448; // fst: st(0) kept
    f.k6 = (float)X6;
    if (f.b17)
        X6 = FUN_000a00e0((float)((hulk_freg)f2f4 + f2ec + f2e4), f.k6, (*(float*)&DAT_0049eca8), a2, 10.0f);

    hulk_freg h2 = (hulk_freg)f470 * 0.5f; // st(1) for both limits
    f.hi3 = (float)(f.oa2 + h2);
    f.oa2 = (float)(f.oa2 - h2);
    CLAMP(X6, f.oa2, f.hi3);
    f214 = (float)(X6 - f20c - f21c);
}
} // namespace fn_000a6400
#undef CLAMP

namespace fn_f69c308d {

// 0x000a74c0 FUN_000a74c0 (267 B): equivalent/0x000a74c0.cpp
// sym: ?target@CChaseCamera_a74c0@fn_f69c308d@@QAEXPAUContext@2@PBD@Z @b18469b1d6e1 @wc09debe98c72
// STATUS: equivalent (tools/equiv.py level 3: 20019 inputs, branch coverage 18/18)
// FUN_000a74c0 @ 0x000a74c0
void CChaseCamera_a74c0::target(Context* context,const char* requested) {
 Item_a74c0* selected=0;
 if(requested) {
  Manager_a74c0* manager=context->manager;
  Key_a74c0 key=FUN_002672f0(requested,0,0);
  selected=manager->FUN_00024280(key);
 } else if(!item) {
  Manager_a74c0* manager=context->manager;
  if(!name[0]) selected=manager->fallback;
  else { Key_a74c0 key=FUN_002672f0(name,0,0); selected=manager->FUN_00024280(key); }
  if(!selected) selected=manager->fallback;
 }
 if(selected) {
  selected->add();
  if(item) item->release();
  item=selected;
  isDefault=(selected==context->manager->fallback);
  FUN_00267830(name,selected->FUN_00036d00(),64);
  item->data->FUN_00059a50(value);
  dirty=0;
 }
 if(item) FUN_000a62c0(context,item);
}

} // namespace fn_f69c308d
