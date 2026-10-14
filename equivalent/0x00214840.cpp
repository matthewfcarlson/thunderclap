// STATUS: equivalent (tools/equiv.py level 3: 3047 inputs, branch coverage 16/18, incomplete)
// FUN_00214840 @ 0x00214840
// Lua 5.0 ldebug.c getfuncname(ci, &name): name the function that is running in `ci` from the
// OP_CALL / OP_TAILCALL instruction of its calling Lua function.
struct Proto_214840 { char pad0[8]; void* constants; unsigned* code; };
struct Closure_214840 { char pad0[6]; unsigned char native; char pad1[5]; Proto_214840* proto; };
struct Slot_214840 { unsigned type; Closure_214840* closure; };
struct CallInfo_214840 { Slot_214840* base; unsigned top; unsigned* pc; int tailcalls; };

// equiv-conv: FUN_002146f0 eax stack stack
const char* __cdecl FUN_002146f0(unsigned reg, CallInfo_214840* ci, char** name);

// equiv-conv: FUN_00214840 ecx stack
const char* __cdecl FUN_00214840(CallInfo_214840* ci, char** name)
{
    Slot_214840* func = ci->base - 1;
    if (func->type == 6 && !func->closure->native && ci->tailcalls > 0) {
        return 0;
    }

    CallInfo_214840* caller = ci - 1;
    Slot_214840* callerFunc = caller->base - 1;
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
