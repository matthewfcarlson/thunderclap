class CUnlockablesManager {
  public:
    int Run(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    int (CUnlockablesManager::*fn)(const char*);
    virtual void vfunc_2(CUnlockablesManager* obj, const char** arg, int* out);
};
void Method1::vfunc_2(CUnlockablesManager* obj, const char** arg, int* out) {
    int (CUnlockablesManager::*f)(const char*) = fn;
    const char* p = *arg;
    int v = (obj->*f)(p);
    if (out)
        *out = v;
}