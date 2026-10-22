#include "compat/ptr.h"
extern "C" char DAT_00433eec[];
class d3dBuildingShader_332800 {
  public:
    char pad[0x80];
    int a, b, c;
    unsigned char d;
    void BaseCtor(int);
    d3dBuildingShader_332800* Target(int);
};
d3dBuildingShader_332800* d3dBuildingShader_332800::Target(int arg) {
    BaseCtor(arg);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433eec);
    return this;
}