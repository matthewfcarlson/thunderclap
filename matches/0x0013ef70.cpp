#include "compat/ptr.h"
extern "C" char DAT_00412ad0[];
struct Base {
    virtual void f();
    ~Base();
};
struct Sub_13ef70 {
    unsigned char x[8];
    void Dtor();
};
struct WallRunTrack : Base {
    unsigned char pad[0x34];
    Sub_13ef70 a;
    Sub_13ef70 b;
    Sub_13ef70 c;
    void Kill();
};
void WallRunTrack::Kill() {
    *(void**)this = (void*)((hulk_intptr)DAT_00412ad0);
    c.Dtor();
    b.Dtor();
    a.Dtor();
    this->Base::~Base();
}
