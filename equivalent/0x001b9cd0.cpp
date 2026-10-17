// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CRenderManager,void,int,int,int>::vfunc_2 @ 0x001b9cd0
struct CRenderManager { };
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Method3 : Function {
    char padding[0x18];
    void (CRenderManager::*method)(int, int, int);
    virtual void vfunc_2(CRenderManager* object, const int* args, void* unused);
};
void Method3::vfunc_2(CRenderManager* object, const int* args, void* unused) {
    (object->*method)(args[0], args[1], args[2]);
}
