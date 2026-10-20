#include "gen/pure3d.h"
struct d3dBumpMapVertexShader_nv_333130 {
    void Init(int);
};
struct d3dBumpMapVertexShader_333130 {
    unsigned int* vptr;
    char pad[0x7c];
    unsigned int a, b, c;
    d3dBumpMapVertexShader_333130* Make(int);
};
extern const float zeroF;
extern unsigned int vtblBump;
void __stdcall CreatePixelShader(const float* src, unsigned int* out);

d3dBumpMapVertexShader_333130* d3dBumpMapVertexShader_333130::Make(int n) {
    ((d3dBumpMapVertexShader_nv_333130*)(((pure3d::d3dBumpMapVertexShader*)this)))->Init(n);
    vptr = (unsigned int*)&vtblBump;
    a = 0;
    b = 0;
    c = 0;
    CreatePixelShader(&zeroF, (unsigned int*)((char*)this + 0x8c));
    return this;
}
