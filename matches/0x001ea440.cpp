typedef unsigned int uint;
extern "C" unsigned char __cdecl lookup(const char*);
extern const char a[];
extern const char b[];
class Base {
  public:
    Base(char*, int);
    virtual void f();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
};
class Method1 : public Base {
  public:
    Method1(char*, void*, void*);
    virtual void f();
    void* obj;
};
class Closure1 : public Method1 {
  public:
    Closure1(char*, void*, void*);
    virtual void f();
    void* other;
};
Closure1::Closure1(char* s, void* p, void* q) : Method1(s, p, q) {
    other = p;
}
Method1::Method1(char* s, void* p, void* q) : Base(s, 1) {
    obj = q;
    y = lookup(a);
    x = lookup(b);
}
