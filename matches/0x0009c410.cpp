extern "C" void _ReadWriteBarrier();
struct CCameraManager {
    void cameraMethod(float, float, bool);
};
struct CameraArgs {
    float first;
    float second;
    bool third;
};
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(int unused, CameraArgs* args, int unused2);
    char pad[0x18];
    void (CCameraManager::*method)(float, float, bool);
    CCameraManager* manager;
};
void Closure3::vfunc_2(int unused, CameraArgs* args, int unused2) {
    float first = args->first;
    _ReadWriteBarrier();
    (manager->*method)(first, args->second, args->third);
    _ReadWriteBarrier();
}