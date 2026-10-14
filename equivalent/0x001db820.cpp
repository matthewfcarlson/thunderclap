// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_001db820 @ 0x001db820
extern "C" double __cdecl sqrt(double);
struct Quaternion_1db820 { float x, y, z, w; };
struct PackedQuaternion_1db820 {
 short x, y, z;
 Quaternion_1db820* FUN_001db820(Quaternion_1db820* out);
};
Quaternion_1db820* PackedQuaternion_1db820::FUN_001db820(Quaternion_1db820* out) {
 const float scale = 3.0518509447574615478515625e-5f;
 double a = (double)x * scale;
 float b = (float)((double)y * scale);
 double c = (double)z * scale;
 float cf = (float)c;
 double remainder = 1.0f - ((c * cf + (double)b * b) + a * a);
 float w = remainder > 0.0f ? (float)sqrt(remainder) : 0.0f;
 out->x = (float)a;
 out->y = b;
 out->z = cf;
 out->w = w;
 return out;
}
