extern char a[], b[];
char __cdecl check(const char*);
class Parent {
  public:
    Parent(const char*, int);
    virtual void f();
};
class Root : public Parent {
  public:
    inline Root(const char* n, void* ctx) : Parent(n, 1) {
        v = ctx;
        y = check(b);
        x = check(a);
    }
    virtual void h();
    char pad[0x0c];
    char x;
    char p1[7];
    char y;
    char p2[3];
    void* v;
    void* w;
};
class Closure : public Root {
  public:
    Closure(const char*, void*, void*);
    virtual void g();
};
Closure::Closure(const char* name, void* vec, void* ctx) : Root(name, ctx) {
    w = vec;
}
