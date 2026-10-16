class CActorManager {
  public:
    int Act(const char*, const char*);
};
struct Args {
    const char* a;
    const char* b;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CActorManager*, Args*, int*);
};
class Method2 : public Function {
    char pad[0x18];

  public:
    typedef int (CActorManager::*Fn)(const char*, const char*);
    Fn fn;
    void v2(CActorManager*, Args*, int*);
};
void Method2::v2(CActorManager* obj, Args* args, int* out) {
    Fn f = fn;
    const char* a = args->a;
    const char* b = args->b;
    int r = (obj->*f)(a, b);
    if (out)
        *out = r;
}
