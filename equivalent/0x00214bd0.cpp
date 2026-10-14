// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// FUN_00214bd0 @ 0x00214bd0
struct Value { int type; unsigned int data; };
struct CallInfo { Value *base; char pad[12]; };
struct State { char pad0[8]; Value *top; char pad1[12]; Value *limit; char pad2[12]; CallInfo *frames; };
struct DebugInfo { char pad[0x5c]; unsigned int frameIndex; };
extern void __cdecl FUN_00214a90(State *, const char *);
// equiv-conv: FUN_00214ac0 eax esi edi stack stack
extern int __cdecl FUN_00214ac0(const char *, DebugInfo *, CallInfo *, State *, Value *);
extern void __cdecl FUN_002141d0(State *);
extern void __cdecl FUN_00215460(State *, int);
extern "C" char * __cdecl strchr(const char *, int);
int __cdecl FUN_00214bd0(State *state, const char *options, DebugInfo *info)
{
    int result = 1;
    if (*options == '>') {
        Value *value = state->top - 1;
        if (value->type != 6)
            FUN_00214a90(state, "value for `lua_getinfo' is not a function");
        result = FUN_00214ac0(options + 1, info, 0, state, value);
        state->top -= 1;
    } else if (info->frameIndex != 0) {
        CallInfo *frame = state->frames + info->frameIndex;
        result = FUN_00214ac0(options, info, frame, state, frame->base - 1);
    } else {
        FUN_002141d0(state);
    }
    if (strchr(options, 'f')) {
        if ((int)((char *)state->limit - (char *)state->top) <= 8)
            FUN_00215460(state, 1);
        state->top += 1;
    }
    return result;
}
