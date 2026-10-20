// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 2/2)
// audio::SeqEventConditionType::vfunc_3 @ 0x00250030
#include "gen/audio.h"

#include "decls/data/engine/audio.h"

typedef unsigned int size_t; inline void* __cdecl operator new(size_t, void* p) { return p; }   extern void* __cdecl FUN_00247530(void*); struct ConditionPart { void FUN_0023fc40(int*,int); }; namespace audio { struct SeqEventCondition_250030 { virtual void FUN_0024fc30(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); char pad[4]; int field8,fieldC,field10; ConditionPart part; void FUN_0025fd00(); };  } 
void* audio::SeqEventConditionType::vfunc_3() { SeqEventCondition_250030* p=(SeqEventCondition_250030*)FUN_00247530(((char*)&DAT_004e68f8)); if (p) { p->FUN_0025fd00(); p->field8=0; p->fieldC=0; p->field10=0; new (p) SeqEventCondition_250030; p->part.FUN_0023fc40(((int*)&DAT_00429b50),2); } return (void*)(p); }
