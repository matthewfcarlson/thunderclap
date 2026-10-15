extern char str1[];
extern char str2[];
extern char __cdecl lookup(const char*);
class Base {
  public:
    virtual void f();
    char pad[12];
    Base(const char*, int);
};
class Method : public Base {
  public:
    virtual void f();
    char a;
    char pad1[7];
    char b;
    char pad2[3];
    int c;
    Method(const char* s, int x) : Base(s, 1) {
        c = x;
        b = lookup(str1);
        a = lookup(str2);
    }
};
class Closure : public Method {
  public:
    virtual void f();
    int d;
    Closure(const char*, int, int);
};
Closure::Closure(const char* s, int x, int y) : Method(s, y) {
    d = x;
}
