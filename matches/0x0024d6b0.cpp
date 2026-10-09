extern void __stdcall FUN_002584d0(void*, void*, void*, int);
class X {
  public:
    int m;
    X();
};
X::X() {
    FUN_002584d0((void*)0x4e6338, (void*)0x4e6330, (void*)0x30, 4);
    m = 0x429440;
}