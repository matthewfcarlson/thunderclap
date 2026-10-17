// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 @ 0x001ba600
struct CRenderManager {
    void FUN_001ba600(float, float, float, float, float, float);
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};
struct Closure6 : Function {
    char padding[0x1c - 4];
    void (CRenderManager::*method)(float, float, float, float, float, float);
    CRenderManager* object;
    void vfunc_2(void* unused, const float* arguments, void* unused2);
};
void Closure6::vfunc_2(void* unused, const float* arguments, void* unused2) {
    (object->*method)(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}