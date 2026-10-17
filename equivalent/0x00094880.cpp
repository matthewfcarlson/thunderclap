// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure6<CUnlockablesManager,void,const_char_*,int,const_char_*,const_char_*,const_char_*,const_char_*>::vfunc_2 @ 0x00094880
struct CUnlockablesManager {
    void FUN_00094880(const char *, int, const char *, const char *, const char *, const char *);
};
struct Arguments {
    const char *name;
    int number;
    const char *text1;
    const char *text2;
    const char *text3;
    const char *text4;
};
struct Closure6 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, Arguments *, void *);
    char pad[0x18];
    void (CUnlockablesManager::*method)(const char *, int, const char *, const char *, const char *, const char *);
    CUnlockablesManager *object;
};
void Closure6::vfunc_2(void *, Arguments *args, void *) {
    (object->*method)(args->name, args->number, args->text1, args->text2, args->text3, args->text4);
}