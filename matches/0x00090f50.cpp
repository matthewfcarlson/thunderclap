extern "C" void __stdcall init(const char*, int);
extern "C" unsigned char lookup(const char*);
extern char key1[];
extern char key2[];
class Base {
  public:
    char pad[4];
    Base(const char* p) { init(p, 1); }
};
class Method1 : public Base {
  public:
    virtual void fn();
    char pad[8];
    unsigned char flag1;
    char pad2[7];
    unsigned char flag2;
    char pad3[3];
    void* arg2;
    void* arg3;
    Method1(const char* p, void* a) : Base(p) {
        arg2 = a;
        flag2 = lookup(key1);
        flag1 = lookup(key2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void fn();
    Closure1(const char* p, void* a, void* b);
};
Closure1::Closure1(const char* p, void* a, void* b) : Method1(p, b) {
    arg3 = a;
}