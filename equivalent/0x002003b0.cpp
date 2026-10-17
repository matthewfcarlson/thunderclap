// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// Closure3<CTriggerVolumeManager,void,const_char_*,int,bool>::vfunc_2 @ 0x002003b0
struct CTriggerVolumeManager {};
struct Arguments { const char* name; int value; unsigned char flag; };
struct Closure3 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void* unused, Arguments* args, void* unused2);
    char padding[0x18];
    void (CTriggerVolumeManager::*method)(const char*, int, unsigned int);
    CTriggerVolumeManager* manager;
};
void Closure3::vfunc_2(void* unused, Arguments* args, void* unused2) {
    (manager->*method)(args->name, args->value, args->flag);
}