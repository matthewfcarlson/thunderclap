typedef unsigned char byte;
extern void __stdcall FUN_001d0480(int, int);
extern byte __cdecl FUN_001d04d0(const char*);
extern const char g1[], g2[];
class Base {
  public:
    Base(int);
};
Base::Base(int x) {
    FUN_001d0480(x, 1);
}
class Method1 : public Base {
  public:
    virtual void invoke();
    char pad[12];
    byte b;
    char pad2[7];
    byte a;
    char pad3[3];
    int obj;
    Method1(int, int);
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    int val;
    Closure1(int, int, int);
};
Method1::Method1(int x, int y) : Base(x) {
    obj = y;
    a = FUN_001d04d0(g1);
    b = FUN_001d04d0(g2);
}
Closure1::Closure1(int x, int y, int z) : Method1(x, z) {
    val = y;
}