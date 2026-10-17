// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CScenarioManager,int,float,const_char_*>::vfunc_2 @ 0x001ce560
struct CScenarioManager { char unused; };
struct Arguments { int value; float fraction; };
struct Closure2 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, Arguments* args, const char** result);
    char padding[0x18];
    const char* (CScenarioManager::*method)(int, float);
    CScenarioManager* object;
};
void Closure2::vfunc_2(void* unused, Arguments* args, const char** result)
{
    const char* value = (object->*method)(args->value, args->fraction);
    if (result) *result = value;
}
