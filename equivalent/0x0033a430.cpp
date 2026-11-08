// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_0033a430 @ 0x0033a430
// cl-flags: /GS
// db_setlocal
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState*, int);
extern "C" int __cdecl FUN_00339f70(LuaVMState*, int);
extern "C" int __cdecl FUN_00213fc0(LuaVMState*, int, LuaVMDebug*);
extern "C" int __cdecl FUN_00339c30(LuaVMState*, int, const char*);
extern "C" void __cdecl FUN_00339dc0(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" void __cdecl FUN_00212cb0(LuaVMState*, LuaVMState*, int);
extern "C" const char* __cdecl FUN_002140c0(LuaVMState*, LuaVMDebug*, int);
extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
extern "C" int __cdecl FUN_0033a430(LuaVMState* state) {
 LuaVMDebug ar;
 int offset = 0;
 LuaVMState* object = state;
 if (FUN_00212f00(state, 1) == 8) {
  offset = 1;
  object = FUN_00213290(state, 1);
 }
 int level = offset + 1;
 int value = FUN_00339f70(state, level);
 if (!FUN_00213fc0(object, value, &ar)) {
  int result = FUN_00339c30(state, level, "level out of range");
  return result;
 }
 level = offset + 3;
 FUN_00339dc0(state, level);
 FUN_00212d80(state, level);
 FUN_00212cb0(state, object, 1);
 value = FUN_00339f70(state, offset + 2);
 const char* result = FUN_002140c0(object, &ar, value);
 FUN_002133d0(state, result);
 return 1;
}
