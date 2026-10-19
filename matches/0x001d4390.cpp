struct ScriptHandler {
    enum script_state { initial_state };
};
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void* unused, const char** argument, int* result);
    char reserved[0x18];
    int (ScriptHandler::*method)(const char*);
    ScriptHandler* object;
};
int Closure1::vfunc_2(void* unused, const char** argument, int* result) {
    ScriptHandler* obj = object;
    int (ScriptHandler::*fn)(const char*) = method;
    const char* arg = *argument;
    int value = (obj->*fn)(arg);
    if (result)
        *result = value;
    return value;
}