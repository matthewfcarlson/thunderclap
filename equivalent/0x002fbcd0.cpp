// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_002fbcd0 @ 0x002fbcd0
struct Vec_2fbcd0 { float x,y,z; };
struct Shape_2fbcd0 {
 char pad0[0x38]; int axisAligned; char pad1[0xc];
 float extentX,extentY,extentZ;
 Vec_2fbcd0 axisX,axisY,axisZ;
 float projection(const Vec_2fbcd0* v);
};
float Shape_2fbcd0::projection(const Vec_2fbcd0* v) {
 union Bits { float f; unsigned int u; } x,y,z;
 if (!axisAligned) {
  x.f = (axisX.z*v->z + axisX.y*v->y) + axisX.x*v->x;
  y.f = (axisY.z*v->z + axisY.y*v->y) + v->x*axisY.x;
  z.f = (axisZ.z*v->z + axisZ.y*v->y) + axisZ.x*v->x;
 } else {
  x.f=v->x; y.f=v->y; z.f=v->z;
 }
 x.u &= 0x7fffffff; y.u &= 0x7fffffff; z.u &= 0x7fffffff;
 return (z.f*extentZ + y.f*extentY) + x.f*extentX;
}
