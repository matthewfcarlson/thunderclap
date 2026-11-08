// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_001d2ba0 @ 0x001d2ba0
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
struct Object {
 char padding[8];
 LuaVMState* context;
 void FUN_001d1980(const char* key, int mode);
 bool target(const char* key, int mode, bool retry);
};
bool Object::target(const char* key, int mode, bool retry) {
 int index = (unsigned char)mode ? -10001 : -2;
 int saved = FUN_00212d70(context);
 FUN_002133d0(context, key);
 FUN_00213600(context, index);
 if (FUN_00212f00(context, -1) == 5) return true;
 if (retry) {
  FUN_00212d80(context, -2);
  FUN_001d1980(key, mode);
  FUN_002133d0(context, key);
  FUN_00213600(context, index);
  if (FUN_00212f00(context, -1) == 5) return true;
 }
 FUN_00212d80(context, saved);
 return false;
}
