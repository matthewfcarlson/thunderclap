// STATUS: equivalent (tools/equiv.py level 3: 3047 inputs, branch coverage 16/18, incomplete)
// FUN_00214840 @ 0x00214840
// Lua 5.0 ldebug.c getfuncname(ci, &name): name the function that is running in `ci` from the
// OP_CALL / OP_TAILCALL instruction of its calling Lua function.
struct Proto { char pad0[8]; void* constants; unsigned* code; };
struct Closure { char pad0[6]; unsigned char native; char pad1[5]; Proto* proto; };
struct Slot { unsigned type; Closure* closure; };
struct CallInfo { Slot* base; unsigned top; unsigned* pc; int tailcalls; };

// equiv-conv: FUN_002146f0 eax stack stack
const char* __cdecl FUN_002146f0(unsigned reg, CallInfo* ci, char** name);

// equiv-conv: FUN_00214840 ecx stack
const char* __cdecl FUN_00214840(CallInfo* ci, char** name)
{
    Slot* func = ci->base - 1;
    if (func->type == 6 && !func->closure->native && ci->tailcalls > 0) {
        return 0;
    }

    CallInfo* caller = ci - 1;
    Slot* callerFunc = caller->base - 1;
    if (callerFunc->type != 6 || callerFunc->closure->native) {
        return 0;
    }

    int pc;
    callerFunc = caller->base - 1;
    if (callerFunc->type == 6 && !callerFunc->closure->native) {
        pc = ((int)((unsigned)caller->pc - (unsigned)callerFunc->closure->proto->code) >> 2) - 1;
    } else {
        pc = -1;
    }

    unsigned instruction = caller->base[-1].closure->proto->code[pc];
    unsigned op = instruction & 0x3f;
    if (op == 0x19 || op == 0x1a) {
        return FUN_002146f0(instruction >> 24, caller, name);
    }
    return 0;
}
