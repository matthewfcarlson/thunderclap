// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 19/20, incomplete)
// FUN_002146f0 @ 0x002146f0
struct Constant_2146f0 { unsigned tag; char* object; };
struct Proto_2146f0 { char pad0[8]; Constant_2146f0* constants; unsigned* code; char pad1[12]; char** upvalues; };
struct Closure_2146f0 { char pad0[6]; unsigned char native; char pad1[5]; Proto_2146f0* proto; };
struct Slot_2146f0 { unsigned type; Closure_2146f0* closure; };
struct Frame_2146f0 { Slot_2146f0* base; unsigned unused; unsigned* pc; };
extern char* __cdecl FUN_00219820(Proto_2146f0*, unsigned, int);
extern unsigned __cdecl FUN_002142d0(Proto_2146f0*, int, unsigned);
// equiv-conv: FUN_002146c0 eax ecx
extern char* __cdecl FUN_002146c0(unsigned, Proto_2146f0*);
// equiv-conv: FUN_002146f0 eax stack stack
const char* __cdecl FUN_002146f0(unsigned reg, Frame_2146f0* frame, char** name) {
 for (;;) {
  Slot_2146f0* slot = frame->base - 1;
  if (slot->type != 6) return 0;
  Closure_2146f0* closure = slot->closure;
  if (closure->native) return 0;
  Proto_2146f0* proto = closure->proto;
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
