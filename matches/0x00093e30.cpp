class CUnlockablesManager {
  public:
    bool Get(int);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method1 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(CUnlockablesManager*, int*, bool*);
    char pad[24];
    bool (CUnlockablesManager::*fn)(int);
};
void Method1::vfunc_2(CUnlockablesManager* obj, int* arg, bool* out) {
    bool (CUnlockablesManager::*f)(int) = fn;
    int v = *arg;
    bool r = (obj->*f)(v);
    if (out)
        *out = r;
}