// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033c6e0 @ 0x0033c6e0
struct CaptureEntry { int value; int auxiliary; };
struct CaptureState { char reserved[8]; void *context; int count; CaptureEntry captures[32]; };
void __cdecl FUN_00338e20(void *, const char *);
int __cdecl FUN_0033c7e0(CaptureState *, int, int);
// equiv-conv: FUN_0033c6e0 esi ebx stack stack
void FUN_0033c6e0(CaptureState *state, int value, int arg1, int arg2)
{
    int index = state->count;
    if (index >= 32)
        FUN_00338e20(state->context, "too many captures");
    state->captures[index].value = value;
    state->captures[index].auxiliary = arg2;
    state->count = index + 1;
    if (!FUN_0033c7e0(state, value, arg1))
        --state->count;
}
