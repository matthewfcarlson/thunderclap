// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 12/12)
// FUN_0033a880 @ 0x0033a880
// db_gethook
#include "decls/data/lua.h"
extern "C" unsigned int DAT_004d9968;
extern "C" {
int __cdecl FUN_00212f00(LuaVMState*, int);
LuaVMState* __cdecl FUN_00213290(LuaVMState*, int);
int __cdecl FUN_00213fa0(LuaVMState*);
LuaVMHook __cdecl FUN_00213f90(LuaVMState*);
void __cdecl FUN_0033a620(LuaVMState* L, LuaVMDebug* ar);
void __cdecl FUN_00213380(LuaVMState*, const char*, unsigned int);
// equiv-conv: FUN_0033a740 esi
void __cdecl FUN_0033a740(LuaVMState*);
void __cdecl FUN_00213550(LuaVMState*, void*);
void __cdecl FUN_00213600(LuaVMState*, int);
void __cdecl FUN_00212de0(LuaVMState*, int);
void __cdecl FUN_00212cb0(LuaVMState*, LuaVMState*, int);
void __cdecl FUN_002133d0(LuaVMState*, const char*);
int __cdecl FUN_00213fb0(LuaVMState*);
void __cdecl FUN_00213360(LuaVMState*, int);
void __fastcall __security_check_cookie(unsigned int);
}
extern "C" int __cdecl FUN_0033a880(LuaVMState* state) {
unsigned int cookie=DAT_004d9968;
LuaVMState* source = state;
if (FUN_00212f00(state,1)==8) source=FUN_00213290(state,1);
int flags=FUN_00213fa0(source);
LuaVMHook hook=FUN_00213f90(source);
if(hook && hook != FUN_0033a620) {
FUN_00213380(state,"external hook",13);
} else {
FUN_0033a740(source);
FUN_00213550(source,source);
FUN_00213600(source,-2);
FUN_00212de0(source,-2);
FUN_00212cb0(source,state,1);
}
char mode[4]; int count=0;
if(flags&1) mode[count++]='c';
if(flags&2) mode[count++]='r';
if(flags&4) mode[count++]='l';
mode[count]=0;
FUN_002133d0(state,mode);
int value=FUN_00213fb0(source);
FUN_00213360(state,value);
__security_check_cookie(cookie);
return 3;
}
