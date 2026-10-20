#include "compat/ptr.h"
extern "C" char DAT_00433c24[];
class d3dLayeredLMapShader_32e800 {
  public:
    int pad[39];
    void Init(int);
    d3dLayeredLMapShader_32e800* Target(int);
};
d3dLayeredLMapShader_32e800* d3dLayeredLMapShader_32e800::Target(int arg) {
    Init(arg);
    *(void**)this = (void*)((hulk_intptr)DAT_00433c24);
    *(int*)((char*)this + 0x9c) = 0;
    return this;
}