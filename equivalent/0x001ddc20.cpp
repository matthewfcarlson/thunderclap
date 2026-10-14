// STATUS: equivalent (tools/equiv.py level 3: 3020 inputs, branch coverage 14/14)
// FUN_001ddc20 @ 0x001ddc20
// FUN_001ddc20: set a mode on the object of a keyed slot from the first letter of a string
struct Obj {
    char pad00[0x198];
    int mode;
};

struct Slot {
    char pad00[0x10];
    unsigned char flags;
    char pad11[3];
};

struct Entry {
    char pad00[0x18];
    Obj *obj;
    char pad1c[6];
    short slot;
    char pad24[4];
};

extern "C" int __cdecl FUN_00345475(int c);

class Manager {
public:
    char pad00[0x608];
    Entry entries[0x800];
    Slot slots[1];

    int FUN_001dbfe0(int key);
    void FUN_001ddc20(int key, const char *name);
};

void Manager::FUN_001ddc20(int key, const char *name)
{
    int i = FUN_001dbfe0(key);
    if (i < 0)
        return;
    Entry *e = &entries[i];
    if (!(slots[e->slot].flags & 1))
        return;
    if (e->obj == 0)
        return;
    int mode = 0;
    if (name != 0) {
        switch (FUN_00345475(*name)) {
        case 'b':
            mode = 2;
            break;
        case 'e':
            mode = 3;
            break;
        case 'g':
            mode = 1;
            break;
        }
    }
    e->obj->mode = mode;
}
