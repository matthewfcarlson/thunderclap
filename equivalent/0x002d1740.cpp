// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002d1740 @ 0x002d1740
struct Lookup { char pad0[0x24]; unsigned *values; signed char *highBytes; };
struct Root { char pad0[0x1bc]; Lookup *lookup; };
struct Result { char pad0[0xc]; unsigned value; char pad1[8]; unsigned char secondFlag; char pad2[0x25]; unsigned char firstFlag; };
unsigned * __cdecl FUN_002e6780(Root **root, unsigned packed, unsigned flag);
unsigned * __cdecl FUN_002e6840(Root **root, unsigned value, unsigned flag);
void __cdecl FUN_002d1740(int unused, int index, Root *root, Result *result) {
    Lookup *lookup = root->lookup;
    unsigned packed = (lookup->values[index] & 0xffffff) | ((unsigned)lookup->highBytes[index] << 24);
    unsigned value = *FUN_002e6780(&root, packed, result->firstFlag);
    result->value = *FUN_002e6840(&root, value, result->secondFlag);
}