// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002538a0 @ 0x002538a0
#include "decls/address.h"
struct Pitch {
    char pad[12];
    Pitch* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
struct SeqEventVarPitchType_2538a0 {
    void* vtable;
    SeqEventVarPitchType_2538a0* FUN_002538a0();
    void FUN_002605e0(Pitch*, unsigned __int64*, int, int);
};
extern void* DAT_0042a20c[];
SeqEventVarPitchType_2538a0* SeqEventVarPitchType_2538a0::FUN_002538a0() {
    unsigned __int64 value = FUN_002672f0("SeqEventVarPitch",0,0);
    Pitch pitch;
    Pitch* p = pitch.FUN_0023fc40("Pitch",0);
    FUN_002605e0(p,&value,12,4);
    pitch.FUN_00240060();
    vtable = DAT_0042a20c;
    return this;
}