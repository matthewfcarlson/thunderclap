struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern "C" unsigned char query(void*);
extern void* gA;
extern void* gB;
class Function_9caf0 : public CtorV_001d0480 {
  public:
    Function_9caf0(void* p) : CtorV_001d0480(p, 1) { }
};
class Method1 : public Function_9caf0 {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char flagA;
    char pad2[7];
    unsigned char flagB;
    char pad3[3];
    void* owner;
    Method1(void* p, void* o) : Function_9caf0(p) {
        owner = o;
        flagB = query(&gB);
        flagA = query(&gA);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void invoke();
    void* extra;
    Closure1(void* p, void* x, void* o);
};
Closure1::Closure1(void* p, void* x, void* o) : Method1(p, o) {
    extra = x;
}
