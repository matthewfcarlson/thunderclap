class Base {
  public:
    Base(int, int);
    virtual void f();
    char pad[12];
};
extern const char str1[], str2[];
char __cdecl query(const char*);
class Method1 : public Base {
  public:
    Method1(int a, int b) : Base(a, 1) {
        v = b;
        c = query(str1);
        d = query(str2);
    }
    virtual void f();
    char d;
    char x[7];
    char c;
    char y[3];
    int v;
};
class Closure1 : public Method1 {
  public:
    Closure1(int a, int b, int z);
    virtual void f();
    int w;
};
Closure1::Closure1(int a, int b, int z) : Method1(a, z) {
    w = b;
}