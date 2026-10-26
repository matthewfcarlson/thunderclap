// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventChannelSendVolumes::vfunc_2 @ 0x0024f230
#include "compat/ptr.h"
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
__forceinline void* operator new(size_t, void* place) { return place; }
void* __cdecl FUN_00247530(void*);
struct SeqActionChannelSendVolumes_24f230 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    void* unknown;
    void* event;
    int zero;
};
struct Channel_24f230 {
    void FUN_0025dc20(SeqActionChannelSendVolumes_24f230*);
};
namespace audio {

}
void audio::SeqEventChannelSendVolumes::vfunc_2(hulk_intptr __p0) { Channel_24f230 * channel = (Channel_24f230 *)__p0;

    void* memory = FUN_00247530(((char*)&DAT_004e6700));
    SeqActionChannelSendVolumes_24f230* action = memory ? new (memory) SeqActionChannelSendVolumes_24f230 : 0;
    if (action) {
        action->event = this;
        action->zero = 0;
    }
    channel->FUN_0025dc20(action);
}
