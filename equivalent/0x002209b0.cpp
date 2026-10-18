// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// FUN_002209b0 @ 0x002209b0
// FUN_002209b0 @ 0x002209b0
struct Args { int kind; int value; };
int __cdecl FUN_002208e0(Args *);
int __cdecl FUN_002209b0(int unused, int value)
{
    Args args;
    args.kind = 4;
    args.value = value;
    return FUN_002208e0(&args);
}
