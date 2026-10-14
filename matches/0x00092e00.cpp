class Obj {
  public:
    void FUN_00092870(int a);
    void FUN_00092e00(int a, int b);
};

void __stdcall Helper(int a, int b);

void Obj::FUN_00092e00(int a, int b) {
    if (a >= 0 && a < 0x2fe) {
        a = a;
        Helper(a, b);
    }
}
