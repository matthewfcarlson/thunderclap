class CGameFlowManager;
class CGameFlowManager {
  public:
    const char* Get(const char* s);
};
typedef const char* (CGameFlowManager::*Fn_8a860)(const char*);
struct Function {
    virtual void f0();
    virtual void f1();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    Fn_8a860 fn;
    virtual void f0();
    virtual void f2(CGameFlowManager* a, const char** p, const char** out);
};
void Method1::f2(CGameFlowManager* a, const char** p, const char** out) {
    Fn_8a860 f = fn;
    const char* s = *p;
    const char* x = (a->*f)(s);
    if (out)
        *out = x;
}
