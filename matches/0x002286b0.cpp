struct Vec3 { unsigned int a, b, c; };
extern unsigned int g0, g1, g2;
extern void __cdecl FUN_00224d70(unsigned int, Vec3*);
struct Obj { char pad[0x8ac]; unsigned int value; Vec3 Get(); };
Vec3 Obj::Get() {
    Vec3 local;
    local.a = g0;
    local.b = g1;
    local.c = g2;
    FUN_00224d70(value, &local);
    return local;
}
