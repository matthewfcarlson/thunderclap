class CTriggerVolumeManager {
  public:
    bool Run(const char*);
};
class Function {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
};
class Method1 : public Function {
  public:
    char pad[0x18];
    bool (CTriggerVolumeManager::*fn)(const char*);
    virtual void vfunc_2(CTriggerVolumeManager* obj, const char** arg, bool* out);
};
void Method1::vfunc_2(CTriggerVolumeManager* obj, const char** arg, bool* out) {
    bool (CTriggerVolumeManager::*f)(const char*) = fn;
    const char* s = *arg;
    bool r = (obj->*f)(s);
    if (out)
        *out = r;
}