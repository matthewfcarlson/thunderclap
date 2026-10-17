// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method4<CCameraManager,void,int,float,float,float>::vfunc_2 @ 0x0009b3c0
struct CCameraManager {};
typedef void (CCameraManager::*CameraMethod)(int, float, float, float);
struct Function { virtual void vfunc_0(); virtual void vfunc_1(); };
struct Args { int mode; float a, b, c; };
struct Method4 : Function {
    virtual void vfunc_2(CCameraManager *, Args *, float);
    char padding[0x18];
    CameraMethod method;
};
void Method4::vfunc_2(CCameraManager *manager, Args *args, float unused) {
    (manager->*method)(args->mode, args->a, args->b, args->c);
}
