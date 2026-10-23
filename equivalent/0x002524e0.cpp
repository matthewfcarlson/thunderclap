// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002524e0 @ 0x002524e0
#include "decls/address.h"
namespace audio { struct SeqEventVarVolumeRandType { void FUN_002605e0(void*, const __int64*, int, int); SeqEventVarVolumeRandType* FUN_002524e0(); }; }
struct Local { char data[32]; void* FUN_0023fc40(const char*, int); void FUN_00240060(); };
extern void* DAT_00429f28[];
audio::SeqEventVarVolumeRandType* audio::SeqEventVarVolumeRandType::FUN_002524e0() { __int64 value = FUN_002672f0("SeqEventVarVolumeRand", 0, 0); Local local; void* p = local.FUN_0023fc40("Vol?", 0); FUN_002605e0(p, &value, 16, 4); local.FUN_00240060(); *(void**)this = DAT_00429f28; return this; }