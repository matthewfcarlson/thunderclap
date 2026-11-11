// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fcd30..0x000fdab0 (kind game, layer game, confidence high), dominant class CControllerAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8104e0e {
#define TREE_TU_END }
namespace fn_f8104e0e {} using namespace fn_f8104e0e;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8104e0e {
class pddiObject_fcde0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_fcde0 : public pddiObject_fcde0 {};
class pddiBaseShader_fcde0 : public pddiShader_fcde0 {
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
class d3dShader_fcde0 : public pddiBaseShader_fcde0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Obj_fce10 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
};
struct CControllerAgent_nv_fce10 {
    float helper_000fc4e0(hulk_intptr, int);
};
struct Vec3_fce60 { float x, y, z; };
struct Matrix_fce60 {
    float m[16];
    void FUN_0022baf0(const Vec3_fce60 *axis, float angle);
};
extern "C" hulk_freg FUN_00224ea0(float y, float x);
extern "C" void FUN_00224d70(float angle, Vec3_fce60 *v);
union FloatBits_fce60 {
    float f;
    unsigned int u;
};
struct Vec_fd010 { float x,y,z; hulk_freg FUN_0022d110(); };
struct Transform_fd010 {  };
extern void* hulk_at_0040d098[];
class CCharacterAgent_fd0c0 {
  public:
    void Destroy_000fc630(); // FUN_00236d60, __thiscall, this in ecx
};
class CControllerAgent_fd0c0 : public CCharacterAgent_fd0c0 {
  public:
    CControllerAgent_fd0c0* vfunc_5(signed char flags);
};
struct Vec3_fd8a0 { float x, y, z; };
struct Mat_fd8a0 {
    float m[16];
};
struct View {
    char data[0x10c];
};
struct ViewSource {
    void FUN_000b3660(View *out);
};
struct ViewTable {
    char pad0[4];
};
struct Owner_fd8a0 {
    char pad0[0x140];
    int mode;
    char pad144[0x1af8 - 0x144];
    Vec3_fd8a0 aim;
    char pad1b04[0x1ff8 - 0x1b04];
    int f1ff8;
    float f1ffc;
    float f2000;
    char pad2004[0x2034 - 0x2004];
    float f2034;
    float f2038;
    char pad203c[0x20a8 - 0x203c];
    int slot;
};
class Provider_fd8a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual Owner_fd8a0 *GetOwner();
};
struct Args_fd8a0 {
    char pad0[4];
    ViewTable *table;
};
extern "C" void FUN_000fce60(Mat_fd8a0 *m, Vec3_fd8a0 *axis, int a, int b, float c, float d, Vec3_fd8a0 *out);
extern "C" void FUN_000fd010(Mat_fd8a0 *m, int a, int b, float c, float d, Vec3_fd8a0 *out);
class Sweep_fd8a0 {
public:
    char pad0[0x58];
    Provider_fd8a0 *provider;
    char pad5c[0xa0 - 0x5c];
    unsigned char started;
    unsigned char flagA1;
    char pada2[2];
    Vec3_fd8a0 out1;
    Vec3_fd8a0 out2;
    Vec3_fd8a0 out3;
    Vec3_fd8a0 out4;
    int fd4;
    Mat_fd8a0 matrix;
    int f118;
    int f11c;
    void Start(Args_fd8a0 *args, const Mat_fd8a0 *m, int a, int b);
};

} // namespace fn_f8104e0e

// 0x000fcd30 FUN_000fcd30 (169 B): equivalent/0x000fcd30.cpp [wrapped: conflict: CControllerAgent]
// sym: ??0CControllerAgent@fn_000fcd30@@QAE@H@Z @19854f190322 @w883daac0687a
namespace fn_000fcd30 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000fcd30 @ 0x000fcd30

struct FUN_000fc760 {
 virtual void slot0();
 char pad04[0x58];
 int field5c, field60;
 float field64;
 FUN_000fc760(int arg);
};
struct CControllerAgent : FUN_000fc760 {
 virtual void slot0();
 float field68;
 unsigned char field6c, field6d;
 char pad6e[2];
 int field70, field74;
 float field78;
 int field7c;
 float field80;
 int field84;
 float values[6];
 unsigned char fielda0, fielda1;
 char pada2[0x32];
 int fieldd4;
 CControllerAgent(hulk_intptr arg);
};
CControllerAgent::CControllerAgent(hulk_intptr arg) : FUN_000fc760(arg) {
 for(int i=0;i<6;++i) values[i]=-1.0f;
 unsigned char initialized=(*(unsigned char*)&DAT_004e0a90);
 field6c=0; field74=0; field84=0; fielda0=0; fielda1=0; fieldd4=0;
 field68=0.2f; field6d=1; field70=-1; field78=0.01f; field7c=1; field80=0.1f;
 field5c=0; field60=0; field64=1.0f;
 if(!initialized) (*(unsigned char*)&DAT_004e0a90)=1;
}
} // namespace fn_000fcd30


// 0x000fcde0 CControllerAgent::vfunc_10 (6 B): matches/0x000fcde0.cpp
// sym: ?vfunc_10@CControllerAgent@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int CControllerAgent::vfunc_10() {
    return 1;
}


// 0x000fce00 CControllerAgent::vfunc_9 (8 B): matches/0x000fce00.cpp
// sym: ?vfunc_9@CControllerAgent@@UAEXXZ
void CControllerAgent::vfunc_9() {
    (*(float *)&this->f_08) = 100.0f;
}


// 0x000fce10 CControllerAgent::vfunc_3 (68 B): matches/0x000fce10.cpp
// sym: ?vfunc_3@CControllerAgent@@UAEMHH@Z
hulk_freg CControllerAgent::vfunc_3(hulk_intptr a, int b) {
    ((CControllerAgent_nv_fce10*)this)->helper_000fc4e0(a, b);
    hulk_intptr x = (*(Obj_fce10 * *)&this->f_58)->f6();
    if (*(int*)((char*)x + 0x20a8) >= 0)
        *(float*)((char*)this + 8) = 100.0f;
    else
        *(float*)((char*)this + 8) = 0.0f;
    return *(float*)((char*)this + 8);
}

namespace fn_f8104e0e {

// 0x000fce60 FUN_000fce60 (423 B): equivalent/0x000fce60.cpp
// sym: ?FUN_000fce60@fn_f8104e0e@@YAXPAUMatrix_fce60@1@PAUVec3_fce60@1@HHMM1@Z @19df9a0820a9 @w0e2c06f0d38a
// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 4/4)
// FUN_000fce60 @ 0x000fce60
// local is the 3x3 rotation matrix (0x2c bytes) built by Matrix::build (0x0022baf0)
// FUN_000fce60 @ 0x000fce60
void FUN_000fce60(Matrix_fce60 *rot, Vec3_fce60 *axis, int unused2, int unused3, float a4, float a5, Vec3_fce60 *out)
{
    FloatBits_fce60 fy;
    fy.f = axis->y;
    fy.u &= 0x7fffffff;

    if (fy.f <= 0.001f) {
        Matrix_fce60 q;
        Vec3_fce60 up;
        q.FUN_0022baf0(axis, -(FUN_00224ea0(a4, a5) + 3.14159274101257f));
        up.x = 0.0f;
        up.y = 1.0f;
        up.z = 0.0f;
        ((owners::M_22c3b0 *)&q)->FUN_0022c3b0((float *)(const Vec3_fce60 *)(&up), (float *)(Vec3_fce60 *)out);
    } else {
        Vec3_fce60 fwd;
        Vec3_fce60 w;
        fwd.x = 0.0f;
        fwd.y = 0.0f;
        fwd.z = 1.0f;
        ((owners::M_22c3b0 *)rot)->FUN_0022c3b0((float *)(const Vec3_fce60 *)(&fwd), (float *)(Vec3_fce60 *)(&w));
        float heading = FUN_00224ea0(w.x, w.z);
        float angle = (FUN_00224ea0(a4, a5) + 3.14159274101257f) + heading;
        out->x = DAT_004a1aa0;
        out->y = (*(float*)&DAT_004a1aa4);
        out->z = (*(float*)&DAT_004a1aa8);
        FUN_00224d70(angle, out);
        out->x = DAT_004a1aa0;
        out->y = (*(float*)&DAT_004a1aa4);
        out->z = (*(float*)&DAT_004a1aa8);
        FUN_00224d70(angle, out);
    }

    FloatBits_fce60 b4, b5;
    b4.f = a4;
    b4.u &= 0x7fffffff;
    b5.f = a5;
    b5.u &= 0x7fffffff;
    float s = (b4.f > b5.f) ? b4.f : b5.f;
    out->x = s * out->x;
    out->y = s * out->y;
    out->z = s * out->z;
}


// 0x000fd010 FUN_000fd010 (176 B): equivalent/0x000fd010.cpp
// sym: ?FUN_000fd010@fn_f8104e0e@@YAXPAUTransform_fd010@1@IIMMPAUVec_fd010@1@@Z @ab4afeffae7f @w375d0e9f9e7c
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000fd010 @ 0x000fd010
void __cdecl FUN_000fd010(Transform_fd010* transform, unsigned int unused1, unsigned int unused2, float a, float b, Vec_fd010* output)
{
    Vec_fd010 input;
    input.x=a; input.y=b; input.z=0.0f;
    ((owners::M_22c3b0 *)transform)->FUN_0022c3b0((float *)(Vec_fd010 *)(&input), (float *)(Vec_fd010 *)output);
    output->FUN_0022d110();
    union Bits { float f; unsigned int u; } aa,bb;
    aa.f=a; bb.f=b;
    aa.u &= 0x7fffffff; bb.u &= 0x7fffffff;
    float scale = aa.f > bb.f ? aa.f : bb.f;
    output->x = scale * output->x;
    output->y = scale * output->y;
    output->z = scale * output->z;
}


// 0x000fd0c0 CControllerAgent::vfunc_2 (36 B): matches/0x000fd0c0.cpp
// sym: ?vfunc_5@CControllerAgent_fd0c0@fn_f8104e0e@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CControllerAgent_fd0c0* CControllerAgent_fd0c0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0040d098;
    Destroy_000fc630();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x000fd8a0 FUN_000fd8a0 (423 B): equivalent/0x000fd8a0.cpp
// sym: ?Start@Sweep_fd8a0@fn_f8104e0e@@QAEXPAUArgs_fd8a0@2@PBUMat_fd8a0@2@HH@Z @a337b207b872 @w77ceab8ce9b0
// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 8/8)
// FUN_000fd8a0 @ 0x000fd8a0
void Sweep_fd8a0::Start(Args_fd8a0 *args, const Mat_fd8a0 *m, int a, int b)
{
    Owner_fd8a0 *o = provider->GetOwner();
    Vec3_fd8a0 v;
    if (o->mode == 4) {
        v = o->aim;
    } else {
        v.x = 0.0f;
        v.y = 1.0f;
        v.z = 0.0f;
    }

    int slot = o->slot;
    if (slot >= 0 && slot < 4) {
        View view;
        ((ViewSource *)((owners::C_b3d20 *)(args->table))->FUN_000b3d20(slot))->FUN_000b3660(&view);
    }

    fd4 = o->f1ff8;
    if (started)
        return;

    started = 1;
    flagA1 = 0;
    matrix = *m;
    f118 = a;
    f11c = b;

    float c1 = o->f1ffc;
    float d1 = o->f2000;
    FUN_000fce60(&matrix, &v, a, b, c1, d1, &out1);
    FUN_000fd010(&matrix, f118, f11c, c1, d1, &out3);

    float c2 = o->f2034;
    float d2 = o->f2038;
    FUN_000fce60(&matrix, &v, f118, f11c, c2, d2, &out2);
    FUN_000fd010(&matrix, f118, f11c, c2, d2, &out4);
}

} // namespace fn_f8104e0e
