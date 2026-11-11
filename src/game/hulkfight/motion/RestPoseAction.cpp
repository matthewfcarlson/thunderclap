// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00172650..0x00172790 (kind game, layer game, confidence medium), dominant class hulkfight::motion::RestPoseAction
#include "tree_prelude.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb8c7993 {
#define TREE_TU_END }
namespace fn_fb8c7993 {} using namespace fn_fb8c7993;
#include "game/hulkfight/motion.h"

// ---- declarations shared by the functions below
namespace fn_fb8c7993 {
class A_172650 {
  public:
};
class B_172650 {
  public:
    B_172650* next_00059a40();
    void finish_00222970(void*, int);
};
class A_172760 {
  public:
};
class B_172760 {
  public:
    B_172760* next_00059a40();
    void finish_00222970(void*, int);
};

} // namespace fn_fb8c7993

// 0x00172650 hulkfight::motion::SurfAction::vfunc_4 (41 B): matches/0x00172650.cpp
// sym: ?vfunc_4@SurfAction@motion@hulkfight@@UAEXXZ
void hulkfight::motion::SurfAction::vfunc_4() {
    A_172650* a = (A_172650*)(*(void * *)&this->f_20);
    if (a) {
        B_172650* b = (B_172650*)((A_172650 *)((owners::Object_592a0 *)a)->FUN_000592a0());
        b = b->next_00059a40();
        if (b)
            b->finish_00222970((*(void * *)&this->f_24), 0);
    }
}


// 0x00172680 hulkfight::motion::RestPoseAction::vfunc_3 (216 B): equivalent/0x00172680.cpp [wrapped: conflict: hulkfight::motion::RestPoseAction]
// sym: ?vfunc_3@RestPoseAction@motion@hulkfight@fn_00172680@@UAE_NPAX0@Z @1b3ddc99235c @w5ff74a7bc1d5
namespace fn_00172680 {
// STATUS: equivalent (tools/equiv.py level 3: 20008 inputs, branch coverage 16/16)
// hulkfight::motion::RestPoseAction::vfunc_3 @ 0x00172680
struct Result_172680;
struct RefPart { void FUN_0027b040(const char*); };
struct RestPoseDriver_172680 { virtual void addRef(); char pad[4]; RefPart ref; RestPoseDriver_172680* FUN_0022a5d0(Result_172680*); void FUN_002224a0(void*); };
struct Result_172680 { void* FUN_0027b670(unsigned int,unsigned int); };
struct Skeleton { Result_172680* FUN_002226b0(); void FUN_00222890(RestPoseDriver_172680*,float,float,float,float,float,float); };
struct Controller_172680 { void* FUN_00059a30(); Skeleton* FUN_00059a40(); };
struct Source_172680 { Controller_172680* FUN_000592a0(); };
struct PoseData_172680 { char pad[24]; unsigned int key1,key2; float x,y,z; };
void* __cdecl FUN_00263ea0(unsigned int);
namespace hulkfight { namespace motion {
struct RestPoseAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(void*,void*); virtual void vfunc_4(); virtual void vfunc_5();
 char pad[24]; PoseData_172680* data; Source_172680* source; RestPoseDriver_172680* object;
};
bool RestPoseAction::vfunc_3(void*,void*) {
 if (!source) return false;
 Controller_172680* controller=source->FUN_000592a0();
 if (!controller) return false;
 if (!controller->FUN_00059a30()) return false;
 Skeleton* skeleton=controller->FUN_00059a40();
 if (!skeleton) return false;
 Result_172680* result=skeleton->FUN_002226b0();
 if (!result) return false;
 RestPoseDriver_172680* allocated=(RestPoseDriver_172680*)FUN_00263ea0(32);
 RestPoseDriver_172680* created=allocated ? allocated->FUN_0022a5d0(result) : 0;
 object=created;
 created->ref.FUN_0027b040("restPose");
 object->addRef();
 unsigned int a=data->key1,b=data->key2;
 if (a|b) { void* value=result->FUN_0027b670(a,b); if(value) object->FUN_002224a0(value); }
 skeleton->FUN_00222890(object,-1.0f,data->x,1.0f,data->y,data->z,-1.0f);
 return true;
}
}}
} // namespace fn_00172680


// 0x00172760 hulkfight::motion::RestPoseAction::vfunc_4 (41 B): matches/0x00172760.cpp
// sym: ?vfunc_4@RestPoseAction@motion@hulkfight@@UAEXXZ
// Same code shape as 0x00172650 (propagated; names are from that function)
void hulkfight::motion::RestPoseAction::vfunc_4() {
    A_172760* a = (A_172760*)(*(void * *)&this->f_20);
    if (a) {
        B_172760* b = (B_172760*)((A_172760 *)((owners::Object_592a0 *)a)->FUN_000592a0());
        b = b->next_00059a40();
        if (b)
            b->finish_00222970((*(void * *)&this->f_24), 0);
    }
}

