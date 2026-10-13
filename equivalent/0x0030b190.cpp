// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 15/16, incomplete)
// physics::PhysicsJoint1D::vfunc_25 @ 0x0030b190
extern float DAT_004d3198;
extern unsigned char DAT_004d319c;
extern float DAT_004d31a0;
extern float DAT_004d31d8;
namespace physics {
struct PhysicsJoint1D {
 char pad0[0x10];
 float lowerLimit;
 float upperLimit;
 char pad18[0xf4];
 float velocity;
 char pad110[4];
 float correction;
 char pad118[4];
 float position;
 void vfunc_25();
};
}
void physics::PhysicsJoint1D::vfunc_25() {
 union { float f; unsigned int u; } absolute;
 absolute.f = velocity;
 absolute.u &= 0x7fffffff;
 if (absolute.f > DAT_004d3198) {
 float sign = 0.0f;
 if (velocity < 0.0f) sign = -1.0f;
 else if (velocity > 0.0f) sign = 1.0f;
 velocity = sign * DAT_004d3198;
 }
 if (DAT_004d319c) {
 if (position > upperLimit) {
 double delta = (double)position - upperLimit;
 position = upperLimit;
 correction = (float)((double)correction - delta * DAT_004d31a0);
 if (velocity > 0.0f) velocity = DAT_004d31d8 * velocity;
 } else if (position < lowerLimit) {
 double delta = (double)position - lowerLimit;
 position = lowerLimit;
 correction = (float)((double)correction - delta * DAT_004d31a0);
 if (velocity < 0.0f) velocity = DAT_004d31d8 * velocity;
 }
 }
}