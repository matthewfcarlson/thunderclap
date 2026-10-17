// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,math::Vector,const_char_*>::vfunc_2 @ 0x001ffa10
struct Vector { float x,y,z; };
struct CTriggerVolumeManager { char padding[28]; };
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const char** input, Vector* result);
    char padding[24];
    Vector (CTriggerVolumeManager::*callback)(const char*);
    CTriggerVolumeManager* manager;
};
void Closure1::vfunc_2(void* unused, const char** input, Vector* result) {
    Vector value = (manager->*callback)(*input);
    if (result) *result = value;
}