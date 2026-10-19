struct CtorV_001d0480 {
    CtorV_001d0480(const char*, int);
    virtual void v_001d0480();
};
extern "C" char __cdecl Check(const char*);
extern const char textA[];
extern const char textB[];
class Base : public CtorV_001d0480 {
  public:
    Base(const char* x) : CtorV_001d0480(x, 1) { }
};
class Method : public Base {
  public:
    virtual void f();
    char pad[0xc];
    char a;
    char pad2[7];
    char b;
    char pad3[3];
    const char* name;
    float val;
    Method(const char*, float, const char*);
};
class Closure : public Method {
  public:
    virtual void g();
    Closure(const char*, float, const char*);
};
Closure::Closure(const char* x, float y, const char* z) : Method(x, y, z) {
    val = y;
}
Method::Method(const char* x, float y, const char* z) : Base(x) {
    name = z;
    b = Check(textA);
    a = Check(textB);
}
