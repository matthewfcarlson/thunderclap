// FUN_00059d30 @ 0x00059d30
struct Buffer_59d30 {
    void FUN_0003b620(int arg);
    void FUN_00263e90();
};

class Resource_59d30 {
public:
    virtual void v0();
    virtual void Release();
    void FUN_00222b90(int arg);
};

struct Entry_59d30 {
    char pad0[0x10];
    Buffer_59d30 *buffer;
    char pad14[4];
    Resource_59d30 *resource;
    char pad1c[0x24 - 0x1c];
};

class EntryTable_59d30 {
public:
    void FUN_00059d30();

    char pad0[4];
    unsigned int count;
    Entry_59d30 *entries;
    char *used;
};

// Releases the buffer and resource of every entry that is marked used.
void EntryTable_59d30::FUN_00059d30() {
    for (unsigned int i = 0; i < count; i++) {
        if (used[i]) {
            Entry_59d30 *e = &entries[i];
            if (e->buffer != 0) {
                e->buffer->FUN_0003b620(0);
                e->buffer->FUN_00263e90();
                e->buffer = 0;
            }
            if (e->resource != 0) {
                e->resource->FUN_00222b90(1);
                if (e->resource != 0) {
                    e->resource->Release();
                    e->resource = 0;
                }
            }
            used[i] = 0;
        }
    }
}
