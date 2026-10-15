extern "C" char __cdecl getFlag(const char*);
extern const char flagA[];
extern const char flagB[];
class Base {
  public:
    Base(void*, int);
    virtual void f0();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    void* handler;
};
class Method : public Base {
  public:
    virtual void f1();
    Method(void* p, void* h) : Base(p, 1) {
        handler = h;
        b = getFlag(flagA);
        a = getFlag(flagB);
    }
};
class Closure : public Method {
  public:
    virtual void f2();
    void* extra;
    Closure(void* p, void* q, void* h);
};
Closure::Closure(void* p, void* q, void* h) : Method(p, h) {
    extra = q;
}