#include "compat/ptr.h"
extern "C" void* __cdecl Alloc(hulk_uintptr);
class d3dLightMapShader_327ec0 {
  public:
    d3dLightMapShader_327ec0* init(int) throw();
    char pad[0x94];
};
d3dLightMapShader_327ec0* __cdecl FUN_00327ec0(int a) {
    d3dLightMapShader_327ec0* p = (d3dLightMapShader_327ec0*)Alloc(sizeof(d3dLightMapShader_327ec0));
    if (p)
        return p->init(a);
    return 0;
}
