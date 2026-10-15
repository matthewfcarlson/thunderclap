extern "C" unsigned char __cdecl Func(const void*);
extern int X;
extern int Y;
class Base {
  public:
    Base(int, int);
    virtual void run();
};
class Method1 : public Base {
  public:
    int a[3];
    unsigned char b;
    char pad[7];
    unsigned char c;
    char pad2[3];
    int value;
    Method1(int x, int v) : Base(x, 1), value(v) {
        c = Func(&X);
        b = Func(&Y);
    }
    virtual void run();
};
class Closure1 : public Method1 {
  public:
    int other;
    Closure1(int x, int y, int z);
    virtual void run();
};
Closure1::Closure1(int x, int y, int z) : Method1(x, z), other(y) {}