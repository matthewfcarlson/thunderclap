// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002fc420..0x002fca90 (kind game, layer engine, confidence medium), dominant class physics::PhysicsInstance
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/content.h"
#include "gen/owners.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fb7c7da0 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fb7c7da0 {} using namespace fn_fb7c7da0;
#include "engine/physics.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fb7c7da0 {
struct TypeInfo_2fc420 { unsigned int value; };
extern TypeInfo_2fc420 DAT_004c60bc, DAT_004d2d90;
struct JointSet { char pad[0x1f8]; void **joints; int unused; int count; };
extern "C" JointSet* __cdecl FUN_00344e74(void*, int, TypeInfo_2fc420*, TypeInfo_2fc420*, int);
extern "C" void* __cdecl FUN_00263ea0(unsigned int);
struct FUN_0030eb10 { FUN_0030eb10(); virtual void slot0(); char pad[0x14]; void* target; int extra; };
} // namespace fn_fb7c7da0
namespace physics {
struct PhysicsJointMatrixModifier_2fc420 : FUN_0030eb10 { virtual void slot0(); };
}
namespace physics {
struct RootMatrixDriver_2fc420 : FUN_0030eb10 { virtual void slot0(); };
}
namespace fn_fb7c7da0 {
struct Container_2fc420 { void FUN_0030fda0(int, FUN_0030eb10*); };
struct State_2fc420 { char pad[0x70]; unsigned char active; void FUN_003046f0(int); };
struct Object_2fc420 { virtual void slot0(); char pad[0x6c]; void* source; State_2fc420* state; void FUN_002ef8b0(int); };
extern "C" char DAT_003f6098[];
extern "C" char DAT_00431898[];
class Ref_2fc520 {
  public:
    virtual void Dummy();
    virtual void Release();
};
class Obj_2fc520 {
  public:
    virtual void Dummy();
    virtual void Release();
};
class PhysicsInstance_2fc520 {
  public:
    void* vptr;
    char pad[12];
    Obj_2fc520* obj;
    Ref_2fc520* ref;
    void Destroy();
};
class Global_2fc520 {
  public:
    void call(int);
};
struct Matrix {
    int m[16];
};
class Listener_2fc580 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int arg);
};
struct Skeleton {
    char pad0[0x10];
    Matrix matrix;             // 0x10
    char pad50[0x70 - 0x50];
    Listener_2fc580 *listener;        // 0x70
    void FUN_002fd950(int arg);
    void FUN_002fdd80(int arg);
};
struct Track {
    char pad0[0x10];
    int count;                 // 0x10
    void FUN_0030ff80(int a);
    void FUN_0030ffb0(int index, int arg);
    void FUN_00310010(int index);
    void FUN_00310070();
};
class Animator_2fc580 {
public:
    char pad0[8];
    void *target;              // 0x08
    char pad0c[4];
    Skeleton *skeleton;        // 0x10
    Track *track;              // 0x14
    void FUN_002fc580(int arg, Matrix *out);
};
class Sub2_2fc670 {
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
    void Fn(int);
};
class Sub3_2fc670 {
  public:
    void Fn(int);
};
class Sub1_2fc670 {
  public:
    void Set(int);
    char pad[0x70];
    Sub2_2fc670* a;
    Sub3_2fc670* b;
};
class Obj_2fc670 {
  public:
    char Change(int s);
    char pad[8];
    int mState;
    int pad2;
    Sub1_2fc670* mSub;
};
class Inner_2fc700 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(int, int);
};
class Outer_2fc700 {
  public:
    char pad[0x10];
    Inner_2fc700* p;
    void target(hulk_intptr a, int b);
};
typedef unsigned int u32_2fc720;
extern void __cdecl Cast(hulk_uintptr, int, const int*, const int*, int);

} // namespace fn_fb7c7da0

// 0x002fc420 FUN_002fc420 (250 B): equivalent/0x002fc420.cpp
// sym: ?FUN_002fc420@PhysicsInstance@physics@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 1114 inputs, branch coverage 12/12)
// FUN_002fc420 @ 0x002fc420
void physics::PhysicsInstance::FUN_002fc420() {
 if((*(Container_2fc420 * *)&this->f_14)) {
  JointSet* set=FUN_00344e74((*(Object_2fc420 * *)&this->f_10)->source,0,&DAT_004c60bc,&DAT_004d2d90,0);
  if(set) for(int i=0;i<set->count;++i) {
   void* joint=set->joints[i];
   void* mem=FUN_00263ea0(0x20);
   FUN_0030eb10* mod=0;
   if(mem) { mod=new(mem) physics::PhysicsJointMatrixModifier_2fc420; mod->target=joint; }
   (*(Container_2fc420 * *)&this->f_14)->FUN_0030fda0(1,mod);
  }
  void* mem=FUN_00263ea0(0x20);
  FUN_0030eb10* mod=0;
  if(mem) { void* target=(char*)(*(Object_2fc420 * *)&this->f_10)+0x10; mod=new(mem) physics::RootMatrixDriver_2fc420; mod->target=target; }
  (*(Container_2fc420 * *)&this->f_14)->FUN_0030fda0(0,mod);
 }
 (*(Object_2fc420 * *)&this->f_10)->slot0(); (*(Object_2fc420 * *)&this->f_10)->state->active=1; (*(Object_2fc420 * *)&this->f_10)->FUN_002ef8b0(0); (*(Object_2fc420 * *)&this->f_10)->state->FUN_003046f0(0); this->f_08=2; (*(unsigned char *)&this->f_0c)=0;
}

namespace fn_fb7c7da0 {

// 0x002fc520 FUN_002fc520 (93 B): matches/0x002fc520.cpp
// sym: ?Destroy@PhysicsInstance_2fc520@fn_fb7c7da0@@QAEXXZ
// data: global_2fc520 = DAT_00554c14
void PhysicsInstance_2fc520::Destroy() {
    vptr = (void*)((hulk_intptr)DAT_00431898);
    (*(Global_2fc520**)&DAT_00554c14)->call(*(int*)((char*)obj + 0x74));
    if (ref)
        ref->Release();
    obj->Release();
    Ref_2fc520* r = ref;
    if (r) {
        ref = 0;
        r->Release();
    }
    Obj_2fc520* o = obj;
    if (o) {
        obj = 0;
        o->Release();
    }
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}


// 0x002fc580 FUN_002fc580 (167 B): matches/0x002fc580.cpp
// sym: ?FUN_002fc580@Animator_2fc580@fn_fb7c7da0@@QAEXHPAUMatrix@2@@Z
// FUN_002fc580 @ 0x002fc580
void Animator_2fc580::FUN_002fc580(int arg, Matrix *out)
{
    if (target == 0)
        return;
    if (track != 0) {
        Listener_2fc580 *l = skeleton->listener;
        if (l != 0)
            l->v5(arg);
        Skeleton *sk = skeleton;
        sk->FUN_002fd950(arg);
        track->FUN_0030ff80(0);
        for (int i = 0; i < track->count; i++) {
            track->FUN_0030ffb0(i, arg);
            track->FUN_00310010(i);
        }
        sk->FUN_002fdd80(arg);
        track->FUN_00310070();
    } else {
        Listener_2fc580 *l = skeleton->listener;
        if (l != 0)
            l->v5(arg);
    }
    if (out != 0)
        *out = skeleton->matrix;
}


// 0x002fc670 FUN_002fc670 (126 B): matches/0x002fc670.cpp
// sym: ?Change@Obj_2fc670@fn_fb7c7da0@@QAEDH@Z
char Obj_2fc670::Change(int s) {
    int old = mState;
    if (s == old)
        return 1;
    switch (s) {
    case 0:
        mSub->Set(1);
        mSub->b->Fn(1);
        break;
    case 1:
        if (!mSub->a)
            return 0;
        mSub->Set(1);
        mSub->a->v13();
        break;
    case 2:
        mSub->Set(0);
        break;
    default:
        return 0;
    }
    mState = s;
    return 1;
}

} // namespace fn_fb7c7da0

// 0x002fc6f0 FUN_002fc6f0 (7 B): matches/0x002fc6f0.cpp
// sym: ?FUN_002fc6f0@C_2fc6f0@owners@@QAEHXZ
hulk_intptr owners::C_2fc6f0::FUN_002fc6f0() {
    return *(int*)((char*)this + 0x10) + 0x10;
}

namespace fn_fb7c7da0 {

// 0x002fc700 FUN_002fc700 (8 B): matches/0x002fc700.cpp
// sym: ?target@Outer_2fc700@fn_fb7c7da0@@QAEXHH@Z
void Outer_2fc700::target(hulk_intptr a, int b) {
    p->f6(a, b);
}

} // namespace fn_fb7c7da0

// 0x002fc720 content::LoadInventory::DynamicCaster<physics::ArticulatedPhysicsObject>::vfunc_0 (30 B): matches/0x002fc720.cpp
// sym: ?vfunc_0@?$DynamicCaster@VArticulatedPhysicsObject@physics@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<physics::ArticulatedPhysicsObject>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}


// 0x002fc740 FUN_002fc740 (282 B): equivalent/0x002fc740.cpp [wrapped: conflict: DAT_004c60bc; physics::PhysicsInstance]
// sym: ??0PhysicsInstance@physics@fn_002fc740@@QAE@PAX0PAUInput_2fc740@2@E@Z
namespace fn_002fc740 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 18/18)
// FUN_002fc740 @ 0x002fc740
struct PoseEngine_2fc740 { virtual void AddRef(); virtual void Release(); char pad[8]; void* data; PoseEngine_2fc740* FUN_00310080(void*,int,void*); void FUN_0030ff80(int); };
struct Input_2fc740 { char pad[12]; void* data; void FUN_00284820(int); };
extern char DAT_004c60bc; extern char DAT_004d2d90;
void* __cdecl FUN_00344e74(void*,int,void*,void*,int);
extern "C" void* __cdecl FUN_0008d690(unsigned);
extern "C" PoseEngine_2fc740* __cdecl FUN_002fddf0(void*,void*,void*);
extern "C" PoseEngine_2fc740* __cdecl FUN_002efa90(void*,void*,int);
extern "C" PoseEngine_2fc740* __cdecl FUN_002fe480(Input_2fc740*,void*,void*);
namespace physics { struct PhysicsInstance { virtual void v0(); unsigned field4; unsigned field8; unsigned char active; char pad[3]; PoseEngine_2fc740* object; PoseEngine_2fc740* wrapper; PhysicsInstance(void*,void*,Input_2fc740*,unsigned char); void FUN_002fc420(); }; }
physics::PhysicsInstance::PhysicsInstance(void* a,void* b,Input_2fc740* input,unsigned char mode) {
field4=0; active=1; object=0; wrapper=0;
PoseEngine_2fc740* result;
if (!mode) { if(input) {
void* cast=FUN_00344e74(b,0,&DAT_004c60bc,&DAT_004d2d90,0);
PoseEngine_2fc740* mem=(PoseEngine_2fc740*)FUN_0008d690(32);
PoseEngine_2fc740* fresh=mem?mem->FUN_00310080(input,2,input->data):0;
PoseEngine_2fc740* old=wrapper;
if(old!=fresh){ wrapper=fresh; if(fresh)fresh->AddRef(); if(old)old->Release(); }
wrapper->AddRef(); wrapper->FUN_0030ff80(1);
result=FUN_002fddf0(wrapper->data,a,cast);
} else result=FUN_002efa90(a,b,0);
} else { input->FUN_00284820(0); result=FUN_002fe480(input,a,b); }
PoseEngine_2fc740* old=object;
if(old!=result){object=result;if(result)result->AddRef();if(old)old->Release();}
FUN_002fc420();
}
} // namespace fn_002fc740


// 0x002fc860 physics::PhysicsInstance::vfunc_2 (30 B): matches/0x002fc860.cpp
// sym: ??_GPhysicsInstance@physics@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
physics::PhysicsInstance::~PhysicsInstance() {}


// 0x002fc880 FUN_002fc880 (170 B): equivalent/0x002fc880.cpp [wrapped: conflict: physics::PhysicsInstance]
// sym: ??0PhysicsInstance@physics@fn_002fc880@@QAE@PAURef_2fc880@2@PAUInput_2fc880@2@@Z
namespace fn_002fc880 {
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 14/16, incomplete)
// FUN_002fc880 @ 0x002fc880
struct Ref_2fc880 { virtual void AddRef() = 0; virtual void Release() = 0; };
struct Input_2fc880 { char pad[12]; int value; };
struct PoseEngine_2fc880 : Ref_2fc880 { PoseEngine_2fc880* FUN_00310080(Input_2fc880*, int, int); void FUN_0030ff80(int); };
extern "C" void* __cdecl FUN_0008d690(unsigned int);
namespace physics {
struct PhysicsInstance {
 virtual void slot0();
 int field4;
 int field8;
 unsigned char enabled;
 char pad[3];
 Ref_2fc880* source;
 PoseEngine_2fc880* wrapper;
 void FUN_002fc420();
 PhysicsInstance(Ref_2fc880*, Input_2fc880*);
};
}
physics::PhysicsInstance::PhysicsInstance(Ref_2fc880* input, Input_2fc880* data) {
 field4=0;
 enabled=1;
 source=0;
 wrapper=0;
 Ref_2fc880* old=source;
 if(old!=input){ source=input; if(input) input->AddRef(); if(old) old->Release(); }
 if(data){
  PoseEngine_2fc880* object=(PoseEngine_2fc880*)FUN_0008d690(32);
  if(object) object=object->FUN_00310080(data,2,data->value);
  PoseEngine_2fc880* previous=wrapper;
  if(previous!=object){ wrapper=object; if(object) object->AddRef(); if(previous) previous->Release(); }
  wrapper->AddRef();
  wrapper->FUN_0030ff80(1);
 }
 FUN_002fc420();
}
} // namespace fn_002fc880


// 0x002fc990 FUN_002fc990 (150 B): equivalent/0x002fc990.cpp [wrapped: conflict: content::LoadInventory::DynamicCaster]
// sym: ?FUN_002fc990@fn_002fc990@@YAPAUPhysicsInstance_2fc990@1@IIPAVInventory_2fc990@1@I@Z
namespace fn_002fc990 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002fc990 @ 0x002fc990
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

namespace physics {
class CollisionObject;
class PhysicsObject;
class ArticulatedPhysicsObject;
}

class Inventory_2fc990 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void *get(void *caster, unsigned int lo, unsigned int hi);
};

extern "C" void *__cdecl FUN_0008d690(unsigned int size);

struct PhysicsInstance_2fc990 {
    char data[0x18];
    PhysicsInstance_2fc990 *FUN_002fc740(void *collision, void *physics, unsigned int a, unsigned int b);
};

PhysicsInstance_2fc990 *__cdecl FUN_002fc990(unsigned int lo, unsigned int hi, Inventory_2fc990 *inv, unsigned int extra)
{
    content::LoadInventory::DynamicCaster<physics::CollisionObject> collisionCaster;
    void *collision = inv->get(&collisionCaster, lo, hi);
    if (collision == 0)
        return 0;

    content::LoadInventory::DynamicCaster<physics::PhysicsObject> physicsCaster;
    void *physics = inv->get(&physicsCaster, lo, hi);
    if (physics == 0) {
        // the original asks again for an articulated object and drops the answer
        content::LoadInventory::DynamicCaster<physics::ArticulatedPhysicsObject> articulatedCaster;
        inv->get(&articulatedCaster, lo, hi);
    }

    PhysicsInstance_2fc990 *body = (PhysicsInstance_2fc990 *)FUN_0008d690(sizeof(PhysicsInstance_2fc990));
    if (body == 0)
        return 0;
    return body->FUN_002fc740(collision, physics, extra, 0);
}
} // namespace fn_002fc990

