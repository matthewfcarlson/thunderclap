// Same code shape as 0x0002ebc0 (propagated; names are from that function)
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
void __cdecl invoke(int, int, int, int);
class Closure_1e17b0 : public Function {
  public:
    char pad[0x18];
    int a;
    int b;
    virtual void f0();
    virtual void f2(int, int, int);
};
void Closure_1e17b0::f2(int x, int y, int z) {
    invoke(b, y, z, a);
}