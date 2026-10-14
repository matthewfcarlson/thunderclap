typedef unsigned int u32_2416f0;
struct Obj_2416f0 {
    char pad[0x34];
    u32_2416f0 field;
};
extern "C" u32_2416f0 FUN_002416f0(void* unused, Obj_2416f0* obj) {
    return obj->field;
}