// STATUS: equivalent (tools/equiv.py level 3: 2586 inputs, branch coverage 6/6)
// FUN_0033a970 @ 0x0033a970
// cl-flags: /GS
// db_debug: a line-by-line console until "cont".
#include "decls/data/lua.h"
#include "decls/data/engine/core.h"

extern "C" LuaVMFile DAT_004d99f0;  // stdin (the CRT's _iob[0]; DAT_004d9a30 is stderr)
extern "C" int __cdecl FUN_00347eed(const char *, LuaVMFile *);  // fputs
extern "C" char * __cdecl _fgets(char *, int, LuaVMFile *);
extern "C" int __cdecl FUN_00339c00(LuaVMState *L, const char *str);
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_0033a970(LuaVMState *state) {
 char line[250];
 FUN_00347eed("lua_debug> ", ((LuaVMFile*)&DAT_004d9a30));
 while (_fgets(line,250,&DAT_004d99f0)) {
  const char *end="cont\n";
  int i;
  for(i=0;i<6;++i) if(line[i]!=end[i]) break;
  if(i==6) break;
  FUN_00339c00(state,line);
  FUN_00212d80(state,0);
  FUN_00347eed("lua_debug> ",((LuaVMFile*)&DAT_004d9a30));
 }
 return 0;
}
