// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// CSoundCommand_PlayDialogueEvent::vfunc_1 @ 0x001ef4f0
#include "decls/data/game/unknown.h"

struct Lookup { int FUN_001e98b0(int *); }; struct Player { void FUN_001f3c00(int, int *, int, int, int, unsigned int); }; struct SoundSystem { Player *player; Lookup *lookup; };  class CSoundCommand_PlayDialogueEvent { public: virtual void vfunc_0(); virtual void vfunc_1(int, int); char pad[12]; int lookupKey; int identifier; int data; unsigned char flag; }; void CSoundCommand_PlayDialogueEvent::vfunc_1(int value, int unused) { int result = (*(SoundSystem**)&DAT_004e370c)->lookup->FUN_001e98b0(&lookupKey); if (result) (*(SoundSystem**)&DAT_004e370c)->player->FUN_001f3c00(result, &data, value, 0, 0, flag); }