struct Manager {
    void FUN_002659a0(unsigned int);
};
extern Manager* DAT_00527c58;
void __cdecl FUN_0023f8c0(const char*);
void __cdecl thunk_FUN_00267090(void*);
struct Resource {
    virtual void slot0();
    virtual void release();
};
struct Holder {
    char pad[16];
    Resource* resource;
};
struct EnginePart {
    void FUN_001c5f20();
};
struct Owned {
    virtual void destroy(int);
};
struct Engine {
    char pad0[4];
    Owned* first;
    EnginePart* part;
    Owned* second;
    char pad10[4];
    Holder* holder14;
    Holder* holder18;
    char pad1c[0x52];
    unsigned char setup;
    void cleanup();
};
void Engine::cleanup() {
    DAT_00527c58->FUN_002659a0(0x60000700);
    if (!setup) {
        FUN_0023f8c0("Render engine not yet setup, cleanup aborted.");
        return;
    }
    FUN_0023f8c0("Render engine shutting down.\n");
    Holder* h = holder18;
    if (h) {
        Resource* r = h->resource;
        if (r)
            r->release();
        h->resource = 0;
        thunk_FUN_00267090(h);
    }
    h = holder14;
    holder18 = 0;
    if (h) {
        Resource* r = h->resource;
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
    Owned* o = second;
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
