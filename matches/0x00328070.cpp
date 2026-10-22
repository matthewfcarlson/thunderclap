#include "compat/ptr.h"
extern "C" void* __cdecl Alloc(hulk_intptr size);

struct d3dSpheremapVertexShader_328070 {
    char data[0x98];
    d3dSpheremapVertexShader_328070* Create(int arg);
};

d3dSpheremapVertexShader_328070* __cdecl Target(int arg) {
    d3dSpheremapVertexShader_328070* p = (d3dSpheremapVertexShader_328070*)Alloc(0x98);
    if (p)
        return p->Create(arg);
    return 0;
}
