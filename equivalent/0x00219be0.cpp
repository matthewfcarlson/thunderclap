// STATUS: equivalent (tools/equiv.py level 3: 2693 inputs, branch coverage 4/4)
// FUN_00219be0 @ 0x00219be0
#include "compat/ptr.h"
struct Entry { unsigned int value; unsigned int extra; };
struct Buffer { char pad[12]; Entry* entries; char reserved[12]; int count; };
extern "C" Entry* __cdecl FUN_0021add0(void* allocator, Entry* oldEntries, hulk_intptr oldBytes, hulk_intptr newBytes);
// equiv-conv: FUN_00219be0 esi edi stack
void __cdecl FUN_00219be0(Buffer* buffer, int newCount, void* allocator)
{
    buffer->entries = FUN_0021add0(allocator, buffer->entries, buffer->count * 8, newCount * 8);
    for (int i = buffer->count; i < newCount; ++i)
        buffer->entries[i].value = 0;
    buffer->count = newCount;
}