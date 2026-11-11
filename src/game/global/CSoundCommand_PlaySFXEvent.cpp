// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001ef610..0x001ef660 (kind game, layer game, confidence medium), dominant class CSoundCommand_PlaySFXEvent
#include "tree_prelude.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f906042a {
#define TREE_TU_END }
namespace fn_f906042a {} using namespace fn_f906042a;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f906042a {
struct SoundLookup { void* manager; void* events; };
struct EventManager { int FUN_001e98b0(void*); };
struct SoundManager { int FUN_001f31a0(int); void FUN_001f3af0(int, void*, int); };
struct CSoundCommand_1ef610 { virtual void vfunc_0(); virtual void vfunc_1(int, int); };

} // namespace fn_f906042a

// 0x001ef610 CSoundCommand_PlaySFXEvent::vfunc_1 (71 B): equivalent/0x001ef610.cpp
// sym: ?vfunc_1@CSoundCommand_PlaySFXEvent@@UAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// CSoundCommand_PlaySFXEvent::vfunc_1 @ 0x001ef610
void CSoundCommand_PlaySFXEvent::vfunc_1(int argument, int unused) {
    int eventId = ((EventManager*)(*(SoundLookup**)&DAT_004e370c)->events)->FUN_001e98b0(&this->f_10);
    int soundId = ((SoundManager*)(*(SoundLookup**)&DAT_004e370c)->manager)->FUN_001f31a0(argument);
    if (eventId && soundId)
        ((SoundManager*)(*(SoundLookup**)&DAT_004e370c)->manager)->FUN_001f3af0(eventId, &this->f_18, soundId);
}

