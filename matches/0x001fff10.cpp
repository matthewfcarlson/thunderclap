extern char keyA[];
extern char keyB[];
extern "C" unsigned char __cdecl Lookup(const char*);
class Base {
  public:
    Base(const char*, int);
    virtual void Run();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    int v;
    int w;
};
class Method1 : public Base {
  public:
    Method1(const char* s, int x, int y) : Base(s, 1) {
        v = y;
        b = Lookup(keyA);
        a = Lookup(keyB);
    }
    virtual void Run();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char* s, int x, int y);
    virtual void Run();
};
Closure1::Closure1(const char* s, int x, int y) : Method1(s, x, y) {
    w = x;
}
