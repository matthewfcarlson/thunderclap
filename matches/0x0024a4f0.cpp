typedef unsigned int uint;
struct Obj {
    char pad[0x14];
};
void __cdecl FUN_0024a450(void*);
void __cdecl FUN_0024a4a0(Obj*);
void __fastcall FUN_0024a4f0(Obj* self) {
    FUN_0024a450((char*)self + 0x14);
    FUN_0024a4a0(self);
}