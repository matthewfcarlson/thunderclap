// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// audio::SeqEventLogicRepeat::vfunc_2 @ 0x00254dd0
#include "decls/data/engine/audio.h"
#include "gen/audio.h"

void* __cdecl FUN_00247530(void*);
struct SeqEventLogicRepeat_254dd0;
struct SeqCommandLogicRepeat_254dd0 {
    void* FUN_00254c80(SeqEventLogicRepeat_254dd0*);
};
struct Receiver { void FUN_0025dba0(void*); };
struct SeqEventLogicRepeat_254dd0 {
    void vfunc_2(Receiver* receiver);
};
void SeqEventLogicRepeat_254dd0::vfunc_2(Receiver* receiver) {
    audio::SeqCommandLogicRepeat* helper = (audio::SeqCommandLogicRepeat*)FUN_00247530(((char*)((char*)&DAT_004e72f8 + 104)));
    if (helper) receiver->FUN_0025dba0(((SeqCommandLogicRepeat_254dd0*)(helper))->FUN_00254c80(this));
    else receiver->FUN_0025dba0(0);
}