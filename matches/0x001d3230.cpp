class ScriptHandler {
  public:
    int Do(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(ScriptHandler*, const char**, int*);
    char pad[24];
};
class Method1 : public Function {
  public:
    int (ScriptHandler::*mFn)(const char*);
    virtual void vfunc_2(ScriptHandler*, const char**, int*);
};
void Method1::vfunc_2(ScriptHandler* obj, const char** arg, int* out) {
    int (ScriptHandler::*fn)(const char*) = mFn;
    const char* v = *arg;
    int result = (obj->*fn)(v);
    if (out)
        *out = result;
}