// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::ImpulseBasedCollisionSolver::vfunc_4 @ 0x002f8730
extern float __cdecl FUN_002f2900(unsigned int, unsigned int);
extern unsigned char DAT_004d2c52;
extern float DAT_004d2c54;
extern "C" double __cdecl sqrt(double);
struct Body_2f8730 { char pad[0x1c]; unsigned int value; };
namespace physics {
struct ImpulseBasedCollisionSolver {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual float vfunc_4();
 char pad04[0x10]; Body_2f8730* first; Body_2f8730* second; char pad1c[0x14]; float threshold; char pad34[0x4c]; float velocity; char pad84[0x64]; float energy; float scale; char padf0[2]; unsigned char flag;
};
float ImpulseBasedCollisionSolver::vfunc_4() {
 float saved = threshold;
 float result = FUN_002f2900(first->value, second->value);
 if (!(result > 1.0f)) result = 1.0f;
 if (!(saved < energy)) { flag=1; return result; }
 union { float f; unsigned int u; } bits;
 bits.f=velocity; bits.u &= 0x7fffffff;
 float limit=(float)sqrt(((double)energy-saved)*scale*2);
 if ((result-1.0f)*bits.f <= limit) {
  bits.f=velocity; bits.u &= 0x7fffffff;
  double factor=(double)DAT_004d2c54/bits.f;
  flag=DAT_004d2c52;
  return (float)(factor*limit+1.0f);
 }
 flag=1; return result;
}
}