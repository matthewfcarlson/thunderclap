class CActorManager {
  public:
    char Act(const char*, const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Method2 : public Function {
    char pad[0x1c - 4];
    char (CActorManager::*fn)(const char*, const char*);

  public:
    virtual void vfunc_2(CActorManager* obj, const char** args, char* out);
};
void Method2::vfunc_2(CActorManager* obj, const char** args, char* out) {
    char (CActorManager::*f)(const char*, const char*) = fn;
    const char* a = args[0];
    const char* b = args[1];
    char r = (obj->*f)(a, b);
    if (out)
        *out = r;
}