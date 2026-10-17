// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f0b30 @ 0x000f0b30
extern void __cdecl FUN_000fb1c0(int);
struct Context { unsigned int entries[512]; unsigned int extra[10]; void FUN_000f9d20(); };
void __stdcall FUN_000f0b30(int value)
{
    Context context = {0};
    FUN_000fb1c0(value);
    context.FUN_000f9d20();
}
