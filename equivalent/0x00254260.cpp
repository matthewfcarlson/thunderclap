// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// audio::SeqActionStream::vfunc_1 @ 0x00254260
#include "gen/audio.h"

struct Voice_254260 {
    char pad0[0x10];
    float volume;           // 0x10
    float pitch;            // 0x14
};

struct Config_254260 {
    char pad0[0x14];
    float gain;             // 0x14
    float *volumeScale;     // 0x18
    float *pitchScale;      // 0x1c
    float pitchB;           // 0x20
    float pitchA;           // 0x24
};

struct Event_254260 {
    float scale;            // 0x0
    Config_254260 *config;         // 0x4
    char pad8[0x34 - 8];
    int handle;             // 0x34
    char pad38[4];
    Voice_254260 *voice;           // 0x3c
};

int __cdecl FUN_0024afe0(int handle);
void __cdecl FUN_0024b040(int handle, float volume);
void __cdecl FUN_0024b080(int handle, float pitch);
void __cdecl FUN_0024c120(int handle);

namespace audio {
class SeqAction_254260 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(Event_254260 *e);
    char pad4[0x1c];
    int state;              // 0x20

    void FUN_00253f70(Event_254260 *e);
};

struct SeqActionStream_nv_254260 {
    void FUN_00253f70(Event_254260 *e);
};

}
void audio::SeqActionStream::vfunc_1(void* __p0) { Event_254260 * e = (Event_254260 *)__p0;

    if (e->handle == 0) {
        this->f_20 = 0;
        return;
    }
    int status = FUN_0024afe0(e->handle);
    if (status == 4 || status == 3) {
        Voice_254260 *v = e->voice;
        Config_254260 *c = e->config;
        FUN_0024b040(e->handle, (((v->volume * e->scale) * *c->volumeScale) * c->gain));
        c = e->config;
        FUN_0024b080(e->handle, (((*c->pitchScale * e->voice->pitch) * c->pitchA) * c->pitchB));
        ((SeqActionStream_nv_254260*)this)->FUN_00253f70(e);
        FUN_0024c120(e->handle);
    }
    this->f_20 = 3;
}
