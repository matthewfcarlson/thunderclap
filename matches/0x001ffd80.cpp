struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char Get(const char*);
extern const char a[];
extern const char b[];
class InitBase : public CtorV_001d0480 {
  public:
    InitBase(const char* name) : CtorV_001d0480(name, 1) { }
};
class Method1 : public InitBase {
  public:
    virtual void f();
    char pad[12];
    unsigned char x;
    char pad2[7];
    unsigned char y;
    char pad3[3];
    int z;
    Method1(const char*, int);
};
Method1::Method1(const char* name, int v) : InitBase(name) {
    z = v;
    y = Get(a);
    x = Get(b);
}
class Closure1 : public Method1 {
  public:
    virtual void f();
    int val;
    Closure1(const char*, int, int);
};
Closure1::Closure1(const char* name, int v, int w) : Method1(name, w) {
    val = v;
}
