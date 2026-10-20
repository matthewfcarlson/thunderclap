// STATUS: equivalent (tools/equiv.py level 3: 19942 inputs, branch coverage 2/2)
// audio::SeqEventCrossFade::vfunc_2 @ 0x00255930
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
void* __cdecl FUN_00247530(void*);
namespace audio {

struct SeqActionCrossFade_255930 {
    virtual void vfunc_0();
    char pad[4];
    audio::SeqEventCrossFade* event;
    int valueC, value10, value14, value18;
    SeqActionCrossFade_255930() : event(0), valueC(0), value10(0), value14(0), value18(0) {}
};
struct SeqContext { void FUN_0025dc20(SeqActionCrossFade_255930*); };

}
void audio::SeqEventCrossFade::vfunc_2(int __p0) { SeqContext * context = (SeqContext *)__p0;

    SeqActionCrossFade_255930* action = (SeqActionCrossFade_255930*)FUN_00247530(((char*)&DAT_004e74c0));
    if (action) {
        action->value10 = 0;
        action->value14 = 0;
        action->value18 = 0;
        action->valueC = 0;
        action->SeqActionCrossFade_255930::SeqActionCrossFade_255930();
        action->event = this;
    }
    context->FUN_0025dc20(action);
}
