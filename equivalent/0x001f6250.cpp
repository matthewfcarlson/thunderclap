// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 32/32)
// FUN_001f6250 @ 0x001f6250
struct Source { char pad0[4]; void *handle; };

struct Slot {
    unsigned __int64 stamp;
    int hash;
    char pad0c[0x28 - 0xc];
};

struct Params {
    int a;
    int b;
};

struct Item {
    char pad0[0x10];
    int active[4];
    Source *sources[4];
    char pad30[0x80 - 0x30];
    Slot slots[4];
};

struct Current {
    char pad0[0x10];
    Item *item;
    unsigned __int64 FUN_001f57e0();
};

unsigned __int64 __cdecl FUN_002672f0(int a, int b, int c);
int __cdecl FUN_002673a0(int a, int b);
int __cdecl FUN_0024a370(void *handle, int *hash);
void __cdecl FUN_00249bd0(void *handle, int x, Params *p);
char __cdecl FUN_00249b40(void *handle);

class Manager {
public:
    char FUN_001f6250(Item *item);
    void FUN_001f47b0(Item *item);

    char pad0[0x8c];
    Current *current;
};

char Manager::FUN_001f6250(Item *item)
{
    if (item == 0)
        return 0;

    if (current->item == item) {
        if (current->FUN_001f57e0() != 0)
            return 1;
        FUN_001f47b0(item);
    }

    for (int k = 0; k < 4; k++) {
        Slot *slot = &item->slots[k];
        if (slot->stamp != FUN_002672f0(0, 0, 0)) {
            for (int j = 0; j < 4; j++) {
                if (item->active[j] != 0) {
                    Source *src = item->sources[j];
                    if (src != 0) {
                        int x = FUN_0024a370(src->handle, &slot->hash);
                        if (x != 0) {
                            Params p;
                            p.a = 0;
                            p.b = 200;
                            FUN_00249bd0(src->handle, x, &p);
                        }
                    }
                }
            }
            slot->stamp = FUN_002672f0(0, 0, 0);
            slot->hash = FUN_002673a0(0, 0);
        }
    }

    if (item->sources[0] != 0 && item->sources[0]->handle != 0 && !FUN_00249b40(item->sources[0]->handle))
        return 1;
    if (item->sources[1] != 0 && item->sources[1]->handle != 0 && !FUN_00249b40(item->sources[1]->handle))
        return 1;
    return 0;
}
