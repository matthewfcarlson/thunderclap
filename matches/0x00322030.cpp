#include "gen/pure3d.h"

class D3DDeviceState {
  public:
    char pad[0x44c];
    unsigned char value;
};

void pure3d::d3dExtAntialiasControl::vfunc_2(unsigned char value) {
    (*(D3DDeviceState * *)&this->f_04)->value = value;
}
