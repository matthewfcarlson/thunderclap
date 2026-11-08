// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_001d2020 @ 0x001d2020
// cl-flags: /GS
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_002135a0(LuaVMState*,int,const char*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*,int);
extern "C" void __cdecl FUN_002139a0(LuaVMState*,int,int);
extern "C" const char* __cdecl FUN_00213190(LuaVMState*,int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*,int);
extern "C" void __cdecl FUN_002133d0(LuaVMState*,const char*);
extern "C" void __cdecl FUN_00213c40(LuaVMState*);
extern "C" int __cdecl FUN_00267760(char*,int,const char*,...);
extern "C" void __cdecl FUN_00212de0(LuaVMState*,int);
// The original pushes the name too, but 0x001d0c60 takes only the state (cdecl: the caller pops it); the 64-bit
// build declares the definition's own type so the call binds.
#if defined(HULK_PTR64)
extern "C" int __cdecl FUN_001d0c60(LuaVMState*);
#else
extern "C" int __cdecl FUN_001d0c60(LuaVMState*,const char*);
#endif
extern "C" void __cdecl FUN_00212e20(LuaVMState*,int);
extern "C" int __cdecl FUN_001d2020(LuaVMState* state) {
 char name[64];
 int result=-1;
 if(FUN_00212d70(state)>=1) {
 FUN_002135a0(state,-10001,"tostring");
 FUN_00212ed0(state,1);
 FUN_002139a0(state,1,1);
 const char* text=FUN_00213190(state,-1);
 if(!text){
 FUN_00212d80(state,-2);
 FUN_002133d0(state,"'LuaDebugChannel':  invalid channel name.");
 FUN_00213c40(state);
 } else {
 FUN_00267760(name,64,"%s",text);
 FUN_00212d80(state,-2);
 FUN_00212de0(state,1);
 #if defined(HULK_PTR64)
 result=FUN_001d0c60(state);
 #else
 result=FUN_001d0c60(state,name);
 #endif
 FUN_002133d0(state,name);
 FUN_00212e20(state,1);
 }
 }
 return result;
}