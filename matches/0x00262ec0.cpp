class C {
    char pad[0x10];
};
extern void __fastcall f(void*);
void __fastcall target(C* self) {
    f((char*)self + 0x10);
    f((char*)self + 4);
}