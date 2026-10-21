// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 2/2)
// FUN_0028dbb0 @ 0x0028dbb0
#include "compat/ptr.h"
struct Quaternion_28dbb0 { float x,y,z,w; };
extern "C" double __cdecl sqrt(double);
struct PackedQuaternion_28dbb0 {
 signed char x,y,z;
 Quaternion_28dbb0* unpack(Quaternion_28dbb0* output);
};
Quaternion_28dbb0* PackedQuaternion_28dbb0::unpack(Quaternion_28dbb0* output) {
 // x87: fx and the sum stay in registers (53 bits), fy goes through the frame; z is squared as its register value
 // times its rounded frame copy (fst, then fmul by the copy)
 double fx = x * 0.0078740157186985016f;
 float fy = y * 0.0078740157186985016f;
 hulk_freg fzu = z * 0.0078740157186985016f;
 float fz = (float)fzu;
 double remainder = 1.0f - (fzu*fz + fy*fy + fx*fx);
 float w = remainder > 0.0f ? (float)sqrt(remainder) : 0.0f;
 output->x=fx; output->y=fy; output->z=fz; output->w=w;
 return output;
}