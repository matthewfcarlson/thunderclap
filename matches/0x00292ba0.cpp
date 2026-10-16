#include "gen/pure3d.h"

struct Block_292ba0 {
    int x[16];
};
class Receiver_292ba0 {
  public:
    void call();
};

void pure3d::Camera::vfunc_26() {
    Block_292ba0* dst = (Block_292ba0*)((char*)this + 0x4c);
    this->f_cc = 1;
    *dst = *(Block_292ba0*)((char*)this + 0x8c);
    ((Receiver_292ba0*)dst)->call();
}
