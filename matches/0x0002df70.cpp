class CActorManager {
  public:
    int Do(const char*, const char*);
};
struct Args {
    const char* a;
    const char* b;
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager*, Args*, int*);
};
class Method2 : public Function {
  public:
    char pad[24];
    typedef int (CActorManager::*MemFn)(const char*, const char*);
    MemFn fn;
    virtual void vfunc_2(CActorManager*, Args*, int*);
};
void Method2::vfunc_2(CActorManager* obj, Args* args, int* out) {
    MemFn f = fn;
    const char* a = args->a;
    const char* b = args->b;
    int result = (obj->*f)(a, b);
    if (out)
        *out = result;
}