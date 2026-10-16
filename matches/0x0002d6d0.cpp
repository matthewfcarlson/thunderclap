class CActorManager {
  public:
    bool Act(int);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method1 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_2(CActorManager*, int*, bool*);
    char pad[0x18];
    bool (CActorManager::*fn)(int);
};
void Method1::vfunc_2(CActorManager* obj, int* input, bool* out) {
    bool (CActorManager::*f)(int) = fn;
    int n = *input;
    bool r = (obj->*f)(n);
    if (out)
        *out = r;
}