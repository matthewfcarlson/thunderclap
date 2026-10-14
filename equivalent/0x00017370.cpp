// STATUS: equivalent (tools/equiv.py level 3: 2987 inputs, branch coverage 4/4)
// COrientAction::vfunc_6 @ 0x00017370
struct Actor; struct Controller; struct Task;
struct Source { Controller* FUN_000592a0(); };
struct Controller { Actor* FUN_00059a40(); };
struct Angle { float FUN_002220d0(); };
struct Label { void FUN_0027b040(const char*); };
struct Value { void FUN_00221d20(float); };
struct Task { virtual void vfunc_0(); char pad[4]; Label label; char pad2[11]; int mode; Value value; Task* FUN_002248f0(int); };
struct Actor { char pad[16]; Angle angle; void FUN_00222890(Task*,float,float,float,float,float,float); };
struct Params { char pad[32]; float x,y,z; };
void* __cdecl FUN_00263ea0(unsigned int);
struct COrientAction { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual bool vfunc_6(int); char pad[24]; Source* source; Params* params; Task* task; };
bool COrientAction::vfunc_6(int) { Actor* actor=source->FUN_000592a0()->FUN_00059a40(); if(!actor) return false; float x=params->x,y=params->y,z=params->z; Task* p=(Task*)FUN_00263ea0(0x70); if(p) p=p->FUN_002248f0(0); task=p; task->label.FUN_0027b040("orient"); task->vfunc_0(); float a=actor->angle.FUN_002220d0(); task->value.FUN_00221d20(a); task->mode=2; actor->FUN_00222890(task,-1.0f,x,1.0f,y,z,-1.0f); return true; }