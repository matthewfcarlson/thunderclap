// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 10/10)
// FUN_0033af80 @ 0x0033af80
// cl-flags: /GS
// table.concat
#include "decls/data/lua.h"
extern "C" {
const char* __cdecl FUN_00339e60(LuaVMState*, int, const char*, unsigned int*);
int __cdecl FUN_00339fe0(LuaVMState*, int, int);
void __cdecl FUN_00339d70(LuaVMState*, int, int);
int __cdecl FUN_003392c0(LuaVMState*, int);
void __cdecl FUN_00339630(LuaVMState*, LuaVMLBuffer*);
void __cdecl FUN_00213640(LuaVMState*, int, int);
int __cdecl FUN_00212fb0(LuaVMState*, int);
int __cdecl FUN_00339c30(LuaVMState*, int, const char*);
void __cdecl FUN_00339590(LuaVMLBuffer*);
void __cdecl FUN_003394b0(LuaVMLBuffer*, const char*, unsigned int);
void __cdecl FUN_00339540(LuaVMLBuffer*);
}
extern "C" int __cdecl FUN_0033af80(LuaVMState* state) {
 unsigned int separatorLength;
 LuaVMLBuffer buffer;
 const char* separator=FUN_00339e60(state,2,"",&separatorLength);
 int first=FUN_00339fe0(state,3,1);
 int last=FUN_00339fe0(state,4,0);
 FUN_00339d70(state,1,5);
 if (!last) last=FUN_003392c0(state,1);
 FUN_00339630(state,&buffer);
 for(int i=first;i<=last;++i) {
  FUN_00213640(state,1,i);
  if(!FUN_00212fb0(state,-1)) FUN_00339c30(state,1,"table contains non-strings");
  FUN_00339590(&buffer);
  if(i!=last) FUN_003394b0(&buffer,separator,separatorLength);
 }
 FUN_00339540(&buffer);
 return 1;
}
