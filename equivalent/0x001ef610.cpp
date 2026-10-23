// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSoundCommand_PlaySFXEvent::vfunc_1 @ 0x001ef610
#include "gen/global.h"

#include "decls/data/game/unknown.h"

struct SoundLookup { void* manager; void* events; };
struct EventManager { int FUN_001e98b0(void*); };
struct SoundManager { int FUN_001f31a0(int); void FUN_001f3af0(int, void*, int); };
struct CSoundCommand_1ef610 { virtual void vfunc_0(); virtual void vfunc_1(int, int); };

void CSoundCommand_PlaySFXEvent::vfunc_1(int argument, int unused) {
    int eventId = ((EventManager*)(*(SoundLookup**)&DAT_004e370c)->events)->FUN_001e98b0(&this->f_10);
    int soundId = ((SoundManager*)(*(SoundLookup**)&DAT_004e370c)->manager)->FUN_001f31a0(argument);
    if (eventId && soundId)
        ((SoundManager*)(*(SoundLookup**)&DAT_004e370c)->manager)->FUN_001f3af0(eventId, &this->f_18, soundId);
}
