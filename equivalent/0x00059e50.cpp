// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 14/14)
// FUN_00059e50 @ 0x00059e50
struct Effect_59e50 {
    void FUN_00222b90(int arg);
    virtual void vfunc_0();
    virtual void vfunc_1();     // release
};

struct Buffer_59e50 {
    void FUN_0003b620(int arg);
    void FUN_00263e90();
};

struct Entry_59e50 {
    void *key;              // 0x00
    char pad04[0xc];
    Buffer_59e50 *buffer;         // 0x10
    char pad14[4];
    Effect_59e50 *effect;         // 0x18
    char pad1c[8];
};

class EntryTable_59e50 {
public:
    char pad00[4];
    unsigned int count;     // 4
    Entry_59e50 *entries;         // 8
    char *used;             // 0xc
    void FUN_00059e50(void *key);
};

void EntryTable_59e50::FUN_00059e50(void *key)
{
    for (unsigned int i = 0; i < count; i++) {
        if (used[i] && entries[i].key == key) {
            Entry_59e50 *e = &entries[i];
            if (e->buffer != 0) {
                e->buffer->FUN_0003b620(0);
                e->buffer->FUN_00263e90();
                e->buffer = 0;
            }
            if (e->effect != 0) {
                e->effect->FUN_00222b90(1);
                if (e->effect != 0) {
                    e->effect->vfunc_1();
                    e->effect = 0;
                }
            }
            used[i] = 0;
            return;
        }
    }
}
