// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,const_char_*,const_char_*>::vfunc_2 @ 0x002004b0
struct CTriggerVolumeManager {};
typedef const char* (CTriggerVolumeManager::*TriggerMethod)(const char*);
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, const char** argument, const char** result);
    char padding[0x18];
    TriggerMethod method;
    CTriggerVolumeManager* object;
};
void Closure1::vfunc_2(void* unused, const char** argument, const char** result) {
    const char* value = (object->*method)(*argument);
    if (result) *result = value;
}
