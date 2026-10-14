class CAmbientsManager;
extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" unsigned char __cdecl FUN_001d04d0(void*);
extern int gA;
extern int gB;
class MethodBase_7e2d0 {
  public:
    MethodBase_7e2d0(void* a) { FUN_001d0480(a, 2); }
};
template <class T, class R, class A, class B> class Method2 : public MethodBase_7e2d0 {
  public:
    virtual void Invoke();
    char pad[12];
    unsigned char x;
    unsigned char y;
    char pad2[6];
    unsigned char z;
    char pad3[3];
    void* obj;
    void* fn;
    Method2(void*, void*, void*);
};
template <class T, class R, class A, class B> class Closure2 : public Method2<T, R, A, B> {
  public:
    virtual void Extra();
    Closure2(void*, void*, void*);
};
template <>
Method2<CAmbientsManager, void, float, float>::Method2(void* a, void* b, void* c) : MethodBase_7e2d0(a) {
    obj = c;
    z = FUN_001d04d0(&gA);
    x = FUN_001d04d0(&gB);
    y = FUN_001d04d0(&gB);
}
template <>
Closure2<CAmbientsManager, void, float, float>::Closure2(void* a, void* b, void* c)
    : Method2<CAmbientsManager, void, float, float>(a, b, c) {
    fn = b;
}