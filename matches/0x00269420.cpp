#include "gen/core.h"

class Pad_269420 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool IsConnected();
    char data[0x49c];
};

void* core::ControllerSystemXBox::vfunc_4(int param) {
    int count = 0;
    for (unsigned int i = 0; i < 4; i++) {
        if ((*(Pad_269420 (*)[4])&this->f_20)[i].IsConnected()) {
            if (count == param)
                return (void*)(&(*(Pad_269420 (*)[4])&this->f_20)[i]);
            ++count;
        }
    }
    return (void*)(0);
}
