class CTriggerVolumeManager {
  public:
    bool Fn(const char*, float);
};
class Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
struct Args {
    const char* s;
    float f;
};
class Method2 : public Function {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2(CTriggerVolumeManager*, Args*, bool*);
    char pad[0x18];
    bool (CTriggerVolumeManager::*fn)(const char*, float);
};
void Method2::v2(CTriggerVolumeManager* o, Args* p, bool* out) {
    bool (CTriggerVolumeManager::*f)(const char*, float) = fn;
    const char* s = p->s;
    float x = p->f;
    bool v = (o->*f)(s, x);
    if (out)
        *out = v;
}