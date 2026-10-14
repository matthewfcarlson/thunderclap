typedef unsigned int u32_25fc80;
void __cdecl f(void*);
struct Obj_25fc80 {
    char pad[0x14];
};
void __fastcall target(Obj_25fc80* self, void*) {
    f((char*)self + 0x14);
}