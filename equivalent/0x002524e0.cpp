// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002524e0 @ 0x002524e0
#include "gen/audio.h"

#include "decls/address.h"
namespace audio { struct SeqEventVarVolumeRandType_nv_2524e0 {
    void FUN_002605e0(void*, const __int64*, int, int);
}; }
struct Local { char data[32]; void* FUN_0023fc40(const char*, int); void FUN_00240060(); };
extern void* DAT_00429f28[];
void* audio::SeqEventVarVolumeRandType::FUN_002524e0() { __int64 value = FUN_002672f0("SeqEventVarVolumeRand", 0, 0); Local local; void* p = local.FUN_0023fc40("Vol?", 0); ((SeqEventVarVolumeRandType_nv_2524e0*)this)->FUN_002605e0(p, &value, 16, 4); local.FUN_00240060(); *(void**)this = DAT_00429f28; return (void*)(this); }
