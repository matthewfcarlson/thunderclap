// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// Closure2<CTriggerVolumeManager,bool,const_char_*,const_char_*>::vfunc_2 @ 0x00200020
class CTriggerVolumeManager {};
class Closure2 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(void *unused, const char **arguments, bool *result);
private:
    char padding[0x18];
    bool (CTriggerVolumeManager::*method)(const char *, const char *);
    CTriggerVolumeManager *object;
};
void Closure2::vfunc_2(void *unused, const char **arguments, bool *result)
{
    bool value = (object->*method)(arguments[0], arguments[1]);
    if (result)
        *result = value;
}
