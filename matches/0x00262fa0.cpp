#include "gen/audio.h"
#include "decls/data/engine/audio.h"


void* audio::HalRsdFileStream::vfunc_9(int index) {
    if (!(*(char * *)&this->f_24))
        return (void*)((char*)((int)((char*)&DAT_0042ae14)));
    return (void*)((*(char * *)&this->f_24) + index * 16 + 0xa4);
}
