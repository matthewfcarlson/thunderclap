#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" char DAT_0043386c[];
class d3dShader_32a9f0 {
  public:
    hulk_intptr v;
    char pad[0x7c];
    int a;
    char b;
    int c;
    char d;
    int e;
};
struct d3dSimpleShader_nv_32a9f0 {
    void BaseInit(int);
};
class d3dSimpleShader_32a9f0 : public d3dShader_32a9f0 {
  public:
    d3dSimpleShader_32a9f0* Init(int);
};
d3dSimpleShader_32a9f0* d3dSimpleShader_32a9f0::Init(int x) {
    ((d3dSimpleShader_nv_32a9f0*)(((pure3d::d3dSimpleShader*)(this))))->BaseInit(x);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    v = ((hulk_intptr)DAT_0043386c);
    return this;
}