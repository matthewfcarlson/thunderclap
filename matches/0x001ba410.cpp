extern "C" unsigned char probe(const char*);
extern const char s1[];
extern const char s2[];
class Core {
  public:
    Core(int, int);
    virtual void f();
    char pad[0x1c - 4];
};
class Method1 : public Core {
  public:
    int x;
    Method1(int a, int c) : Core(a, 1), x(c) {
        *((unsigned char*)this + 0x18) = probe(s1);
        *((unsigned char*)this + 0x10) = probe(s2);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    int y;
    Closure1(int a, int b, int c);
    virtual void f();
};
Closure1::Closure1(int a, int b, int c) : Method1(a, c), y(b) {}
