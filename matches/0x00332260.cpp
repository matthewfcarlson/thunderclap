#include "compat/ptr.h"
class Ref_332260 {
  public:
    virtual void f();
    virtual void Release();
};
extern int vtable_332260;
class d3dBuildingShader_332260 {
  public:
    virtual void v();
    char pad[0x7c];
    Ref_332260* a;
    Ref_332260* b;
    Ref_332260* c;
    void init();
    void cleanup();
};
void d3dBuildingShader_332260::init() {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_332260;
    if (a)
        a->Release();
    if (b)
        b->Release();
    if (c)
        c->Release();
    cleanup();
}