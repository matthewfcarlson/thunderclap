class CActorManager {
  public:
    int f(const char* a);
};
class Closure1 {
  public:
    virtual void v0();
    virtual void v1();
    virtual int v2(CActorManager** obj, const char** arg, int** out);
    char pad[0x18];
    int (CActorManager::*mFn)(const char*);
    CActorManager* mObj;
};
int Closure1::v2(CActorManager** obj, const char** arg, int** out) {
    CActorManager* o = mObj;
    const char* a = *arg;
    int (CActorManager::*fn)(const char*) = mFn;
    int r = (o->*fn)(a);
    if (out)
        *out = (int*)r;
    return r;
}
