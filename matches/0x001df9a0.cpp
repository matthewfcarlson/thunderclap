class CSPManager {
  public:
    int method(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, void*, void*);
};
class Method1 : public Function {
  public:
    char pad[0x18];
    int (CSPManager::*fn)(const char*);
    virtual void vfunc_2(CSPManager* obj, const char** arg, int* out);
};
void Method1::vfunc_2(CSPManager* obj, const char** arg, int* out) {
    int (CSPManager::*f)(const char*) = fn;
    const char* a = *arg;
    int r = (obj->*f)(a);
    if (out)
        *out = r;
}