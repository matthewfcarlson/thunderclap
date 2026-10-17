// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,math::Vector>::vfunc_2 @ 0x001ffb80
struct Vector { float x,y,z,w; };
struct CTriggerVolumeManager {};
struct Closure {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const Vector *value, bool *result);
    char padding[0x18];
    bool (CTriggerVolumeManager::*method)(Vector);
    CTriggerVolumeManager *object;
};
void Closure::vfunc_2(void *, const Vector *value, bool *result)
{
    bool answer = (object->*method)(*value);
    if (result) *result = answer;
}
