// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e9030..0x000e92d0 (kind game, layer game, confidence medium), dominant class FEObject
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_faa2c089 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faa2c089 {} using namespace fn_faa2c089;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_faa2c089 {
extern void* hulk_at_0040c208[];
class Ref_e9030 {
  public:
    virtual void F0();
    virtual void Release();
};
} // namespace fn_faa2c089
void operator delete[](void*) throw();
namespace fn_faa2c089 {
struct Sub_e9030 {
    char c;
};
class FEObject_e9030 {
  public:
    void* vptr;
    char p[0x14];
    Sub_e9030 s18;
    char p2[0x37];
    Ref_e9030* m50;
    char p3[0xc];
    Ref_e9030* m60;
    Ref_e9030* m64;
    char p4[0x44];
    char* mac;
    ~FEObject_e9030() throw();
};
struct Vec2f { float x, y, z; };
class Ref_e9090 {
public:
    virtual void AddRef();
    virtual void Release();
};
class Host_e9090;
class Source_e9090 {
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
    virtual void v15(Vec2f *out, Host_e9090 *h);
};
extern "C" void __cdecl FUN_000f69e0(Ref_e9090 *r, Vec2f *out);
class Host_e9090 {
public:
    char pad0[0x14];
    Source_e9090 *src;
    char pad1[0x50 - 0x18];
    Ref_e9090 *cur;
    float f54;
    float f58;
    float f5c;
    void FUN_000e9090(Ref_e9090 *r);
};
struct Frame_e9090 {
    Vec2f a;
    Vec2f b;
};
class Thing_e9100 {
  public:
    virtual void A();
    virtual void B();
};
class Owner_e9100 {
  public:
    char pad[0x60];
    Thing_e9100* mThing;
    void Set(Thing_e9100* p);
};
class NewItem {
  public:
    virtual void Dispose();
};
class OldItem {
  public:
    virtual void First();
    virtual void Release();
};
class Owner_e9130 {
  public:
    char pad[0x64];
    OldItem* item;
    void Set(NewItem* p);
};
struct FEObject;
struct Source_e9160 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void* s44();
};
struct Link_e9160 { char pad[4]; Source_e9160* source; };
struct Triple_e9160 { float x,y,z; };
struct Owner_e9160 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual int s15(Triple_e9160*,FEObject*); virtual float s16(FEObject*); virtual float s17(FEObject*);
 char pad[4]; Link_e9160* link;
};
struct Matrix {
 struct Row {float a,b,scale,d;} rows[8]; char pad[8]; int index; int tail;
 void FUN_000f7fe0(void*);
 hulk_freg FUN_000f8840(Triple_e9160*);
 hulk_freg FUN_000f88a0(Triple_e9160*);
};
extern "C" void FUN_000f78e0();
struct FEObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual int vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
 char pad04[16]; Owner_e9160* owner; Triple_e9160 position; char pad24[0x48]; int mode; char pad70[8]; float offset; char pad7c[0x1c]; unsigned char dirty; char pad99[3]; float x,y;
};
class FEObject_e9240 {
public:
    FEObject_e9240(int arg) throw();
    virtual void v0_000e1360();
    char pad04[0x44 - 4];
    int link;
    char pad48[0x118 - 0x48];
};
class FEControl : public FEObject_e9240 {
public:
    FEControl(int arg) throw();
    virtual void c0_000d79f0(int);
    int slots[10];
    bool flag0;
    bool flag1;
    bool flag2;
    bool flag3;
    char flag4;
    char pad145[3];
    int link0;
    int link1;
};
class CEffectStopTrack {
  public:
};
void __fastcall FUN_000e9030(CEffectStopTrack*);


// 0x000e9030 FUN_000e9030 (92 B): matches/0x000e9030.cpp
// sym: ??1FEObject_e9030@fn_faa2c089@@QAE@XZ
FEObject_e9030::~FEObject_e9030() throw() {
    vptr = hulk_at_0040c208;
    _ReadWriteBarrier();
    if (m50) {
        m50->Release();
        m50 = 0;
    }
    if (m60) {
        m60->Release();
        m60 = 0;
    }
    if (m64) {
        m64->Release();
        m64 = 0;
    }
    if (mac) {
        operator delete[](mac);
        mac = 0;
    }
    ((owners::Thing_f7960 *)&s18)->FUN_000f7960();
}


// 0x000e9090 FUN_000e9090 (107 B): equivalent/0x000e9090.cpp
// sym: ?FUN_000e9090@Host_e9090@fn_faa2c089@@QAEXPAVRef_e9090@2@@Z @6869adcad9fa @w6ac87299b8cf
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000e9090 @ 0x000e9090
void Host_e9090::FUN_000e9090(Ref_e9090 *r)
{
    Frame_e9090 f;
    if (r != 0)
        r->AddRef();
    if (cur != 0)
        cur->Release();
    cur = r;
    if (r != 0) {
        FUN_000f69e0(r, &f.b);
        src->v15(&f.a, this);
        f5c = 1.0f;
        f54 = f.a.x / f.b.x;
        f58 = f.a.y / f.b.y;
    }
}


// 0x000e9100 FUN_000e9100 (38 B): matches/0x000e9100.cpp
// sym: ?Set@Owner_e9100@fn_faa2c089@@QAEXPAVThing_e9100@2@@Z
void Owner_e9100::Set(Thing_e9100* p) {
    if (p)
        p->A();
    if (mThing)
        mThing->B();
    mThing = p;
}


// 0x000e9130 FUN_000e9130 (38 B): matches/0x000e9130.cpp
// sym: ?Set@Owner_e9130@fn_faa2c089@@QAEXPAVNewItem@2@@Z
void Owner_e9130::Set(NewItem* p) {
    if (p)
        p->Dispose();
    if (item)
        item->Release();
    item = (OldItem*)p;
}


// 0x000e9160 FEObject::vfunc_3 (213 B): equivalent/0x000e9160.cpp
// sym: ?vfunc_3@FEObject@fn_faa2c089@@UAEHXZ @a43bea5f3d88 @wd8aadeec3cbb
// STATUS: equivalent (tools/equiv.py level 3: 13613 inputs, branch coverage 6/6)
// FEObject::vfunc_3 @ 0x000e9160
int FEObject::vfunc_3() {
 Matrix matrix;
 matrix.FUN_000f7fe0(owner->link->source->s44());
 float scale = owner->s17(this);
 matrix.rows[matrix.index].scale = owner->s16(this)*scale;
 x = matrix.FUN_000f8840(&position);
 y = matrix.FUN_000f88a0(&position);
 int result=mode;
 if(mode==0) { Triple_e9160 t; result=owner->s15(&t,this); offset=t.x * -0.5f; }
 else if(mode==1) { result=0; offset=0.0f; }
 else if(mode==2) { Triple_e9160 t; result=owner->s15(&t,this); offset=t.x * 0.5f; }
 else result-=2;
 dirty=1;
 FUN_000f78e0();
 return result;
}


// 0x000e9240 FUN_000e9240 (109 B): equivalent/0x000e9240.cpp
// sym: ??0FEControl@fn_faa2c089@@QAE@H@Z @971a701e3786 @w48119c2d8486
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e9240 @ 0x000e9240
// equiv-map: ??0FEBase@@QAE@H@Z = 0x000e2860
FEControl::FEControl(int arg) throw() : FEObject_e9240(arg)
{
    for (int i = 0; i < 10; i++)
        slots[i] = 0;
    flag0 = true;
    flag1 = true;
    flag2 = true;
    flag3 = true;
    link0 = link;
    link1 = link;
    flag4 = 0;
}


// 0x000e92b0 FUN_000e92b0 (11 B): matches/0x000e92b0.cpp
// sym: ?FUN_000e92b0@fn_faa2c089@@YIXPAVCEffectStopTrack@1@@Z
// Same code shape as 0x00060920 (propagated; names are from that function)
void __fastcall FUN_000e92b0(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&CEffectStopTrack_vftable;
    FUN_000e9030(self);
}

} // namespace fn_faa2c089
