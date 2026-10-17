// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Method1<CWorldStreamManager,int,int>::vfunc_2 @ 0x002053f0
struct CWorldStreamManager {};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method1 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CWorldStreamManager *manager, int *input, int *result);
    char padding[0x18];
    int (CWorldStreamManager::*callback)(int);
};
void Method1::vfunc_2(CWorldStreamManager *manager, int *input, int *result) {
    int value = (manager->*callback)(*input);
    if (result) *result = value;
}