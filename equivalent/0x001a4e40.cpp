// STATUS: equivalent (tools/equiv.py level 3: 20054 inputs, branch coverage 28/28)
// FUN_001a4e40 @ 0x001a4e40
#include "compat/ptr.h"
static inline hulk_uintptr strlen_inline(const char *s)
{
    const char *p = s;
    while (*p)
        p++;
    return p - s;
}

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
    if (strlen_inline(name) < 2)
        return 0;
    return name;
}
