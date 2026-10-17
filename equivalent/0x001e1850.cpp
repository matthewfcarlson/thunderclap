// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CSPManager,int,const_char_*,int>::vfunc_2 @ 0x001e1850
struct CSPManager { int FUN_001e1850(int, const char *); };
struct Closure2_CSPManager_int_const_char_int {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const void *arguments, int *result);
    char padding[0x18];
    int (CSPManager::*method)(int, const char *);
    CSPManager *object;
};
void Closure2_CSPManager_int_const_char_int::vfunc_2(void *unused, const void *arguments, int *result) {
    const struct Arguments { int first; const char *second; } *args = (const Arguments *)arguments;
    int value = (object->*method)(args->first, args->second);
    if (result) *result = value;
}
