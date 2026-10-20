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
class Closure1_1ea440 : public Base {
  public:
    Closure1_1ea440(char*, void*, void*);
    virtual void f();
    void* obj;
};
class Closure1 : public Closure1_1ea440 {
  public:
    Closure1(char*, void*, void*);
    virtual void f();
    void* other;
};
Closure1::Closure1(char* s, void* p, void* q) : Closure1_1ea440(s, p, q) {
    other = p;
}
Closure1_1ea440::Closure1_1ea440(char* s, void* p, void* q) : Base(s, 1) {
    obj = q;
    y = lookup(a);
    x = lookup(b);
}
