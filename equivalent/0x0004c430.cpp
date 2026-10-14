// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// CCollisionPushbackYAngleCondition::vfunc_7 @ 0x0004c430
struct Vec_4c430 { float x,y,z; float FUN_0022d110(); };
struct State_4c430 { char pad[0x28]; Vec_4c430 direction; };
struct Context { virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual State_4c430* slot3(); };
float __cdecl FUN_000189c0(float);
bool __cdecl FUN_00018960(float,float,float);
class CCollisionPushbackYAngleCondition {
public:
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7(Context*);
 char pad[8]; unsigned operation; float threshold;
};
bool CCollisionPushbackYAngleCondition::vfunc_7(Context* c) {
 State_4c430* s=c->slot3(); if(!s) return false;
 Vec_4c430 v=s->direction; v.FUN_0022d110();
 float angle=FUN_000189c0(v.y);
 switch(operation) {
 case 0: return angle < threshold;
 case 1: return angle <= threshold;
 case 2: return FUN_00018960(angle,threshold,0.00001f);
 case 3: return !FUN_00018960(angle,threshold,0.00001f);
 case 4: return angle >= threshold;
 case 5: return angle > threshold;
 }
 return false;
}