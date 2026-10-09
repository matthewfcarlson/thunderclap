typedef unsigned int u32;
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(u32, u32);
};
void __stdcall FUN_001c2550(Obj*, u32);
struct Owner {
    char pad[0xbc];
    u32 value;
    void helper(Obj*, u32);
    void target(Obj*, u32, u32);
};
void Owner::target(Obj* p, u32 a, u32 b) {
    if (p) {
        FUN_001c2550(p, b);
        helper(p, a);
        p->v8(value, 0);
    }
}