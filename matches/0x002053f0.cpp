struct CWorldStreamManager {};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method1 : Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CWorldStreamManager* manager, int* input, int* result);
    char padding[0x18];
    int (CWorldStreamManager::*callback)(int);
};
void Method1::vfunc_2(CWorldStreamManager* manager, int* input, int* result) {
    int (CWorldStreamManager::*fn)(int) = callback;
    int arg = *input;
    int value = (manager->*fn)(arg);
    if (result)
        *result = value;
}