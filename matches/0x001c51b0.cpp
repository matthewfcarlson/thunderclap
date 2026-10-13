struct Data {
    char pad[0x74];
    void* field74;
};
struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void* v15();
    Data* FUN_001d72e0();
};
struct Render {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(int);
    virtual int v16(int);
    virtual void v17(int, void*);
};
extern Render** DAT_0052c2ac;
struct Parent {
    char pad[0x23];
    unsigned char flag;
};
struct Owner;
struct Context {
    void FUN_001c25c0(Item*, Owner*, float);
};
struct Owner {
    char p0[0x10];
    Item* fallback;
    char p14[4];
    Parent* parent;
    Item* item;
    char p20[2];
    unsigned char enabled;
    char p23[0x0d];
    char state[0x50];
    float a;
    char p84[0x0c];
    float b;
    int target(Context* context);
};
int Owner::target(Context* context) {
    (*DAT_0052c2ac)->v15(0);
    if (!parent || parent->flag)
        (*DAT_0052c2ac)->v17(0, state);
    if (enabled && item) {
        if (!item->FUN_001d72e0() || !item->FUN_001d72e0()->field74) {
            void* value = item->v15();
            (*DAT_0052c2ac)->v17(0, value);
        }
        float value = a < b ? b : a;
        context->FUN_001c25c0(item, this, value);
    } else {
        float value = a < b ? b : a;
        context->FUN_001c25c0(fallback, this, value);
    }
    return (*DAT_0052c2ac)->v16(0);
}