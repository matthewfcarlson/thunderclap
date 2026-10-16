class CTriggerVolumeManager {
  public:
    int Invoke(const char*);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CTriggerVolumeManager*, const char**, int*);
};
class Method1 : public Function {
  public:
    char pad[0x18];
    int (CTriggerVolumeManager::*fn)(const char*);
    virtual void vfunc_2(CTriggerVolumeManager*, const char**, int*);
};
void Method1::vfunc_2(CTriggerVolumeManager* obj, const char** arg, int* out) {
    int (CTriggerVolumeManager::*f)(const char*) = fn;
    const char* s = *arg;
    int r = (obj->*f)(s);
    if (out)
        *out = r;
}