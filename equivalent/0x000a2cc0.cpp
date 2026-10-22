// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000a2cc0 @ 0x000a2cc0
struct Vec3_a2cc0 { float x,y,z; };
void __cdecl FUN_000a04c0(Vec3_a2cc0*, float*, float*, float*);
float __cdecl FUN_000a02a0(float);
struct CChaseCamera_a2cc0 {
 char pad0[0x170]; Vec3_a2cc0 position; char pad1[0x1c4-0x17c]; Vec3_a2cc0 previous; char pad2[0x320-0x1d0];
 int state, savedState, nextState; char pad3[0x394-0x32c];
 float speed, targetSpeed, angle, targetAngle, elevation, targetElevation, distance, targetDistance;
 void update(float a, float b, float c, float speedValue, int next);
};
void CChaseCamera_a2cc0::update(float a,float b,float c,float speedValue,int next) {
 savedState = state == 7 ? nextState : state;
 state = 7;
 speed = 0.0f;
 Vec3_a2cc0 delta;
 delta.x = position.x - previous.x;
 delta.y = position.y - previous.y;
 delta.z = position.z - previous.z;
 FUN_000a04c0(&delta, &angle, &elevation, &distance);
 float normalized = FUN_000a02a0(a);
 targetAngle = normalized;
 float difference = normalized - angle;
 targetElevation = b;
 targetDistance = c;
 float magnitude = FUN_000a02a0(difference);
 union { float f; unsigned int u; } bits;
 bits.f = magnitude;
 bits.u &= 0x7fffffff;
 magnitude = bits.f;
 if (magnitude < 90.0f) targetSpeed = speedValue;
 else targetSpeed = magnitude * speedValue * 0.011111111f;
 speed = targetSpeed;
 nextState = next;
}
