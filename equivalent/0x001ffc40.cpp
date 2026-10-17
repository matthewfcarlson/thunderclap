// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,float>::vfunc_2 @ 0x001ffc40
struct CTriggerVolumeManager {
    bool FUN_001ffc40_member(const char *, float);
};
struct TriggerArguments {
    const char *name;
    float value;
};
struct Function {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *, const TriggerArguments *, bool *);
};
struct Closure2 : Function {
    char padding[0x18];
    bool (CTriggerVolumeManager::*method)(const char *, float);
    CTriggerVolumeManager *object;
    void vfunc_2(void *unused, const TriggerArguments *arguments, bool *result);
};
void Closure2::vfunc_2(void *unused, const TriggerArguments *arguments, bool *result) {
    bool value = (object->*method)(arguments->name, arguments->value);
    if (result) *result = value;
}