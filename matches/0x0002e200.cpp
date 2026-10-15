class CActorManager {
  public:
    float Method(const char*, const char*);
};
struct Args {
    const char* a;
    const char* b;
};
typedef float (CActorManager::*MemFn)(const char*, const char*);
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class Method2 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager* obj, Args* args, float* out);
    char pad[24];
    MemFn fn;
};
void Method2::v2(CActorManager* obj, Args* args, float* out) {
    MemFn f = fn;
    const char* a = args->a;
    const char* b = args->b;
    float r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
