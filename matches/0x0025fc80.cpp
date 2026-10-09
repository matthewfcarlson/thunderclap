typedef unsigned int u32;
void __cdecl f(void*);
struct Obj {
    char pad[0x14];
};
void __fastcall target(Obj* self, void*) {
    f((char*)self + 0x14);
}