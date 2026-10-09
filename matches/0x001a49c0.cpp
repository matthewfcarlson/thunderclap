typedef unsigned char u8;
struct NodeIsNotRunningCondition {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void*, void*, void*);
    char pad[8];
    u8 mValue;
};
extern int FUN_00344e74(void*, int, const void*, const void*, int);
struct Runner {
    bool run(int);
};
struct Manager {
    char pad[0x30];
    Runner* runner;
};
extern Manager* gManager;
extern char typeNode;
extern char typeBranch;
bool NodeIsNotRunningCondition::vfunc_6(void* arg, void*, void*) {
    bool result = false;
    int value = FUN_00344e74(arg, 0, &typeBranch, &typeNode, 0);
    if (value)
        result = gManager->runner->run(value);
    return result != mValue;
}