struct A_1c3cb0 {
    char pad[0x14];
    void* m;
};
extern "C" void __fastcall FUN_001c4500(void*);
extern "C" void __fastcall FUN_001c3cb0(A_1c3cb0* self) {
    FUN_001c4500(self->m);
}