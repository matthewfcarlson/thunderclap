// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b35d0..0x000b3d50 (kind game, layer game, confidence medium), dominant class CSimController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8cdf61b {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8cdf61b {} using namespace fn_f8cdf61b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f8cdf61b {
extern void* hulk_at_003f6098;
struct Obj_b35d0 {
    void** vf;
    char pad[4];
    struct Ref_b35d0* p;
};
struct Ref_b35d0 {
    virtual void a();
    virtual void b();
};
struct Entry3 {
    int a, b, c;
};
struct Entry14 {
    int w[14];
};
struct Table_b35f0 {
    Entry3 small[13];
    Entry14 big[2];
};
struct B_b3660 {
    unsigned int x[0x43];
};
class C_b3660 {
  public:
    char pad[0xc];
    B_b3660 b;
    void Copy(B_b3660* dst);
};
extern int hulk_at_004060c4;
extern int vtbl_refcount;
class Sub_b36a0 {
  public:
    virtual void a();
    virtual void b();
};
class CSimController {
  public:
    virtual void f0();
    virtual void f1();
    virtual CSimController* vfunc_2(int);
    char pad[4];
    Sub_b36a0* sub;
};
extern void thunk_0008d330(CSimController*);
float __cdecl FUN_00224ea0(float x, float y);
float __cdecl FUN_00224fc0(float a, float b);
union Bits_b36d0 {
    float f;
    unsigned int u;
};
struct Btn {
    int state;                  // 0x00
    float a;                    // 0x04
    float b;                    // 0x08
};
struct Stick_b36d0 {
    int state;                  // 0x00
    float a;                    // 0x04
    float x;                    // 0x08
    float y;                    // 0x0c
    float m;                    // 0x10
    float ang;                  // 0x14
    float f14;                  // 0x18
    float f18;                  // 0x1c
    float f1c;                  // 0x20
    float f20;                  // 0x24
    float f24;                  // 0x28
    int mode;                   // 0x2c
    float f2c;                  // 0x30
    float f30;                  // 0x34
};
struct Input_b36d0 {
    Btn btn[13];                // 0x00
    Stick_b36d0 stick[2];             // 0x9c
};
struct Buttons_b36d0 {
    float v[13];
};
struct Sticks_b36d0 {
    float xy[4];
};
struct Meter_b36d0 {
    float FUN_000ad3c0();
    float FUN_000ad2b0();
};
class Ctrl_b36d0 {
public:
    char pad00[8];
    Meter_b36d0 *meter;               // 0x08
    void FUN_000b36d0(Input_b36d0 *s, Buttons_b36d0 buttons, Sticks_b36d0 sticks, float dt);
};
struct Sample_b3bc0 { unsigned int words[17]; };
struct Vector3_b3bc0 { unsigned int x,y,z; };
struct Block_b3bc0 { Vector3_b3bc0 vectors[13]; char rest[112]; };
struct Source_b3bc0 {
 void FUN_000ada90(Sample_b3bc0*);
 void FUN_000adad0(Sample_b3bc0*);
};
struct Object {
 char pad[8];
 Source_b3bc0* source;
 Block_b3bc0 first;
 Block_b3bc0 second;
 void FUN_000b36d0(Block_b3bc0*, Sample_b3bc0, unsigned int);
 void FUN_000b3bc0(unsigned int arg);
};
struct Obj_b3c80 {
    char pad[8];
    unsigned char field;
};
struct Root_b3c80 {
    char pad[4];
    Obj_b3c80* ptr;
};
extern Root_b3c80* hulk_at_004dd700;
extern void* hulk_at_004060d8[];
class Controller_b3c90 {
  public:
    virtual void Init();
};
class Arg_b3c90 {
  public:
};
} // namespace fn_f8cdf61b
void* operator new(size_t);
namespace fn_f8cdf61b {
struct CSimController_b3c90 {
    Controller_b3c90* Build_000b3b80(int);
};
class CSimControllerManager_b3c90 {
  public:
    void* vptr;
    Controller_b3c90* controller;
    unsigned char flag;
    CSimControllerManager_b3c90* ctor(Arg_b3c90* a);
};


// 0x000b35d0 FUN_000b35d0 (25 B): matches/0x000b35d0.cpp
// sym: ?target@fn_f8cdf61b@@YIXPAUObj_b35d0@1@@Z
// Same code shape as 0x000af0d0 (propagated; names are from that function)
void __fastcall target(Obj_b35d0* self) {
    self->p;
    self->vf = (void**)&gameVtable;
    self->p->b();
    self->vf = (void**)&hulk_at_003f6098;
}


// 0x000b35f0 FUN_000b35f0 (104 B): equivalent/0x000b35f0.cpp
// sym: ?FUN_000b35f0@fn_f8cdf61b@@YGXPAUTable_b35f0@1@_N@Z @7247537bc07e @w76359ca057b3
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000b35f0 @ 0x000b35f0
void __stdcall FUN_000b35f0(Table_b35f0* t, bool clearBig) {
    for (int i = 0; i < 13; i++) {
        t->small[i].a = 0;
        t->small[i].b = 0;
        t->small[i].c = 0;
    }
    if (clearBig) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 14; j++)
                t->big[i].w[j] = 0;
    }
}


// 0x000b3660 FUN_000b3660 (21 B): matches/0x000b3660.cpp
// sym: ?Copy@C_b3660@fn_f8cdf61b@@QAEXPAUB_b3660@2@@Z
void C_b3660::Copy(B_b3660* dst) {
    *dst = b;
}


// 0x000b36a0 CSimController::vfunc_2 (45 B): matches/0x000b36a0.cpp
// sym: ?vfunc_2@CSimController@fn_f8cdf61b@@UAEPAV12@H@Z
CSimController* CSimController::vfunc_2(int flags) {
    CSimController* p = this;
    *((hulk_intptr*)p) = (hulk_intptr)&hulk_at_004060c4;
    sub->b();
    *((hulk_intptr*)p) = (hulk_intptr)&vtbl_refcount;
    if (flags & 1)
        thunk_0008d330(this);
    return this;
}


// 0x000b36d0 FUN_000b36d0 (1074 B): equivalent/0x000b36d0.cpp
// sym: ?FUN_000b36d0@Ctrl_b36d0@fn_f8cdf61b@@QAEXPAUInput_b36d0@2@UButtons_b36d0@2@USticks_b36d0@2@M@Z @690842ccaa0a @w4c6d99e77a61
// STATUS: equivalent (tools/equiv.py level 3: 3031 inputs, branch coverage 74/74)
// FUN_000b36d0 @ 0x000b36d0
void Ctrl_b36d0::FUN_000b36d0(Input_b36d0 *s, Buttons_b36d0 buttons, Sticks_b36d0 sticks, float dt)
{
    float *vals = buttons.v;
    float *xy = sticks.xy;

    for (int i = 0; i < 13; i++) {
        float v = vals[i];
        Btn *b = &s->btn[i];
        if (v > 0.0f) {
            switch (b->state) {
            case 0:
                b->state = 1;
                b->a = dt + b->a;
                break;
            case 1:
                b->state = 2;
                b->a = dt;
                break;
            case 2:
                b->a = dt + b->a;
                break;
            case 3:
                b->state = 1;
                b->a = dt;
                break;
            }
        } else {
            switch (b->state) {
            case 0:
                b->a = dt + b->a;
                break;
            case 1:
                b->state = 3;
                b->a = dt;
                break;
            case 2:
                b->state = 3;
                b->a = dt + b->a;
                break;
            case 3:
                b->state = 0;
                b->a = dt;
                break;
            }
        }
        b->b = v;
    }

    for (int k = 0; k < 2; k++) {
        Stick_b36d0 *st = &s->stick[k];
        Bits_b36d0 bx, by, ax, ay;
        bx.f = xy[2 * k];
        by.f = xy[2 * k + 1];
        ax.u = bx.u & 0x7fffffff;
        ay.u = by.u & 0x7fffffff;
        st->m = ax.f;
        if (ay.f > ax.f)
            st->m = ay.f;
        if (st->m > 0.0f) {
            float ang = FUN_00224ea0(bx.f, by.f);
            int state = st->state;
            bool reset = false;
            bool diff = false;
            if (state == 0) {
                st->a = dt + st->a;
                reset = true;
            } else if (state == 1) {
                st->state = 2;
                st->a = dt;
                diff = true;
            } else if (state == 2) {
                st->a = dt + st->a;
                st->state = 2;
                diff = true;
            } else if (state == 3) {
                st->a = dt;
                reset = true;
            }
            if (reset) {
                st->state = 1;
                st->f14 = 0.0f;
                st->f18 = 0.0f;
                st->f24 = 0.0f;
            }
            if (diff) {
                float d = FUN_00224fc0(st->ang, ang);
                Bits_b36d0 ad;
                ad.f = d;
                ad.u &= 0x7fffffff;
                bool acc = false;
                if (ad.f <= 0.00001f)
                    acc = true;
                else if (d < 0.0f && st->f14 < 0.0f)
                    acc = true;
                else if (d > 0.0f && st->f14 > 0.0f)
                    acc = true;
                if (acc) {
                    st->f14 = d + st->f14;
                    st->f18 = dt + st->f18;
                    st->f24 = dt + st->f24;
                } else {
                    st->f14 = d;
                    st->f18 = dt;
                    st->f20 = st->ang;
                    st->f24 = dt;
                }
            }

            float r = meter->FUN_000ad3c0();
            if (r <= st->m) {
                if (st->mode == 0) {
                    st->mode = 1;
                    st->f30 = dt + st->f30;
                } else if (st->mode == 1) {
                    st->mode = 2;
                    st->f2c = st->ang;
                    st->f30 = dt;
                } else if (st->mode == 2) {
                    st->mode = 2;
                    st->f30 = dt + st->f30;
                }
            } else {
                if (st->mode == 1) {
                    st->f2c = st->ang;
                    st->f30 = 0.0f;
                }
                float r2 = meter->FUN_000ad2b0();
                if (!(r2 >= st->m))
                    st->mode = 2;
                else
                    st->mode = 0;
                st->f30 = dt + st->f30;
            }
            st->ang = ang;
            if ((DAT_004ddbcc & 1) == 0) {
                DAT_004ddbcc |= 1;
                (*(float*)&DAT_004ddbc8) = 1.5707964f;
            }
            float d2 = FUN_00224fc0(ang, st->f20);
            if (d2 > (*(float*)&DAT_004ddbc8) || st->f24 > 0.3f) {
                float q = d2 / st->f24;
                st->f20 = st->ang;
                st->f24 = 0.0f;
                Bits_b36d0 aq;
                aq.f = q;
                aq.u &= 0x7fffffff;
                st->f1c = aq.f;
            }
        } else {
            switch (st->state) {
            case 0:
                st->a = dt + st->a;
                break;
            case 1:
                st->state = 3;
                st->a = dt;
                break;
            case 2:
                st->state = 3;
                st->a = dt + st->a;
                break;
            case 3:
                st->state = 0;
                st->a = dt;
                break;
            }
            if (st->mode == 1) {
                st->f2c = st->ang;
                st->f30 = 0.0f;
            }
            st->mode = 0;
            float nf = dt + st->f30;
            st->ang = 0.0f;
            st->f14 = 0.0f;
            st->f18 = 0.0f;
            st->f30 = nf;
            st->f1c = 0.0f;
            st->f20 = 0.0f;
            st->f24 = 0.0f;
        }
        st->x = bx.f;
        st->y = by.f;
    }
}

} // namespace fn_f8cdf61b

// 0x000b3b50 FUN_000b3b50 (38 B): matches/0x000b3b50.cpp
// sym: ?FUN_000b3b50@Obj_b3b50@owners@@QAEXI@Z
void owners::Obj_b3b50::FUN_000b3b50(unsigned int v) {
    Copy((char*)this + 0xC, v);
    Copy((char*)this + 0x118, v);
}


// 0x000b3b80 FUN_000b3b80 (62 B): matches/0x000b3b80.cpp [wrapped: conflict: CSimController]
// sym: ??0CSimController@fn_000b3b80@@QAE@PAVRef_b3b80@1@@Z
namespace fn_000b3b80 {
class Ref_b3b80 {
  public:
    virtual void F();
};
extern int vtable_b3b80;
class CSimController {
  public:
    hulk_intptr vt;
    int m;
    Ref_b3b80* p;
    char pad[0x10c];
    CSimController(Ref_b3b80*);
    void Init_000b35f0(void*, int);
};
CSimController::CSimController(Ref_b3b80* q) {
    m = 0;
    vt = (hulk_intptr)&vtable_b3b80;
    p = q;
    q->F();
    Init_000b35f0((char*)this + 0xc, 1);
    Init_000b35f0((char*)this + 0x118, 1);
}
} // namespace fn_000b3b80

namespace fn_f8cdf61b {

// 0x000b3bc0 FUN_000b3bc0 (186 B): equivalent/0x000b3bc0.cpp
// sym: ?FUN_000b3bc0@Object@fn_f8cdf61b@@QAEXI@Z @774d96273852 @weecb1cd0fc84
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 6/6)
// FUN_000b3bc0 @ 0x000b3bc0
void Object::FUN_000b3bc0(unsigned int arg) {
 Sample_b3bc0 sample;
 source->FUN_000ada90(&sample);
 FUN_000b36d0(&first,sample,arg);
 source->FUN_000adad0(&sample);
 FUN_000b36d0(&second,sample,arg);
 if ((*(unsigned char*)&DAT_004e222c)) {
  for (int i=0;i<13;++i) { first.vectors[i].x=0; first.vectors[i].y=0; first.vectors[i].z=0; }
  for (int j=0;j<13;++j) { second.vectors[j].x=0; second.vectors[j].y=0; second.vectors[j].z=0; }
 }
}


// 0x000b3c80 FUN_000b3c80 (16 B): matches/0x000b3c80.cpp
// sym: _FUN_000b3c80
extern "C" void __cdecl FUN_000b3c80(unsigned char x) {
    hulk_at_004dd700->ptr->field = x;
}


// 0x000b3c90 FUN_000b3c90 (86 B): matches/0x000b3c90.cpp
// sym: ?ctor@CSimControllerManager_b3c90@fn_f8cdf61b@@QAEPAV12@PAVArg_b3c90@2@@Z
CSimControllerManager_b3c90* CSimControllerManager_b3c90::ctor(Arg_b3c90* a) {
    vptr = hulk_at_004060d8;
    flag = 1;
    void* p = operator new(0x224);
    Controller_b3c90* c;
    if (p) {
        c = ((CSimController_b3c90*)p)->Build_000b3b80(((int)((owners::C_ae640 *)a)->FUN_000ae640(0)));
    } else
        c = 0;
    controller = c;
    c->Init();
    return this;
}


// 0x000b3d00 FUN_000b3d00 (1 B): matches/0x000b3d00.cpp
// sym: ?FUN_000b3d00@fn_f8cdf61b@@YAXPAX@Z
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000b3d00(void* /*this, unused: callers pass it (unb4)*/) {}

} // namespace fn_f8cdf61b

// 0x000b3d20 FUN_000b3d20 (25 B): matches/0x000b3d20.cpp
// sym: ?FUN_000b3d20@C_b3d20@owners@@QAEHH@Z
// Same code shape as 0x000ae640 (propagated; names are from that function)
hulk_intptr owners::C_b3d20::FUN_000b3d20(int i) {
    if (i >= 0 && i < 1)
        return *(&a + i);
    return 0;
}

