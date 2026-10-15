extern char nameA[];
extern char nameB[];
extern char __cdecl lookup(const char*);
class Base {
  public:
    Base(const char*, int);
    virtual void f();
    char pad[12];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    int p;
};
class Method1 : public Base {
  public:
    Method1(const char* n, int p) : Base(n, 1) {
        this->p = p;
        b = lookup(nameA);
        a = lookup(nameB);
    }
    virtual void f();
};
class Closure1 : public Method1 {
  public:
    Closure1(const char*, int, int);
    virtual void f();
    int q;
};
Closure1::Closure1(const char* n, int q, int p) : Method1(n, p) {
    this->q = q;
}
