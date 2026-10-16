class CTriggerVolumeManager {
  public:
    int invoke(const char*);
    typedef int (CTriggerVolumeManager::*Method)(const char*);
    inline int Do(Method fn, const char* arg) { return (this->*fn)(arg); }
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager*, const char**, int*) = 0;
};
class Method1 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager*, const char**, int*);
    char pad[24];
    CTriggerVolumeManager::Method method;
};
void Method1::vfunc_2(CTriggerVolumeManager* obj, const char** args, int* result) {
    CTriggerVolumeManager::Method fn = method;
    int r = obj->Do(fn, *args);
    if (result)
        *result = r;
}