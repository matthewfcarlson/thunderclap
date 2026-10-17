// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,const_char_*,int>::vfunc_2 @ 0x001ffdf0
struct CTriggerVolumeManager { };
struct Closure1 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2(void *unused, const char **value, int *result);
    char padding[0x18];
    int (CTriggerVolumeManager::*handler)(const char *);
    CTriggerVolumeManager *manager;
};
int Closure1::vfunc_2(void *unused, const char **value, int *result) {
    int answer = (manager->*handler)(*value);
    if (result) *result = answer;
    return answer;
}