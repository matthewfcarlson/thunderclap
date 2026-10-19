struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char lookup(const char*);
extern const char key1[];
extern const char key2[];
class Root : public CtorV_001d0480 {
  public:
    Root(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Root {
  public:
    virtual void f();
    char pad[12];
    unsigned char b10;
    char pad2[7];
    unsigned char b18;
    char pad3[3];
    void* owner;
    Method1(const char* s, void* o) : Root(s) {
        owner = o;
        b18 = lookup(key1);
        b10 = lookup(key2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void f();
    void* arg;
    Closure1(const char*, void*, void*);
};
Closure1::Closure1(const char* s, void* a, void* o) : Method1(s, o) {
    arg = a;
}
