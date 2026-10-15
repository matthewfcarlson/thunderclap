class CActorManager {
  public:
    bool Do(const char*, float, float);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
typedef bool (CActorManager::*Fn)(const char*, float, float);
struct Args {
    const char* s;
    float x, y;
};
class Method3 : public Function {
    char pad[24];
    Fn fn;

  public:
    virtual void vfunc_2(CActorManager*, Args*, bool*);
};
void Method3::vfunc_2(CActorManager* obj, Args* args, bool* out) {
    Fn f = fn;
    const char* s = args->s;
    float x = args->x;
    float y = args->y;
    bool r = (obj->*f)(s, x, y);
    if (out)
        *out = r;
}