struct ScriptHandler {
    const char* invoke(const char*);
};
struct Closure1_ScriptHandler {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual const char* vfunc_2(void* unused, const char** argument, const char** result);
    char padding[0x18];
    const char* (ScriptHandler::*callback)(const char*);
    ScriptHandler* handler;
};
const char* Closure1_ScriptHandler::vfunc_2(void* unused, const char** argument, const char** result) {
    ScriptHandler* h = handler;
    const char* arg = *argument;
    const char* (ScriptHandler::*fn)(const char*) = callback;
    const char* value = (h->*fn)(arg);
    if (result)
        *result = value;
    return value;
}