#include "compat/ptr.h"
extern "C" char DAT_00431394[];
class PhysicsPropertiesLoader {
  public:
    hulk_intptr vptr;
    int a;
    int b;
    int c;
    int d;
    PhysicsPropertiesLoader();
};
PhysicsPropertiesLoader::PhysicsPropertiesLoader() {
    a = 0;
    b = 0x07011010;
    c = 0;
    d = 0;
    vptr = ((hulk_intptr)DAT_00431394);
}