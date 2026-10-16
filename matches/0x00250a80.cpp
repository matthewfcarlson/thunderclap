#include "gen/audio.h"

struct Temp_250a80 {
    char bytes[12];
    void init();
    void fini();
};
extern void operate(int, Temp_250a80*, int);

void audio::SeqActionExpression::vfunc_1(void* __p0) { int p = (int)__p0;

    Temp_250a80 t;
    t.init();
    operate(*(int*)(p + 0x3c) + 0x5c, &t, this->f_08 + 8);
    this->f_0c = 0;
    t.fini();
}
