class CGameFlowManager {
  public:
    bool Invoke(const char*);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method1 : public Function {
  public:
    virtual void v0();
    virtual void v2(CGameFlowManager*, const char**, bool*);
    char pad[0x18];
    bool (CGameFlowManager::*fn)(const char*);
};
void Method1::v2(CGameFlowManager* obj, const char** arg, bool* out) {
    bool (CGameFlowManager::*f)(const char*) = fn;
    const char* value = *arg;
    bool r = (obj->*f)(value);
    if (out)
        *out = r;
}