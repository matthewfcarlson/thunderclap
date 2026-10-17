// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,float,float,math::Vector,float>::vfunc_2 @ 0x0009a890
struct Vector { float x,y,z; };
struct Args { float first, second; Vector direction; float last; };
struct CCameraManager { int unused; };
struct Method4 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CCameraManager* manager, const Args* args, void* unused);
    char pad[0x18];
    void (CCameraManager::*callback)(float,float,Vector,float);
};
void Method4::vfunc_2(CCameraManager* manager, const Args* args, void* unused) {
    (manager->*callback)(args->first,args->second,args->direction,args->last);
}