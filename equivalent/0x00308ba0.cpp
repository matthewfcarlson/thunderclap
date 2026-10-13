// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_00308ba0 @ 0x00308ba0
extern "C" double __cdecl sqrt(double);
extern float DAT_004d3120, DAT_004d311c, DAT_004d3118;
namespace physics {
struct SimCGSValue { virtual void slot0(); float a; float value; void FUN_002ecca0(); };
struct SimLength : SimCGSValue { void FUN_002ecf20(int); void vfunc_1(float); };
}
struct Body { float FUN_002ef420(); };
struct Properties { char pad[0x28]; float mass; float unused; float stiffness; };
struct Owner { char pad[0x10]; Body* body; char pad2[8]; Properties* properties; };
struct Target {
char pad[0x40]; float damping; float rate; float length; float period; float periodScale; float dampingScale; float lengthScale; unsigned char dirty; char pad2[3]; Owner* owner;
void FUN_00308b20(); bool update(float dt);
};
bool Target::update(float dt) {
 if(dirty) {
  Properties* p=owner->properties;
  if(p && p->mass>0.0f) {
   double ratio=(double)p->stiffness/p->mass;
   double t=(double)dt/sqrt(ratio+ratio);
   period=(float)(sqrt(ratio)*(1.0-DAT_004d3120*10.0+DAT_004d3120*t)*periodScale*5.0);
   damping=(float)(sqrt((double)p->mass*p->stiffness*2.0)*(DAT_004d311c*t+DAT_004d3118)*dampingScale*0.1f);
  } else { damping=0.0f; period=1000000000.0f; }
  physics::SimCGSValue storage;
  physics::SimLength& temp=static_cast<physics::SimLength&>(storage);
  temp.FUN_002ecf20(0);
  Body* b=owner->body;
  temp.vfunc_1(b ? b->FUN_002ef420() : 100.0f);
  double v=(double)lengthScale/temp.value;
  length=temp.value;
  dirty=0;
  rate=(float)(v*damping*2.0);
  if(owner->body) FUN_00308b20();
  temp.FUN_002ecca0();
 }
 return true;
}