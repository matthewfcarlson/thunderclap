namespace physics {
class PhysicsJoint3D {
public:
 virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6();
 virtual void a7(); virtual void a8();
 virtual void vfunc_9(float, float);
 virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27(); virtual void a28();
 char pad[0x10 - 4];
 float x;
 float y;
 char pad2[0xf8 - 0x18];
 unsigned char flag;
};
void PhysicsJoint3D::vfunc_9(float a, float b) {
 x = a;
 y = b;
 if (b == a && b > 0.0f) {
  flag = 0;
  x = -b;
 } else {
  flag = 1;
  x = -b;
 }
}
}