// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 10/10)
// FUN_001dd890 @ 0x001dd890
struct Node { char pad0[0x14c]; unsigned char enabled; };
struct Entry { char pad0[0x18]; Node* node; char pad1[6]; short slot; char pad2[4]; };
struct Flag { char pad[0x10]; unsigned char bits; char rest[3]; };
struct Owner { char pad0[0x608]; Entry entries[0x800]; Flag flags[1]; void FUN_001dd890(int index, unsigned char value); };
void Owner::FUN_001dd890(int index, unsigned char value) {
    if (index < 0 || index >= 0x800) return;
    Entry& entry = entries[index];
    Flag& flag = flags[entry.slot];
    if (value) flag.bits |= 0x10;
    else flag.bits &= 0xef;
    if ((flag.bits & 1) && entry.node) entry.node->enabled = value;
}