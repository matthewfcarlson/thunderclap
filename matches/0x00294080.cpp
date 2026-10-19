struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void slot();
};
struct State {
    char pad[8];
    int value;
};
extern State* state;
struct Owner {
    char pad[0x3c];
    Item* items[32];
    void func();
};
void Owner::func() {
    state->value = 0;
    for (int i = 0; i < 32; ++i) {
        if (items[i])
            items[i]->slot();
    }
}