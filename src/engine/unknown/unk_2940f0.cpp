// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002940f0..0x00294a10 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5f765cb {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5f765cb {} using namespace fn_f5f765cb;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f5f765cb {
struct Vec_2940f0 { float x,y,z; };
struct System_2940f0 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float s16(); };
struct Vec_2941b0 { float x,y,z; };
struct Source_2941b0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void getFactors(float*,float*);
};
struct Screen_2941b0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual int height(); virtual int width();
};
struct Vector { float x,y,z; };
struct Display_294270 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int width(); virtual int height(); };
struct Aspect_294270 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void get(float*,float*); };
struct Vec3_294500 {
    float x, y, z;
};
struct Buf_294500 {
    char pad[12];
};
struct Sub_294500 {
    unsigned int getval_0028faa0();
};
struct Mgr_294500 {
    Sub_294500* sub;
};
struct Obj_294500 {
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
    virtual unsigned int get();
};
class Target_294500 {
  public:
    char pad[0x18];
    Obj_294500* obj;
    void run(Vec3_294500 a, Buf_294500* out);
};
struct T_294620 {
    int x, y, z;
};
class C_294620 {
  public:
    void Prep_00294270(T_294620* a, T_294620* out);
    void Finish_00294550(T_294620 t, int d, int e);
    void Target(T_294620 a, int d, int e);
};
struct Vec3_294670 { float x, y, z; };
struct Matrix { float m[16]; };
struct Camera {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void s6(float* angle,float* scale);
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual Matrix* v13();
    Matrix* FUN_0028faa0();
};
struct Owner_2940f0 { char pad[24]; Camera* camera; void target(const Vec_2940f0* in,Vec_2940f0* out); };
struct Vec3Ops_294670 : Vec3_294670 {
};
class Target_294670 {
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
    virtual Matrix* v13();
};
struct View {
    char pad00[0x18];
    Target_294670* target;      // 0x18
    void FUN_002940f0(const Vec3_294670* a, const Vec3_294670* b);
    void FUN_002941b0(const Vec3_294670* a, float* out);
    void Project(Vec3_294670 pos, float* out);
};
struct Vec3_2946e0 {
    unsigned int x, y, z;
};
class Source_2946e0 {
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
    virtual unsigned int Get();
};
struct Scratch_2946e0 {
    char data[12];
};
class Owner_2946e0 {
  public:
    char pad[0x18];
    Source_2946e0* source;
    void Process_002940f0(Scratch_2946e0*, unsigned int);
    void Run(Vec3_2946e0 a, unsigned int d);
};
struct Vec_294720 { float x,y,z;  };
struct Object {
  public:
    char _m_pad_0[0x8];
    float left;
    float top;
    float right;
    float bottom;
    union { Aspect_294270* aspect; Camera* camera; Source_2941b0* source; };
    void target(Vec_2941b0* input, Vec_2941b0* output);
    void transform(Vector* in,Vector* out);
    void FUN_00294720(float x,float y,float z,Vec_294720* out);
};
struct Context { Matrix* FUN_0028faa0(); };
struct V3_2947e0 {
    float x, y, z;
};
struct Matrix4_2947e0 {
    float m[16];
};
class Frame_2947e0 {
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
    virtual Matrix4_2947e0 *GetMatrix();
};
class Holder_2947e0 {
public:
    void FUN_002947e0(V3_2947e0 in, V3_2947e0 *out);

    char pad0[0x18];
    Frame_2947e0 *frame;
};
struct Mat_294880 { char data[0x40]; void FUN_0022b980(); };
namespace pure3d {
class View {
  public:
    View();
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    int refCount;
    int f08, f0c;
    float f10, f14;
    int f18;
    unsigned int ambient;
    unsigned int clearColor;
    float f24;
    int f28, f2c, f30, f34, f38;
    int zeros[32];
    unsigned char flag;
    char pad_bd[3];
    Mat_294880 m0;
    Mat_294880 m1;
};
}
class Item_294980 {
  public:
    virtual void First();
    virtual void Second();
};
class Owner_294980 {
    char pad[0x18];

  public:
    Item_294980* item;
    void Set(Item_294980* p);
};
class Item_2949e0 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_2949e0 {
  public:
    char pad[0x3c];
    Item_2949e0* items[0x20];
    void Clear();
};


// 0x002940f0 FUN_002940f0 (187 B): equivalent/0x002940f0.cpp
// sym: ?target@Owner_2940f0@fn_f5f765cb@@QAEXPBUVec_2940f0@2@PAU32@@Z
// STATUS: equivalent (tools/equiv.py level 3: 29 inputs, branch coverage 4/4)
// FUN_002940f0 @ 0x002940f0
void Owner_2940f0::target(const Vec_2940f0* in,Vec_2940f0* out) {
 if (!camera) return;
 if (in->z == 0.0f) { out->x=0.0f; out->y=0.0f; out->z=1.0f; return; }
 float inverseDepth=1.0f/in->z;
 float scale,angle;
 camera->s6(&angle,&scale);
 double adjustedScale=(*(System_2940f0**)&DAT_0052c2a4)->s16()* (double)scale;
 double focal=1.0/tan((double)angle*0.5f);
 out->x=(float)(focal*in->x*inverseDepth*0.5f);
 out->y=(float)(focal*adjustedScale*in->y*inverseDepth*0.5f);
 out->z=in->z;
}


// 0x002941b0 FUN_002941b0 (189 B): equivalent/0x002941b0.cpp
// sym: ?target@Object@fn_f5f765cb@@QAEXPAUVec_2941b0@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002941b0 @ 0x002941b0
void Object::target(Vec_2941b0* input, Vec_2941b0* output) {
 if (!source) return;
 union { Vec_2941b0* pointer; float value; } factor;
 factor.pointer=output;
 float unused;
 output->z=0.0f;
 source->getFactors(&unused,&factor.value);
 output->x=(right-left)*(input->x+0.5f)+(left-0.5f);
 output->y=(factor.value*input->y-0.5f)*(bottom-top)+(0.5f-top);
 int width=(*(Screen_2941b0**)&DAT_0052c2a4)->width();
 output->x=(output->x+0.5f)*width;
 int height=(*(Screen_2941b0**)&DAT_0052c2a4)->height();
 output->y=(1.0f-(output->y+0.5f))*height;
}


// 0x00294270 FUN_00294270 (205 B): equivalent/0x00294270.cpp
// sym: ?transform@Object@fn_f5f765cb@@QAEXPAUVector@2@0@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00294270 @ 0x00294270
void Object::transform(Vector* in,Vector* out) {
 int h=(*(Display_294270**)&DAT_0052c2a4)->height();
 float x=(float)((double)in->x/h-0.5f);
 int w=(*(Display_294270**)&DAT_0052c2a4)->width();
 float z=in->z;
 float y=(float)(1.0f-(double)in->y/w-0.5f);
 union { int integer; float real; } unused;
 unused.integer=w;
 float scale;
 if(aspect) aspect->get(&unused.real,&scale); else scale=1.0f;
 out->x=(float)(((double)x+0.5f-left)/((double)right-left)-0.5f);
 out->z=z;
 out->y=(float)((0.5f-(0.5f-(double)y-top)/((double)bottom-top))/scale);
}

} // namespace fn_f5f765cb

// 0x00294340 FUN_00294340 (238 B): equivalent/0x00294340.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_00294340@Object@fn_00294340@@QAEXPAUVec3_294340@2@00@Z
namespace fn_00294340 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00294340 @ 0x00294340

struct Vec3_294340 { float x,y,z; };
struct Camera {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5();
 virtual void parameters(float* angle, float* scale);
 virtual void slot7(); virtual float nearPlane(); virtual void slot9(); virtual float farPlane();
};
struct System_294340 { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual float aspect(); };

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl tan(double);
#endif

struct Object { char pad[24]; Camera* camera; void FUN_00294340(Vec3_294340* input, Vec3_294340* nearOut, Vec3_294340* farOut); };
void Object::FUN_00294340(Vec3_294340* input, Vec3_294340* nearOut, Vec3_294340* farOut) {
 if (!camera) return;
 float scale,angle;
 camera->parameters(&angle,&scale);
 double scaled = (*(System_294340**)&DAT_0052c2a4)->aspect() * (double)scale;
 double cot = 1.0 / tan(angle * 0.5);
 float horizontal=(float)cot;
 float vertical=(float)(cot*scaled);
 float inverseNear=1.0f/camera->nearPlane();
 float inverseFar=1.0f/camera->farPlane();
 nearOut->x=(float)(input->x / ((double)inverseNear*horizontal*0.5));
 nearOut->y=(float)(input->y / ((double)inverseNear*vertical*0.5));
 nearOut->z=camera->nearPlane();
 farOut->x=(float)(input->x / ((double)inverseFar*horizontal*0.5));
 farOut->y=(float)(input->y / ((double)inverseFar*vertical*0.5));
 farOut->z=camera->farPlane();
}
} // namespace fn_00294340

namespace fn_f5f765cb {

// 0x00294500 FUN_00294500 (69 B): matches/0x00294500.cpp
// sym: ?run@Target_294500@fn_f5f765cb@@QAEXUVec3_294500@2@PAUBuf_294500@2@@Z
// data: gmgr = DAT_0052c2b0
// a..c: a vector passed by value.
void Target_294500::run(Vec3_294500 a, Buf_294500* out) {
    Buf_294500 local;
    ((owners::C_22d240 *)&local)->FUN_0022d240((hulk_intptr)(&a), (hulk_intptr)((*(Mgr_294500**)&DAT_0052c2b0)->sub->getval_0028faa0()));
    if (obj) {
        unsigned int v = obj->get();
        ((owners::C_22d240 *)out)->FUN_0022d240((hulk_intptr)(&local), (hulk_intptr)v);
    }
}

} // namespace fn_f5f765cb

// 0x00294550 FUN_00294550 (197 B): equivalent/0x00294550.cpp [wrapped: merged class would differ: Matrix: size 1 vs 64]
// sym: ?target@Object@fn_00294550@@QAEXUVec_294550@2@PAU32@1@Z
namespace fn_00294550 {
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 4/4)
// FUN_00294550 @ 0x00294550

struct Matrix { unsigned int data[16];  };
struct Vec_294550 { float x,y,z; Vec_294550* FUN_0022d240(const Vec_294550*, const Matrix*); };
struct Parent_294550 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual Matrix* v14(); };
struct Camera { Matrix* FUN_0028faa0(); };
struct Object { char pad[24]; Parent_294550* parent; void FUN_00294340(Vec_294550*,Vec_294550*,Vec_294550*); void target(Vec_294550 a,Vec_294550* out1,Vec_294550* out2); };
void Object::target(Vec_294550 a,Vec_294550* out1,Vec_294550* out2) {
 Vec_294550 first,second;
 FUN_00294340(&a,&first,&second);
 if(parent) { first.FUN_0022d240(&first,parent->v14()); if(parent) second.FUN_0022d240(&second,parent->v14()); }
 Matrix m = *(*(*(Camera***)&DAT_0052c2b0))->FUN_0028faa0();
 ((owners::Matrix_22c120 *)&m)->FUN_0022c120();
 out1->FUN_0022d240(&first,&m);
 m = *(*(*(Camera***)&DAT_0052c2b0))->FUN_0028faa0();
 ((owners::Matrix_22c120 *)&m)->FUN_0022c120();
 out2->FUN_0022d240(&second,&m);
}
} // namespace fn_00294550

namespace fn_f5f765cb {

// 0x00294620 FUN_00294620 (72 B): matches/0x00294620.cpp
// sym: ?Target@C_294620@fn_f5f765cb@@QAEXUT_294620@2@HH@Z
void C_294620::Target(T_294620 a, int d, int e) {
    T_294620 t;
    Prep_00294270(&a, &t);
    Finish_00294550(t, d, e);
}


// 0x00294670 FUN_00294670 (106 B): equivalent/0x00294670.cpp
// sym: ?Project@View@fn_f5f765cb@@QAEXUVec3_294670@2@PAM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00294670 @ 0x00294670
void View::Project(Vec3_294670 pos, float* out)
{
    if (target == 0)
        return;
    Vec3Ops_294670 local;
    ((owners::C_22d240 *)&local)->FUN_0022d240((hulk_intptr)(const Vec3_294670 *)(&pos), (hulk_intptr)(const Matrix *)((*(*(Camera***)&DAT_0052c2b0))->FUN_0028faa0()));
    if (target != 0)
        ((owners::C_22d240 *)&local)->FUN_0022d240((hulk_intptr)(const Vec3_294670 *)(&local), (hulk_intptr)(const Matrix *)(target->v13()));
    FUN_002940f0(&local, &local);
    FUN_002941b0(&local, out);
}


// 0x002946e0 FUN_002946e0 (59 B): matches/0x002946e0.cpp
// sym: ?Run@Owner_2946e0@fn_f5f765cb@@QAEXUVec3_2946e0@2@I@Z
// a..c: a vector passed by value.
void Owner_2946e0::Run(Vec3_2946e0 a, unsigned int d) {
    if (source) {
        unsigned int x = source->Get();
        Scratch_2946e0 temp;
        ((owners::C_22d240 *)&temp)->FUN_0022d240((hulk_intptr)(&a), (hulk_intptr)x);
        Process_002940f0(&temp, d);
    }
}


// 0x00294720 FUN_00294720 (185 B): equivalent/0x00294720.cpp
// sym: ?FUN_00294720@Object@fn_f5f765cb@@QAEXMMMPAUVec_294720@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 20009 inputs, branch coverage 4/4)
// FUN_00294720 @ 0x00294720
void Object::FUN_00294720(float x,float y,float z,Vec_294720* out) {
 if (!camera) return;
 Vec_294720 v; v.x=x; v.y=y; v.z=z;
 ((owners::Obj_22d210 *)&v)->FUN_0022d210((owners::Obj_22d210 *)(Matrix *)((*(*(Context***)&DAT_0052c2b0))->FUN_0028faa0()));
 ((owners::Obj_22d210 *)&v)->FUN_0022d210((owners::Obj_22d210 *)(Matrix *)(camera->v13()));
 if (v.z != 0.0f) { hulk_freg inverse=1.0f / v.z; out->z=v.z; out->x=v.x*inverse*0.5f; out->y=v.y*inverse*0.5f; }
 else { out->x=0.0f; out->y=0.0f; out->z=1.0f; }
}


// 0x002947e0 FUN_002947e0 (123 B): equivalent/0x002947e0.cpp
// sym: ?FUN_002947e0@Holder_2947e0@fn_f5f765cb@@QAEXUV3_2947e0@2@PAU32@@Z
// STATUS: equivalent (tools/equiv.py level 3: 19853 inputs, branch coverage 4/4)
// FUN_002947e0 @ 0x002947e0
void Holder_2947e0::FUN_002947e0(V3_2947e0 in, V3_2947e0 *out) {
    if (frame == 0) {
        return;
    }
    V3_2947e0 local;
    ((owners::Mat_22c2b0 *)(frame->GetMatrix()))->FUN_0022c2b0((float *)(const V3_2947e0 *)(&in), (float *)(V3_2947e0 *)(&local));
    if (local.z == 0.0f) {
        out->x = 0;
        out->y = 0;
        out->z = 1.0f;
    } else {
        hulk_freg h = 0.5f / local.z;
        *(unsigned *)&out->z = *(unsigned *)&local.z;  // raw copy, no FPU round trip
        out->x = local.x * h;
        out->y = local.y * h;
    }
}


// 0x00294880 FUN_00294880 (249 B): equivalent/0x00294880.cpp
// sym: ??0View@pure3d@fn_f5f765cb@@QAE@XZ
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_00294880 @ 0x00294880
pure3d::View::View() {
    refCount = 0;
    f08 = 0;
    f0c = 0;
    f18 = 0;
    clearColor = 0xff000000;
    f28 = 0;
    ambient = 0xff101010;
    f14 = 1.0f;
    f10 = 1.0f;
    f24 = 1.0f;
    for (int i = 0; i < 32; i++) zeros[i] = 0;
    f2c = 3;
    flag = 0;
    f30 = -1;
    f38 = 0;
    f34 = 0;
    m0.FUN_0022b980();
    m1.FUN_0022b980();
}


// 0x00294980 FUN_00294980 (38 B): matches/0x00294980.cpp
// sym: ?Set@Owner_294980@fn_f5f765cb@@QAEXPAVItem_294980@2@@Z
// Same code shape as 0x00059d00 (propagated; names are from that function)
void Owner_294980::Set(Item_294980* p) {
    if (p)
        p->First();
    if (item)
        item->Second();
    item = p;
}


// 0x002949e0 FUN_002949e0 (42 B): matches/0x002949e0.cpp
// sym: ?Clear@Owner_2949e0@fn_f5f765cb@@QAEXXZ
void Owner_2949e0::Clear() {
    for (int i = 0; i < 0x20; ++i) {
        if (items[i]) {
            items[i]->B();
            items[i] = 0;
        }
    }
}

} // namespace fn_f5f765cb
