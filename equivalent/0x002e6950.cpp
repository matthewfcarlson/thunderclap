// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002e6950 @ 0x002e6950
#include "decls/data/engine/core.h"

struct File;
extern "C" int __cdecl FID_conflict__fwprintf(File *, const char *);
// equiv-conv: FUN_002e6950 eax
void FUN_002e6950(const char *message)
{
    FID_conflict__fwprintf(((File*)&DAT_004d9a30), "libpng warning: %s\n");
}
