class CSPManager {
  public:
    bool fn(const char*);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    bool (CSPManager::*fn)(const char*);
    virtual void vfunc_2(CSPManager* obj, const char** arg, bool* out);
};
void Method1::vfunc_2(CSPManager* obj, const char** arg, bool* out) {
    bool (CSPManager::*f)(const char*) = fn;
    const char* a = *arg;
    bool r = (obj->*f)(a);
    if (out)
        *out = r;
}
