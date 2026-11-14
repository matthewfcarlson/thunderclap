// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00221b30..0x002222f0 (kind game, layer engine, confidence high)
// (regress, tri2) nanquiet64: `__isnan(m[i])` loads a signalling float NaN with fld and stores it as a double: the emulated x87 keeps it signalling, cvtss2sd quiets it (bit 0x00080000 of the high word)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f403c6ef {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f403c6ef {} using namespace fn_f403c6ef;
#include "engine/choreo2.h"

// ---- declarations shared by the functions below
namespace fn_f403c6ef {
struct P_221b30 {
    int a[16];
};
struct Q_221b30 {
    int a[4];
};
class X_221b30 {
  public:
    P_221b30 p;
    Q_221b30 q;
    int c;
    void Copy(const X_221b30&);
};
typedef unsigned int u32_221b70;
struct Block_221b70 {
    u32_221b70 x[16];
};
struct Obj_221b70 {
    Block_221b70 block;
    u32_221b70 a, b, c, d, e;
    void Copy(const Block_221b70* src);
};
struct Pair_221ba0 {
    int a, b, c, d;
};
class Obj_221ba0 {
  public:
    char pad[0x40];
    Pair_221ba0 value;
    int flag;
    void First_0022b980();
    Obj_221ba0* Run(Pair_221ba0* src, int x);
};
struct P_221be0 {
    int a[16];
};
struct Q_221be0 {
    int a[4];
};
class X_221be0 {
  public:
    P_221be0 p;
    Q_221be0 q;
    int c;
    void Copy(const X_221be0&);
};
class Base_221c20 {
  public:
    void Init_0022b980();
};
class Thing_221c20 : public Base_221c20 {
    char pad[0x40];
    volatile int a;
    volatile int b;
    volatile int c;
    volatile int d;
    volatile int e;

  public:
    void Run();
};
struct Obj_221c40 {
    char pad[0x40];
    struct Sub {
        void FnF_0022b650(Obj_221c40*);
    } sub;
    char pad2[0x0c];
    int state;
    Obj_221c40* target();
};
struct Data_221c60 {
    unsigned int a[16];
};
class C_221c60 {
  public:
    Data_221c60 d;
    char pad[0x10];
    int x;
    void Copy(C_221c60*);
};
struct X {
    int a, b, c;
    char pad0[4];
    int d, e, f;
    char pad1[4];
    int g, h, i;
    char pad2[36];
    int state;
    void Copy(const X* p);
};
struct Sub_221cd0 {
    char pad[0x10];
};
struct C_221cd0 {
    char pad[0x40];
    Sub_221cd0 sub;
    int state;
    void* target();
};
struct Four_221cf0 {
    int x, y, z, w;
};
class Obj_221cf0 {
  public:
    char pad[0x40];
    Four_221cf0 v;
    int flag;
    void Set(const Four_221cf0& p);
};
struct Four {
    int a, b, c, d;
    void Set_0022b1c0(int);
};
class Obj {
  public:
    char pad[0x40];
    Four f;
    int flag;
    void Fn(int);
};
class Obj_221d60;
class Elem_221d60 {
  public:
};
class Obj_221d60 {
  public:
    void Fn(Obj_221d60*, float);
    char pad0[0x30];
    float x, y, z;
    char pad3c[4];
    Elem_221d60 elem;
    char pad44[0xc];
    int state;
};
} // namespace fn_f403c6ef
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f403c6ef {
class Obj_221df0;
class Sub_221df0 {
  public:
    void Fn_0022b650(Obj_221df0*);
};
class Obj_221df0 {
  public:
    char pad[0x40];
    Sub_221df0 sub;
    char pad44[0x0c];
    int state;
    char pad54[0x2c];
    void Run(Obj_221df0*);
};
class Tmp_221df0 {
  public:
    char data[0x40];
};
struct Work_221e60 {
    void First_0022b650(owners::Obj_221e60*);
};
struct Sub_221eb0 {
    void call_0022b650(struct Obj_221eb0*);
};
struct Obj_221eb0 {
    char pad[0x40];
    Sub_221eb0 sub;
    char pad2[0xc];
    int state;
    void target();
};
class Inner_221ee0 {
  public:
    char pad[0x10];
};
class Obj_221ee0 {
  public:
    void Run();
    void Other_0022c1b0();
    char pad0[0x40];
    Inner_221ee0 inner;
    int state;
};
class Obj2_221f70 {
  public:
    char pad[0x40];
    void callee1_0022b4d0(int, int);
};
struct MatrixData_221f90 {
    float matrix[4][4];
    float extra[4];
    bool FUN_00221f90();
};
extern "C" void __fastcall FUN_0022b980(void*);
class Obj_222050 {
  public:
    char pad[0x40];
    volatile int a, b, c, d, e;
    Obj_222050();
};
class Base_222080 {
  public:
    Base_222080();
    char pad[0x40];
};
class Thing_222080 : public Base_222080 {
  public:
    int a;
    int b;
    int c;
    float d;
    int e;
    Thing_222080(int);
};
struct Helper { void FUN_0022b4d0(float *source, Vec3 *out); };
struct Object {
    char pad[0x40];
    Helper helper;
    char pad2[0x0f];
    int mode;
    Vec3 *FUN_00222120(Vec3 *result);
};
struct Arg_222180 {
    char pad0[4];
    int f4;                     // 0x04
};
hulk_freg __cdecl FUN_000189c0(int v);
hulk_freg __cdecl FUN_00224f10(Arg_222180 *a);
struct Pos_222180 {
    int x, y, z;
};
struct Mat_222180 {
    float m[12];
    Pos_222180 pos;                    // 0x30
    float tw;
    void FUN_0022b980();
};
class Node {
public:
    Mat_222180 mat;
    char pad40[0x10];
    int state;                  // 0x50
    void FUN_00222180(Arg_222180 *a);
};
struct Sub40_222230 {
    char pad0[0x10];
    void FUN_0022b650(struct Xform_222230* dst);
};
struct Xform_222230 {
    char pad0[0x40];
    Sub40_222230 sub;          // 0x40
    int mode;           // 0x50
    void FUN_00222230(void* a, void* b);
};
class Member_2222d0 {
  public:
    virtual void f0();
    virtual void f1();
};
class PartitionDriver {
  public:
    virtual ~PartitionDriver();
    char pad[12];
    Member_2222d0* mChild;
    void Finish_0022a910();
};



// 0x00221f90 FUN_00221f90 (178 B): equivalent/0x00221f90.cpp
// sym: ?FUN_00221f90@MatrixData_221f90@fn_f403c6ef@@QAE_NXZ
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 12/12)
// FUN_00221f90 @ 0x00221f90
bool MatrixData_221f90::FUN_00221f90() {
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if (__isnan(matrix[row][col])) return false;
        }
    }
    if (__isnan(extra[0])) return false;
    if (__isnan(extra[1])) return false;
    if (__isnan(extra[2])) return false;
    return __isnan(extra[3]) == 0;
}


} // namespace
