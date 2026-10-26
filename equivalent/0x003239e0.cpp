// STATUS: equivalent (tools/equiv.py level 3: 3065 inputs, branch coverage 28/28; --wine 665 inputs)
// pure3d::d3dExtFramebufferEffects::vfunc_4 @ 0x003239e0
#include "decls/data/platform/xbox/pure3d.h"

namespace pure3d {
struct d3dExtFramebufferEffects {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(float a,float b,float c,float d,int color);
char pad[0x64]; float scale, amount, curve, bias, result; char pad2[4]; float red,green,blue;
};
void d3dExtFramebufferEffects::vfunc_4(float a,float b,float c,float d,int color) {
red = int((color>>16)&255)*0.00392156862745098f;
green = int((color>>8)&255)*0.00392156862745098f;
blue = int(color&255)*0.00392156862745098f;
if (!(a >= -100.0f && a <= 100.0f)) { if (a > 100.0f) a = 100.0f; else a = -100.0f; }
float initial = a * 0.01f + 1.0f; scale = initial;
if (!(c >= -100.0f && c <= 100.0f)) { if (c > 100.0f) c = 100.0f; else c = -100.0f; }
curve = c;
if (!(d >= 0.0f && d <= 1.0f)) d = d > 1.0f ? 1.0f : 0.0f;
bias = d;
if (!(b >= -100.0f && b <= 100.0f)) { if (b > 100.0f) b = 100.0f; else b = -100.0f; }
amount = b * 0.00392156862745098f;
if (c < 0.0f) {
 curve = c * 0.01f + 1.0f;
 scale = (c * 0.01f + 1.0f) * initial;
} else {
 int index = (int)(c + 0.5f);
 curve = ((float*)&DAT_00432a10)[index];
}
result = (curve < 1.0f ? curve : 1.0f) * scale;
}
}