extern "C" void __stdcall init(void*, int);
extern "C" unsigned char query(void*);
extern void* gA;
extern void* gB;
class Parent {
  public:
    Parent(void* p) { init(p, 1); }
};
class Method1 : public Parent {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char flagA;
    char pad2[7];
    unsigned char flagB;
    char pad3[3];
    void* owner;
    Method1(void* p, void* o) : Parent(p) {
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
