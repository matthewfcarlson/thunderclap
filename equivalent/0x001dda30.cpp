// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001dda30 @ 0x001dda30
struct Entry { char pad[17]; unsigned char flags; char rest[2]; };
struct Mapping { short entry; char rest[38]; };
struct Object { char pad[0x62a]; union { Mapping mappings[0x800]; struct { char gap[0x14608-0x62a]; Entry entries[1]; } table; } fields; unsigned char FUN_001dda30(int index, unsigned char enabled); };
unsigned char Object::FUN_001dda30(int index, unsigned char enabled) {
    if (index < 0 || index >= 0x800) return 0;
    Entry &entry = fields.table.entries[fields.mappings[index].entry];
    if (enabled) entry.flags |= 0x10;
    else entry.flags &= 0xef;
    return 1;
}