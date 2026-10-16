class CActorManager {
  public:
    int Act(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method1 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_2(CActorManager*, const char**, int*);
    char pad[0x18];
    int (CActorManager::*fn)(const char*);
};
void Method1::vfunc_2(CActorManager* obj, const char** arg, int* out) {
    int (CActorManager::*f)(const char*) = fn;
    const char* a = *arg;
    int x = (obj->*f)(a);
    if (out)
        *out = x;
}