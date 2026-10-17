// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002209b0 @ 0x002209b0
struct Args { int kind; int value; };
void __cdecl FUN_002208e0(Args *);
void __cdecl FUN_002209b0(int unused, int value)
{
    Args args;
    args.kind = 4;
    args.value = value;
    FUN_002208e0(&args);
}