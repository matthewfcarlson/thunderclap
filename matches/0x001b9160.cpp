struct Obj {
    void method();
};
Obj* __stdcall FUN_001c3d90(int a, int b, int c, int d);
void __stdcall FUN_001b9160(int param_1) {
    FUN_001c3d90(0, 0, 1, param_1)->method();
}