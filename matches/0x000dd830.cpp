#include "gen/global.h"

struct Block_dd830 {
    unsigned long x[10];
};
struct Other_dd830 {
    virtual void f0();
    virtual void f1(void*, void*);
};

void ControllerState::vfunc_2() {
    *reinterpret_cast<Block_dd830*>((*(unsigned long * *)&this->f_10)) = *reinterpret_cast<Block_dd830*>((*(unsigned long * *)&this->f_0c));
    (*(Other_dd830 * *)&this->f_08)->f1((*(void * *)&this->f_04), (*(unsigned long * *)&this->f_0c));
}
