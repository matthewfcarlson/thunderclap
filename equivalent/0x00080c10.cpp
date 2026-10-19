// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// FUN_00080c10 @ 0x00080c10
// FUN_00080c10 @ 0x00080c10
struct Vec3 { float x,y,z; void FUN_0022c3b0(Vec3 *direction, Vec3 *result); }; struct Object { char pad[0x34]; Vec3 transform; Vec3 * FUN_00080c10(Vec3 *out); }; Vec3 * Object::FUN_00080c10(Vec3 *out) { Vec3 direction = {0.0f,0.0f,-1.0f}; Vec3 result; transform.FUN_0022c3b0(&direction,&result); *out = result;     return out;
}
