// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::FlyingAutoTargetAction::vfunc_3 @ 0x001346d0
struct VectorPart { void FUN_00221be0(const void*); };
struct NamePart { void FUN_0027b040(const char*); };
struct Created_1346d0 {
 virtual void vfunc_0();
 char pad4[4];
 NamePart name;
 char pad9[15];
 VectorPart vector;
 Created_1346d0* FUN_002248f0(int);
};
struct Target_1346d0 {
 char pad[16];
 char position[12];
 void FUN_00222890(Created_1346d0*,float,float,float,float,float,float);
};
struct Controller_1346d0 {
 void FUN_00059a30();
 Target_1346d0* FUN_00059a40();
};
struct Source_1346d0 { Controller_1346d0* FUN_000592a0(); };
struct Settings_1346d0 { char pad[48]; float x,y,z; };
extern void* __cdecl FUN_00263ea0(unsigned int);
namespace hulkfight { namespace motion {
struct FlyingAutoTargetAction {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
 virtual bool vfunc_3(int,int);
 virtual void vfunc_4(); virtual void vfunc_5();
 char pad[24]; Settings_1346d0* settings; Source_1346d0* source; Created_1346d0* created;
};
bool FlyingAutoTargetAction::vfunc_3(int,int) {
 Controller_1346d0* controller=source->FUN_000592a0();
 controller->FUN_00059a30();
 Target_1346d0* target=controller->FUN_00059a40();
 if (!target) return false;
 float x=settings->x, y=settings->y, z=settings->z;
 Created_1346d0* storage=(Created_1346d0*)FUN_00263ea0(0x70);
 Created_1346d0* object=storage ? storage->FUN_002248f0(0) : 0;
 created=object;
 object->name.FUN_0027b040("flyingAutoTarget");
 created->vfunc_0();
 created->vector.FUN_00221be0(target->position);
 target->FUN_00222890(created,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}
}}
