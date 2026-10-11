class ScriptHandler;
class ScriptHandler {
  public:
    enum script_state { s0, s1 };
    script_state Get(const char* s);
};
typedef ScriptHandler::script_state (ScriptHandler::*Fn)(const char*);
struct Function {
    virtual void f0();
    virtual void f1();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    Fn fn;
    virtual void f0();
    virtual void f2(ScriptHandler* a, const char** p, ScriptHandler::script_state* out);
};
void Method1::f2(ScriptHandler* a, const char** p, ScriptHandler::script_state* out) {
    Fn f = fn;
    const char* s = *p;
    ScriptHandler::script_state x = (a->*f)(s);
    if (out)
        *out = x;
}
