typedef unsigned char byte;
extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" byte __cdecl FUN_001d04d0(const char*);
extern const char a[], b[];
class Base {
  public:
    Base(void* p) { FUN_001d0480(p, 1); }
};
class Method1 : public Base {
  public:
    virtual void Invoke();
    char pad[0x0c];
    byte x;
    char pad2[7];
    byte y;
    char pad3[3];
    void* obj;
    Method1(void*, void*);
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke();
    void* extra;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* p, void* q, void* r) : Method1(p, r) {
    extra = q;
}
Method1::Method1(void* p, void* q) : Base(p) {
    obj = q;
    y = FUN_001d04d0(a);
    x = FUN_001d04d0(b);
}
