struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char check(const char*);
extern char strA[];
extern char strB[];
class Root : public CtorV_001d0480 {
  public:
    Root(void* a) : CtorV_001d0480(a, 1) { }
};
class Method1 : public Root {
  public:
    virtual void invoke();
    char pad[0xc];
    unsigned char flagA;
    char pad2[7];
    unsigned char flagB;
    char pad3[3];
    void* data;
    Method1(void* a, void* c) : Root(a) {
        data = c;
        flagB = check(strB);
        flagA = check(strA);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    void* extra;
    Closure1(void* a, void* b, void* c);
};
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    extra = b;
}
