// STATUS: equivalent (tools/equiv.py level 3: 108 inputs, branch coverage 11/12, incomplete)
// FUN_00046140 @ 0x00046140
// FUN_00046140: destroy every entry whose key matches
typedef unsigned __int64 u64;

struct Entry {
    virtual void v0();
    virtual void Release();
    char pad04[0x3b0 - 4];
    char key[8];
    void FUN_00044430();
};

class Registry {
public:
    char pad00[0xc];
    int count;
    Entry **entries;

    void FUN_00046140(void *name);
};

u64 __cdecl FUN_0027b020(void *p);

void Registry::FUN_00046140(void *name)
{
    u64 key = FUN_0027b020(name);
    for (int i = 0; i < count; i++) {
        if (entries[i] != 0 && FUN_0027b020(entries[i]->key) == key) {
            entries[i]->FUN_00044430();
            Entry *e = entries[i];
            if (e != 0) {
                e->Release();
                entries[i] = 0;
            }
            entries[i] = 0;
        }
    }
}
