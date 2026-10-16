class CEventManager {
  public:
    bool Test(const char*);
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
    virtual void vfunc_2(CEventManager*, const char**, bool*);
    char pad[0x18];
    bool (CEventManager::*fn)(const char*);
};
void Method1::vfunc_2(CEventManager* obj, const char** arg, bool* out) {
    bool (CEventManager::*f)(const char*) = fn;
    const char* value = *arg;
    bool r = (obj->*f)(value);
    if (out)
        *out = r;
}