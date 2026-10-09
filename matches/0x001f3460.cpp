typedef unsigned int u32;
struct Target { char pad[4]; void* value; };
struct Pair { u32 a; u32 b; };
extern void __cdecl FUN_00249a90(void*, Pair*);
extern void __cdecl FUN_0024a800(void*, u32);
void __fastcall FUN_001f3460(Target* self, void*) {
    Pair p;
    p.a = 0;
    p.b = 0xfa;
    FUN_00249a90(self->value, &p);
    FUN_0024a800(self->value, 0x32);
}