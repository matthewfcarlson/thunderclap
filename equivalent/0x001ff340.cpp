// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Method3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 @ 0x001ff340
struct CTriggerVolumeManager {};
struct TriggerArguments {
    const char *name;
    int value;
    bool enabled;
};
struct Method3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager *manager, TriggerArguments *args, void *unused);
    char reserved[0x18];
    void (CTriggerVolumeManager::*method)(const char *, int, bool);
};
void Method3::vfunc_2(CTriggerVolumeManager *manager, TriggerArguments *args, void *unused) {
    (manager->*method)(args->name, args->value, args->enabled);
}
