// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CActorManager,void,const_char_*,const_char_*,float>::vfunc_2 @ 0x0002dce0
struct CActorManager {};
struct ActorArguments { const char *first; const char *second; float value; };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CActorManager *manager, const ActorArguments *arguments, void *unused);
    char padding[0x18];
    void (CActorManager::*callback)(const char *, const char *, float);
};
void Method3::vfunc_2(CActorManager *manager, const ActorArguments *arguments, void *unused) {
    (manager->*callback)(arguments->first, arguments->second, arguments->value);
}