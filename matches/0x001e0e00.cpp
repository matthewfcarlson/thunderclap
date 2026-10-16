class CSPManager {
  public:
    void* Get(const char*);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method1 : public Function {
  public:
    virtual void vfunc_2(CSPManager*, const char**, void**);
    char pad[0x18];
    void* (CSPManager::*fn)(const char*);
};
void Method1::vfunc_2(CSPManager* a, const char** b, void** out) {
    void* (CSPManager::*f)(const char*) = fn;
    const char* arg = *b;
    void* result = (a->*f)(arg);
    if (out)
        *out = result;
}