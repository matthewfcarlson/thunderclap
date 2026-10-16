#include "gen/global.h"

extern "C" char DAT_0040c61c[];
extern void* __cdecl alloc(unsigned int);
class TextLabel_f1e00 {
  public:
    virtual void f0();
    void initialize(int);
    char pad[0x118 - 4];
    volatile int a, b, c, d;
};

void* FEThingsBase::vfunc_56(int arg) {
    TextLabel_f1e00* p = (TextLabel_f1e00*)alloc(0x128);
    if (p) {
        p->initialize(arg);
        p->a = 0;
        *(volatile int*)p = ((int)DAT_0040c61c);
        p->b = 0;
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
