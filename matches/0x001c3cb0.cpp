struct A_1c3cb0 {
    char pad[0x14];
    void* m;
};
extern "C" int __fastcall FUN_001c4500(void*);
extern "C" int __fastcall FUN_001c3cb0(A_1c3cb0* self) {
    return FUN_001c4500(self->m);
}