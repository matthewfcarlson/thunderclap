class CActorManager {
  public:
    int f(const char*);
};

class Closure1 {
  public:
    virtual void v0();
    virtual void v1();
    virtual int v2(int a, const char** b, int* out);
    char pad[0x18];
    int (CActorManager::*mFn)(const char*);
    CActorManager* mObj;
};

int Closure1::v2(int a, const char** b, int* out) {
    CActorManager* o = mObj;
    int (CActorManager::*fn)(const char*) = mFn;
    const char* p = *b;
    int r = (o->*fn)(p);
    if (out)
        *out = r;
    return r;
}
