// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000964d0..0x00096b00 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_ff9d56b0 {
#define TREE_TU_END }
namespace fn_ff9d56b0 {} using namespace fn_ff9d56b0;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_ff9d56b0 {
struct RandomState { uint first; uint second; };
extern "C" float angle(float, float);
int __cdecl FUN_00345b90(int c);
extern "C" hulk_intptr Alloc(hulk_intptr);
class Inner_966f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void Send(int, int);
};
struct Shader_nv_966f0 {
    pure3d::Shader* Init();
};
typedef unsigned int U_96740;
struct Pos_96740 { U_96740 x,y,z; };
struct Batch_96740 { char pad[8]; Pos_96740* volatile position; U_96740 unused; U_96740* volatile color; void FUN_0008ef00(); };
struct Resource_96740 { char pad[16]; U_96740 handle; };
} // namespace fn_ff9d56b0
struct Gfx {
virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void setMode(U_96740); virtual U_96740 getMode(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual Batch_96740* begin(U_96740,U_96740,U_96740,U_96740,U_96740); virtual void end(Batch_96740*); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void setA(U_96740); virtual U_96740 getA(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void setB(U_96740); virtual U_96740 getB();
};
namespace fn_ff9d56b0 {
struct Context { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void finish(U_96740); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void start(U_96740); };
extern "C" void FUN_000966f0();
U_96740 FUN_00267f00();
struct Q_969d0 {
    float Get();
};
struct C_969d0 {
    char pad[0x12c];
    hulk_intptr v;
};
struct B_969d0 {
    char pad[0xc];
    int kind;
};
struct I_969d0 {
    char pad[0xec];
    Q_969d0* q;
    char pad2[0x110 - 0xf0];
    char flag;
    char pad3[3];
    B_969d0* b;
    char pad4[0x148 - 0x118];
    C_969d0* c;
};
struct N_969d0 {
    char pad[8];
    I_969d0* i;
    int kind;
};
struct Sub_96a40 {
    void f(void*);
    void g(void*);
};
struct Obj_96a40 {
    char pad[8];
    Sub_96a40* sub;
    int kind;
    char q[0x30];
    unsigned a, b, c;
};
class Sub_96a90 {
  public:
    void F(void*);
    char G(void*);
};
class Obj_96a90 {
  public:
    char pad0[8];
    Sub_96a90* mSub;
    int mType;
    char pad10[0x30];
    int mA;
    int mB;
    int mC;
};


// 0x000964d0 FUN_000964d0 (6 B): matches/0x000964d0.cpp
// sym: _FUN_000964d0
// Same code shape as 0x00085cd0 (propagated; names are from that function)
// Returns the gameplay RNG's pointer (DAT_004e5acc): a pointer, so it stays whole on 64-bit
extern "C" void* FUN_000964d0(void) {
    return (*(void**)&DAT_004e5acc);
}


// 0x000964e0 FUN_000964e0 (96 B): equivalent/0x000964e0.cpp
// sym: ?FUN_000964e0@fn_ff9d56b0@@YAMXZ @ef427a018a9a @web4ed377eaf3
// STATUS: equivalent (tools/equiv.py level 3: 19809 inputs, branch coverage 0/0)
// FUN_000964e0 @ 0x000964e0
hulk_freg FUN_000964e0()
{
    RandomState *state = (*(RandomState**)&DAT_004e5acc);
    uint first = state->first;
    state->first = (first & 0xffff) * 0x9069 + (first >> 16);
    uint second = state->second;
    state->second = (second & 0xffff) * 0x4650 + (second >> 16);
    uint bits = ((state->second & 0xffff) + (state->first << 16)) & 0x7fffff;
    bits |= 0x3f800000;
    return *(float *)&bits - (*(float*)&DAT_003f32dc);
}


// 0x00096540 FUN_00096540 (25 B): matches/0x00096540.cpp
// sym: ?FUN_00096540@fn_ff9d56b0@@YAMMM@Z
// data: radToDeg = DAT_003f3ef4
hulk_freg FUN_00096540(float a, float b) {
    return angle(a, b) * DAT_003f3ef4;
}


// 0x00096600 FUN_00096600 (112 B): equivalent/0x00096600.cpp
// sym: _FUN_00096600 @8944b7581ddb @w92c09faa9dda
// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 15/18, incomplete)
// FUN_00096600 @ 0x00096600
// Case-insensitive strcmp
extern "C" int FUN_00096600(const char* s1, const char* s2)
{
    while (*s1 != 0 && *s2 != 0) {
        char a = (char)FUN_00345b90(*s1);
        char b = (char)FUN_00345b90(*s2);
        if (a > b)
            return 1;
        if (a < b)
            return -1;
        s1++;
        s2++;
    }
    if (*s2 != 0)
        return -1;
    if (*s1 != 0)
        return 1;
    return 0;
}


// 0x00096670 FUN_00096670 (104 B): equivalent/0x00096670.cpp
// sym: _FUN_00096670 @3525692d3019 @w047b49ab3d69
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_00096670 @ 0x00096670
extern "C" int __cdecl FUN_00096670(const char* s1, const char* s2, unsigned int n) {
    if (*s1 != 0 && *s2 != 0) {
        for (;;) {
            if (n == 0)
                return 0;
            char a = (char)FUN_00345b90(*s1);
            char b = (char)FUN_00345b90(*s2);
            if (a > b)
                return 1;
            if (a < b)
                return -1;
            char next = s1[1];
            s1++;
            s2++;
            n--;
            if (next == 0)
                break;
            if (*s2 == 0)
                break;
        }
    }
    if (n == 0)
        return 0;
    if (*s1 != *s2)
        return 1;
    return 0;
}


// 0x000966f0 FUN_000966f0 (75 B): matches/0x000966f0.cpp
// sym: _FUN_000966f0
// data: gEnabled_966f0 = DAT_004dd8e4, gObject_966f0 = DAT_004dd930
extern "C" void FUN_000966f0() {
    if ((*(unsigned char*)&DAT_004dd8e4) && (*(pure3d::Shader**)&DAT_004dd930) == 0) {
        pure3d::Shader* p = (pure3d::Shader*)Alloc(0x20);
        if (p)
            p = ((Shader_nv_966f0*)(p))->Init();
        else
            p = 0;
        (*(pure3d::Shader**)&DAT_004dd930) = p;
        (*(pure3d::Shader**)&DAT_004dd930)->vfunc_0();
        (*(Inner_966f0 * *)&(*(pure3d::Shader**)&DAT_004dd930)->f_10)->Send(0x444d4c42, 1);
    }
}


// 0x00096740 FUN_00096740 (584 B): equivalent/0x00096740.cpp
// sym: _FUN_00096740 @ceb95f951c9e @wd61266b3fe19
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/8, incomplete)
// FUN_00096740 @ 0x00096740
extern "C" void FUN_00096740() {
 if (!(*(unsigned char*)&DAT_004dd8e4)) return;
 FUN_000966f0();
 U_96740 now=FUN_00267f00(); U_96740 delta=now-(*(U_96740*)&DAT_004dd944);
 double elapsed=(int)delta; if((int)delta<0) elapsed+=4294967296.0f;
 (*(U_96740*)&DAT_004dd944)=now; DAT_004dd910=(float)(elapsed*0.000001f);
 U_96740 a=DAT_0052c2a8->getA(); DAT_0052c2a8->setA(0);
 U_96740 b=DAT_0052c2a8->getB(); DAT_0052c2a8->setB(1);
 U_96740 m=DAT_0052c2a8->getMode(); DAT_0052c2a8->setMode(2);
 (*(*(Context***)&DAT_0052c2ac))->start(0);
 Batch_96740* batch=DAT_0052c2a8->begin((*(Resource_96740**)&DAT_004dd930)->handle,0,0x2020,6,0);
 U_96740 color;
 if (DAT_004dd910>=0.044f) color=0x80ff0000;
 else if (DAT_004dd910>0.038f) color=0x80ffff00;
 else color=0x8000ff00;
 for(int i=0;i<6;++i) {
 *batch->color=color;
 batch->position->x=(i==2 || i==4 || i==5)?0x42700000:0;
 batch->position->y=(i==0 || i==2 || i==4)?0x42700000:0;
 batch->position->z=0x3f800000;
 batch->FUN_0008ef00();
 }
 DAT_0052c2a8->end(batch);
 (*(*(Context***)&DAT_0052c2ac))->finish(0);
 DAT_0052c2a8->setA(a); DAT_0052c2a8->setB(b); DAT_0052c2a8->setMode(m);
}


// 0x000969c0 FUN_000969c0 (1 B): matches/0x000969c0.cpp
// sym: _FUN_000969c0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_000969c0() {}


// 0x000969d0 FUN_000969d0 (106 B): matches/0x000969d0.cpp
// sym: _FUN_000969d0
// data: gZero_969d0 = DAT_003f32e0
extern "C" N_969d0* __cdecl FUN_000969d0(N_969d0* n) {
    if (!n)
        return 0;
    if (n->kind == 5) {
        I_969d0* i = n->i;
        if (i) {
            if (i->c) {
                if (i->c->v)
                    return (N_969d0*)i->c->v;
            }
            B_969d0* b = i->b;
            if (b && b->kind == 1) {
                if (i->q->Get() > DAT_003f32e0) {
                    if (!i->flag)
                        return (N_969d0*)b;
                }
            }
        }
    }
    return n;
}


// 0x00096a40 FUN_00096a40 (67 B): matches/0x00096a40.cpp
// sym: _FUN_00096a40
extern "C" void __cdecl FUN_00096a40(Obj_96a40* p, unsigned* out) {
    if (p->kind == 5) {
        p->sub->f(out);
        return;
    }
    if (p->kind == 1) {
        p->sub->g(out);
        return;
    }
    out[0] = p->a;
    out[1] = p->b;
    out[2] = p->c;
}


// 0x00096a90 FUN_00096a90 (112 B): matches/0x00096a90.cpp
// sym: _FUN_00096a90
extern "C" void FUN_00096a90(Obj_96a90* p, int* out) {
    if (!p) {
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        return;
    }
    switch (p->mType) {
    case 1:
        if (!p->mSub->G(out)) {
            out[0] = p->mA;
            out[1] = p->mB;
            out[2] = p->mC;
        }
        return;
    case 5:
        p->mSub->F(out);
        return;
    default:
        out[0] = p->mA;
        out[1] = p->mB;
        out[2] = p->mC;
        return;
    }
}

} // namespace fn_ff9d56b0
