// Same code shape as 0x0002c760 (propagated; names are from that function)
class CActorManager;
typedef float (CActorManager::*Fn)(const char*);
class CActorManager {
  public:
    float Get(const char* s);
};
class Method1 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(CActorManager* a, const char** p, float* out);
    char pad[0x1c - 4];
    Fn fn;
};
void Method1::f2(CActorManager* a, const char** p, float* out) {
    Fn f = fn;
    const char* s = *p;
    float x = (a->*f)(s);
    if (out)
        *out = x;
}
