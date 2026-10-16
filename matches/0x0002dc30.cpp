class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class CActorManager {
  public:
    bool Act(const char*, float);
};
struct Args {
    const char* s;
    float f;
};
class Method2 : public Function {
    char pad[0x18];

  public:
    typedef bool (CActorManager::*Fn)(const char*, float);
    Fn fn;
    void v2(CActorManager* obj, Args* args, char* out);
};
void Method2::v2(CActorManager* obj, Args* args, char* out) {
    Fn f = fn;
    const char* s = args->s;
    float x = args->f;
    bool r = (obj->*f)(s, x);
    if (out)
        *out = r;
}