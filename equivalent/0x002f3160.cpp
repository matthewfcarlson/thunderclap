// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::CollisionCylinder::vfunc_8 @ 0x002f3160
namespace physics {
struct CollisionCylinder {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
 char pad04[0x24]; float extent[3]; char pad34[0x10]; float axis[3]; float halfLength; float radius; unsigned char curved;
};
void CollisionCylinder::vfunc_8() {
 for (int i=0;i<3;++i) {
 union { float f; unsigned int u; } a;
 a.f=axis[i]; a.u &= 0x7fffffff;
 if(curved) {
 double square=(double)a.f*a.f;
 extent[i]=(float)(((1.0-0.5*square)+square*square*0.125)*radius+(double)a.f*halfLength);
 } else extent[i]=(float)((double)a.f*halfLength+radius);
 }
}
}
