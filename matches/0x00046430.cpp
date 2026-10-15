class Base {
  public:
    virtual void f();
    Base(const char*, int);
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int c;
};
extern char g1[];
extern char g2[];
extern unsigned char __cdecl FUN_001d04d0(const void*);
class Method1 : public Base {
  public:
    Method1(const char*, int);
    virtual void f();
};
Method1::Method1(const char* s, int x) : Base(s, 1) {
    c = x;
    b = FUN_001d04d0(g2);
    a = FUN_001d04d0(g1);
}
class Closure1 : public Method1 {
  public:
    int d;
    Closure1(const char*, int, int);
    virtual void f();
};
Closure1::Closure1(const char* s, int x, int y) : Method1(s, y) {
    d = x;
}
