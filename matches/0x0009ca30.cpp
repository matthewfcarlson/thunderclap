class CCameraManager;
extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" unsigned char __cdecl FUN_001d04d0(const void*);
extern int g1, g2;
class Base {
  public:
    Base(void* a) { FUN_001d0480(a, 2); }
};
class Method2 : public Base {
  public:
    virtual void invoke();
    char pad[12];
    unsigned char b1, b2;
    char pad2[6];
    unsigned char b3;
    char pad3[3];
    CCameraManager* mgr;
    Method2(void*, void*, CCameraManager*);
};
Method2::Method2(void* a, void* p, CCameraManager* m) : Base(a) {
    mgr = m;
    b3 = FUN_001d04d0(&g1);
    b1 = FUN_001d04d0(&g2);
    b2 = FUN_001d04d0(&g2);
}
class Closure2 : public Method2 {
  public:
    void* extra;
    Closure2(void*, void*, CCameraManager*);
    virtual void invoke();
};
Closure2::Closure2(void* a, void* p, CCameraManager* m) : Method2(a, p, m) {
    extra = p;
}