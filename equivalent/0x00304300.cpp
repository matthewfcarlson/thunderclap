// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00304300 @ 0x00304300
#include "decls/data/engine/unknown.h"

struct Buffer { void* begin; void* end; void* capacity; Buffer* FUN_00304300(); };  extern void* __cdecl FUN_0008d6d0(int); Buffer* Buffer::FUN_00304300() { begin = 0; end = 0; capacity = 0; if (DAT_004d2f80 != 0) { int bytes = DAT_004d2f80 * 0x44; begin = FUN_0008d6d0(bytes); if (begin != 0) { capacity = (char*)begin + bytes; end = begin; return this; } } begin = 0; end = 0; capacity = 0; return this; }