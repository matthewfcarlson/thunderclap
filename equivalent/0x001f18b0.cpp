// STATUS: equivalent (tools/equiv.py level 3: 18759 inputs, branch coverage 11/12, incomplete)
// FUN_001f18b0 @ 0x001f18b0
// cl-flags: /GS
#include "decls/data/game/unknown.h"
#include "gen/global.h"

struct CSoundCommand_PlayFightDialogueEvent_nv_1f18b0 {
    CSoundCommand_PlayFightDialogueEvent* FUN_001f06c0(const char* name, void* data, unsigned a, unsigned b, unsigned c);
};
struct Manager_1f18b0 {
    void FUN_001ef260(CSoundCommand_PlayFightDialogueEvent* item);
};
extern void* __cdecl FUN_0008d710(unsigned size, unsigned tag);
void __stdcall FUN_001f18b0(const char* name, void* data, unsigned a, unsigned b, unsigned c) {
    if (name && data) {
        Manager_1f18b0* manager = (*(Manager_1f18b0**)&DAT_004e3710);
        if (manager) {
            char buffer[64] = {0};
            unsigned i = 0;
            do { buffer[i] = name[i]; } while (name[i++]);
            CSoundCommand_PlayFightDialogueEvent* item = (CSoundCommand_PlayFightDialogueEvent*)FUN_0008d710(40, 6);
            if (item) item = ((CSoundCommand_PlayFightDialogueEvent_nv_1f18b0*)(item))->FUN_001f06c0(name, data, a, b, c);
            manager->FUN_001ef260(item);
        }
    }
}
