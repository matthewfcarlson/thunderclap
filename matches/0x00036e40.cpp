typedef unsigned int u32;
struct Obj {
    char pad[0x2158];
    u32 values[1];
    int FUN_00036d90(u32 value);
    u32 target(u32 arg);
};
u32 Obj::target(u32 arg) {
    int i = FUN_00036d90(arg);
    if (i < 0)
        return 0;
    return *(u32*)((char*)this + 0x2158 + i * 16);
}