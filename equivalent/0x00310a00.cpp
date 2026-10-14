// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// physics::ArticulatedPhysicsObject::vfunc_25 @ 0x00310a00
struct Vec_310a00 { float x,y,z; };
struct Body_310a00 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(Vec_310a00*);
 short unused; short active; char pad[0x78]; Vec_310a00 position;
};
namespace physics {
struct PhysicsObject { bool vfunc_25(Vec_310a00*,Vec_310a00*,int); };
struct ArticulatedPhysicsObject : PhysicsObject { char pad[0x1fc]; Body_310a00** bodies; bool vfunc_25(Vec_310a00*,Vec_310a00*,int); };
}
bool physics::ArticulatedPhysicsObject::vfunc_25(Vec_310a00* out,Vec_310a00* input,int index) {
 if(index<0) return PhysicsObject::vfunc_25(out,input,-1);
 if(bodies[index]->active>0) {
 bodies[index]->s22(input);
 Vec_310a00& p=bodies[index]->position;
 float y=p.x*input->z-p.z*input->x;
 float z=p.y*input->x-p.x*input->y;
 float x=input->y*p.z-input->z*p.y;
 out->x=x; out->y=y; out->z=z;
 } else { out->z=0;out->y=0;out->x=0;input->z=0;input->y=0;input->x=0; }
 return true;
}