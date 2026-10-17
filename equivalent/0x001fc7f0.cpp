// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 8/8)
// FUN_001fc7f0 @ 0x001fc7f0
struct Entry { char pad[8]; unsigned low; unsigned high; };
struct Table { char pad[12]; Entry* slots[128]; Entry* FUN_001fc7f0(unsigned value); };
unsigned __int64 __cdecl FUN_00096d80(unsigned value);
Entry* Table::FUN_001fc7f0(unsigned value)
{
    unsigned __int64 key = FUN_00096d80(value);
    for (int i = 0; i < 128; ++i) {
        Entry* entry = slots[i];
        if (entry && entry->low == (unsigned)key && entry->high == (unsigned)(key >> 32))
            return entry;
    }
    return 0;
}