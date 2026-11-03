#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" void* __cdecl Alloc(hulk_uintptr);
class d3dLightMapShader_327ec0 {
  public:
    char pad[0x94];
};
d3dLightMapShader_327ec0* __cdecl FUN_00327ec0(int a) {
    d3dLightMapShader_327ec0* p = (d3dLightMapShader_327ec0*)Alloc(sizeof(d3dLightMapShader_327ec0));
    if (p)
        return ((d3dLightMapShader_327ec0 *)((pure3d::d3dLightMapShader *)p)->FUN_0032ba30(a));
    return 0;
}
