// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// physics::PhysicsObject::vfunc_12 @ 0x002f58e0
extern float DAT_00555454;
struct Motion { char pad[0x50]; float vx,vy,vz,wx,wy,wz; };
namespace physics {
struct PhysicsObject {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual bool vfunc_11(); virtual bool vfunc_12(int);
 char pad04[12]; Motion* motion; char pad14[12]; unsigned char active; char pad21[0x1cc-0x21]; float value; char pad1d0[4]; float linearAverage,linearWeight,angularAverage,angularWeight,linearThreshold,angularThreshold; char pad1ec[4]; unsigned char countdown; char pad1f1[3]; unsigned char flags;
};
bool PhysicsObject::vfunc_12(int) {
 if(active && !vfunc_11() && value < DAT_00555454) {
 Motion* m=motion;
 double angular=(double)m->wx*m->wx+(double)m->wy*m->wy+(double)m->wz*m->wz;
 double linear=((double)m->vx*m->vx+(double)m->vy*m->vy+(double)m->vz*m->vz)*linearWeight+(1.0-(double)linearWeight)*linearAverage;
 linearAverage=(float)linear;
 double filteredAngular=(1.0-(double)angularWeight)*angularAverage+angular*angularWeight;
 angularAverage=(float)filteredAngular;
 if(countdown) --countdown;
 else if((float)linear < linearThreshold && filteredAngular < angularThreshold) flags |= 2;
 }
 return (flags >> 1)&1;
}
}