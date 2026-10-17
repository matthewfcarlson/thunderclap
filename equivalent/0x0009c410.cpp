// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CCameraManager,void,float,float,bool>::vfunc_2 @ 0x0009c410
struct CCameraManager { void cameraMethod(float, float, bool); };
struct CameraArgs { float first; float second; bool third; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, CameraArgs* args, int unused2);
    char pad[0x18];
    void (CCameraManager::*method)(float, float, bool);
    CCameraManager* manager;
};
void Closure3::vfunc_2(int unused, CameraArgs* args, int unused2)
{
    (manager->*method)(args->first, args->second, args->third);
}
