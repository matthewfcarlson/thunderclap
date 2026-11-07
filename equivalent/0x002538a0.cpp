// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002538a0 @ 0x002538a0
#include "decls/address.h"
#include "gen/owners.h"
#include "decls/data/records.h"
struct Pitch {
    char pad[12];
};
struct SeqEventVarPitchType_2538a0 {
    void* vtable;
    SeqEventVarPitchType_2538a0* FUN_002538a0();
    void FUN_002605e0(Pitch*, unsigned __int64*, int, int);
};
extern void* DAT_0042a20c[];
SeqEventVarPitchType_2538a0* SeqEventVarPitchType_2538a0::FUN_002538a0() {
    HULK_SIZE32(AudioSeqEventVarPitch, 0xc);
    unsigned __int64 value = FUN_002672f0("SeqEventVarPitch",0,0);
    Pitch pitch;
    Pitch* p = ((Pitch *)((owners::String_23fc40 *)&pitch)->FUN_0023fc40("Pitch", (hulk_intptr)0));
    FUN_002605e0(p,&value,(int)sizeof(AudioSeqEventVarPitch),(int)__alignof(AudioSeqEventVarPitch));
    ((owners::Str_240060 *)&pitch)->FUN_00240060();
    vtable = DAT_0042a20c;
    return this;
}