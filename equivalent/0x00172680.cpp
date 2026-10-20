// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
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
