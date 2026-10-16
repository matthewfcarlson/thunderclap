class CTriggerVolumeManager {
  public:
    void* Fn(const char*);
    inline void* Invoke(void* (CTriggerVolumeManager::*fn)(const char*), const char* arg) {
        return (this->*fn)(arg);
    }
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method1 : public Function {
  public:
    virtual void vfunc_2(CTriggerVolumeManager*, const char**, void**);
    char pad[24];
    void* (CTriggerVolumeManager::*method)(const char*);
};
void Method1::vfunc_2(CTriggerVolumeManager* obj, const char** arg, void** out) {
    void* (CTriggerVolumeManager::*fn)(const char*) = method;
    void* result = obj->Invoke(fn, *arg);
    if (out)
        *out = result;
}