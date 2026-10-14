typedef unsigned int u32_213fb0;
struct Obj_213fb0 {
    char pad[0x34];
    u32_213fb0 value;
};
u32_213fb0 __cdecl target(Obj_213fb0* p) {
    return p->value;
}