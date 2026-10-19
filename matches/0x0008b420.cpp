struct CGameFlowManager {};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Closure1 : Function {
    char padding[0x18];
    const char* (CGameFlowManager::*method)(const char*);
    CGameFlowManager* object;
    virtual void vfunc_2(void* unused, const char** argument, const char** result);
};
void Closure1::vfunc_2(void* unused, const char** argument, const char** result) {
    CGameFlowManager* obj = object;
    const char* (CGameFlowManager::*fn)(const char*) = method;
    const char* value = (obj->*fn)(*argument);
    if (result)
        *result = value;
}