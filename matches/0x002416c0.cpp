typedef unsigned int u32_2416c0;
struct Obj_2416c0 {
    char pad0[0x28];
    u32_2416c0 value;
    char pad2[8];
    int state;
};
void __cdecl FUN_002416c0(u32_2416c0 a, Obj_2416c0* obj, u32_2416c0 value) {
    if (obj->state != 0) {
        obj->state = 3;
        obj->value = value;
    }
}