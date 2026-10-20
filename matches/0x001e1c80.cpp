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
class Closure1_1e1c80 : public Root {
  public:
    virtual void a();
    Closure1_1e1c80(const char*, void*);
    char y;
    char pad2[7];
    char x;
    char pad3[3];
    void* val;
};
Closure1_1e1c80::Closure1_1e1c80(const char* s, void* p) : Root(s, 1) {
    val = p;
    x = f(label1);
    y = f(label2);
}
class Closure1 : public Closure1_1e1c80 {
  public:
    virtual void a();
    Closure1(const char*, void*, void*);
    void* val2;
};
Closure1::Closure1(const char* s, void* p, void* q) : Closure1_1e1c80(s, q) {
    val2 = p;
}