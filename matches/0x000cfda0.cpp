extern int gA, gB;
extern "C" unsigned char __cdecl lookup(const void*);
class Root {
  public:
    virtual void invoke();
    Root(int, int);
};
class Method : public Root {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char a;
    unsigned char b;
    char pad2[6];
    unsigned char c;
    char pad3[3];
    int m;
    Method(int x, int y) : Root(x, 2) {
        m = y;
        c = lookup(&gA);
        a = lookup(&gA);
        b = lookup(&gB);
    }
};
class Closure : public Method {
  public:
    virtual void invoke();
    int n;
    Closure(int x, int y, int z);
};
Closure::Closure(int x, int y, int z) : Method(x, z) {
    n = y;
}
