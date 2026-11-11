// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a83e0..0x002a87c0 (kind game, layer engine, confidence high), dominant class pure3d::ShaderAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f8dbb66d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f8dbb66d {} using namespace fn_f8dbb66d;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f8dbb66d {
extern "C" void __fastcall FUN_00284cd0(void*);
class ShaderAnimationController_2a83e0 {
  public:
    void* vptr;
    char pad[0x3c];
    int field40;
    ShaderAnimationController_2a83e0();
};
} // namespace fn_f8dbb66d
namespace pure3d {
struct Vec3_2a8450 {
    float x, y, z;
};
}
namespace pure3d {
struct Quat_2a8450 {
    float x, y, z, w;
};
}
namespace pure3d {
class Entity_2a8450 {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
};
}
namespace pure3d {
class Texture_2a8450 : public Entity_2a8450 {
public:
    char pad04[0x10 - 4];
    int handle;               // 0x10
};
}
namespace pure3d {
class ParamSink {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5(int id, int tex);
    virtual void s6(int id, int value);
    virtual void s7(int id, float value);
    virtual void s8(int id, int color);
    virtual void s9(int id, const Vec3_2a8450 *v);
    virtual void s10(int id, const Quat_2a8450 *q);
};
}
namespace pure3d {
struct SinkHolder_2a8450 {
    char pad00[0x10];
    ParamSink *sink;          // 0x10
};
}
namespace pure3d {
class Channel_2a8450 {
public:
    virtual void c0();
    virtual void c1();
    virtual unsigned int type();
    virtual void c3();
    virtual void sampleVec3(float frame, Vec3_2a8450 *out);
    virtual void c5();
    virtual void sampleQuat(float frame, Quat_2a8450 *out);
    char pad04[4];
    int paramId;              // 0x08
    void FUN_0028a0b0(float frame, int *out);
    void FUN_0028ac00(float frame, Entity_2a8450 **out);
    void FUN_0028ad20(float frame, int *out);
    void FUN_0028ac90(float frame, unsigned char *out);
    void FUN_0028a1c0(float frame, float *out);
};
}
namespace pure3d {
struct ChannelList_2a8450 {
    char pad00[0x14];
    int count;                // 0x14
    Channel_2a8450 *FUN_00288950(int index);
};
}
namespace pure3d {
struct Animation_2a8450 {
    ChannelList_2a8450 *FUN_00288a10(int index);
};
}
namespace fn_f8dbb66d {
extern void* hulk_at_0042dd24[];
class Ref_2a8620 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a8620 {
  public:
    void* vptr;
    void Fin_00285800();
};
class ShaderAnimationController_2a8620 : public SimpleFrameController_2a8620 {
  public:
    char pad[60];
    Ref_2a8620* m;
    ~ShaderAnimationController_2a8620();
};
class Obj_2a8650 {
  public:
    virtual void f();
    virtual void g();
};
class CMotionTrail {
  public:
    char pad[0x40];
    Obj_2a8650* mObj;
    void vfunc_8(Obj_2a8650* p);
};
extern void* g_vftable_2a8680[];
} // namespace fn_f8dbb66d
void operator delete(void*);
namespace fn_f8dbb66d {
class Ref_2a8680 {
  public:
    virtual void F0();
    virtual void Release();
};
class SimpleFrameController_2a8680 {
  public:
    void* vptr;
    void Fin_00285800();
};
class ShaderAnimationController_2a8680 : public SimpleFrameController_2a8680 {
  public:
    char pad[0x40 - 4];
    Ref_2a8680* m;
    ShaderAnimationController_2a8680* f2(unsigned char flags);
};
extern "C" char DAT_0042dd24[];
class SimpleFrameController_2a8700 {
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
};
class ShaderAnimationController_2a8700 : public SimpleFrameController_2a8700 {
  public:
    char pad[0x40 - sizeof(SimpleFrameController_2a8700)];
    SimpleFrameController_2a8700* mRef;
    virtual SimpleFrameController_2a8700* own4();
    void setup_00285780(ShaderAnimationController_2a8700*);
};
extern void* __cdecl alloc_00263ea0(hulk_uintptr);


// 0x002a83e0 FUN_002a83e0 (25 B): matches/0x002a83e0.cpp
// sym: ??0ShaderAnimationController_2a83e0@fn_f8dbb66d@@QAE@XZ
// Same code shape as 0x002960e0 (propagated; names are from that function)
ShaderAnimationController_2a83e0::ShaderAnimationController_2a83e0() {
    FUN_00284cd0((void*)(this));
    vptr = &scenegraph_vftable;
    field40 = 0;
}

} // namespace fn_f8dbb66d

// 0x002a8400 pure3d::ShaderAnimationController::vfunc_3 (3 B): matches/0x002a8400.cpp
// sym: ?vfunc_3@ShaderAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ShaderAnimationController::vfunc_3() {
    return true;
}


// 0x002a8410 pure3d::ShaderAnimationController::vfunc_26 (39 B): matches/0x002a8410.cpp
// sym: ?vfunc_26@ShaderAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::ShaderAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && *(int*)((char*)p + 0x28) > 0)
        return *(int*)((char*)p + 0x1c) == 0x44414853;
    return false;
}


// 0x002a8450 pure3d::ShaderAnimationController::vfunc_7 (460 B): equivalent/0x002a8450.cpp
// sym: ?vfunc_7@ShaderAnimationController@pure3d@@UAEXXZ @f9c83d82bc9b @wd303900717e8
// STATUS: equivalent (tools/equiv.py level 3: 141 inputs, branch coverage 18/22, incomplete)
// pure3d::ShaderAnimationController::vfunc_7 @ 0x002a8450
void pure3d::ShaderAnimationController::vfunc_7() {
    ChannelList_2a8450 *list = (*(Animation_2a8450 * *)&this->f_3c)->FUN_00288a10(0);
    for (int i = 0; i < list->count; i++) {
        Channel_2a8450 *ch = list->FUN_00288950(i);
        switch (ch->type()) {
        case 0x544f52: {
            Quat_2a8450 q;
            ch->sampleQuat(this->f_34, &q);
            (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s10(ch->paramId, &q);
            break;
        }
        case 0x524c43: {
            int color;
            ch->FUN_0028ad20(this->f_34, &color);
            (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s8(ch->paramId, color);
            break;
        }
        case 0x544e45: {
            Entity_2a8450 *e;
            ch->FUN_0028ac00(this->f_34, &e);
            int id = ch->paramId;
            Texture_2a8450 *t = dynamic_cast<Texture_2a8450 *>(e);
            if (t)
                (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s5(id, t->handle);
            else
                (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s5(id, 0);
            break;
        }
        case 0x544e49: {
            int value;
            ch->FUN_0028a0b0(this->f_34, &value);
            (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s6(ch->paramId, value);
            break;
        }
        case 0x31544c46: {
            float f;
            ch->FUN_0028a1c0(this->f_34, &f);
            (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s7(ch->paramId, f);
            break;
        }
        case 0x4c4f4f42: {
            unsigned char b;
            ch->FUN_0028ac90(this->f_34, &b);
            (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s6(ch->paramId, b);
            break;
        }
        case 0x54434556: {
            Vec3_2a8450 v;
            ch->sampleVec3(this->f_34, &v);
            (*(SinkHolder_2a8450 * *)&this->f_40)->sink->s9(ch->paramId, &v);
            break;
        }
        default:
            break;
        }
    }
}

namespace fn_f8dbb66d {

// 0x002a8620 FUN_002a8620 (36 B): matches/0x002a8620.cpp
// sym: ??1ShaderAnimationController_2a8620@fn_f8dbb66d@@QAE@XZ
ShaderAnimationController_2a8620::~ShaderAnimationController_2a8620() {
    vptr = hulk_at_0042dd24;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285800();
}


// 0x002a8650 FUN_002a8650 (38 B): matches/0x002a8650.cpp
// sym: ?vfunc_8@CMotionTrail@fn_f8dbb66d@@QAEXPAVObj_2a8650@2@@Z
// Same code shape as 0x002830e0 (propagated; names are from that function)
void CMotionTrail::vfunc_8(Obj_2a8650* p) {
    if (p)
        p->f();
    if (mObj)
        mObj->g();
    mObj = p;
}


// 0x002a8680 pure3d::ShaderAnimationController::vfunc_2 (57 B): matches/0x002a8680.cpp
// sym: ?f2@ShaderAnimationController_2a8680@fn_f8dbb66d@@QAEPAV12@E@Z
ShaderAnimationController_2a8680* ShaderAnimationController_2a8680::f2(unsigned char flags) {
    vptr = g_vftable_2a8680;
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


// 0x002a8700 pure3d::ShaderAnimationController::vfunc_4 (79 B): matches/0x002a8700.cpp
// sym: ?own4@ShaderAnimationController_2a8700@fn_f8dbb66d@@UAEPAVSimpleFrameController_2a8700@2@XZ
SimpleFrameController_2a8700* ShaderAnimationController_2a8700::own4() {
    ShaderAnimationController_2a8700* self = this;
    ShaderAnimationController_2a8700* p = (ShaderAnimationController_2a8700*)alloc_00263ea0(0x48);
    if (p) {
        p->setup_00285780(self);
        *(hulk_intptr*)p = ((hulk_intptr)DAT_0042dd24);
        p->mRef = 0;
        SimpleFrameController_2a8700* q = self->mRef;
        if (q)
            q->v0();
        if (p->mRef)
            p->mRef->v1();
        p->mRef = q;
        return (SimpleFrameController_2a8700*)p;
    }
    return 0;
}

} // namespace fn_f8dbb66d

// 0x002a8750 pure3d::ShaderAnimationController::vfunc_5 (99 B): matches/0x002a8750.cpp
// sym: ?vfunc_5@ShaderAnimationController@pure3d@@UAEXPAX@Z
// the original casts to the game's classes (RTTI 0x0048f610 pure3d::Entity, 0x004ce60c pure3d::DrawablePrimitive,
// 0x0048e000 pure3d::Shader); the shader comes from DrawablePrimitive slot 7, the reference count is core::IRefCount's
void pure3d::ShaderAnimationController::vfunc_5(void* __p0) { pure3d::Entity * e = (pure3d::Entity *)__p0;

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

