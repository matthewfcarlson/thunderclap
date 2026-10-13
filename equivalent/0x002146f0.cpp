// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 19/20, incomplete)
// FUN_002146f0 @ 0x002146f0
struct Constant { unsigned tag; char* object; };
struct Proto { char pad0[8]; Constant* constants; unsigned* code; char pad1[12]; char** upvalues; };
struct Closure { char pad0[6]; unsigned char native; char pad1[5]; Proto* proto; };
struct Slot { unsigned type; Closure* closure; };
struct Frame { Slot* base; unsigned unused; unsigned* pc; };
extern char* __cdecl FUN_00219820(Proto*, unsigned, int);
extern unsigned __cdecl FUN_002142d0(Proto*, int, unsigned);
// equiv-conv: FUN_002146c0 eax ecx
extern char* __cdecl FUN_002146c0(unsigned, Proto*);
// equiv-conv: FUN_002146f0 eax stack stack
const char* __cdecl FUN_002146f0(unsigned reg, Frame* frame, char** name) {
 for (;;) {
  Slot* slot = frame->base - 1;
  if (slot->type != 6) return 0;
  Closure* closure = slot->closure;
  if (closure->native) return 0;
  Proto* proto = closure->proto;
  int pc = ((int)((unsigned)frame->pc - (unsigned)proto->code) >> 2) - 1;
  char* local = FUN_00219820(proto, reg + 1, pc);
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
    *name = proto->constants[(instruction >> 6) & 0x3ffff].object + 16;
    return "global";
   case 6:
    *name = FUN_002146c0((instruction >> 6) & 511, proto);
    return "field";
   case 4:
    *name = proto->upvalues[(instruction >> 15) & 511] + 16;
    return "upvalue";
   case 11:
    *name = FUN_002146c0((instruction >> 6) & 511, proto);
    return "method";
   default: return 0;
  }
 }
}
