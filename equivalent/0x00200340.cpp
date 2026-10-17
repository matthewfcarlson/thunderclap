// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure1<CTriggerVolumeManager,int,const_char_*>::vfunc_2 @ 0x00200340
class CTriggerVolumeManager { public: int FUN_00200340(const char *); };
class Closure1_CTriggerVolumeManager_int_const_char {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **value, int *result);
    char padding[0x18];
    int (CTriggerVolumeManager::*method)(const char *);
    CTriggerVolumeManager *object;
};
void Closure1_CTriggerVolumeManager_int_const_char::vfunc_2(void *unused, const char **value, int *result)
{
    int answer = (object->*method)(*value);
    if (result)
        *result = answer;
}
