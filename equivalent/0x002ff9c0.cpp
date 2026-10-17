// STATUS: equivalent (tools/equiv.py level 3: 144 inputs, branch coverage 4/4)
// FUN_002ff9c0 @ 0x002ff9c0
struct Entry { char pad[0x50]; unsigned char active; char rest[0x1b]; };
struct Object {
    Entry *entries;
    char pad[4];
    unsigned int *first;
    unsigned int *last;
    void FUN_002ff9c0();
};
void Object::FUN_002ff9c0() {
    for (unsigned int i = 0; i < (unsigned int)(last - first); ++i)
        entries[first[i]].active = 0;
    last = first;
}