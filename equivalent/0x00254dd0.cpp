// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// audio::SeqEventLogicRepeat::vfunc_2 @ 0x00254dd0
#include "decls/data/engine/audio.h"

void* __cdecl FUN_00247530(void*);
struct audio_SeqEventLogicRepeat;
struct Helper { void* FUN_00254c80(audio_SeqEventLogicRepeat*); };
struct Receiver { void FUN_0025dba0(void*); };
struct audio_SeqEventLogicRepeat {
    void vfunc_2(Receiver* receiver);
};
void audio_SeqEventLogicRepeat::vfunc_2(Receiver* receiver) {
    Helper* helper = (Helper*)FUN_00247530(((char*)((char*)&DAT_004e72f8 + 104)));
    if (helper) receiver->FUN_0025dba0(helper->FUN_00254c80(this));
    else receiver->FUN_0025dba0(0);
}