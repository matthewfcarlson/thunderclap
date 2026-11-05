// STATUS: equivalent (tools/equiv.py level 3: 19904 inputs, branch coverage 0/0)
// FUN_002209b0 @ 0x002209b0
// FUN_002209b0 @ 0x002209b0
// FUN_002209b0 @ 0x002209b0
#include "compat/ptr.h"
struct Args { int kind; int value; };
// equiv-conv: FUN_002208e0 ebx ecx stack
int __cdecl FUN_002208e0(int fs, Args *k, Args *v);
int __cdecl FUN_002209b0(hulk_intptr unused, int value)
{
    Args args;
    args.kind = 4;
    args.value = value;
    return FUN_002208e0(unused, &args, &args);
}
