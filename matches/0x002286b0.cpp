struct Vec3_2286b0 {
    unsigned int a, b, c;
};
extern unsigned int g0_2286b0, g1, g2;
extern void __cdecl FUN_00224d70(unsigned int, Vec3_2286b0*);
struct Obj_2286b0 {
    char pad[0x8ac];
    unsigned int value;
    Vec3_2286b0 Get();
};
Vec3_2286b0 Obj_2286b0::Get() {
    Vec3_2286b0 local;
    local.a = g0_2286b0;
    local.b = g1;
    local.c = g2;
    FUN_00224d70(value, &local);
    return local;
}
