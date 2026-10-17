// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure7<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*,int>::vfunc_2 @ 0x00094b10
struct CUnlockablesManager { void FUN_00000000(const char *, int, const char *, const char *, const char *, const char *, int); };
struct Closure7 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const unsigned int *args, void *unused2);
    char pad[0x18];
    void (CUnlockablesManager::*method)(const char *, int, const char *, const char *, const char *, const char *, int);
    CUnlockablesManager *object;
};
void Closure7::vfunc_2(void *unused, const unsigned int *args, void *unused2)
{
    (object->*method)((const char *)args[0], (int)args[1], (const char *)args[2], (const char *)args[3], (const char *)args[4], (const char *)args[5], (int)args[6]);
}