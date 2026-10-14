class C_262ec0 {
    char pad[0x10];
};
extern void __fastcall f(void*);
void __fastcall target(C_262ec0* self) {
    f((char*)self + 0x10);
    f((char*)self + 4);
}