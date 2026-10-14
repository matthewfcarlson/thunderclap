struct Item_ec250 {
    char pad[0xab8];
    unsigned char active;
};
struct Lookup_ec250 {
    Item_ec250* FUN_000e6410(const char*);
};
struct ContextInner_ec250 {
    char pad[4];
    Lookup_ec250* lookup;
};
struct Context {
    char pad[8];
    ContextInner_ec250* inner;
};
struct Receiver_ec250 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual unsigned char slot4(int, int, int, int);
};
struct SelectionSink {
    void FUN_000f8b90(int);
};
struct MenuSelector {
    virtual void vfunc_0();
    char pad04[0x10];
    Context* context;
    char pad18[0x90];
    int id;
    char padac[0x6c];
    Receiver_ec250* receivers[10];
    char pad140[0x14];
    int selected;
    char pad158[0x1c00];
    int count;
    char pad1d5c[0x38];
    SelectionSink* sink;
    char pad1d98[0x11];
    char names[1][64];
    void vfunc_25(int index);
};
void MenuSelector::vfunc_25(int index) {
    context->inner->lookup->FUN_000e6410(names[selected])->active = 0;
    context->inner->lookup->FUN_000e6410(names[index])->active = 1;
    int next = (index + 1) % count;
    for (int i = 0; i < 10 && receivers[i]; ++i) {
        if (receivers[i]->slot4(4, id, next, index))
            receivers[i]->slot1();
    }
    SelectionSink* currentSink = sink;
    selected = index;
    if (currentSink)
        currentSink->FUN_000f8b90(index);
    vfunc_0();
}
