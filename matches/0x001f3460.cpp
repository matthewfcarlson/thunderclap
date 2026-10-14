typedef unsigned int u32_1f3460;
struct Target_1f3460 {
    char pad[4];
    void* value;
};
struct Pair_1f3460 {
    u32_1f3460 a;
    u32_1f3460 b;
};
extern void __cdecl FUN_00249a90(void*, Pair_1f3460*);
extern void __cdecl FUN_0024a800(void*, u32_1f3460);
void __fastcall FUN_001f3460(Target_1f3460* self, void*) {
    Pair_1f3460 p;
    p.a = 0;
    p.b = 0xfa;
    FUN_00249a90(self->value, &p);
    FUN_0024a800(self->value, 0x32);
}