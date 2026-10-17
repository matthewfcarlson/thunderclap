// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,bool>::vfunc_2 @ 0x00200210
struct Arguments { const char *name; bool value; };
struct CTriggerVolumeManager { bool invoke(const char *, bool); };
struct Closure2_CTriggerVolumeManager {
    void *vtable;
    char padding[0x18];
    bool (CTriggerVolumeManager::*method)(const char *, bool);
    CTriggerVolumeManager *object;
    void vfunc_2(void *unused, Arguments *arguments, bool *result);
};
void Closure2_CTriggerVolumeManager::vfunc_2(void *unused, Arguments *arguments, bool *result) {
    bool value = (object->*method)(arguments->name, arguments->value);
    if (result) *result = value;
}
