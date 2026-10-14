typedef unsigned int u32_36e40;
struct Obj_36e40 {
    char pad[0x2158];
    u32_36e40 values[1];
    int FUN_00036d90(u32_36e40 value);
    u32_36e40 target(u32_36e40 arg);
};
u32_36e40 Obj_36e40::target(u32_36e40 arg) {
    int i = FUN_00036d90(arg);
    if (i < 0)
        return 0;
    return *(u32_36e40*)((char*)this + 0x2158 + i * 16);
}