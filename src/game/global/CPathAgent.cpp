// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001047b0..0x00106170 (kind game, layer game, confidence high), dominant class CPathAgent
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f58850d5 {
#define TREE_TU_END }
namespace fn_f58850d5 {} using namespace fn_f58850d5;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f58850d5 {
class C_1048d0 {
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
    char pad[0x58];
    int value;
    void set(hulk_intptr x);
};
class Helper_1048f0 {
  public:
    float Fnf_000fc4e0(hulk_intptr, int);
};
extern volatile const float hulk_at_003f32e0;
class X_104920 {
  public:
    char pad[0x88];
    unsigned char value;
};
struct PathState {
    char pad[0x68];
    unsigned char blocked;
    char pad69;
    unsigned char active;
    char pad6b;
    float value;
};
class Thing_104970 {
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
    char pad[0xbc - 4];
    int value;
    void Set(int);
};
typedef unsigned int u32_104a70;
void thunk_FUN_00267090(u32_104a70);
struct Obj_104a70 {
    u32_104a70 a;
    char pad[8];
    u32_104a70 b;
};
extern "C" void __cdecl thunk_FUN_00267090(void*);
struct Obj_104b20 {
  public:
    void* field0;
    char pad[8];
    void* fieldC;
    void* func(unsigned char b);
};
struct Vec_104c60 { int x, y, z; };
struct Sub_104c60 { char pad[0x75]; char v75; };
struct CPathAgent_104c60 {
 char pad0[0x60]; Sub_104c60* sub; char pad1[4];
 int v68, v6c;
 Vec_104c60 p70, p7c;
 char v88, v89, pad2[2];
 int v8c; char v90; char pad3[3];
 int v94, v98;
 char pad4[0xd8 - 0x9c];
 int vd8, vdc, ve0, ve4;
 int Reset(int a, int b, const Vec_104c60* pos, int c, char d, int e, int unused);
};
struct V3_104d00 {
    float x, y, z;
    hulk_freg FUN_0022d110();
};
struct Mode_104d00 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int vfunc_9();
};
struct Agent_104d00 {
    char pad0[0x1a60];
    V3_104d00 pos;                 // 0x1a60
    char pad1a6c[0x1ca0 - 0x1a6c];
    Mode_104d00 *mode;             // 0x1ca0
    char pad1ca4[0x2064 - 0x1ca4];
    V3_104d00 out1;                // 0x2064
    float outK;             // 0x2070
    V3_104d00 out2;                // 0x2074
    void FUN_00035550(V3_104d00 *out);
};
struct Target_104d00;
struct Sub58_104d00 {
    char pad0[8];
    Target_104d00 *tgt;            // 0x8
};
struct Target_104d00 {
    char pad0[8];
    Agent_104d00 *agent;           // 0x8
    int kind;               // 0xc
    char pad10[0x40 - 0x10];
    V3_104d00 pos40;
};
class Owner58 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Agent_104d00 *vfunc_6();
    char pad04[0x58 - 4];
    Sub58_104d00 sub58;
};
extern "C" char DAT_0040d518[];
struct Root_105ef0 {
    char pad[0x1c];
    void* sub;
};
extern Root_105ef0* hulk_at_004dd700;
struct Sub_105ef0 {
};
extern void __cdecl Ref_0008d340(void*);
class CPathGraphAgent_105ef0 {
  public:
    void* vptr;
    char p1[0x58];
    char p2[0x34];
    void* mB;
    void* mBcopy;
    char p3[0x2c];
    void* mA;
    void* mAcopy;
};
extern void __fastcall Finish_000fc630(CPathGraphAgent_105ef0*);

} // namespace fn_f58850d5

// 0x001047b0 FUN_001047b0 (253 B): equivalent/0x001047b0.cpp [wrapped: conflict: CPathAgent]
// sym: ??0CPathAgent@fn_001047b0@@QAE@PAUArg_1047b0@1@@Z
namespace fn_001047b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001047b0 @ 0x001047b0
struct Resource_1047b0 { virtual void retain(); };
struct Arg_1047b0 { Resource_1047b0* FUN_000fefa0(); };
struct FUN_000fc760 {
    FUN_000fc760(Arg_1047b0*);
    virtual void baseVirtual();
    char pad[0x58];
};
struct Obj_1047b0 { virtual void retain(); Obj_1047b0* FUN_00109ba0(); };
extern "C" void* __cdecl FUN_0008d690(unsigned);
struct CPathAgent : FUN_000fc760 {
    unsigned f5c;
    Resource_1047b0* f60;
    unsigned f64,f68,f6c,f70,f74,f78;
    char pad7c[12];
    unsigned char f88,f89; char pad8a[2];
    float f8c; unsigned char f90,f91; char pad92[2];
    float f94,f98; unsigned f9c; char pada0[28];
    unsigned fbc,fc0,fc4; Obj_1047b0* fc8; char padcc[12];
    unsigned fd8,fdc,fe0,fe4,fe8,fec,ff0,ff4; float ff8;
    virtual void baseVirtual();
    CPathAgent(Arg_1047b0*);
};
CPathAgent::CPathAgent(Arg_1047b0* arg) : FUN_000fc760(arg) {
 f5c=0; f6c=0;
 f60=arg->FUN_000fefa0(); f60->retain();
 f64=0; f68=0; f70=0; f74=0; f78=0;
 f88=0; f89=1; f90=0; f91=0; f9c=0;
 f8c=1.0f; f94=1.0f; f98=1.0f;
 fc4=0; fc0=0; fbc=0; fe0=0; fdc=0; fd8=0; fe4=0; ff0=0; fec=0; fe8=0; ff4=0; ff8=999.0f;
 Obj_1047b0* p=(Obj_1047b0*)FUN_0008d690(0x38);
 fc8=p ? p->FUN_00109ba0() : 0;
 fc8->retain();
}
} // namespace fn_001047b0


// 0x001048b0 CPathAgent::vfunc_11 (30 B): matches/0x001048b0.cpp
// sym: ?vfunc_11@CPathAgent@@UAEXHHH@Z
void CPathAgent::vfunc_11(int x, int y, int z) {
    this->f_7c = x;
    this->f_80 = y;
    this->f_84 = z;
}

namespace fn_f58850d5 {

// 0x001048d0 FUN_001048d0 (28 B): matches/0x001048d0.cpp
// sym: ?set@C_1048d0@fn_f58850d5@@QAEXH@Z
void C_1048d0::set(hulk_intptr x) {
    if (value != x) {
        f9();
        value = x;
    }
}

} // namespace fn_f58850d5

// 0x001048f0 CPathAgent::vfunc_3 (39 B): matches/0x001048f0.cpp
// sym: ?vfunc_3@CPathAgent@@UAEMHH@Z
// Same code shape as 0x00102b60 (propagated; names are from that function)
hulk_freg CPathAgent::vfunc_3(hulk_intptr x, int y) {
    ((Helper_1048f0*)this)->Fnf_000fc4e0(x, y);
    float z = hulk_at_003f32e0;
    *(int*)((char*)this + 8) = 0;
    return z;
}

namespace fn_f58850d5 {

// 0x00104920 FUN_00104920 (7 B): matches/0x00104920.cpp
// sym: ?FUN_00104920@fn_f58850d5@@YIEPAVX_104920@1@@Z
unsigned char __fastcall FUN_00104920(X_104920* self) {
    return self->value;
}

} // namespace fn_f58850d5

// 0x00104930 CPathGraphAgent::vfunc_3 (62 B): equivalent/0x00104930.cpp
// sym: ?vfunc_3@CPathGraphAgent@@UAEMHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6)
// CPathGraphAgent::vfunc_3 @ 0x00104930
hulk_freg CPathGraphAgent::vfunc_3(hulk_intptr , int ) {
    PathState *s = (*(PathState * *)&this->f_58);
    if (!s->active && !(s->value < (*(float*)&DAT_003f5d00)) && !s->blocked)
        return (*(float*)&DAT_0040d510);
    (*(unsigned char *)&this->f_5d) = 0;
    (*(unsigned char *)&this->f_5c) = 0;
    return (*(float*)&DAT_003f32e0);
}

namespace fn_f58850d5 {

// 0x00104970 FUN_00104970 (34 B): matches/0x00104970.cpp
// sym: ?Set@Thing_104970@fn_f58850d5@@QAEXH@Z
void Thing_104970::Set(int x) {
    if (value != x) {
        f9();
        value = x;
    }
}


// 0x001049a0 CPathGraphAgent::vfunc_9 (1 B): matches/0x001049a0.cpp
// sym: ?FUN_001049a0@fn_f58850d5@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_001049a0() {}


// 0x00104a70 FUN_00104a70 (25 B): matches/0x00104a70.cpp
// sym: ?FUN_00104a70@fn_f58850d5@@YIXPAUObj_104a70@1@@Z
void __fastcall FUN_00104a70(Obj_104a70* self) {
    thunk_FUN_00267090(self->a);
    thunk_FUN_00267090(self->b);
}


// 0x00104b20 FUN_00104b20 (46 B): matches/0x00104b20.cpp
// sym: ?func@Obj_104b20@fn_f58850d5@@QAEPAXE@Z
void* Obj_104b20::func(unsigned char b) {
    thunk_FUN_00267090(field0);
    thunk_FUN_00267090(fieldC);
    if (b & 1) {
        operator delete(this);
    }
    return this;
}

} // namespace fn_f58850d5

// 0x00104b50 CPathAgent::vfunc_9 (258 B): equivalent/0x00104b50.cpp [wrapped: conflict: CPathAgent]
// sym: ?vfunc_9@CPathAgent@fn_00104b50@@UAEXXZ
namespace fn_00104b50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// CPathAgent::vfunc_9 @ 0x00104b50
struct Vec3_104b50 { float x,y,z; };
struct Location { void FUN_00059a50(Vec3_104b50*); };
struct Result_104b50 { char pad[16]; Location* location; };
struct Provider_104b50 { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual Result_104b50* slot6(); };
struct Allocation_104b50 { void* first; char pad[8]; void* second; };
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
struct CPathAgent {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
 char pad04[4]; int state; char pad0c[76]; Provider_104b50* provider; int f5c; int f60; Allocation_104b50* allocation; int f68; int f6c; int f70; int f74; int f78; char pad7c[12]; unsigned char f88,f89; char pad8a[2]; float f8c; unsigned char f90; char pad91[3]; float f94,f98; int f9c; Vec3_104b50 position; float fac; int fb0,fb4,fb8; char padbc[28]; int fd8,fdc,fe0,fe4,fe8,fec,ff0,ff4; float ff8;
};
void CPathAgent::vfunc_9() {
 Allocation_104b50* old=allocation;
 state=0; f5c=0; f6c=0;
 if(old) { FUN_0008d340(old->first); FUN_0008d340(old->second); FUN_0008d330(old); allocation=0; }
 f68=0; f70=0; f74=0; f78=0;
 f88=0; f89=1; f8c=1.0f; f90=0; f94=1.0f; f98=1.0f; f9c=0;
 fb8=0; fb4=0; fb0=0; fac=2.5f;
 Result_104b50* result=0;
 if(provider) result=provider->slot6();
 if(result) result->location->FUN_00059a50(&position);
 else { position.x=-1.0f; position.y=-1.0f; position.z=-1.0f; }
 fe0=0; fdc=0; fd8=0; fe4=0; ff0=0; fec=0; fe8=0; ff4=0; ff8=999.0f;
}
} // namespace fn_00104b50

namespace fn_f58850d5 {

// 0x00104c60 FUN_00104c60 (136 B): equivalent/0x00104c60.cpp
// sym: ?Reset@CPathAgent_104c60@fn_f58850d5@@QAEHHHPBUVec_104c60@2@HDHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 19903 inputs, branch coverage 0/0)
// FUN_00104c60 @ 0x00104c60
int CPathAgent_104c60::Reset(int, int, const Vec_104c60* pos, int c, char d, int e, int) {
 v6c = 0;
 sub->v75 = 0;
 v68 = 0;
 p70.x = pos->x; p70.y = pos->y; p70.z = pos->z;
 p7c.x = pos->x; p7c.y = pos->y; p7c.z = pos->z;
 v8c = c;
 v90 = d;
 v89 = 0;
 v88 = 1;
 v94 = e;
 v98 = e;
 ve0 = 0; vdc = 0; vd8 = 0; ve4 = 0;
    return e;
}

} // namespace fn_f58850d5

// 0x00104cf0 CPathAgent::vfunc_7 (3 B): matches/0x00104cf0.cpp
// sym: ?vfunc_7@CPathAgent@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CPathAgent::vfunc_7(int a) {
    (void)a;
}


// 0x00104d00 CPathGraphAgent::vfunc_4 (665 B): equivalent/0x00104d00.cpp
// sym: ?vfunc_4@CPathGraphAgent@@UAEXHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 21/22, incomplete)
// CPathGraphAgent::vfunc_4 @ 0x00104d00
void CPathGraphAgent::vfunc_4(int a, int b, int c) {
    V3_104d00 u;
    V3_104d00 d;
    V3_104d00 w;
    float k;

    if (!(*(Owner58 * *)&this->f_58))
        return;
    Agent_104d00 *ag = (*(Owner58 * *)&this->f_58)->vfunc_6();
    if (!ag)
        return;
    if (ag->mode->vfunc_9() == 4)
        return;

    k = 0.0f;
    u.x = 0.0f;
    u.y = 0.0f;
    u.z = 0.0f;
    d.x = 0.0f;
    d.y = 0.0f;
    d.z = 0.0f;
    ag->FUN_00035550(&u);
    V3_104d00 v1 = u;
    V3_104d00 v2 = u;
    (*(V3_104d00 *)&this->f_60) = ag->pos;

    Sub58_104d00 *s = &(*(Owner58 * *)&this->f_58)->sub58;
    if (s) {
        Target_104d00 *t = s->tgt;
        if (t) {
            if (t->kind == 1)
                (*(V3_104d00 *)&this->f_6c) = t->agent->pos;
            else
                (*(V3_104d00 *)&this->f_6c) = t->pos40;

            d.x = (*(V3_104d00 *)&this->f_6c).x - (*(V3_104d00 *)&this->f_60).x;
            d.y = (*(V3_104d00 *)&this->f_6c).y;
            d.z = (*(V3_104d00 *)&this->f_6c).z;
            float dy = d.y - (*(V3_104d00 *)&this->f_60).y;
            d.z = d.z - (*(V3_104d00 *)&this->f_60).z;
            float ady = dy;
            {
                union {
                    float f;
                    unsigned int u;
                } b;
                b.f = dy;
                b.u &= 0x7fffffff;
                ady = b.f;
            }
            if (ady > (*(float*)&DAT_0040d4d8)) {
                this->f_5c = 0;
            } else {
                d.y = 0.0f;
                float len = d.FUN_0022d110();
                this->f_5c = 1;
                if (this->f_5d && this->f_b4 != 2) {
                    w.x = (*(V3_104d00 *)&this->f_a4).x;
                    w.y = (*(V3_104d00 *)&this->f_a4).y;
                    w.z = (*(V3_104d00 *)&this->f_a4).z;
                    w.x = w.x - (*(V3_104d00 *)&this->f_60).x;
                    w.y = 0.0f;
                    w.z = w.z - (*(V3_104d00 *)&this->f_60).z;
                    float wl = w.FUN_0022d110();
                    if (!FUN_00018960(wl, 0.0f, 0.00001f) && len > DAT_004a1c68) {
                        v2 = w;
                        k = 1.0f;
                        v1 = w;
                    } else {
                        v2 = d;
                        k = 0.0f;
                        v1 = d;
                    }
                }
            }
        }
    }

    ag->outK = k;
    ag->out2 = v2;
    ag->out1 = v1;
}


// 0x00105060 FUN_00105060 (99 B): matches/0x00105060.cpp [wrapped: conflict: CPathAgent]
// sym: ??1CPathAgent@fn_00105060@@QAE@XZ
namespace fn_00105060 {
class Obj_105060 {
  public:
    virtual void A();
    virtual void B();
};
extern void thunk_0008d340(unsigned int);
extern void thunk2_0008d330(void*);
extern void* hulk_at_0040d4e0;
class CCharacterAgent_105060 {
  public:
    void* vptr;
    ~CCharacterAgent_105060() throw();
};
class CPathAgent : public CCharacterAgent_105060 {
  public:
    char pad[0x5c];
    Obj_105060* m60;
    Obj_105060* m64;
    char pad2[0x60];
    Obj_105060* mc8;
    ~CPathAgent() throw();
};
CPathAgent::~CPathAgent() throw() {
    *(void* volatile*)&vptr = &hulk_at_0040d4e0;
    Obj_105060* q = *(Obj_105060* volatile*)&m60;
    if (q) {
        q->B();
        m60 = 0;
    }
    mc8->B();
    Obj_105060* p = m64;
    mc8 = 0;
    if (p) {
        thunk_0008d340(*(unsigned int*)p);
        thunk_0008d340(*(unsigned int*)((char*)p + 0xc));
        thunk2_0008d330(p);
        m64 = 0;
    }
}
} // namespace fn_00105060


// 0x001050d0 CPathAgent::vfunc_4 (3405 B): equivalent/0x001050d0.cpp [wrapped: conflict: CPathAgent]
// sym: ?vfunc_4@CPathAgent@fn_001050d0@@UAEDPAUCtx_1050d0@2@MH@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001050d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 130/132, incomplete)
// CPathAgent::vfunc_4 @ 0x001050d0
// equiv-map: ?Del340@@YAXPAX@Z = 0x0008d340
// equiv-map: ?Del330@@YAXPAX@Z = 0x0008d330
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif

void __cdecl Del340(void *p);
void __cdecl Del330(void *p);

struct V3_1050d0 {
    float x, y, z;
    float FUN_0022d110();
    float FUN_00018990();
    char FUN_0022d2b0(V3_1050d0 *other, float eps);
    void FUN_00011250(V3_1050d0 *out, V3_1050d0 *other);
};

struct Locator {
    void FUN_00059a50(V3_1050d0 *out);
};

struct Body_1050d0 {
    char pad0[0x10];
    Locator *locator;
    char pad14[0x1a64 - 0x14];
    float f1a64;
    char pad1a68[0x1d0c - 0x1a68];
    float f1d0c;
    float f1d10;
    char pad1d14[0x2074 - 0x1d14];
    V3_1050d0 v2074;
    char FUN_000372f0();
};

struct PNode {
    V3_1050d0 pos;
    int link;
};
struct PList {
    char pad0[0x14];
    int count;
    PNode *FUN_00106160(int idx);
};

struct Part2_1050d0 {
    char pad0[0x60];
    PList *f60;
    char pad64[0xb8 - 0x64];
    int fb8;
};

struct Mgr20 {
    void FUN_00024300(Body_1050d0 *b);
    void FUN_00025260(int a, int b, int c);
};
struct Ctx_1050d0 {
    char pad0[0x20];
    Mgr20 *f20;
};
struct Sink0c {
    void FUN_001dcf60(int a);
};
struct World {
    char pad0[0xc];
    Sink0c *f0c;
};

class Part_1050d0 {
public:
    virtual void p0(); virtual void p1(); virtual void p2(); virtual void p3(); virtual void p4();
    virtual void p5();
    virtual Body_1050d0 *vfunc_6();
    virtual void p7(); virtual void p8();
    virtual int vfunc_9();
    char pad04[0xe8 - 4];
    char flagE8;
    char pad_e9[0x129 - 0xe9];
    char b129;
    Part2_1050d0 *FUN_000fdc40();
};

struct VList {
    V3_1050d0 *nodes;
    int f04;
    int count;
    void *f0c;
};

class AgentSub_1050d0 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void vfunc_4(Ctx_1050d0 *c, float dt, int a3);
    char pad04[0x76 - 4];
    char b76;
    char pad77[0x89 - 0x77];
    char b89;
    void FUN_00102b90(V3_1050d0 *p, float a, int b);
};

struct Dir_1050d0 {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual bool vfunc_4(V3_1050d0 *target, V3_1050d0 *pos, Body_1050d0 *b, Ctx_1050d0 *a1, float dt, V3_1050d0 *fbc, V3_1050d0 *w);
};

float __cdecl FUN_00018710(float *a, float *b);
float __cdecl FUN_000186f0(float *a, float *b);
V3_1050d0 *__cdecl FUN_00083e00(V3_1050d0 *out, V3_1050d0 *in, float s);
float __cdecl FUN_0010b1c0(Ctx_1050d0 *a1, Body_1050d0 *b, float thr, V3_1050d0 *out);
char __cdecl FUN_00036b10(Ctx_1050d0 *w, V3_1050d0 *a, V3_1050d0 *b, V3_1050d0 *c, V3_1050d0 *d, char *e, char *f);


struct Frame_1050d0 {
    float L;                          // path-length / scratch (reused for t and k later)
    union {
        float gy;
        unsigned char b;              // bool stored as a byte then pushed as a dword
        unsigned int w;
    } g;
    char pad08;
    char fl19;
    char flag1a;
    char fl1b;
    V3_1050d0 qv;
    V3_1050d0 dv;
    V3_1050d0 pos;
    V3_1050d0 pp;
    V3_1050d0 o1;
    V3_1050d0 v3;
    float two;
    Body_1050d0 *bsave;
    V3_1050d0 h;
    V3_1050d0 out1;
    V3_1050d0 out2;
};

class CPathAgent {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual char vfunc_4(Ctx_1050d0 *a1, float a2, int a3);
    char pad04[0x58 - 4];
    Part_1050d0 *part;
    char pad5c[4];
    AgentSub_1050d0 *sub;
    VList *list;
    int idx;
    float f6c;
    V3_1050d0 p70;
    V3_1050d0 p7c;
    char b88;
    char b89;
    char pad8a[2];
    float f8c;
    unsigned char b90;
    unsigned char b91;
    char pad92[2];
    float f94;
    float f98;
    char pad9c[4];
    V3_1050d0 pa0;
    float fac;
    V3_1050d0 pb0;
    V3_1050d0 pbc;
    Dir_1050d0 *fc8;
    char padcc[0xe4 - 0xcc];
    float fe4;
    V3_1050d0 pe8;
    float ff4;
    float ff8;

    void FUN_000fc550(Ctx_1050d0 *a1, float a2, int a3);
    void FUN_00104c60(Ctx_1050d0 *a1, V3_1050d0 *pos, V3_1050d0 *p7c, float f8c, int b90, float f94, int z);
};


char CPathAgent::vfunc_4(Ctx_1050d0 *a1, float a2, int a3)
{
    Frame_1050d0 f;
    FUN_000fc550(a1, a2, a3);
    if (!b88)
        return b88;                 // (0: the flag the original tested is what it leaves in al)
    if (part) {
        int state = part->vfunc_9();
        if (state == 4)
            return (char)state;     // (the original returns with vfunc_9's 4 still in eax)
    }
    {
        Body_1050d0 *b = part->vfunc_6();
        f.bsave = b;
        b->locator->FUN_00059a50(&f.pos);
        f.dv.x = p70.x - f.pos.x;
        f.dv.y = p70.y - f.pos.y;
        f.dv.z = p70.z - f.pos.z;
        if ((char)a3) {
            pb0.x = b->v2074.x;
            pb0.y = b->v2074.y;
            pb0.z = b->v2074.z;
            pe8.z = 0.0f;
            pe8.y = 0.0f;
            pe8.x = 0.0f;
            ff4 = 0.0f;
            ff8 = 999.0f;
            f6c = 0.0f;
        }
        a1->f20->FUN_00024300(b);
        fac = fac - a2;
        f.flag1a = 0;
        f.L = (float)sqrt(f.dv.z * f.dv.z + f.dv.y * f.dv.y + f.dv.x * f.dv.x);
        b->f1d10 = f.L;
        if (f98 <= 1.0f)
            f98 = 10.0f;
        if (!b->FUN_000372f0()) {
            if (f6c == 0.0f || f.L < f6c) {
                f6c = f.L;
                b->f1d0c = f.L;
            }
            if (f.L - 0.2f > f6c) {
                Part2_1050d0 *p = part->FUN_000fdc40();
                if (p && p->f60) {
                    PNode *n1 = p->f60->FUN_00106160(p->fb8);
                    if (n1) {
                        int k = n1->link;
                        if (k >= 0 && k < p->f60->count) {
                            PNode *n2 = p->f60->FUN_00106160(k);
                            if (n2) {
                                f.pp = f.pos;
                                f.g.gy = b->f1a64 + 0.25f;
                                f.qv = n2->pos;
                                f.pos.y = FUN_00018710(&f.pos.y, &f.g.gy);
                                f.qv.y = FUN_00018710(&f.qv.y, &f.g.gy);
                                a1->f20->FUN_00025260(0, 0, 0);
                                DAT_004dd700->f0c->FUN_001dcf60(0);
                                if (FUN_00036b10(a1, &f.pp, &f.qv, &f.o1, &f.dv, &f.fl19, &f.fl1b))
                                    f.flag1a = 1;
                                a1->f20->FUN_00025260(1, 0, 0);
                                DAT_004dd700->f0c->FUN_001dcf60(1);
                            }
                        }
                    }
                }
            }
        }

        // Decide between advancing to the next waypoint (1) and holding (0).
        int advance;
        bool lookahead = false;
        bool reachNear = (f.L < f98) || (!part->flagE8 && f.L < 3.0f);
        if (!reachNear) {
            advance = -1;                            // go straight to the stuck/blocked test
        } else if (list && idx < list->count - 1) {
            advance = f.L < f98 ? -2 : -1;           // -2: look ahead
        } else {
            advance = f.L < f98 ? 1 : -1;
        }
        (void)lookahead;
        if (advance == -2) {
            f.g.gy = b->f1a64 + 0.25f;
            f.dv = f.pos;
            f.o1 = list->nodes[idx + 1];
            f.pos.y = FUN_00018710(&f.pos.y, &f.g.gy);
            f.o1.y = FUN_00018710(&f.o1.y, &f.g.gy);
            f.qv.x = f.o1.x - f.dv.x;
            f.qv.y = f.o1.y - f.dv.y;
            f.qv.z = f.o1.z - f.dv.z;
            f.g.gy = f.qv.FUN_00018990();      // segment length; f.L (distance to the waypoint) stays live
            f.qv.FUN_0022d110();
            f.two = 2.0f;
            V3_1050d0 *step = FUN_00083e00(&f.pp, &f.qv, FUN_000186f0(&f.two, &f.g.gy));
            f.o1.x = f.dv.x + step->x;
            f.o1.y = f.dv.y + step->y;
            f.o1.z = f.dv.z + step->z;
            if (FUN_00036b10(a1, &f.dv, &f.o1, &f.out2, &f.out1, &f.fl1b, &f.fl19)) {
                advance = 1;
            } else {
                if (f98 > 0.5f) {
                    f.two = f98 * 0.5f;
                    f.g.gy = 0.5f;
                    f98 = FUN_00018710(&f.g.gy, &f.two);
                }
                advance = f.flag1a ? 1 : 0;
            }
        } else if (advance == -1) {
            advance = 0;
            if (f.flag1a) {
                advance = 1;
            } else if (list) {
                f.qv.x = -1.0f;
                f.qv.y = -1.0f;
                f.qv.z = -1.0f;
                if (!pa0.FUN_0022d2b0(&f.qv, 1e-005f) && idx < list->count - 1 && f.L < f98) {
                    p70.FUN_00011250(&f.qv, &pa0);
                    f.qv.y = 0.0f;
                    f.qv.FUN_0022d110();
                    f.pp.x = p70.x - f.pos.x;
                    f.pp.y = 0.0f;
                    f.pp.z = p70.z - f.pos.z;
                    f.pp.FUN_0022d110();
                    if (f.qv.z * f.pp.z + f.qv.y * f.pp.y + f.qv.x * f.pp.x < 0.25f) {
                        f.o1 = f.pos;
                        f.g.gy = b->f1a64 + 0.25f;
                        f.dv = p70;
                        f.pos.y = FUN_00018710(&f.pos.y, &f.g.gy);
                        f.dv.y = FUN_00018710(&f.dv.y, &f.g.gy);
                        f.flag1a = FUN_00036b10(a1, &f.o1, &f.dv, &f.out1, &f.out2, &f.fl1b, &f.fl19);
                        advance = f.flag1a ? 1 : 0;
                    }
                }
            }
        }

        if (advance == 1) {
            f6c = 0.0f;
            pe8.z = 0.0f;
            pe8.y = 0.0f;
            pe8.x = 0.0f;
            idx = idx + 1;
            ff4 = 0.0f;
            ff8 = 999.0f;
            f98 = f94;
            VList *done = list;     // the original keeps the list pointer in a register across the deletes
            if (done && idx >= done->count) {
                Del340(done->nodes);
                Del340(done->f0c);
                Del330(done);
                list = 0;
                idx = 0;
                b89 = 1;
                pa0.x = -1.0f;
                pa0.y = -1.0f;
                pa0.z = -1.0f;
            }
            if (list == 0) {
                b89 = 1;
            } else {
                pa0 = p70;
                p70 = list->nodes[idx];
                sub->FUN_00102b90(&p70, f8c, b91 ? 0 : (unsigned char)b90);
                sub->vfunc_4(a1, a2, a3);
            }
        } else {
            if (pe8.FUN_0022d2b0(&p70, 1e-005f)) {
                if (ff8 - f.L > 0.25f) {
                    ff8 = f.L;
                    ff4 = 0.0f;
                } else {
                    if (!sub->b76)
                        ff4 = a2 + ff4;
                }
            } else {
                ff4 = 0.0f;
                ff8 = 999.0f;
                pe8 = p70;
            }
            bool skip = false;
            if (!(fac < 0.0f) && !(ff4 > DAT_004a1c64))
                skip = true;
            if (!skip && !b91) {
                bool doMove = false;
                if (list == 0 || ff4 > DAT_004a1c64) {
                    doMove = true;
                } else if (idx < list->count) {
                    f.pp = f.pos;
                    f.g.gy = b->f1a64 + 0.25f;
                    f.qv = p70;
                    f.pp.y = FUN_00018710(&f.pp.y, &f.g.gy);
                    f.qv.y = FUN_00018710(&f.qv.y, &f.g.gy);
                    f.fl19 = FUN_00036b10(a1, &f.pp, &f.qv, &f.out1, &f.out2, &f.fl1b, &f.fl19) == 0;
                    if (f.fl19) {
                        doMove = true;
                    } else if (fac < 0.0f) {
                        fac = 2.5f;
                    }
                }
                if (doMove) {
                    f.two = f6c;
                    FUN_00104c60(a1, &f.pos, &p7c, f8c, b90, f94, 0);
                    f6c = f.two;
                }
            }
            if (fe4 < 3.0f) {
                f.g.b = (b90 && !b91 && (list == 0 || idx < list->count - 1)) ? 1 : 0;
                sub->FUN_00102b90(&p70, f8c, f.g.w);
                sub->vfunc_4(a1, a2, a3);
            }
        }

        f.pp.x = 0.0f;
        f.pp.z = 0.0f;
        if (list && !b91) {
            f.dv = f.pos;
            f.L = 2.0f;
            int i = idx;
            if (i >= 0) {
                int off = i * 12;
                for (;;) {
                    f.qv = list->nodes[i];
                    f.o1.x = f.qv.x - f.dv.x;
                    f.o1.y = 0.0f;
                    f.o1.z = f.qv.z - f.dv.z;
                    f.o1.FUN_0022d110();
                    float ln = (float)sqrt(f.o1.z * f.o1.z + f.o1.x * f.o1.x + f.o1.y * f.o1.y);
                    if (ln > f.L || i >= list->count - 1) {
                        float tz = f.o1.z * f.L;
                        f.pp.x = f.o1.x * f.L + f.dv.x;
                        f.pp.z = tz + f.dv.z;
                        break;
                    }
                    f.L = f.L - ln;
                    i++;
                    off += 12;
                    f.dv.x = f.qv.x;
                    f.dv.z = f.qv.z;
                    if (off < 0)
                        break;
                }
            }
        } else {
            f.qv.z = pb0.z + pb0.z;
            f.pp.x = (pb0.x + pb0.x) + f.pos.x;
            f.pp.z = f.qv.z + f.pos.z;
        }
        Body_1050d0 *tb = f.bsave;
        f.h.x = f.pp.x - f.pos.x;
        f.h.y = 0.0f;
        f.h.z = f.pp.z - f.pos.z;
        f.h.FUN_0022d110();
        f.L = a2 * 30.0003f * DAT_004a1c7c;
        float kc;
        if (1.0f < f.L)
            kc = 1.0f;
        else if (0.0f < f.L)
            kc = f.L;
        else
            kc = 0.0f;
        f.qv.x = f.h.x * kc;
        f.qv.y = f.h.y * kc;
        f.qv.z = f.h.z * kc;
        hulk_freg om = 1.0f - kc;
        V3_1050d0 *pb = &pb0;
        f.pp.x = om * pb->x;
        f.pp.y = om * pb->y;
        V3_1050d0 t;
        t.x = f.pp.x + f.qv.x;
        t.y = f.pp.y + f.qv.y;
        t.z = om * pb->z + f.qv.z;
        *pb = t;
        pb0.FUN_0022d110();
        tb->v2074.x = pb0.x;
        tb->v2074.y = pb0.y;
        tb->v2074.z = pb0.z;

        f.v3.x = 0.0f;
        f.v3.y = 0.0f;
        f.v3.z = 0.0f;
        f.L = part->b129 ? 1.5f : 0.75f;
        float r = FUN_0010b1c0(a1, tb, f.L, &f.v3);
        f.g.gy = r;
        if (!(r < 0.0f) && !(r > f.L)) {
            part->b129 = 1;
            f.v3.FUN_0022d110();
            hulk_freg m = (f.L - f.g.gy) / f.L;
            if (1.0f < m)
                m = 1.0f;
            f.v3.x = f.v3.x * m;
            f.v3.y = f.v3.y * m;
            f.v3.z = f.v3.z * m;
        } else {
            part->b129 = 0;
            f.v3.z = 0.0f;
            f.v3.y = 0.0f;
            f.v3.x = 0.0f;
        }
        return fc8->vfunc_4(&p70, &f.pos, tb, a1, a2, &pbc, &f.v3);
    }
}
} // namespace fn_001050d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f58850d5 {

// 0x00105ef0 FUN_00105ef0 (85 B): matches/0x00105ef0.cpp
// sym: ?FUN@fn_f58850d5@@YIXPAVCPathGraphAgent_105ef0@1@@Z
void __fastcall FUN(CPathGraphAgent_105ef0* self) {
    self->vptr = (void*)((hulk_intptr)DAT_0040d518);
    ((owners::Ring_1ae150 *)(((Sub_105ef0*)hulk_at_004dd700->sub)))->FUN_001ae150((hulk_intptr)((char*)self + 0x5c));
    self->mAcopy = self->mA;
    if (self->mA)
        Ref_0008d340(self->mA);
    self->mBcopy = self->mB;
    if (self->mB)
        Ref_0008d340(self->mB);
    Finish_000fc630(self);
}

} // namespace fn_f58850d5

// 0x00105f50 FUN_00105f50 (354 B): equivalent/0x00105f50.cpp [wrapped: conflict: CCharacterAgent; CPathGraphAgent; World]
// sym: ??0CPathGraphAgent@fn_00105f50@@QAE@PAVOwner_105f50@1@@Z
namespace fn_00105f50 {
// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 14/14)
// FUN_00105f50 @ 0x00105f50
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


struct Stats_105f50 {
    char pad0[0x380];
    int value;
    __int64 FUN_000443c0();
};

struct Body_105f50 {
    char pad0[0x11c];
    Stats_105f50 *stats;
};

class Owner_105f50 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Body_105f50 *v6();
};

struct Ring_105f50 {
    void **head;
    void **cur;
    void **base;
    void **end;
};

struct Registry_105f50 {
    char pad0[0x18];
    Ring_105f50 ring;
};

struct World {
    char pad0[0x1c];
    Registry_105f50 *registry;
};


class __declspec(novtable) CCharacterAgent {
public:
    virtual void v0();
    char pad04[0x58 - 4];
    Owner_105f50 *owner;
    void FUN_000fc760(Owner_105f50 *o);
    CCharacterAgent(Owner_105f50 *o) { FUN_000fc760(o); }
};

class CPathGraphAgent : public CCharacterAgent {
public:
    CPathGraphAgent(Owner_105f50 *o);
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

    char flag5c;
    char pad5d[3];
    int f60, f64, f68, f6c, f70, f74;
    float f78, f7c, f80, f84;
    int f88;
    char pad8c[4];
    int f90, f94, f98;
    char pad9c[4];
    int fa0, fa4, fa8, fac, fb0;
    char padb4[4];
    int fb8, fbc;
    char padc0[4];
    int fc4, fc8, fcc;
    char padd0[4];
    int fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0;
};

CPathGraphAgent::CPathGraphAgent(Owner_105f50 *o) : CCharacterAgent(o)
{
    f90 = 0;
    f94 = 0;
    f98 = 0;
    fa0 = 0;
    fc4 = 0;
    fc8 = 0;
    fcc = 0;
    fd4 = 0;
    fbc = 0;
    fdc = 0;
    fe0 = 0;
    fe4 = 0;
    fe8 = 0;
    fec = 0;
    ff0 = 0;
    fd8 = 0;
    flag5c = 0;
    f60 = 0;
    f64 = 0;
    f68 = 0;
    f6c = 0;
    f70 = 0;
    f74 = 0;

    Body_105f50 *body = o->v6();
    if (body->stats)
        fb8 = body->stats->value;
    __int64 id = body->stats->FUN_000443c0();
    float scale;
    if (id == (*(__int64*)&DAT_004dc0c0))
        scale = (*(float*)&DAT_004a1c80);
    else
        scale = 1.0f;
    f78 = scale;
    f7c = 0.2f;
    f80 = scale;
    f84 = 0.3f;
    f88 = 0;
    fa4 = 0;
    fa8 = 0;
    fac = 0;
    fb0 = 0;

    Ring_105f50 *r = &DAT_004dd700->registry->ring;
    if (r->cur < r->end) {
        if (r->cur)
            *r->cur = &flag5c;
        void **next = r->cur + 1;
        r->cur = next;
        if (next == r->end)
            r->cur = r->base;
        if (r->head == r->cur)
            r->cur = r->cur + (r->end - r->base);
    }
}
} // namespace fn_00105f50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001060c0 CPathGraphAgent::vfunc_2 (30 B): matches/0x001060c0.cpp
// sym: ??_GCPathGraphAgent@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CPathGraphAgent::~CPathGraphAgent() {}


// 0x00106130 FUN_00106130 (36 B): matches/0x00106130.cpp [wrapped: conflict: CPatrolPath]
// sym: ?target@CPatrolPath@fn_00106130@@QAEXXZ
namespace fn_00106130 {
extern "C" char DAT_0040d564[];
typedef unsigned int u32_106130;
void __cdecl thunk_FUN_00267090(u32_106130);
struct CPatrolPath {
    void* vptr;
    char pad[0x0c];
    u32_106130 m10;
    u32_106130 m14;
    void finish_0027afd0();
    void target();
};
void CPatrolPath::target() {
    vptr = (void*)((hulk_intptr)DAT_0040d564);
    u32_106130 x = m10;
    thunk_FUN_00267090(x);
    m14 = 0;
    finish_0027afd0();
}
} // namespace fn_00106130


// 0x00106160 FUN_00106160 (16 B): matches/0x00106160.cpp
// sym: ?FUN_00106160@Target_106160@owners@@QAEHH@Z
hulk_intptr owners::Target_106160::FUN_00106160(int index) {
    return value + index * 0x24;
}

