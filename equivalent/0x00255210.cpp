// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventLogicOr::vfunc_2 @ 0x00255210
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t;
inline void* __cdecl operator new(size_t, void* ptr) { return ptr; }
void* __cdecl FUN_00247530(void*);

struct SeqCommandLogicOr_255210 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    char reserved[4];
    audio::SeqEventLogicOr* event;
};
struct Context_255210 { void FUN_0025dba0(SeqCommandLogicOr_255210*); };

void audio::SeqEventLogicOr::vfunc_2(int __p0) { Context_255210 * context = (Context_255210 *)__p0;

    SeqCommandLogicOr_255210* command = (SeqCommandLogicOr_255210*)FUN_00247530(((char*)&DAT_004e7410));
    if (command) {
        new(command) SeqCommandLogicOr_255210;
        command->event = this;
    }
    context->FUN_0025dba0(command);
}
