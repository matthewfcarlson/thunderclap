// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CSPManager,void,float,float,float>::vfunc_2 @ 0x001e0be0
struct CSPManager {};
struct Triple { float x, y, z; };
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method3 : Function {
    virtual void vfunc_2(CSPManager* manager, Triple* values, void* unused);
    char padding[0x18];
    void (CSPManager::*method)(float, float, float);
};
void Method3::vfunc_2(CSPManager* manager, Triple* values, void* unused) {
    (manager->*method)(values->x, values->y, values->z);
}
