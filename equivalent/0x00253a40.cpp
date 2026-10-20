// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventVarPitch::vfunc_2 @ 0x00253a40
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

namespace audio {
struct Sequencer;

struct SeqActionVarPitch_253a40 {
    void** vtable;
    int unknown;
    audio::SeqEventVarPitch* event;
    int value;
};
struct Sequencer { void FUN_0025dc20(SeqActionVarPitch_253a40* action); };
}
extern void* DAT_0042a244;
void* __cdecl FUN_00247530(void*);
void audio::SeqEventVarPitch::vfunc_2(int __p0) { audio::Sequencer * sequencer = (audio::Sequencer *)__p0;

    audio::SeqActionVarPitch_253a40* action = (audio::SeqActionVarPitch_253a40*)FUN_00247530(((char*)((char*)&DAT_004e70e8 + 104)));
    if (action) {
        action->vtable = &DAT_0042a244;
        action->event = this;
        action->value = 0;
    }
    sequencer->FUN_0025dc20(action);
}
