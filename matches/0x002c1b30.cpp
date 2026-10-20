#include "compat/ptr.h"
extern "C" char DAT_0042ebe8[];
class CameraLoader {
  public:
    void* vf;
    int a;
    int b;
    int c;
    int d;
    CameraLoader();
};
CameraLoader::CameraLoader() {
    a = 0;
    b = 0x2200;
    c = 0;
    d = 0;
    vf = (void*)((hulk_intptr)DAT_0042ebe8);
}