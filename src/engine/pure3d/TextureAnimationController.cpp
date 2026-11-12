// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a9410..0x002a9760 (kind game, layer engine, confidence high), dominant class pure3d::TextureAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f097dcce {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f097dcce {} using namespace fn_f097dcce;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f097dcce {
extern "C" void __fastcall FUN_00284cd0(void*);
class TextureAnimationController_2a9410 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    TextureAnimationController_2a9410();
};
struct Anim {
    char pad[0x1c];
    int type;
    char pad2[8];
    int count;
};
} // namespace fn_f097dcce
namespace pure3d {
class Channel_2a9480 {
public:
    virtual void v0();
};
}
namespace pure3d {
class EntityChannel_2a9480 : public Channel_2a9480 {
public:
    virtual void v1();
    char pad04[4];
    int field8;              // 0x08
    void FUN_0028ac00(int arg, class Entity_2a9480 **out);
};
}
namespace pure3d {
class Entity_2a9480 {
public:
    virtual void v0();
    char pad04[0xc];
    int field10;             // 0x10
};
}
namespace pure3d {
class Texture_2a9480 : public Entity_2a9480 {
public:
    virtual void v1();
};
}
namespace fn_f097dcce {
struct ChannelList_2a9480 {
    char pad00[0x14];
    int count;               // 0x14
};
struct ChannelSource {
};
class Receiver_2a9480 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void Apply(int a, int b);        // slot 5
};
struct Binding_2a9480 {
    char pad00[0x10];
    Receiver_2a9480 *receiver;      // 0x10
};
extern void* hulk_at_0042de4c[];
class Ref_2a9510 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a9510 {
  public:
    void* vptr;
    void Fin_00285800();
};
class TextureAnimationController_2a9510 : public SimpleFrameController_2a9510 {
  public:
    char pad[60];
    Ref_2a9510* m;
    ~TextureAnimationController_2a9510();
};
class Obj_2a9540 {
  public:
    virtual void f();
    virtual void g();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Obj_2a9540* mObj;
    void vfunc_8(Obj_2a9540* p);
};
extern void* g_vftable_2a9570[];
} // namespace fn_f097dcce
void operator delete(void*);
namespace fn_f097dcce {
class Ref_2a9570 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a9570 {
  public:
    void* vptr;
    void Fin_00285800();
};
class TextureAnimationController_2a9570 : public SimpleFrameController_2a9570 {
  public:
    char pad[0x40 - 4];
    Ref_2a9570* m;
    TextureAnimationController_2a9570* f2(unsigned char flags);
};
extern "C" char DAT_0042de4c[];
struct TextureAnimationController_nv_2a95f0 {
    void Init_00285780(pure3d::TextureAnimationController*);
};
extern void* __cdecl Alloc_00263ea0(unsigned int);


// 0x002a9410 FUN_002a9410 (25 B): matches/0x002a9410.cpp
// sym: ??0TextureAnimationController_2a9410@fn_f097dcce@@QAE@XZ
// Same code shape as 0x002960e0 (propagated; names are from that function)
TextureAnimationController_2a9410::TextureAnimationController_2a9410() {
    FUN_00284cd0((void*)(this));
    vptr = ((void**)DAT_0042de4c);
    field40 = 0;
}

} // namespace fn_f097dcce

// 0x002a9430 pure3d::TextureAnimationController::vfunc_3 (3 B): matches/0x002a9430.cpp
// sym: ?vfunc_3@TextureAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::TextureAnimationController::vfunc_3() {
    return true;
}


// 0x002a9440 pure3d::TextureAnimationController::vfunc_26 (39 B): matches/0x002a9440.cpp
// sym: ?vfunc_26@TextureAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::TextureAnimationController::vfunc_26(void* __p0) { Anim * a = (Anim *)__p0;

    if (a && a->count > 0)
        return a->type == 0x584554;
    return false;
}


// 0x002a9480 pure3d::TextureAnimationController::vfunc_7 (144 B): equivalent/0x002a9480.cpp
// sym: ?vfunc_7@TextureAnimationController@pure3d@@UAEXXZ @a1d1d65e7ddd @w44c1e30bdb36
// STATUS: equivalent (tools/equiv.py level 3: 222 inputs, branch coverage 8/8)
// pure3d::TextureAnimationController::vfunc_7 @ 0x002a9480
void pure3d::TextureAnimationController::vfunc_7() {
    ChannelList_2a9480 *list = ((ChannelList_2a9480 *)((owners::Target_288a10 *)((*(ChannelSource * *)&this->f_3c)))->FUN_00288a10(0));
    for (int i = list->count - 1; i >= 0; i--) {
        pure3d::EntityChannel_2a9480 *channel = dynamic_cast<pure3d::EntityChannel_2a9480 *>(((pure3d :: Channel_2a9480 *)((owners::C_288950 *)list)->FUN_00288950(i)));
        if (channel == 0)
            continue;
        pure3d::Entity_2a9480 *entity;
        channel->FUN_0028ac00((*(int *)&this->f_34), &entity);
        pure3d::Texture_2a9480 *texture = dynamic_cast<pure3d::Texture_2a9480 *>(entity);
        int target = channel->field8;
        if (texture == 0)
            continue;
        (*(Binding_2a9480 * *)&this->f_40)->receiver->Apply(target, texture->field10);
    }
}

namespace fn_f097dcce {

// 0x002a9510 FUN_002a9510 (36 B): matches/0x002a9510.cpp
// sym: ??1TextureAnimationController_2a9510@fn_f097dcce@@QAE@XZ
TextureAnimationController_2a9510::~TextureAnimationController_2a9510() {
    vptr = hulk_at_0042de4c;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285800();
}


// 0x002a9540 FUN_002a9540 (38 B): matches/0x002a9540.cpp
// sym: ?vfunc_8@CMotionTrail@fn_f097dcce@@QAEXPAVObj_2a9540@2@@Z
// Same code shape as 0x002830e0 (propagated; names are from that function)
void CMotionTrail::vfunc_8(Obj_2a9540* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}


// 0x002a9570 pure3d::TextureAnimationController::vfunc_2 (57 B): matches/0x002a9570.cpp
// sym: ?f2@TextureAnimationController_2a9570@fn_f097dcce@@QAEPAV12@E@Z
TextureAnimationController_2a9570* TextureAnimationController_2a9570::f2(unsigned char flags) {
    vptr = ((void**)DAT_0042de4c);
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285800();
    if (flags & 1)
        operator delete(this);
    return this;
}

} // namespace fn_f097dcce

// 0x002a95f0 pure3d::TextureAnimationController::vfunc_4 (79 B): matches/0x002a95f0.cpp
// sym: ?vfunc_4@TextureAnimationController@pure3d@@UAEPAXXZ
void* pure3d::TextureAnimationController::vfunc_4() {
    pure3d::TextureAnimationController* p = (pure3d::TextureAnimationController*)Alloc_00263ea0(0x48);
    if (p) {
        ((TextureAnimationController_nv_2a95f0*)(p))->Init_00285780(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042de4c);
        (*(pure3d::TextureAnimationController * *)&p->f_40) = 0;
        pure3d::TextureAnimationController* r = (*(pure3d::TextureAnimationController * *)&this->f_40);
        if (r)
            r->vfunc_0();
        if ((*(pure3d::TextureAnimationController * *)&p->f_40))
            (*(pure3d::TextureAnimationController * *)&p->f_40)->vfunc_1();
        (*(pure3d::TextureAnimationController * *)&p->f_40) = r;
    } else {
        return (void*)(0);
    }
    return (void*)(p);
}


// 0x002a9640 pure3d::TextureAnimationController::vfunc_5 (99 B): matches/0x002a9640.cpp
// sym: ?vfunc_5@TextureAnimationController@pure3d@@UAEXPAX@Z
// the original casts to the game's classes (RTTI 0x0048f610 pure3d::Entity, 0x004ce60c pure3d::DrawablePrimitive,
// 0x0048e000 pure3d::Shader); the shader comes from DrawablePrimitive slot 7, the reference count is core::IRefCount's
void pure3d::TextureAnimationController::vfunc_5(void* __p0) { pure3d::Entity * e = (pure3d::Entity *)__p0;

    pure3d::Shader* r;
    pure3d::DrawablePrimitive* d = dynamic_cast<pure3d::DrawablePrimitive*>(e);
    if (d)
        r = (pure3d::Shader*)d->vfunc_7();
    else
        r = dynamic_cast<pure3d::Shader*>(e);
    if (r)
        r->vfunc_0();
    if ((pure3d::Shader*)this->f_40)
        ((pure3d::Shader*)this->f_40)->vfunc_1();
    this->f_40 = r;
}

