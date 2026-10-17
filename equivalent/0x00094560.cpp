// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094560
struct CUnlockablesManager { };
struct CallArgs { const char *first; int second; const char *third; const char *fourth; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); };
struct Method4 : Function {
    char padding[0x18];
    void (CUnlockablesManager::*method)(const char *, int, const char *, const char *);
    virtual void vfunc_2(CUnlockablesManager *object, const CallArgs *args, void *unused);
};
void Method4::vfunc_2(CUnlockablesManager *object, const CallArgs *args, void *unused) {
    (object->*method)(args->first, args->second, args->third, args->fourth);
}