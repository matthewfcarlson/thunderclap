// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// audio::SeqActionClip::vfunc_1 @ 0x00256370
#include "gen/audio.h"
struct Source_256370 {
    char pad0[0x1c];
    float* level;           // 0x1c
    float x20;              // 0x20
    float x24;              // 0x24
};

struct Scale_256370 {
    char pad0[0x14];
    float k;                // 0x14
};

struct Event_256370 {
    int f00;
    Source_256370* source;         // 0x04
    char pad08[0x3c - 8];
    Scale_256370* scale;           // 0x3c
};

struct Target_256370 {
    char pad0[8];
    unsigned char b8;       // 0x08
};

struct Voice;

void __cdecl FUN_00258c80(Voice* v, float gain);
void __cdecl FUN_00258b40(Voice* v, int flag);
void __cdecl FUN_00259be0(Voice* v);



namespace audio {
class SeqActionClip_256370 : public ::audio::SeqAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(Event_256370* e);
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[4];
    Target_256370* target;         // 0x08
    char pad0c[4];
    void* clip;             // 0x10
    Voice* voice;           // 0x14
    int state;              // 0x18
    void FUN_00256150(Event_256370* e);
    void FUN_00255e60(Event_256370* e);
};
}

void audio::SeqActionClip_256370::vfunc_1(Event_256370* e)
{
    if (clip == 0 || voice == 0) {
        state = 5;
        return;
    }
    FUN_00256150(e);
    FUN_00258c80(voice, ((*e->source->level * e->scale->k) * e->source->x20) * e->source->x24);
    FUN_00255e60(e);
    FUN_00258b40(voice, target->b8);
    FUN_00259be0(voice);
    state = 3;
}
