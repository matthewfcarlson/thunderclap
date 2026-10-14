struct Obj {
    char pad[0x368];
    int m;
};
extern "C" Obj* __stdcall FUN_000678d0();
void __stdcall FUN_00024f20(int x) {
    Obj* p = FUN_000678d0();
    p->m = x;
}
