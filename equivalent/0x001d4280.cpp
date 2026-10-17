// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<ScriptHandler,const_char_*,const_char_*>::vfunc_2 @ 0x001d4280
struct ScriptHandler { const char* invoke(const char*); };
struct Closure1_ScriptHandler {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual const char* vfunc_2(void* unused, const char** argument, const char** result);
    char padding[0x18];
    const char* (ScriptHandler::*callback)(const char*);
    ScriptHandler* handler;
};
const char* Closure1_ScriptHandler::vfunc_2(void* unused, const char** argument, const char** result)
{
    const char* value = (handler->*callback)(*argument);
    if (result) *result = value;
    return value;
}