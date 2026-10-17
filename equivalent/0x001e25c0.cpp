// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure4<CSPManager,bool,const_char_*,float,float,int>::vfunc_2 @ 0x001e25c0
struct CSPManager { bool FUN_001e25c0(const char*, float, float, int); };
struct ClosureArgs { const char* text; float first; float second; int number; };
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const ClosureArgs* args, bool* result);
    char padding[0x18];
    bool (CSPManager::*method)(const char*, float, float, int);
    CSPManager* object;
};
void Closure4::vfunc_2(void* unused, const ClosureArgs* args, bool* result) {
    bool value = (object->*method)(args->text, args->first, args->second, args->number);
    if (result) *result = value;
}
