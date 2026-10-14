struct T_24bb0 {
    char pad[0x2c0];
    int value;
};
T_24bb0* __stdcall FUN_000678d0();
void __stdcall FUN_00024bb0(int arg) {
    T_24bb0* p = FUN_000678d0();
    p->value = arg;
}
