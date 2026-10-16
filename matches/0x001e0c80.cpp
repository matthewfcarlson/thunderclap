class CSPManager {
  public:
    bool Invoke(const char*, float);
};
struct Args {
    const char* name;
    float val;
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager*, Args*, bool*);
};
class Method2 : public Function {
    char pad[0x18];
    bool (CSPManager::*method)(const char*, float);

  public:
    virtual void vfunc_2(CSPManager*, Args*, bool*);
};
void Method2::vfunc_2(CSPManager* obj, Args* a, bool* out) {
    bool (CSPManager::*fn)(const char*, float) = method;
    const char* name = a->name;
    float val = a->val;
    bool result = (obj->*fn)(name, val);
    if (out)
        *out = result;
}