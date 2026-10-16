// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 40/42, incomplete)
// FUN_00092c80 @ 0x00092c80
#include "decls/address.h"
extern "C" int __cdecl FUN_00345804(const char *str, const char *fmt, ...);

struct Slot_92c80 {
    unsigned __int64 key;
    int chapter;
    int mission;
    int values[16];
};

class SlotTable_92c80 {
public:
    char pad0[0xd90];
    Slot_92c80 slots[32];
    void FUN_00092c80(const char *name, int value);
};

void SlotTable_92c80::FUN_00092c80(const char *name, int value)
{
    if (*name == 0)
        return;
    if (value < 0 || value >= 0x2fe)
        return;

    unsigned __int64 key = FUN_0027b020(name);
    int i = 0;
    while (slots[i].key != 0 && slots[i].key != key) {
        i++;
        if (i >= 32)
            return;
    }

    Slot_92c80 *s = &slots[i];
    s->key = key;
    if (FUN_00345804(name, "c%dm%d", &s->chapter, &s->mission) != 2)
        return;
    for (int j = 0; j < 16; j++) {
        if (s->values[j] == value)
            return;
        if (s->values[j] == -1) {
            s->values[j] = value;
            return;
        }
    }
}
