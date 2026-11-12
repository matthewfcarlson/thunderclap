// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000af110..0x000af380 (kind game, layer game, confidence medium), dominant class CGameController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb9e703c {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb9e703c {} using namespace fn_fb9e703c;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb9e703c {
extern void* hulk_at_00405e2c[];
} // namespace fn_fb9e703c
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif
namespace fn_fb9e703c {
class Arg_af110 {
  public:
    virtual void V0();
};
class CGameController_af110 {
  public:
    void* vptr;
    int m4;   // (x64t7) pure3d::NonCopyable's reference count (was a pointer)
    Arg_af110* m8;
    int arr[0x29];
    CGameController_af110* ctor(Arg_af110* a);
};
extern "C" char DAT_00405e2c[];
class NonCopyable {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class CGameController : public NonCopyable {
  public:
    int pad;
    void* member;
    virtual CGameController* vfunc_2(unsigned char flag);
};
void Destroy_0008d330(CGameController*);
struct Samples {
    float v[17];
};
class Source_af170 {
public:
    void FUN_000ada70(Samples *out);
};
struct Track {
    int state;
    float held;
    float value;
};
struct Stick_af170 {
    int state;
    float held;
    float x;
    float y;
};
class InputTracker {
public:
    char pad0[8];
    Source_af170 *source;
    Track tracks[11];
    Stick_af170 sticks[2];
    void FUN_000af170(float dt);
};
static __forceinline void advance(int &state, float &held, float dt, bool active)
{
    if (active) {
        switch (state) {
        case 0:
            state = 1;
            held += dt;
            break;
        case 1:
            state = 2;
            held = dt;
            break;
        case 2:
            held += dt;
            break;
        case 3:
            state = 1;
            held = dt;
            break;
        }
    } else {
        switch (state) {
        case 0:
            held += dt;
            break;
        case 1:
            state = 3;
            held = dt;
            break;
        case 2:
            state = 3;
            held += dt;
            break;
        case 3:
            state = 0;
            held = dt;
            break;
        }
    }
}
extern void* hulk_at_00405e3c[];
class Controller_af310 {
  public:
    virtual void Init();
};
class Arg_af310 {
  public:
};
} // namespace fn_fb9e703c
void* operator new(size_t);
namespace fn_fb9e703c {
struct CGameController_af310 {
    Controller_af310* Build_000af110(int);
};
class CGameControllerManager_af310 {
  public:
    void* vptr;
    Controller_af310* controller;
    unsigned char flag;
    CGameControllerManager_af310* ctor(Arg_af310* a);
};


// 0x000af110 FUN_000af110 (47 B): matches/0x000af110.cpp
// sym: ?ctor@CGameController_af110@fn_fb9e703c@@QAEPAV12@PAVArg_af110@2@@Z
CGameController_af110* CGameController_af110::ctor(Arg_af110* a) {
    m4 = 0;
    vptr = hulk_at_00405e2c;
    m8 = a;
    a->V0();
    memset(arr, 0, 0xa4);

    return this;
}


// 0x000af140 CGameController::vfunc_2 (45 B): matches/0x000af140.cpp
// sym: ?vfunc_2@CGameController@fn_fb9e703c@@UAEPAV12@E@Z
CGameController* CGameController::vfunc_2(unsigned char flag) {
    *(void**)this = (void*)((hulk_intptr)DAT_00405e2c);
    ((NonCopyable*)member)->vfunc_1();
    *(void**)this = (void*)((hulk_intptr)DAT_003f6098);
    if (flag & 1)
        Destroy_0008d330(this);
    return this;
}


// 0x000af170 FUN_000af170 (348 B): equivalent/0x000af170.cpp
// sym: ?FUN_000af170@InputTracker@fn_fb9e703c@@QAEXM@Z @ff51fcab7152 @w13700d501880
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 34/34)
// FUN_000af170 @ 0x000af170
void InputTracker::FUN_000af170(float dt)
{
    Samples in;
    source->FUN_000ada70(&in);
    for (int i = 0; i < 11; i++) {
        float v = in.v[i];
        advance(tracks[i].state, tracks[i].held, dt, v > 0.0f);
        tracks[i].value = v;
    }
    for (int i = 0; i < 2; i++) {
        float a = in.v[11 + i * 2];
        float b = in.v[12 + i * 2];
        union {
            float f;
            unsigned int u;
        } ta, tb;
        ta.f = a;
        ta.u &= 0x7fffffff;
        bool active = true;
        if (ta.f <= 1e-05f) {
            tb.f = b;
            tb.u &= 0x7fffffff;
            if (tb.f <= 1e-05f)
                active = false;
        }
        advance(sticks[i].state, sticks[i].held, dt, active);
        sticks[i].x = a;
        sticks[i].y = b;
    }
}


// 0x000af310 FUN_000af310 (82 B): matches/0x000af310.cpp
// sym: ?ctor@CGameControllerManager_af310@fn_fb9e703c@@QAEPAV12@PAVArg_af310@2@@Z
CGameControllerManager_af310* CGameControllerManager_af310::ctor(Arg_af310* a) {
    vptr = hulk_at_00405e3c;
    void* p = operator new(0xb0);
    Controller_af310* c;
    if (p) {
        c = ((CGameController_af310*)p)->Build_000af110(((int)((owners::C_ae640 *)a)->FUN_000ae640(0)));
    } else
        c = 0;
    controller = c;
    c->Init();
    return this;
}

} // namespace fn_fb9e703c
