#include "compat/ptr.h"
extern int vtable_32ba30;
class d3dLightMapShader_32ba30 {
  public:
    virtual void V();
    char pad[0x7c];
    int a;
    int b;
    char c;
    char d;
    int e;
    int f;
    void Init(int);
    d3dLightMapShader_32ba30* Target(int);
};
d3dLightMapShader_32ba30* d3dLightMapShader_32ba30::Target(int arg) {
    Init(arg);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    *(hulk_intptr*)this = (hulk_intptr)&vtable_32ba30;
    return this;
}