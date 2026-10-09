extern "C" double __cdecl sqrt(double);
class PhysicsJoint3D { public: char pad[0x138]; float x; float y; float z; float vfunc_6(); };
float PhysicsJoint3D::vfunc_6() { return (float)sqrt((double)(z*z + y*y + x*x)); }