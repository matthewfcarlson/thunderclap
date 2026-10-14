extern int gA_cfda0, gB;
extern "C" unsigned char __cdecl lookup(const void*);
class Root_cfda0 {
  public:
    virtual void invoke();
    Root_cfda0(int, int);
};
class Method_cfda0 : public Root_cfda0 {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char a;
    unsigned char b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int m;
    Method_cfda0(int x, int y) : Root_cfda0(x, 2) {
        m = y;
        c = lookup(&gA_cfda0);
        a = lookup(&gA_cfda0);
        b = lookup(&gB);
    }
};
class Closure : public Method_cfda0 {
  public:
    virtual void invoke();
    int n;
    Closure(int x, int y, int z);
};
Closure::Closure(int x, int y, int z) : Method_cfda0(x, z) {
    n = y;
}
