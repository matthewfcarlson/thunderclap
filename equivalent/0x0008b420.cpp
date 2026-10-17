// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CGameFlowManager,const_char_*,const_char_*>::vfunc_2 @ 0x0008b420
struct CGameFlowManager {};
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Closure1 : Function {
    char padding[0x18];
    const char *(CGameFlowManager::*method)(const char *);
    CGameFlowManager *object;
    virtual void vfunc_2(void *unused, const char **argument, const char **result);
};
void Closure1::vfunc_2(void *unused, const char **argument, const char **result) {
    const char *value = (object->*method)(*argument);
    if (result) *result = value;
}