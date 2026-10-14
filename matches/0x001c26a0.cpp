typedef unsigned int u32_1c26a0;
struct Obj_1c26a0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(u32_1c26a0, u32_1c26a0);
};
void __stdcall FUN_001c2550(Obj_1c26a0*, u32_1c26a0);
struct Owner_1c26a0 {
    char pad[0xbc];
    u32_1c26a0 value;
    void helper(Obj_1c26a0*, u32_1c26a0);
    void target(Obj_1c26a0*, u32_1c26a0, u32_1c26a0);
};
void Owner_1c26a0::target(Obj_1c26a0* p, u32_1c26a0 a, u32_1c26a0 b) {
    if (p) {
        FUN_001c2550(p, b);
        helper(p, a);
        p->v8(value, 0);
    }
}