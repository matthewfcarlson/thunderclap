// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure4<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*>::vfunc_2 @ 0x00094bb0
struct CUnlockablesManager { char dummy; };
struct Arguments { const char *first; int second; const char *third; const char *fourth; };
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const Arguments *arguments, void *unused2);
    char padding[0x18];
    void (CUnlockablesManager::*callback)(const char *, int, const char *, const char *);
    CUnlockablesManager *object;
};
void Closure4::vfunc_2(void *unused, const Arguments *arguments, void *unused2) {
    (object->*callback)(arguments->first, arguments->second, arguments->third, arguments->fourth);
}
