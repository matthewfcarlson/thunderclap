// Same code shape as 0x0002e800 (propagated; names are from that function)
class CActorManager {
public:
    float Method(const char *);
};
typedef float (CActorManager::*Fn)(const char *);
class Closure1 {
public:
    char pad[0x18];
    Fn mFn;
    CActorManager *mObject;
    virtual void f0();
    virtual void f1();
    virtual void f2(int, const char **, float *);
};
void Closure1::f2(int ignored, const char **arg, float *out) {
    CActorManager *obj = mObject;
    Fn fn = mFn;
    float value = (obj->*fn)(*arg);
    if (out) *out = value;
}
