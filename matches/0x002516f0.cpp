#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

extern "C" char DAT_004298fc[];
extern void __cdecl Cleanup(void*, void*);
class SeqActionPlayTrack {
  public:
    int* vptr;
    SeqActionPlayTrack* vfunc_0(int);
};
SeqActionPlayTrack* SeqActionPlayTrack::vfunc_0(int x) {
    SeqActionPlayTrack* self = this;
    vptr = (int*)((hulk_intptr)DAT_004298fc);
    if (x & 1)
        Cleanup((void*)((hulk_intptr)((char*)((char*)&DAT_004e6bc8 + 104))), self);
    return self;
}