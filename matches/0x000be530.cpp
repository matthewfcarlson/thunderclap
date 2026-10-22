class Function {
  public:
    virtual void f0();
    virtual void f1();
};
class Function0_be530 : public Function {
  public:
    virtual void f0();
    virtual void f2(int, int, int);
    char pad[0x18];
    void(__cdecl* mFn)();
};
void Function0_be530::f2(int, int, int) {
    mFn();
}