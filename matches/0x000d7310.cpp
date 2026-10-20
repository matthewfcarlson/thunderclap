typedef unsigned char byte;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern "C" byte __cdecl GetFlag(void*);
extern int gOne;
extern int gTwo;
class Base : public CtorV_001d0480 {
  public:
    Base(void* p) : CtorV_001d0480(p, 1) { }
};
class Closure1_d7310 : public Base {
  public:
    virtual void Fn();
    char pad[12];
    byte first;
    char pad2[7];
    byte second;
    char pad3[3];
    void* obj;
    Closure1_d7310(void* p, void* c);
};
class Closure1 : public Closure1_d7310 {
  public:
    virtual void Fn();
    void* extra;
    Closure1(void* p, void* e, void* c);
};
Closure1_d7310::Closure1_d7310(void* p, void* c) : Base(p) {
    obj = c;
    second = GetFlag(&gOne);
    first = GetFlag(&gTwo);
}
Closure1::Closure1(void* p, void* e, void* c) : Closure1_d7310(p, c), extra(e) {}
