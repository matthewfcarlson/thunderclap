struct Manager_1c4230 {
    void FUN_002659a0(unsigned int);
};
extern Manager_1c4230* DAT_00527c58;
void __cdecl FUN_0023f8c0(const char*);
void __cdecl thunk_FUN_00267090(void*);
struct Resource_1c4230 {
    virtual void slot0();
    virtual void release();
};
struct Holder_1c4230 {
    char pad[16];
    Resource_1c4230* resource;
};
struct EnginePart {
    void FUN_001c5f20();
};
struct Owned_1c4230 {
    virtual void destroy(int);
};
struct Engine_1c4230 {
    char pad0[4];
    Owned_1c4230* first;
    EnginePart* part;
    Owned_1c4230* second;
    char pad10[4];
    Holder_1c4230* holder14;
    Holder_1c4230* holder18;
    char pad1c[0x52];
    unsigned char setup;
    void cleanup();
};
void Engine_1c4230::cleanup() {
    DAT_00527c58->FUN_002659a0(0x60000700);
    if (!setup) {
        FUN_0023f8c0("Render engine not yet setup, cleanup aborted.");
        return;
    }
    FUN_0023f8c0("Render engine shutting down.\n");
    Holder_1c4230* h = holder18;
    if (h) {
        Resource_1c4230* r = h->resource;
        if (r)
            r->release();
        h->resource = 0;
        thunk_FUN_00267090(h);
    }
    h = holder14;
    holder18 = 0;
    if (h) {
        Resource_1c4230* r = h->resource;
        if (r)
            r->release();
        h->resource = 0;
        thunk_FUN_00267090(h);
    }
    EnginePart* p = part;
    holder14 = 0;
    if (p) {
        p->FUN_001c5f20();
        thunk_FUN_00267090(p);
    }
    Owned_1c4230* o = second;
    part = 0;
    if (o)
        o->destroy(1);
    o = first;
    second = 0;
    if (o)
        o->destroy(1);
    first = 0;
    FUN_0023f8c0("Render engine cleanup done.\n");
    setup = 0;
}
