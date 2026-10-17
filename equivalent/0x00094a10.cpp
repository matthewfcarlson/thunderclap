// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CUnlockablesManager,void,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094a10
struct CUnlockablesManager { void callbackPlaceholder(); };
struct Arguments { int value; const char *first; const char *second; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const Arguments *, void *);
    char unused[24];
    void (CUnlockablesManager::*method)(int, const char *, const char *);
    CUnlockablesManager *object;
};
void Closure3::vfunc_2(void *, const Arguments *args, void *) {
    (object->*method)(args->value, args->first, args->second);
}