// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 10/10)
// FUN_0023ee40 @ 0x0023ee40
typedef void (__cdecl *Callback)();
void __cdecl FUN_0023ea20();
void __cdecl FUN_0023ea30();
void __cdecl FUN_0023ea40();
void __cdecl FUN_0023ea50();
void* __cdecl FUN_0008d690(unsigned);
inline void* operator new(unsigned, void* p) { return p; }
namespace fight {
class SpawnTrack;
template<class T> struct ParamFloatConstRange {
 virtual void slot0();
 char padding[12];
 Callback callback;
 int tail;
 void FUN_00234960(const char*);
};
template<class T> struct ParamBranch {
 virtual void slot0();
 char padding[12];
 Callback callback;
 int tail;
 void FUN_00235170(const char*);
};
template<class T> struct ParamConditionGroup {
 virtual void slot0();
 char padding[12];
 Callback callback;
 int tail;
 void FUN_00235220(const char*);
};
}
extern unsigned DAT_004e5c84;
extern unsigned DAT_004e5c80;
void __cdecl FUN_002347b0(void*, void**, int);
void __cdecl FUN_0023ee40() {
 if (DAT_004e5c84 == 0) {
 void* params[4];
 void* p = FUN_0008d690(24);
 if(p) {
 fight::ParamFloatConstRange<fight::SpawnTrack>* q = (fight::ParamFloatConstRange<fight::SpawnTrack>*)p;
 q->FUN_00234960("timeBegin");
 q = new(p) fight::ParamFloatConstRange<fight::SpawnTrack>;
 q->callback = FUN_0023ea20;
 }
 params[0]=p;
 p=FUN_0008d690(24);
 if(p) {
 fight::ParamFloatConstRange<fight::SpawnTrack>* q = (fight::ParamFloatConstRange<fight::SpawnTrack>*)p;
 q->FUN_00234960("timeEnd");
 q = new(p) fight::ParamFloatConstRange<fight::SpawnTrack>;
 q->callback = FUN_0023ea30;
 }
 params[1]=p;
 p=FUN_0008d690(24);
 if(p) {
 fight::ParamBranch<fight::SpawnTrack>* q = (fight::ParamBranch<fight::SpawnTrack>*)p;
 q->FUN_00235170("branch");
 q = new(p) fight::ParamBranch<fight::SpawnTrack>;
 q->callback = FUN_0023ea40;
 }
 params[2]=p;
 p=FUN_0008d690(24);
 if(p) {
 fight::ParamConditionGroup<fight::SpawnTrack>* q = (fight::ParamConditionGroup<fight::SpawnTrack>*)p;
 q->FUN_00235220("conditionGroup");
 q = new(p) fight::ParamConditionGroup<fight::SpawnTrack>;
 q->callback = FUN_0023ea50;
 }
 params[3]=p;
 FUN_002347b0(&DAT_004e5c80,params,4);
 }
 ++DAT_004e5c84;
}
