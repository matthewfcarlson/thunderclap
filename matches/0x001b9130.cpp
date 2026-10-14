class X_1b9130 {
  public:
    void f();
};
X_1b9130* __stdcall FUN_001c3d90(float, int, int, int, int, int);
void __stdcall FUN_001b9130(int param_1) {
    X_1b9130* p = FUN_001c3d90(1.0f, 0, 0, 1, param_1, 0);
    p->f();
}