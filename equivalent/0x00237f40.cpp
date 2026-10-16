// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 8/8)
// FUN_00237f40 @ 0x00237f40
#include "decls/data/engine/fight.h"

inline void* __cdecl operator new(unsigned int, void* p) { return p; }
void* __cdecl FUN_0008d690(unsigned int);
void __cdecl FUN_00237b70(); void __cdecl FUN_00237b80(); void __cdecl FUN_00237b90();
 
namespace fight {
class SequenceTrack;
template<class T> struct ParamBranch { virtual void v0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00235170(const char*); };
template<class T> struct ParamIntConstRange { virtual void v0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_002348e0(const char*); };
template<class T> struct ParamConditionGroup { virtual void v0(); char data[12]; void (__cdecl *callback)(); char tail[4]; void FUN_00235220(const char*); };
}
void __cdecl FUN_002347b0(int*, void**, int);
void target() {
 if (!DAT_004e5c08) {
 void* values[3];
 fight::ParamBranch<fight::SequenceTrack>* a = (fight::ParamBranch<fight::SequenceTrack>*)FUN_0008d690(24);
 if(a) { a->FUN_00235170("branch"); new(a) fight::ParamBranch<fight::SequenceTrack>; a->callback=FUN_00237b70; } values[0]=a;
 fight::ParamIntConstRange<fight::SequenceTrack>* b = (fight::ParamIntConstRange<fight::SequenceTrack>*)FUN_0008d690(24);
 if(b) { b->FUN_002348e0("priority"); new(b) fight::ParamIntConstRange<fight::SequenceTrack>; b->callback=FUN_00237b80; } values[1]=b;
 fight::ParamConditionGroup<fight::SequenceTrack>* c = (fight::ParamConditionGroup<fight::SequenceTrack>*)FUN_0008d690(24);
 if(c) { c->FUN_00235220("conditionGroup"); new(c) fight::ParamConditionGroup<fight::SequenceTrack>; c->callback=FUN_00237b90; } values[2]=c;
 FUN_002347b0(&DAT_004e5c04,values,3);
 }
 ++DAT_004e5c08;
}