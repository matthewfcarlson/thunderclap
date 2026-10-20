#include "compat/ptr.h"
class Base_31b790 {
  public:
    Base_31b790();
};
extern int device_vftable;
class Device_31b790 {
  public:
    Base_31b790 base;
    Device_31b790();
};
Device_31b790::Device_31b790() {
    *(hulk_intptr*)this = (hulk_intptr)&device_vftable;
}
