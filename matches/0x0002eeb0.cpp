extern char textA[];
extern char textB[];
extern "C" unsigned char __cdecl getFlag(const char*);
class Base {
  public:
    Base(const char*, int);
    virtual void f();
    char pad[12];
};
class Method1 : public Base {
  public:
    Method1(const char* p, int x) : Base(p, 1) {
        value = x;
        flagA = getFlag(textA);
        flagB = getFlag(textB);
    }
    virtual void f();
    unsigned char flagB;
    char pad1[7];
    unsigned char flagA;
    char pad2[3];
    int value;
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* p, int y, int x);
    virtual void f();
    int other;
};
Closure1::Closure1(const char* p, int y, int x) : Method1(p, x), other(y) {}