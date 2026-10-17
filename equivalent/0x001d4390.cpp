// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<ScriptHandler,ScriptHandler::script_state,const_char_*>::vfunc_2 @ 0x001d4390
struct ScriptHandler {
    enum script_state { initial_state };
};

struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void *unused, const char **argument, int *result);
    char reserved[0x18];
    int (ScriptHandler::*method)(const char *);
    ScriptHandler *object;
};

int Closure1::vfunc_2(void *unused, const char **argument, int *result)
{
    int value = (object->*method)(*argument);
    if (result)
        *result = value;
    return value;
}
