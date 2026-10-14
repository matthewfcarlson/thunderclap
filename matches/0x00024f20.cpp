struct Obj_24f20 {
    char pad[0x368];
    int m;
};
extern "C" Obj_24f20* __stdcall FUN_000678d0();
void __stdcall FUN_00024f20(int x) {
    Obj_24f20* p = FUN_000678d0();
    p->m = x;
}
