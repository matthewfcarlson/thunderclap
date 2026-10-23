#include "gen/audio.h"

#include "compat/ptr.h"
typedef unsigned int uint_262cc0;
int FUN_0024c310(hulk_intptr);
int FUN_0024c2f0(void*);
struct Base_262cc0 {
    virtual void f0();
    virtual void f1();
    virtual int f2();
};

int audio::HalRadicalAdpcmDecodeStream::vfunc_3() {
    uint_262cc0 a = (*(Base_262cc0 * *)&this->f_04)->f2();
    uint_262cc0 b = FUN_0024c310(a);
    void* p = (char*)this + 8;
    uint_262cc0 c = FUN_0024c2f0(p);
    uint_262cc0 d = FUN_0024c310((hulk_intptr)p);
    return (int)(c * b / d);
}
