// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0033cb10 @ 0x0033cb10
struct CaptureEntry { int start; int end; };
struct CaptureState { int base; int reserved; int context; int pad; CaptureEntry entries[1]; };
void __cdecl FUN_00338e20(int context, const char* message);
void __cdecl FUN_00213360(int context, int count);
void __cdecl FUN_00213380(int context, int start, int end);
// equiv-conv: FUN_0033cb10 eax esi
void FUN_0033cb10(int index, CaptureState* state)
{
    int end = state->entries[index].end;
    if (end == -1)
        FUN_00338e20(state->context, "unfinished capture");
    else if (end == -2) {
        FUN_00213360(state->context, state->entries[index].start - state->base + 1);
        return;
    }
    FUN_00213380(state->context, state->entries[index].start, end);
}