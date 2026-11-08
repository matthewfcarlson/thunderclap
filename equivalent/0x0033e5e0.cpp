// STATUS: equivalent (tools/equiv.py level 3: 3081 inputs, branch coverage 23/24, incomplete)
// FUN_0033e5e0 @ 0x0033e5e0
// luaB_require
#include "decls/data/lua.h"

extern "C" char* __cdecl strchr(const char*, int);
extern "C" {
const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
void __cdecl FUN_00212d80(LuaVMState* L, int idx);
void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
int __cdecl FUN_00212f00(LuaVMState* L, int idx);
int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
void __cdecl FUN_00213600(LuaVMState* L, int idx);
int __cdecl FUN_00213160(LuaVMState* L, int idx);
void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
int __cdecl FUN_00339800(LuaVMState* L, const char* filename);
void __cdecl FUN_00212e20(LuaVMState* L, int idx);
void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
void __cdecl FUN_002139a0(LuaVMState* L, int nargs, int nresults);
void __cdecl FUN_00213520(LuaVMState* L, int b);
void __cdecl FUN_00212e60(LuaVMState* L, int idx);
void __cdecl FUN_00213800(LuaVMState* L, int idx);
}
// equiv-conv: FUN_0033e570 ebx
void FUN_0033e570(LuaVMState* L);
// equiv-conv: FUN_0033e4d0 esi
const char* FUN_0033e4d0(LuaVMState* L);
extern "C" int __cdecl FUN_0033e5e0(LuaVMState* state) {
 int status=2;
 FUN_00339df0(state,1,0);
 FUN_00212d80(state,1);
 FUN_002135a0(state,-10001,"_LOADED");
 if(FUN_00212f00(state,2)!=5) return FUN_00338e20(state,"`_LOADED' is not a table");
 FUN_002135a0(state,-10001,"LUA_PATH");
 const char* path=FUN_00213190(state,-1);
 FUN_00212d80(state,-2);
 if(!path) path="?;?.lua";
 FUN_00212ed0(state,1);
 FUN_00213600(state,2);
 if(FUN_00213160(state,-1)) return 1;
 do {
  FUN_00212d80(state,3);
  if(!*path) break;
  const char* start=path;
  if(*start==';') ++start;
  path=strchr(start,';');
  if(!path) { path=start; while(*path) ++path; }
  FUN_00213380(state,start,(unsigned)(path-start));
  if(!path) break;
  FUN_0033e570(state);
  const char* filename=FUN_00213190(state,-1);
  status=FUN_00339800(state,filename);
 } while(status==2);
 if(status!=0) {
  const char* detail;
  if(status==2) detail=FUN_0033e4d0(state);
  else detail=FUN_00213190(state,-1);
  const char* package=FUN_00213190(state,1);
  if(status==2) return FUN_00338e20(state,"could not load package `%s' from path `%s'",package,detail);
  return FUN_00338e20(state,"error loading package `%s' (%s)",package,detail);
 }
 FUN_002135a0(state,-10001,"_REQUIREDNAME");
 FUN_00212e20(state,-2);
 FUN_00212ed0(state,1);
 FUN_00213790(state,-10001,"_REQUIREDNAME");
 FUN_002139a0(state,0,1);
 FUN_00212e20(state,-2);
 FUN_00213790(state,-10001,"_REQUIREDNAME");
 if(!FUN_00212f00(state,-1)) {
  FUN_00213520(state,1);
  FUN_00212e60(state,-2);
 }
 FUN_00212ed0(state,1);
 FUN_00212ed0(state,-2);
 FUN_00213800(state,2);
 return 1;
}
