// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0028dbb0 @ 0x0028dbb0
struct Quaternion { float x,y,z,w; };
extern "C" double __cdecl sqrt(double);
struct PackedQuaternion {
 signed char x,y,z;
 Quaternion* unpack(Quaternion* output);
};
Quaternion* PackedQuaternion::unpack(Quaternion* output) {
 float fx = x * 0.0078740157186985016f;
 float fy = y * 0.0078740157186985016f;
 float fz = z * 0.0078740157186985016f;
 float remainder = 1.0f - (fz*fz + fy*fy + fx*fx);
 float w = remainder > 0.0f ? (float)sqrt(remainder) : 0.0f;
 output->x=fx; output->y=fy; output->z=fz; output->w=w;
 return output;
}