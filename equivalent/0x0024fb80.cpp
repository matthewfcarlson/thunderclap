// STATUS: equivalent (tools/equiv.py level 3: 19941 inputs, branch coverage 2/2)
// audio::SeqEventChannelSends::vfunc_2 @ 0x0024fb80
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

namespace audio {
struct SeqActionChannelSends_24fb80 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad[4];
    void *event;
    int value;
    SeqActionChannelSends_24fb80(void *e) : event(e), value(0) {}
};
}
void * __cdecl FUN_00247530(void *);
struct Channel_24fb80 { void FUN_0025dc20(audio::SeqActionChannelSends_24fb80 *); };
void audio::SeqEventChannelSends::vfunc_2(int __p0) { void * channel = (void *)__p0;

    void *memory = FUN_00247530(((char*)&DAT_004e6800));
    audio::SeqActionChannelSends_24fb80 *action = 0;
    if (memory) {
        action = (audio::SeqActionChannelSends_24fb80 *)memory;
        audio::SeqActionChannelSends_24fb80 source(this);
        const unsigned char *src = (const unsigned char *)&source;
        unsigned char *dst = (unsigned char *)action;
        for (unsigned int i = 0; i < 4; ++i) dst[i] = src[i];
        action->event = this;
        action->value = 0;
    }
    ((Channel_24fb80 *)channel)->FUN_0025dc20(action);
}
