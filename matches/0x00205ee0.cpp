extern int g;
extern unsigned char __cdecl f(int*);
class Function_205ee0 {
  public:
    Function_205ee0(int, int);
    virtual void v0();
    char pad[0x0c];
    unsigned char b10;
    char pad2[7];
    unsigned char b18;
    char pad3[3];
    int n1c;
};
class Method1 : public Function_205ee0 {
  public:
    Method1(int x, int z) : Function_205ee0(x, 1) {
        n1c = z;
        b18 = f(&g);
        b10 = f(&g);
    }
    virtual void v0();
};
class Closure1 : public Method1 {
  public:
    Closure1(int x, int y, int z);
    virtual void v0();
    virtual void v1();
    int n20;
};
Closure1::Closure1(int x, int y, int z) : Method1(x, z) {
    n20 = y;
}
