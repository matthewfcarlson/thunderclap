class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
void __cdecl invoke(int, int, int, int);
class Closure_2ebc0 : public Function {
  public:
    char pad[0x18];
    int a;
    int b;
    virtual void f0();
    virtual void f2(int, int, int);
};
void Closure_2ebc0::f2(int x, int y, int z) {
    invoke(b, y, z, a);
}