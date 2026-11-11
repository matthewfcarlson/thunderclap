// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033acd0..0x0033b610 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f711172d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f711172d {} using namespace fn_f711172d;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f711172d {
extern "C" {
const char* __cdecl FUN_00339e60(LuaVMState*, int, const char*, unsigned int*);
}
extern "C" {
int __cdecl FUN_00339fe0(LuaVMState*, int, int);
}
extern "C" {
void __cdecl FUN_00339d70(LuaVMState*, int, int);
}
extern "C" {
int __cdecl FUN_003392c0(LuaVMState*, int);
}
extern "C" {
void __cdecl FUN_00339630(LuaVMState*, LuaVMLBuffer*);
}
extern "C" {
void __cdecl FUN_00213640(LuaVMState*, int, int);
}
extern "C" {
int __cdecl FUN_00212fb0(LuaVMState*, int);
}
extern "C" {
int __cdecl FUN_00339c30(LuaVMState*, int, const char*);
}
extern "C" {
void __cdecl FUN_00339590(LuaVMLBuffer*);
}
extern "C" {
void __cdecl FUN_003394b0(LuaVMLBuffer*, const char*, unsigned int);
}
extern "C" {
void __cdecl FUN_00339540(LuaVMLBuffer*);
}


// 0x0033af80 FUN_0033af80 (250 B): matches/0x0033af80.cpp
// sym: _FUN_0033af80
// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 10/10)
// FUN_0033af80 @ 0x0033af80
// table.concat
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

} // namespace fn_f711172d
