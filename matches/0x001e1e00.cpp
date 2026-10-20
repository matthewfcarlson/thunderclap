extern "C" unsigned char __cdecl fn(const char*);
extern const char str1[];
extern const char str2[];
class Base {
  public:
    Base(const char*, int);
    virtual void f();
};
class Closure1_1e1e00 : public Base {
  public:
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* c;
    Closure1_1e1e00(const char*, void*);
    virtual void f();
};
class Closure1 : public Closure1_1e1e00 {
  public:
    void* d;
    Closure1(const char*, void*, void*);
    virtual void f();
};
Closure1_1e1e00::Closure1_1e1e00(const char* s, void* p) : Base(s, 1) {
    c = p;
    b = fn(str1);
    a = fn(str2);
}
Closure1::Closure1(const char* s, void* p, void* q) : Closure1_1e1e00(s, q) {
    d = p;
}