extern char g1, g2;
extern "C" unsigned char __cdecl Check(const void*);
class Base {
  public:
    Base(const char*, int);
    virtual void fn();
    char pad[0xc];
    unsigned char flag;
    char pad2[7];
};
class Method : public Base {
  public:
    Method(const char* s, void* p) : Base(s, 1) {
        value = p;
        flag2 = Check(&g1);
        flag = Check(&g2);
    }
    virtual void fn();
    unsigned char flag2;
    char pad3[3];
    void* value;
};
class Closure : public Method {
  public:
    Closure(const char* s, void* x, void* p);
    virtual void fn();
    void* extra;
};
Closure::Closure(const char* s, void* x, void* p) : Method(s, p) {
    extra = x;
}