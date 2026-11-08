// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 6/6)
// FUN_0033a340 @ 0x0033a340
// cl-flags: /GS
// db_getlocal
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState*, int);
extern "C" int __cdecl FUN_00339f70(LuaVMState*, int);
extern "C" int __cdecl FUN_00213fc0(LuaVMState*, int, LuaVMDebug*);
extern "C" int __cdecl FUN_00339c30(LuaVMState*, int, const char*);
extern "C" const char* __cdecl FUN_00214050(LuaVMState*, LuaVMDebug*, int);
extern "C" void __cdecl FUN_00212cb0(LuaVMState*, LuaVMState*, int);
extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C" void __cdecl FUN_00213320(LuaVMState*);
extern "C" int __cdecl FUN_0033a340(LuaVMState* state) {
 LuaVMDebug ar;
 LuaVMState* other = state;
 int base = 0;
 if (FUN_00212f00(state,1)==8) { base=1; other=FUN_00213290(state,1); }
 int level=FUN_00339f70(state,base+1);
 int ok=FUN_00213fc0(other,level,&ar);
 int ret;
 if (!ok) ret=FUN_00339c30(state,base+1,"level out of range");
 else {
 int item=FUN_00339f70(state,base+2);
 const char* result=FUN_00214050(other,&ar,item);
 if(result) {
 FUN_00212cb0(other,state,1);
 FUN_002133d0(state,result);
 FUN_00212ed0(state,-2);
 ret=2;
 } else {
 FUN_00213320(state);
 ret=1;
 }
 }
 return ret;
}
