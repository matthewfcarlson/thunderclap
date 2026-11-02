// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 6/6)
// FUN_00220480 @ 0x00220480
// equiv-conv: FUN_00220310 eax
#include "decls/data/engine/unknown.h"
#include "compat/ptr.h"

extern "C" void __cdecl FUN_00220310(void *);
extern "C" void * __cdecl FUN_00220050(void *, void *);
struct Arguments { unsigned int first, second, third; const char *text; };
void __cdecl FUN_00220480(unsigned int a, unsigned int b, unsigned int c, const char *text)
{
    Arguments args;
    if (*text == '@' || *text == '=') args.text = text + 1;
    else if (*text == '\x1b') args.text = DAT_004271a8;
    else args.text = text;
    args.first = a;
    args.second = b;
    args.third = c;
    FUN_00220310(&args);
    FUN_00220050(&args, (void *)(hulk_uintptr)(int)0);
}