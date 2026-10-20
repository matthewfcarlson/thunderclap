// STATUS: equivalent (tools/equiv.py level 3: 19867 inputs, branch coverage 2/2)
// audio::HalRsdFileStream::vfunc_0 @ 0x002632c0
// audio::HalRsdFileStream::vfunc_0 @ 0x002632c0
#include "gen/audio.h"

namespace audio {
struct StreamHelper {};
}
void* __fastcall FUN_0023fb00(audio::StreamHelper*);
void __cdecl thunk_FUN_002710d0(void**, void*, int, int, int, int, int, int);
void audio::HalRsdFileStream::vfunc_0() {
    if ((*(void * *)&this->f_20) == 0) {
        int saved = this->f_1c;
        audio::StreamHelper* helper = (audio::StreamHelper*)((char*)this + 4);
        void* result = FUN_0023fb00(helper);
        thunk_FUN_002710d0(&(*(void * *)&this->f_20), result, 0, 0, saved, 0, 1, 1);
    }
    (*(int *)&this->f_44) = 1;
}
