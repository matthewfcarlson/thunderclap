struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char readFlag(const char*);
extern char flagA[];
extern char flagB[];
class Function_94a30 : public CtorV_001d0480 {
  public:
    Function_94a30(const char* s) : CtorV_001d0480(s, 1) { }
};
class Method1 : public Function_94a30 {
  public:
    virtual void run();
    char pad0[12];
    unsigned char a;
    char pad1[7];
    unsigned char b;
    char pad2[3];
    int value;
    Method1(const char* s, int v) : Function_94a30(s) {
        value = v;
        b = readFlag(flagA);
        a = readFlag(flagB);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void run();
    int extra;
    Closure1(const char* s, int v, int e);
};
Closure1::Closure1(const char* s, int v, int e) : Method1(s, e) {
    extra = v;
}
