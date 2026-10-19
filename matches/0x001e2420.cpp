extern "C" void _ReadWriteBarrier();
struct CSPManager {};
struct Arguments {
    int a;
    int b;
    const char* c;
};
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void*, Arguments*, void*);
    char padding[0x18];
    void (CSPManager::*method)(int, int, const char*);
    CSPManager* object;
};
void Closure3::vfunc_2(void* unused, Arguments* args, void* unused2) {
    int a = args->a;
    _ReadWriteBarrier();
    int b = args->b;
    const char* c = args->c;
    (object->*method)(a, b, c);
    _ReadWriteBarrier();
}