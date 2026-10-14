// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 28/28)
// FUN_001a4e40 @ 0x001a4e40
extern "C" unsigned int strlen(const char *);

struct Entry_1a4e40 {
    const char *name;
    int pad[3];
};

struct Table_1a4e40 {
    char pad0[0x5c];
    Entry_1a4e40 entries[20];
};

const char *FUN_001a4e40(Table_1a4e40 *table, unsigned int index)
{
    if (index > 0x13)
        return 0;
    const char *name = table->entries[index].name;
    if (name == 0)
        return 0;
    if (strlen(name) < 2)
        return 0;
    return name;
}
