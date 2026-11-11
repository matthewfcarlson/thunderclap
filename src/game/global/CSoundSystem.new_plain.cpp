// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f0ab0..0x001f2db0 (kind game, layer game, confidence high), dominant class CSoundSystem
#include "tree_prelude.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe4d26cb {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe4d26cb {} using namespace fn_fe4d26cb;
#include "game/global.h"

// ---- declarations shared by the functions below
inline void* __cdecl operator new(size_t, void* p) { return p; }
namespace fn_fe4d26cb {
struct InitObject { void FUN_001ea8b0(int); };
struct Owner_1f2c00 { void FUN_001f6990(); };
struct StateData { char data[8]; void FUN_0027af00();  };
struct CSoundTriggerExecutionState_1f2c00 {
 virtual void slot0();
 int references;
 int field8, fieldC, field10;
 unsigned char active;
 char pad[3];
 StateData state;
 float duration;
 int field24;
};
extern "C" void* __cdecl FUN_0008d750(int,int);
struct Target_1f2c00 {
 Owner_1f2c00* owner;
 InitObject* init;
 int field8;
 CSoundTriggerExecutionState_1f2c00* entries;
 void FUN_001f2730();
 void FUN_001f2c00(int arg);
};


// 0x001f2c00 FUN_001f2c00 (221 B): equivalent/0x001f2c00.cpp
// sym: ?FUN_001f2c00@Target_1f2c00@fn_fe4d26cb@@QAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 225 inputs, branch coverage 6/6)
// FUN_001f2c00 @ 0x001f2c00
void Target_1f2c00::FUN_001f2c00(int arg) {
 init->FUN_001ea8b0(arg);
 owner->FUN_001f6990();
 void* storage=FUN_0008d750(0xfa4,6);
 CSoundTriggerExecutionState_1f2c00* result=0;
 if(storage) {
  *((int*)storage)=100;
  result=(CSoundTriggerExecutionState_1f2c00*)((int*)storage+1);
  for(int i=0;i<100;++i) {
   new (&result[i]) CSoundTriggerExecutionState_1f2c00;
   result[i].references=1;
   result[i].state.FUN_0027af00();
   result[i].field8=0; result[i].fieldC=0; result[i].field10=0;
   result[i].active=0; result[i].duration=100.0f; result[i].field24=0;
   ((owners::Target_27b040 *)&(result[i].state))->FUN_0027b040((hulk_uintptr)0);
  }
 }
 entries=result;
 for(int j=0;j<100;++j) {
  CSoundTriggerExecutionState_1f2c00* p=entries+j;
  p->field8=0; p->fieldC=0; p->field10=0; p->active=0;
  p->duration=100.0f; p->field24=0;
  ((owners::Target_27b040 *)&(p->state))->FUN_0027b040((hulk_uintptr)0);
 }
 FUN_001f2730();
}

} // namespace fn_fe4d26cb
