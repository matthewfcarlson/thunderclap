typedef unsigned int u32_1c9a20;
struct Obj_1c9a20 {
    u32_1c9a20 pad;
    u32_1c9a20 target(u32_1c9a20);
};
struct ThisCall_001c9750 {
    void FUN_001c9750(int, int, u32_1c9a20);
};
u32_1c9a20 Obj_1c9a20::target(u32_1c9a20 param) {
    ((ThisCall_001c9750*)(this))->FUN_001c9750(2, 0xb0, param);
    return (u32_1c9a20)this;
}