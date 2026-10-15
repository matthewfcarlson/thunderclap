extern "C" char f(const char*);
extern "C" void __stdcall init(void*, int);
extern char label1[];
extern char label2[];
class Root {
  public:
    Root(const char*, int);
    char pad[12];
};
Root::Root(const char* p, int n) {
    init((void*)p, n);
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