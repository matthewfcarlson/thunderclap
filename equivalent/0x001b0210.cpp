// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// AICollisionSolverAgent::vfunc_11 @ 0x001b0210
#include "gen/global.h"

struct AgentState { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual int vfunc_6(); }; struct Checker { unsigned char FUN_001d7300(); }; struct Object_1b0210 { char pad[8]; Checker* check; int kind; }; struct Input { char pad[0x18]; Object_1b0210* object; char pad2[4]; AgentState* state; };  
bool AICollisionSolverAgent::vfunc_11(void* __p0) { Input * input = (Input *)__p0;
 unsigned char result=1; if(input->state) { int value=input->state->vfunc_6(); if(value==0 || value==8) result=0; } if(input->object->kind==5 && !input->object->check->FUN_001d7300()) return (bool)(0); return (bool)(result); }
