// STATUS: equivalent (tools/equiv.py level 3: 1862 inputs, branch coverage 12/12)
// FUN_00046140 @ 0x00046140
// FUN_00046140: destroy every entry whose key matches
typedef unsigned __int64 u64_46140;

struct Entry_46140 {
    virtual void v0();
    virtual void Release();
    char pad04[0x3b0 - 4];
    char key[8];
    void FUN_00044430();
};

class Registry_46140 {
public:
    char pad00[0xc];
    int count;
    Entry_46140 **entries;

    void FUN_00046140(void *name);
};

u64_46140 __cdecl FUN_0027b020(void *p);

void Registry_46140::FUN_00046140(void *name)
{
    u64_46140 key = FUN_0027b020(name);
    for (int i = 0; i < count; i++) {
        if (entries[i] != 0 && FUN_0027b020(entries[i]->key) == key) {
            entries[i]->FUN_00044430();
            Entry_46140 **slot = entries + i;
            Entry_46140 *e = *slot;
            if (e != 0) {
                e->Release();
                *slot = 0;
            }
            entries[i] = 0;
        }
    }
}
