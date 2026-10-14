// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_001f57e0 @ 0x001f57e0
extern "C" char DAT_004c7eb4[];
extern "C" char DAT_004c7ed4[];
extern void* __cdecl FUN_00344e74(void*, int, const char*, const char*, int);

struct Pair {
    unsigned int lo;
    unsigned int hi;
};

struct Inner {
    char pad0[8];
    Pair value;             // 0x08
};

struct Found {
    char pad0[8];
    Inner* inner;           // 0x08
};

struct List;
struct Item;

Item* __cdecl FUN_002495c0(List* list);
void* __cdecl FUN_002495f0(Item* item);
void* __cdecl FUN_00249610(List* list, void* key);
Item* __cdecl FUN_002495e0(List* list, Item* item);

class Registry {
public:
    int f00;
    List* list;             // 0x04
    unsigned __int64 FUN_001f57e0();
};

// Walks the list for the first entry that casts to the wanted type and returns its pair.
unsigned __int64 Registry::FUN_001f57e0()
{
    if (list == 0)
        return 0;
    for (Item* item = FUN_002495c0(list); item; item = FUN_002495e0(list, item)) {
        void* key = FUN_002495f0(item);
        if (key) {
            Found* f = (Found*)FUN_00344e74(FUN_00249610(list, key), 0, DAT_004c7eb4, DAT_004c7ed4, 0);
            if (f) {
                union {
                    Pair pair;
                    unsigned __int64 packed;
                } r;
                r.pair = f->inner->value;
                return r.packed;
            }
        }
    }
    return 0;
}
