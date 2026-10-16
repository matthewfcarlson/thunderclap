#include "gen/audio.h"

extern "C" char DAT_0042ae14[];

void* audio::HalRsdFileStream::vfunc_9(int index) {
    if (!(*(char * *)&this->f_24))
        return (void*)((char*)((int)DAT_0042ae14));
    return (void*)((*(char * *)&this->f_24) + index * 16 + 0xa4);
}
