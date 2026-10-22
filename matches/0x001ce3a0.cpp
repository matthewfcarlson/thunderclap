extern "C" unsigned char __cdecl getFlag(const void*);
extern int flagA, flagB;
class Function_1ce3a0 {
  public:
    Function_1ce3a0(int, int);
    virtual void f();
    char pad[0xc];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int x;
    int y;
};
class Method1 : public Function_1ce3a0 {
  public:
    Method1(int a, int c) : Function_1ce3a0(a, 1) {
        x = c;
        b = getFlag(&flagA);
        this->a = getFlag(&flagB);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(int a, int b, int c);
    virtual void f();
};
Closure1::Closure1(int a, int b, int c) : Method1(a, c) {
    y = b;
}
