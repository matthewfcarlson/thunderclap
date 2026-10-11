// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 28/28)
// FUN_001a4cb0 @ 0x001a4cb0
extern "C" unsigned int strlen(const char *);
struct Entry {
    const char *name;
    char pad[12];
};
struct Table {
    char pad0[0x60];
    Entry entries[20];
};
const char *FUN_001a4cb0(Table *t, unsigned int idx)
{
    const char *s = 0;
    if (idx < 20)
        s = t->entries[idx].name;
    if (s != 0 && strlen(s) < 2)
        s = 0;
    return s;
}
