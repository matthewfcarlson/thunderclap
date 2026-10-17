// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventChannelSendVolumesType::vfunc_3 @ 0x0024f540
#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void * __cdecl operator new(size_t, void *p) { return p; }
namespace audio {
struct SeqEventChannelSendVolumes {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    char pad[4];
    unsigned int volumes[16];
    int count;
    void *tag;
    void FUN_0025fd00();
};
struct SeqEventChannelSendVolumesType {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual SeqEventChannelSendVolumes *vfunc_3();
};
}
extern void * __cdecl FUN_00247530(void *);
extern void * __cdecl FUN_002673a0(const char *, int);
audio::SeqEventChannelSendVolumes *audio::SeqEventChannelSendVolumesType::vfunc_3() {
    audio::SeqEventChannelSendVolumes *event = (audio::SeqEventChannelSendVolumes *)FUN_00247530(((char*)((char*)&DAT_004e6748 + 8)));
    if (event) {
        event->FUN_0025fd00();
        event = new(event) audio::SeqEventChannelSendVolumes;
        event->tag = FUN_002673a0("stitched", 0);
        event->count = 100;
        for (int i = 0; i < 16; ++i) event->volumes[i] = 0;
    }
    return event;
}
