// STATUS: equivalent (tools/equiv.py level 3: 3053 inputs, branch coverage 19/20, incomplete)
// getobjname: what register reg of ci's Lua function holds ("local", "global", "field", "upvalue", "method") and its name.
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00219820(const LuaVMProto* f, int local_number, int pc);
extern "C" LuaVMInstruction __cdecl FUN_002142d0(const LuaVMProto* pt, int lastpc, int reg);
// equiv-conv: FUN_002146c0 eax ecx
extern "C" const char* FUN_002146c0(int c, const LuaVMProto* p);

// equiv-conv: FUN_002146f0 eax stack stack
extern "C" const char* __cdecl FUN_002146f0(unsigned reg, LuaVMCallInfo* ci, const char** name) {
 for (;;) {
  LuaVMTObject* slot = ci->base - 1;
  if (slot->tt != LUAVM_TFUNCTION) return 0;
  LuaVMClosure* closure = (LuaVMClosure*)slot->value.gc;
  if (closure->c.isC) return 0;
  LuaVMProto* proto = closure->l.p;
  int pc = (int)(ci->savedpc - proto->code) - 1;
  const char* local = FUN_00219820(proto, reg + 1, pc);
  *name = local;
  if (local) return "local";
  unsigned instruction = FUN_002142d0(proto, pc, reg);
  switch (instruction & 63) {
   case 0: {
    unsigned source = (instruction >> 15) & 511;
    if (source >= (instruction >> 24)) return 0;
    reg = source;
    break;
   }
   case 5:
    *name = LUAVM_GETSTR(proto->k[(instruction >> 6) & 0x3ffff].value.gc);
    return "global";
   case 6:
    *name = FUN_002146c0((int)((instruction >> 6) & 511), proto);
    return "field";
   case 4:
    *name = LUAVM_GETSTR(proto->upvalues[(instruction >> 15) & 511]);
    return "upvalue";
   case 11:
    *name = FUN_002146c0((int)((instruction >> 6) & 511), proto);
    return "method";
   default: return 0;
  }
 }
}
