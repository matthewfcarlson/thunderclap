#include "compat/ptr.h"
#include "gen/audio.h"

struct Temp_250a80 {
    char bytes[12];
    void init();
    void fini();
};
extern "C" void FUN_002613b0(int, Temp_250a80*, int);

void audio::SeqActionExpression::vfunc_1(void* __p0) { hulk_intptr p = (hulk_intptr)__p0;

    Temp_250a80 t;
    t.init();
    FUN_002613b0(*(int*)(p + 0x3c) + 0x5c, &t, this->f_08 + 8);
    this->f_0c = 0;
    t.fini();
}
