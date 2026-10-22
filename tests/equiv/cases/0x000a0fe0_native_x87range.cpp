// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 2/2)
// FUN_000a0fe0 @ 0x000a0fe0
#include "compat/ptr.h"
extern "C" double __cdecl tan(double);
extern "C" double __cdecl atan(double);
extern "C" double __cdecl sqrt(double);
struct CChaseCamera_a0fe0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual float v8();
 char pad0[0xd8-4]; float horizontal; float vertical; char pad1[0x450-0xe0];
 float value; char pad2[8]; float x; float y; float z; float radius; float angleX; float angleY; float angleZ;
 void FUN_000a9090(float);
 void update(float);
};
void CChaseCamera_a0fe0::update(float v) {
 if (v == value) return;
 value=v;
 FUN_000a9090(v);
 volatile float tx=(float)tan(horizontal * 0.008726646192371845f);
 angleX=(float)(atan(0.5f * tx)*114.591552734375f);
 angleZ=(float)(atan(0.24f * tx)*114.591552734375f);
 volatile float ty=(float)tan(vertical * 0.008726646192371845f);
 angleY=(float)(atan(0.45f * ty)*114.591552734375f);
 float distance=v8();
 x=tx*distance; y=ty*distance; z=distance;
 // the original reloads the stored (rounded) x, y, z for the radius: volatile reads keep MSVC from reusing its registers
 float rz=*(volatile float*)&z, ry=*(volatile float*)&y, rx=*(volatile float*)&x;
 radius=(float)(sqrt((hulk_freg)rx*rx+(hulk_freg)ry*ry+(hulk_freg)rz*rz)+0.1f);
}