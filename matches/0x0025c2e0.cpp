#include "gen/audio.h"

struct AudioDevice {
    void** vt;
};

void audio::OmHalStream::vfunc_5(int param_2) {
    void* local;
    void** vt = (*(AudioDevice * *)&this->f_04)->vt;
    ((void (*)(void**, void**))vt[4])(vt, &local);
    vt = (*(AudioDevice * *)&this->f_04)->vt;
    ((void (*)(void**, void*))vt[5])(vt, (char*)local + param_2);
}
