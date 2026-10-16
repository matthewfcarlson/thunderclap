class ScriptHandler {
  public:
    bool Do(const char*);
};
class Function {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(ScriptHandler*, const char**, bool*);
    char pad[24];
};
class Method1 : public Function {
  public:
    typedef bool (ScriptHandler::*Fn)(const char*);
    Fn fn;
    virtual void f2(ScriptHandler*, const char**, bool*);
};
inline bool invoke(ScriptHandler* obj, Method1::Fn fun, const char* arg) {
    return (obj->*fun)(arg);
}
void Method1::f2(ScriptHandler* a, const char** b, bool* c) {
    Fn fun = fn;
    bool r = invoke(a, fun, *b);
    if (c)
        *c = r;
}