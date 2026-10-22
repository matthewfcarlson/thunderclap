#include "compat/ptr.h"
class d3dDevice_31b790 {
  public:
    d3dDevice_31b790();
};
extern int device_vftable;
class pddiDevice_31b790 {
  public:
    d3dDevice_31b790 base;
    pddiDevice_31b790();
};
pddiDevice_31b790::pddiDevice_31b790() {
    *(hulk_intptr*)this = (hulk_intptr)&device_vftable;
}
