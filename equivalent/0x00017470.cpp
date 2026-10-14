// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// COrientTargetAction::vfunc_6 @ 0x00017470
struct Target_17470;
struct Owner_17470 { Target_17470* FUN_000592a0(); };
struct Angle_17470 { float FUN_002220d0(); void FUN_00221d20(float); };
struct Label_17470 { void FUN_0027b040(const char*); };
struct Task_17470 {
 virtual void slot0();
 char pad4[4];
 Label_17470 label;
 char pad9[11];
 int mode;
 Angle_17470 angle;
 Task_17470* FUN_002248f0(int);
};
struct Target_17470 {
 char pad0[16];
 Angle_17470 angle;
 void FUN_00059a30();
 Target_17470* FUN_00059a40();
 void FUN_00222890(Task_17470*,float,float,float,float,float,float);
};
struct Config_17470 { char pad[32]; float x,y,z; };
void* __cdecl FUN_00263ea0(unsigned int);
struct COrientTargetAction {
 char pad[28]; Owner_17470* owner; Config_17470* config; int unknown; Task_17470* task;
 bool vfunc_6(int);
};
bool COrientTargetAction::vfunc_6(int) {
 Target_17470* t=owner->FUN_000592a0();
 t->FUN_00059a30();
 t=t->FUN_00059a40();
 if(!t) return false;
 float x=config->x, y=config->y, z=config->z;
 Task_17470* p=(Task_17470*)FUN_00263ea0(0x70);
 if(p) p=p->FUN_002248f0(0);
 task=p;
 task->label.FUN_0027b040("orientTarget");
 task->slot0();
 float a=t->angle.FUN_002220d0();
 task->angle.FUN_00221d20(a);
 task->mode=2;
 t->FUN_00222890(task,-1.0f,x,1.0f,y,z,-1.0f);
 return true;
}