// STATUS: equivalent (tools/equiv.py level 3: 2575 inputs, branch coverage 16/16)
// FUN_003392c0 @ 0x003392c0
// luaL_getn
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState*);
// equiv-conv: FUN_003391f0 esi
extern "C" void __cdecl FUN_003391f0(LuaVMState*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*,int);
extern "C" void __cdecl FUN_00213600(LuaVMState*,int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*,int);
extern "C" int __cdecl FUN_00213120(LuaVMState*,int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*,int);
extern "C" void __cdecl FUN_002135a0(LuaVMState*,int,const char*);
extern "C" void __cdecl FUN_00213640(LuaVMState*,int,int);
extern "C" int __cdecl FUN_003392c0(LuaVMState* state,int index) {
 if(index<=0 && index>-10000) index=index+FUN_00212d70(state)+1;
 FUN_003391f0(state);
 FUN_00212ed0(state,index);
 FUN_00213600(state,-2);
 int length=-1;
 if(FUN_00212f00(state,-1)==3) length=FUN_00213120(state,-1);
 FUN_00212d80(state,-3);
 if(length>=0) return length;
 FUN_002135a0(state,index,((const char*)&DAT_00426788));
 length=-1;
 if(FUN_00212f00(state,-1)==3) length=FUN_00213120(state,-1);
 FUN_00212d80(state,-2);
 if(length>=0) return length;
 int count=1;
 FUN_00213640(state,index,count);
 while(FUN_00212f00(state,-1)!=0) {
 FUN_00212d80(state,-2);
 ++count;
 FUN_00213640(state,index,count);
 }
 FUN_00212d80(state,-2);
 return count-1;
}
