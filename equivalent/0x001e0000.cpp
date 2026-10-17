// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CSPManager,void,int,float,float,float>::vfunc_2 @ 0x001e0000
struct CSPManager { void FUN_001e0000_callback(int, float, float, float); };
struct Arguments { int id; float first; float second; float third; };
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager* manager, Arguments* arguments, void* unused);
    char padding[0x18];
    void (CSPManager::*callback)(int, float, float, float);
};
void Method4::vfunc_2(CSPManager* manager, Arguments* arguments, void* unused) {
    (manager->*callback)(arguments->id, arguments->first, arguments->second, arguments->third);
}