// STATUS: equivalent (tools/equiv.py level 3: 18759 inputs, branch coverage 11/12, incomplete)
// FUN_001f17f0 @ 0x001f17f0
// cl-flags: /GS
#include "decls/data/game/unknown.h"
#include "gen/global.h"

struct CSoundCommand_PlayMissionDialogueEvent_nv_1f17f0 {
    CSoundCommand_PlayMissionDialogueEvent* FUN_001f0760(const char*, void*, unsigned, unsigned, unsigned, unsigned);
};
struct Manager_1f17f0 { void FUN_001ef260(CSoundCommand_PlayMissionDialogueEvent*); };
extern "C" void* __cdecl FUN_0008d710(unsigned,unsigned);
void __stdcall FUN_001f17f0(const char* name, void* data, unsigned a, unsigned b, unsigned c, unsigned d) {
 if(name && data) {
  Manager_1f17f0* manager=(*(Manager_1f17f0**)&DAT_004e3710);
  if(manager) {
   char buffer[64]={0};
   unsigned n=0; do {buffer[n]=name[n];} while(name[n++]);
   CSoundCommand_PlayMissionDialogueEvent* item=(CSoundCommand_PlayMissionDialogueEvent*)FUN_0008d710(0x48,6);
   if(item) item=((CSoundCommand_PlayMissionDialogueEvent_nv_1f17f0*)(item))->FUN_001f0760(name,data,a,b,c,d);
   manager->FUN_001ef260(item);
  }
 }
}