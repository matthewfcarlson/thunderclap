extern char a[];
extern char b[];
extern "C" unsigned char __cdecl lookup(const char*);
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[12];
    unsigned char flag10;
    char pad2[7];
    unsigned char flag18;
    char pad3[3];
    void* value;
};
class Method1 : public Base {
  public:
    Method1(void*, void*);
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void f();
    void* other;
};
Method1::Method1(void* p, void* v) : Base(p, 1) {
    value = v;
    flag18 = lookup(a);
    flag10 = lookup(b);
}
Closure1::Closure1(void* p, void* v, void* q) : Method1(p, q) {
    other = v;
}