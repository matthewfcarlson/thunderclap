// STATUS: equivalent (tools/equiv.py level 3: 9159 inputs, branch coverage 18/18)
// FUN_001e9960 @ 0x001e9960
// cl-flags: /GS
#include "decls/address.h"
extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);

struct IdPair_1e9960 {
    unsigned int lo;
    unsigned int hi;
};

struct Resource_1e9960 {
    IdPair_1e9960 *FUN_00243390();
};

struct Slot_1e9960 {
    char pad00[8];
    Resource_1e9960 *resource;
};

class Registry_1e9960 {
public:
    char pad00[0x4c0];
    Slot_1e9960 *slots[20];
    int count;

    Slot_1e9960 *FUN_001e9960(const char *name);
};

// Looks a slot up by its resource name hashed with a ".Mix" suffix.
Slot_1e9960 *Registry_1e9960::FUN_001e9960(const char *name)
{
    struct Frame {
        char buf[0x20];
    } fr = { "" };
    Registry_1e9960 *self = this;
    if (!name || *name == 0) {
        return 0;
    }
    strcpy(fr.buf, name);
    strcat(fr.buf, ".Mix");
    for (int i = 0; i < count; i++) {
        if (slots[i]) {
            unsigned __int64 id = FUN_002672f0(fr.buf, 0, 0);
            IdPair_1e9960 *found = slots[i]->resource->FUN_00243390();
            if (found->lo == (unsigned int)id && found->hi == (unsigned int)(id >> 32)) {
                return self->slots[i];
            }
        }
    }
    return 0;
}
