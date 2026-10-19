extern "C" char f(const char*);
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern char label1[];
extern char label2[];
class Root : public CtorV_001d0480 {
  public:
    Root(const char*, int);
    char pad[12];
};
Root::Root(const char* p, int n) : CtorV_001d0480((void*)p, n) {
}
class Method1 : public Root {
  public:
    virtual void a();
    Method1(const char*, void*);
    char y;
    char pad2[7];
    char x;
    char pad3[3];
    void* val;
};
Method1::Method1(const char* s, void* p) : Root(s, 1) {
    val = p;
    x = f(label1);
    y = f(label2);
}
class Closure1 : public Method1 {
  public:
    virtual void a();
    Closure1(const char*, void*, void*);
    void* val2;
};
Closure1::Closure1(const char* s, void* p, void* q) : Method1(s, q) {
    val2 = p;
}