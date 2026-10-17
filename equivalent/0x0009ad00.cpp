// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,bool,bool,bool,bool>::vfunc_2 @ 0x0009ad00
struct CCameraManager { void FUN_0009ad00(unsigned, unsigned, unsigned, unsigned); };
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Method4 : Function {
    virtual void vfunc_2(CCameraManager *, const unsigned char *, void *);
    char padding[0x18];
    void (CCameraManager::*callback)(unsigned, unsigned, unsigned, unsigned);
};
void Method4::vfunc_2(CCameraManager *manager, const unsigned char *args, void *) {
    (manager->*callback)(((unsigned)this & 0xffffff00u) | args[0],
                         ((unsigned)args & 0xffffff00u) | args[4],
                         args[8], args[12]);
}
