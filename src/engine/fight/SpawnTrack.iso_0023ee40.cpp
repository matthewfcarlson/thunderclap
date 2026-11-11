// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023ea20..0x0023f0d0 (kind game, layer engine, confidence high), dominant class fight::SpawnTrack
#include "tree_prelude.h"


// 0x0023ee40 FUN_0023ee40 (256 B): equivalent/0x0023ee40.cpp [isolated: compile error C2084: function 'void *operator new(size_t,void *)' already has a body]
// sym: ?FUN_0023ee40@fn_f8468b6e@@YAXXZ
#include "gen/owners.h"
#include "decls/data/engine/fight.h"
namespace fn_f8468b6e {} using namespace fn_f8468b6e;
namespace fn_f8468b6e {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 10/10)
// FUN_0023ee40 @ 0x0023ee40

typedef void (__cdecl *Callback_23ee40)();
void __cdecl SetTimeBegin_0023ea20();
void __cdecl SetTimeEnd_0023ea30();
void __cdecl GetBranch_0023ea40();
void __cdecl GetConditionGroup_0023ea50();
void* __cdecl FUN_0008d690(unsigned);

} // namespace fn_f8468b6e
inline void* operator new(size_t, void* p) { return p; }
namespace fn_f8468b6e {

namespace fight {
class SpawnTrack;
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char padding[12];
 Callback_23ee40 callback;
 int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamBranch {
 virtual void slot0();
 char padding[12];
 Callback_23ee40 callback;
 int tail;
 void FUN_00235170(const char*);
};
template<class T> struct ParamConditionGroup {
 virtual void slot0();
 char padding[12];
 Callback_23ee40 callback;
 int tail;
 void FUN_00235220(const char*);
};
}
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl FUN_0023ee40() {
 if (DAT_004e5c84 == 0) {
 void* params[4];
 void* p = FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<fight::SpawnTrack>));
 if(p) {
 fight::ParamFloatConstRange<fight::SpawnTrack>* q = (fight::ParamFloatConstRange<fight::SpawnTrack>*)p;
 q->FUN_00234960("timeBegin");
 q = new(p) fight::ParamFloatConstRange<fight::SpawnTrack>;
 q->callback = SetTimeBegin_0023ea20;
 }
 params[0]=p;
 p=FUN_0008d690((int)sizeof(fight::ParamFloatConstRange<fight::SpawnTrack>));
 if(p) {
 fight::ParamFloatConstRange<fight::SpawnTrack>* q = (fight::ParamFloatConstRange<fight::SpawnTrack>*)p;
 q->FUN_00234960("timeEnd");
 q = new(p) fight::ParamFloatConstRange<fight::SpawnTrack>;
 q->callback = SetTimeEnd_0023ea30;
 }
 params[1]=p;
 p=FUN_0008d690((int)sizeof(fight::ParamBranch<fight::SpawnTrack>));
 if(p) {
 fight::ParamBranch<fight::SpawnTrack>* q = (fight::ParamBranch<fight::SpawnTrack>*)p;
 q->FUN_00235170("branch");
 q = new(p) fight::ParamBranch<fight::SpawnTrack>;
 q->callback = GetBranch_0023ea40;
 }
 params[2]=p;
 p=FUN_0008d690((int)sizeof(fight::ParamConditionGroup<fight::SpawnTrack>));
 if(p) {
 fight::ParamConditionGroup<fight::SpawnTrack>* q = (fight::ParamConditionGroup<fight::SpawnTrack>*)p;
 q->FUN_00235220("conditionGroup");
 q = new(p) fight::ParamConditionGroup<fight::SpawnTrack>;
 q->callback = GetConditionGroup_0023ea50;
 }
 params[3]=p;
 FUN_002347b0(&DAT_004e5c80,params,4);
 }
 ++DAT_004e5c84;
}
} // namespace fn_f8468b6e

