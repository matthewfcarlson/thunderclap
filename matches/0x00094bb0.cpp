struct CUnlockablesManager {
    char dummy;
};
struct Arguments {
    const char* first;
    int second;
    const char* third;
    const char* fourth;
};
struct Closure4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, const Arguments*, void*);
    char padding[0x18];
    void (CUnlockablesManager::*callback)(const char*, int, const char*, const char*);
    CUnlockablesManager* object;
};
void Closure4::vfunc_2(void*, const Arguments* arguments, void*) {
    const char** p = (const char**)arguments;
    const char* a = *p++;
    int b = *(int*)p++;
    const char* c = *p++;
    const char* d = *p++;
    (object->*callback)(a, b, c, d);
}