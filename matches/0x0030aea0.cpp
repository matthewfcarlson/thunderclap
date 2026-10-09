namespace physics {
class PhysicsJoint {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8();
};
class PhysicsJoint1D : public PhysicsJoint {
public:
 virtual void vfunc_9(float, float);
 virtual void f10(); virtual void f11(); virtual void f12();
 virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22(); virtual void f23(); virtual void f24(); virtual void f25(); virtual void f26(); virtual void f27(); virtual void f28();
 char pad[0x10- sizeof(PhysicsJoint)];
 float a; float b;
 char pad2[0xf8-0x18];
 unsigned char flag;
};
void PhysicsJoint1D::vfunc_9(float x, float y) {
 a=x; b=y;
 if (y == x && y > 0.0f) { flag=0; a=-y; return; }
 flag=1;
}
}