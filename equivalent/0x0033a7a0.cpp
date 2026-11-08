// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_0033a7a0 @ 0x0033a7a0
// db_sethook
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState*,int);
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState*,int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*,int);
extern "C" void __cdecl FUN_0033a620(LuaVMState* L, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00213f60(LuaVMState*,LuaVMHook,int,int);
extern "C" const char* __cdecl FUN_00339df0(LuaVMState*,int,unsigned int*);
extern "C" int __cdecl FUN_00339fe0(LuaVMState*,int,int);
extern "C" void __cdecl FUN_00339d70(LuaVMState*,int,int);
// equiv-conv: FUN_0033a6b0 edi stack
extern "C" int __cdecl FUN_0033a6b0(const char*,int);
// equiv-conv: FUN_0033a740 esi
extern "C" void __cdecl FUN_0033a740(LuaVMState*);
extern "C" void __cdecl FUN_00213550(LuaVMState*,void*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*,int);
extern "C" void __cdecl FUN_00212cb0(LuaVMState*,LuaVMState*,int);
extern "C" void __cdecl FUN_00213800(LuaVMState*,int);
extern "C" int __cdecl FUN_0033a7a0(LuaVMState* state) {
 int offset=0; LuaVMState* context=state;
 if(FUN_00212f00(state,1)==8){offset=1; context=FUN_00213290(state,1);}
 int index=offset+1;
 if(FUN_00212f00(state,index)<=0){FUN_00212d80(state,index); FUN_00213f60(context,0,0,0);}
 else {const char* first=FUN_00339df0(state,offset+2,0); int second=FUN_00339fe0(state,offset+3,0); FUN_00339d70(state,index,6); int result=FUN_0033a6b0(first,second); FUN_00213f60(context,FUN_0033a620,result,second);}
 FUN_0033a740(context); FUN_00213550(context,context); FUN_00212ed0(state,index); FUN_00212cb0(state,context,1); FUN_00213800(context,-3); FUN_00212d80(context,-2); return 0;
}
