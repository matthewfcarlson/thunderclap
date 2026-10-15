typedef unsigned char byte;
extern "C" void __stdcall Init(void*, int);
extern "C" byte __cdecl GetFlag(void*);
extern int gOne;
extern int gTwo;
class Base {
  public:
    Base(void* p) { Init(p, 1); }
};
class Method1 : public Base {
  public:
    virtual void Fn();
    char pad[12];
    byte first;
    char pad2[7];
    byte second;
    char pad3[3];
    void* obj;
    Method1(void* p, void* c);
};
class Closure1 : public Method1 {
  public:
    virtual void Fn();
    void* extra;
    Closure1(void* p, void* e, void* c);
};
Method1::Method1(void* p, void* c) : Base(p) {
    obj = c;
    second = GetFlag(&gOne);
    first = GetFlag(&gTwo);
}
Closure1::Closure1(void* p, void* e, void* c) : Method1(p, c), extra(e) {}
