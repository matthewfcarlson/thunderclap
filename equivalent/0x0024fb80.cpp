// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventChannelSends::vfunc_2 @ 0x0024fb80
#include "decls/data/engine/audio.h"

namespace audio {
struct SeqActionChannelSends {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char pad[4];
    void *event;
    int value;
    SeqActionChannelSends(void *e) : event(e), value(0) {}
};
struct SeqEventChannelSends {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *channel);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
}
void * __cdecl FUN_00247530(void *);
struct Channel { void FUN_0025dc20(audio::SeqActionChannelSends *); };
void audio::SeqEventChannelSends::vfunc_2(void *channel) {
    void *memory = FUN_00247530(((char*)&DAT_004e6800));
    audio::SeqActionChannelSends *action = 0;
    if (memory) {
        action = (audio::SeqActionChannelSends *)memory;
        audio::SeqActionChannelSends source(this);
        const unsigned char *src = (const unsigned char *)&source;
        unsigned char *dst = (unsigned char *)action;
        for (unsigned int i = 0; i < 4; ++i) dst[i] = src[i];
        action->event = this;
        action->value = 0;
    }
    ((Channel *)channel)->FUN_0025dc20(action);
}
