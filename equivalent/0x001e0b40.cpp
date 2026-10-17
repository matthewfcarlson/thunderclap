// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSPManager,void,int,int,const_char_*>::vfunc_2 @ 0x001e0b40
struct CSPManager { void FUN_001e0b40(int, int, const char *); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_2(CSPManager *object, const int *args, void *unused);
    char padding[0x18];
    void (CSPManager::*method)(int, int, const char *);
};
void Method3::vfunc_2(CSPManager *object, const int *args, void *unused) {
    (object->*method)(args[0], args[1], (const char *)args[2]);
}