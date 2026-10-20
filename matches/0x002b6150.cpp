#include "compat/ptr.h"
extern "C" char DAT_0042e614[];
class ShadowMeshLoader {
  public:
    int vptr;
    int a, b, c, d;
    ShadowMeshLoader();
};
ShadowMeshLoader::ShadowMeshLoader() {
    a = 0;
    b = 0x1001a;
    c = 0;
    d = 0;
    vptr = ((hulk_intptr)DAT_0042e614);
}