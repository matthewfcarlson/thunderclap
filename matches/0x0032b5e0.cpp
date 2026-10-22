#include "compat/ptr.h"
extern "C" char DAT_0043397c[];
struct Ref_32b5e0 {
    virtual void f0();
    virtual void f1();
};
struct d3dShader_32b5e0 {
    void cleanup();
};
struct d3dLightMapShader_32b5e0 : d3dShader_32b5e0 {
    char pad[0x80];
    Ref_32b5e0* a;
    Ref_32b5e0* b;
    void run();
};
void d3dLightMapShader_32b5e0::run() {
    *(void**)this = (void*)((hulk_intptr)DAT_0043397c);
    if (a)
        a->f1();
    if (b)
        b->f1();
    cleanup();
}