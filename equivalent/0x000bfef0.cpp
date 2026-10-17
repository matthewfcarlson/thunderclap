// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure6<CFEManager,void,const_char_*,const_char_*,const_char_*,const_char_*,int,int>::vfunc_2 @ 0x000bfef0
struct CFEManager { void FUN_000bfef0(const char *,const char *,const char *,const char *,int,int); };
struct Closure6_CFEManager {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const int *args, void *unused2);
    char padding[0x18];
    void (CFEManager::*method)(const char *,const char *,const char *,const char *,int,int);
    CFEManager *object;
};
void Closure6_CFEManager::vfunc_2(void *unused, const int *args, void *unused2) {
    (object->*method)((const char *)args[0], (const char *)args[1], (const char *)args[2], (const char *)args[3], args[4], args[5]);
}