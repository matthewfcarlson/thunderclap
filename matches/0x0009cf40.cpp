extern char gA[], gB[], gC[];
char __cdecl check(const char*);
class Base {
  public:
    virtual void f();
    Base(void*, int);
    char pad[12];
    char b10;
    char b11;
    char pad2[6];
    char b18;
    char pad3[3];
    void* p1;
    void* p2;
};
class Method2 : public Base {
  public:
    virtual void f();
    Method2(void* p, void* c) : Base(p, 2) {
        p1 = c;
        b18 = check(gA);
        b10 = check(gB);
        b11 = check(gC);
    }
};
class Closure2 : public Method2 {
  public:
    virtual void f();
    Closure2(void*, void*, void*);
};
Closure2::Closure2(void* a, void* b, void* c) : Method2(a, c) {
    p2 = b;
}
