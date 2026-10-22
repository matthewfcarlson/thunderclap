struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
unsigned char __cdecl Lookup(const char*);
extern const char text1[], text2[];
class Function_2f1e0 : public CtorV_001d0480 {
  public:
    Function_2f1e0(void* x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Function_2f1e0 {
  public:
    virtual void Fn();
    char pad[12];
    unsigned char a;
    char pad2[7];
    unsigned char b;
    char pad3[3];
    void* p;
    void* q;
    Method1(void* x, void* y) : Function_2f1e0(x) {
        p = y;
        b = Lookup(text1);
        a = Lookup(text2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Fn();
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    q = y;
}
