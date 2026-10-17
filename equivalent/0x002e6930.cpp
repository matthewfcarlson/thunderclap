// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e6930 @ 0x002e6930
#include "decls/data/engine/core.h"

struct FILE_TYPE { char unused; };
extern "C" int __cdecl _fwprintf(FILE_TYPE *, const char *);
extern "C" void __cdecl _longjmp(void *, int);
void __cdecl FUN_002e6930(void *jumpBuffer)
{
    _fwprintf(((FILE_TYPE*)&DAT_004d9a30), "libpng error: %s\n");
    _longjmp(jumpBuffer, 1);
}