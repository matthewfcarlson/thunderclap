// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0026bbe0 @ 0x0026bbe0
// FUN_0026bbe0 @ 0x0026bbe0
#include "decls/data/engine/core.h"

struct MemoryStats { unsigned int systemBytes; char pad04[12]; unsigned int inUseBytes; unsigned int maxSystemBytes; char pad18[4]; unsigned int otherBytes; char pad20[8]; };
extern MemoryStats* __cdecl FUN_0026bac0(MemoryStats* stats);
extern int __cdecl _fwprintf(void* stream, const char* format, ...);
void __cdecl FUN_0026bbe0()
{
    MemoryStats output;
    MemoryStats stats = *FUN_0026bac0(&output);
    _fwprintf(((char*)&DAT_004d9a30), "max system bytes = %10u\n", stats.maxSystemBytes);
    _fwprintf(((char*)&DAT_004d9a30), "system bytes     = %10u\n", stats.systemBytes + stats.inUseBytes);
    _fwprintf(((char*)&DAT_004d9a30), "in use bytes     = %10u\n", stats.otherBytes + stats.inUseBytes);
}
