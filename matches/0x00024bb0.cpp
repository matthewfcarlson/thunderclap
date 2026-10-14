struct T {
    char pad[0x2c0];
    int value;
};
T* __stdcall FUN_000678d0();
void __stdcall FUN_00024bb0(int arg) {
    T* p = FUN_000678d0();
    p->value = arg;
}
