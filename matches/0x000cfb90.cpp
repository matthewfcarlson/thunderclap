extern "C" unsigned char __cdecl GetFlag(const char*);
extern const char name1[];
extern const char name2[];
class Base {
  public:
    Base(void*, int);
    virtual void f();
    char pad[0x0c];
};
class Method1 : public Base {
  public:
    Method1(void* a, void* c) : Base(a, 1) {
        p = c;
        flag2 = GetFlag(name1);
        flag1 = GetFlag(name2);
    }
    virtual void g();
    char flag1;
    char pad2[7];
    unsigned char flag2;
    char pad3[3];
    void* p;
};
class Closure1 : public Method1 {
  public:
    Closure1(void*, void*, void*);
    virtual void g();
    void* q;
};
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    q = b;
}