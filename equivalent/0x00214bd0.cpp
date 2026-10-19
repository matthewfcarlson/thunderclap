// STATUS: equivalent (tools/equiv.py level 3: 12294 inputs, branch coverage 10/10)
// FUN_00214bd0 @ 0x00214bd0
// FUN_00214bd0 @ 0x00214bd0
struct Value_214bd0 { int type; unsigned int data; };
struct CallInfo_214bd0 { Value_214bd0 *base; char pad[12]; };
struct State_214bd0 { char pad0[8]; Value_214bd0 *top; char pad1[12]; Value_214bd0 *limit; char pad2[12]; CallInfo_214bd0 *frames; };
struct DebugInfo_214bd0 { char pad[0x5c]; unsigned int frameIndex; };
extern void __cdecl FUN_00214a90(State_214bd0 *, const char *);
// equiv-conv: FUN_00214ac0 eax esi edi stack stack
extern int __cdecl FUN_00214ac0(const char *, DebugInfo_214bd0 *, CallInfo_214bd0 *, State_214bd0 *, Value_214bd0 *);
// equiv-conv: FUN_002141d0 esi stack
extern void __cdecl FUN_002141d0(DebugInfo_214bd0 *, State_214bd0 *);
extern void __cdecl FUN_00215460(State_214bd0 *, int);
extern "C" char * __cdecl strchr(const char *, int);
int __cdecl FUN_00214bd0(State_214bd0 *state, const char *options, DebugInfo_214bd0 *info)
{
    int result = 1;
    if (*options == '>') {
        Value_214bd0 *value = state->top - 1;
        if (value->type != 6)
            FUN_00214a90(state, "value for `lua_getinfo' is not a function");
        result = FUN_00214ac0(options + 1, info, 0, state, value);
        state->top -= 1;
    } else if (info->frameIndex != 0) {
        CallInfo_214bd0 *frame = state->frames + info->frameIndex;
        result = FUN_00214ac0(options, info, frame, state, frame->base - 1);
    } else {
        FUN_002141d0(info, state);
    }
    if (strchr(options, 'f')) {
        if ((int)((char *)state->limit - (char *)state->top) <= 8)
            FUN_00215460(state, 1);
        state->top += 1;
    }
    return result;
}
