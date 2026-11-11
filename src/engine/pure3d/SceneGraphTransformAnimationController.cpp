// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a7730..0x002a7b90 (kind game, layer engine, confidence high), dominant class pure3d::SceneGraphTransformAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f22c50ed {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f22c50ed {} using namespace fn_f22c50ed;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f22c50ed {
struct SceneGraphTransformAnimationController_nv_2a7730 {
    void First_00285ac0();
    void Second_00284ad0(int);
};
extern void* hulk_at_0042db8c;
struct Param_2a7790 {
    char pad[0x1c];
    int tag;
    char pad2[8];
    int count;
};
extern "C" char DAT_0042db8c[];
typedef unsigned char u8_2a7aa0;
struct SceneGraphTransformAnimationController {
    virtual void v0();
    virtual void v1();
    virtual SceneGraphTransformAnimationController* vfunc_2(u8_2a7aa0);
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
    void init_00285f50();
    char pad[0x110 - 4];
    int member;
};
void destroy_00263f30(SceneGraphTransformAnimationController*);
typedef unsigned int u32_2a7b60;
struct Type_2a7b60 {};
extern Type_2a7b60 hulk_at_0048f610;
extern Type_2a7b60 hulk_at_004c29f4;
extern void* __cdecl Cast(void*, int, Type_2a7b60*, Type_2a7b60*, int);

} // namespace fn_f22c50ed

// 0x002a7730 FUN_002a7730 (37 B): matches/0x002a7730.cpp
// sym: ?FUN_002a7730@SceneGraphTransformAnimationController@pure3d@@QAEPAV12@XZ
pure3d::SceneGraphTransformAnimationController* pure3d::SceneGraphTransformAnimationController::FUN_002a7730() {
    ((SceneGraphTransformAnimationController_nv_2a7730*)this)->First_00285ac0();
    *(void**)this = &hulk_at_0042db8c;
    this->f_110 = 0;
    ((SceneGraphTransformAnimationController_nv_2a7730*)this)->Second_00284ad0(1);
    return (pure3d::SceneGraphTransformAnimationController*)(this);
}


// 0x002a7780 pure3d::SceneGraphTransformAnimationController::vfunc_3 (3 B): matches/0x002a7780.cpp
// sym: ?vfunc_3@SceneGraphTransformAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::SceneGraphTransformAnimationController::vfunc_3() {
    return true;
}


// 0x002a7790 pure3d::SceneGraphTransformAnimationController::vfunc_26 (39 B): matches/0x002a7790.cpp
// sym: ?vfunc_26@SceneGraphTransformAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::SceneGraphTransformAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && ((Param_2a7790*)p)->count > 0)
        return ((Param_2a7790*)p)->tag == 0x4e525453;
    return false;
}


// 0x002a77c0 FUN_002a77c0 (13 B): matches/0x002a77c0.cpp
// sym: ?FUN_002a77c0@C_2a77c0@owners@@QAEXH@Z
void owners::C_2a77c0::FUN_002a77c0(hulk_intptr x) {
    value = ((int)x);
}


// 0x002a77e0 pure3d::SceneGraphTransformAnimationController::vfunc_27 (209 B): equivalent/0x002a77e0.cpp [wrapped: conflict: pure3d::SceneGraphTransformAnimationController]
// sym: ?vfunc_27@SceneGraphTransformAnimationController@pure3d@fn_002a77e0@@QAEXXZ
namespace fn_002a77e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// pure3d::SceneGraphTransformAnimationController::vfunc_27 @ 0x002a77e0
struct Node {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(int,int,int,int);
 char pad04[16]; Node* child; char pad18[16]; float rotation[12]; float translation[3];
};
struct Channel {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(float, float*); virtual void v5(); virtual void v6(float,float*);
};
struct Track { Channel* FUN_00288960(unsigned,unsigned); };
struct Animation { Track* FUN_00288a10(int); };
struct State_2a77e0 { Animation* FUN_00284f50(); float FUN_00284f70(); };
namespace pure3d {
struct SceneGraphTransformAnimationController {
 char pad0[44]; State_2a77e0 state; char pad2d[227]; Node* node;
 void vfunc_27();
};
}
void pure3d::SceneGraphTransformAnimationController::vfunc_27() {
 Track* track = state.FUN_00284f50()->FUN_00288a10(0);
 float time = state.FUN_00284f70();
 Channel* channel = track->FUN_00288960(0x544f52,0x544f52);
 if(channel) {
 Node* n=node;
 n->v10(1,6,2,1);
 if(n->child) n->child->v10(1,2,1,1);
 channel->v6(time,n->rotation);
 }
 channel=track->FUN_00288960(0x4e415254,0x54434556);
 if(channel) {
 Node* n=node;
 n->v10(1,6,2,1);
 if(n->child) n->child->v10(1,2,1,1);
 channel->v4(time,n->translation);
 }
}
} // namespace fn_002a77e0


// 0x002a78c0 pure3d::SceneGraphTransformAnimationController::vfunc_28 (468 B): equivalent/0x002a78c0.cpp [wrapped: conflict: Channel; Node]
// sym: ?vfunc_28@SceneGraphTransformAnimationController@fn_002a78c0@@UAEXXZ
namespace fn_002a78c0 {
// STATUS: equivalent (tools/equiv.py level 3: 57 inputs, branch coverage 12/12)
// pure3d::SceneGraphTransformAnimationController::vfunc_28 @ 0x002a78c0
struct V3_2a78c0 { float x, y, z; };

struct Matrix {
    float r[12];
    V3_2a78c0 pos;
    float w;
};

struct Quat_2a78c0 {
    float x, y, z, w;
    void FUN_0022b650(Matrix* m);
};

class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(float t, V3_2a78c0* out);
    virtual void vf5(float t, Quat_2a78c0* out);
};

class ChannelSet_2a78c0 {
public:
    Channel* FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};

class Source_2a78c0 {
public:
};

class Node {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(int a, int b, int c, int d);
    char pad04[0x14 - 4];
    Node* child;
    char pad18[0x28 - 0x18];
    Matrix xform;
};

struct Track {
    float cur;
    int a4;
    int a8;
    float remain;
    float fadeRate;
    float weight;
    int f18;
    int f1c;
    int a20;
    int f24;
    Source_2a78c0* owner;
    float FUN_00284f70();
};

class SceneGraphTransformAnimationController {
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
    virtual void vfunc_28();
    virtual void v29();
    char pad04[0x28 - 4];
    unsigned int count;
    Track tracks[5];
    char pad108[0x110 - 0x108];
    Node* target;
};

void SceneGraphTransformAnimationController::vfunc_28()
{
    struct Frame {
        float w;
        float inv;
        unsigned int i;
        float cur;
        V3_2a78c0 acc;
        V3_2a78c0 t;
        Quat_2a78c0 q;
        Quat_2a78c0 r;
    } fr;
    fr.acc.x = 0.0f;
    fr.acc.y = 0.0f;
    fr.acc.z = 0.0f;
    fr.q.x = 0.0f;
    fr.q.y = 0.0f;
    fr.q.z = 0.0f;
    fr.q.w = 1.0f;
    fr.i = 0;
    if (count != 0) {
        Track* trk = &tracks[0];
        do {
            Source_2a78c0* src = ((Source_2a78c0 *)((owners::Target_284f50 *)trk)->FUN_00284f50());
            ChannelSet_2a78c0* cs = ((ChannelSet_2a78c0 *)((owners::Target_288a10 *)src)->FUN_00288a10(0));
            fr.cur = trk->FUN_00284f70();
            fr.w = ((owners::CJumpTrack_284f60 *)trk)->FUN_00284f60();
            fr.inv = 1.0f - fr.w;
            Channel* rot = cs->FUN_00288960(0x544f52, 0x544f52);
            if (rot != 0) {
                rot->vf5(fr.cur, &fr.r);
                ((owners::Quaternion_22b750 *)&(fr.q))->FUN_0022b750((const owners::Quaternion_22b750 *)(const Quat_2a78c0 *)(&fr.q), (const owners::Quaternion_22b750 *)(const Quat_2a78c0 *)(&fr.r), fr.w);
            }
            Channel* pos = cs->FUN_00288960(0x4e415254, 0x54434556);
            if (pos != 0) {
                fr.acc.x = fr.acc.x * fr.inv;
                fr.acc.y = fr.acc.y * fr.inv;
                fr.acc.z = fr.acc.z * fr.inv;
                pos->vf4(fr.cur, &fr.t);
                fr.acc.x = fr.t.x * fr.w + fr.acc.x;
                fr.acc.y = fr.t.y * fr.w + fr.acc.y;
                fr.acc.z = fr.t.z * fr.w + fr.acc.z;
            }
            fr.i++;
            trk++;
        } while (fr.i < count);
    }
    Node* n = target;
    n->vf10(1, 6, 2, 1);
    if (n->child != 0)
        n->child->vf10(1, 2, 1, 1);
    fr.q.FUN_0022b650(&n->xform);
    n = target;
    n->vf10(1, 6, 2, 1);
    if (n->child != 0)
        n->child->vf10(1, 2, 1, 1);
    n->xform.pos.x = fr.acc.x;
    n->xform.pos.y = fr.acc.y;
    n->xform.pos.z = fr.acc.z;
}
} // namespace fn_002a78c0

namespace fn_f22c50ed {

// 0x002a7aa0 pure3d::SceneGraphTransformAnimationController::vfunc_2 (46 B): matches/0x002a7aa0.cpp
// sym: ?vfunc_2@SceneGraphTransformAnimationController@fn_f22c50ed@@UAEPAU12@E@Z
SceneGraphTransformAnimationController* SceneGraphTransformAnimationController::vfunc_2(u8_2a7aa0 flag) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042db8c);
    member = 0;
    init_00285f50();
    if (flag & 1)
        destroy_00263f30(this);
    return this;
}

} // namespace fn_f22c50ed

// 0x002a7b10 pure3d::SceneGraphTransformAnimationController::vfunc_4 (78 B): matches/0x002a7b10.cpp [wrapped: conflict: SceneGraphTransformAnimationController]
// sym: ?vfunc_4@SceneGraphTransformAnimationController@fn_002a7b10@@QAEPAV12@XZ
namespace fn_002a7b10 {
extern "C" char DAT_0042db8c[];
class SceneGraphTransformAnimationController {
  public:
    hulk_uintptr vf;
    char pad[0x10c];
    int field;
    SceneGraphTransformAnimationController* vfunc_4();
    void copy_00285d70(SceneGraphTransformAnimationController*);
    void initialize_00284ad0(int);
};
extern "C++" __declspec(nothrow) void* alloc_00263ea0(hulk_uintptr);

SceneGraphTransformAnimationController* SceneGraphTransformAnimationController::vfunc_4() {
    SceneGraphTransformAnimationController* p = (SceneGraphTransformAnimationController*)alloc_00263ea0(0x118);
    if (p) {
        p->copy_00285d70(this);
        p->vf = ((hulk_intptr)DAT_0042db8c);
        p->field = 0;
        p->initialize_00284ad0(1);
        p->field = field;
        return p;
    }
    return 0;
}
} // namespace fn_002a7b10


// 0x002a7b60 pure3d::SceneGraphTransformAnimationController::vfunc_5 (40 B): matches/0x002a7b60.cpp
// sym: ?vfunc_5@SceneGraphTransformAnimationController@pure3d@@UAEXPAX@Z
void pure3d::SceneGraphTransformAnimationController::vfunc_5(void* __p0) { void * p = (void *)__p0;

    (*(void * *)&this->f_110) = Cast(p, 0, &hulk_at_0048f610, &hulk_at_004c29f4, 0);
}

