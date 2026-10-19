struct CUnlockablesManager {};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
struct Method4 : Function {
    char padding[0x18];
    void (CUnlockablesManager::*method)(const char*, int, const char*, const char*);
    virtual void vfunc_2(CUnlockablesManager* object, const char** args, void* unused);
};
void Method4::vfunc_2(CUnlockablesManager* object, const char** args, void* unused) {
    const char* a = *args++;
    int b = *(const int*)args++;
    const char* c = *args++;
    const char* d = *args;
    (object->*method)(a, b, c, d);
}