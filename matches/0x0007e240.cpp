class CAmbientsManager;
extern "C" void __stdcall init(void*, int);
extern "C" unsigned char __cdecl lookup(const char*);
extern const char a[];
extern const char b[];
class Base {
  public:
    Base(void* x) { init(x, 1); }
};
class Method1 : public Base {
  public:
    virtual void Invoke(float);
    char pad[12];
    char flag1;
    char pad2[7];
    char flag2;
    char pad3[3];
    void* obj;
    Method1(void* x, void* z) : Base(x) {
        obj = z;
        flag2 = lookup(a);
        flag1 = lookup(b);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke(float);
    void* extra;
    Closure1(void*, void*, void*);
};
Closure1::Closure1(void* x, void* y, void* z) : Method1(x, z) {
    extra = y;
}
