struct CWorldStreamManager {};
struct Arguments {
    const char* volatile name;
    volatile int number;
    bool flag;
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method3 : Function {
    virtual void vfunc_0();
    virtual void vfunc_2(CWorldStreamManager* object, Arguments* arguments, void* unused);
    char padding[24];
    void (CWorldStreamManager::*method)(const char*, int, bool);
};
void Method3::vfunc_2(CWorldStreamManager* object, Arguments* arguments, void* unused) {
    const char* name = arguments->name;
    (object->*method)(name, arguments->number, arguments->flag);
}