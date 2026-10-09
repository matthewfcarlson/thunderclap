class X { public: void f(); };
X* __stdcall FUN_001c3d90(float, int, int, int, int, int);
void __stdcall FUN_001b9130(int param_1) {
    X* p = FUN_001c3d90(1.0f, 0, 0, 1, param_1, 0);
    p->f();
}