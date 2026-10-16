class CTriggerVolumeManager {
  public:
    bool run(const char*, const char*);
};
struct Pair {
    const char* a;
    const char* b;
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
};
class Method2 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(CTriggerVolumeManager*, Pair*, bool*);
    char pad[24];
    bool (CTriggerVolumeManager::*fn)(const char*, const char*);
};
void Method2::vfunc_2(CTriggerVolumeManager* obj, Pair* p, bool* out) {
    bool (CTriggerVolumeManager::*f)(const char*, const char*) = fn;
    const char* a = p->a;
    const char* b = p->b;
    bool r = (obj->*f)(a, b);
    if (out)
        *out = r;
}