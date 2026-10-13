extern int __cdecl FUN_00266da0(int);
extern void __cdecl FUN_0023f8c0(const char*);
extern void* __cdecl FUN_0008d690(unsigned int);
extern void* __cdecl thunk_FUN_0008d690(unsigned int);
struct Engine {
    Engine* FUN_001c9030();
};
struct Small {
    Small* FUN_001c5f10();
};
struct Medium {
    Medium* FUN_001c5840();
};
struct Owner;
struct Registration {
    Registration* FUN_001c8f60(Engine*, Owner*);
};
struct Item {
    char pad[12];
    unsigned char active;
    Item* FUN_001c49c0();
};
struct Manager {
    void FUN_00265210(Registration*, unsigned int);
};
extern Manager* DAT_00527c58;
struct Owner {
    void* context;
    Engine* engine;
    Small* small;
    Medium* medium;
    char pad10[4];
    Item* item14;
    Item* item18;
    char pad1c[0x52];
    unsigned char initialized;
    void FUN_001c35f0();
};
void Owner::FUN_001c35f0() {
    int previous = FUN_00266da0(15);
    if (initialized) {
        FUN_0023f8c0("Render engine already setup, setup aborted.\n");
        FUN_00266da0(previous);
        return;
    }
    FUN_0023f8c0("Starting render engine setup...\n");
    Engine* e = (Engine*)FUN_0008d690(0x768);
    engine = e ? e->FUN_001c9030() : 0;
    Small* s = (Small*)FUN_0008d690(0x10);
    small = s ? s->FUN_001c5f10() : 0;
    Medium* m = (Medium*)FUN_0008d690(0x250);
    medium = m ? m->FUN_001c5840() : 0;
    Registration* r = (Registration*)thunk_FUN_0008d690(0x20);
    r = r ? r->FUN_001c8f60(engine, (Owner*)context) : 0;
    DAT_00527c58->FUN_00265210(r, 0x60000700);
    FUN_0023f8c0("Render engine setup complete\n");
    Item* i = (Item*)FUN_0008d690(0x38);
    item18 = i ? i->FUN_001c49c0() : 0;
    i = (Item*)FUN_0008d690(0x38);
    item14 = i ? i->FUN_001c49c0() : 0;
    item14->active = 1;
    initialized = 1;
    FUN_00266da0(previous);
}
