// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::CollisionOBB::vfunc_8 @ 0x002fbbb0
namespace physics {
struct CollisionOBB {
 char pad0[0x28];
 float bounds[3];
 char pad34[4];
 int axisAligned;
 char pad3c[12];
 float halfSize[3];
 float axes[3][3];
 void vfunc_8();
};
}
void physics::CollisionOBB::vfunc_8() {
 if (axisAligned) {
  bounds[0]=halfSize[0]; bounds[1]=halfSize[1]; bounds[2]=halfSize[2];
 } else {
  for (int i=0;i<3;++i) {
   union Bits { float f; unsigned int u; } a,b,c;
   a.f=axes[0][i]; a.u &= 0x7fffffff;
   b.f=axes[1][i]; b.u &= 0x7fffffff;
   c.f=axes[2][i]; c.u &= 0x7fffffff;
   bounds[i]=(a.f*halfSize[0]+c.f*halfSize[2])+b.f*halfSize[1];
  }
 }
}
