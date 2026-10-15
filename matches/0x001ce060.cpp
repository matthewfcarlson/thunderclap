extern "C" unsigned char __cdecl getFlag(const char*);
extern char labelA[];
extern char labelB[];
class Base {
  public:
    virtual void f();
    Base(void*, int);
    char pad[12];
};
class Method1 : public Base {
  public:
    virtual void f();
    char m10;
    char gap11[7];
    char m18;
    char gap19[3];
    int m1c;
    Method1(void*, int, int);
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    int m20;
    Closure1(void*, int, int);
};
inline Method1::Method1(void* p, int x, int y) : Base(p, 1) {
    m1c = y;
    m18 = getFlag(labelA);
    m10 = getFlag(labelB);
}
Closure1::Closure1(void* p, int x, int y) : Method1(p, x, y) {
    m20 = x;
}
