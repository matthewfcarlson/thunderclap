typedef unsigned char u8;
struct CtorV_001d0480 {
    CtorV_001d0480(void*, int);
    virtual void v_001d0480();
};
extern "C" u8 __cdecl Check(const char*);
extern const char name1[];
extern const char name2[];
class Core : public CtorV_001d0480 {
  public:
    Core(void* x) : CtorV_001d0480(x, 1) { }
};
class Method1 : public Core {
  public:
    virtual void Invoke();
    char pad[12];
    u8 flag1;
    char pad2[7];
    u8 flag2;
    char pad3[3];
    void* member;
    Method1(void* x, void* y) : Core(x) {
        member = y;
        flag2 = Check(name1);
        flag1 = Check(name2);
    }
};
class Closure1 : public Method1 {
  public:
    virtual void Invoke();
    void* last;
    Closure1(void* a, void* b, void* c);
};
Closure1::Closure1(void* a, void* b, void* c) : Method1(a, c) {
    last = b;
}
