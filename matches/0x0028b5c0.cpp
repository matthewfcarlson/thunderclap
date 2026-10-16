#include "gen/pure3d.h"

class Ref_28b5c0 {
  public:
    virtual void f0();
    virtual void Release();
};
extern void __cdecl thunk(void*);

void pure3d::Vector1DOFChannel::vfunc_1() {
    if ((*(volatile int *)&this->f_0c) == 0)
        thunk((*(void * *)&this->f_28));
    (*(void * *)&this->f_28) = 0;
    if ((*(volatile int *)&this->f_0c) == 0) {
        thunk((*(void * *)&this->f_14));
        (*(void * *)&this->f_14) = 0;
        return;
    }
    Ref_28b5c0* p = (Ref_28b5c0*)(*(volatile int *)&this->f_0c);
    if (p != 0) {
        p->Release();
        (*(volatile int *)&this->f_0c) = 0;
    }
    (*(void * *)&this->f_14) = 0;
}
