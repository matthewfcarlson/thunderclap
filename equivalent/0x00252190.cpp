// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventChannelVolumes::vfunc_2 @ 0x00252190
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

struct AllocationPool { char byte; };
void* __cdecl FUN_00247530(AllocationPool*);
namespace audio {

struct SeqActionChannelVolumes_252190 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char padding[4];
    audio::SeqEventChannelVolumes* source;
    int state;
};
}
struct Context_252190 { void FUN_0025dc20(audio::SeqActionChannelVolumes_252190*); };
void audio::SeqEventChannelVolumes::vfunc_2(int __p0) { void * context = (void *)__p0;

    void* memory = FUN_00247530(((AllocationPool*)&DAT_004e6ce0));
    audio::SeqActionChannelVolumes_252190* action = (audio::SeqActionChannelVolumes_252190*)memory;
    if (action) {
        action->audio::SeqActionChannelVolumes_252190::SeqActionChannelVolumes_252190();
        action->source = this;
        action->state = 0;
    }
    ((Context_252190*)context)->FUN_0025dc20(action);
}
