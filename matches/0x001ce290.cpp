extern char a[];
extern char b[];
char __cdecl lookup(const char*);
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
    char x;
    char pad2[7];
    char y;
    char pad3[3];
};
class Method1 : public Base {
  public:
    Method1(void*, void*);
    virtual void f();
    void* arg;
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* extra;
};
Closure1::Closure1(void* p, void* q, void* r) : Method1(p, r) {
    extra = q;
}
Method1::Method1(void* p, void* q) : Base(p, 1) {
    arg = q;
    y = lookup(a);
    x = lookup(b);
}
