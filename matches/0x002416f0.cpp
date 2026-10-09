typedef unsigned int u32;
struct Obj {
    char pad[0x34];
    u32 field;
};
extern "C" u32 FUN_002416f0(void* unused, Obj* obj) {
    return obj->field;
}