struct Button {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void apply(void* data);
};
struct Container {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int count(const char* name);
    virtual Button* get(const char* name, int index);
};
void __cdecl thunk_FUN_00267090(void*);
struct Object {
    char pad0[0x10];
    Container* container;
    char pad14[0x40];
    int state;
    char pad58[0x450];
    void** data;
    void FUN_000b0e20();
};
void Object::FUN_000b0e20() {
    if (state == 2 || !container || !data)
        return;
    int n = container->count("Button");
    for (int i = 0; i < n; ++i) {
        Button* button = container->get("Button", i);
        if (button && data[i])
            button->apply(data[i]);
    }
    if (data) {
        for (int i = 0; i < n; ++i) {
            if (data[i]) {
                thunk_FUN_00267090(data[i]);
                data[i] = 0;
            }
        }
    }
    if (data) {
        thunk_FUN_00267090(data);
        data = 0;
    }
}
