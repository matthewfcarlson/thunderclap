// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// physics::PhysicsJoint1D::vfunc_26 @ 0x0030c300
struct Vec3 { float x,y,z; };
extern float DAT_003f32e0;
extern float DAT_004d31bc;
extern "C" double __cdecl sqrt(double);
namespace physics {
struct PhysicsJoint1D {
 char pad0[0x80]; Vec3 axis;
 char pad1[0xe4-0x8c]; float strength;
 char pad2[0xfc-0xe8]; Vec3 direction;
 float FUN_0030b2c0(float value);
 bool vfunc_26(const Vec3* input, Vec3* output);
};
}
bool physics::PhysicsJoint1D::vfunc_26(const Vec3* input, Vec3* output) {
 float x = direction.y * axis.z - direction.z * axis.y;
 float y = direction.z * axis.x - direction.x * axis.z;
 float z = direction.x * axis.y - direction.y * axis.x;
 float amount = (float)(-(sqrt(z*z+y*y+x*x) * (z*input->z+y*input->y+x*input->x) * strength * DAT_004d31bc));
 union { float f; unsigned int u; } absolute;
 absolute.f = amount; absolute.u &= 0x7fffffff;
 if (!(absolute.f > DAT_003f32e0)) return false;
 float scale = FUN_0030b2c0(amount) * amount;
 output->x = scale * direction.x;
 output->y = scale * direction.y;
 output->z = scale * direction.z;
 return true;
}