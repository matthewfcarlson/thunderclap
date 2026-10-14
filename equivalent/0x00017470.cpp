// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 4/4)
// COrientTargetAction::vfunc_6 @ 0x00017470
struct Target;
struct Owner { Target* FUN_000592a0(); };
struct Angle { float FUN_002220d0(); void FUN_00221d20(float); };
struct Label { void FUN_0027b040(const char*); };
struct Task {
 virtual void slot0();
 char pad4[4];
 Label label;
 char pad9[11];
 int mode;
 Angle angle;
 Task* FUN_002248f0(int);
};
struct Target {
 char pad0[16];
 Angle angle;
 void FUN_00059a30();
 Target* FUN_00059a40();
 void FUN_00222890(Task*,float,float,float,float,float,float);
};
struct Config { char pad[32]; float x,y,z; };
void* __cdecl FUN_00263ea0(unsigned int);
struct COrientTargetAction {
 char pad[28]; Owner* owner; Config* config; int unknown; Task* task;
 bool vfunc_6(int);
};
bool COrientTargetAction::vfunc_6(int) {
 Target* t=owner->FUN_000592a0();
 t->FUN_00059a30();
 t=t->FUN_00059a40();
 if(!t) return false;
 float x=config->x, y=config->y, z=config->z;
 Task* p=(Task*)FUN_00263ea0(0x70);
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